#include "smtp.h"

Smtp::Smtp(QString host, QString username, QString pass){
    qDebug() << "### Smtp start"; 
    smtphost = host;
    smtpusername = username;
    smtppass = pass; 
}
void Smtp::SetHost(QString host, QString username, QString pass){
    smtphost = host;
    smtpusername = username;
    smtppass = pass; 
}

void Smtp::Send(const QString &from, const QString &to, 
                const QString &subject, const QString &body){
    int waittime = 5000;
    this->from = from;
    rcpt = to;
    ErrorMSG.clear();
    Timeout = waittime;
    linesend = 0;
    isconnected = false;
    message = TimeStampMail()+"\n";
    message.append("User-Agent: Qt SMTP client\n");
    message.append("X-Accept-Language: en-us, en\n");
    message.append("MIME-Version: 1.0\n");
    message.append("To: " + to + "\n");
    message.append("From: "+from+" <" + from + ">\n");
    message.append("Subject: " + subject + "\n");
    message.append("Content-Type: text/html; charset=UTF8;\n");   /* или txt */
    message.append("Content-transfer-encoding: 8BIT\n\n\n\n");
    message.append(body);
    message.replace( QString::fromLatin1( "\n" ), QString::fromLatin1( "\r\n" ) );
    message.replace( QString::fromLatin1( "\r\n.\r\n" ),QString::fromLatin1( "\r\n..\r\n" ) );
    
    qDebug() << "### Launch mail compose....  "  << from << to << subject << body;
    qDebug() << "### Config server smtp connect to......  "  << smtphost;
    smtpsocket = new QTcpSocket(this);
    connect( this, SIGNAL(ConnectorSuccess()), this, SLOT(ReadLiner())); 
    connect( this, SIGNAL(SendLine()), this, SLOT(PutSendLine())); 
    if (smtphost.size() > 0) {    
        smtpsocket->connectToHost(smtphost, 25);
    }else{
        smtpsocket->connectToHost("localhost", 25);  
    }
    if (smtpsocket->waitForConnected(Timeout)) {
        qDebug() <<"### connected on  " << smtphost; 
        if (smtpsocket->waitForReadyRead(Timeout)) {
            qDebug() <<"### emit from waitForReadyRead connect go can read";
            isconnected = true;
            emit ConnectorSuccess();
        } 
    }else{
        emit ErrorCloseAll();
    }
}

void Smtp::ReadLiner(){
    if (isconnected) {
        qDebug() << "### socketType = " << smtpsocket->socketType();
        qDebug() << "### ReadLiner is start by textstream ";
        QTextCodec *codecx;
        codecx = QTextCodec::codecForMib(106);
        t = new QTextStream( smtpsocket );
        t->setCodec(codecx);
        
        int loops = 0;
        while (!t->atEnd()) {
        loops++;
        response = t->readLine();
        qDebug() << loops << " in line  " << response;
        }
        if (response.size() > 0) {
        RemoteServerName = response;
        mailstatus = response.left(3);
        qDebug() << "###Status=" << mailstatus;
            if (mailstatus == "220") {
                response="";
                linesend = 1;
                emit SendLine();
            }
        }else{
            emit ErrorCloseAll(); 
        }
    }
}

Smtp::~Smtp(){
    qDebug() << "### Smtp stop and delete "; 
}

void Smtp::PutSendLine(){
    int current = linesend;
    qDebug() <<"### Go and Send line " << linesend;
    switch(current) {
      case 1:
          response = SendLineAndGrab("ehlo localhost");
          if (response.size() > 0) {
              ErrorMSG.append(response);
              qDebug() << "1---- " << response;
              linesend = 2;
              emit SendLine();
          }else{
              qDebug() << "Connection lost";
          }
          response ="";
      break;
      case 2:
          response = SendLineAndGrab("AUTH LOGIN");
           if (response.size() > 0) {
           ErrorMSG.append(response);
                qDebug() << "2---- " << response;
                linesend = 3;
                emit SendLine();
           } else {
                qDebug() << "Connection lost";
           }
          response ="";
      break;
      case 3:
          response = SendLineAndGrab(encodeBase64(smtpusername));
           if (response.size() > 0) {
           ErrorMSG.append(response);
                qDebug() << "3---- " << response;
                linesend = 4;
                emit SendLine();
           } else {
                qDebug() << "Connection lost";
           }
          response ="";
      break;
      case 4:
          response = SendLineAndGrab(encodeBase64(smtppass));
           qDebug() << "4---- " << response;
           if (response.size() > 0) {
           ErrorMSG.append(response);
                if (response.contains("ok", Qt::CaseInsensitive) ||
                    response.contains("succeeded", Qt::CaseInsensitive) ) {
                   linesend = 5;
                   emit SendLine();
                } else {
                   qDebug() << "Connection lost!";
                }
           } else {
                qDebug() << "Connection lost!!";
           }
          response ="";
      break;
      case 5:
          response = SendLineAndGrab("MAIL FROM: "+from);
           qDebug() << "5---- " << response;
           if (response.size() > 0) {
                linesend = 6;
                emit SendLine();               
           }
          
      break;
      case 6:
          response = SendLineAndGrab("RCPT TO: "+rcpt);
           qDebug() << "6---- " << response;
           if (response.size() > 0) {
                ErrorMSG.append(response);
                response ="";
                response = SendLineAndGrab("DATA");
                         if (!response.contains("not", Qt::CaseInsensitive)) {
                         ErrorMSG.append(response);
                         response ="";             
                         linesend = 7;
                         emit SendLine();                      
                         }
           }
          response ="";
      break;
      case 7:
          response = SendLineAndGrab(message+"\r\n.");
           qDebug() << "7---- " << response;
           if (response.size() && response.contains("ok", Qt::CaseInsensitive) ) {
                ErrorMSG.append(response);
                linesend = 8;
                emit SendLine();               
           }
           response ="";
      break;
      case 8:
          SendLineAndGrab("QUIT");
      break;
      default:
        qDebug() << "Last line ...";
        emit ErrorCloseAll();
        return;
        break;
    }   
}

