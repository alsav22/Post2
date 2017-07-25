#include "message.h"
#include <QtGui>

Message::Message(QString date, QString from, 
                 QString to,   QString subject, QString text, QString attachment)
                 
{
	m_date       = date;
	m_from       = from;
	m_to         = to;
	m_subject    = subject;
	m_text       = text;
	m_attachment = attachment;
}

Message::Message()
{
    m_date       = "";
	m_from       = "";
	m_to         = "";
	m_subject    = "";
	m_text       = "";
	m_attachment = "";
}

void Message::setdate      (QString str ) { m_date       = str;           };
void Message::setfrom      (QString str ) { m_from       = str;           };
void Message::setto        (QString str ) { m_to         = str;           };
void Message::setsubject   (QString str ) { m_subject    = str;           };
void Message::settext      (QString &str) { m_text       = str;           };
void Message::setattachment(QString str)  { m_attachment = str;           };

QString Message::getdate      () const { return m_date;       } 
QString Message::getfrom      () const { return m_from;       } 
QString Message::getto        () const { return m_to;         } 
QString Message::getsubject   () const { return m_subject;    } 
QString Message::gettext      () const { return m_text;       }
QString Message::getattachment() const { return m_attachment; };


QTextStream& operator<<(QTextStream &out, const Message &message) 
{
	out 
	<< S                    << N
	<< message.m_date       << N
	<< message.m_from       << N
	<< message.m_to         << N
	<< message.m_subject    << N
	<< message.m_attachment << N
	
	<< message.m_text       << N;
	
	return out;
}

QTextStream& operator>>(QTextStream &in, Message &message) // ������ ������ �� �����
{
	message.m_date       = in.readLine();
	message.m_from       = in.readLine();
	message.m_to         = in.readLine();
	message.m_subject    = in.readLine();
	message.m_attachment = in.readLine();
	
	while (!in.atEnd()) // ������ ������ ������
	{   
		QString temp   = in.readLine();
		
		if (temp == S) 
		{
			message.m_text.truncate(message.m_text.size() - 1); // ������� ��������� ������ ������
			in.seek(in.pos() - 3);
			break;
		}
		
		message.m_text.append(temp + N);
	}
	
	return in;
}

void operator<<(QTextEdit *pTextEdit, const Message &message) // ����� ������ � ���� TextEdit
{
	pTextEdit ->append("-----------"            );
	pTextEdit ->append(message.m_date           );
	pTextEdit ->append(message.m_from           );
	pTextEdit ->append(message.m_to             );
	pTextEdit ->append(message.m_subject    + N );
	pTextEdit ->append(message.m_text       + N );

	if (message.m_attachment != QWidget::tr("������������ �����: "))
	{
		pTextEdit ->append("............");
		pTextEdit ->append(message.m_attachment + N);
		QString path = message.m_attachment;
		path.remove(QWidget::tr("������������ �����: "));
		QStringList listfile = QDir(path).entryList(QDir::Files);
		for (int i = 0; i < listfile.size(); i++)
			pTextEdit ->append(listfile[i]);
	}
	
}

void operator<<(QListWidget *pListMessage, const Message &message) // ����� ������ � ListWidget
{
	//QPixmap pix(Address::PATH + address.getimage());
	//QIcon   icon(pix);
	
	QString str = message.m_from + " | " + message.m_subject + " | " + message.m_date + " | ";
	
	if (message.m_attachment != QWidget::tr("������������ �����: ")) str += message.m_attachment;
	
	QListWidgetItem *itemMessage = new QListWidgetItem(str, pListMessage);
}

//............................................................................................

Message formatMessage (const Message message) // �������������� ������ ��� ������ � ������ � ����
{
	Message formatMessage;
	
	formatMessage.setdate   (QWidget::tr("����: "   ) + message.getdate());
	formatMessage.setfrom   (QWidget::tr("�� ����: ") + message.getfrom());
	formatMessage.setto     (QWidget::tr("����: "   ) + message.getto());
	formatMessage.setsubject(QWidget::tr("����: "   ) + message.getsubject());
	formatMessage.settext   (message.gettext());
	formatMessage.setattachment(QWidget::tr("������������ �����: ") + message.getattachment());
	
	return formatMessage; 
}

//.............................................................................................

Message readMessagePOP(/*QSslSocket *m_pSocketPOP, */QTextStream &in, QTextEdit *m_ptxtSender,  // ������ � ��������� 
                             QTextEdit *m_ptxtReceiver, uint m_k)                               // ����������� ������
{
	Message message_receive;  qDebug() << "readMessagePOP";
	QString Str; //qDebug() << in.device() ->bytesAvailable();
	
	while (true) // ������ �� ������� �� ������ ������
	{
		QString temp;
		
		temp = in.readLine(0); // ������ ������
		m_ptxtSender ->append(temp); qDebug() << temp;
				
		if (temp.indexOf("Date:") == 0)           // ���� ������ ������
			message_receive.setdate(temp.mid(6)); // ��������� ������ � �������� � ���� message
		
		if (temp.indexOf("From:") == 0) 
			message_receive.setfrom(temp.mid(6));
					
		if (temp.indexOf("To:") == 0) 
			message_receive.setto(temp.mid(4));
					
		if (temp.indexOf("Subject:") == 0) 
			message_receive.setsubject(temp.mid(9));
                                                   
		if (temp.isEmpty()) 
		{
			qDebug() << "isEmpty()"; 
			break;
		}
	}
	
	//while (!in.atEnd())
	Str = in.readAll();            // ������ ���������� ������
	m_ptxtSender   ->append(Str); qDebug() << Str; qDebug() << "in.atEnd() = " << in.atEnd();

	Str.remove(Str.size() - 4, 4);// �������� ��������� ������ ������ � �����
	
	message_receive.settext(Str);
	
	return message_receive;
}
