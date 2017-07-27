////#include "post.h"
////Post::Post(QWidget *parent, Qt::WFlags flags)
////	: QWidget(parent, flags)
////{
////	ui.setupUi(this);
////}
////
////Post::~Post()
////{
////
////}
///////////////////////////////////////////////
#include "post.h"
#include "data.h"
#include "address.h"
#include "message.h"
#include "dialog.h"
#include "functions.h"
#include <QtGui>
#include <QtNetwork>
//#include <QVector>
#include <QString>
//#include <QTextEdit>
//#include <QLineEdit>
//#include <QLabel>
//#include <QPushButton>
//#include <QLayout>
//#include <QTime>
//#include <QListWidget>
//#include <iostream>
//#include <fstream>
//using namespace std;

extern QTextCodec *LocalCodec;

const QString RN = "\r\n";
const QString N  = "\n";
const QString R  = "\r";
const QString S  = "#"; // строка-разделитель

const QString PATH_ACCOUNT    = "./Account/account.txt";
const QString PATH_ADDRESS    = "./Address/address.txt";
const QString PATH_SENDER     = "./Sender/sender.txt";
const QString PATH_RECEIVER   = "./Receiver/receiver.txt";
const QString PATH_ATTACHMENT = "./Attachment/";

QString *pPathAttachment = NULL;

// конструктор ======================================================================

