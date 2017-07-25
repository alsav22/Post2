#include "dialog.h"
#include "functions.h"
#include "address.h"
#include <QtGui>


CreateAccount::CreateAccount(QString strsender, QWidget *pwdg /*= 0*/) 
                             : QDialog(pwdg, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
{	
	if (strsender == "buttonCreateAccount")
		this ->setWindowTitle(QWidget::tr("Создание ящика"));
	if (strsender == "buttonSettingsAccount")
		this ->setWindowTitle(QWidget::tr("Настройка ящика"));

	this ->setStyleSheet("font: 11pt Times; color: black;"); // oblique
	this ->resize(600, 200);
	
	m_pname     = new QLineEdit; m_pe_mail   = new QLineEdit;
	m_plogin    = new QLineEdit; m_ppassword = new QLineEdit;
	m_pHostSMTP = new QLineEdit; m_pPortSMTP = new QLineEdit;
	m_pHostPOP  = new QLineEdit; m_pPortPOP  = new QLineEdit;
	m_pcheckbox = new QCheckBox;
	m_pcheckbox ->setText(QWidget::tr ("Удалять письма на сервере"));

	m_pPortSMTP ->setReadOnly(true);
	m_pPortPOP  ->setReadOnly(true);
	
	m_ppassword ->setEchoMode(QLineEdit::Password);
	
	QLabel *plblname     = new QLabel; QLabel *plble_mail   = new QLabel;
	QLabel *plbllogin    = new QLabel; QLabel *plblpassword = new QLabel;
	QLabel *plblHostSMTP = new QLabel; QLabel *plblPortSMTP = new QLabel;
	QLabel *plblHostPOP  = new QLabel; QLabel *plblPortPOP  = new QLabel;
	

	plblname     ->setText(QWidget::tr("Имя"));         plble_mail   ->setText(QWidget::tr("e-mail"));
	plbllogin    ->setText(QWidget::tr("Логин"));       plblpassword ->setText(QWidget::tr("Пароль"));
	plblHostSMTP ->setText(QWidget::tr("Сервер SMTP")); plblPortSMTP ->setText(QWidget::tr("Порт SMTP"));
	plblHostPOP  ->setText(QWidget::tr("Сервер POP"));  plblPortPOP  ->setText(QWidget::tr("Порт POP"));
	
	QPushButton *pcmdOk     = new QPushButton(QWidget::tr("Да"));
	QPushButton *pcmdCancel = new QPushButton(QWidget::tr("Выход"));
	pcmdOk     ->setFixedWidth(150);   
	pcmdCancel ->setFixedWidth(150);

	QGridLayout *pEditLayout = new QGridLayout(this);

	pEditLayout ->addWidget(plblname,     0, 0); pEditLayout ->addWidget(plble_mail ,  0, 1);
	pEditLayout ->addWidget(m_pname,      1, 0); pEditLayout ->addWidget(m_pe_mail,    1, 1);
	pEditLayout ->addWidget(plbllogin,    2, 0); pEditLayout ->addWidget(plblpassword, 2, 1);
	pEditLayout ->addWidget(m_plogin,     3, 0); pEditLayout ->addWidget(m_ppassword,  3, 1);
	pEditLayout ->addWidget(plblHostSMTP, 4, 0); pEditLayout ->addWidget(plblPortSMTP, 4, 1);
	pEditLayout ->addWidget(m_pHostSMTP,  5, 0); pEditLayout ->addWidget(m_pPortSMTP,  5, 1);
	pEditLayout ->addWidget(plblHostPOP,  6, 0); pEditLayout ->addWidget(plblPortPOP,  6, 1);
	pEditLayout ->addWidget(m_pHostPOP,   7, 0); pEditLayout ->addWidget(m_pPortPOP,   7, 1);
	pEditLayout ->addWidget(m_pcheckbox,  8, 0);
	pEditLayout ->addWidget(pcmdOk,       9, 0); pEditLayout ->addWidget(pcmdCancel,   9, 1);
	
	setLayout(pEditLayout);
	
	connect(pcmdOk,     SIGNAL(clicked()), SLOT(accept()));
	connect(pcmdCancel, SIGNAL(clicked()), SLOT(reject()));
}

QString CreateAccount::getname    () { return m_pname     ->text(); };
QString CreateAccount::getlogin   () { return m_plogin    ->text(); };
QString CreateAccount::getpassword() { return m_ppassword ->text(); };
QString CreateAccount::gete_mail  () { return m_pe_mail   ->text(); };        
QString CreateAccount::getHostSMTP() { return m_pHostSMTP ->text(); };
QString CreateAccount::getHostPOP () { return m_pHostPOP  ->text(); };
QString CreateAccount::getPortSMTP() { return m_pPortSMTP ->text(); };
QString CreateAccount::getPortPOP () { return m_pPortPOP  ->text(); };
Qt::CheckState CreateAccount::getstatecheckbox() { return m_pcheckbox ->checkState(); }

void CreateAccount::setname    (QString str) { m_pname     ->setText(str); };
void CreateAccount::setlogin   (QString str) { m_plogin    ->setText(str); };
void CreateAccount::setpassword(QString str) { m_ppassword ->setText(str); };
void CreateAccount::sete_mail  (QString str) { m_pe_mail   ->setText(str); };
void CreateAccount::setHostSMTP(QString str) { m_pHostSMTP ->setText(str); };
void CreateAccount::setHostPOP (QString str) { m_pHostPOP  ->setText(str); };
void CreateAccount::setPortSMTP(QString str) { m_pPortSMTP ->setText(str); };
void CreateAccount::setPortPOP (QString str) { m_pPortPOP  ->setText(str); };
void CreateAccount::setstatecheckbox(Qt::CheckState state) { m_pcheckbox ->setCheckState(state); }

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

CreateAddress::CreateAddress(QWidget *pwdg /*= 0*/) 
                       : QDialog(pwdg, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
{	
	this ->setWindowTitle(QWidget::tr("Создание адреса"));
	this ->setStyleSheet("font: 11pt Times; color: black;"); // oblique
	this ->resize(600, 200);
	
	m_pname   = new QLineEdit;
	m_pe_mail = new QLineEdit;
	m_pimage  = new QLineEdit;
	
	QLabel *plblname   = new QLabel; 
	QLabel *plble_mail = new QLabel; 
	QLabel *plblimage  = new QLabel; 

	plblname   ->setText(QWidget::tr("Имя"));         
	plble_mail ->setText(QWidget::tr("e-mail"));       
	plblimage  ->setText(QWidget::tr("Фото (имя файла, с расширением .png, в папке \"Image\")"));  
	
	QPushButton *pcmdOk     = new QPushButton(QWidget::tr("Да"));
	QPushButton *pcmdCancel = new QPushButton(QWidget::tr("Выход"));
	pcmdOk     ->setFixedWidth(150);   
	pcmdCancel ->setFixedWidth(150);

	QVBoxLayout *pEditLayout = new QVBoxLayout;

	pEditLayout ->addWidget(plblname);
	pEditLayout ->addWidget(m_pname);
	pEditLayout ->addWidget(plble_mail);
	pEditLayout ->addWidget(m_pe_mail);
	pEditLayout ->addWidget(plblimage);
	pEditLayout ->addWidget(m_pimage); 
	
	QHBoxLayout *pOkCancelLayout = new QHBoxLayout;
	pOkCancelLayout ->addWidget(pcmdOk); 
	pOkCancelLayout ->addWidget(pcmdCancel);

	QVBoxLayout *pBaseLayout = new QVBoxLayout(this);
	pBaseLayout ->addLayout(pEditLayout);
	pBaseLayout ->addLayout(pOkCancelLayout);
	
	setLayout(pBaseLayout);
	
	connect(pcmdOk,     SIGNAL(clicked()), SLOT(accept()));
	connect(pcmdCancel, SIGNAL(clicked()), SLOT(reject()));

}

QString CreateAddress::getname  () { return m_pname   ->text(); };
QString CreateAddress::gete_mail() { return m_pe_mail ->text(); };        
QString CreateAddress::getimage () { return m_pimage  ->text(); };


void CreateAddress::setname  (QString str) { m_pname   ->setText(str); };
void CreateAddress::sete_mail(QString str) { m_pe_mail ->setText(str); };
void CreateAddress::setimage (QString str) { m_pimage  ->setText(str); };

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

SettingsAddress::SettingsAddress(const QList<Address> *pvectorAddress, QWidget *pwdg /*= 0*/) : QDialog(pwdg, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
{
	this ->setWindowTitle(QWidget::tr("Изменение адреса"));
	this ->setStyleSheet("font: 11pt Times; color: black;"); // oblique
	this ->resize(200, 600);

	QLabel *plbltitle = new QLabel(QWidget::tr("Выберите адрес"));
	plbltitle ->setAlignment(Qt::AlignCenter);
	plbltitle ->setStyleSheet("font: 12pt bold Times; color: black;"); // oblique
	
	m_plistwidget = new QListWidget(this);
    m_plistwidget ->setIconSize(QSize(40, 60));
	m_plistwidget ->setObjectName("ListWidgetSettingsAddress");
	QCursor cur(Qt::PointingHandCursor);
	m_plistwidget ->setCursor(cur);


	m_pvectorAddress = pvectorAddress; // чтобы использовать в слоте slotChoiceAddress()
	readVectorInListWidget(pvectorAddress, m_plistwidget); // заполняем поле адресами из вектора
	
    m_pname     = new QLineEdit;
	m_pe_mail   = new QLineEdit;
	m_pimage    = new QLineEdit;
	m_pcheckbox = new QCheckBox;
	
	QLabel *plblname      = new QLabel; 
	QLabel *plble_mail    = new QLabel; 
	QLabel *plblimage     = new QLabel;
	
	plblname     ->setText(QWidget::tr("Имя"));         
	plble_mail   ->setText(QWidget::tr("e-mail"));       
	plblimage    ->setText(QWidget::tr("Фото (имя файла, с расширением .png, в папке \"Image\")"));
	m_pcheckbox ->setText(QWidget::tr ("Удалить адрес"));
	
	QPushButton *pcmdOk     = new QPushButton(QWidget::tr("Да"));
	QPushButton *pcmdCancel = new QPushButton(QWidget::tr("Выход"));
	pcmdOk     ->setFixedWidth(150);   
	pcmdCancel ->setFixedWidth(150);
	QHBoxLayout *pOkCancelLayout = new QHBoxLayout;
	pOkCancelLayout ->addWidget(pcmdOk    ); 
	pOkCancelLayout ->addWidget(pcmdCancel);

	QVBoxLayout *pEditLayout = new QVBoxLayout;

	pEditLayout ->addWidget(plblname  );
	pEditLayout ->addWidget(m_pname   );
	pEditLayout ->addWidget(plble_mail);
	pEditLayout ->addWidget(m_pe_mail );
	pEditLayout ->addWidget(plblimage );
	pEditLayout ->addWidget(m_pimage  ); 

	QVBoxLayout *pBaseLayout = new QVBoxLayout(this);
	pBaseLayout ->addWidget(plbltitle      );
	pBaseLayout ->addWidget(m_plistwidget  );
	pBaseLayout ->addLayout(pEditLayout    );
	pBaseLayout ->addWidget(m_pcheckbox    );
	pBaseLayout ->addLayout(pOkCancelLayout);

	setLayout(pBaseLayout);

	connect(pcmdOk,     SIGNAL(clicked()), SLOT(accept()));
	connect(pcmdCancel, SIGNAL(clicked()), SLOT(reject()));
	connect(m_plistwidget, SIGNAL(itemClicked(QListWidgetItem *)), this, SLOT(slotChoiceAddress(QListWidgetItem *)));
}

QListWidget*   SettingsAddress::getlistwidget   () { return m_plistwidget;             }
QString        SettingsAddress::getname         () { return m_pname     ->text();      }
QString        SettingsAddress::gete_mail       () { return m_pe_mail   ->text();      }
QString        SettingsAddress::getimage        () { return m_pimage    ->text();      }
Qt::CheckState SettingsAddress::getstatecheckbox() { return m_pcheckbox ->checkState();}
int            SettingsAddress::geti            () { return m_i;                       }

void SettingsAddress::setlistwidget   (QListWidget *plistwidget) { m_plistwidget = plistwidget;       }
void SettingsAddress::setname         (QString str)              { m_pname  ->setText(str);           }
void SettingsAddress::sete_mail       (QString str)              { m_pe_mail ->setText(str);          }
void SettingsAddress::setimage        (QString str)              { m_pimage  ->setText(str);          }
void SettingsAddress::setstatecheckbox(Qt::CheckState state)     { m_pcheckbox ->setCheckState(state);}

void SettingsAddress::slotChoiceAddress(QListWidgetItem *pchoiceItem)
{
	Address address;
	m_i = m_plistwidget ->row(pchoiceItem); // в m_i - номер выбранного в списке адреса
	address = (*m_pvectorAddress)[m_i]; // поиск в векторе по номеру в списке
	
	//m_i = readObjectFromVector(&address, m_pvectorAddress,  // поиск в векторе адресса с выбранным именем
	                               // pchoiceItem ->text());  // и чтение его в address (в m_i заносится индекс адреса в векторе)
	
	m_pname   ->setText(address.getname  ()); 
    m_pe_mail ->setText(address.gete_mail());  
    m_pimage  ->setText(address.getimage ());
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//#include "dialog.h.moc"