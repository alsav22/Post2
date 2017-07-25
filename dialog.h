#ifndef _DIALOG_H_
#define _DIALOG_H_

#include <QWidget>
#include <QDialog>

extern const QString RN;
extern const QString N;
extern const QString R;
extern const QString S;

extern const QString PATH_ACCOUNT;
extern const QString PATH_ADDRESS;
extern const QString PATH_SENDER;
extern const QString PATH_RECEIVER;
extern const QString PATH_ATTACHMENT;

class QLineEdit;
class Account;
class Post;
class Address;
class QListWidget;
class QListWidgetItem;
class QCheckBox;


class CreateAccount : public QDialog
{
	Q_OBJECT 
 
 private :
	QLineEdit *m_pname;
	QLineEdit *m_plogin;
	QLineEdit *m_ppassword;
	QLineEdit *m_pe_mail;
	QLineEdit *m_pHostSMTP;
	QLineEdit *m_pHostPOP;
	QLineEdit *m_pPortSMTP;
	QLineEdit *m_pPortPOP;
	QCheckBox *m_pcheckbox;
	
 public :
	CreateAccount(QString sender, QWidget *pwdg = 0);

	QString        getname          ();
	QString        getlogin         ();
	QString        getpassword      ();
	QString        gete_mail        ();
	QString        getHostSMTP      ();
	QString        getHostPOP       ();
	QString        getPortSMTP      ();
	QString        getPortPOP       ();
	Qt::CheckState getstatecheckbox ();
	
	void setname          (QString str);
	void setlogin         (QString str);
	void setpassword      (QString str);
	void sete_mail        (QString str);
	void setHostSMTP      (QString str);
	void setHostPOP       (QString str);
	void setPortSMTP      (QString str);
	void setPortPOP       (QString str);
	void setstatecheckbox (Qt::CheckState state);
};

class CreateAddress : public QDialog
{
	Q_OBJECT 
 
 private :
	QLineEdit *m_pname;
	QLineEdit *m_pe_mail;
	QLineEdit *m_pimage;
	
 public :
	CreateAddress(QWidget *pwdg = 0);

	QString getname  ();
	QString gete_mail();
	QString getimage ();
	
	void setname  (QString str);
	void sete_mail(QString str);
	void setimage (QString str);
};

class SettingsAddress : public QDialog
{
	Q_OBJECT 
 
 private :
	QListWidget *m_plistwidget;
	QLineEdit   *m_pname;
	QLineEdit   *m_pe_mail;
	QLineEdit   *m_pimage;
	QCheckBox   *m_pcheckbox;
	const QList <Address> *m_pvectorAddress; // для копирования вектора адресов(чтобы использовать в слоте)
	int  m_i; // индекс выбранного адреса в векторе адресов

 public :
	SettingsAddress(const QList<Address> *vecaddress, QWidget *pwdg = 0);

	QListWidget*   getlistwidget      ();
	QString        getname            ();
	QString        gete_mail          ();
	QString        getimage           ();
	Qt::CheckState getstatecheckbox   ();
	int            geti               ();
	
	void setlistwidget    (QListWidget *m_plistwidget);
	void setname          (QString str         );
	void sete_mail        (QString str         );
	void setimage         (QString str         );
	void setstatecheckbox (Qt::CheckState state);
 
 private slots :
		void slotChoiceAddress(QListWidgetItem *);
};
#endif