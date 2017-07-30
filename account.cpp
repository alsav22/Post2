#include "account.h"
#include <QtGui>

const QString base64_chars = 
             "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
             "abcdefghijklmnopqrstuvwxyz"
             "0123456789+/";

static inline bool is_base64(unsigned char c) 
{
  return (isalnum(c) || (c == '+') || (c == '/'));
}

// коструктор нигде не применяется?
Account::Account(QString name,     QString login, 
                 QString password, QString e_mail,
				 QString HostSMTP, QString HostPOP,
	             QString PortSMTP, QString PortPOP,
				 QString flagdele /*= "0"*/)    
{
	m_name           = name;
	m_login          = login;
	m_loginBase64    = QByteArray(login.toStdString().c_str()).toBase64();//base64_encode(login, login.size());
	m_password       = password;
	m_passwordBase64 = QByteArray(password.toStdString().c_str()).toBase64();//base64_encode(password, password.size());
	m_e_mail         = e_mail;
	m_HostSMTP       = HostSMTP;
	m_HostPOP        = HostPOP;
	m_PortSMTP       = PortSMTP;
	m_PortPOP        = PortPOP;
	m_flagdele       = flagdele;
}   

Account::Account()
{
	m_name           = "";
	m_login          = "";
	m_loginBase64    = "";
	m_password       = "";
	m_passwordBase64 = "";
	m_e_mail         = "";
	m_HostSMTP       = "";
	m_HostPOP        = "";
	m_PortSMTP       = "";
	m_PortPOP        = "";
	m_flagdele       = "0";
}

void Account::setname          (const QString str) { m_name           = str; }
void Account::setlogin         (const QString str) { m_login          = str; }
void Account::setloginBase64   (const QString str) { m_loginBase64    = str; }
void Account::setpassword      (const QString str) { m_password       = str; }
void Account::setpasswordBase64(const QString str) { m_passwordBase64 = str; }
void Account::sete_mail        (const QString str) { m_e_mail         = str; }
void Account::setHostSMTP      (const QString str) { m_HostSMTP       = str; }
void Account::setHostPOP       (const QString str) { m_HostPOP        = str; }
void Account::setPortSMTP      (const QString str) { m_PortSMTP       = str; }
void Account::setPortPOP       (const QString str) { m_PortPOP        = str; }
void Account::setflagdele      (const QString str) { m_flagdele       = str; }

QString Account::getname          () const { return m_name;           } 
QString Account::getlogin         () const { return m_login;          } 
QString Account::getloginBase64   () const { return m_loginBase64;    } 
QString Account::getpassword      () const { return m_password;       } 
QString Account::getpasswordBase64() const { return m_passwordBase64; }
QString Account::gete_mail        () const { return m_e_mail;         }
QString Account::getHostSMTP      () const { return m_HostSMTP;       }
QString Account::getHostPOP       () const { return m_HostPOP;        }
QString Account::getPortSMTP      () const { return m_PortSMTP;       }
QString Account::getPortPOP       () const { return m_PortPOP;        }
QString Account::getflagdele      () const { return m_flagdele;       }

Account& Account::operator=(const Account &account)
{
		m_name           = account.m_name;
		m_login          = account.m_login;
		m_loginBase64    = account.m_loginBase64;
		m_password       = account.m_password;
		m_passwordBase64 = account.m_passwordBase64;
		m_e_mail         = account.m_e_mail;
		m_HostSMTP       = account.m_HostSMTP;
		m_HostPOP        = account.m_HostPOP;
		m_PortSMTP       = account.m_PortSMTP;
		m_PortPOP        = account.m_PortPOP;
		m_flagdele       = account.m_flagdele;
		
		return *this;
} 


QTextStream& operator<<(QTextStream &out, const Account &account)
{
	out << account.m_name           << N
		<< account.m_login          << N
		<< account.m_loginBase64    << N
		<< encodePassword(account.m_password)       << N
		<< encodePassword(account.m_passwordBase64) << N
		<< account.m_e_mail         << N
		<< account.m_HostSMTP       << N
		<< account.m_HostPOP        << N
		<< account.m_PortSMTP       << N
		<< account.m_PortPOP        << N
		<< account.m_flagdele       << N;;

		return out;
}

QTextStream& operator>>(QTextStream &in,  Account &account)
{
	account.m_name           = in.readLine();         
	account.m_login          = in.readLine();        
	account.m_loginBase64    = in.readLine();  
	account.m_password       = decodePassword(in.readLine());    
	account.m_passwordBase64 = decodePassword(in.readLine());
	account.m_e_mail         = in.readLine();       
	account.m_HostSMTP       = in.readLine();     
	account.m_HostPOP        = in.readLine();      
	account.m_PortSMTP       = in.readLine();     
	account.m_PortPOP        = in.readLine();
	account.m_flagdele       = in.readLine();
	
	return in;  
}

