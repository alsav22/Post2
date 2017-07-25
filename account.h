#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
//#include <QWidget>
#include <QString>

extern const QString RN;
extern const QString N;
extern const QString R;
extern const QString S;

extern const QString PATH_ACCOUNT;
extern const QString PATH_ADDRESS;
extern const QString PATH_SENDER;
extern const QString PATH_RECEIVER;
extern const QString PATH_ATTACHMENT;

class QTextStream;
class QTextEdit;
//extern const QString base64_chars;
//extern const QString base64_chars_rus;

QString base64_encode(const QString bytes_to_encode, uint in_len/*, const QString base64chars*/);
QString base64_decode(const QString &encoded_string/*, const QString base64chars*/);


QString encodePassword(QString m_password); // кодирование пароля
QString decodePassword(QString m_password); // декодирование пароля

class Account 
{
 private :	
	QString m_name;
	QString m_login;
	QString m_loginBase64;
	QString m_password;
	QString m_passwordBase64;
	QString m_e_mail;
	QString m_HostSMTP;
	QString m_HostPOP;
	QString m_PortSMTP;
	QString m_PortPOP;
	QString m_flagdele; // удалять ли письма на сервере ("1" - удалять, "0" - не удалять)

public :
	
	Account(QString name, 
			QString login, 
			QString password,
			QString e_mail,
			QString HostSMTP,
			QString HostPOP,
			QString PortSMTP,
			QString PortPOP,
			QString m_flagdele = "0");
		   
	Account ();
	
	void setname          (const QString str); 
	void setlogin         (const QString str);
	void setloginBase64   (const QString str);
	void setpassword      (const QString str);
	void setpasswordBase64(const QString str);
	void sete_mail        (const QString str);
	void setHostSMTP      (const QString str);
	void setHostPOP       (const QString str);
	void setPortSMTP      (const QString str);
	void setPortPOP       (const QString str);
	void setflagdele      (const QString flagdele);
	
	QString getname          () const;  
	QString getlogin         () const; 
	QString getloginBase64   () const; 
	QString getpassword      () const; 
	QString getpasswordBase64() const;
	QString gete_mail        () const;
	QString getHostSMTP      () const;
	QString getHostPOP       () const;
	QString getPortSMTP      () const;
	QString getPortPOP       () const;
	QString getflagdele      () const;

	Account& operator=(const Account &account);
	
	friend QTextStream& operator<<(QTextStream &out,    const Account &account);
	
	friend QTextStream& operator>>(QTextStream &in,           Account &account);
	
	friend void         operator<<(QTextEdit *pTextEdit, const Account &account);
	
	friend void         operator<<(QVector <QString> &vectorStr, const Account &account);
};

#endif _USER_H_