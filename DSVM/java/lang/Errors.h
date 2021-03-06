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


#ifndef _JAVA_LANG_ERROR_H_
#define _JAVA_LANG_ERROR_H_
#ifdef __cplusplus
extern "C" {
#endif


#include "Throwable.h"


extern clsDefinition clsJAVA_LANG_ABSTRACTMETHODERROR;
extern clsDefinition clsJAVA_LANG_CLASSCIRCULARITYERROR;
extern clsDefinition clsJAVA_LANG_CLASSFORMATERROR;
extern clsDefinition clsJAVA_LANG_ERROR;
extern clsDefinition clsJAVA_LANG_EXCEPTIONININITIALIZERERROR;
extern clsDefinition clsJAVA_LANG_INCOMPATIBLECLASSCHANGEERROR;
extern clsDefinition clsJAVA_LANG_INSTANTIATIONERROR;
extern clsDefinition clsJAVA_LANG_LINKAGEERROR;
extern clsDefinition clsJAVA_LANG_NOCLASSDEFFOUNDERROR;
extern clsDefinition clsJAVA_LANG_NOSUCHFIELDERROR;
extern clsDefinition clsJAVA_LANG_NOSUCHMETHODERROR;
extern clsDefinition clsJAVA_LANG_OUTOFMEMORYERROR;
extern clsDefinition clsJAVA_LANG_STACKOVERFLOWERROR;
extern clsDefinition clsJAVA_LANG_UNKNOWNERROR;
extern clsDefinition clsJAVA_LANG_UNSATISFIEDLINKERROR;
extern clsDefinition clsJAVA_LANG_UNSUPPORTEDCLASSVERSIONERROR;
extern clsDefinition clsJAVA_LANG_VIRTUALMACHINEERROR;


#ifdef __cplusplus
}
#endif
#endif	/* NOT _JAVA_LANG_ERROR_H_ */
