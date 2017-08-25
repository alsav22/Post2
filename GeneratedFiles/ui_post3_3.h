/********************************************************************************
** Form generated from reading UI file 'post3_3.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POST3_3_H
#define UI_POST3_3_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PostClass
{
public:
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *plblRec;
    QTextEdit *m_ptxtReceiver;
    QLabel *plblSender;
    QTextEdit *m_ptxtSender;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *m_pinput_comServer;
    QCheckBox *m_pCheckBox;
    QLabel *m_pinfoReceive;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pcmd_receive;
    QPushButton *pcmd_clearreceive;
    QVBoxLayout *verticalLayout_4;
    QLabel *plblMessage;
    QGridLayout *gridLayout;
    QLabel *to;
    QLineEdit *m_pTo;
    QLabel *subject;
    QLineEdit *m_pSubject;
    QTextEdit *m_ptxtMessage;
    QLabel *m_pinfoSend;
    QHBoxLayout *horizontalLayout;
    QProgressBar *progressBar;
    QPushButton *pcmd_send;
    QPushButton *pcmd_clearsend;
    QVBoxLayout *verticalLayout_3;
    QLabel *plblAddress;
    QListWidget *m_pListAddress;
    QVBoxLayout *verticalLayout;
    QLabel *plblSettings;
    QPushButton *pbuttonCreateAccount;
    QPushButton *pbuttonSettingsAccount;
    QPushButton *pbuttonCreateAddress;
    QPushButton *pbuttonSettingsAddress;
    QPushButton *pbuttonSettings;
    QSpacerItem *verticalSpacer;
    QPushButton *pbuttonReceived;
    QPushButton *pbuttonSend;
    QLabel *plblAccount_info;
    QLabel *m_pAccountInfo;

    void setupUi(QWidget *PostClass)
    {
        if (PostClass->objectName().isEmpty())
            PostClass->setObjectName(QString::fromUtf8("PostClass"));
        PostClass->resize(1343, 667);
        PostClass->setMinimumSize(QSize(0, 0));
        PostClass->setCursor(QCursor(Qt::ArrowCursor));
        QIcon icon;
        icon.addFile(QString::fromUtf8("icon2.png"), QSize(), QIcon::Normal, QIcon::Off);
        PostClass->setWindowIcon(icon);
        horizontalLayout_4 = new QHBoxLayout(PostClass);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        plblRec = new QLabel(PostClass);
        plblRec->setObjectName(QString::fromUtf8("plblRec"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plblRec->sizePolicy().hasHeightForWidth());
        plblRec->setSizePolicy(sizePolicy);
        plblRec->setMinimumSize(QSize(0, 0));
        plblRec->setStyleSheet(QString::fromUtf8("font: bold oblique 14pt Times; color: blue;"));
        plblRec->setFrameShape(QFrame::WinPanel);
        plblRec->setFrameShadow(QFrame::Raised);
        plblRec->setLineWidth(6);
        plblRec->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(plblRec);

        m_ptxtReceiver = new QTextEdit(PostClass);
        m_ptxtReceiver->setObjectName(QString::fromUtf8("m_ptxtReceiver"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(m_ptxtReceiver->sizePolicy().hasHeightForWidth());
        m_ptxtReceiver->setSizePolicy(sizePolicy1);
        m_ptxtReceiver->setMinimumSize(QSize(0, 0));
        m_ptxtReceiver->setStyleSheet(QString::fromUtf8("font: oblique 12pt Times; color: black;"));
        m_ptxtReceiver->setFrameShape(QFrame::WinPanel);
        m_ptxtReceiver->setFrameShadow(QFrame::Raised);
        m_ptxtReceiver->setLineWidth(7);
        m_ptxtReceiver->setReadOnly(true);

        verticalLayout_2->addWidget(m_ptxtReceiver);

        plblSender = new QLabel(PostClass);
        plblSender->setObjectName(QString::fromUtf8("plblSender"));
        sizePolicy.setHeightForWidth(plblSender->sizePolicy().hasHeightForWidth());
        plblSender->setSizePolicy(sizePolicy);
        plblSender->setMinimumSize(QSize(0, 40));
        plblSender->setStyleSheet(QString::fromUtf8("font: bold oblique 12pt Times; color: blue;"));
        plblSender->setFrameShape(QFrame::WinPanel);
        plblSender->setFrameShadow(QFrame::Raised);
        plblSender->setLineWidth(6);
        plblSender->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(plblSender);

        m_ptxtSender = new QTextEdit(PostClass);
        m_ptxtSender->setObjectName(QString::fromUtf8("m_ptxtSender"));
        sizePolicy1.setHeightForWidth(m_ptxtSender->sizePolicy().hasHeightForWidth());
        m_ptxtSender->setSizePolicy(sizePolicy1);
        m_ptxtSender->setMinimumSize(QSize(0, 0));
        m_ptxtSender->setStyleSheet(QString::fromUtf8("font: 9pt Arial; color: black;"));
        m_ptxtSender->setFrameShape(QFrame::WinPanel);
        m_ptxtSender->setFrameShadow(QFrame::Raised);
        m_ptxtSender->setLineWidth(6);
        m_ptxtSender->setReadOnly(true);

        verticalLayout_2->addWidget(m_ptxtSender);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        m_pinput_comServer = new QLineEdit(PostClass);
        m_pinput_comServer->setObjectName(QString::fromUtf8("m_pinput_comServer"));
        sizePolicy.setHeightForWidth(m_pinput_comServer->sizePolicy().hasHeightForWidth());
        m_pinput_comServer->setSizePolicy(sizePolicy);
        m_pinput_comServer->setStyleSheet(QString::fromUtf8("font: 12pt Times; color: black;"));

        horizontalLayout_3->addWidget(m_pinput_comServer);

        m_pCheckBox = new QCheckBox(PostClass);
        m_pCheckBox->setObjectName(QString::fromUtf8("m_pCheckBox"));
        sizePolicy.setHeightForWidth(m_pCheckBox->sizePolicy().hasHeightForWidth());
        m_pCheckBox->setSizePolicy(sizePolicy);
        m_pCheckBox->setStyleSheet(QString::fromUtf8("font: 11pt Times; color: black;"));

        horizontalLayout_3->addWidget(m_pCheckBox);


        verticalLayout_2->addLayout(horizontalLayout_3);

        m_pinfoReceive = new QLabel(PostClass);
        m_pinfoReceive->setObjectName(QString::fromUtf8("m_pinfoReceive"));
        sizePolicy.setHeightForWidth(m_pinfoReceive->sizePolicy().hasHeightForWidth());
        m_pinfoReceive->setSizePolicy(sizePolicy);
        m_pinfoReceive->setStyleSheet(QString::fromUtf8("font: bold oblique 13pt Times; color: red;"));
        m_pinfoReceive->setFrameShape(QFrame::WinPanel);
        m_pinfoReceive->setFrameShadow(QFrame::Raised);
        m_pinfoReceive->setLineWidth(6);
        m_pinfoReceive->setAlignment(Qt::AlignCenter);
        m_pinfoReceive->setMargin(3);

        verticalLayout_2->addWidget(m_pinfoReceive);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pcmd_receive = new QPushButton(PostClass);
        pcmd_receive->setObjectName(QString::fromUtf8("pcmd_receive"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pcmd_receive->sizePolicy().hasHeightForWidth());
        pcmd_receive->setSizePolicy(sizePolicy2);
        pcmd_receive->setCursor(QCursor(Qt::PointingHandCursor));
        pcmd_receive->setStyleSheet(QString::fromUtf8("font: bold oblique 11pt Times; color: black;"));

        horizontalLayout_2->addWidget(pcmd_receive);

        pcmd_clearreceive = new QPushButton(PostClass);
        pcmd_clearreceive->setObjectName(QString::fromUtf8("pcmd_clearreceive"));
        sizePolicy2.setHeightForWidth(pcmd_clearreceive->sizePolicy().hasHeightForWidth());
        pcmd_clearreceive->setSizePolicy(sizePolicy2);
        pcmd_clearreceive->setCursor(QCursor(Qt::PointingHandCursor));
        pcmd_clearreceive->setStyleSheet(QString::fromUtf8("font: bold oblique 11pt Times; color: black;"));

        horizontalLayout_2->addWidget(pcmd_clearreceive);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        plblMessage = new QLabel(PostClass);
        plblMessage->setObjectName(QString::fromUtf8("plblMessage"));
        sizePolicy.setHeightForWidth(plblMessage->sizePolicy().hasHeightForWidth());
        plblMessage->setSizePolicy(sizePolicy);
        plblMessage->setMinimumSize(QSize(0, 0));
        plblMessage->setStyleSheet(QString::fromUtf8("font: bold oblique 14pt Times; color: blue;"));
        plblMessage->setFrameShape(QFrame::WinPanel);
        plblMessage->setFrameShadow(QFrame::Raised);
        plblMessage->setLineWidth(6);
        plblMessage->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(plblMessage);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(9);
        to = new QLabel(PostClass);
        to->setObjectName(QString::fromUtf8("to"));
        sizePolicy1.setHeightForWidth(to->sizePolicy().hasHeightForWidth());
        to->setSizePolicy(sizePolicy1);
        to->setStyleSheet(QString::fromUtf8("font: bold oblique 12pt Times; color: black;"));
        to->setFrameShape(QFrame::WinPanel);
        to->setFrameShadow(QFrame::Raised);
        to->setLineWidth(6);
        to->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(to, 0, 0, 1, 1);

        m_pTo = new QLineEdit(PostClass);
        m_pTo->setObjectName(QString::fromUtf8("m_pTo"));
        sizePolicy1.setHeightForWidth(m_pTo->sizePolicy().hasHeightForWidth());
        m_pTo->setSizePolicy(sizePolicy1);
        m_pTo->setStyleSheet(QString::fromUtf8("font: bold oblique 11pt Times; color: black;"));

        gridLayout->addWidget(m_pTo, 1, 0, 1, 1);

        subject = new QLabel(PostClass);
        subject->setObjectName(QString::fromUtf8("subject"));
        sizePolicy1.setHeightForWidth(subject->sizePolicy().hasHeightForWidth());
        subject->setSizePolicy(sizePolicy1);
        subject->setStyleSheet(QString::fromUtf8("font: bold oblique 12pt Times; color: black;"));
        subject->setFrameShape(QFrame::WinPanel);
        subject->setFrameShadow(QFrame::Raised);
        subject->setLineWidth(6);
        subject->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(subject, 0, 1, 1, 1);

        m_pSubject = new QLineEdit(PostClass);
        m_pSubject->setObjectName(QString::fromUtf8("m_pSubject"));
        sizePolicy1.setHeightForWidth(m_pSubject->sizePolicy().hasHeightForWidth());
        m_pSubject->setSizePolicy(sizePolicy1);
        m_pSubject->setStyleSheet(QString::fromUtf8("font: bold oblique 11pt Times; color: black;"));

        gridLayout->addWidget(m_pSubject, 1, 1, 1, 1);


        verticalLayout_4->addLayout(gridLayout);

        m_ptxtMessage = new QTextEdit(PostClass);
        m_ptxtMessage->setObjectName(QString::fromUtf8("m_ptxtMessage"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(m_ptxtMessage->sizePolicy().hasHeightForWidth());
        m_ptxtMessage->setSizePolicy(sizePolicy3);
        m_ptxtMessage->setMinimumSize(QSize(0, 0));
        m_ptxtMessage->setStyleSheet(QString::fromUtf8("font: oblique 14pt Times; color: black;"));
        m_ptxtMessage->setFrameShape(QFrame::WinPanel);
        m_ptxtMessage->setFrameShadow(QFrame::Raised);
        m_ptxtMessage->setLineWidth(7);

        verticalLayout_4->addWidget(m_ptxtMessage);

        m_pinfoSend = new QLabel(PostClass);
        m_pinfoSend->setObjectName(QString::fromUtf8("m_pinfoSend"));
        m_pinfoSend->setStyleSheet(QString::fromUtf8("font: bold oblique 13pt Times; color: blue;"));
        m_pinfoSend->setFrameShape(QFrame::WinPanel);
        m_pinfoSend->setFrameShadow(QFrame::Raised);
        m_pinfoSend->setLineWidth(6);
        m_pinfoSend->setAlignment(Qt::AlignCenter);
        m_pinfoSend->setMargin(3);

        verticalLayout_4->addWidget(m_pinfoSend);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        progressBar = new QProgressBar(PostClass);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(10);

        horizontalLayout->addWidget(progressBar);

        pcmd_send = new QPushButton(PostClass);
        pcmd_send->setObjectName(QString::fromUtf8("pcmd_send"));
        sizePolicy2.setHeightForWidth(pcmd_send->sizePolicy().hasHeightForWidth());
        pcmd_send->setSizePolicy(sizePolicy2);
        pcmd_send->setCursor(QCursor(Qt::PointingHandCursor));
        pcmd_send->setStyleSheet(QString::fromUtf8("font: bold oblique 11pt Times; color: black;"));

        horizontalLayout->addWidget(pcmd_send);

        pcmd_clearsend = new QPushButton(PostClass);
        pcmd_clearsend->setObjectName(QString::fromUtf8("pcmd_clearsend"));
        sizePolicy2.setHeightForWidth(pcmd_clearsend->sizePolicy().hasHeightForWidth());
        pcmd_clearsend->setSizePolicy(sizePolicy2);
        pcmd_clearsend->setCursor(QCursor(Qt::PointingHandCursor));
        pcmd_clearsend->setStyleSheet(QString::fromUtf8("font: bold oblique 11pt Times; color: black;"));

        horizontalLayout->addWidget(pcmd_clearsend);


        verticalLayout_4->addLayout(horizontalLayout);


        horizontalLayout_4->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        plblAddress = new QLabel(PostClass);
        plblAddress->setObjectName(QString::fromUtf8("plblAddress"));
        sizePolicy.setHeightForWidth(plblAddress->sizePolicy().hasHeightForWidth());
        plblAddress->setSizePolicy(sizePolicy);
        plblAddress->setMinimumSize(QSize(0, 82));
        plblAddress->setStyleSheet(QString::fromUtf8("font: bold oblique 14pt Times; color: blue;"));
        plblAddress->setFrameShape(QFrame::WinPanel);
        plblAddress->setFrameShadow(QFrame::Raised);
        plblAddress->setLineWidth(6);
        plblAddress->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(plblAddress);

        m_pListAddress = new QListWidget(PostClass);
        m_pListAddress->setObjectName(QString::fromUtf8("m_pListAddress"));
        sizePolicy1.setHeightForWidth(m_pListAddress->sizePolicy().hasHeightForWidth());
        m_pListAddress->setSizePolicy(sizePolicy1);
        m_pListAddress->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        m_pListAddress->setStyleSheet(QString::fromUtf8("font: oblique bold 13pt Times; color: black;"));
        m_pListAddress->setIconSize(QSize(124, 152));
        m_pListAddress->setViewMode(QListView::IconMode);

        verticalLayout_3->addWidget(m_pListAddress);


        horizontalLayout_4->addLayout(verticalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        plblSettings = new QLabel(PostClass);
        plblSettings->setObjectName(QString::fromUtf8("plblSettings"));
        sizePolicy.setHeightForWidth(plblSettings->sizePolicy().hasHeightForWidth());
        plblSettings->setSizePolicy(sizePolicy);
        plblSettings->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("Times"));
        font.setPointSize(14);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        plblSettings->setFont(font);
        plblSettings->setStyleSheet(QString::fromUtf8("font: bold oblique 14pt Times; color: blue;"));
        plblSettings->setFrameShape(QFrame::WinPanel);
        plblSettings->setFrameShadow(QFrame::Raised);
        plblSettings->setLineWidth(6);
        plblSettings->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(plblSettings);

        pbuttonCreateAccount = new QPushButton(PostClass);
        pbuttonCreateAccount->setObjectName(QString::fromUtf8("pbuttonCreateAccount"));
        sizePolicy2.setHeightForWidth(pbuttonCreateAccount->sizePolicy().hasHeightForWidth());
        pbuttonCreateAccount->setSizePolicy(sizePolicy2);
        pbuttonCreateAccount->setCursor(QCursor(Qt::PointingHandCursor));
        pbuttonCreateAccount->setStyleSheet(QString::fromUtf8("font: bold oblique 10pt Times; color: black;"));

        verticalLayout->addWidget(pbuttonCreateAccount);

        pbuttonSettingsAccount = new QPushButton(PostClass);
        pbuttonSettingsAccount->setObjectName(QString::fromUtf8("pbuttonSettingsAccount"));
        sizePolicy2.setHeightForWidth(pbuttonSettingsAccount->sizePolicy().hasHeightForWidth());
        pbuttonSettingsAccount->setSizePolicy(sizePolicy2);
        pbuttonSettingsAccount->setCursor(QCursor(Qt::PointingHandCursor));
        pbuttonSettingsAccount->setStyleSheet(QString::fromUtf8("font: bold oblique 10pt Times; color: black;"));

        verticalLayout->addWidget(pbuttonSettingsAccount);

        pbuttonCreateAddress = new QPushButton(PostClass);
        pbuttonCreateAddress->setObjectName(QString::fromUtf8("pbuttonCreateAddress"));
        sizePolicy2.setHeightForWidth(pbuttonCreateAddress->sizePolicy().hasHeightForWidth());
        pbuttonCreateAddress->setSizePolicy(sizePolicy2);
        pbuttonCreateAddress->setCursor(QCursor(Qt::PointingHandCursor));
        pbuttonCreateAddress->setStyleSheet(QString::fromUtf8("font: bold oblique 10pt Times; color: black;"));

        verticalLayout->addWidget(pbuttonCreateAddress);

        pbuttonSettingsAddress = new QPushButton(PostClass);
        pbuttonSettingsAddress->setObjectName(QString::fromUtf8("pbuttonSettingsAddress"));
        sizePolicy2.setHeightForWidth(pbuttonSettingsAddress->sizePolicy().hasHeightForWidth());
        pbuttonSettingsAddress->setSizePolicy(sizePolicy2);
        pbuttonSettingsAddress->setCursor(QCursor(Qt::PointingHandCursor));
        pbuttonSettingsAddress->setStyleSheet(QString::fromUtf8("font: bold oblique 10pt Times; color: black;"));

        verticalLayout->addWidget(pbuttonSettingsAddress);

        pbuttonSettings = new QPushButton(PostClass);
        pbuttonSettings->setObjectName(QString::fromUtf8("pbuttonSettings"));
        sizePolicy2.setHeightForWidth(pbuttonSettings->sizePolicy().hasHeightForWidth());
        pbuttonSettings->setSizePolicy(sizePolicy2);
        pbuttonSettings->setCursor(QCursor(Qt::PointingHandCursor));
        pbuttonSettings->setStyleSheet(QString::fromUtf8("font: bold oblique 10pt Times; color: black;"));

        verticalLayout->addWidget(pbuttonSettings);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pbuttonReceived = new QPushButton(PostClass);
        pbuttonReceived->setObjectName(QString::fromUtf8("pbuttonReceived"));
        sizePolicy1.setHeightForWidth(pbuttonReceived->sizePolicy().hasHeightForWidth());
        pbuttonReceived->setSizePolicy(sizePolicy1);
        pbuttonReceived->setCursor(QCursor(Qt::PointingHandCursor));
        pbuttonReceived->setStyleSheet(QString::fromUtf8("font: bold oblique 13pt Times; color: blue;"));
        pbuttonReceived->setFlat(true);

        verticalLayout->addWidget(pbuttonReceived);

        pbuttonSend = new QPushButton(PostClass);
        pbuttonSend->setObjectName(QString::fromUtf8("pbuttonSend"));
        sizePolicy1.setHeightForWidth(pbuttonSend->sizePolicy().hasHeightForWidth());
        pbuttonSend->setSizePolicy(sizePolicy1);
        pbuttonSend->setCursor(QCursor(Qt::PointingHandCursor));
        pbuttonSend->setStyleSheet(QString::fromUtf8("font: bold oblique 13pt Times; color: blue;"));
        pbuttonSend->setFlat(true);

        verticalLayout->addWidget(pbuttonSend);

        plblAccount_info = new QLabel(PostClass);
        plblAccount_info->setObjectName(QString::fromUtf8("plblAccount_info"));
        sizePolicy1.setHeightForWidth(plblAccount_info->sizePolicy().hasHeightForWidth());
        plblAccount_info->setSizePolicy(sizePolicy1);
        plblAccount_info->setStyleSheet(QString::fromUtf8("font: bold oblique 11pt Times; color: black;"));
        plblAccount_info->setFrameShape(QFrame::WinPanel);
        plblAccount_info->setFrameShadow(QFrame::Raised);
        plblAccount_info->setLineWidth(5);
        plblAccount_info->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(plblAccount_info);

        m_pAccountInfo = new QLabel(PostClass);
        m_pAccountInfo->setObjectName(QString::fromUtf8("m_pAccountInfo"));
        sizePolicy1.setHeightForWidth(m_pAccountInfo->sizePolicy().hasHeightForWidth());
        m_pAccountInfo->setSizePolicy(sizePolicy1);
        m_pAccountInfo->setStyleSheet(QString::fromUtf8("font: bold oblique 10pt Times; color: black;"));
        m_pAccountInfo->setFrameShape(QFrame::WinPanel);
        m_pAccountInfo->setFrameShadow(QFrame::Raised);
        m_pAccountInfo->setLineWidth(5);
        m_pAccountInfo->setAlignment(Qt::AlignCenter);
        m_pAccountInfo->setMargin(3);

        verticalLayout->addWidget(m_pAccountInfo);


        horizontalLayout_4->addLayout(verticalLayout);


        retranslateUi(PostClass);
        QObject::connect(pbuttonCreateAccount, SIGNAL(clicked()), PostClass, SLOT(slotCreateAccount()));
        QObject::connect(pbuttonSettingsAccount, SIGNAL(clicked()), PostClass, SLOT(slotCreateAccount()));
        QObject::connect(pbuttonCreateAddress, SIGNAL(clicked()), PostClass, SLOT(slotCreateAddress()));
        QObject::connect(pbuttonSettingsAddress, SIGNAL(clicked()), PostClass, SLOT(slotSettingsAddress()));
        QObject::connect(pbuttonSettings, SIGNAL(clicked()), PostClass, SLOT(slotSettings()));
        QObject::connect(pbuttonReceived, SIGNAL(clicked()), PostClass, SLOT(slotOutMessage()));
        QObject::connect(pbuttonSend, SIGNAL(clicked()), PostClass, SLOT(slotOutMessage()));
        QObject::connect(pcmd_receive, SIGNAL(clicked()), PostClass, SLOT(slotReceiveMessage()));
        QObject::connect(pcmd_clearreceive, SIGNAL(clicked()), PostClass, SLOT(slotClear()));
        QObject::connect(m_pinput_comServer, SIGNAL(returnPressed()), PostClass, SLOT(slotSendToServer()));
        QObject::connect(pcmd_clearsend, SIGNAL(clicked()), PostClass, SLOT(slotClear()));
        QObject::connect(pcmd_send, SIGNAL(clicked()), PostClass, SLOT(slotSendMessage()));
        QObject::connect(m_pTo, SIGNAL(textChanged(QString)), PostClass, SLOT(slottextChanged(QString)));
        QObject::connect(m_pSubject, SIGNAL(textChanged(QString)), PostClass, SLOT(slottextChanged(QString)));
        QObject::connect(m_pListAddress, SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)), PostClass, SLOT(slotChoiceAddress(QListWidgetItem*)));

        QMetaObject::connectSlotsByName(PostClass);
    } // setupUi

    void retranslateUi(QWidget *PostClass)
    {
        PostClass->setWindowTitle(QApplication::translate("PostClass", "\320\237\320\276\321\207\321\202\320\276\320\262\320\270\320\272", 0, QApplication::UnicodeUTF8));
        plblRec->setText(QApplication::translate("PostClass", "\320\237\320\276\320\273\321\203\321\207\320\265\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        plblSender->setText(QApplication::translate("PostClass", "\320\241\320\273\321\203\320\266\320\265\320\261\320\275\320\260\321\217 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", 0, QApplication::UnicodeUTF8));
        m_pCheckBox->setText(QApplication::translate("PostClass", "\320\240\321\203\321\207\320\275\320\276\320\271 \320\262\320\262\320\276\320\264 \320\272\320\276\320\274\320\260\320\275\320\264", 0, QApplication::UnicodeUTF8));
        m_pinfoReceive->setText(QString());
        pcmd_receive->setText(QApplication::translate("PostClass", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pcmd_clearreceive->setText(QApplication::translate("PostClass", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        plblMessage->setText(QApplication::translate("PostClass", "\320\235\320\276\320\262\320\276\320\265 \320\277\320\270\321\201\321\214\320\274\320\276", 0, QApplication::UnicodeUTF8));
        to->setText(QApplication::translate("PostClass", "\320\220\320\264\321\200\320\265\321\201", 0, QApplication::UnicodeUTF8));
        subject->setText(QApplication::translate("PostClass", "\320\242\320\265\320\274\320\260", 0, QApplication::UnicodeUTF8));
        m_pinfoSend->setText(QString());
        pcmd_send->setText(QApplication::translate("PostClass", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pcmd_clearsend->setText(QApplication::translate("PostClass", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        plblAddress->setText(QApplication::translate("PostClass", "\320\220\320\264\321\200\320\265\321\201\320\260", 0, QApplication::UnicodeUTF8));
        plblSettings->setText(QApplication::translate("PostClass", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", 0, QApplication::UnicodeUTF8));
        pbuttonCreateAccount->setText(QApplication::translate("PostClass", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \321\217\321\211\320\270\320\272", 0, QApplication::UnicodeUTF8));
        pbuttonSettingsAccount->setText(QApplication::translate("PostClass", "\320\235\320\260\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \321\217\321\211\320\270\320\272", 0, QApplication::UnicodeUTF8));
        pbuttonCreateAddress->setText(QApplication::translate("PostClass", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\260\320\264\321\200\320\265\321\201", 0, QApplication::UnicodeUTF8));
        pbuttonSettingsAddress->setText(QApplication::translate("PostClass", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\260\320\264\321\200\320\265\321\201", 0, QApplication::UnicodeUTF8));
        pbuttonSettings->setText(QApplication::translate("PostClass", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", 0, QApplication::UnicodeUTF8));
        pbuttonReceived->setText(QApplication::translate("PostClass", "\320\237\320\276\320\273\321\203\321\207\320\265\320\275\320\275\321\213\320\265", 0, QApplication::UnicodeUTF8));
        pbuttonSend->setText(QApplication::translate("PostClass", "\320\236\321\202\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\275\321\213\320\265", 0, QApplication::UnicodeUTF8));
        plblAccount_info->setText(QApplication::translate("PostClass", "\320\257\321\211\320\270\320\272", 0, QApplication::UnicodeUTF8));
        m_pAccountInfo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PostClass: public Ui_PostClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POST3_3_H