Post::Post(QWidget *pwgt /*= 0*/) : QWidget(pwgt)
{
	//m_ptxtSender      = NULL;
	//m_pCheckBox       = NULL;
    //m_pcurrentAccount = NULL;
	//m_pcurrentMessage = NULL;
	//m_pcurrentAddress = NULL;
	  
	//m_pcodec = QTextCodec::codecForName("CP1251");
    //QTextCodec::setCodecForTr(m_pcodec);
	
	ui.setupUi(this);

//	
//	this ->setWindowTitle(QWidget::tr("Почтовик"));
//	QIcon icon("icon2.png");
//	this ->setWindowIcon(icon);
//	
//	QLabel *plblAddress = new QLabel(QWidget::tr("Адреса"));
//	plblAddress ->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
//	plblAddress ->setStyleSheet("font: bold oblique 14pt Times; color: blue;");
//	plblAddress ->setFrameStyle(QFrame::WinPanel | QFrame::Raised);
//	plblAddress ->setLineWidth(6);
//	plblAddress ->setFixedHeight(109);
//
// список адресов
	
	//ui.m_pListAddress = new QListWidget;
	//ui.m_pListAddress ->setStyleSheet("font: oblique bold 13pt Times; color: black;"); // oblique
	////ui.m_pListAddress ->setMinimumWidth(300);
	//ui.m_pListAddress ->setFixedWidth(290);
	//ui.m_pListAddress ->setIconSize(QSize(124, 152));
	//ui.m_pListAddress ->setViewMode(QListView::IconMode);
	//
	//m_pCursor = new QCursor(Qt::PointingHandCursor);
	//ui.m_pListAddress ->setCursor(*m_pCursor);
	
	/*QCursor cur(Qt::PointingHandCursor);
	ui.m_pListAddress ->setCursor(cur);*/
//
//	QVBoxLayout *pvbLayoutAddress = new QVBoxLayout;
//	//QSplitter *pgridLayoutAddress= new QSplitter(Qt::Vertical);
//	pvbLayoutAddress ->addWidget(plblAddress);
//	pvbLayoutAddress ->addWidget(ui.m_pListAddress);
//
//	//connect(ui.m_pListAddress, SIGNAL(itemClicked(QListWidgetItem *)), this, SLOT(slotChoiceAddress(QListWidgetItem *)));
//	connect(ui.m_pListAddress, SIGNAL(currentItemChanged (QListWidgetItem *, QListWidgetItem *)) , this, SLOT(slotChoiceAddress(QListWidgetItem *)));
//
//// список отправленных писем
//	
	m_pListMessageSend = new QListWidget;
    //m_pListMessageSend ->setStyleSheet("font: oblique bold 13pt Times; color: black;"); // oblique
	//m_pListMessageSend ->setMinimumWidth(300);
	//m_pListMessageSend ->setFixedWidth(290);
	//m_pListMessageSend ->setIconSize(QSize(124, 152));
	//m_pListMessageSend ->setViewMode(QListView::IconMode);
	
	m_pCursor = new QCursor(Qt::PointingHandCursor);
	m_pListMessageSend ->setCursor(*m_pCursor);

	m_pListMessageSend ->setObjectName("ListMessageSend");
	
	//connect(m_pListMessageSend, SIGNAL(itemClicked(QListWidgetItem *)), this, SLOT(slotChoiceMessage(QListWidgetItem *)));
	connect(m_pListMessageSend, SIGNAL(currentItemChanged (QListWidgetItem *, QListWidgetItem *)) , this, SLOT(slotChoiceMessage(QListWidgetItem *)));

// список полученных писем
	
	m_pListMessageReceived = new QListWidget;
	//m_pListMessageReceived ->setStyleSheet("font: oblique bold 13pt Times; color: black;"); // oblique
	//m_pListMessageReceived ->setMinimumWidth(300);
	//m_pListMessageReceived ->setFixedWidth(290);
	//m_pListMessageReceived ->setIconSize(QSize(124, 152));
	//m_pListMessageReceived ->setViewMode(QListView::IconMode);
	
	m_pCursor = new QCursor(Qt::PointingHandCursor);
	m_pListMessageReceived ->setCursor(*m_pCursor);
	
	m_pListMessageReceived ->setObjectName("ListMessageReceived");
	
	//connect(m_pListMessageReceived, SIGNAL(itemClicked(QListWidgetItem *)), this, SLOT(slotChoiceMessage(QListWidgetItem *)));
	connect(m_pListMessageReceived, SIGNAL(currentItemChanged (QListWidgetItem *, QListWidgetItem *)) , this, SLOT(slotChoiceMessage(QListWidgetItem *)));

//// Получение и Служебная информация	
//	
//  // Получение
//	QLabel *plblRec = new QLabel(QWidget::tr("Получение"));
//	plblRec ->setAlignment(Qt::AlignCenter);
//	plblRec ->setStyleSheet("font: bold oblique 16pt Times; color: blue;");
//	plblRec ->setFrameStyle(QFrame::WinPanel | QFrame::Raised);
//	plblRec ->setLineWidth(6);
//	plblRec ->setFixedHeight(109);
//	
//	// поле редактирования
//	m_ptxtReceiver = new QTextEdit;
//	m_ptxtReceiver ->setStyleSheet("font: oblique 12pt Times; color: black;");
//	m_ptxtReceiver ->setFrameStyle(QFrame::WinPanel | QFrame::Raised);
//	m_ptxtReceiver ->setLineWidth(7);
//	m_ptxtReceiver ->setMinimumWidth(700);
//	//m_ptxtReceiver ->setReadOnly(true);
//
// // Служебная информация
//    QLabel *plblSender = new QLabel(QWidget::tr("Служебная информация"));
//	plblSender ->setAlignment(Qt::AlignCenter);
//	plblSender ->setStyleSheet("font: bold oblique 12pt Times; color: blue;");
//	plblSender ->setFrameStyle(QFrame::WinPanel | QFrame::Raised);
//	plblSender ->setLineWidth(6);
//	plblSender ->setFixedHeight(40);
//    
//	// поле редактирования
//	m_ptxtSender = new QTextEdit;	
//	m_ptxtSender ->setStyleSheet("font: 9pt Arial; color: black;");
//	m_ptxtSender ->setFrameStyle(QFrame::WinPanel | QFrame::Raised);
//	m_ptxtSender ->setLineWidth(7);
//	m_ptxtSender ->setMinimumWidth(700);
//	//m_ptxtSender ->setReadOnly(true);
//
//	// ручной ввод команд сервера....................................................
//	m_pinput_comServer = new QLineEdit;
//	m_pinput_comServer ->setStyleSheet("font: 12pt Times; color: black;");
//	m_pinput_comServer ->setFixedHeight(35);
//
//	m_pCheckBox = new QCheckBox(QWidget::tr("Ручной ввод команд"));
//	m_pCheckBox ->setStyleSheet("font: 11pt Times; color: black;");
//	QHBoxLayout *phbxLayout_comServer = new QHBoxLayout;
//	//QSplitter *phbxLayout_comServer = new QSplitter(Qt::Vertical);
//	phbxLayout_comServer ->addWidget(m_pinput_comServer);
//	phbxLayout_comServer ->addWidget(m_pCheckBox);
//
//	//*Для отправки команд на сервер...............................
//	 connect(m_pinput_comServer, SIGNAL(returnPressed   ()), 
//                           this, SLOT  (slotSendToServer()));
//	//........................................................................*/
//
//	// вывод информации (сообщения) о получении
//	m_pinfoReceive = new QLabel;
//	m_pinfoReceive ->setAlignment(Qt::AlignCenter);
//    m_pinfoReceive ->setStyleSheet("font: bold oblique 13pt Times; color: red;");
//	m_pinfoReceive ->setFrameStyle(QFrame::WinPanel | QFrame::Raised);
//	m_pinfoReceive ->setLineWidth(6);
//	m_pinfoReceive ->setMargin(3);
//	
//	// кнопка Получить
//	QPushButton* pcmd_receive = new QPushButton(QWidget::tr("Получить"));
//	pcmd_receive ->setStyleSheet("font: bold oblique 11pt Times; color: black;");
//    pcmd_receive ->setCursor(*m_pCursor);
//	pcmd_receive ->setObjectName("pcmd_clear");
//
//	connect(pcmd_receive, SIGNAL(clicked()), SLOT(slotReceiveMessage()));
//
//	// кнопка Очистить
//	QPushButton* pcmd_clearreceive = new QPushButton(QWidget::tr("Очистить"));
//	pcmd_clearreceive ->setStyleSheet("font: bold oblique 11pt Times; color: black;");
//    pcmd_clearreceive ->setCursor(*m_pCursor);
//	pcmd_clearreceive ->setObjectName("pcmd_clearreceive");
//
//	connect(pcmd_clearreceive, SIGNAL(clicked()), SLOT(slotClear()));
//	
//	// компоновка кнопок Получить и Очистить
//	QHBoxLayout *phbxLayout_receive_clearreceive = new QHBoxLayout;
//	phbxLayout_receive_clearreceive ->addWidget(pcmd_receive, 1);
//	phbxLayout_receive_clearreceive ->addWidget(pcmd_clearreceive);
//	
//	// компоновка Получение и Служебная информация
//	QSplitter *spl_Receiver_Sender = new QSplitter(Qt::Vertical);
//	spl_Receiver_Sender  ->addWidget(plblRec);
//	spl_Receiver_Sender  ->addWidget(m_ptxtReceiver);
//	spl_Receiver_Sender  ->addWidget(plblSender);
//	spl_Receiver_Sender  ->addWidget(m_ptxtSender);
//	//spl_Receiver_Sender  ->addLayout(phbxLayout_comServer);
//	
//	QVBoxLayout *pvbxLayout_sender   = new QVBoxLayout;
//	//pvbxLayout_sender ->addWidget(plblRec);
//	//pvbxLayout_sender ->addWidget(m_ptxtReceiver);
//	pvbxLayout_sender ->addWidget(spl_Receiver_Sender);
//	pvbxLayout_sender ->addLayout(phbxLayout_comServer); // ручной ввод команд сервера
//	pvbxLayout_sender ->addWidget(m_pinfoReceive);
//	//pvbxLayout_sender ->addWidget(pcmd_receive);
//	pvbxLayout_sender ->addLayout(phbxLayout_receive_clearreceive);
//
//
//// Новое письмо
//	QLabel *plblMessage  = new QLabel(QWidget::tr("Новое письмо"));
//	plblMessage ->setAlignment(Qt::AlignCenter);
//	plblMessage ->setStyleSheet("font: bold oblique 16pt Times; color: blue;");
//	plblMessage ->setFrameStyle(QFrame::WinPanel | QFrame::Raised);
//	plblMessage ->setLineWidth(6);
//	plblMessage ->setFixedHeight(60);
//	
//	// надписи Адрес Тема
//	QLabel *to      = new QLabel(QWidget::tr("Адрес"));
//	QLabel *subject = new QLabel(QWidget::tr("Тема"));
//	to      ->setAlignment(Qt::AlignCenter);
//	subject ->setAlignment(Qt::AlignCenter);
//	to      ->setStyleSheet("font: bold oblique 12pt Times; color: black;");
//	subject ->setStyleSheet("font: bold oblique 12pt Times; color: black;");
//	to ->setFrameStyle(QFrame::WinPanel | QFrame::Raised);
//	to ->setLineWidth(6);
//	subject ->setFrameStyle(QFrame::WinPanel | QFrame::Raised);
//	subject ->setLineWidth(6);
//	to ->setFixedHeight(40);
//	subject->setFixedHeight(40);
//    QHBoxLayout *phbxLayoutLbl = new QHBoxLayout;
//	phbxLayoutLbl ->addWidget(to);
//	phbxLayoutLbl ->addWidget(subject);
//
//	// строки редактирования Адрес Тема
//	m_pTo          = new QLineEdit;
//	m_pSubject     = new QLineEdit;
//	QHBoxLayout *phbxLayout_to_subject = new QHBoxLayout;
//	phbxLayout_to_subject ->addWidget(m_pTo);
//	phbxLayout_to_subject ->addWidget(m_pSubject);
//	m_pTo          ->setStyleSheet("font: bold oblique 13pt Times; color: black;");
//	m_pSubject     ->setStyleSheet("font: bold oblique 13pt Times; color: black;");
//
//	m_pTo      ->setObjectName("m_pTo");     
//	m_pSubject ->setObjectName("m_pSubject");
//	
//	connect(m_pTo,      SIGNAL(textChanged(const QString &)), SLOT(slottextChanged(const QString &)));
//	connect(m_pSubject, SIGNAL(textChanged(const QString &)), SLOT(slottextChanged(const QString &)));
//	
//    // поле редактирования Новое письмо
//	m_ptxtMessage = new QTextEdit;
//	m_ptxtMessage ->setStyleSheet("font: oblique 14pt Times; color: black;");
//	m_ptxtMessage ->setFrameStyle(QFrame::WinPanel | QFrame::Raised);
//	m_ptxtMessage ->setLineWidth(7);
//	//m_ptxtMessage ->setMinimumWidth(550);
//
//	// вывод информации (сообщения) об отправке
//	m_pinfoSend = new QLabel;
//	m_pinfoSend ->setAlignment(Qt::AlignCenter);
//    //m_pinfoSend ->setStyleSheet("font: bold oblique 13pt Times; color: red;");
//	m_pinfoSend ->setFrameStyle(QFrame::WinPanel | QFrame::Raised);
//	m_pinfoSend ->setLineWidth(6);
//	m_pinfoSend ->setMargin(3);
//	
//	// кнопка Отправить 
//	QPushButton* pcmd_send    = new QPushButton(QWidget::tr("Отправить"));
//	pcmd_send    ->setStyleSheet("font: bold oblique 11pt Times; color: black;");
//	pcmd_send    ->setCursor(*m_pCursor);
//	
//	connect(pcmd_send, SIGNAL(clicked()), SLOT(slotSendMessage()));
//
//	// кнопка Очистить
//	QPushButton* pcmd_clearsend = new QPushButton(QWidget::tr("Очистить"));
//	pcmd_clearsend ->setStyleSheet("font: bold oblique 11pt Times; color: black;");
//    pcmd_clearsend ->setCursor(*m_pCursor);
//	pcmd_clearsend ->setObjectName("pcmd_clearsend");
//
//	connect(pcmd_clearsend, SIGNAL(clicked()), SLOT(slotClear()));
//	
//	// компоновка кнопок Отправить и Очистить
//	QHBoxLayout *phbxLayout_send_clearsend = new QHBoxLayout;
//	phbxLayout_send_clearsend ->addWidget(pcmd_send, 1);
//	phbxLayout_send_clearsend ->addWidget(pcmd_clearsend);
//	
//	// компоновка Новое письмо
//	QVBoxLayout *pvbxLayout_message  = new QVBoxLayout;
//	pvbxLayout_message ->addWidget(plblMessage);
//	pvbxLayout_message ->addLayout(phbxLayoutLbl);
//	pvbxLayout_message ->addLayout(phbxLayout_to_subject);
//	pvbxLayout_message ->addWidget(m_ptxtMessage);
//	pvbxLayout_message ->addWidget(m_pinfoSend);
//	//pvbxLayout_message ->addWidget(pcmd_send);
//	pvbxLayout_message ->addLayout(phbxLayout_send_clearsend);
//
//// Настройки
//	QLabel *plblSettings = new QLabel(QWidget::tr("Настройки"));
//	plblSettings ->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
//	plblSettings ->setStyleSheet("font: bold oblique 14pt Times; color: blue;");
//	plblSettings ->setFrameStyle(QFrame::WinPanel | QFrame::Raised);
//	plblSettings ->setLineWidth(5);
//	plblSettings ->setFixedHeight(109);
//
//	QPushButton *pbuttonCreateAccount   = new QPushButton(QWidget::tr("Создать ящик"));
//	QPushButton *pbuttonSettingsAccount = new QPushButton(QWidget::tr("Настроить ящик"));
//	QPushButton *pbuttonCreateAddress   = new QPushButton(QWidget::tr("Добавить адрес"));
//	QPushButton *pbuttonSettingsAddress = new QPushButton(QWidget::tr("Изменить / удалить адрес"));
//	QPushButton *pbuttonSettings        = new QPushButton(QWidget::tr("Настройки"));
//	//QPushButton *pbuttonHelp            = new QPushButton(QWidget::tr("Помощь"));
//	QPushButton *pbuttonReceived        = new QPushButton(QWidget::tr("Полученные"));
//	QPushButton *pbuttonSend            = new QPushButton(QWidget::tr("Отправленные"));
//	pbuttonCreateAccount    ->setStyleSheet("font: bold oblique 10pt Times; color: black;");
//	pbuttonSettingsAccount  ->setStyleSheet("font: bold oblique 10pt Times; color: black;");
//	pbuttonCreateAddress    ->setStyleSheet("font: bold oblique 10pt Times; color: black;");
//	pbuttonSettingsAddress  ->setStyleSheet("font: bold oblique 10pt Times; color: black;");
//	pbuttonSettings         ->setStyleSheet("font: bold oblique 10pt Times; color: black;");
//	//pbuttonHelp             ->setStyleSheet("font: bold oblique 10pt Times; color: black;");
//    pbuttonReceived         ->setStyleSheet("font: bold oblique 13pt Times; color: blue;");
//	pbuttonSend             ->setStyleSheet("font: bold oblique 13pt Times; color: blue;");
//
//	/*pbuttonCreateAccount  ->setFixedHeight(40);
//	pbuttonSettingsAccount  ->setFixedHeight(40);
//	pbuttonCreateAddress    ->setFixedHeight(40);
//	pbuttonSettingsAddress  ->setFixedHeight(40);*/
//	
//	/*
//	pbuttonCreateAccount    ->setFlat(true);
//	pbuttonSettingsAccount  ->setFlat(true);
//	pbuttonCreateAddress    ->setFlat(true);
//	pbuttonSettingsAddress  ->setFlat(true);
//	pbuttonSettings         ->setFlat(true);
//	pbuttonHelp             ->setFlat(true);*/
//	
//	pbuttonReceived         ->setFlat(true);
//	pbuttonSend             ->setFlat(true);
//	
//	pbuttonCreateAccount    ->setCursor(*m_pCursor);
//	pbuttonSettingsAccount  ->setCursor(*m_pCursor);
//	pbuttonCreateAddress    ->setCursor(*m_pCursor);
//	pbuttonSettingsAddress  ->setCursor(*m_pCursor);
//	pbuttonSettings         ->setCursor(*m_pCursor);
//	//pbuttonHelp             ->setCursor(*m_pCursor);
//	pbuttonReceived         ->setCursor(*m_pCursor);
//	pbuttonSend             ->setCursor(*m_pCursor);
//	
//	pbuttonCreateAccount    ->setObjectName("buttonCreateAccount");          
//	pbuttonSettingsAccount  ->setObjectName("buttonSettingsAccount");
//	pbuttonCreateAddress    ->setObjectName("buttonCreateAddress");
//	pbuttonSettingsAddress  ->setObjectName("buttonSettingsAddress");
//	pbuttonSettings         ->setObjectName("buttonSettings");
//	//pbuttonHelp             ->setObjectName("buttonHelp");
//	pbuttonReceived         ->setObjectName("buttonReceived");
//	pbuttonSend             ->setObjectName("buttonSend");
//	
//	connect(pbuttonCreateAccount,    SIGNAL(clicked()), SLOT(slotCreateAccount  ()));
//	connect(pbuttonSettingsAccount,  SIGNAL(clicked()), SLOT(slotCreateAccount  ()));
//	connect(pbuttonCreateAddress,    SIGNAL(clicked()), SLOT(slotCreateAddress  ()));
//	connect(pbuttonSettingsAddress,  SIGNAL(clicked()), SLOT(slotSettingsAddress()));
//	connect(pbuttonSettings,         SIGNAL(clicked()), SLOT(slotSettings       ()));
//	//connect(pbuttonHelp,             SIGNAL(clicked()), SLOT(slotHelp         ()));
//	connect(pbuttonReceived,         SIGNAL(clicked()), SLOT(slotOutMessage     ()));
//	connect(pbuttonSend,             SIGNAL(clicked()), SLOT(slotOutMessage     ()));
//    
//	//ящик
//	QLabel *plblAccount_info = new QLabel(QWidget::tr("Ящик"));
//	plblAccount_info  ->setStyleSheet("font: bold oblique 11pt Times; color: black;");
//	plblAccount_info  ->setFrameStyle(QFrame::WinPanel | QFrame::Raised);
//	plblAccount_info  ->setLineWidth(5);
//	plblAccount_info  ->setAlignment(Qt::AlignCenter);
//	plblAccount_info  ->setFixedHeight(37);
//	
//	m_pAccountInfo  = new QLabel;
//	m_pAccountInfo ->setStyleSheet("font: bold oblique 10pt Times; color: black;");
//	m_pAccountInfo ->setFrameStyle(QFrame::WinPanel | QFrame::Raised);
//	m_pAccountInfo ->setLineWidth(5);
//    m_pAccountInfo ->setAlignment(Qt::AlignCenter);
//	m_pAccountInfo ->setFixedHeight(35);
//	m_pAccountInfo ->setMargin(3);
//	
//	QVBoxLayout *pvbxLayoutAccountInfo = new QVBoxLayout;
//	pvbxLayoutAccountInfo ->addWidget(plblAccount_info);
//	pvbxLayoutAccountInfo ->addWidget(m_pAccountInfo);
//	
//	// компоновка Настройки
//	QVBoxLayout *pvbxLayout_Settings  = new QVBoxLayout;
//	pvbxLayout_Settings ->addWidget(plblSettings);
//	pvbxLayout_Settings ->addWidget(pbuttonCreateAccount);
//	pvbxLayout_Settings ->addWidget(pbuttonSettingsAccount);
//	pvbxLayout_Settings ->addWidget(pbuttonCreateAddress);
//	pvbxLayout_Settings ->addWidget(pbuttonSettingsAddress);
//	pvbxLayout_Settings ->addWidget(pbuttonSettings);
//	//pvbxLayout_Settings ->addWidget(pbuttonHelp);
//	pvbxLayout_Settings ->addStretch();
//	pvbxLayout_Settings ->addWidget(pbuttonReceived);  
//	pvbxLayout_Settings ->addWidget(pbuttonSend);
//	pvbxLayout_Settings ->addLayout(pvbxLayoutAccountInfo);
//	//QSplitter *p        = new QSplitter(Qt::Horizontal);
//	//p ->addWidget(pgridLayoutAddress);
//	//p ->addWidget(spl_Receiver_Sender);
//
//// общая компоновка
//	QHBoxLayout *phbxLayout_base  = new QHBoxLayout;
//	//QSplitter *phbxLayout_base  = new QSplitter(Qt::Horizontal);
//	//phbxLayout_base ->addStretch(1);
//	
//	//phbxLayout_base ->addWidget(pgridLayoutAddress);
//	phbxLayout_base ->addLayout(pvbxLayout_sender);
//	//phbxLayout_base ->addWidget(spl_Receiver_Sender);
//	//phbxLayout_base ->addWidget(p);
//	
//	phbxLayout_base ->addLayout(pvbxLayout_message);
//	phbxLayout_base ->addLayout(pvbLayoutAddress);
//	
//	phbxLayout_base ->addLayout(pvbxLayout_Settings);
//	
//    setLayout(phbxLayout_base);
//
////==============================================================================
//
// создание сокета для SMTP и соединение его со слотами обработки сигналов
    m_pSocketSMTP = new QSslSocket(this);
	//m_pSocketSMTP = new QTcpSocket(this);

	//m_pSocketSMTP ->setPrivateKey("grupal.key");
    //m_pSocketSMTP ->setLocalCertificate("grupal.crt");

	connect(m_pSocketSMTP, SIGNAL(connected()), SLOT(slotConnectedSMTP()));
    connect(m_pSocketSMTP, SIGNAL(readyRead()), SLOT(slotReadyReadSMTP()));
    connect(m_pSocketSMTP, SIGNAL(error(QAbstractSocket::SocketError)),
                     this, SLOT(slotErrorSMTP(QAbstractSocket::SocketError)));

// создание сокета для POP и соединение его со слотами обработки сигналов
	//m_pSocketPOP = new QTcpSocket(this);
	m_pSocketPOP = new QSslSocket(this);

    //m_pSocketPOP ->setPrivateKey("grupal.key");
    //m_pSocketPOP ->setLocalCertificate("grupal.crt");

	connect(m_pSocketPOP, SIGNAL(connected()), SLOT(slotConnectedPOP()));
    //connect(m_pSocketPOP, SIGNAL(readyRead()), SLOT(slotReadyReadPOP()));
    connect(m_pSocketPOP, SIGNAL(error    (QAbstractSocket::SocketError)),
                          this,  SLOT(slotErrorPOP(QAbstractSocket::SocketError)));
//............................................................

//============================================================================

	if (QFile::exists(PATH_ACCOUNT)) // если файл существует
	{
		QFile file(PATH_ACCOUNT);
	
		file.open(QIODevice::ReadOnly | QIODevice::Text);
		QTextStream fin(&file);
		
		// создание ящика
			m_pcurrentAccount = new Account;
			
			m_flagExistAccount = 1;    // флаг существования ящика
			
			fin >> *m_pcurrentAccount; // чтение данных ящика из файла (с декодированием пароля в двух видах)
			                           // !!! два вида пароля в файле должны быть в закодированном виде !!!

			ui.m_pAccountInfo ->setText(m_pcurrentAccount ->gete_mail()); // вывод e-mail текущего ящика 
			                                                           // в поле Текущий ящик
			file.close();
    }
	else  m_flagExistAccount = 0;  // если файла нет

	m_pvectorMessageSend     = new QList<Message>; // массив писем отправленных
	m_pvectorMessageReceived = new QList<Message>; // массив писем полученных
	m_pvectorAddress         = new QList<Address>; // массив адресов

	m_pcurrentAddress        = new Address;          // текущий адрес
	m_pcurrentMessage        = new Message;          // текущее письмо
		
  // чтение из файлов в массивы всех адресов, отправленных и полученных писем
	if (QFile::exists(PATH_ADDRESS))
	{
		readFileInVector(m_pvectorAddress, PATH_ADDRESS, S);
		readVectorInListWidget(m_pvectorAddress, ui.m_pListAddress); // заполняем поле Адреса
	}
			
	if (QFile::exists(PATH_SENDER))
		readFileInVector(m_pvectorMessageSend, PATH_SENDER, S); // нужно?
			
	if (QFile::exists(PATH_RECEIVER))
		readFileInVector(m_pvectorMessageReceived, PATH_RECEIVER, S); // нужно?

  // заполнение списков отправленных и полученных писем
	readVectorInListWidget(m_pvectorMessageSend,     m_pListMessageSend    ); // заполняем список отправленных писем
    readVectorInListWidget(m_pvectorMessageReceived, m_pListMessageReceived); // заполняем список полученных писем

//=========================================================================================		 
    
	//QString s = "Василий Иванович";
	//QString s2 = "Pz8/Pz8/Pz8/Pz8/Pw==";
    
	//QString s = "UGFjaWZpYyBPY2Vhbg==";
	//qDebug() << "base64_decode" << base64_decode(s);
	//s2 = base64_decode(s2);
	//qDebug() << "base64_decode" << s2;
	//qDebug() << "base64_decode" << QString::fromLocal8Bit(s2.toStdString().c_str());
	//qDebug() << base64_encode(s, s.size());
}


/////////////////////////////////////////////////////////////////////////////////