//void operator<<(QTextEdit *pTextEdit, const Account &account)
//{
//	pTextEdit ->append(account.m_name          );
//	pTextEdit ->append(account.m_login         );
//	pTextEdit ->append(account.m_loginBase64   );
//	pTextEdit ->append(account.m_password      );
//	pTextEdit ->append(account.m_passwordBase64);
//	pTextEdit ->append(account.m_e_mail        );
//	pTextEdit ->append(account.m_HostSMTP      );
//	pTextEdit ->append(account.m_HostPOP       );
//	pTextEdit ->append(account.m_PortSMTP      );
//	pTextEdit ->append(account.m_PortPOP    + N);
//}

void operator<<(QVector <QString> &vectorStr, const Account &account)
{
	vectorStr.push_back(account.m_name);
	vectorStr.push_back(account.m_login);
	vectorStr.push_back(account.m_loginBase64);
	vectorStr.push_back(account.m_password);
	vectorStr.push_back(account.m_passwordBase64);
	vectorStr.push_back(account.m_e_mail);
	vectorStr.push_back(account.m_HostSMTP);
	vectorStr.push_back(account.m_HostPOP);
	vectorStr.push_back(account.m_PortSMTP);
	vectorStr.push_back(account.m_PortPOP);
	vectorStr.push_back(account.m_flagdele);
}

//----------------------------------------------------------------------------------

QString base64_encode(const QString bytes_to_encode, uint in_len/*, const QString base64chars*/) 
{
  QString ret;
  int i = 0;
  int j = 0;
  int n = 0;
  uchar char_array_3[3];
  uchar char_array_4[4];
 
  while (in_len--) 
  {
    char_array_3[i++] = bytes_to_encode.toStdString()[n++];
    if (i == 3) 
	{
      char_array_4[0] = ( char_array_3[0] & 0xfc) >> 2;
      char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
      char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
      char_array_4[3] =   char_array_3[2] & 0x3f;
 
      for(i = 0; (i < 4) ; i++)
        ret += base64_chars[char_array_4[i]];
      i = 0;
    }
  }
 
  if (i)
  {
    for(j = i; j < 3; j++)
      char_array_3[j] = '\0';
 
    char_array_4[0] = ( char_array_3[0] & 0xfc) >> 2;
    char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
    char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
    char_array_4[3] =   char_array_3[2] & 0x3f;
 
    for (j = 0; (j < i + 1); j++)
      ret += base64_chars[char_array_4[j]];
 
    while((i++ < 3))
      ret += '=';
 
  }
 
  return ret;
}

//................................................................. 

QString base64_decode(const QString &encoded_string/*, const QString base64chars*/) 
{
  int in_len = encoded_string.size();
  int i = 0;
  int j = 0;
  int in_ = 0;
  uchar char_array_4[4];
  uchar char_array_3[3];
  QString ret;
 
  while (in_len-- && ( encoded_string[in_] != '=') && is_base64(encoded_string.toStdString()[in_])) 
  {
    char_array_4[i++] = encoded_string.toStdString()[in_]; 
	in_++;
    if (i ==4) 
	{
      for (i = 0; i <4; i++)
        char_array_4[i] = base64_chars.toStdString().find(char_array_4[i]);
 
      char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
      char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
      char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];
 
      for (i = 0; (i < 3); i++)
        ret += char_array_3[i];
      i = 0;
    }
  }
 
  if (i) 
  {
    for (j = i; j <4; j++)
      char_array_4[j] = 0;
 
    for (j = 0; j <4; j++)
      char_array_4[j] = base64_chars.toStdString().find(char_array_4[j]);
 
    char_array_3[0] = ( char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
    char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
    char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];
 
    for (j = 0; (j < i - 1); j++) 
		ret += char_array_3[j];
  }
 
  return ret;
}

// кодирование пароля
QString encodePassword(QString password)
{
	for ( int i = 0; i < password.size(); i++ )
	{
		password[i].unicode() = password[i].unicode() + 2;
	}

 //qDebug() << "encodePassword = " << password;
	return password;
}

// декодирование пароля
QString decodePassword(QString password)
{
	for ( int i = 0; i < password.size(); i++ )
		password[i].unicode() = password[i].unicode() - 2;
	
 //qDebug() << "decodePassword = " << password;
	return password;
} 


