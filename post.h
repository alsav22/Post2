#ifndef POST_H
#define POST_H

#include <QtGui/QWidget>
#include <QAbstractSocket>
#include "ui_post3_2.h"

//class Post : public QWidget
//{
//	Q_OBJECT
//
//public:
//	Post(QWidget *parent = 0, Qt::WFlags flags = 0);
//	~Post();
//
//private:
//	Ui::PostClass ui;
//};
//////////////////////////////////////////////////
extern const QString RN;
extern const QString N;
extern const QString R;
extern const QString S;

class QTextEdit;
class QLineEdit;
class QLabel;
class QStringList;
class QTcpSocket;
class QSslSocket;
class QDialog;
class QPushButton;
class QListWidget;
class QListWidgetItem;
class QCheckBox;
class QCursor;
//class QAbstractSocket;

class Account;
class Message;
class Address;
class CreateAccount;


class Post : public QWidget
{
	Q_OBJECT
private :
    Ui::PostClass ui;
	
	QTextCodec       *m_pcodec; // кодек для форматирования данных письма
	
	QCursor          *m_pCursor;
	CreateAccount    *m_pсreateAccount;    // окно диалога создания ящика
	
	QSslSocket       *m_pSocketSMTP;	   // SSL сокет для SMTP
	QSslSocket       *m_pSocketPOP;        // SSL сокет для POP
	//QTcpSocket       *m_pSocketSMTP;     // TCP сокет для SMTP
	//QTcpSocket       *m_pSocketPOP;      // TCP сокет для POP

	QList<Message>   *m_pvectorMessageSend;      // массив писем отправленных
	QList<Message>   *m_pvectorMessageReceived;  // массив писем полученных
	QList<Address>   *m_pvectorAddress;          // массив адресов

	//QListWidget      *m_pListAddress ;         // список адресов
	QListWidget      *m_pListMessageSend ;     // список писем отправленных
	QListWidget      *m_pListMessageReceived ; // список писем полученных
	
    Account          *m_pcurrentAccount;  // ящик
	Message          *m_pcurrentMessage;  // текущее письмо
	Address          *m_pcurrentAddress;  // текущий адрес
	QString          dataLetter;          // данные письма (то, что передаётся после команды DATA)
	QString          dataOutput;              // данные письм для вывода в поле служебной информации
	
	uint flagErrorSend; // флаг ошибки при отправке письма
	uint m_c;           // индекс, выводимого кода, в массиве
	uint m_k;           // счётчик считанных писем
	uint m_number;      // количество писем на сервере
	uint m_flagReadmessage; // флаг чтения текста письма
	
public :
	
	Post(QWidget *pwgt = 0);
	
	void receiveMessage(); // получение письма
	
	// форматирование данных для отправки на SMTP сервер
    bool formatMessageForSMTP();
	// вывод информации
	void outInfo();
	
	uint m_flagExistAccount; // флаг установлен, если хотя бы один ящик был создан

public slots :
	void slotReadyReadSMTP  (                            );
	void slotReadyReadPOP   (                            );
    void slotErrorSMTP      (QAbstractSocket::SocketError);
	void slotErrorPOP       (QAbstractSocket::SocketError);
    void slotSendToServer   (                            );
    void slotConnectedSMTP  (                            );
	void slotConnectedPOP   (                            );
	
	void slotSendMessage    (                            );
	void slotReceiveMessage (                            );

	void slotChoiceAddress  (QListWidgetItem *           );
	void slotChoiceMessage  (QListWidgetItem *           );

	void slotCreateAccount  (                            );
	void slotCreateAddress  (                            );
	void slotSettingsAddress(                            );
	void slotSettings       (                            );
	void slotHelp           (                            );
	void slotOutMessage     (                            );
	void slottextChanged    (const QString &             );
	void slotClear          (                            );
	
	void slotReadySSL       (QListWidgetItem *           );
	void slotProgress       (qint64 written              )
	{
		qDebug() << written;
	}

};

// форматирование данных для отправки на SMTP сервер
//void formatMessageForSMTP(QString& data, const Post* post, const QTextCodec* codec);

bool reedTextMessage                 (QSslSocket *m_pSocketPOP, QTextStream &in, 
                                      QTextEdit  *m_ptxtSender, QVector <QString> &vecstr);
QString numbermessage                (uint n);
Message extractfromString            (const QString &fullstr_istext);
Message noMIMEextractfromString      (const QString &fullstr);
Message isMIMEextractfromString      (const QString &fullstr);
Message text_plain_extractfromString (const QString &fullstr, const QString contenttype);
Message message_extractfromString    (const QString &fullstr, const QString contenttype);
Message image_extractfromString      (const QString &fullstr, const QString contenttype);
Message audio_extractfromString      (const QString &fullstr, const QString contenttype);
Message video_extractfromString      (const QString &fullstr, const QString contenttype);
Message application_extractfromString(const QString &fullstr, const QString contenttype);
Message multipart_extractfromString  (const QString &fullstr, const QString contenttype);
QString searchString                 (const QString &fullstr_istext, 
                                      const QString begin, const QString ch);
QString extractText                  (const QString &fullstr);
void decodeText                      (QString &extract, const QString encoding, const QString charset);
void decodeQuotedPrintable           (QString &extract);
void decode_strings                  (QString &extract);
void updateFrom_To                   (QString &extract);
QString extractValueParameter        (const QString &fullstr_istext, const QString Begin, 
                                      const QString NameParameter,   const QString EndParameter);
QString createFile                   (QString &data, QString filename, const QString encoding);

#endif // POST_H
