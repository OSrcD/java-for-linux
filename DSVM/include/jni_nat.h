/**************************************************************************
* This file has been released into the public domain by:                  *
*             Dusan Stastny <info@developservice.cz>                      *
*                                                                         *
* This software is distributed in the hope that it will be useful, but    *
* WITHOUT ANY WARRANTY!                                                   *
**************************************************************************/

/** @file
   The Java Native Interface (JNI) platform specific definitions. 
   @author Dusan Stastny <info@developservice.cz>
*/

#ifndef _JNI_NAT_H
#define _JNI_NAT_H

#ifdef __cplusplus
extern "C" {
#endif


#define JNICALL          __stdcall
#define JNIIMPORT        __declspec(dllimport)
#define JNIEXPORT        __declspec(dllexport)


/* system specific primitive types */
typedef unsigned char jboolean;
typedef float  jfloat;
typedef double jdouble;
typedef char   jbyte;
typedef unsigned char jubyte;
#ifdef __GNUC__
	typedef int jshort __attribute__((__mode__(__HI__)));
	typedef int jint   __attribute__((__mode__(__SI__)));
	typedef int jlong  __attribute__((__mode__(__DI__)));
	typedef unsigned short jushort __attribute__((__mode__(__HI__)));
	typedef unsigned int juint     __attribute__((__mode__(__SI__)));
#else
	typedef __int16 jshort;
	typedef __int32 jint;
	typedef __int64 jlong;
	typedef unsigned __int16 jushort;
	typedef unsigned __int32 juint;
#endif
typedef jushort jchar;


/* vm specific structures */
typedef struct _jobject_struct _jobject;     /* kept as an incomplete type */
typedef struct _jobject_struct _jarray;      /* kept as an incomplete type */
typedef struct _jfieldID_struct _jfieldID;   /* kept as an incomplete type */
typedef struct _methodID_struct _jmethodID;  /* kept as an incomplete type */


/* other system specific definitions */
#define FASTCALL
#define JLONG(lc)           ((jlong)(lc))
#define _JSTRING_(tc)       L##tc
#define JSTRING(tc)         _JSTRING_(tc)


/* other system specific types */
typedef void*               vmMemHandle;
typedef void*               natEventData;
typedef unsigned long       natThreadID;
typedef void*               natThreadData;


#ifdef __cplusplus
}
#endif

#endif	/* NOT _JNI_NAT_H */
