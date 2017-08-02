#ifndef _FUNCTION_H_
#define _FUNCTION_H_
//#include "message.h"
#include "account.h"
//#include "post.h"
//#include "dialog.h"
//#include "address.h"
//#include <QFile>
//#include <QTextStream>
//#include <QTextEdit>
//#include <QLabel>
//#include <QSound>
#include <QtGui>

void initData(); // инициализация глобальных данных

// создание сообщения, если текущего ящика нет
int messageAccount(); 

// вывод команд для серверов на поле Служебная информация и вывод в сокет
void outputCommands(QTextEdit *m_ptxtSender, const QString commands, QTextStream &out);

// вывод сообщения в Информполе со звуковым сигналом
void outputInfo(QLabel *pinfo, const QString str, const QString str_sound, int err = 4);

// проверка выделения в списке и, если есть, сброс выделения
void undoselected(QListWidget *m_pListAddress);

// заполнение векторов командами для серверов
void setcommandsSMTP(const Account *m_pcurrentAccount, const QLineEdit *m_pTo);
void setcommandsPOP(const Account *m_pcurrentAccount);
//======================================================================================

// Шаблонные функции   /////////////////////////////////////////////////////////////////

// дозапись объекта в файл (если файла нет, то создаётся)................................................................
template <class T> 
bool writeObjectInFile(const T *object, const QString path) 
{
	QFile file(path);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) 
		return false;
	
	QTextStream fout(&file); 
	
	fout << *object;
	
	file.close();

	return true;
}

//..........................................................................................

// поиск и чтение нужного объекта из файла. search - строка, в данных объекта, для поиска в файле,
// n - номер строки в записи данных объекта (нумерация с 1)..................................

template <class T> 
bool readObjectFromFile(T *object, const QString path,            
                           const QString search, uint n)  
{
	QFile file(path);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) // тут сделать обработку ошибки при открытии файла
	{
	       return false;
	}
	
	QTextStream fin(&file);
	QString temp;
	n++;
	
	temp = fin.readLine(); // пропускаем первую строку (в случае с файлом ящиков, там e-mail текущего ящика)
		//qDebug() << "search = " << search << " " << search.size();
	while (true) // поиск и чтение нужной записи
	{
		temp = fin.readLine();
		//if (fin.atEnd()) break;
			//qDebug() << temp << " " << temp.size();
			//if (temp > search) qDebug() << " > ";
			//else qDebug() << " < ";
		if (temp == search)
		{
			uint k = 0;
	       
		    for (int j = 0; k < n; j++) // поиск начала записи нужного ящика
			{
					//qDebug() << "pos " << fin.pos();
				fin.seek(fin.pos() - 2);
					//qDebug() << "seek " << fin.pos();
				temp = fin.read(1);
					//qDebug() << "read " << fin.pos();
					//qDebug() << temp[0] << (uint)(temp.toStdString())[0];
		        if (temp[0] == '\n') 
				{
					k++;
					if (k < n) fin.seek(fin.pos() - 1);
						//qDebug() << "seek if " << fin.pos();
				}
			}
			    fin >> *object; // чтение найденной записи в объект
				break;
		} // if
	} // while
	
	file.close();
	
	return true;
}

//..............................................................................................

// поиск и чтение нужного объекта из вектора (object - куда читается) 
// search - строка, в данных объекта, для поиска в векторе. Возвращает индекс найденного объекта в векторе или -1.

template <class T> 
int readObjectFromVector(T *object, const QList <T> *pvectorObjects,            
                           const QString search)   
{
	QVector <QString> vecstring;
	
	for (int i = 0; i < pvectorObjects ->size(); i++) // поиск и чтение нужной записи
	{
		vecstring << (*pvectorObjects)[i]; // строки из объекта помещаются в вектор 
										   // (<< - перегруженный оператор)
		for (int j = 0; j < vecstring.size(); j++)
		{
			if (vecstring[j] == search) // если нужная строка в объекте найдена
			{
				*object = (*pvectorObjects)[i];
                            
			    return i; // индекс найденного объекта в векторе
			}
		} 
	} 
	return -1;
}

// запись объектов из вектора в новый файл.............................................................
template <class T>
bool writeVectorInFile(const QList <T> *pvectorObjects, const QString path) 
{
	QFile file(path);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) // тут сделать обработку ошибки при открытии файла
	{
	      return false;
	}
	
	QTextStream fout(&file);
	
	for (int i = 0; i < pvectorObjects ->size(); i++)
			fout << (*pvectorObjects)[i];

	file.close();
	return true;
}
//..............................................................................................

// чтение объектов из файла в вектор.............................................................
template <class T>
bool readFileInVector(QList <T> *pvectorObjects, const QString path, const QString splitter) 
{
	QFile file(path);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) // тут сделать обработку ошибки при открытии файла
	{
	     return false;
	}
	
	QTextStream fin(&file);
	QString temp;
	
	while (true) 
	{
		temp = fin.readLine();
			//qDebug() << temp;
		if (fin.atEnd()) break;
			
		if (temp == splitter) 
		{
			T tempObject; //qDebug() << "temp == splitter";
			
			fin >> tempObject; // чтение из файла записи объекта
					/*........................
						QTextStream stream(stdout);
						stream << tempObject;
					//........................*/
		    pvectorObjects ->push_back(tempObject); // сохранение объекта в векторе
		}
	} 
		//qDebug() << pvectorObjects ->size();
		//qDebug() << "\nreadAccount";
	
	file.close();
	
	return true;
}

//...............................................................................................

// вывод объектов из вектора в поле TextEdit ...................................................
template <class T>
void readVectorInEdit(const QList <T> *pvectorObjects, QTextEdit *pTextEdit) 
{
	//qDebug() << pvectorObjects ->size();
	
	for (int i = 0; i < pvectorObjects ->size(); i++)
	{
		pTextEdit << (*pvectorObjects)[i];
	}
	
	//qDebug() << "\nreadObjectsInEdit";
}

// вывод объектов из вектора в поле ListWidget ...................................................
template <class T>
void readVectorInListWidget(const QList <T> *pvectorObjects, QListWidget *pListWidget) 
{
	for (int i = 0; i < pvectorObjects ->size(); i++)
	{
		pListWidget << (*pvectorObjects)[i];
	}
}

template <class T>
void changeItemInListWidget(const QList <T> *m_pvectorMessage, QListWidget *m_pListMessage, const T &message)
{ 
	//readVectorInListWidget(m_pvectorMessageSend,     m_pListMessageSend    ); // заполняем список отправленных писем
	//readVectorInListWidget(m_pvectorMessageReceived, m_pListMessageReceived); // заполняем список полученных писем
}

#endif