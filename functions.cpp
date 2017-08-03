#include <QtGui>
#include "functions.h"
#include "message.h"
//#include "account.h"
#include "post.h"
#include "dialog.h"
#include "address.h"
//#include "data.h"
//#include <QFile>
//#include <QTextStream>
#include <QtNetwork>
#include "data.h"

// инициализация кодеков и глобальных данных
void initData()
{
	QTextCodec::setCodecForTr(LocalCodec);
	QTextCodec::setCodecForCStrings(LocalCodec); // кодек для Си-строк и QByteArray
	
	Info tempInfo[] = { {"Письмо успешно отправлено!"  , "sound/send_done.wav"  },
                         {"Ошибка при отправке письма!" , "sound/send_error.wav" },
                         {"У вас новая почта!"          , "sound/rec_done.wav"   },
                         {"Ошибка при получении писем!" , "sound/rec_error.wav"  },
                         {"Нет новых писем!" ,            "sound/rec_info2.wav"  } }; 
	
	for (int i = 0; i < sizeof(tempInfo) / sizeof(Info); ++i)
		arrInfo[i] = tempInfo[i];
	
	QString tempError[] = {"\nОшибка приветствия сервера.",       "\nЗапрос на аутентификацию не прошёл.", 
                            "\nПроверьте логин или пароль.",       "\nПроверьте логин или пароль.",
			                "\nПроверьте Ящик.",                   "\nПроверьте Адрес.", 
				            "\nНеполадки в сети или на сервере.",  "\nНеполадки в сети или на сервере."};

	for (int i = 0; i < sizeof(tempError) / sizeof(tempError[0]); ++i)
		arrError[i] = tempError[i];
}

// форматирование данных для отправки на SMTP сервер
void formatMessageForSMTP(QString& letter, const Post* post, const QTextCodec* codec)
{
	QString charset("=?" + codec ->name() + "?");
	QString beg("B?");
	QString end("?= ");
	letter.append("From: " + charset + beg +
			        codec ->fromUnicode(post ->m_pcurrentAccount ->getname()).toBase64() + 
					end + '<' + post ->m_pcurrentAccount ->gete_mail() + '>' + RN); 
		
	letter.append("To: " + charset + beg +
					codec ->fromUnicode(post ->m_pcurrentAddress ->getname()).toBase64() +
					end + '<' + post ->m_pcurrentAddress ->gete_mail() + '>' + RN);
		
	letter.append("Subject: " + charset + beg +
					codec ->fromUnicode(post ->m_pcurrentMessage ->getsubject()).toBase64() + 
					end + RN);

	letter.append("MIME-Version: 1.0" + RN );
	letter.append("Content-Type: text/plain; charset=" + codec ->name() + RN);
	letter.append("Content-Transfer-Encoding: 8bit" + RN); // без этого в оригинале письма будет quoted-printable

	letter.append(RN); // отделяем заголовки от тела письма
	letter.append(post ->m_pcurrentMessage ->gettext()); // тело письма
	letter.append(QString(RN + "." + RN)); // признак конца данных
}

// вывод команд для серверов на поле Служебная информация и вывод в сокет......................................................................................
void outputCommands(QTextEdit *m_ptxtSender, const QString commands, QTextStream &out)
{
	m_ptxtSender ->append(commands);
	out << commands + RN;
	out.flush();
}

// вывод сообщения в Информполе со звуковым сигналом .....................................................................................

void outputInfo(QLabel *pinfo, const QString str, const QString str_sound, int err)
{
	if (err == SEND_ERROR || err == REC_ERROR)
		pinfo ->setStyleSheet("font: bold oblique 13pt Times; color: red;");
	else if (err == SEND_DONE || err == REC_DONE)
		pinfo ->setStyleSheet("font: bold oblique 13pt Times; color: #22BB22;");
	else
		pinfo ->setStyleSheet("font: bold oblique 13pt Times; color: #483D8B;");
	pinfo ->clear();
	
	//pinfo ->setText(QWidget::tr(str.toStdString().c_str()));
	//pinfo ->setText(QWidget::tr(str.toAscii().data()));
	pinfo ->setText(str);
	QSound::play(str_sound);
}

// заполнение векторa командами для сервера SMTP........................................................

