#ifndef _MESSAGE_H_
#define _MESSAGE_H_

//#include <QWidget>
#include <QString>

class QTextStream;
class QTextEdit;
class QListWidget;
class Address;
class QDir;

extern const QString RN;
extern const QString N;
extern const QString R;
extern const QString S;

extern const QString PATH_ACCOUNT;
extern const QString PATH_ADDRESS;
extern const QString PATH_SENDER;
extern const QString PATH_RECEIVER;
extern const QString PATH_ATTACHMENT;


class Message
{
 private :
	QString m_date;
	QString m_from;
	QString m_to;
	QString m_subject;
	QString m_text;
	QString m_attachment;

public :
	Message(QString date, QString from,
	        QString to,   QString subject, QString text, QString attachment);

	Message();
	        
    void setdate       (QString str );
	void setfrom       (QString str );
	void setto         (QString str );
	void setsubject    (QString str );
	void settext       (QString &str);
	void setattachment (QString str);
	
	QString getdate       () const;
	QString getfrom       () const;
	QString getto         () const;
	QString getsubject    () const;
	QString gettext       () const;
	QString getattachment () const;

	friend QTextStream& operator<<(QTextStream &out,          const Message &message);
	friend         void operator<<(QTextEdit *pTextEdit,      const Message &message);
	friend QTextStream& operator>>(QTextStream &out,                Message &message);
	friend         void operator<<(QListWidget *pListMessage, const Message &message); // вывод письма в ListWidget

};

void  outMessage  (const Message &message, QTextEdit *m_ptxtReceiver);  // вывод письма в поле TextEdit

//bool  writeMessage(const Message *message, const QString path);        // запись письма в файл

Message readMessagePOP(/*QSslSocket *m_pSocketPOP,*/ QTextStream &in, QTextEdit *m_ptxtSender,// чтение и обработка полученного письма
                             QTextEdit *m_ptxtReceiver, uint m_k); 

Message formatMessage (const Message message); // форматирование письма для вывода и записи в файл

#endif