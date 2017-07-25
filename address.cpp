#include "address.h"
#include <QtGui>

const QString Address::PATH = "./Images/";

Address::Address(QString name, 
                 QString e_mail, 
				 QString image)
				 
{
	m_name   = name;
	m_e_mail = e_mail;
	m_image  = image;
}

Address::Address()
{
	m_name   = "";
	m_e_mail = "";
	m_image  = "";
}
	
QTextStream& operator<<(QTextStream &out, const Address &address) // вывод адреса в поток
{
	out                 << S 
	                    << N
	<< address.m_name   << N
	<< address.m_e_mail << N
	<< address.m_image  << N;
	
	return out;
}

void operator<<(QTextEdit *pTextEdit, const Address &address) // вывод адреса в поле TextEdit
{
	pTextEdit ->append("-----------"   );
	pTextEdit ->append(address.m_name  );
	pTextEdit ->append(address.m_e_mail);
	pTextEdit ->append(address.m_image );
	
}

void operator<<(QVector<QString> &vecstring, const Address &address)
{
	vecstring.push_back(address.getname  ());
	vecstring.push_back(address.gete_mail());
	vecstring.push_back(address.getimage ());
}

void operator<<(QListWidget *pListAddress, const Address &address) // вывод адреса в ListWidget
{
	QPixmap pix(Address::PATH + address.getimage());
	QIcon   icon(pix);
	QListWidgetItem *itemAddress = new QListWidgetItem(icon, address.getname(), pListAddress);
}

QTextStream& operator>>(QTextStream &in, Address &address) // чтение адреса из потока
{
	
	address.m_name   = in.readLine();
	address.m_e_mail = in.readLine();
	address.m_image  = in.readLine();
	
	return in;
}

void Address::setname  (QString str) { m_name   = str; };
void Address::sete_mail(QString str) { m_e_mail = str; };
void Address::setimage (QString str) { m_image  = str; };

QString Address::getname  () const { return m_name;   };
QString Address::gete_mail() const { return m_e_mail; };
QString Address::getimage () const { return m_image;  };

	