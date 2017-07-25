#ifndef _ADDRESS_H_
#define _ADDRESS_H_

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
class QListWidget;

class Address 
{
 private :
	
	QString m_name;
	QString m_e_mail;
	QString m_image;
	
public :
	static const QString PATH;
	
	Address(QString name, 
	        QString e_mail, 
			QString image);
			

	Address();
	
	void setname  (QString str);
	void sete_mail(QString str);
	void setimage (QString str);
	
	QString getname  () const;
	QString gete_mail() const;
	QString getimage () const;
	
	friend QTextStream& operator<<(QTextStream &out,            const Address &address);
	friend         void operator<<(QTextEdit   *pTextEdit,      const Address &address);
	friend         void operator<<(QVector<QString> &vecstring, const Address &address);
	friend         void operator<<(QListWidget *pListAddress,   const Address &address);
	friend QTextStream& operator>>(QTextStream &out,                  Address &address);
	
};

#endif