void Post::slotSendMessage()
{
	if (this ->m_flagExistAccount == 0) // если ящика не существует
	{
	    if (messageAccount() == QMessageBox::Yes) // если Yes
	            this ->slotCreateAccount(); // переход к созданию ящика
		return;
	}
	
	ui.m_pinfoSend    ->clear();
	ui.m_pinfoReceive ->clear();
    
	// если поле Кому пустое. Если не пустое, то текущий адрес будет заполнен 
	// или в slotChoiceAddress, или в slottextChanged
	if (ui.m_pTo ->text().isEmpty()) 
	{
		outputInfo(ui.m_pinfoSend, arrInfo[SEND_ERROR].strInfo + "\nВведите или выберите адрес.", arrInfo[SEND_ERROR].strSound);
		return;
	}

/*.. соединение сокета с сервером SMTP
    m_pSocketSMTP ->abort();
    m_pSocketSMTP ->connectToHost(m_pcurrentAccount ->getHostSMTP(), 
	                              m_pcurrentAccount ->getPortSMTP().toUInt());
//.................*/
    //qDebug() << "ciphers()" << m_pSocketSMTP ->ciphers();
    
	
	QApplication::restoreOverrideCursor(); // возвращаем обычный курсор
	QApplication::setOverrideCursor(QCursor(Qt::WaitCursor)); // песочные часы
    
	if (m_pSocketSMTP ->state() == QAbstractSocket::ConnectedState) 
		m_pSocketSMTP ->abort();
	
	m_pSocketSMTP ->connectToHostEncrypted(m_pcurrentAccount ->getHostSMTP(), 
	                                       m_pcurrentAccount ->getPortSMTP().toUInt());
    
	//qDebug() << "peerCertificate()" << m_pSocketSMTP ->peerCertificate();

	//qDebug() << "sessionCipher()" << m_pSocketSMTP ->sessionCipher();

	//qDebug() << "localCertificate" << m_pSocketSMTP ->localCertificate();

/* для отладки......................................................................
m_pTo ->clear();
m_pTo ->insert(m_pcurrentAccount ->gete_mail());	
//.......................................................................*/	
	
	QDateTime date;

	m_pcurrentMessage ->setdate   (date.currentDateTime().toString(Qt::SystemLocaleDate)); // дата отправки
	m_pcurrentMessage ->setfrom   (m_pcurrentAccount ->getname() + " <" + m_pcurrentAccount ->gete_mail() + ">"); // добавляем имя к полю from, добавляем к e-mail "<>"
	m_pcurrentMessage ->setto     (m_pcurrentAddress ->getname() + " <" + m_pcurrentAddress ->gete_mail() + ">"); // добавляем имя к полю to,   добавляем к e-mail "<>"
	m_pcurrentMessage ->setsubject(ui.m_pSubject        ->text());
	m_pcurrentMessage ->settext   (ui.m_ptxtMessage     ->toPlainText());
	
	//if (m_pcurrentMessage != NULL) 
	//{
		//delete m_pcurrentMessage;
		//m_pcurrentMessage = NULL;
	//}
	
	//m_pcurrentMessage = new Message(date.currentDateTime().toString(Qt::SystemLocaleDate), // дата отправки
	//                                 m_pcurrentAccount ->getname()   +                     // добавляем имя к полю from
	//						  " <" + m_pcurrentAccount ->gete_mail() + ">",                // добавляем к полю from (e-mail)"<>"
	//						         m_pcurrentAddress ->getname()   +                     // добавляем имя к полю to
	//                          " <" + m_pcurrentAddress ->gete_mail() + ">",                // добавляем к e-mail "<>"
	//								 m_pSubject        ->text(), 
	//								 m_ptxtMessage     ->toPlainText());
   
   setcommandsSMTP(m_pcurrentAccount, ui.m_pTo); // заполнение вектора командами для сервера SMTP

   flagErrorSend     = 0;
   m_c               = 0;
   m_flagReadmessage = 0;

   //qDebug() << m_pSocketSMTP ->caCertificates();
}

//==========================================================================

void Post::slotReceiveMessage()
{
	if (this ->m_flagExistAccount == 0) // если ящика не существует
	{
	    if (messageAccount() == QMessageBox::Yes) // если Yes
	            this ->slotCreateAccount(); // переход к созданию ящика
		return;
	}
	
	ui.m_pinfoSend    ->clear();
	ui.m_pinfoReceive ->clear();
	
	//m_pinfoReceive ->setText("AAAA");	
	
	if (m_pSocketPOP ->state() == QAbstractSocket::ConnectedState) 
		m_pSocketPOP ->abort();
	
/*................................
	m_pSocketPOP ->connectToHost(m_pcurrentAccount ->getHostPOP(), 
	                             m_pcurrentAccount ->getPortPOP().toUInt());
//..............................*/
//*.........................
    m_pSocketPOP ->connectToHostEncrypted(m_pcurrentAccount ->getHostPOP(), 
	                                       m_pcurrentAccount ->getPortPOP().toUInt());
//...............................*/
    
	setcommandsPOP(m_pcurrentAccount); // заполнение вектора командами для сервера

	m_k = 0;
    m_c = 0;
	m_number = 0;
	m_flagReadmessage = 0;
	
	//qDebug() << base64_decode("Pz8/Pz8/");
	//qDebug() << base64_decode(" =?WINDOWS-1251?B?6u7j5OAg/yDt4CDv7vfy5Q==?=");
	//qDebug() << base64_decode(" =?WINDOWS-1251?B?wOvl6vHl6Q==?=");

	//this ->receiveMessage();
//*------------------------------------------------------------------------------	
    
	QApplication::restoreOverrideCursor(); // возвращаем обычный курсор
	QApplication::setOverrideCursor(QCursor(Qt::WaitCursor)); // песочные часы
	
	QTextStream in (m_pSocketPOP);
	QTextStream out(m_pSocketPOP);
	QString str;
	QString word;
	m_c = 0;               // индекс, выводимого кода, в массиве
	m_k = 0;               // счётчик считанных писем
	m_number = 0;          // количество писем на сервере
	m_flagReadmessage = 0; // флаг чтения текста письма
	
	for (uint i = 0; i < 4; i++)
	{
		if (!m_pSocketPOP ->waitForReadyRead()) // если нет данных бельше, чем 30 сек.
		{
			qDebug() << "false";
			m_pSocketPOP ->abort();
			outputInfo(ui.m_pinfoReceive, arrInfo[REC_ERROR].strInfo + arrError[7], arrInfo[REC_ERROR].strSound); // сообщение - ошибка ("Неполадки в сети")
			
			QApplication::restoreOverrideCursor();
			return;
		}
	
	qDebug() << "true";
		ui.m_ptxtSender ->append(QWidget::tr("Новые данные сервера POP доступны для чтения."));
	
		in >> word;
		str = word + in.readAll(); // чтение сообщений сервера
		ui.m_ptxtSender ->append(str); // вывод сообщений сервера

		if (str[0] == '-') // если сервер выдал ошибку
		{ 
			m_pSocketPOP ->abort();
			outputInfo(ui.m_pinfoReceive, arrInfo[REC_ERROR].strInfo + arrError[m_c], arrInfo[REC_ERROR].strSound); // сообщение - ошибка
			
			QApplication::restoreOverrideCursor();
			return; 
		}
		
		outputCommands(ui.m_ptxtSender, vectorCommands[m_c], out); // отправка команд серверу
		m_c++;
		
	}

	if (!m_pSocketPOP ->waitForReadyRead()) // если нет данных бельше, чем 30 сек.
	{
		qDebug() << "false";
		m_pSocketPOP ->abort();
		outputInfo(ui.m_pinfoReceive, arrInfo[REC_ERROR].strInfo + arrError[7], arrInfo[REC_ERROR].strSound); // сообщение - ошибка ("Неполадки в сети")
		
		QApplication::restoreOverrideCursor();
		return;
	}
	 
  qDebug() << "true";
	ui.m_ptxtSender ->append(QWidget::tr("Новые данные сервера POP доступны для чтения."));

	in >> word;        // чтение ответа сервера после STAT
	if (word[0] == '-') 
	{ 
		str = word + in.readAll(); 
		ui.m_ptxtSender ->append(str); qDebug() << str;
		m_pSocketPOP ->abort();
		outputInfo(ui.m_pinfoReceive, arrInfo[REC_ERROR].strInfo + arrError[m_c], arrInfo[REC_ERROR].strSound); // сообщение - ошибка
		
		QApplication::restoreOverrideCursor();
		return; 
	}
		
	in >> m_number; // чтение количества писем
	str = word + " " + QString::number(m_number) + in.readAll(); // readAll() читает количество байтов
	ui.m_ptxtSender ->append(str); qDebug() << str;
		
	if (m_number == 0) // выход, если писем 0
	{
		m_pSocketPOP ->abort();
		outputInfo(ui.m_pinfoReceive, arrInfo[REC_INFO].strInfo, arrInfo[REC_INFO].strSound);
		
		QApplication::restoreOverrideCursor();
		return; 
	}
	
	// чтение текста писем
	m_k++;
	for (uint i = 0; i < m_number; i++)
	{	
		outputCommands(ui.m_ptxtSender, vectorCommands[m_c] + QString::number(m_k), out); // вывод RETR m_k
		m_c++;

	    QVector <QString> vecstr;
		vecstr.reserve(10000000);

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>		
		if (!reedTextMessage(m_pSocketPOP, in, ui.m_ptxtSender, vecstr)) // чтение текста письма в vecstr
		{
			m_pSocketPOP ->abort();
			outputInfo(ui.m_pinfoReceive, arrInfo[REC_ERROR].strInfo + arrError[7], arrInfo[REC_ERROR].strSound); // сообщение - ошибка
			
			QApplication::restoreOverrideCursor();

			vecstr.squeeze();
			return; 
		}  
		
		qDebug() << vecstr.size();
		
		QString fullstr;
		fullstr.reserve(10000000);
		
		for (int i = 0; i < vecstr.size(); i++) // создание строки с полными данными письма
	    {
			fullstr += vecstr[i];
		//	fullstr += '\n';
		}
		ui.m_ptxtSender ->append(fullstr); // вывод данных письма
	qDebug() << fullstr;
		
		if (vecstr[0][0] == '-') // проверка ответа сервера после RETR
		{
			m_pSocketPOP ->abort();
			outputInfo(ui.m_pinfoReceive, arrInfo[REC_ERROR].strInfo + arrError[m_c], arrInfo[REC_ERROR].strSound); // сообщение - ошибка
			
			QApplication::restoreOverrideCursor();

			vecstr .squeeze();
		    fullstr.squeeze();
			return; 
	    }

		// проверка, что письмо считано до конца
		if ( vecstr.last().size() >= 5 && vecstr.last().right(5) != (RN + "." + RN))
		{
			m_pSocketPOP ->abort();
			outputInfo(ui.m_pinfoReceive, arrInfo[REC_ERROR].strInfo + arrError[m_c], arrInfo[REC_ERROR].strSound); // сообщение - ошибка
			
			QApplication::restoreOverrideCursor();
			
			vecstr .squeeze();
		    fullstr.squeeze();
			return; 
		}
	
	//>>>>>>>>>>>>>>>>>>>>>>>>>>
		//чтение письма, извлечение нужных данных в Message, форматирование и сохранение в векторе
		m_pvectorMessageReceived ->push_back(formatMessage(extractfromString(fullstr)));

		ui.m_ptxtReceiver << m_pvectorMessageReceived ->last(); // вывод письма в поле Получение
		
		 m_pListMessageReceived << m_pvectorMessageReceived ->last(); // вывод письма в список полученных писем

		if (!writeObjectInFile(&m_pvectorMessageReceived ->last(), PATH_RECEIVER)) // записываем письмо в файл
					ui.m_ptxtMessage ->append(QWidget::tr("Ошибка открытия файла для записи!"));

		if (pPathAttachment != NULL) // удаляем путь к папке с прикреплёнными файлами
		{
			delete pPathAttachment;
			pPathAttachment = NULL;
		}
	//>>>>>>>>>>>>>>>>>>>>>>>>>>>
	
		vecstr .squeeze();
		fullstr.squeeze();
		
		if (m_pcurrentAccount ->getflagdele() == "1") // если удалять письма на сервере
				outputCommands(ui.m_ptxtSender, vectorCommands[m_c] + QString::number(m_k), out); // вывод DELE m_k
		else outputCommands(ui.m_ptxtSender, vectorCommands[m_c], out); // вывод NOOP
		
		m_c++;
		
		if (!m_pSocketPOP ->waitForReadyRead()) // если нет данных бельше, чем 30 сек.
		{
			qDebug() << "false";
			m_pSocketPOP ->abort();
			outputInfo(ui.m_pinfoReceive, arrInfo[REC_ERROR].strInfo + arrError[7], arrInfo[REC_ERROR].strSound); // сообщение - ошибка ("Неполадки в сети")
			
			QApplication::restoreOverrideCursor();
			return;
		}
		
	qDebug() << "true";
		ui.m_ptxtSender ->append(QWidget::tr("Новые данные сервера POP доступны для чтения."));

		str = in.readAll(); // чтение ответа сервера после DELE
		ui.m_ptxtSender ->append(str); qDebug() << str;
		
		if (str[0] == '-') 
		{ 
			m_pSocketPOP ->abort();
			outputInfo(ui.m_pinfoReceive, arrInfo[REC_ERROR].strInfo + arrError[m_c], arrInfo[REC_ERROR].strSound);
			
			QApplication::restoreOverrideCursor();
			return; 
		}
		
		m_k++;
		
		if (m_k > m_number) // если письма все прочитаны
		{
			QString str = numbermessage(m_k - 1);
			
			outputInfo(ui.m_pinfoReceive, arrInfo[REC_DONE].strInfo + str, arrInfo[REC_DONE].strSound); // сообщение - новая почта
			
			outputCommands(ui.m_ptxtSender, vectorCommands[m_c], out); // вывод QUIT
		}
		else m_c -= 2;

	 } // цикл for() чтения писем
	
	if (!m_pSocketPOP ->waitForReadyRead()) // если нет данных бельше, чем 30 сек.
	{
		qDebug() << "false";
		m_pSocketPOP ->abort();
		outputInfo(ui.m_pinfoReceive, arrInfo[REC_ERROR].strInfo + arrError[7], arrInfo[REC_ERROR].strSound); // сообщение - ошибка ("Неполадки в сети")
		
		QApplication::restoreOverrideCursor();
		return;
	}
	
  qDebug() << "true";
	ui.m_ptxtSender ->append(QWidget::tr("Новые данные сервера POP доступны для чтения."));
	
	str = in.readAll(); // чтение ответа сервера после QUIT
	ui.m_ptxtSender ->append(str); qDebug() << str;
	
	m_pSocketPOP ->abort();
	QApplication::restoreOverrideCursor();
//------------------------------------------------*/
}
	
//-----------------------------------------------------------------------------

