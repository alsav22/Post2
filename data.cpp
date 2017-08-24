#include "data.h"

extern const QString RN = "\r\n";
extern const QString N  = "\n";
extern const QString R  = "\r";
extern const QString S  = "#"; // строка-разделитель

extern const QString PATH_ACCOUNT    = "./Account/account.txt";
extern const QString PATH_ADDRESS    = "./Address/address.txt";
extern const QString PATH_SENDER     = "./Sender/sender.txt";
extern const QString PATH_RECEIVER   = "./Receiver/receiver.txt";
extern const QString PATH_ATTACHMENT = "./Attachment/";

QString *pPathAttachment = NULL;

QTextCodec *LocalCodec = QTextCodec::codecForName(QTextCodec::codecForLocale() ->name());

uint OK_code[] = {OK220, OK250, OK334, OK334, OK235, OK250, OK250, OK354, OK250, OK221};

QString arrCommandsSMTP[8] = {"EHLO ",       "AUTH LOGIN", "",      "",
                              "MAIL FROM: ", "RCPT TO: ",  "DATA",  "QUIT"};
                               

QString arrCommandsPOP_AUTH_LOGIN[7] = {"AUTH LOGIN", "",      "",
                                        "STAT",       "RETR ", "DELE ", 
										"QUIT" }; 
						           
QString arrCommandsPOP_USER      [7] = {"USER ", "PASS ",  "NOOP",
                                        "STAT",  "RETR ",  "DELE ", 
								        "QUIT"};
						                      
QVector <QString> vectorCommands;

QVector <Info> arrInfo;
				 
QVector <QString> arrError;
					  
QString  arrHEADER[] = {"Date: ", "From: ", "To: ", "Subject: "};

QString arrMIME[] = {"MIME",     "Content-Type: ", "Content-Transfer-Encoding: ", 
                     
					 "text/plain", "text/html",
					 
					 "multipart/alternative", "multipart/mixed", "multipart/parallel",  
					 "multipart/digest",      "multipart/report",
					 
					 "message/rfc822",        "message/partial", 
					 "message/External-body", "message/delivery-status",
					 
					 "image/jpeg", "image/gif",
					 
					 "audio/basic", "audio/mpeg", "video/mpeg", "video/x-msvideo",
					 
					 "application/octet-stream", "application/PostScript",
					 "application/msword",
                     
					 "base64",   "quoted-printable", "8bit", "7bit",
	                 "charset=", "boundary=", "US-Ascii", "Windows-1251",  "koi8-r", "UTF-8", "ISO-8859-1" };