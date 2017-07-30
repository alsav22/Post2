#ifndef _SMTP_H_
#define _SMTP_H_

#include <QtCore> 
#include <QtNetwork>
#include <QDebug>
#include <QtTest/QtTest>

class Smtp : public QObject {
    Q_OBJECT
public:
    Smtp(QString host, QString username, QString pass);
    ~Smtp();
    void SetHost(QString host, QString username, QString pass);
    void Send(const QString &from, const QString &to,
              const QString &subject, const QString &body);
    int linesend;
    QStringList ErrorMSG;
    QStringList GetErrorlist();
signals:
    void status( const QString &);
    void ConnectorSuccess();
    void SendLine();
    void ErrorCloseAll();
    void SuccessQuit();
private slots:
    void disconnected();
    void connected();
    void ReadLiner();
    void PutSendLine();
private:
    bool isconnected;
    QString smtphost;
    QString smtpusername;
    QString smtppass;
    QString message;
    QString output;
    QString RemoteServerName;
    QString mailstatus;
    QTextStream *t;
    QTcpSocket *smtpsocket;
    QString from;
    QString rcpt;
    QString response;
    QString SendLineAndGrab(QString senddata);
    int Timeout;
    QString encodeBase64( QString xml );
    QString decodeBase64( QString xml );
    int dateswap(QString form, uint unixtime );
    QString TimeStampMail();
};

#endif // _SMTP_H_

