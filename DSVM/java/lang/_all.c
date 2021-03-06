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


#include "_all.h"

void JNICALL Java_java_lang_ClassLoader_clinit(JNIEnv *env, jclass clazz);


void vmRegister_JavaLangPackage(vmJavaVM *vm, vmJNIEnv *env) {

	/* resolve low core classes */
	clsDefinition *clsOBJECT = &clsJAVA_LANG_OBJECT;
	clsDefinition *clsOBJECTARRAY = &clsJAVA_LANG_OBJECT_ARRAY;
	clsDefinition *clsCLASS = &clsJAVA_LANG_CLASS;
	clsDefinition *clsCLASSLOADER = &clsJAVA_LANG_CLASSLOADER;

	/* clone class definitions */
	clsOBJECT = vmCloneClassDefinition(env, clsOBJECT);
	clsOBJECTARRAY = vmCloneClassDefinition(env, clsOBJECTARRAY);
	clsOBJECTARRAY->super_class = clsOBJECT;
	clsCLASS = vmCloneClassDefinition(env, clsCLASS);
	clsCLASS->super_class = clsOBJECT;
	clsCLASSLOADER = vmCloneClassDefinition(env, clsCLASSLOADER);
	clsCLASSLOADER->super_class = clsOBJECT;

	clsOBJECT->access_flags |= ACC_RESOLVED | ACC_INITED;
	clsOBJECT->total_data_size = clsOBJECT->fields_data_size;
	clsOBJECT->finalizeID = vmGetInstanceMethod(clsOBJECT, "finalize", "()V", JNI_TRUE);
	clsOBJECTARRAY->access_flags |= ACC_RESOLVED | ACC_INITED;
	clsOBJECTARRAY->total_data_size = clsOBJECT->total_data_size + clsOBJECTARRAY->fields_data_size;
	clsOBJECTARRAY->finalizeID = vmGetInstanceMethod(clsOBJECTARRAY, "finalize", "()V", JNI_TRUE);
	clsCLASS->access_flags |= ACC_RESOLVED | ACC_INITED;
	clsCLASS->total_data_size = clsOBJECT->total_data_size + clsCLASS->fields_data_size;
	clsCLASS->finalizeID = vmGetInstanceMethod(clsCLASS, "finalize", "()V", JNI_TRUE);
	clsCLASSLOADER->access_flags |= ACC_RESOLVED | ACC_INITED;
	clsCLASSLOADER->total_data_size = clsOBJECT->total_data_size + clsCLASSLOADER->fields_data_size;
	clsCLASSLOADER->finalizeID = vmGetInstanceMethod(clsCLASSLOADER, "finalize", "()V", JNI_TRUE);
	vm->class_clsdef = clsCLASS;
	vm->array_clsdef = clsOBJECTARRAY;

	/* register low core classes */
	vmRegisterClass(vm, env, clsCLASS);
	Java_java_lang_ClassLoader_clinit((JNIEnv*)env, vmRegisterClass(vm, env, clsCLASSLOADER));	
	vmRegisterClass(vm, env, clsOBJECT);
	vmRegisterClass(vm, env, clsOBJECTARRAY);

	/* primitives */
	vmRegisterClass(vm, env, &clsVOID);
	vmRegisterClass(vm, env, &clsBOOLEAN);
	vmRegisterClass(vm, env, &clsBYTE);
	vmRegisterClass(vm, env, &clsCHAR);
	vmRegisterClass(vm, env, &clsSHORT);
	vmRegisterClass(vm, env, &clsINT);
	vmRegisterClass(vm, env, &clsLONG);
	vmRegisterClass(vm, env, &clsFLOAT);
	vmRegisterClass(vm, env, &clsDOUBLE);

	/* interfaces */
	vmRegisterClass(vm, env, &clsJAVA_IO_SERIALIZABLE);
	vmRegisterClass(vm, env, &clsJAVA_LANG_CHARSEQUENCE);
	vmRegisterClass(vm, env, &clsJAVA_LANG_CLONEABLE);
	vmRegisterClass(vm, env, &clsJAVA_LANG_COMPARABLE);
	vmRegisterClass(vm, env, &clsJAVA_LANG_RUNNABLE);
	vmRegisterClass(vm, env, &clsJAVA_LANG_STRING);
	vmRegisterClass(vm, env, &clsJAVA_LANG_THROWABLE);

	/* errors */
	vmRegisterClass(vm, env, &clsJAVA_LANG_ABSTRACTMETHODERROR);
	vmRegisterClass(vm, env, &clsJAVA_LANG_CLASSCIRCULARITYERROR);
	vmRegisterClass(vm, env, &clsJAVA_LANG_CLASSFORMATERROR);
	vmRegisterClass(vm, env, &clsJAVA_LANG_ERROR);
	vmRegisterClass(vm, env, &clsJAVA_LANG_EXCEPTIONININITIALIZERERROR);
	vmRegisterClass(vm, env, &clsJAVA_LANG_INCOMPATIBLECLASSCHANGEERROR);
	vmRegisterClass(vm, env, &clsJAVA_LANG_INSTANTIATIONERROR);
	vmRegisterClass(vm, env, &clsJAVA_LANG_LINKAGEERROR);
	vmRegisterClass(vm, env, &clsJAVA_LANG_NOCLASSDEFFOUNDERROR);
	vmRegisterClass(vm, env, &clsJAVA_LANG_NOSUCHFIELDERROR);
	vmRegisterClass(vm, env, &clsJAVA_LANG_NOSUCHMETHODERROR);
	vmRegisterClass(vm, env, &clsJAVA_LANG_OUTOFMEMORYERROR);
	vmRegisterClass(vm, env, &clsJAVA_LANG_UNKNOWNERROR);
	vmRegisterClass(vm, env, &clsJAVA_LANG_UNSATISFIEDLINKERROR);
	vmRegisterClass(vm, env, &clsJAVA_LANG_UNSUPPORTEDCLASSVERSIONERROR);
	vmRegisterClass(vm, env, &clsJAVA_LANG_VIRTUALMACHINEERROR);
	Java_java_lang_ClassLoader_resolveClass((JNIEnv*)env, NULL, vmRegisterClass(vm, env, &clsJAVA_LANG_STACKOVERFLOWERROR));

	/* exceptions */
	vmRegisterClass(vm, env, &clsJAVA_LANG_ARITHMETICEXCEPTION);
	vmRegisterClass(vm, env, &clsJAVA_LANG_ARRAYINDEXOUTOFBOUNDSEXCEPTION);
	vmRegisterClass(vm, env, &clsJAVA_LANG_ARRAYSTOREEXCEPTION);
	vmRegisterClass(vm, env, &clsJAVA_LANG_CLASSCASTEXCEPTION);
	vmRegisterClass(vm, env, &clsJAVA_LANG_CLASSNOTFOUNDEXCEPTION);
	vmRegisterClass(vm, env, &clsJAVA_LANG_CLONENOTSUPPORTEDEXCEPTION);
	vmRegisterClass(vm, env, &clsJAVA_LANG_EXCEPTION);
	vmRegisterClass(vm, env, &clsJAVA_LANG_ILLEGALACCESSEXCEPTION);
	vmRegisterClass(vm, env, &clsJAVA_LANG_ILLEGALARGUMENTEXCEPTION);
	vmRegisterClass(vm, env, &clsJAVA_LANG_ILLEGALMONITORSTATEEXCEPTION);
	vmRegisterClass(vm, env, &clsJAVA_LANG_ILLEGALSTATEEXCEPTION);
	vmRegisterClass(vm, env, &clsJAVA_LANG_ILLEGALTHREADSTATEEXCEPTION);
	vmRegisterClass(vm, env, &clsJAVA_LANG_INDEXOUTOFBOUNDSEXCEPTION);
	vmRegisterClass(vm, env, &clsJAVA_LANG_INSTANTIATIONEXCEPTION);
	vmRegisterClass(vm, env, &clsJAVA_LANG_INTERRUPTEDEXCEPTION);
	vmRegisterClass(vm, env, &clsJAVA_LANG_NEGATIVEARRAYSIZEEXCEPTION);
	vmRegisterClass(vm, env, &clsJAVA_LANG_NOSUCHFIELDEXCEPTION);
	vmRegisterClass(vm, env, &clsJAVA_LANG_NOSUCHMETHODEXCEPTION);
	vmRegisterClass(vm, env, &clsJAVA_LANG_NULLPOINTEREXCEPTION);
	vmRegisterClass(vm, env, &clsJAVA_LANG_NUMBERFORMATEXCEPTION);
	vmRegisterClass(vm, env, &clsJAVA_LANG_RUNTIMEEXCEPTION);
	vmRegisterClass(vm, env, &clsJAVA_LANG_SECURITYEXCEPTION);
	vmRegisterClass(vm, env, &clsJAVA_LANG_STRINGINDEXOUTOFBOUNDSEXCEPTION);
	vmRegisterClass(vm, env, &clsJAVA_LANG_UNSUPPORTEDOPERATIONEXCEPTION);

	/* classes */
#if JAVA_LANG_BOOLEAN_ENABLED
	vmRegisterClass(vm, env, &clsJAVA_LANG_BOOLEAN);
#endif	/* JAVA_LANG_BOOLEAN_ENABLED */
#if JAVA_LANG_BYTE_ENABLED
	vmRegisterClass(vm, env, &clsJAVA_LANG_BYTE);
#endif	/* JAVA_LANG_BYTE_ENABLED */
#if JAVA_LANG_DOUBLE_ENABLED
	vmRegisterClass(vm, env, &clsJAVA_LANG_DOUBLE);
#endif	/* JAVA_LANG_DOUBLE_ENABLED */
#if JAVA_LANG_CHARACTER_ENABLED
	vmRegisterClass(vm, env, &clsJAVA_LANG_CHARACTER);
#endif	/* JAVA_LANG_CHARACTER_ENABLED */
#if JAVA_LANG_FLOAT_ENABLED
	vmRegisterClass(vm, env, &clsJAVA_LANG_FLOAT);
#endif	/* JAVA_LANG_FLOAT_ENABLED */
#if JAVA_LANG_INTEGER_ENABLED
	vmRegisterClass(vm, env, &clsJAVA_LANG_INTEGER);
#endif	/* JAVA_LANG_INTEGER_ENABLED */
#if JAVA_LANG_LONG_ENABLED
	vmRegisterClass(vm, env, &clsJAVA_LANG_LONG);
#endif	/* JAVA_LANG_LONG_ENABLED */
#if JAVA_LANG_MATH_ENABLED
	vmRegisterClass(vm, env, &clsJAVA_LANG_MATH);
#endif	/* JAVA_LANG_MATH_ENABLED */
#if JAVA_LANG_SHORT_ENABLED
	vmRegisterClass(vm, env, &clsJAVA_LANG_SHORT);
#endif	/* JAVA_LANG_SHORT_ENABLED */
	vmRegisterClass(vm, env, &clsJAVA_LANG_STACKTRACEELEMENT);
	vmRegisterClass(vm, env, &clsJAVA_LANG_STRINGBUFFER);
#if JAVA_LANG_STRINGBUILDER_ENABLED
	vmRegisterClass(vm, env, &clsJAVA_LANG_STRINGBUILDER);
#endif  /* JAVA_LANG_STRINGBUILDER_ENABLED */
	vmRegisterClass(vm, env, &clsJAVA_LANG_SYSTEM);
	vmRegisterClass(vm, env, &clsJAVA_LANG_THREAD);
	vmRegisterClass(vm, env, &clsJAVA_LANG_VOID);

#ifndef DSVM_LITE
	vmRegisterClass(vm, env, &clsJAVA_LANG_RUNTIME);
	vmRegisterClass(vm, env, &clsJAVA_LANG_RUNTIMEPERMISSION);
	vmRegisterClass(vm, env, &clsJAVA_LANG_SECURITYMANAGER);
	vmRegisterClass(vm, env, &clsJAVA_LANG_NUMBER);
	vmRegisterClass(vm, env, &clsJAVA_LANG_PROCESS);
	vmRegisterClass(vm, env, &clsJAVA_LANG_THREADLOCAL);
#endif /* DSVM_LITE */
}
