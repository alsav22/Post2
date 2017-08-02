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

void initData(); // ������������� ���������� ������

// �������� ���������, ���� �������� ����� ���
int messageAccount(); 

// ����� ������ ��� �������� �� ���� ��������� ���������� � ����� � �����
void outputCommands(QTextEdit *m_ptxtSender, const QString commands, QTextStream &out);

// ����� ��������� � ���������� �� �������� ��������
void outputInfo(QLabel *pinfo, const QString str, const QString str_sound, int err = 4);

// �������� ��������� � ������ �, ���� ����, ����� ���������
void undoselected(QListWidget *m_pListAddress);

// ���������� �������� ��������� ��� ��������
void setcommandsSMTP(const Account *m_pcurrentAccount, const QLineEdit *m_pTo);
void setcommandsPOP(const Account *m_pcurrentAccount);
//======================================================================================

// ��������� �������   /////////////////////////////////////////////////////////////////

// �������� ������� � ���� (���� ����� ���, �� ��������)................................................................
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

// ����� � ������ ������� ������� �� �����. search - ������, � ������ �������, ��� ������ � �����,
// n - ����� ������ � ������ ������ ������� (��������� � 1)..................................

template <class T> 
bool readObjectFromFile(T *object, const QString path,            
                           const QString search, uint n)  
{
	QFile file(path);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) // ��� ������� ��������� ������ ��� �������� �����
	{
	       return false;
	}
	
	QTextStream fin(&file);
	QString temp;
	n++;
	
	temp = fin.readLine(); // ���������� ������ ������ (� ������ � ������ ������, ��� e-mail �������� �����)
		//qDebug() << "search = " << search << " " << search.size();
	while (true) // ����� � ������ ������ ������
	{
		temp = fin.readLine();
		//if (fin.atEnd()) break;
			//qDebug() << temp << " " << temp.size();
			//if (temp > search) qDebug() << " > ";
			//else qDebug() << " < ";
		if (temp == search)
		{
			uint k = 0;
	       
		    for (int j = 0; k < n; j++) // ����� ������ ������ ������� �����
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
			    fin >> *object; // ������ ��������� ������ � ������
				break;
		} // if
	} // while
	
	file.close();
	
	return true;
}

//..............................................................................................

// ����� � ������ ������� ������� �� ������� (object - ���� ��������) 
// search - ������, � ������ �������, ��� ������ � �������. ���������� ������ ���������� ������� � ������� ��� -1.

template <class T> 
int readObjectFromVector(T *object, const QList <T> *pvectorObjects,            
                           const QString search)   
{
	QVector <QString> vecstring;
	
	for (int i = 0; i < pvectorObjects ->size(); i++) // ����� � ������ ������ ������
	{
		vecstring << (*pvectorObjects)[i]; // ������ �� ������� ���������� � ������ 
										   // (<< - ������������� ��������)
		for (int j = 0; j < vecstring.size(); j++)
		{
			if (vecstring[j] == search) // ���� ������ ������ � ������� �������
			{
				*object = (*pvectorObjects)[i];
                            
			    return i; // ������ ���������� ������� � �������
			}
		} 
	} 
	return -1;
}

// ������ �������� �� ������� � ����� ����.............................................................
template <class T>
bool writeVectorInFile(const QList <T> *pvectorObjects, const QString path) 
{
	QFile file(path);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) // ��� ������� ��������� ������ ��� �������� �����
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

// ������ �������� �� ����� � ������.............................................................
template <class T>
bool readFileInVector(QList <T> *pvectorObjects, const QString path, const QString splitter) 
{
	QFile file(path);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) // ��� ������� ��������� ������ ��� �������� �����
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
			
			fin >> tempObject; // ������ �� ����� ������ �������
					/*........................
						QTextStream stream(stdout);
						stream << tempObject;
					//........................*/
		    pvectorObjects ->push_back(tempObject); // ���������� ������� � �������
		}
	} 
		//qDebug() << pvectorObjects ->size();
		//qDebug() << "\nreadAccount";
	
	file.close();
	
	return true;
}

//...............................................................................................

// ����� �������� �� ������� � ���� TextEdit ...................................................
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

// ����� �������� �� ������� � ���� ListWidget ...................................................
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
	//readVectorInListWidget(m_pvectorMessageSend,     m_pListMessageSend    ); // ��������� ������ ������������ �����
	//readVectorInListWidget(m_pvectorMessageReceived, m_pListMessageReceived); // ��������� ������ ���������� �����
}

#endif