QString Smtp::SendLineAndGrab(QString senddata){
    QString incommingData = "";
    if (isconnected) {
   /////////QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
        int current = linesend;
        int loops = 0;
    
        qDebug() << "####Send" << current << "Now => " << senddata;
        *t << senddata << "\r\n";
        t->flush();
        if (senddata != "QUIT") {
            if (smtpsocket->waitForReadyRead(Timeout)) {
                while (!t->atEnd()) {
                    loops++;
                    QString opera = t->readLine()+"\n";
                 incommingData = opera + incommingData;
                    qDebug() << loops << "|#" << opera << "#|";
                }
            } 
        } else {
            ////////QApplication::restoreOverrideCursor();
            delete smtpsocket;
            delete t;
            isconnected = false;
            emit SuccessQuit();
         return incommingData;
        }
        ///////QApplication::restoreOverrideCursor();
    } else {
        emit ErrorCloseAll();
    }
    return incommingData;
}
 
void Smtp::disconnected(){
    qDebug() <<"disconneted";
    qDebug() << "error "  << smtpsocket->errorString();
}

void Smtp::connected(){
    output.append("connected");
    qDebug() << "Connected ";
}

QString Smtp::encodeBase64( QString xml ) {
    QByteArray text;
    text.append(xml);
    return text.toBase64();
}

QString Smtp::decodeBase64( QString xml ) {
    QByteArray xcode("");;
    xcode.append(xml);
    QByteArray precode(QByteArray::fromBase64(xcode));
    QString notetxt = precode.data();
    return notetxt;
}

QStringList Smtp::GetErrorlist(){
    return ErrorMSG;
}

int Smtp::dateswap(QString form, uint unixtime ) {
     QDateTime fromunix;
     fromunix.setTime_t(unixtime); 
     QString numeric = fromunix.toString((const QString)form);
     bool ok; 
     return (int)numeric.toFloat(&ok);
}

QString Smtp::TimeStampMail(){
     /* mail rtf Date format! http://www.faqs.org/rfcs/rfc788.html */
       QDateTime timer1( QDateTime::currentDateTime() ); 
                 /////////timer1.setTimeSpec(Qt::UTC);
    
     uint unixtime = timer1.toTime_t();
     QDateTime fromunix;
     fromunix.setTime_t(unixtime); 
     QStringList RTFdays = QStringList() << "giorno_NULL" << "Mon" << "Tue" 
                                         << "Wed" << "Thu" << "Fri" << "Sat" 
                                         << "Sun";
     QStringList RTFmonth = QStringList() << "mese_NULL" << "Jan" << "Feb" 
                                          << "Mar" << "Apr" << "May" << "Jun" 
                                          << "Jul" << "Aug" << "Sep" << "Oct" 
                                          << "Nov" << "Dec";
     QDate timeroad(dateswap("yyyy",unixtime),
                    dateswap("M",unixtime), dateswap("d",unixtime));
     qDebug() << "### RTFdays " << RTFdays.at(timeroad.dayOfWeek());
     qDebug() << "### RTFmonth " << RTFmonth.at(dateswap("M",unixtime));
     qDebug() << "### yyyy " << dateswap("yyyy",unixtime);
     qDebug() << "### M " << dateswap("M",unixtime);
     qDebug() << "### d " << dateswap("d",unixtime);
     QStringList rtfd_line;
     rtfd_line.clear();
     rtfd_line.append("Date: ");
     rtfd_line.append(RTFdays.at(timeroad.dayOfWeek()));
     rtfd_line.append(", ");
     rtfd_line.append(QString::number(dateswap("d",unixtime)));
     rtfd_line.append(" ");
     rtfd_line.append(RTFmonth.at(dateswap("M",unixtime)));
     rtfd_line.append(" ");
     rtfd_line.append(QString::number(dateswap("yyyy",unixtime)));
     rtfd_line.append(" ");
     rtfd_line.append(fromunix.toString("hh:mm:ss"));
     rtfd_line.append(" +0100");
     qDebug() << "### mail rtf Date format " << rtfd_line.join("");
    return QString(rtfd_line.join(""));
}

//----------------------------------
#include <QtCore> 
#include "smtp.h"

QString fopenutf8(QString fullFileName) {
    QString s = "";
    QFile file(fullFileName); 
    if (file.exists()) {
        if (file.open(QFile::ReadOnly | QFile::Text)) {
            s = QString::fromUtf8(file.readAll());
            file.close();
        }
    }
    return s;
}

//int main(int argc, char *argv[]) {
//    QCoreApplication a( argc, argv );
//    Smtp *smtp  = new Smtp("smtp.mail.ru", "им€", "пароль");
//    smtp->Send("им€@mail.ru", "получатель@сервер.ru",
//               QObject::tr("“ема письма"), fopenutf8("mail.html") );
//    delete smtp;
//    return 0;
//}

