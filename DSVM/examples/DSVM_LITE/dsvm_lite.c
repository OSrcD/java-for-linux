/**************************************************************************
* Copyright (c) 2006-2007 Dusan Stastny. All rights reserved.             *
*                                                                         *
* This software is free software; you can redistribute it and/or modify   *
* it under the terms of the GNU General Public License version 2 as       *
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

/** @file
   The Java application launcher.
   This tool launches a Java application.
   <PRE>
   Using:   dsvm [options] class_file [arguments]

   Options:
       -classpath path      class path entries separated by path separators
       -cp path             class path entries separated by path separators
       -jar jar_file        .jar file
       -Dproperty=value     set a system property value
       -Xproperty=value     set a VM specific property value
       -help                this help
       -?                   this help

   Arguments:
       arguments passed to the main function
   </PRE>
   @author Dusan Stastny
*/

#include "config.h"
#include "java\lang\_all.h"

/** Maximal length of the classpath argument */
#define CLASSPATH_LIMIT 5120

/** Maximal number of the properties */
#define OPTIONS_LIMIT 32

#ifdef _DEBUG
	extern int AllocCnt; extern int AllocMaxCnt;
	extern int AllocObjectCnt; extern int AllocObjectMaxCnt;
	DWORD tick;
#endif


/**
   The program entry point.
   @param argc the count of arguments that follow in @a argv
   @param argv an array of strings representing command-line arguments entered by the user of the program
   @return the program exit code (0 on success)
*/
int main(int argc, char *argv[]) {
	int argStartIndex, printHelp, ret; jchar pombuf[1024];
	char *classname, classpath[CLASSPATH_LIMIT], *pcp, APP_NAME[1024];
	JavaVMOption options[OPTIONS_LIMIT]; 
	JavaVM *jvm; JNIEnv *env;
	jthrowable err;
	JavaVMInitArgs args;
	natPackageInfo hApp;

	/* get application name */
	hApp = GetModuleHandle(NULL);
	toUtf8(APP_NAME, vmGetPackageInfo(pombuf, sizeof(pombuf) / sizeof(jchar), &hApp, 1), -1);
	vmStrCatUTF(APP_NAME, " ");
	toUtf8(APP_NAME + vmStrLenUTF(APP_NAME), vmGetPackageInfo(pombuf, sizeof(pombuf) / sizeof(jchar), &hApp, 3), -1);
	pcp = APP_NAME;
	while (*pcp && (*pcp != '.')) pcp++; if (*pcp) pcp++;
	while (*pcp && (*pcp != '.')) pcp++; *pcp = 0;

	/* initialisation */
	argStartIndex = 1; printHelp = ret = 0;
	classname = NULL; 
	strcpy(classpath, "-Djava.class.path=");
	pcp = classpath + 18;

#ifdef _DEBUG
	tick = GetTickCount();
#endif

	/* initial VM configuration */
	args.version = JNI_VERSION_1_2;
	args.nOptions = 0;
	args.options = options;
	args.ignoreUnrecognized = JNI_TRUE;

	/* process program arguments */
	for (; argStartIndex < argc; argStartIndex++) {
		char *arg = argv[argStartIndex];
		if ((arg[0] == '-') || (arg[0] == '/')) {
			if (!strcmpi(arg + 1, "?")) { 
				printHelp = 1; 
				break; 
			} else
			if (!strcmpi(arg + 1, "help")) { 
				printHelp = 1; 
				break; 
			} else
			if (!strcmpi(arg + 1, "cp") || !strcmpi(arg + 1, "classpath")
#if JAVA_UTIL_ZIP_ENABLED
						|| !strcmpi(arg + 1, "jar")
#endif
					) {
				if (++argStartIndex >= argc) {
					vmDisplayError("Classpath entry expected\n\n", APP_NAME);
					printHelp = 1;
					break;
				}
				arg = argv[argStartIndex];
CP_ARG:			if ((strlen(classpath) + strlen(arg)) > (CLASSPATH_LIMIT - 20)) {
					vmDisplayError("Classpath limit exceeded\n\n", APP_NAME);
					return -8;
				}
				if (*pcp != 0)
					strcat(classpath, VM_PATH_SEPARATOR);
				strcat(classpath, arg);
			} else
			if ((arg[1] == 'D') || (arg[1] == 'X')) {
				if (arg[0] == '/')
					arg[0] = '-';
				if (!strncmp(arg, "-Djava.class.path=", 18)) {
					arg += 18;
					goto CP_ARG;
				}
				if (args.nOptions >= OPTIONS_LIMIT) {
					vmDisplayError("Properties limit exceeded\n\n", APP_NAME);
					printHelp = 1;
					break;
				}
				args.options[args.nOptions].optionString = arg;
				args.options[args.nOptions].extraInfo = NULL;
				args.nOptions++;
			} else {
				char buf[4096];
				vmSprintfUTF(buf, "Unknown option '%s'\n\n", arg);
				vmDisplayError(buf, APP_NAME);
				printHelp = 1;
				break;
			}
		} else
			if (classname == NULL) {
				classname = arg;
				argStartIndex++;
				break;
			}
	}
	if (*pcp != 0)
		if (args.nOptions >= OPTIONS_LIMIT) {
			vmDisplayError("Properties limit exceeded\n\n", APP_NAME);
			printHelp = 1;
		} else {
			args.options[args.nOptions].optionString = classpath;
			args.options[args.nOptions].extraInfo = NULL;
			args.nOptions++;
		}

	/* print help? */
	if (printHelp || (classname == NULL)) {
		char buf[8096], COPYRIGHT[512];
		toUtf8(COPYRIGHT, vmGetPackageInfo(pombuf, sizeof(pombuf) / sizeof(jchar), &hApp, 7), -1);
        vmSprintfUTF(buf, "%s, %s\n" \
			"This tool launches a Java application.\n\n" \
			"Using:   dsvm [options] class_file [arguments]\n\n" \
			"Options:\n" \
			"    -classpath path      class path entries separated by %s (%s)\n" \
			"    -cp path             class path entries separated by %s (%s)\n" \
			"%s" \
			"    -Dproperty=value     set a system property value\n" \
			"    -Xproperty=value     set a VM specific property value\n" \
			"    -help                this help\n\n" \
 			"Arguments:\n" \
			"    arguments passed to the main function\n\n", 
			APP_NAME,
			COPYRIGHT,
			vmStrCmpUTF(VM_PATH_SEPARATOR, ";") ? "colons" : "semicolons",
			VM_PATH_SEPARATOR,
			vmStrCmpUTF(VM_PATH_SEPARATOR, ";") ? "colons" : "semicolons",
			VM_PATH_SEPARATOR,
#if JAVA_UTIL_ZIP_ENABLED
			"    -jar jar_file        .jar file\n"
#else
			""
#endif
		);
		vmDisplayInfo(buf, APP_NAME);
		return -3;
	}

	/* load and initialize a JVM */
	if (JNI_OK == JNI_CreateJavaVM(&jvm, &env, &args)) {
		int i;
		jclass cls, strcls;
		jmethodID met;
		jarray arguments;
		err = (*env)->ExceptionOccurred(env);
		if (err != NULL) 
			goto FATAL_ERROR;

		/* create arguments array */
		strcls = (*env)->FindClass(env, "java/lang/String");
		arguments = (*env)->NewObjectArray(env, argc - argStartIndex, strcls, NULL);
		for (i = argStartIndex; i < argc; i++) {
			jstring arg = (*env)->NewStringUTF(env, argv[i]);
			(*env)->SetObjectArrayElement(env, arguments, i - argStartIndex, arg);
		}
		err = (*env)->ExceptionOccurred(env);
		if (err != NULL) 
			goto FATAL_ERROR;

		/* find class */
		cls = (*env)->FindClass(env, classname);
		err = (*env)->ExceptionOccurred(env);
		if (err != NULL) 
			goto FATAL_ERROR;
		if (cls == NULL) {
			vmDisplayError("Class not found\n\n", APP_NAME);
			return -5;
		}

		/* find class main method */
		met = (*env)->GetStaticMethodID(env, cls, "main", "([Ljava/lang/String;)V");
		err = (*env)->ExceptionOccurred(env);
		if (err != NULL) 
			goto FATAL_ERROR;
		if (met == NULL) {
			vmDisplayError("Method main(java.lang.String[]) not found\n\n", APP_NAME);
			return -6;
		}

		/* invoke class main method */
		(*env)->CallStaticVoidMethod(env, cls, met, arguments);

 		/* any exception? */
		err = (*env)->ExceptionOccurred(env);
FATAL_ERROR:
		if (err != NULL) {
			char *buf;
			buf = vmMemAlloc((vmJavaVM*)jvm, Java_java_lang_Throwable_toStackTrace_c(env, err, NULL, NULL) + 16);
			if (buf != NULL) {
				Java_java_lang_Throwable_toStackTrace_c(env, err, buf, NULL);
				vmStrCatUTF(buf, "\n\n");
				vmDisplayError(buf, APP_NAME);
				ret = vmStringHashFceUTF(err->clsdef->name, vmStrLenUTF(err->clsdef->name));
				_vmMemFree(buf);
			}
		}

		/* destroy JVM */
		if (JNI_OK != (*jvm)->DestroyJavaVM(jvm)) {
			vmDisplayError("JVM not destroyed\n\n", APP_NAME);
			ret = -9;
		}
	} else {
		vmDisplayError("JVM not created\n\n", APP_NAME);
		ret = -4;
	}
#ifdef _DEBUG
	{ char buf[4096]; int t = (GetTickCount() - tick);
	vmMemPrintUnalloc();
	vmSprintfUTF(buf, "AllocCnt=%d (TOTAL:%d), AllocObjectCnt=%d (TOTAL:%d)\nTime consumed: %d.%03d s\n", 
		AllocCnt, AllocMaxCnt, AllocObjectCnt, AllocObjectMaxCnt, t / 1000, t % 1000);
	vmDisplayError(buf, APP_NAME);
	}
#endif
	return ret;
}