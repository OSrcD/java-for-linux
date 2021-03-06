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


#ifndef _JAVA_IO_EXCEPTIONS_H_
#define _JAVA_IO_EXCEPTIONS_H_
#ifdef __cplusplus
extern "C" {
#endif


#include "..\lang\Exceptions.h"


extern clsDefinition clsJAVA_IO_CHARCONVERSIONEXCEPTION;
extern clsDefinition clsJAVA_IO_EOFEXCEPTION;
extern clsDefinition clsJAVA_IO_FILENOTFOUNDEXCEPTION;
extern clsDefinition clsJAVA_IO_INTERRUPTEDIOEXCEPTION;
extern clsDefinition clsJAVA_IO_INVALIDCLASSEXCEPTION;
extern clsDefinition clsJAVA_IO_INVALIDOBJECTEXCEPTION;
extern clsDefinition clsJAVA_IO_IOEXCEPTION;
extern clsDefinition clsJAVA_IO_NOTACTIVEEXCEPTION;
extern clsDefinition clsJAVA_IO_NOTSERIALIZABLEEXCEPTION;
extern clsDefinition clsJAVA_IO_OBJECTSTREAMEXCEPTION;
extern clsDefinition clsJAVA_IO_OPTIONALDATAEXCEPTION;
extern clsDefinition clsJAVA_IO_STREAMCORRUPTEDEXCEPTION;
extern clsDefinition clsJAVA_IO_SYNCFAILEDEXCEPTION;
extern clsDefinition clsJAVA_IO_UNSUPPORTEDENCODINGEXCEPTION;
extern clsDefinition clsJAVA_IO_UTFDATAFORMATEXCEPTION;
extern clsDefinition clsJAVA_IO_WRITEABORTEDEXCEPTION;


#ifdef __cplusplus
}
#endif
#endif	/* NOT _JAVA_IO_EXCEPTIONS_H_ */
