#include <QTextCodec>
#include <QtGui>
#include <QApplication>
//#include <Windows.h>
//#include "data.h"
#include "post.h"
#include "functions.h"

#include <iostream>

int main(int argc, char *argv[])
{
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);
	
	QApplication app(argc, argv);

	QSplashScreen splash(QPixmap("icon1.png"));
	splash.show();
	
	initData(); // ��������� ������� ������ ��� ��-����� � tr, � ������������� ���������� ������

	///////////////////////////////////////////////////////////////////	
	
	//bool flag = LocalCodec ->canEncode(str);
	////QByteArray arr = str.toAscii();
	//std::cout << str.toLocal8Bit().data() << std::endl;
	//int a = 4;
	//QTextCodec *codec = QTextCodec::codecForName("ISO-8859-1");
 //   QString str = "????? ? ?? ?????.";
	////str = codec->toUnicode(str.toAscii());
	////qDebug() << str;
	//QChar *data = str.data();
	//for (uint i = 0; !data ->isNull(); i++)
	//{
	//	qDebug() << data ->unicode() << " ";
	//	++data;
	//}
	//QTextCodec *codec = QTextCodec::codecForName("CP1251");
	//QTextCodec::setCodecForTr(codec);
	
	
	//QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

	//QTextCodec *codec = QTextCodec::codecForName(/*"UTF-8"*/"ISO-8859-1"/*"KOI8-R"*/);
	//qDebug() << codec ->aliases();
	
	//QString str = /*QWidget::tr(*/"Go to me.";
	//qDebug() << (int)(str.toStdString().c_str()[0]);
	//QByteArray arr = codec ->fromUnicode(str);
	//qDebug() << (int)(str.toStdString().c_str()[0]);
	//qDebug() << arr;
	//qDebug() << codec ->toUnicode(arr);
	//qDebug() << (int)(str.toStdString().c_str()[0]);
	//qDebug() << str.toLatin1();
	//QChar ch = 'F';
	//qDebug() << QChar(0xFF).toLatin1();
	//qDebug() << codec ->fromUnicode(&ch, 1) << " " << ch.unicode() << " " << QChar(70);
 ///////////////////////////////////////////////////////////////////////////////////////////   
	
	Post post;
	post.setObjectName("post");

	//post.resize(1700, 850);
	//post.setMinimumHeight(850);
	post.move(50, 40);
	
    post.show();
    splash.finish(&post);
	
	if (post.m_flagExistAccount == 0 && messageAccount() == QMessageBox::Yes) // ���� ����� �� ����������, � ���� Yes,
		post.slotCreateAccount();                                             // �� ������� � �������� �����
	
	return app.exec();
}
