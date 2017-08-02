#ifndef _DATA_H_
#define _DATA_H_
#include <qglobal.h>
#include <qstring.h>
#include <qvector.h>

enum OK {OK220 = 220, OK221 = 221, OK235 = 235, OK250 = 250, OK334 = 334,  OK354 = 354};

extern uint OK_code[10];
extern QString arrCommandsSMTP[8];
extern QString arrCommandsPOP_AUTH_LOGIN[7];
extern QString arrCommandsPOP_USER[7];
extern QVector <QString> vectorCommands;

struct Info
{
	//QString strInfo;
	//QString strSound;
	const char* strInfo;
	const char* strSound;
};

enum INFO { SEND_DONE, SEND_ERROR, REC_DONE, REC_ERROR, REC_INFO };

extern Info arrInfo[5];
				 
extern const char* arrError[8];
					  
enum HEADER {DATE, FROM, TO, SUBJECT};

extern QString arrHEADER[4];

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

extern QString arrMIME[34]; 
                       
#endif