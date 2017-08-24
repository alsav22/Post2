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
	
	QTextCodec       *m_pcodec; // ����� ��� �������������� ������ ������
	
	QCursor          *m_pCursor;
	CreateAccount    *m_p�reateAccount;    // ���� ������� �������� �����
	
	QSslSocket       *m_pSocketSMTP;	   // SSL ����� ��� SMTP
	QSslSocket       *m_pSocketPOP;        // SSL ����� ��� POP
	//QTcpSocket       *m_pSocketSMTP;     // TCP ����� ��� SMTP
	//QTcpSocket       *m_pSocketPOP;      // TCP ����� ��� POP

	QList<Message>   *m_pvectorMessageSend;      // ������ ����� ������������
	QList<Message>   *m_pvectorMessageReceived;  // ������ ����� ����������
	QList<Address>   *m_pvectorAddress;          // ������ �������

	//QListWidget      *m_pListAddress ;         // ������ �������
	QListWidget      *m_pListMessageSend ;     // ������ ����� ������������
	QListWidget      *m_pListMessageReceived ; // ������ ����� ����������
	
    Account          *m_pcurrentAccount;  // ����
	Message          *m_pcurrentMessage;  // ������� ������
	Address          *m_pcurrentAddress;  // ������� �����
	QString          dataLetter;          // ������ ������ (��, ��� ��������� ����� ������� DATA)
	QString          dataOutput;              // ������ ����� ��� ������ � ���� ��������� ����������
	
	uint flagErrorSend; // ���� ������ ��� �������� ������
	uint m_c;           // ������, ���������� ����, � �������
	uint m_k;           // ������� ��������� �����
	uint m_number;      // ���������� ����� �� �������
	uint m_flagReadmessage; // ���� ������ ������ ������
	
public :
	
	Post(QWidget *pwgt = 0);
	
	void receiveMessage(); // ��������� ������
	
	// �������������� ������ ��� �������� �� SMTP ������
    bool formatMessageForSMTP();
	// ����� ����������
	void outInfo();
	
	uint m_flagExistAccount; // ���� ����������, ���� ���� �� ���� ���� ��� ������

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

// �������������� ������ ��� �������� �� SMTP ������
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
