/**************************************************************************
* Copyright (c) 2006-2007 Dusan Stastny. All rights reserved.             *
*                                                                         *
* This software is free software; you can redistribute it and/or modify   *
* it under the terms of the GNU General Public License Version 2 as       *
* published by the Free Software Foundation.                              *
*                                                                         *
* This software is distributed in the hope that it will be useful, but    *
* WITHOUT ANY WARRANTY; without even the implied warranty of              *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU        *
* General Public License for more details.                                *
*                                                                         *
* You should have received a copy of the GNU General Public License       *
* along with DS Virtual Machine; see the file COPYING. If not, write to   *
* the Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, *
* MA 02111-1307 USA.                                                      *
*                                                                         *
*   Dusan Stastny                                                         *
*   Jizni Svahy 804                  info@developservice.cz               *
*   330 27 Vejprnice                 http://www.developservice.cz         *
*   Czech Republic - EUROPE                                               *
**************************************************************************/


#ifndef _JAVA_LANG_EXCEPTIONS_H_
#define _JAVA_LANG_EXCEPTIONS_H_
#ifdef __cplusplus
extern "C" {
#endif


#include "Throwable.h"


extern clsDefinition clsJAVA_LANG_ARITHMETICEXCEPTION;
extern clsDefinition clsJAVA_LANG_ARRAYINDEXOUTOFBOUNDSEXCEPTION;
extern clsDefinition clsJAVA_LANG_ARRAYSTOREEXCEPTION;
extern clsDefinition clsJAVA_LANG_CLASSCASTEXCEPTION;
extern clsDefinition clsJAVA_LANG_CLASSNOTFOUNDEXCEPTION;
extern clsDefinition clsJAVA_LANG_CLONENOTSUPPORTEDEXCEPTION;
extern clsDefinition clsJAVA_LANG_EXCEPTION;
extern clsDefinition clsJAVA_LANG_ILLEGALACCESSEXCEPTION;
extern clsDefinition clsJAVA_LANG_ILLEGALARGUMENTEXCEPTION;
extern clsDefinition clsJAVA_LANG_ILLEGALMONITORSTATEEXCEPTION;
extern clsDefinition clsJAVA_LANG_ILLEGALSTATEEXCEPTION;
extern clsDefinition clsJAVA_LANG_ILLEGALTHREADSTATEEXCEPTION;
extern clsDefinition clsJAVA_LANG_INDEXOUTOFBOUNDSEXCEPTION;
extern clsDefinition clsJAVA_LANG_INSTANTIATIONEXCEPTION;
extern clsDefinition clsJAVA_LANG_INTERRUPTEDEXCEPTION;
extern clsDefinition clsJAVA_LANG_NEGATIVEARRAYSIZEEXCEPTION;
extern clsDefinition clsJAVA_LANG_NOSUCHFIELDEXCEPTION;
extern clsDefinition clsJAVA_LANG_NOSUCHMETHODEXCEPTION;
extern clsDefinition clsJAVA_LANG_NULLPOINTEREXCEPTION;
extern clsDefinition clsJAVA_LANG_NUMBERFORMATEXCEPTION;
extern clsDefinition clsJAVA_LANG_RUNTIMEEXCEPTION;
extern clsDefinition clsJAVA_LANG_SECURITYEXCEPTION;
extern clsDefinition clsJAVA_LANG_STRINGINDEXOUTOFBOUNDSEXCEPTION;
extern clsDefinition clsJAVA_LANG_UNSUPPORTEDOPERATIONEXCEPTION;


#ifdef __cplusplus
}
#endif
#endif	/* NOT _JAVA_LANG_EXCEPTIONS_H_ */