void setcommandsSMTP(const Account *m_pcurrentAccount, const QLineEdit *m_pTo)
{
	if (!vectorCommands.empty()) vectorCommands.clear();
	vectorCommands.push_back(arrCommandsSMTP[0] + m_pcurrentAccount ->getlogin());
	vectorCommands.push_back(arrCommandsSMTP[1]);
	vectorCommands.push_back(m_pcurrentAccount ->getloginBase64());
	vectorCommands.push_back(m_pcurrentAccount ->getpasswordBase64());
    vectorCommands.push_back(arrCommandsSMTP[4] + '<' + m_pcurrentAccount ->gete_mail() + '>'); // "MAIL FROM: <адрес от кого письмо>"
	vectorCommands.push_back(arrCommandsSMTP[5] + '<' + m_pTo ->text() + '>'); // "RCPT TO: <адрес кому письмо>"
	vectorCommands.push_back(arrCommandsSMTP[6]);
	vectorCommands.push_back(arrCommandsSMTP[7]);
}	

//.........................................................................

// заполнение векторa командами для сервера POP
 void setcommandsPOP(const Account *m_pcurrentAccount)
 {   
	// если удалять письма на сервере
	if (m_pcurrentAccount ->getflagdele() == "1")
	{
		arrCommandsPOP_USER[5]       = "DELE ";
		arrCommandsPOP_AUTH_LOGIN[5] = "DELE ";
	}
	else 
	{
		arrCommandsPOP_USER[5]       = "NOOP";
		arrCommandsPOP_AUTH_LOGIN[5] = "NOOP";
	}
	//if (m_pcurrentAccount ->getHostPOP() /*== "pop.yandex.ru" || m_pcurrentAccount ->getHostPOP()*/ == "pop.gmail.com"
	                                                        ///*|| m_pcurrentAccount ->getHostPOP() == "mail.rambler.ru"*/)
	//{
		// с USER , PASS.
		if (!vectorCommands.empty()) vectorCommands.clear();
		vectorCommands.push_back(arrCommandsPOP_USER[0] + m_pcurrentAccount ->getlogin());
		vectorCommands.push_back(arrCommandsPOP_USER[1] + m_pcurrentAccount ->getpassword());
		vectorCommands.push_back(arrCommandsPOP_USER[2]);
		vectorCommands.push_back(arrCommandsPOP_USER[3]);
		vectorCommands.push_back(arrCommandsPOP_USER[4]);
		vectorCommands.push_back(arrCommandsPOP_USER[5]);
		vectorCommands.push_back(arrCommandsPOP_USER[6]);
	//}
    //else
	//{
		//// с AUTH LOGIN
		//if (!vectorCommPOP.empty()) vectorCommPOP.clear();
		//vectorCommPOP.push_back(arrCommandsPOP_AUTH_LOGIN[0]);
		//vectorCommPOP.push_back(m_pcurrentAccount ->getloginBase64());
		//vectorCommPOP.push_back(m_pcurrentAccount ->getpasswordBase64());
		//vectorCommPOP.push_back(arrCommandsPOP_AUTH_LOGIN[3]);
		//vectorCommPOP.push_back(arrCommandsPOP_AUTH_LOGIN[4]);
		//vectorCommPOP.push_back(arrCommandsPOP_AUTH_LOGIN[5]);
		//vectorCommPOP.push_back(arrCommandsPOP_AUTH_LOGIN[6]);
	//}
}

// окно сообщения, если нет ящиков..............................................

int messageAccount() 
{
	    QMessageBox *pmessage = new QMessageBox;
		
		pmessage ->setText       (QWidget::tr("Не существует ни одного ящика.\n"
									          "Перейти к созданию ящика ?"));
		pmessage ->setWindowTitle(QWidget::tr("Внимание!"));
		pmessage ->addButton     (QMessageBox::Yes);
		pmessage ->addButton     (QMessageBox::No);
		pmessage ->addButton     (QMessageBox::Cancel);
		pmessage ->setButtonText (QMessageBox::Yes,    QWidget::tr("Да"));
		pmessage ->setButtonText (QMessageBox::No,     QWidget::tr("Нет"));
		pmessage ->setButtonText (QMessageBox::Cancel, QWidget::tr("Выйти"));
		pmessage ->setIcon       (QMessageBox::Warning);
		pmessage ->setStyleSheet ("font: 12pt Times; color: black;"); // bold 

		pmessage ->button(QMessageBox::Yes)    ->setStyleSheet( "font: bold 10pt Arial; color: black;");
		pmessage ->button(QMessageBox::No)     ->setStyleSheet( "font: bold 10pt Arial; color: black;");
		pmessage ->button(QMessageBox::Cancel) ->setStyleSheet( "font: bold 10pt Arial; color: black;");
		
		int n = pmessage ->exec();
		
		delete pmessage;
	
	    return n;
}

// проверка выделения в списке и, если есть, сброс выделения

void undoselected(QListWidget *m_pListAddress)
{
	if (m_pListAddress ->count())
		if (!m_pListAddress ->selectedItems().isEmpty())
			m_pListAddress  ->currentItem() ->setSelected(false);
}





