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

// ������������� ������� � ���������� ������
void initData()
{
	QTextCodec::setCodecForTr(LocalCodec);
	QTextCodec::setCodecForCStrings(LocalCodec); // ����� ��� ��-����� � QByteArray
	
	Info tempInfo[] = { {"������ ������� ����������!"  , "sound/send_done.wav"  },
                        {"������ ��� �������� ������!" , "sound/send_error.wav" },
                        {"� ��� ����� �����!"          , "sound/rec_done.wav"   },
                        {"������ ��� ��������� �����!" , "sound/rec_error.wav"  },
                        {"��� ����� �����!" ,            "sound/rec_info2.wav"  } }; 
	
	for (int i = 0; i < sizeof(tempInfo) / sizeof(Info); ++i)
		arrInfo.push_back(tempInfo[i]);
	
	QString tempError[] = {"\n������ ����������� �������.",       "\n������ �� �������������� �� ������.", 
                           "\n��������� ����� ��� ������.",       "\n��������� ����� ��� ������.",
			               "\n��������� ����.",                   "\n��������� �����.", 
				           "\n��������� � ���� ��� �� �������.",  "\n��������� � ���� ��� �� �������."};

	for (int i = 0; i < sizeof(tempError) / sizeof(tempError[0]); ++i)
		arrError.push_back(tempError[i]);
}

// ������ ������ �� �������������� �����
bool readFile(QByteArray& buffer, const QString path)
{
	QFile file(path);
	if (file.open(QIODevice::ReadOnly))
	{
		qint64 sizefile = file.size();
		buffer.resize(sizefile); // �������� ������ (readRawData() �� ������ resize() �������)

		QDataStream stream(&file);
		int sizeread = stream.readRawData(buffer.data(), sizefile);
		//stream >> buffer; // ��� �� ����� (�������� ���������, �����, ��������������� QByteArray,
		                    // ������� ������ ������, �����, ����������� � ���� �������, ����� �����,
		                    // ������ ��� ���� ��������������)
		if (sizeread == sizefile)
			return true;
		else
		{
			QMessageBox::critical(0, "������!", "������ ��� �������� ����� " + path + "!");
			return false;
		}
	}
	else
	{
		QMessageBox::critical(nullptr, "������!", "���� " + path + " �� ������!");
	qDebug() << "Error opening file!";
		return false;
	}
}

// ����� ������ ��� �������� �� ���� ��������� ���������� � ����� � �����......................................................................................
void outputCommands(QTextEdit *m_ptxtSender, const QString commands, QTextStream &out)
{
	m_ptxtSender ->append(commands);
	out << commands + RN;
	out.flush();
}

// ����� ��������� � ���������� �� �������� �������� .....................................................................................

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

// ���������� ������a ��������� ��� ������� SMTP........................................................

void setcommandsSMTP(const Account *m_pcurrentAccount, const QLineEdit *m_pTo)
{
	if (!vectorCommands.empty()) vectorCommands.clear();
	vectorCommands.push_back(arrCommandsSMTP[0] + m_pcurrentAccount ->getlogin());
	vectorCommands.push_back(arrCommandsSMTP[1]);
	vectorCommands.push_back(m_pcurrentAccount ->getloginBase64());
	vectorCommands.push_back(m_pcurrentAccount ->getpasswordBase64());
    vectorCommands.push_back(arrCommandsSMTP[4] + '<' + m_pcurrentAccount ->gete_mail() + '>'); // "MAIL FROM: <����� �� ���� ������>"
	vectorCommands.push_back(arrCommandsSMTP[5] + '<' + m_pTo ->text() + '>'); // "RCPT TO: <����� ���� ������>"
	vectorCommands.push_back(arrCommandsSMTP[6]);
	vectorCommands.push_back(arrCommandsSMTP[7]);
}	

//.........................................................................

// ���������� ������a ��������� ��� ������� POP
 void setcommandsPOP(const Account *m_pcurrentAccount)
 {   
	// ���� ������� ������ �� �������
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
		// � USER , PASS.
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
		//// � AUTH LOGIN
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

// ���� ���������, ���� ��� ������..............................................

int messageAccount() 
{
	    QMessageBox *pmessage = new QMessageBox;
		
		pmessage ->setText       (QWidget::tr("�� ���������� �� ������ �����.\n"
									          "������� � �������� ����� ?"));
		pmessage ->setWindowTitle(QWidget::tr("��������!"));
		pmessage ->addButton     (QMessageBox::Yes);
		pmessage ->addButton     (QMessageBox::No);
		pmessage ->addButton     (QMessageBox::Cancel);
		pmessage ->setButtonText (QMessageBox::Yes,    QWidget::tr("��"));
		pmessage ->setButtonText (QMessageBox::No,     QWidget::tr("���"));
		pmessage ->setButtonText (QMessageBox::Cancel, QWidget::tr("�����"));
		pmessage ->setIcon       (QMessageBox::Warning);
		pmessage ->setStyleSheet ("font: 12pt Times; color: black;"); // bold 

		pmessage ->button(QMessageBox::Yes)    ->setStyleSheet( "font: bold 10pt Arial; color: black;");
		pmessage ->button(QMessageBox::No)     ->setStyleSheet( "font: bold 10pt Arial; color: black;");
		pmessage ->button(QMessageBox::Cancel) ->setStyleSheet( "font: bold 10pt Arial; color: black;");
		
		int n = pmessage ->exec();
		
		delete pmessage;
	
	    return n;
}

// �������� ��������� � ������ �, ���� ����, ����� ���������

void undoselected(QListWidget *m_pListAddress)
{
	if (m_pListAddress ->count())
		if (!m_pListAddress ->selectedItems().isEmpty())
			m_pListAddress  ->currentItem() ->setSelected(false);
}





