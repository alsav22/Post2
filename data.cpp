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

Info arrInfo[] = { {"Письмо успешно отправлено!"  , "sound/send_done.wav"  },
                   {"Ошибка при отправке письма!" , "sound/send_error.wav" },
                   {"У вас новая почта!"          , "sound/rec_done.wav"   },
                   {"Ошибка при получении писем!" , "sound/rec_error.wav"  },
                   {"Нет новых писем!" ,            "sound/rec_info2.wav"  } }; 
				 
const char* arrError[] =  {"\nОшибка приветствия сервера.",       "\nЗапрос на аутентификацию не прошёл.", 
                       "\nПроверьте логин или пароль.",       "\nПроверьте логин или пароль.",
			           "\nПроверьте Ящик.",                   "\nПроверьте Адрес.", 
				       "\nНеполадки в сети или на сервере.",  "\nНеполадки в сети или на сервере."};
					  
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