void Post::slotReadyReadSMTP()
{
  //if (m_pSocketSMTP ->isEncrypted()) {qDebug() << "isEncrypted()"; qDebug() << "sessionCipher()" << m_pSocketSMTP ->sessionCipher();}
  
	ui.m_ptxtSender ->append(QWidget::tr("Новые данные сервера SMTP доступны для чтения."));
	
	QTextStream in (m_pSocketSMTP);
	QTextStream out(m_pSocketSMTP);

	uint i;
	
	in >> i;
	QString str = QString::number(i) + in.readAll();
	
    ui.m_ptxtSender ->append(str);

//* если галка не стоит, то автоматический ввод команд.........................................

if (ui.m_pCheckBox ->checkState() != Qt::Checked)
{
		
//...........................................................*/

//*/////////////////////////////////////////////////////	
	if (i != OK_code[m_c]) 
	{
		m_pSocketSMTP ->abort();
		flagErrorSend = 1;
		if (m_c != 9) // если ошибка не в ответ на QUIT, то вывод сообщения 
			outputInfo(ui.m_pinfoSend, arrInfo[SEND_ERROR].strInfo + arrError[m_c - 1], arrInfo[SEND_ERROR].strSound, SEND_ERROR);
		
		QApplication::restoreOverrideCursor();
		return;
	}

//--------------------------------------------------------------------------------------	
	if (m_c <= 6)
	{   
// вывод команды "MAIL FROM: <alsav22@rambler.ru>" //(оставляем от from часть, начиная с '<')                 
		if (m_c == 4) 
		    outputCommands(ui.m_ptxtSender, vectorCommands[m_c], out);
		
	    else if (m_c == 5) // вывод команды "RCPT TO: <alsav22@rambler.ru>"
		         outputCommands(ui.m_ptxtSender, vectorCommands[m_c], out);
		                                  
			 
			 else outputCommands(ui.m_ptxtSender, vectorCommands[m_c], out);
		
		++m_c;
		//qDebug() << "m_c = " << m_c;
		return;
	}
//---------------------------------------------------------------------------------------	
	if (m_c == 7)  
	{
		QString ss = m_pcurrentMessage ->getfrom();
		
		out << "From: "    + m_pcurrentMessage ->getfrom()    + RN; 
		out	<< "To: "      + m_pcurrentMessage ->getto()      + RN;
		out << "Subject: " + m_pcurrentMessage ->getsubject() + RN + RN; 
		
		out << m_pcurrentMessage ->gettext() 
		<< RN + "." + RN;
		
		
		ui.m_ptxtSender ->append("From: "    + m_pcurrentMessage ->getfrom() + RN); 
		ui.m_ptxtSender ->append("To: "      + m_pcurrentMessage ->getto()      + RN);
		ui.m_ptxtSender ->append("Subject: " + m_pcurrentMessage ->getsubject() + RN + RN); 
		
		ui.m_ptxtSender ->append(m_pcurrentMessage ->gettext() + RN + "." + RN);
		

		++m_c;
		return;

	}
//-----------------------------------------------------------------------------------------	
	if (m_c == 8) 
	{
	    outputCommands(ui.m_ptxtSender, vectorCommands[m_c - 1], out); // вывод QUIT
		
		ui.m_ptxtMessage ->clear();
		
		outputInfo(ui.m_pinfoSend, arrInfo[SEND_DONE].strInfo, arrInfo[SEND_DONE].strSound, SEND_DONE); // успешно отправлено
		flagErrorSend = 0;
		
		//undoselected(ui.m_pListAddress); // сброс, если есть, выделения адреса
		QApplication::restoreOverrideCursor(); // возвращаем обычный курсор
		
  //----------------------------------
		m_pvectorMessageSend ->push_back(formatMessage(*m_pcurrentMessage)); // форматируем письмо и сохраняем в векторе

		m_pListMessageSend << m_pvectorMessageSend ->last(); // выводим письмо в список отправленных писем
		
		if (!writeObjectInFile(&m_pvectorMessageSend ->last(), PATH_SENDER)) // записываем в файл
		          ui.m_ptxtMessage ->append(QWidget::tr("Ошибка открытия файла для записи!"));
		
  //-----------------------------------
		m_c++;
		
		return;
	}
//////////////////////////////////////////////////////*/
} // if () (ручной ввод команд)

//} // if () isEncrypted()
//else if (ui.m_ptxtSender != NULL) ui.m_ptxtSender ->append("isEncrypted() == false");

}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void Post::slotReadyReadPOP()
{
	ui.m_ptxtSender ->append(QWidget::tr("Новые данные сервера POP доступны для чтения."));
	//qDebug() << m_flagReadmessage << ' ' << m_c;
	
	QTextStream in (m_pSocketPOP);
	QTextStream out(m_pSocketPOP);

	qDebug() << m_pSocketPOP ->peerName();

	QString Str;
	QString List;

if (ui.m_pCheckBox ->checkState() == Qt::Checked) // ручной ввод команд
{
	//if (m_pSocketPOP ->waitForReadyRead(1000)) qDebug() << "true";
	//else qDebug() << "false";
	in >> List;
	Str = List + in.readAll(); // чтение сообщений сервера
	
	ui.m_ptxtSender ->append(Str); // вывод сообщений сервера
	
}
else // автоматический ввод команд
{
	if (m_c <= 3)
	{
		Str = in.readAll(); // чтение сообщений сервера
		ui.m_ptxtSender ->append(Str); qDebug() << Str;
	
		if (Str[0] == '-') // если сервер выдал ошибку
		{ 
			m_pSocketPOP ->abort();
			outputInfo(ui.m_pinfoReceive, arrInfo[REC_ERROR].strInfo, arrInfo[REC_ERROR].strSound); // сообщение - ошибка
			return; 
		}
		
		outputCommands(ui.m_ptxtSender, vectorCommands[m_c], out); // отправка команд серверу
		m_c++;
		
		return;
	}
	
	if (m_c == 4) // чтение сообщения после STAT 
	{
	    in >> List;
		if (List[0] == '-') 
		{ 
			Str = List + in.readAll(); 
			ui.m_ptxtSender ->append(Str); qDebug() << Str;
			m_pSocketPOP ->abort();
			outputInfo(ui.m_pinfoReceive, arrInfo[REC_ERROR].strInfo, arrInfo[REC_ERROR].strSound); // сообщение - ошибка
			return; 
		}
		
		in >> m_number; // чтение количества писем
		Str = List + " " + QString::number(m_number) + in.readAll(); // readAll() читает количество байтов
		ui.m_ptxtSender ->append(Str); qDebug() << Str;
		
		if (m_number == 0) // выход, если писем 0
		{
			m_pSocketPOP ->abort();
			outputInfo(ui.m_pinfoReceive, arrInfo[REC_INFO].strInfo, arrInfo[REC_INFO].strSound);
			return; 
		}
		
		outputCommands(ui.m_ptxtSender, vectorCommands[m_c] + QString::number(++m_k), out); // вывод RETR
		m_c++;
		
		return;
	}
	
	if (m_c == 5 /*&& m_flagReadmessage = 0;*/) 
	{
		
		if (m_flagReadmessage == 0)
		{
			List = in.readLine(); // чтение ответа сервера после RETR
			ui.m_ptxtSender ->append(List); qDebug() << List; qDebug() << "in.atEnd() = " << in.atEnd();
			
			if (List[0] == '-') 
			{ 
				m_pSocketPOP ->abort();
				outputInfo(ui.m_pinfoReceive, arrInfo[REC_ERROR].strInfo, arrInfo[REC_ERROR].strSound);
				return; 
			}
			if (m_pSocketPOP ->peerName() != "pop.gmail.com")
			{
				m_flagReadmessage = 1;
				return;
			}
		}
	    if (m_flagReadmessage == 1 || m_pSocketPOP ->peerName() == "pop.gmail.com")
		{
			
			/*if (m_pSocketPOP ->waitForReadyRead(3000)) qDebug() << "true";
			else qDebug() << "false";*/
			//qDebug() << "signalsBlocked() = " << m_pSocketPOP ->signalsBlocked();
			//qDebug() << in.device() ->bytesAvailable();
	  
			//чтение письма, извлечение нужных данных, форматирование, сохранение и вывод обработанного письма
			m_pvectorMessageReceived ->push_back(formatMessage(readMessagePOP(/*m_pSocketPOP, */in, ui.m_ptxtSender, ui.m_ptxtReceiver, m_k)));

			ui.m_ptxtReceiver << m_pvectorMessageReceived ->last(); // вывод письма в поле Получение 

			if (!writeObjectInFile(&m_pvectorMessageReceived ->last(), PATH_RECEIVER)) // записываем письмо в файл
						ui.m_ptxtMessage ->append(QWidget::tr("Ошибка открытия файла для записи!"));
		
			outputCommands(ui.m_ptxtSender, vectorCommands[m_c] + QString::number(m_k), out); // вывод DELE 1
			m_c++;
			
		return;
		}
	}
	
	if (m_c == 6) 
	{
		Str = List + in.readAll(); // чтение ответа сервера после DELE
		ui.m_ptxtSender ->append(Str); qDebug() << Str;
		if (List[0] == '-') 
		{ 
			m_pSocketPOP ->abort();
			outputInfo(ui.m_pinfoReceive, arrInfo[REC_ERROR].strInfo, arrInfo[REC_ERROR].strSound);
			return; 
		}
		
		m_k++;
		
		if (m_k > m_number) // если письма все прочитаны
		{
			outputInfo(ui.m_pinfoReceive, arrInfo[REC_DONE].strInfo, arrInfo[REC_DONE].strSound); // сообщение - новая почта
			
			outputCommands(ui.m_ptxtSender, vectorCommands[m_c], out); // вывод QUIT
			m_c++;
		    return;
		}
		else
		{
			m_c -= 2;
			outputCommands(ui.m_ptxtSender, vectorCommands[m_c] + QString::number(m_k), out); // вывод RETR m_k
			m_c++;
			m_flagReadmessage = 0;
			
			return; 
		}
	}
		
	Str = List + in.readAll(); // чтение ответа сервера после QUIT
	ui.m_ptxtSender ->append(Str); qDebug() << Str;

	m_pSocketPOP ->abort();
 
} // else (ручной ввод команд)

} // end slot
//..........................*/
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//.................................................................................

void Post::slotConnectedSMTP()
{
	ui.m_ptxtSender ->append(QWidget::tr("Соединения с сервером SMTP установлено."));
}

//----------------------------------------------------------------------------------

void Post::slotConnectedPOP()
{
     ui.m_ptxtSender ->append(QWidget::tr("Соединение с сервером POP установлено."));
}

//----------------------------------------------------------------------

void Post::slotErrorSMTP(QAbstractSocket::SocketError err)
{
  if (err == QAbstractSocket::HostNotFoundError/* || QAbstractSocket::UnknownSocketError*/)
         outputInfo(ui.m_pinfoSend, arrInfo[SEND_ERROR].strInfo + "\nПроверьте соединение с интернетом.", arrInfo[SEND_ERROR].strSound);
		                                                        
    QString strError = 
        QWidget::tr("Ошибка: ") + (err == QAbstractSocket::HostNotFoundError ? 
                     QWidget::tr("Хост не найден.") : //"The host was not found." :
                     err == QAbstractSocket::RemoteHostClosedError ? 
                     QWidget::tr("Удалённый хост закрыт.")/*"The remote host is closed."*/ :
                     err == QAbstractSocket::ConnectionRefusedError ? 
                     QWidget::tr("В соединении отказано.") : //"The connection was refused." :
                     QString(m_pSocketSMTP ->errorString())
                    );
    
		ui.m_ptxtSender ->append(strError);
		
		QApplication::restoreOverrideCursor(); // возвращаем обычный курсор
		
}

//---------------------------------------------------------------------------

void Post::slotErrorPOP(QAbstractSocket::SocketError err)
{
    if (err == QAbstractSocket::HostNotFoundError/* || QAbstractSocket::UnknownSocketError*/)
         outputInfo(ui.m_pinfoReceive, arrInfo[REC_ERROR].strInfo + "\nПроверьте соединение с интернетом.", arrInfo[REC_ERROR].strSound);
   
    QString strError = 
        "Error: " + (err == QAbstractSocket::HostNotFoundError ? 
                      QWidget::tr("Хост не найден.") : //"The host was not found." :
                     err == QAbstractSocket::RemoteHostClosedError ? 
                     QWidget::tr("Удалённый хост закрыт.")/*"The remote host is closed."*/ :
                     err == QAbstractSocket::ConnectionRefusedError ? 
                     QWidget::tr("В соединении отказано.") : //"The connection was refused." :
                     QString(m_pSocketPOP ->errorString())
                    );
    
		ui.m_ptxtSender ->append(strError);

		QApplication::restoreOverrideCursor(); // возвращаем обычный курсор
}


void Post::slotCreateAccount()
{
	ui.m_pinfoSend    ->clear();
	//ui.m_pinfoReceive ->clear();
	
	QString strsender;
	if (m_pcurrentAccount == NULL) // если первое создание ящика
	{ 
		m_pcurrentAccount = new Account;
		strsender = "buttonCreateAccount";
	}
	else strsender = sender() ->objectName(); // если ящик уже есть, то в зависимости от кнопки
	
	m_pсreateAccount = new CreateAccount(strsender); // объект класса-наследника класса QDialog

begin : 
  
  // если ящик существует и нажата Изменить ящик
	if (m_pcurrentAccount != NULL && strsender == "buttonSettingsAccount")
	{
		m_pсreateAccount ->setname    (m_pcurrentAccount ->getname());
		m_pсreateAccount ->setlogin   (m_pcurrentAccount ->getlogin());
		m_pсreateAccount ->setpassword(m_pcurrentAccount ->getpassword());
		m_pсreateAccount ->sete_mail  (m_pcurrentAccount ->gete_mail());
		m_pсreateAccount ->setHostSMTP(m_pcurrentAccount ->getHostSMTP());
		m_pсreateAccount ->setHostPOP (m_pcurrentAccount ->getHostPOP ());
		m_pсreateAccount ->setPortSMTP(m_pcurrentAccount ->getPortSMTP());
		m_pсreateAccount ->setPortPOP (m_pcurrentAccount ->getPortPOP());
		
		if (m_pcurrentAccount ->getflagdele() == "1")
			m_pсreateAccount ->setstatecheckbox(Qt::Checked);
	}
	else 
	{
		m_pсreateAccount ->setPortSMTP("465");
		m_pсreateAccount ->setPortPOP ("995");
	}

	if (m_pсreateAccount ->exec() == QDialog::Accepted)
	{
	  // если ящик есть, то сохраняем на время
		Account temp;
		if (m_pcurrentAccount != NULL) 
			temp = *m_pcurrentAccount; 
			
		m_pcurrentAccount ->setname          (m_pсreateAccount  ->getname    ());
		m_pcurrentAccount ->setlogin         (m_pсreateAccount  ->getlogin   ());
		m_pcurrentAccount ->setloginBase64   (base64_encode(m_pcurrentAccount ->getlogin(), 
		                                      m_pcurrentAccount ->getlogin().size()));
		m_pcurrentAccount ->setpassword      (m_pсreateAccount  ->getpassword());
		m_pcurrentAccount ->setpasswordBase64(base64_encode(m_pcurrentAccount ->getpassword(), 
		                                      m_pcurrentAccount ->getpassword().size()));
		m_pcurrentAccount ->sete_mail        (m_pсreateAccount  ->gete_mail  ());
		m_pcurrentAccount ->setHostSMTP      (m_pсreateAccount  ->getHostSMTP());
		m_pcurrentAccount ->setHostPOP       (m_pсreateAccount  ->getHostPOP ());
		m_pcurrentAccount ->setPortSMTP      (m_pсreateAccount  ->getPortSMTP());
		m_pcurrentAccount ->setPortPOP       (m_pсreateAccount  ->getPortPOP ());
		
		if (m_pсreateAccount   ->getstatecheckbox() == Qt::Checked) // если удалять письма на сервере
			m_pcurrentAccount  ->setflagdele ("1");
		else m_pcurrentAccount ->setflagdele ("0");
	    
		// создаётся новый файл (или старый стирается)
			QFile file(PATH_ACCOUNT);
			if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) // если ошибка при записи в файл
			{
				*m_pcurrentAccount = temp; // возвращаем старый ящик
				//delete m_pсreateAccount;
				
				if(strsender == "buttonCreateAccount")
					QMessageBox::critical(0, QWidget::tr("Ошибка!"), QWidget::tr("Ошибка при создании ящика!\nЯщик не сохранён."));
				if(strsender == "buttonSettingsAccount")
					QMessageBox::critical(0, QWidget::tr("Ошибка!"), QWidget::tr("Ошибка при изменении ящика!\nЯщик не сохранён."));
				
				goto begin;
				//return;
			}
			else
			{
				QTextStream fout(&file);
				fout << *m_pcurrentAccount; // запись ящика в файл (с кодированием пароля в двух видах)
			    file.close();
			}
			
		// заполнение векторов командами для серверов	
			//setcommands(m_pcurrentAccount);
		    
			ui.m_pAccountInfo ->setText(m_pcurrentAccount ->gete_mail()); // вывод e-mail ящика в поле Ящик
		
            m_flagExistAccount = 1; // ящик существует

			if(strsender == "buttonCreateAccount")
				QMessageBox::information(0, QWidget::tr("Сообщение"), QWidget::tr("Ящик успешно создан!"));
			
			if(strsender == "buttonSettingsAccount")
				QMessageBox::information(0, QWidget::tr("Сообщение"), QWidget::tr("Ящик успешно изменён!"));
		
		}
	
	delete m_pсreateAccount;
}

