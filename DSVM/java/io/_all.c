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


#include "..\lang\Class.h"
#include "_all.h"


/* hidden classes */
extern clsDefinition clsJAVA_IO_FILE_DELETEONEXIT;


void vmRegister_JavaIoPackage(vmJavaVM *vm, vmJNIEnv *env) {

	/* exceptions */
	vmRegisterClass(vm, env, &clsJAVA_IO_CHARCONVERSIONEXCEPTION);
	vmRegisterClass(vm, env, &clsJAVA_IO_EOFEXCEPTION);
	vmRegisterClass(vm, env, &clsJAVA_IO_FILENOTFOUNDEXCEPTION);
	vmRegisterClass(vm, env, &clsJAVA_IO_INTERRUPTEDIOEXCEPTION);
	vmRegisterClass(vm, env, &clsJAVA_IO_INVALIDCLASSEXCEPTION);
	vmRegisterClass(vm, env, &clsJAVA_IO_INVALIDOBJECTEXCEPTION);
	vmRegisterClass(vm, env, &clsJAVA_IO_IOEXCEPTION);
	vmRegisterClass(vm, env, &clsJAVA_IO_NOTACTIVEEXCEPTION);
	vmRegisterClass(vm, env, &clsJAVA_IO_NOTSERIALIZABLEEXCEPTION);
	vmRegisterClass(vm, env, &clsJAVA_IO_OBJECTSTREAMEXCEPTION);
	vmRegisterClass(vm, env, &clsJAVA_IO_OPTIONALDATAEXCEPTION);
	vmRegisterClass(vm, env, &clsJAVA_IO_STREAMCORRUPTEDEXCEPTION);
	vmRegisterClass(vm, env, &clsJAVA_IO_SYNCFAILEDEXCEPTION);
	vmRegisterClass(vm, env, &clsJAVA_IO_UNSUPPORTEDENCODINGEXCEPTION);
	vmRegisterClass(vm, env, &clsJAVA_IO_UTFDATAFORMATEXCEPTION);
	vmRegisterClass(vm, env, &clsJAVA_IO_WRITEABORTEDEXCEPTION);

	/* interfaces */
#ifndef DSVM_LITE
	vmRegisterClass(vm, env, &clsJAVA_IO_DATAINPUT);
	vmRegisterClass(vm, env, &clsJAVA_IO_DATAOUTPUT);
	vmRegisterClass(vm, env, &clsJAVA_IO_EXTERNALIZABLE);
	vmRegisterClass(vm, env, &clsJAVA_IO_FILEFILTER);
	vmRegisterClass(vm, env, &clsJAVA_IO_FILENAMEFILTER);
	vmRegisterClass(vm, env, &clsJAVA_IO_OBJECTINPUT);
	vmRegisterClass(vm, env, &clsJAVA_IO_OBJECTINPUTVALIDATION);
	vmRegisterClass(vm, env, &clsJAVA_IO_OBJECTOUTPUT);
	vmRegisterClass(vm, env, &clsJAVA_IO_OBJECTSTREAMCONSTANTS);

	/* classes */
	vmRegisterClass(vm, env, &clsJAVA_IO_FILE);
	vmRegisterClass(vm, env, &clsJAVA_IO_FILEPERMISSION);
	vmRegisterClass(vm, env, &clsJAVA_IO_BUFFEREDINPUTSTREAM);
	vmRegisterClass(vm, env, &clsJAVA_IO_BUFFEREDOUTPUTSTREAM);
	vmRegisterClass(vm, env, &clsJAVA_IO_BUFFEREDREADER);
	vmRegisterClass(vm, env, &clsJAVA_IO_BUFFEREDWRITER);
	vmRegisterClass(vm, env, &clsJAVA_IO_BYTEARRAYINPUTSTREAM);
	vmRegisterClass(vm, env, &clsJAVA_IO_BYTEARRAYOUTPUTSTREAM);
	vmRegisterClass(vm, env, &clsJAVA_IO_CHARARRAYREADER);
	vmRegisterClass(vm, env, &clsJAVA_IO_CHARARRAYWRITER);
	vmRegisterClass(vm, env, &clsJAVA_IO_FILE_DELETEONEXIT);
	vmRegisterClass(vm, env, &clsJAVA_IO_FILEDESCRIPTOR);
	vmRegisterClass(vm, env, &clsJAVA_IO_FILEINPUTSTREAM);
	vmRegisterClass(vm, env, &clsJAVA_IO_FILEOUTPUTSTREAM);
	vmRegisterClass(vm, env, &clsJAVA_IO_FILEREADER);
	vmRegisterClass(vm, env, &clsJAVA_IO_FILEWRITER);
	vmRegisterClass(vm, env, &clsJAVA_IO_FILTERINPUTSTREAM);
	vmRegisterClass(vm, env, &clsJAVA_IO_FILTEROUTPUTSTREAM);
	vmRegisterClass(vm, env, &clsJAVA_IO_FILTERREADER);
	vmRegisterClass(vm, env, &clsJAVA_IO_FILTERWRITER);
	vmRegisterClass(vm, env, &clsJAVA_IO_INPUTSTREAM);
	vmRegisterClass(vm, env, &clsJAVA_IO_INPUTSTREAMREADER);
	vmRegisterClass(vm, env, &clsJAVA_IO_OBJECTINPUTSTREAM);
	vmRegisterClass(vm, env, &clsJAVA_IO_OBJECTOUTPUTSTREAM);
	vmRegisterClass(vm, env, &clsJAVA_IO_OBJECTSTREAMFIELD);
	vmRegisterClass(vm, env, &clsJAVA_IO_OUTPUTSTREAM);
	vmRegisterClass(vm, env, &clsJAVA_IO_OUTPUTSTREAMWRITER);
	vmRegisterClass(vm, env, &clsJAVA_IO_PRINTWRITER);
	vmRegisterClass(vm, env, &clsJAVA_IO_PUSHBACKREADER);
	vmRegisterClass(vm, env, &clsJAVA_IO_RANDOMACCESSFILE);
	vmRegisterClass(vm, env, &clsJAVA_IO_RANDOMACCESSFILE_INPUTSTREAM);
	vmRegisterClass(vm, env, &clsJAVA_IO_READER);
	vmRegisterClass(vm, env, &clsJAVA_IO_SERIALIZABLEPERMISSION);
	vmRegisterClass(vm, env, &clsJAVA_IO_WRITER);
#endif /* DSVM_LITE */
	vmRegisterClass(vm, env, &clsJAVA_IO_PRINTSTREAM);
}
