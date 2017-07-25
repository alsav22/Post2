#ifndef _DATA_H_
#define _DATA_H_

class QString;
class Account;

enum OK {OK220 = 220, OK221 = 221, OK235 = 235, OK250 = 250, OK334 = 334,  OK354 = 354};

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

struct Info
{
	QString strInfo;
	QString strSound;
};

enum INFO { SEND_DONE, SEND_ERROR, REC_DONE, REC_ERROR, REC_INFO };

Info arrInfo[] = { {"Письмо успешно отправлено!"  , "sound/send_done.wav"  },
                   {"Ошибка при отправке письма!" , "sound/send_error.wav" },
                   {"У вас новая почта!"          , "sound/rec_done.wav"   },
                   {"Ошибка при получении писем!" , "sound/rec_error.wav"  },
                   {"Нет новых писем!" ,            "sound/rec_info2.wav"  } }; 
				 
QString arrError[] =  {"\nОшибка приветствия сервера.",       "\nЗапрос на аутентификацию не прошёл.", 
                       "\nПроверьте логин или пароль.",       "\nПроверьте логин или пароль.",
			           "\nПроверьте Ящик.",                   "\nПроверьте Адрес.", 
				       "\nНеполадки в сети или на сервере.",  "\nНеполадки в сети или на сервере."};
					  
enum HEADER {DATE, FROM, TO, SUBJECT};

QString  arrHEADER[] = {"Date: ", "From: ", "To: ", "Subject: "};

enum MIME { MIME,    CONTENT_TYPE, CONTENT_TRANSFER_ENCODING,
            
			TEXT_PLAIN, TEXT_HTML,
			MULTIPART_ALTERNATIVE, MULTIPART_MIXED, MULTIPART_PARALLEL, 
			MULTIPART_DIGEST,      MULTIPART_REPORT,
			MESSAGE_RFC822,        MESSAGE_PARTIAL, 
			MESSAGE_EXTERNAL_BODY, MESSAGE_DELIVERY_STATUS,
			IMAGE_JPEG, IMAGE_GIF,
			AUDIO_BASIC, AUDIO_MPEG, VIDEO_MPEG, VIDEO_MP3, 
			APPLICATION_OCTET_STREAM, APPLICATION_POSTSCRIPT,
			APPLICATION_MSWORD,
            
			BASE64,  QUOTED_PRINTABLE, _8BIT, _7BIT,
			CHARSET, BOUNDARY, US_ASCII, WINDOWS_1251, KOI8_R, UTF_8, ISO_8859_1 };

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
                       
#endif