//.........................................................................

void Post::slotCreateAddress()
{
	if (this ->m_flagExistAccount == 0) // если ящика не существует
	{
	    if (messageAccount() == QMessageBox::Yes) // если Yes
	            this ->slotCreateAccount(); // переход к созданию ящика
		return;
	}
	
	ui.m_pinfoSend    ->clear();
	//ui.m_pinfoReceive ->clear();

	CreateAddress *pCreateAddress = new CreateAddress; // окно диалога

begin :
	if (pCreateAddress ->exec() == QDialog::Accepted)
	{
		if (pCreateAddress  ->getname().isEmpty()) // если нажата ОК, но имя не задано
		{
			
			QMessageBox::critical(0, QWidget::tr("Ошибка!"), QWidget::tr("Ошибка при создании адреса! Задайте имя."));
			goto begin;
		}
		
		Address *newaddress = new Address;
		if (readObjectFromVector(newaddress, m_pvectorAddress,  pCreateAddress  ->gete_mail()) != -1) 
		{         
              pCreateAddress  ->sete_mail("");
			  delete newaddress;
			  QMessageBox::critical(0, QWidget::tr("Ошибка!"), QWidget::tr("Ошибка при создании адреса!\nАдрес с таким e-mail уже существует."));
			  goto begin; 
		}
		
		newaddress ->setname  (pCreateAddress  ->getname  ());
		newaddress ->sete_mail(pCreateAddress  ->gete_mail());
		
		if (pCreateAddress  ->getimage().isEmpty()) newaddress ->setimage("nofoto.png"); // если фото не указано
		else newaddress ->setimage (pCreateAddress ->getimage ());

		m_pvectorAddress ->push_back(*newaddress); // сохраняем новый адресс в массиве адресов
        
		writeObjectInFile(newaddress, PATH_ADDRESS); // запись адреса в файл
		
	// вывод нового адреса в поле Адреса
		ui.m_pListAddress << *newaddress;

		delete newaddress;
		QMessageBox::information(0, QWidget::tr("Сообщение"), QWidget::tr("Адрес успешно создан!"));
	}	
	
	delete pCreateAddress;
	
}

//.........................................................................

void Post::slotChoiceAddress(QListWidgetItem *plistwidgetitem)
{
	//qDebug() << ui.m_pListAddress ->row(plistwidgetitem);
	
	if (this ->m_flagExistAccount == 0) // если ящика не существует
	{
	    if (messageAccount() == QMessageBox::Yes) // если Yes
	            this ->slotCreateAccount(); // переход к созданию ящика
		return;
	}
	
	ui.m_pinfoSend    ->clear();
    //ui.m_ptxtMessage ->clear();
	//ui.m_pinfoReceive ->clear();

	*m_pcurrentAddress = (*m_pvectorAddress)[ui.m_pListAddress ->row(plistwidgetitem)]; // поиск в векторе по номеру в списке
	
    ui.m_pTo ->setText(m_pcurrentAddress ->gete_mail()); // установка в поле Кому e-mail выбранного адреса

}

//.........................................................................


void Post::slotSettingsAddress()
{
	if (this ->m_flagExistAccount == 0) // если ящика не существует
	{
	    if (messageAccount() == QMessageBox::Yes) // если Yes
	            this ->slotCreateAccount(); // переход к созданию ящика
		return;
	}
	
	ui.m_pinfoSend    ->clear();
	ui.m_pinfoReceive ->clear();
	
	if (m_pvectorAddress ->isEmpty())
	{
		QMessageBox::warning(0, QWidget::tr("Внимание!"), QWidget::tr("Адресов нет! Добавьте адрес."));
		return;
	}
	
	SettingsAddress *pSettingsAddress = new SettingsAddress(m_pvectorAddress); // окно диалога
	pSettingsAddress ->resize(200, 650);

begin :	
	if (pSettingsAddress ->exec() == QDialog::Accepted)
	{
		if (pSettingsAddress ->getname().isEmpty()) // если нажата OK, но ничего не выбрано
		{
			QMessageBox::critical(0, QWidget::tr("Ошибка!"), QWidget::tr("Ошибка при изменении адреса! Адрес не выбран."));
			goto begin;
		} 
		
		if (pSettingsAddress ->getstatecheckbox() != Qt::Checked) // если адрес не удаляется
		{
			
			Address *newaddress = new Address;

			if (readObjectFromVector(newaddress, m_pvectorAddress,  pSettingsAddress  ->gete_mail()) != -1) 
			{         
				  pSettingsAddress  ->sete_mail("");
				  delete newaddress;
				  QMessageBox::critical(0, QWidget::tr("Ошибка!"), QWidget::tr("Ошибка при изменении адреса!\nАдрес с таким e-mail уже существует."));
				  goto begin; 
			}
		
			newaddress ->setname  (pSettingsAddress  ->getname  ());
			newaddress ->sete_mail(pSettingsAddress  ->gete_mail());
			newaddress ->setimage (pSettingsAddress  ->getimage ());

			Address temp = (*m_pvectorAddress)[pSettingsAddress  ->geti()]; // схраняем старый адрес

			(*m_pvectorAddress)[pSettingsAddress  ->geti()] = *newaddress; // помещаем новый адрес в вектор вместо старого 
																		   // (geti() возвращает индекс выбранного адреса в векторе)
		// запись изменённого вектора в новый файл
			if (!writeVectorInFile(m_pvectorAddress, PATH_ADDRESS)) // если ошибка при записи
			{
				(*m_pvectorAddress)[pSettingsAddress  ->geti()] = temp; // возвращаем старый адрес в вектор
				
				delete newaddress;
				QMessageBox::critical(0, QWidget::tr("Ошибка!"), QWidget::tr("Ошибка при изменении адреса! Изменения не сохранены."));
				goto begin;
			}
			
			ui.m_pTo ->clear(); // очищаем поле Кому (возможно, там прописан старый адрес)
			
		// очищаем и заполняем поле Адреса
			ui.m_pListAddress ->clear(); 
			readVectorInListWidget(m_pvectorAddress, ui.m_pListAddress);
		
			delete newaddress;
			QMessageBox::information(0, QWidget::tr("Сообщение"), QWidget::tr("Адрес успешно изменён!"));
		}
		else // если адрес удаляется
		{
			Address temp = (*m_pvectorAddress)[pSettingsAddress  ->geti()]; // схраняем удаляемый адрес

			m_pvectorAddress ->removeAt(pSettingsAddress  ->geti()); // удаляем адрес из вектора 
																   // (geti() возвращает индекс выбранного адреса в векторе)
		// запись изменённого вектора в новый файл
			if (!writeVectorInFile(m_pvectorAddress, PATH_ADDRESS)) // если ошибка при записи
			{
				(*m_pvectorAddress)[pSettingsAddress  ->geti()] = temp; // возвращаем старый адрес в вектор
				
				QMessageBox::critical(0, QWidget::tr("Ошибка!"), QWidget::tr("Ошибка при удалении адреса! Изменения не сохранены."));
				goto begin;
			}
			
			ui.m_pListAddress ->clear(); // очищаем и заполняем поле Адреса
			readVectorInListWidget(m_pvectorAddress, ui.m_pListAddress);
		    
			QMessageBox::information(0, QWidget::tr("Сообщение"), QWidget::tr("Адрес успешно удалён!"));
		}
	}

	delete pSettingsAddress;
}

//..........................................................................

void Post::slotSettings()
{
	if (this ->m_flagExistAccount == 0) // если ящика не существует
	{
	    if (messageAccount() == QMessageBox::Yes) // если Yes
	            this ->slotCreateAccount(); // переход к созданию ящика
		return;
	}

	ui.m_pinfoSend    ->clear();
	//ui.m_pinfoReceive ->clear();
}

//..........................................................................

void Post::slottextChanged(const QString &text)
{
	ui.m_pinfoSend ->clear();
	if (sender() ->objectName() == "m_pTo") // если изменение в поле Кому
	{	
		if (!m_pvectorAddress ->isEmpty()) // если адреса есть
		{
			// ищем в векторе адрес с таким e_mail, если найден, то будет текущим
			int index = readObjectFromVector(m_pcurrentAddress, m_pvectorAddress, text);
		
			// если адрес с таким e_mail есть, то выделяем в списке
			if (index != -1)
				ui.m_pListAddress     ->setCurrentRow(index);
		
			else // если нет в списке
			{
				undoselected(ui.m_pListAddress); // если что-то выделено, то снимаем выделение
				
				// создаём пустой адрес и присваиваем его текущему (делаем текущий пустым)
				Address empty;
				*m_pcurrentAddress = empty;

				m_pcurrentAddress ->sete_mail(text); // в текущий адрес устанавливаем e_mail с поля Кому.
													 // Остальное в текущем будет пустым.
			}	
		}
		else m_pcurrentAddress ->sete_mail(text); // если нет адресов, то в текущий адрес 
												  // устанавливаем e_mail с поля Кому. Остальное в текущем будет пустым.
	}
}

void Post::slotChoiceMessage(QListWidgetItem *)
{
	
}

//..........................................................................

void Post::slotOutMessage()
{
	if (this ->m_flagExistAccount == 0) // если ящика не существует
	{
	    if (messageAccount() == QMessageBox::Yes) // если Yes
	            this ->slotCreateAccount(); // переход к созданию ящика
		return;
	}
	
	ui.m_pinfoSend    ->clear();
	
	if (sender() ->objectName() == "buttonReceived")
	{
		if (m_pvectorMessageReceived ->isEmpty())
		{
			QMessageBox::warning(0, QWidget::tr("Внимание!"), QWidget::tr("Полученных писем нет!"));
			return;
		}
		

		ui.m_pinfoReceive ->clear();
		ui.m_ptxtReceiver ->clear();

		QApplication::setOverrideCursor(QCursor(Qt::WaitCursor)); // песочные часы
		readVectorInEdit(m_pvectorMessageReceived, ui.m_ptxtReceiver);
		QApplication::restoreOverrideCursor(); // возвращаем обычный курсор

		m_pListMessageReceived ->resize(700, 600);
		//m_pListMessageReceived ->sortItems(Qt::DescendingOrder);
		//m_pListMessageReceived ->sortItems(Qt::AscendingOrder);

		m_pListMessageReceived ->show();
	}
	
	if (sender() ->objectName() == "buttonSend")
	{
		if (m_pvectorMessageSend ->isEmpty())
		{
			QMessageBox::warning(0, QWidget::tr("Внимание!"), QWidget::tr("Отправленных писем нет!"));
			return;
		}
		ui.m_ptxtMessage ->clear();

		QApplication::setOverrideCursor(QCursor(Qt::WaitCursor)); // песочные часы
		readVectorInEdit(m_pvectorMessageSend, ui.m_ptxtMessage);
		QApplication::restoreOverrideCursor(); // возвращаем обычный курсор

		m_pListMessageSend ->resize(700, 600);
		m_pListMessageSend ->show();
	}
}

//..........................................................................

void Post::slotClear()
{
	if (sender() ->objectName() == "pcmd_clearreceive")
	{
		ui.m_pinfoReceive ->clear();
		ui.m_ptxtReceiver ->clear();
		ui.m_ptxtSender   ->clear();
	}

	if (sender() ->objectName() == "pcmd_clearsend")
	{
		ui.m_pinfoSend    ->clear();
		ui.m_ptxtMessage  ->clear();
	}
}

//..........................................................................

void Post::slotSendToServer()
{
	QTextStream out;
	if (m_pSocketPOP ->state() == QAbstractSocket::UnconnectedState)
		out.setDevice(m_pSocketSMTP);
	else out.setDevice(m_pSocketPOP);
	
	QString str = ui.m_pinput_comServer ->text();

	ui.m_ptxtSender ->append(str + RN);
    out << str + RN;
}


void Post::slotHelp()
{
	if (this ->m_flagExistAccount == 0) // если ящика не существует
	{
	    if (messageAccount() == QMessageBox::Yes) // если Yes
	            this ->slotCreateAccount(); // переход к созданию ящика
		return;
	}
	qDebug() << "destroyed()";
}


void Post::slotReadySSL(QListWidgetItem *p)
{
	if (this ->m_flagExistAccount == 0) // если ящика не существует
	{
	    if (messageAccount() == QMessageBox::Yes) // если Yes
	            this ->slotCreateAccount(); // переход к созданию ящика
		return;
	}
	
	//qDebug() << "slotReadySSL()";
	qDebug() << p ->text();
	
}


