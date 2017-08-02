#include "data.h"

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

Info arrInfo[] = { {"������ ������� ����������!"  , "sound/send_done.wav"  },
                   {"������ ��� �������� ������!" , "sound/send_error.wav" },
                   {"� ��� ����� �����!"          , "sound/rec_done.wav"   },
                   {"������ ��� ��������� �����!" , "sound/rec_error.wav"  },
                   {"��� ����� �����!" ,            "sound/rec_info2.wav"  } }; 
				 
const char* arrError[] =  {"\n������ ����������� �������.",       "\n������ �� �������������� �� ������.", 
                       "\n��������� ����� ��� ������.",       "\n��������� ����� ��� ������.",
			           "\n��������� ����.",                   "\n��������� �����.", 
				       "\n��������� � ���� ��� �� �������.",  "\n��������� � ���� ��� �� �������."};
					  
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