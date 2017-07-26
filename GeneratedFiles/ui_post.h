/********************************************************************************
** Form generated from reading UI file 'post.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POST_H
#define UI_POST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PostClass
{
public:
    QLabel *plblRec;
    QLabel *label_2;
    QLabel *plblAddress;
    QLabel *plblSettings;
    QTextEdit *m_ptxtReceiver;
    QTextEdit *m_ptxtSender;
    QLineEdit *m_pinput_comServer;
    QLineEdit *m_pTo;
    QLineEdit *m_pSubject;
    QTextEdit *m_ptxtMessage;
    QListWidget *m_pListAddress;
    QPushButton *pcmd_receive;
    QPushButton *pcmd_clearreceive;
    QPushButton *pcmd_send;
    QPushButton *pcmd_clearsend;
    QPushButton *pbuttonCreateAccount;
    QPushButton *pbuttonSettingsAccount;
    QPushButton *pbuttonCreateAddress;
    QPushButton *pbuttonSettingsAddress;
    QPushButton *pbuttonSettings;
    QLabel *m_pAccountInfo;
    QLabel *plblAccount_info;
    QPushButton *pbuttonReceived;
    QPushButton *pbuttonSend;
    QCheckBox *m_pCheckBox;
    QLabel *m_pinfoReceive;
    QLabel *plblSender;

    void setupUi(QWidget *PostClass)
    {
        if (PostClass->objectName().isEmpty())
            PostClass->setObjectName(QString::fromUtf8("PostClass"));
        PostClass->resize(1609, 868);
        PostClass->setMinimumSize(QSize(0, 850));
        PostClass->setCursor(QCursor(Qt::ArrowCursor));
        QIcon icon;
        icon.addFile(QString::fromUtf8("icon2.png"), QSize(), QIcon::Normal, QIcon::Off);
        PostClass->setWindowIcon(icon);
        plblRec = new QLabel(PostClass);
        plblRec->setObjectName(QString::fromUtf8("plblRec"));
        plblRec->setGeometry(QRect(25, 20, 496, 109));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plblRec->sizePolicy().hasHeightForWidth());
        plblRec->setSizePolicy(sizePolicy);
        plblRec->setStyleSheet(QString::fromUtf8("font: bold oblique 14pt Times; color: blue;"));
        plblRec->setFrameShape(QFrame::WinPanel);
        plblRec->setFrameShadow(QFrame::Raised);
        plblRec->setLineWidth(6);
        plblRec->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(PostClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(530, 20, 381, 41));
        label_2->setStyleSheet(QString::fromUtf8("font: bold oblique 14pt Times; color: blue;"));
        label_2->setFrameShape(QFrame::WinPanel);
        label_2->setFrameShadow(QFrame::Raised);
        label_2->setLineWidth(6);
        label_2->setAlignment(Qt::AlignCenter);
        plblAddress = new QLabel(PostClass);
        plblAddress->setObjectName(QString::fromUtf8("plblAddress"));
        plblAddress->setGeometry(QRect(930, 20, 366, 109));
        sizePolicy.setHeightForWidth(plblAddress->sizePolicy().hasHeightForWidth());
        plblAddress->setSizePolicy(sizePolicy);
        plblAddress->setStyleSheet(QString::fromUtf8("font: bold oblique 14pt Times; color: blue;"));
        plblAddress->setFrameShape(QFrame::WinPanel);
        plblAddress->setFrameShadow(QFrame::Raised);
        plblAddress->setLineWidth(6);
        plblAddress->setAlignment(Qt::AlignCenter);
        plblSettings = new QLabel(PostClass);
        plblSettings->setObjectName(QString::fromUtf8("plblSettings"));
        plblSettings->setGeometry(QRect(1325, 25, 256, 109));
        sizePolicy.setHeightForWidth(plblSettings->sizePolicy().hasHeightForWidth());
        plblSettings->setSizePolicy(sizePolicy);
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
        m_ptxtReceiver = new QTextEdit(PostClass);
        m_ptxtReceiver->setObjectName(QString::fromUtf8("m_ptxtReceiver"));
        m_ptxtReceiver->setGeometry(QRect(25, 140, 700, 321));
        m_ptxtReceiver->setMinimumSize(QSize(700, 0));
        m_ptxtReceiver->setStyleSheet(QString::fromUtf8("font: oblique 12pt Times; color: black;"));
        m_ptxtReceiver->setFrameShape(QFrame::WinPanel);
        m_ptxtReceiver->setFrameShadow(QFrame::Raised);
        m_ptxtReceiver->setLineWidth(7);
        m_ptxtReceiver->setReadOnly(true);
        m_ptxtSender = new QTextEdit(PostClass);
        m_ptxtSender->setObjectName(QString::fromUtf8("m_ptxtSender"));
        m_ptxtSender->setGeometry(QRect(25, 530, 700, 201));
        m_ptxtSender->setMinimumSize(QSize(700, 0));
        m_ptxtSender->setStyleSheet(QString::fromUtf8("font: 9pt Arial; color: black;"));
        m_ptxtSender->setFrameShape(QFrame::WinPanel);
        m_ptxtSender->setFrameShadow(QFrame::Raised);
        m_ptxtSender->setLineWidth(6);
        m_ptxtSender->setReadOnly(true);
        m_pinput_comServer = new QLineEdit(PostClass);
        m_pinput_comServer->setObjectName(QString::fromUtf8("m_pinput_comServer"));
        m_pinput_comServer->setGeometry(QRect(25, 745, 281, 35));
        m_pinput_comServer->setStyleSheet(QString::fromUtf8("font: 12pt Times; color: black;"));
        m_pTo = new QLineEdit(PostClass);
        m_pTo->setObjectName(QString::fromUtf8("m_pTo"));
        m_pTo->setGeometry(QRect(535, 79, 181, 36));
        m_pSubject = new QLineEdit(PostClass);
        m_pSubject->setObjectName(QString::fromUtf8("m_pSubject"));
        m_pSubject->setGeometry(QRect(730, 80, 181, 36));
        m_ptxtMessage = new QTextEdit(PostClass);
        m_ptxtMessage->setObjectName(QString::fromUtf8("m_ptxtMessage"));
        m_ptxtMessage->setGeometry(QRect(535, 135, 376, 601));
        m_pListAddress = new QListWidget(PostClass);
        m_pListAddress->setObjectName(QString::fromUtf8("m_pListAddress"));
        m_pListAddress->setGeometry(QRect(930, 140, 366, 691));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(m_pListAddress->sizePolicy().hasHeightForWidth());
        m_pListAddress->setSizePolicy(sizePolicy1);
        m_pListAddress->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        m_pListAddress->setStyleSheet(QString::fromUtf8("font: oblique bold 13pt Times; color: black;"));
        m_pListAddress->setIconSize(QSize(124, 152));
        m_pListAddress->setViewMode(QListView::IconMode);
        pcmd_receive = new QPushButton(PostClass);
        pcmd_receive->setObjectName(QString::fromUtf8("pcmd_receive"));
        pcmd_receive->setGeometry(QRect(30, 800, 356, 34));
        pcmd_receive->setCursor(QCursor(Qt::PointingHandCursor));
        pcmd_receive->setStyleSheet(QString::fromUtf8("font: bold oblique 11pt Times; color: black;"));
        pcmd_clearreceive = new QPushButton(PostClass);
        pcmd_clearreceive->setObjectName(QString::fromUtf8("pcmd_clearreceive"));
        pcmd_clearreceive->setGeometry(QRect(400, 800, 112, 34));
        pcmd_clearreceive->setCursor(QCursor(Qt::PointingHandCursor));
        pcmd_clearreceive->setStyleSheet(QString::fromUtf8("font: bold oblique 11pt Times; color: black;"));
        pcmd_send = new QPushButton(PostClass);
        pcmd_send->setObjectName(QString::fromUtf8("pcmd_send"));
        pcmd_send->setGeometry(QRect(535, 800, 241, 34));
        pcmd_send->setCursor(QCursor(Qt::PointingHandCursor));
        pcmd_send->setStyleSheet(QString::fromUtf8("font: bold oblique 11pt Times; color: black;"));
        pcmd_clearsend = new QPushButton(PostClass);
        pcmd_clearsend->setObjectName(QString::fromUtf8("pcmd_clearsend"));
        pcmd_clearsend->setGeometry(QRect(795, 800, 121, 34));
        pcmd_clearsend->setStyleSheet(QString::fromUtf8("font: bold oblique 11pt Times; color: black;"));
        pbuttonCreateAccount = new QPushButton(PostClass);
        pbuttonCreateAccount->setObjectName(QString::fromUtf8("pbuttonCreateAccount"));
        pbuttonCreateAccount->setGeometry(QRect(1320, 150, 256, 34));
        pbuttonCreateAccount->setCursor(QCursor(Qt::PointingHandCursor));
        pbuttonCreateAccount->setStyleSheet(QString::fromUtf8("font: bold oblique 10pt Times; color: black;"));
        pbuttonSettingsAccount = new QPushButton(PostClass);
        pbuttonSettingsAccount->setObjectName(QString::fromUtf8("pbuttonSettingsAccount"));
        pbuttonSettingsAccount->setGeometry(QRect(1320, 195, 256, 34));
        pbuttonSettingsAccount->setCursor(QCursor(Qt::PointingHandCursor));
        pbuttonSettingsAccount->setStyleSheet(QString::fromUtf8("font: bold oblique 10pt Times; color: black;"));
        pbuttonCreateAddress = new QPushButton(PostClass);
        pbuttonCreateAddress->setObjectName(QString::fromUtf8("pbuttonCreateAddress"));
        pbuttonCreateAddress->setGeometry(QRect(1320, 240, 256, 34));
        pbuttonCreateAddress->setCursor(QCursor(Qt::PointingHandCursor));
        pbuttonCreateAddress->setStyleSheet(QString::fromUtf8("font: bold oblique 10pt Times; color: black;"));
        pbuttonSettingsAddress = new QPushButton(PostClass);
        pbuttonSettingsAddress->setObjectName(QString::fromUtf8("pbuttonSettingsAddress"));
        pbuttonSettingsAddress->setGeometry(QRect(1315, 285, 261, 34));
        pbuttonSettingsAddress->setCursor(QCursor(Qt::PointingHandCursor));
        pbuttonSettingsAddress->setStyleSheet(QString::fromUtf8("font: bold oblique 10pt Times; color: black;"));
        pbuttonSettings = new QPushButton(PostClass);
        pbuttonSettings->setObjectName(QString::fromUtf8("pbuttonSettings"));
        pbuttonSettings->setGeometry(QRect(1315, 330, 261, 34));
        pbuttonSettings->setCursor(QCursor(Qt::PointingHandCursor));
        pbuttonSettings->setStyleSheet(QString::fromUtf8("font: bold oblique 10pt Times; color: black;"));
        m_pAccountInfo = new QLabel(PostClass);
        m_pAccountInfo->setObjectName(QString::fromUtf8("m_pAccountInfo"));
        m_pAccountInfo->setGeometry(QRect(1310, 790, 276, 35));
        sizePolicy.setHeightForWidth(m_pAccountInfo->sizePolicy().hasHeightForWidth());
        m_pAccountInfo->setSizePolicy(sizePolicy);
        m_pAccountInfo->setStyleSheet(QString::fromUtf8("font: bold oblique 10pt Times; color: black;"));
        m_pAccountInfo->setFrameShape(QFrame::WinPanel);
        m_pAccountInfo->setFrameShadow(QFrame::Raised);
        m_pAccountInfo->setLineWidth(5);
        m_pAccountInfo->setAlignment(Qt::AlignCenter);
        m_pAccountInfo->setMargin(3);
        plblAccount_info = new QLabel(PostClass);
        plblAccount_info->setObjectName(QString::fromUtf8("plblAccount_info"));
        plblAccount_info->setGeometry(QRect(1315, 740, 271, 37));
        sizePolicy.setHeightForWidth(plblAccount_info->sizePolicy().hasHeightForWidth());
        plblAccount_info->setSizePolicy(sizePolicy);
        plblAccount_info->setStyleSheet(QString::fromUtf8("font: bold oblique 11pt Times; color: black;"));
        plblAccount_info->setFrameShape(QFrame::WinPanel);
        plblAccount_info->setFrameShadow(QFrame::Raised);
        plblAccount_info->setLineWidth(5);
        plblAccount_info->setAlignment(Qt::AlignCenter);
        pbuttonReceived = new QPushButton(PostClass);
        pbuttonReceived->setObjectName(QString::fromUtf8("pbuttonReceived"));
        pbuttonReceived->setGeometry(QRect(1320, 650, 241, 34));
        pbuttonReceived->setCursor(QCursor(Qt::PointingHandCursor));
        pbuttonReceived->setStyleSheet(QString::fromUtf8("font: bold oblique 13pt Times; color: blue;"));
        pbuttonReceived->setFlat(true);
        pbuttonSend = new QPushButton(PostClass);
        pbuttonSend->setObjectName(QString::fromUtf8("pbuttonSend"));
        pbuttonSend->setGeometry(QRect(1305, 695, 251, 34));
        pbuttonSend->setCursor(QCursor(Qt::PointingHandCursor));
        pbuttonSend->setStyleSheet(QString::fromUtf8("font: bold oblique 13pt Times; color: blue;"));
        pbuttonSend->setFlat(true);
        m_pCheckBox = new QCheckBox(PostClass);
        m_pCheckBox->setObjectName(QString::fromUtf8("m_pCheckBox"));
        m_pCheckBox->setGeometry(QRect(335, 750, 181, 23));
        m_pCheckBox->setStyleSheet(QString::fromUtf8("font: 11pt Times; color: black;"));
        m_pinfoReceive = new QLabel(PostClass);
        m_pinfoReceive->setObjectName(QString::fromUtf8("m_pinfoReceive"));
        m_pinfoReceive->setGeometry(QRect(535, 750, 381, 41));
        m_pinfoReceive->setStyleSheet(QString::fromUtf8("font: bold oblique 13pt Times; color: red;"));
        m_pinfoReceive->setFrameShape(QFrame::WinPanel);
        m_pinfoReceive->setFrameShadow(QFrame::Raised);
        m_pinfoReceive->setLineWidth(6);
        m_pinfoReceive->setAlignment(Qt::AlignCenter);
        m_pinfoReceive->setMargin(3);
        plblSender = new QLabel(PostClass);
        plblSender->setObjectName(QString::fromUtf8("plblSender"));
        plblSender->setGeometry(QRect(25, 470, 491, 40));
        sizePolicy.setHeightForWidth(plblSender->sizePolicy().hasHeightForWidth());
        plblSender->setSizePolicy(sizePolicy);
        plblSender->setStyleSheet(QString::fromUtf8("font: bold oblique 12pt Times; color: blue;"));
        plblSender->setFrameShape(QFrame::WinPanel);
        plblSender->setFrameShadow(QFrame::Raised);
        plblSender->setLineWidth(6);
        plblSender->setAlignment(Qt::AlignCenter);

        retranslateUi(PostClass);
        QObject::connect(m_pListAddress, SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)), PostClass, SLOT(slotChoiceAddress(QListWidgetItem*)));
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

        QMetaObject::connectSlotsByName(PostClass);
    } // setupUi

    void retranslateUi(QWidget *PostClass)
    {
        PostClass->setWindowTitle(QApplication::translate("PostClass", "\320\237\320\276\321\207\321\202\320\276\320\262\320\270\320\272", 0, QApplication::UnicodeUTF8));
        plblRec->setText(QApplication::translate("PostClass", "\320\237\320\276\320\273\321\203\321\207\320\265\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("PostClass", "\320\235\320\276\320\262\320\276\320\265 \320\277\320\270\321\201\321\214\320\274\320\276", 0, QApplication::UnicodeUTF8));
        plblAddress->setText(QApplication::translate("PostClass", "\320\220\320\264\321\200\320\265\321\201\320\260", 0, QApplication::UnicodeUTF8));
        plblSettings->setText(QApplication::translate("PostClass", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", 0, QApplication::UnicodeUTF8));
        pcmd_receive->setText(QApplication::translate("PostClass", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pcmd_clearreceive->setText(QApplication::translate("PostClass", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pcmd_send->setText(QApplication::translate("PostClass", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pcmd_clearsend->setText(QApplication::translate("PostClass", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pbuttonCreateAccount->setText(QApplication::translate("PostClass", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \321\217\321\211\320\270\320\272", 0, QApplication::UnicodeUTF8));
        pbuttonSettingsAccount->setText(QApplication::translate("PostClass", "\320\235\320\260\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \321\217\321\211\320\270\320\272", 0, QApplication::UnicodeUTF8));
        pbuttonCreateAddress->setText(QApplication::translate("PostClass", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\260\320\264\321\200\320\265\321\201", 0, QApplication::UnicodeUTF8));
        pbuttonSettingsAddress->setText(QApplication::translate("PostClass", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214/\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\260\320\264\321\200\320\265\321\201", 0, QApplication::UnicodeUTF8));
        pbuttonSettings->setText(QApplication::translate("PostClass", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", 0, QApplication::UnicodeUTF8));
        m_pAccountInfo->setText(QString());
        plblAccount_info->setText(QApplication::translate("PostClass", "\320\257\321\211\320\270\320\272", 0, QApplication::UnicodeUTF8));
        pbuttonReceived->setText(QApplication::translate("PostClass", "\320\237\320\276\320\273\321\203\321\207\320\265\320\275\320\275\321\213\320\265", 0, QApplication::UnicodeUTF8));
        pbuttonSend->setText(QApplication::translate("PostClass", "\320\236\321\202\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\275\321\213\320\265", 0, QApplication::UnicodeUTF8));
        m_pCheckBox->setText(QApplication::translate("PostClass", "\320\240\321\203\321\207\320\275\320\276\320\271 \320\262\320\262\320\276\320\264 \320\272\320\276\320\274\320\260\320\275\320\264", 0, QApplication::UnicodeUTF8));
        m_pinfoReceive->setText(QString());
        plblSender->setText(QApplication::translate("PostClass", "\320\241\320\273\321\203\320\266\320\265\320\261\320\275\320\260\321\217 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PostClass: public Ui_PostClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POST_H