// создание строки для вывода количества полученных писем
QString numbermessage(uint n)
{
	QString number = QString::number(n);
	QString str;
	if (n > 10 && n < 20) str = " писем.";
	else
	{
		if (number.right(1) == "1") str = " письмо.";
		if (number.right(1) > "1" && number.right(1) < "5") str = " письма.";
		if (number.right(1) == "0" || (number.right(1) > "4" && number.right(1) < "9") || number.right(1) == "9") str = " писем.";
	}

	return (" " + number + str);
}

// получение писем. Добавить в слот slotReceiveMessage()
void Post::receiveMessage()
{
	QTextStream in (m_pSocketPOP);
	QTextStream out(m_pSocketPOP);
	QString str;
	QString word;
	m_c = 0;               // индекс, выводимого кода, в массиве
	m_k = 0;               // счётчик считанных писем
	m_number = 0;          // количество писем на сервере
	m_flagReadmessage = 0; // флаг чтения текста письма
	
	for (uint i = 0; i < 4; i++)
	{
		if (!m_pSocketPOP ->waitForReadyRead()) // если нет данных бельше, чем 30 сек.
		{
			qDebug() << "false";
			m_pSocketPOP ->abort();
			outputInfo(ui.m_pinfoReceive, arrInfo[REC_ERROR].strInfo + arrError[7], arrInfo[REC_ERROR].strSound); // сообщение - ошибка ("Неполадки в сети")
			return;
		}
	
	qDebug() << "true";
		ui.m_ptxtSender ->append(QWidget::tr("Новые данные сервера POP доступны для чтения."));
	
		in >> word;
		str = word + in.readAll(); // чтение сообщений сервера
		ui.m_ptxtSender ->append(str); // вывод сообщений сервера

		if (str[0] == '-') // если сервер выдал ошибку
		{ 
			m_pSocketPOP ->abort();
			outputInfo(ui.m_pinfoReceive, arrInfo[REC_ERROR].strInfo + arrError[m_c], arrInfo[REC_ERROR].strSound); // сообщение - ошибка
			return; 
		}
		
		outputCommands(ui.m_ptxtSender, vectorCommands[m_c], out); // отправка команд серверу
		m_c++;
		
	}

	if (!m_pSocketPOP ->waitForReadyRead()) // если нет данных бельше, чем 30 сек.
	{
		qDebug() << "false";
		m_pSocketPOP ->abort();
		outputInfo(ui.m_pinfoReceive, arrInfo[REC_ERROR].strInfo + arrError[7], arrInfo[REC_ERROR].strSound); // сообщение - ошибка ("Неполадки в сети")
		return;
	}
	 
  qDebug() << "true";
	ui.m_ptxtSender ->append(QWidget::tr("Новые данные сервера POP доступны для чтения."));

	in >> word;        // чтение ответа сервера после STAT
	if (word[0] == '-') 
	{ 
		str = word + in.readAll(); 
		ui.m_ptxtSender ->append(str); qDebug() << str;
		m_pSocketPOP ->abort();
		outputInfo(ui.m_pinfoReceive, arrInfo[REC_ERROR].strInfo + arrError[m_c], arrInfo[REC_ERROR].strSound); // сообщение - ошибка
		return; 
	}
		
	in >> m_number; // чтение количества писем
	str = word + " " + QString::number(m_number) + in.readAll(); // readAll() читает количество байтов
	ui.m_ptxtSender ->append(str); qDebug() << str;
		
	if (m_number == 0) // выход, если писем 0
	{
		m_pSocketPOP ->abort();
		outputInfo(ui.m_pinfoReceive, arrInfo[REC_INFO].strInfo, arrInfo[REC_INFO].strSound);
		return; 
	}
	
	// чтение текста писем
	m_k++;
	for (uint i = 0; i < m_number; i++)
	{	
		outputCommands(ui.m_ptxtSender, vectorCommands[m_c] + QString::number(m_k), out); // вывод RETR m_k
		m_c++;

	    QVector <QString> vecstr;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>		
		if (!reedTextMessage(m_pSocketPOP, in, ui.m_ptxtSender, vecstr)) // чтение текста письма в vecstr
		{
			m_pSocketPOP ->abort();
			outputInfo(ui.m_pinfoReceive, arrInfo[REC_ERROR].strInfo + arrError[7], arrInfo[REC_ERROR].strSound); // сообщение - ошибка
			return; 
		}  
		
		qDebug() << vecstr.size();
		
		QString fullstr;
		for (int i = 0; i < vecstr.size(); i++) // создание строки с полными данными письма
	    {
			fullstr += vecstr[i];
		//	fullstr += '\n';
		}
		ui.m_ptxtSender ->append(fullstr); // вывод данных письма
		qDebug() << fullstr;
		
		if (vecstr[0][0] == '-') // проверка ответа сервера после RETR
		{
			m_pSocketPOP ->abort();
			outputInfo(ui.m_pinfoReceive, arrInfo[REC_ERROR].strInfo + arrError[m_c], arrInfo[REC_ERROR].strSound); // сообщение - ошибка
			return; 
	    }

		// проверка, что письмо считано до конца
		if ( vecstr.last().size() >= 5 && vecstr.last().right(5) != (RN + "." + RN))
		{
			m_pSocketPOP ->abort();
			outputInfo(ui.m_pinfoReceive, arrInfo[REC_ERROR].strInfo + arrError[m_c], arrInfo[REC_ERROR].strSound); // сообщение - ошибка
			return; 
		}
	
	//>>>>>>>>>>>>>>>>>>>>>>>>>>
		//чтение письма, извлечение нужных данных в Message, форматирование и сохранение в векторе
		m_pvectorMessageReceived ->push_back(formatMessage(extractfromString(fullstr)));

		ui.m_ptxtReceiver << m_pvectorMessageReceived ->last(); // вывод письма в поле Получение 

		if (!writeObjectInFile(&m_pvectorMessageReceived ->last(), PATH_RECEIVER)) // записываем письмо в файл
					ui.m_ptxtMessage ->append(QWidget::tr("Ошибка открытия файла для записи!"));
	//>>>>>>>>>>>>>>>>>>>>>>>>>>>	
		
		outputCommands(ui.m_ptxtSender, vectorCommands[m_c] + QString::number(m_k), out); // вывод DELE m_k
		m_c++;
		
		if (!m_pSocketPOP ->waitForReadyRead()) // если нет данных бельше, чем 30 сек.
		{
			qDebug() << "false";
			m_pSocketPOP ->abort();
			outputInfo(ui.m_pinfoReceive, arrInfo[REC_ERROR].strInfo + arrError[7], arrInfo[REC_ERROR].strSound); // сообщение - ошибка ("Неполадки в сети")
			return;
		}
		
	qDebug() << "true";
		ui.m_ptxtSender ->append(QWidget::tr("Новые данные сервера POP доступны для чтения."));

		str = in.readAll(); // чтение ответа сервера после DELE
		ui.m_ptxtSender ->append(str); qDebug() << str;
		
		if (str[0] == '-') 
		{ 
			m_pSocketPOP ->abort();
			outputInfo(ui.m_pinfoReceive, arrInfo[REC_ERROR].strInfo + arrError[m_c], arrInfo[REC_ERROR].strSound);
			return; 
		}
		
		m_k++;
		
		if (m_k > m_number) // если письма все прочитаны
		{
			QString str = numbermessage(m_k - 1);
			
			outputInfo(ui.m_pinfoReceive, arrInfo[REC_DONE].strInfo + str, arrInfo[REC_DONE].strSound); // сообщение - новая почта
			
			outputCommands(ui.m_ptxtSender, vectorCommands[m_c], out); // вывод QUIT
		}
		else m_c -= 2;
		
	} // цикл for() чтения писем
	
	if (!m_pSocketPOP ->waitForReadyRead()) // если нет данных бельше, чем 30 сек.
	{
		qDebug() << "false";
		m_pSocketPOP ->abort();
		outputInfo(ui.m_pinfoReceive, arrInfo[REC_ERROR].strInfo + arrError[7], arrInfo[REC_ERROR].strSound); // сообщение - ошибка ("Неполадки в сети")
		return;
	}
	
  qDebug() << "true";
	ui.m_ptxtSender ->append(QWidget::tr("Новые данные сервера POP доступны для чтения."));
	
	str = in.readAll(); // чтение ответа сервера после QUIT
	ui.m_ptxtSender ->append(str); qDebug() << str;
	
	m_pSocketPOP ->abort();
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// чтение текста всего письма в вектор строк
bool reedTextMessage(QSslSocket *m_pSocketPOP, QTextStream &in, QTextEdit *m_ptxtSender, QVector <QString> &vecstr)
{
	QString str;
	str.reserve(10000);
	while (m_pSocketPOP ->waitForReadyRead()) // чтение текста письма. Выход, если нет данных для чтения больше 30 сек.
	{
		m_ptxtSender ->append(QWidget::tr("Новые данные сервера POP доступны для чтения."));
		qDebug() << "while()";
			
		str = in.readAll();
		vecstr.push_back(str);
		
		if (str.size() >= 5 && str.right(5) == (RN + "." + RN)) // выход, если достигнут конец письма
		{
			str.clear();
			return true; 
		}
	}
	//if (vecstr.isEmpty()) return false;
	//else 
	str.squeeze();
	return false;
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// Определение: есть MIME или нет (поиск в заголовке письма "MIME") 
Message extractfromString(const QString &fullstr_istext)
{
	// оставляем заголовок письма перед поиском
	QString fullstr = fullstr_istext;
	int space = fullstr.indexOf(RN + RN); // индекс пробела после заголовка
	
	if (space != -1) fullstr.truncate(space + 2); // оставляем заголовок с RN в конце
	//qDebug() << fullstr;
	
	if (fullstr.contains(arrMIME[MIME])) // если используется MIME
		return isMIMEextractfromString(fullstr_istext);
		
	else 
	return noMIMEextractfromString(fullstr_istext); // если MIME не используется
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// MIME нет. Извлечение из строки, в которой всё письмо, нужных строк.
Message noMIMEextractfromString(const QString &fullstr)
{
	Message message_receive;
 qDebug() << fullstr;
	message_receive.setdate   (searchString(fullstr, arrHEADER[DATE],    RN));
	message_receive.setfrom   (searchString(fullstr, arrHEADER[FROM],    RN));
	message_receive.setto     (searchString(fullstr, arrHEADER[TO],      RN));
	message_receive.setsubject(searchString(fullstr, arrHEADER[SUBJECT], RN));
	
	message_receive.settext(extractText(fullstr));
    
	return message_receive;
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// MIME есть. Определение Content-Type 
Message isMIMEextractfromString(const QString &fullstr)
{
	Message message_receive;
	 
	QString	full_contenttype = searchString(fullstr, arrMIME[CONTENT_TYPE], RN);
	if (full_contenttype == "") return noMIMEextractfromString(fullstr); // если не найдено поле Content-Type
	                                                                // или может нужно text_plain_extractfromString(fullstr, contenttype);
	else
	{
		QString contenttype = full_contenttype;
		
	
		if (contenttype.contains(';')) // если Content-Type несколько полей, то извлекаем !!!пока!!! первое поле (text/plain, multipart/* и т.п.)
			 contenttype.truncate(full_contenttype.indexOf(';')); 
		// если поле одно, то contenttype == full_contenttype;
			
		qDebug() << arrMIME[CONTENT_TYPE] << contenttype;
		// если поле данных Content-Type пустое
		if (contenttype.isEmpty()) contenttype = arrMIME[TEXT_PLAIN];
	
	// text................................................................................
		if (   !contenttype.compare(arrMIME[TEXT_PLAIN], Qt::CaseInsensitive)
		    || !contenttype.compare(arrMIME[TEXT_HTML ], Qt::CaseInsensitive))
			return text_plain_extractfromString(fullstr, contenttype);
	
	// message.............................................................................	
		if (    !contenttype.compare(arrMIME[MESSAGE_RFC822 ],         Qt::CaseInsensitive)
		     || !contenttype.compare(arrMIME[MESSAGE_PARTIAL],         Qt::CaseInsensitive)
			 || !contenttype.compare(arrMIME[MESSAGE_EXTERNAL_BODY],   Qt::CaseInsensitive)
			 || !contenttype.compare(arrMIME[MESSAGE_DELIVERY_STATUS], Qt::CaseInsensitive)) 
				
				return message_extractfromString(fullstr, contenttype);
	
	// image...............................................................................	
		if (    !contenttype.compare(arrMIME[IMAGE_JPEG], Qt::CaseInsensitive)
		     || !contenttype.compare(arrMIME[IMAGE_GIF ], Qt::CaseInsensitive))
			    
				return image_extractfromString(fullstr, contenttype);
	
	// audio...............................................................................
		if (    !contenttype.compare(arrMIME[AUDIO_BASIC], Qt::CaseInsensitive)
		     || !contenttype.compare(arrMIME[AUDIO_MPEG ], Qt::CaseInsensitive))
				
				return audio_extractfromString(fullstr, contenttype);
	
	// video...............................................................................	
		if (    !contenttype.compare(arrMIME[VIDEO_MPEG ], Qt::CaseInsensitive)
		     || !contenttype.compare(arrMIME[VIDEO_MP3  ], Qt::CaseInsensitive))
			    
				return video_extractfromString(fullstr, contenttype);
	
	// application..................................................................................
		if (    !contenttype.compare(arrMIME[APPLICATION_OCTET_STREAM], Qt::CaseInsensitive)
		     || !contenttype.compare(arrMIME[APPLICATION_POSTSCRIPT  ], Qt::CaseInsensitive)
			 || !contenttype.compare(arrMIME[APPLICATION_MSWORD      ], Qt::CaseInsensitive))
			    
				return application_extractfromString(fullstr, contenttype);
	
	// multipart....................................................................................	
		
		if (    !contenttype.compare(arrMIME[MULTIPART_ALTERNATIVE], Qt::CaseInsensitive)
		     || !contenttype.compare(arrMIME[MULTIPART_MIXED      ], Qt::CaseInsensitive)
			 || !contenttype.compare(arrMIME[MULTIPART_PARALLEL   ], Qt::CaseInsensitive)
			 || !contenttype.compare(arrMIME[MULTIPART_DIGEST     ], Qt::CaseInsensitive)
			 || !contenttype.compare(arrMIME[MULTIPART_REPORT     ], Qt::CaseInsensitive))
			    
				return multipart_extractfromString(fullstr, contenttype);
	//...............................................................................................
		
		return message_receive;
	}
}
 
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

QString createFile(QString &data, QString filename, const QString encoding)
{
	QString nameDirAtt;
	QString pathFile;

	if (pPathAttachment == NULL)
	{
		//QDateTime date;
		//QString nameDirAtt = date.currentDateTime().toString(Qt::SystemLocaleDate);
	
		//QRegExp reg("[/:*\?\"<>| \\\\]"); // заменяем пробелы и символы, 
		//								  //недопустимые в названии директории, на "_"
		//nameDirAtt.replace(reg, "_");

		//QDir DirAtt(PATH_ATTACHMENT);

		//while (DirAtt.exists(nameDirAtt)) // если папка с таким именем существует
		//	nameDirAtt.append('p');
	
		//DirAtt.mkdir(nameDirAtt); // создаём суб-директорию для прикреплённых файлов

		QDateTime date;
		nameDirAtt = date.currentDateTime().toString(Qt::SystemLocaleDate);
	
		QRegExp reg("[/:*\?\"<>| \\\\]"); // заменяем пробелы и символы, 
										  //недопустимые в названии директории, на "_"
		nameDirAtt.replace(reg, "_");

		QDir DirAtt(PATH_ATTACHMENT);

		while (DirAtt.exists(nameDirAtt)) // если папка с таким именем существует
			nameDirAtt.append('p');
	
		DirAtt.mkdir(nameDirAtt); // создаём суб-директорию для прикреплённых файлов

		pPathAttachment = new QString;
		*pPathAttachment = PATH_ATTACHMENT + nameDirAtt + '/';

		pathFile = *pPathAttachment + filename;

		//qDebug() << QDir(nameDirAtt).entryList();
	}
	else pathFile = *pPathAttachment + filename;
	
	//qDebug() << dir_att.path();
	//qDebug() << dir_att.dirName();
	
	//QString pathFile = PATH_ATTACHMENT + nameDirAtt + '/' + filename;

	QFile file(pathFile);
	while (file.exists()) // если файл с таким именем существует
	{
		filename = "~" + filename;
		//pathFile = PATH_ATTACHMENT + nameDirAtt + '/' + filename;
		pathFile = *pPathAttachment + filename;
		file.setFileName(pathFile);
	}
	
	file.open(QIODevice::ReadWrite);
	
	QDataStream out(&file);
	out.setVersion(QDataStream::Qt_4_8);
	
	int beginstr = 0;
	int endstr   = 0;
	QString str;
	
	data.append(RN); // добавляем в конец для правильной обработки последней строки

	uint namber = 0; // сколько байт записано в файл
	int temp = 0;
	//QString strout = "";
	
	while(true) // читаем по строке, декодируем и записываем в файл
	{
		endstr = data.indexOf(RN, beginstr);
		if (endstr == -1) break;
		
		str = data.mid(beginstr, endstr - beginstr);
	    
		if (!encoding.compare(arrMIME[BASE64], Qt::CaseInsensitive))
			str = base64_decode(str);
	//qDebug() << str;
	    
		if (!encoding.compare(arrMIME[QUOTED_PRINTABLE], Qt::CaseInsensitive))
			decodeQuotedPrintable(str);
			
	    temp = out.writeRawData(str.toStdString().c_str(), str.toStdString().size());
		
		if ( temp != -1) namber += temp;
					
		beginstr = endstr + RN.size();
		if (beginstr >= data.size()) break;
	}
	file.close();
	
	qDebug() << "namber = " << namber;

	qDebug() << *pPathAttachment;
	qDebug() << QDir(*pPathAttachment).entryList(QDir::Files);
	qDebug() << pathFile;
	
	//QDesktopServices::openUrl(QUrl(pathFile, QUrl::TolerantMode));
	
	//QProcess* proc = new QProcess;
	//pathFile = '\"' + pathFile + '\"';
	//proc ->start(pathFile);

	return *pPathAttachment;
}

// MIME multipart
Message multipart_extractfromString(const QString &fullstr, const QString contenttype)
{
	Message message_receive;

  qDebug() << "\nMULTIPART" << endl << endl;

 // извлекаем значение boundary
	QString boundary = extractValueParameter(fullstr, arrMIME[CONTENT_TYPE], 
	                                                  arrMIME[BOUNDARY], ";");
  qDebug() << boundary;
    
	if (boundary == "") return message_receive; // // если поле Content-Type или boundary не найден

	QVector <int> vecindex; // индексы границ частей
	QString partfullstr;
	QString begin = "--" + boundary; // граница начала каждой части
	QString end   = "--" + boundary + "--"; // граница конца всех частей
	
	int index = 0;
	while (true) 
	{
		index = fullstr.indexOf(begin, index);
		if (index == -1) break;
		vecindex.push_back(index);
		index = index + begin.size() + RN.size();
	}
	
  qDebug() << vecindex.size();
	 
	//for (int i = 0; i < vecindex.size() - 1; i++)
	//{
	//	int indexbegin = vecindex[i] + begin.size() + RN.size(); // индекс начала части
	//	partfullstr    = fullstr.mid(indexbegin, vecindex[i + 1] - indexbegin);
	//	partfullstr = partfullstr + RN + '.' + RN;
	//	
	//} 
	
 // формируем из полной строки заголовок к первой части
	
	// строка Date
	QString date    = searchString(fullstr, arrHEADER[DATE], RN);
	        date    = arrHEADER[DATE] + date + RN;
	// строка From
	QString from    = searchString(fullstr, arrHEADER[FROM], RN);
	        from    = arrHEADER[FROM] + from + RN;
	// стрка To
	QString to      = searchString(fullstr, arrHEADER[TO], RN);
	        to      = arrHEADER[TO] + to + RN;	
	// строка Subject
	QString subject = searchString(fullstr, arrHEADER[SUBJECT], RN);
	        subject = arrHEADER[SUBJECT] + subject + RN;			
	
	QString header = date + from + to + subject; // заголовок к первой части
	
	QString firstpart;

	for (int i = 0; i < vecindex.size() - 1; i++)
	{
		int indexbegin = vecindex[i] + begin.size() + RN.size(); // индекс начала части
		partfullstr    = fullstr.mid(indexbegin, vecindex[i + 1] - indexbegin);
	
	//qDebug() << partfullstr;
	
		if (i == 0) partfullstr = RN + header + partfullstr + RN + '.' + RN; // первая часть
		else partfullstr = RN + partfullstr + RN + '.' + RN; // остальные части
  
	//qDebug() << partfullstr;
		if (i == 0)
			firstpart = partfullstr;

		Message temp = isMIMEextractfromString(partfullstr);
		
		if (i == 0)
			message_receive = temp; // первая часть сохраняется без обработки
		else // из остальных частей извлекается тело(текст) и присоединяется к тексту первой части
		{
			message_receive.settext(message_receive.gettext() += (RN + RN + "attachment-----------" + RN + RN + temp.gettext()));
			if (message_receive.getattachment() == "") // если папки под прикреплённые файлы нет
				message_receive.setattachment(temp.getattachment());
		}
	}
	
	//return isMIMEextractfromString(firstpart);
	return message_receive;
}

// MIME text/plain
Message text_plain_extractfromString(const QString &fullstr, const QString contenttype)
{
	Message message_receive;
	
  qDebug() << "\nTEXT/PLAIN" << endl << endl;

	// извлекаем кодировку
	QString encoding      = searchString(fullstr, arrMIME[CONTENT_TRANSFER_ENCODING], RN);
	
	if (encoding == "") // если поле Content-Transfer-Encoding отсутствует
	{
		encoding = "7bit";
		qDebug() << "no encoding = " << encoding;
	}
	else qDebug() << "encoding = " << encoding;
  
	// извлекаем значение "filename="
	QString filename = extractValueParameter(fullstr, RN, "filename=", ";");
	                                                
	if (filename != "") // если "filename=" найден
	{
	 //qDebug() << filename;
		decode_strings(filename);
	 qDebug() << "filename decode = " << filename;

		//QTextCodec *codec = QTextCodec::codecForName(charset.toStdString().c_str());
		//filename = codec->fromUnicode(decode.toAscii());
		//filename = filename.toLocal8Bit();
				
		QString data = extractText(fullstr);

		message_receive.setattachment(createFile(data, filename, encoding)); // создаём файл и записываем в него данные
		
		return message_receive;
	}
 
  // извлекаем значение charset
	QString charset = extractValueParameter(fullstr, arrMIME[CONTENT_TYPE], 
	                                                 arrMIME[CHARSET], ";");
	if (charset == "") // если Content-Type или charset не найден
	{
		charset = arrMIME[US_ASCII];
		qDebug() << "no charset = " << charset;
	} 
	
 qDebug() << "charset =" << charset;

	
	QString extract;

 // установка в message_receive даты, от кого, кому, темы
// Date:
	extract = searchString(fullstr, arrHEADER[DATE], RN); // то что после "Date: "
  qDebug() << extract;
	
	message_receive.setdate(extract);
	
// From:	
	extract = searchString(fullstr, arrHEADER[FROM], RN); // то что после "From: "

	if (extract != "") // если "From: " найден
	{
		decode_strings(extract); // извлечение из строки закодированного имени 
								 // и создание строки с именем и адресом
		updateFrom_To(extract);  // добавление к e-mail, если нет, <>
	 
	}
  qDebug() << extract;
	
	message_receive.setfrom (extract);
		
// To:   
	extract = searchString(fullstr, arrHEADER[TO], RN); // то что после "To: "
	
	if (extract != "") // если "To: " найден
	{
		decode_strings(extract); // извлечение из строки закодированного имени 
								 // и создание строки с именем и адресом
		updateFrom_To(extract);  // добавление к e-mail, если нет, <>
	}
  qDebug() << extract;
    
	message_receive.setto (extract);
		
// Subject:
	extract = searchString(fullstr, arrHEADER[SUBJECT], RN); // то что после "Subject: "

	if (extract != "") // если "Subject: " найден
		decode_strings(extract); // декодируем
  
  qDebug() << extract;	
	
	message_receive.setsubject (extract);

// Text
// установка в message_receive текста
	
	extract = extractText(fullstr);
	
	if (extract != "") // если текст есть
		decodeText(extract, encoding, charset); // обработка текста(декодирование и перевод в нужный charset)
	
	message_receive.settext(extract);
	
	return message_receive;
}

// MIME message
Message message_extractfromString(const QString &fullstr, const QString contenttype)
{
	Message message_receive;
	
	message_receive = text_plain_extractfromString(fullstr, contenttype);

	return message_receive;
}

// MIME image
Message image_extractfromString(const QString &fullstr, const QString contenttype)
{
	Message message_receive;
  
  qDebug() << "\nIMAGE" << endl << endl;

  message_receive = application_extractfromString(fullstr, contenttype);

  return message_receive;

/*...........................................................................................	
	QString encoding      = searchString(fullstr, arrMIME[CONTENT_TRANSFER_ENCODING], RN);
	if (encoding == "") // если поле Content-Transfer-Encoding отсутствует
	{
		encoding = "8bit";
		qDebug() << "no encoding = " << encoding;
	}
	else qDebug() << "encoding = " << encoding;
  
  // извлекаем значение "filename="
	QString filename = extractValueParameter(fullstr, RN , "filename=", ";");
	                                                
	if (filename == "") // если поле Content-Type или "filename=" не найден
		return message_receive;
	
//qDebug() << filename;
	decode_strings(filename);
qDebug() << "filename = " << filename;
	
	QString data = extractText(fullstr);

	//filename = LocalCodec->fromUnicode(filename.toAscii());
	
	createFile(data, filename, encoding); // создаём файл и записываем в него данные
    
	return message_receive;
//......................................................................................*/
}

// MIME audio
Message audio_extractfromString(const QString &fullstr, const QString contenttype)
{
	Message message_receive;

	qDebug() << "\nAUDIO" << endl << endl;
	
	message_receive = application_extractfromString(fullstr, contenttype);
	
	return message_receive;
}

// MIME video
Message video_extractfromString(const QString &fullstr, const QString contenttype)
{
	Message message_receive;

	qDebug() << "\nVIDEO" << endl << endl;

	message_receive = application_extractfromString(fullstr, contenttype);

	return message_receive;
}

// MIME application
Message application_extractfromString(const QString &fullstr, const QString contenttype)
{
	Message message_receive;
  
  qDebug() << "\nAPPLICATION" << endl << endl;
	
	QString encoding      = searchString(fullstr, arrMIME[CONTENT_TRANSFER_ENCODING], RN);
	if (encoding == "") // если поле Content-Transfer-Encoding отсутствует
	{
		encoding = "7bit";
		qDebug() << "no encoding = " << encoding;
	}
	else qDebug() << "encoding = " << encoding;
 
 // извлекаем значение "filename="
	QString filename = extractValueParameter(fullstr, RN, "filename=", ";");
	                                                
	
	if (filename == "") // если поле Content-Type или "filename=" не найден
		return message_receive;
	
qDebug() << "filename encoding = " << filename;
	decode_strings(filename);
qDebug() << "filename decoding = " << filename;

	QString data = extractText(fullstr);

	//filename = LocalCodec->fromUnicode(filename.toAscii());

	message_receive.setattachment(createFile(data, filename, encoding)); // создаём файл и записываем в него данные

	return message_receive;
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// обрабока полей From и To (добавление к e-mail, если нет, <>) 
void updateFrom_To(QString &extract)
{
	// если в строке не только e-mail, то находим e-mail, и если он не в <>, то добавляем
	int index = extract.lastIndexOf(' ');
	if (index != -1)
	{
		QString e_mail = extract.mid(index + 1, extract.size() - (index + 1)); // извлекаем e-mail
	
		// если e-mail не в <>, то добавляем
		if (e_mail[0] != '<')
		{ 
			extract.truncate(index + 1);
			extract = extract + '<' + e_mail + '>';
		}
			
	}
	else if (extract[0] != '<') extract = '<' + extract + '>'; // если в строке только e-mail и он не в <>
}

// декодирование и перевод текста в нужный charset
void decodeText(QString &extract, const QString encoding, const QString charset)
{
	if (!encoding.compare(arrMIME[_8BIT], Qt::CaseInsensitive)) // если 8bit 
	{
		qDebug() << "8BIT";
		qDebug() << "CHARSET = "  << charset;
		
		QTextCodec *codec = QTextCodec::codecForName(charset.toStdString().c_str());
		extract = codec->toUnicode(extract.toUtf8());
		
		// если есть, то обрезаем на конце "\r\n", "\r" , "\n"
		while (extract.right(2) == RN)
			extract.chop(2);
		while (extract.right(1) == R || extract.right(1) == N)
			extract.chop(1);

		return;
	}
	
	if (!encoding.compare(arrMIME[_7BIT], Qt::CaseInsensitive)) // если 7bit (или неизвестен)
	{
		qDebug() << "7BIT";
		qDebug() << "CHARSET = "  << charset;
		
		if (charset.compare(arrMIME[US_ASCII], Qt::CaseInsensitive)) // если не Ascii 
		{
			QTextCodec *codec = QTextCodec::codecForName(charset.toStdString().c_str());
			if (!charset.compare(arrMIME[UTF_8], Qt::CaseInsensitive)) // если UTF-8
					extract = codec->toUnicode(extract.toLocal8Bit());
			else extract = codec->toUnicode(extract.toAscii()); // ???? если не UTF-8
		}
		
		// если Ascii (или неизвестно), то ничего не делаем

		// если есть, то обрезаем на конце "\r\n", "\r" , "\n"
		while (extract.right(2) == RN)
			extract.chop(2);
		while (extract.right(1) == R || extract.right(1) == N)
			extract.chop(1);

		return;
	}
	
	if (!encoding.compare(arrMIME[QUOTED_PRINTABLE], Qt::CaseInsensitive)) // если quoted-printable
	{ 
		qDebug() << "QUOTED-PRINTABLE";
		
		extract.remove("=\r\n"); // перед декодированием убираем мягкий конец строки
		
		decodeQuotedPrintable(extract);
	
	}
	
	if (!encoding.compare(arrMIME[BASE64], Qt::CaseInsensitive)) // если base64
	{
		qDebug() << "BASE64";
		
		extract.remove("\r\n"); // перед декодированием удаляем добавленные (кем? Beky!?) \r\n
		 
		extract = base64_decode(extract);
		
	//qDebug() << extract;
	}	
	
	if (!charset.compare(arrMIME[ISO_8859_1], Qt::CaseInsensitive))
	{
		qDebug() << "ISO-8859-1";
		qDebug() << "ENCODING = " << encoding;
		qDebug() << "CHARSET = "  << charset;
		
		QTextCodec *codec = QTextCodec::codecForName(/*"ISO-8859-1"*/QTextCodec::codecForLocale() ->name()/*"Windows-1251"*/);
		extract = codec->toUnicode(extract.toAscii());
		//extract = codec->toUnicode(extract.toLocal8Bit());
		//extract = codec->toUnicode(extract.toUtf8());
		//extract = codec->toUnicode(extract.toLatin1());
	}
	else
	{
		qDebug() << "ENCODING = " << encoding;
		qDebug() << "CHARSET = "  << charset;
		
		QTextCodec *codec = QTextCodec::codecForName(charset.toStdString().c_str());
		extract = codec->toUnicode(extract.toAscii());
	}
	
	// если есть, то обрезаем на конце "\r\n", "\r" , "\n"
	while (extract.right(2) == RN)
		extract.chop(2);
	while (extract.right(1) == R || extract.right(1) == N)
		extract.chop(1);
//qDebug() << extract;
	
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// поиск (в заголовке письма) и извленчение значения парамера
QString extractValueParameter(const QString &fullstr_istext,      const QString Begin, 
                              const QString NameParameter, const QString EndParameter)
{
	// оставляем заголовок письма перед поиском
	QString fullstr = fullstr_istext;
	int space = fullstr.indexOf(RN + RN); // индекс пробела после заголовка
	
	if (space != -1) fullstr.truncate(space + 2); // оставляем заголовок с RN в конце

	// удаляем пробелы в начале строк (Becy!, при переносе параметров, вставляет в начале строки пробел) 
	int beginstr = 0;
	int index = 0;
	while (true)
	{
		beginstr = (fullstr.indexOf(RN, index) + 2); // начало строки
		if (beginstr >= fullstr.size()) break; 
		if (fullstr[beginstr] == ' ') 
			fullstr.remove(beginstr, 1);

		index = beginstr;
	}
 qDebug() << fullstr;

	QString value = ""; // значение параметра

	int indBegin = fullstr.indexOf(Begin); // отсюда будем искать параметр
	if (indBegin == -1) return value;      // если начало, для поиска параметра, не найдено
	
	int beginParameter  = fullstr.indexOf(NameParameter, indBegin); // начало параметра

	if (beginParameter == -1) return value; // если параметр не найден
	
	if (fullstr[beginParameter + NameParameter.size()] == '"') // если значение параметра в ""
	{
	    qDebug() << "PARAMETR \"\"";
		int beginvalue = fullstr.indexOf('"', beginParameter + NameParameter.size());
		int endvalue   = fullstr.indexOf('"', beginvalue + 1);
		value = fullstr.mid(beginvalue, endvalue - beginvalue); // индекс конца параметра
	}
	else
	{
		int endParameter      = fullstr.indexOf(EndParameter, beginParameter); // индекс конца параметра
		int endStrisParameter = fullstr.indexOf(RN,           beginParameter); // индекс конца строки с параметром
		
		if (endStrisParameter != - 1)
		{
			if (endParameter != -1 && (endParameter < endStrisParameter)) // если после значения параметра есть ещё параметры
					 value = fullstr.mid(beginParameter + NameParameter.size(), endParameter - (beginParameter + NameParameter.size()));  
			// если значение параметра в конце строки
			else value = fullstr.mid(beginParameter + NameParameter.size(), endStrisParameter - (beginParameter + NameParameter.size()));
		}
	}
	
	// если значение параметра расположено в нескольких строках (присутствуют "\r\n")
	value.remove(RN);
	
	// если значение параметра в "", то удаляем ""
	if (value.startsWith('"')) value.remove(0, 1);
	if (value.endsWith  ('"')) value.chop(1);
		
	return value;
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// поиск в загловке письма строки, перед которой rn(в конце "\r\n") 
// и возврат её(без begin и без "\r\n"). begin - начало строки
QString searchString(const QString &fullstr_istext, const QString Begin, const QString rn)
{
	int beginstr = 0;
	int endstr = 0;
	QString str = "";
	QVector <QString> vecstr;

	// оставляем заголовок письма перед поиском
	QString fullstr = fullstr_istext;
	int space = fullstr.indexOf(RN + RN);  // индекс пробела после заголовка
	
	if (space != -1) fullstr.truncate(space + 2); // оставляем заголовок с RN в конце
 if (Begin == arrMIME[CONTENT_TYPE]) qDebug() << fullstr;
	
	while (beginstr < fullstr.size())
	{
		beginstr = fullstr.indexOf(Begin, beginstr);
		if (beginstr == -1) return str; // если вообще нет Begin
		
		if (fullstr.mid(beginstr - 2, 2) == rn) // если Begin в начале строки (перед ней "\r\n")
		{
			//if (Begin != arrHEADER[3]) // если Begin не "Subject: "
			//{
				beginstr += Begin.size(); // начало строки после Begin
				endstr = fullstr.indexOf(rn, beginstr); // конец строки
				str = fullstr.mid(beginstr, endstr - beginstr); // строка
			
			//qDebug() << str;
				return str;
			//}
			//else // тесли Begin это - "Subject: "
			//{
			//	uint flag = 0;
			//
			//	while (true)
			//	{
			//		if (flag == 0) // только в первый раз
			//		{
			//			beginstr += Begin.size(); // начало строки после Begin
			//			flag = 1;
			//		}

			//		endstr = fullstr.indexOf(rn, beginstr); // конец строки
			//		str = fullstr.mid(beginstr, endstr - beginstr); // строка
			//	qDebug() << str;
			//		if (str.contains("=?") || flag == 1) // если в строке есть закодированное 
			//		{                                    // или первая строка, то сохраняем строку
			//			if (str[0] == ' ' && str[1] == '=' && str[2] == '?') // удаляем лишний пробел,
			//			        str.remove(0, 1);                            // добавляемый при переносе длинной закодированной строки
			//	qDebug() << str;		
			//			vecstr.push_back(str);
			//			flag++;
			//		} 
			//		else 
			//		{
			//			// собираем общую строку
			//			str.clear();
			//			for (int i = 0; i < vecstr.size(); i++)
			//				str += vecstr[i];
			//	
			//		qDebug() << str;
			//			return str;
			//			//break;
			//		}
			//	
			//		endstr += 2; // на начало следующей строки
			//		if (endstr >= fullstr.size()) break;
			//		beginstr = endstr;
			//	} // 2 while() 
			//} // если Begin это - "Subject: "
		}
		else beginstr++; // если найденный Begin не в начале строки
		
	} // 1 while()
	
	return str;
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// извлечение из строки закодированного и создание строки с декодированным и незакодированным
void decode_strings(QString &extract)
{
	QVector <QString> vecstr;
	
	QString encoding;
	
	int indexbeginE = extract.indexOf("?B?"); // индекс метки начала закодированного в Base64
	if (indexbeginE != -1) encoding = "?B?";
	else 
	{
		indexbeginE = extract.indexOf("?Q?"); // индекс метки начала закодированного в Quoted-printable
		if (indexbeginE != -1) encoding = "?Q?";
	}

	int indexcharset; // начало значения charset
	
	if (indexbeginE != -1) // если в строке есть закодированное
	{
		qDebug() << "zahod decode_strings";
		indexcharset = extract.indexOf("=?"); // индекс метки начала значения charset
		if (indexcharset != 0) // если до закодированного есть незакодированное
		{
			QString notencode = extract.mid(0, indexcharset); // вырезаем незакодированное
			//qDebug() << notencode;
					
			vecstr.push_back(notencode); // помещаем в вектор
		}
		
		indexcharset = indexcharset + 2; // индекс начала значения charset
		
		while(true)
		{
			//qDebug() << "=?" << indexcharset;
			// извлекаем значение charset для закодированного
			QString charset = extract.mid(indexcharset, indexbeginE - indexcharset);
			//charset = charset.toUpper(); // переводим в верхний регистр
		qDebug() << "charset = " << charset;
		
			int indexendE   = extract.indexOf("?=", indexbeginE + 3); // индекс метки конца закодированного 
		/*qDebug() << "indexbeginE + 3 = " << indexbeginE + 3;
		qDebug() << "indexendE = " << indexendE;
		qDebug() << "indexendE - (indexbeginE + 3) = " << indexendE - (indexbeginE + 3);*/
			QString encode  = extract.mid(indexbeginE + 3, indexendE - (indexbeginE + 3)); // вырезаем закодированное
		qDebug() << "encode = " << encode;
			
		    // декодируем

			QString decode;
			if (encoding == "?B?")
			{
				decode = base64_decode(encode);
			
				QTextCodec *codec = QTextCodec::codecForName(charset.toStdString().c_str());
				//QTextCodec *codec = QTextCodec::codecForName(arrMIME[WINDOWS_1251].toStdString().c_str());
				qDebug() << "codecForName = " << codec->name();
				if (codec ->name() == "ISO-8859-1") codec = QTextCodec::codecForName("Windows-1251");
				
				decode = codec->toUnicode(decode.toAscii());

				//decode = LocalCodec->toUnicode(decode.toAscii());
				
			qDebug() << "base64 decode = " << decode;
			}
			
			if (encoding == "?Q?")
			{
			    decodeQuotedPrintable(encode);
				decode = encode;

				QTextCodec *codec = QTextCodec::codecForName(charset.toStdString().c_str());
				//QTextCodec *codec = QTextCodec::codecForName(arrMIME[WINDOWS_1251].toStdString().c_str());
				qDebug() << "codecForName = " << codec->name();
				if (codec ->name() == "ISO-8859-1") codec = QTextCodec::codecForName("Windows-1251");
				
				decode = codec->toUnicode(decode.toAscii());
				//decode = LocalCodec->toUnicode(decode.toAscii());
				
				//decode = decode.toLocal8Bit();
			/*qDebug() << decode;
				codec = QTextCodec::codecForName(arrMIME[WINDOWS_1251].toStdString().c_str());
				decode = codec->fromUnicode(decode);*/
			
			qDebug() << "quoted-printable decode = " << decode;
			}
		
			vecstr.push_back(decode); // помещаем в вектор

			if (indexendE + 2 == extract.size()) // если после закодированного ничего нет
			{
				// собираем строку из декодированного и незакодированного
				extract.clear();
				for (int i = 0; i < vecstr.size(); i++)
				        extract += vecstr[i];
					
					qDebug() << extract;
					qDebug() << "vihod decode_strings";
				return;
			}
			else // если после закодированного есть или незакодированное, или закодированное
			{
 				indexcharset = extract.indexOf("=?", indexendE + 2); // индекс метки начала значения charset
				if ( indexcharset == -1) // если дальше нет закодированного
				{ 
					QString notencode = extract.mid(indexendE + 2, extract.size() - (indexendE + 2)); // вырезаем незакодированное
				 //qDebug() << notencode;
					
					vecstr.push_back(notencode); // помещаем в вектор
					
					// собираем строку из декодированного и незакодированного
					extract.clear();
					for (int i = 0; i < vecstr.size(); i++) 
				        extract += vecstr[i];
                 
				 //qDebug() << extract;
				 qDebug() << "vihod decode_strings";
					return;
				}
				else // если дальше есть закодированное (перед ним обязательно будет незакодированное)
				{	
					// сначала извлекаем незакодированное
					QString notencode = extract.mid(indexendE + 2,  indexcharset - (indexendE + 2)); // извлекаем незакодированное
				
					vecstr.push_back(notencode); // помещаем в вектор

					// дальше будем извлекать закодированное
					indexcharset = indexcharset + 2; // начало значения charset
					indexbeginE = extract.indexOf(encoding, indexcharset); // индекс метки начала закодированного
				}
			}
		} // while()
		
	}
	qDebug() << "vihod decode_strings";
	
	// если кодировки в строке нет, то extract остаётся равен тому, 
	// что после "From: ", "To: ", "Subject: ", "filename=" и т.п.
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// извлечение текста письма
QString extractText(const QString &fullstr)
{
	QString extract = "";
	int i = fullstr.indexOf(RN + RN);
	if (i != -1)
	{
		extract = fullstr.mid(i);
		extract.remove(0, 4);// удаление  "\r\n\r\n"
		
		// удаление последних "r\n", точки и "r\n" до текста 
		while (extract.right(1) != ".") 
			extract.chop(1);
		extract.chop(1);
		while (extract.right(2) == RN) 
			extract.chop(2);
		
	//qDebug() << extract;
		return extract;
	}
	else return extract;
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// декодирование строки из QuotedPrintable
void decodeQuotedPrintable(QString &extract)
{
	QString output;
	QString hex;
	QRegExp reg("[0-9a-fA-F]"); // символы шестнадцатиричного числа
	
	for (int i = 0; i < extract.size(); i++)
	{
		
		if (extract[i] == '=') // нашли '='(дальше или закодированный символ, или то, что не нужно)
		{
		  // если дальше символ шестнадцатиричного числа, то формируем код символа
			//QString temp = extract[i + 1]; 
			//if (temp.contains(reg))
			//{
				i++;
				if (i >= extract.size()) break;
				
				bool ok;
				hex = extract[i];
				hex += extract[++i]; 
			 //qDebug() << "hex = " << hex;
				uint code = hex.toUInt(&ok, 16); 
			 //qDebug() << "code = " << code;
			
				output.append(QChar(code));
			//}
			//else // если дальше не символ шестнадцатиричного числа, то ищем '='
			//{
			//	i++;
			//	if (i >= extract.size()) break;
			//	while (extract[i] != '=') 
			//	{
			//		i++;
			//		if (i >= extract.size()) break;
			//	}
			//	i--;
			//}
		}
		else output.append(extract[i]); // если символ не закодирован
	} // for()
	
	qDebug() << output;
	
	extract = output;
}

//#include "post.h.moc"


