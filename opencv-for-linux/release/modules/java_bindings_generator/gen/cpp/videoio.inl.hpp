//
// This file is auto-generated. Please don't modify it!
//

#undef LOG_TAG

#include "opencv2/opencv_modules.hpp"
#ifdef HAVE_OPENCV_VIDEOIO

#include <string>

#include "opencv2/videoio.hpp"

#include "/Users/virtualman/Downloads/MySource/opencv-4.3.0/modules/videoio/include/opencv2/videoio.hpp"
#include "/Users/virtualman/Downloads/MySource/opencv-4.3.0/modules/videoio/include/opencv2/videoio/registry.hpp"

#define LOG_TAG "org.opencv.videoio"
#include "common.h"

using namespace cv;

/// throw java exception
#undef throwJavaException
#define throwJavaException throwJavaException_videoio
static void throwJavaException(JNIEnv *env, const std::exception *e, const char *method) {
  std::string what = "unknown exception";
  jclass je = 0;

  if(e) {
    std::string exception_type = "std::exception";

    if(dynamic_cast<const cv::Exception*>(e)) {
      exception_type = "cv::Exception";
      je = env->FindClass("org/opencv/core/CvException");
    }

    what = exception_type + ": " + e->what();
  }

  if(!je) je = env->FindClass("java/lang/Exception");
  env->ThrowNew(je, what.c_str());

  LOGE("%s caught %s", method, what.c_str());
  (void)method;        // avoid "unused" warning
}

extern "C" {


//
//   cv::VideoWriter::VideoWriter(String filename, int apiPreference, int fourcc, double fps, Size frameSize, bool isColor = true)
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_videoio_VideoWriter_VideoWriter_10 (JNIEnv*, jclass, jstring, jint, jint, jdouble, jdouble, jdouble, jboolean);

JNIEXPORT jlong JNICALL Java_org_opencv_videoio_VideoWriter_VideoWriter_10
  (JNIEnv* env, jclass , jstring filename, jint apiPreference, jint fourcc, jdouble fps, jdouble frameSize_width, jdouble frameSize_height, jboolean isColor)
{
    static const char method_name[] = "videoio::VideoWriter_10()";
    try {
        LOGD("%s", method_name);
        const char* utf_filename = env->GetStringUTFChars(filename, 0); String n_filename( utf_filename ? utf_filename : "" ); env->ReleaseStringUTFChars(filename, utf_filename);
        Size frameSize((int)frameSize_width, (int)frameSize_height);
        cv::VideoWriter* _retval_ = new cv::VideoWriter( n_filename, (int)apiPreference, (int)fourcc, (double)fps, frameSize, (bool)isColor );
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_videoio_VideoWriter_VideoWriter_11 (JNIEnv*, jclass, jstring, jint, jint, jdouble, jdouble, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_videoio_VideoWriter_VideoWriter_11
  (JNIEnv* env, jclass , jstring filename, jint apiPreference, jint fourcc, jdouble fps, jdouble frameSize_width, jdouble frameSize_height)
{
    static const char method_name[] = "videoio::VideoWriter_11()";
    try {
        LOGD("%s", method_name);
        const char* utf_filename = env->GetStringUTFChars(filename, 0); String n_filename( utf_filename ? utf_filename : "" ); env->ReleaseStringUTFChars(filename, utf_filename);
        Size frameSize((int)frameSize_width, (int)frameSize_height);
        cv::VideoWriter* _retval_ = new cv::VideoWriter( n_filename, (int)apiPreference, (int)fourcc, (double)fps, frameSize );
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//   cv::VideoWriter::VideoWriter(String filename, int fourcc, double fps, Size frameSize, bool isColor = true)
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_videoio_VideoWriter_VideoWriter_12 (JNIEnv*, jclass, jstring, jint, jdouble, jdouble, jdouble, jboolean);

JNIEXPORT jlong JNICALL Java_org_opencv_videoio_VideoWriter_VideoWriter_12
  (JNIEnv* env, jclass , jstring filename, jint fourcc, jdouble fps, jdouble frameSize_width, jdouble frameSize_height, jboolean isColor)
{
    static const char method_name[] = "videoio::VideoWriter_12()";
    try {
        LOGD("%s", method_name);
        const char* utf_filename = env->GetStringUTFChars(filename, 0); String n_filename( utf_filename ? utf_filename : "" ); env->ReleaseStringUTFChars(filename, utf_filename);
        Size frameSize((int)frameSize_width, (int)frameSize_height);
        cv::VideoWriter* _retval_ = new cv::VideoWriter( n_filename, (int)fourcc, (double)fps, frameSize, (bool)isColor );
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_videoio_VideoWriter_VideoWriter_13 (JNIEnv*, jclass, jstring, jint, jdouble, jdouble, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_videoio_VideoWriter_VideoWriter_13
  (JNIEnv* env, jclass , jstring filename, jint fourcc, jdouble fps, jdouble frameSize_width, jdouble frameSize_height)
{
    static const char method_name[] = "videoio::VideoWriter_13()";
    try {
        LOGD("%s", method_name);
        const char* utf_filename = env->GetStringUTFChars(filename, 0); String n_filename( utf_filename ? utf_filename : "" ); env->ReleaseStringUTFChars(filename, utf_filename);
        Size frameSize((int)frameSize_width, (int)frameSize_height);
        cv::VideoWriter* _retval_ = new cv::VideoWriter( n_filename, (int)fourcc, (double)fps, frameSize );
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//   cv::VideoWriter::VideoWriter()
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_videoio_VideoWriter_VideoWriter_14 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_videoio_VideoWriter_VideoWriter_14
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "videoio::VideoWriter_14()";
    try {
        LOGD("%s", method_name);
        cv::VideoWriter* _retval_ = new cv::VideoWriter();
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  String cv::VideoWriter::getBackendName()
//

using namespace cv;

JNIEXPORT jstring JNICALL Java_org_opencv_videoio_VideoWriter_getBackendName_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jstring JNICALL Java_org_opencv_videoio_VideoWriter_getBackendName_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "videoio::getBackendName_10()";
    try {
        LOGD("%s", method_name);
        cv::VideoWriter* me = (cv::VideoWriter*) self; //TODO: check for NULL
        cv::String _retval_ = me->getBackendName();
        return env->NewStringUTF(_retval_.c_str());
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return env->NewStringUTF("");
}



//
//  bool cv::VideoWriter::isOpened()
//

using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_videoio_VideoWriter_isOpened_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_videoio_VideoWriter_isOpened_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "videoio::isOpened_10()";
    try {
        LOGD("%s", method_name);
        cv::VideoWriter* me = (cv::VideoWriter*) self; //TODO: check for NULL
        return me->isOpened();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  bool cv::VideoWriter::open(String filename, int apiPreference, int fourcc, double fps, Size frameSize, bool isColor = true)
//

using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_videoio_VideoWriter_open_10 (JNIEnv*, jclass, jlong, jstring, jint, jint, jdouble, jdouble, jdouble, jboolean);

JNIEXPORT jboolean JNICALL Java_org_opencv_videoio_VideoWriter_open_10
  (JNIEnv* env, jclass , jlong self, jstring filename, jint apiPreference, jint fourcc, jdouble fps, jdouble frameSize_width, jdouble frameSize_height, jboolean isColor)
{
    static const char method_name[] = "videoio::open_10()";
    try {
        LOGD("%s", method_name);
        cv::VideoWriter* me = (cv::VideoWriter*) self; //TODO: check for NULL
        const char* utf_filename = env->GetStringUTFChars(filename, 0); String n_filename( utf_filename ? utf_filename : "" ); env->ReleaseStringUTFChars(filename, utf_filename);
        Size frameSize((int)frameSize_width, (int)frameSize_height);
        return me->open( n_filename, (int)apiPreference, (int)fourcc, (double)fps, frameSize, (bool)isColor );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_videoio_VideoWriter_open_11 (JNIEnv*, jclass, jlong, jstring, jint, jint, jdouble, jdouble, jdouble);

JNIEXPORT jboolean JNICALL Java_org_opencv_videoio_VideoWriter_open_11
  (JNIEnv* env, jclass , jlong self, jstring filename, jint apiPreference, jint fourcc, jdouble fps, jdouble frameSize_width, jdouble frameSize_height)
{
    static const char method_name[] = "videoio::open_11()";
    try {
        LOGD("%s", method_name);
        cv::VideoWriter* me = (cv::VideoWriter*) self; //TODO: check for NULL
        const char* utf_filename = env->GetStringUTFChars(filename, 0); String n_filename( utf_filename ? utf_filename : "" ); env->ReleaseStringUTFChars(filename, utf_filename);
        Size frameSize((int)frameSize_width, (int)frameSize_height);
        return me->open( n_filename, (int)apiPreference, (int)fourcc, (double)fps, frameSize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  bool cv::VideoWriter::open(String filename, int fourcc, double fps, Size frameSize, bool isColor = true)
//

using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_videoio_VideoWriter_open_12 (JNIEnv*, jclass, jlong, jstring, jint, jdouble, jdouble, jdouble, jboolean);

JNIEXPORT jboolean JNICALL Java_org_opencv_videoio_VideoWriter_open_12
  (JNIEnv* env, jclass , jlong self, jstring filename, jint fourcc, jdouble fps, jdouble frameSize_width, jdouble frameSize_height, jboolean isColor)
{
    static const char method_name[] = "videoio::open_12()";
    try {
        LOGD("%s", method_name);
        cv::VideoWriter* me = (cv::VideoWriter*) self; //TODO: check for NULL
        const char* utf_filename = env->GetStringUTFChars(filename, 0); String n_filename( utf_filename ? utf_filename : "" ); env->ReleaseStringUTFChars(filename, utf_filename);
        Size frameSize((int)frameSize_width, (int)frameSize_height);
        return me->open( n_filename, (int)fourcc, (double)fps, frameSize, (bool)isColor );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_videoio_VideoWriter_open_13 (JNIEnv*, jclass, jlong, jstring, jint, jdouble, jdouble, jdouble);

JNIEXPORT jboolean JNICALL Java_org_opencv_videoio_VideoWriter_open_13
  (JNIEnv* env, jclass , jlong self, jstring filename, jint fourcc, jdouble fps, jdouble frameSize_width, jdouble frameSize_height)
{
    static const char method_name[] = "videoio::open_13()";
    try {
        LOGD("%s", method_name);
        cv::VideoWriter* me = (cv::VideoWriter*) self; //TODO: check for NULL
        const char* utf_filename = env->GetStringUTFChars(filename, 0); String n_filename( utf_filename ? utf_filename : "" ); env->ReleaseStringUTFChars(filename, utf_filename);
        Size frameSize((int)frameSize_width, (int)frameSize_height);
        return me->open( n_filename, (int)fourcc, (double)fps, frameSize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  bool cv::VideoWriter::set(int propId, double value)
//

using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_videoio_VideoWriter_set_10 (JNIEnv*, jclass, jlong, jint, jdouble);

JNIEXPORT jboolean JNICALL Java_org_opencv_videoio_VideoWriter_set_10
  (JNIEnv* env, jclass , jlong self, jint propId, jdouble value)
{
    static const char method_name[] = "videoio::set_10()";
    try {
        LOGD("%s", method_name);
        cv::VideoWriter* me = (cv::VideoWriter*) self; //TODO: check for NULL
        return me->set( (int)propId, (double)value );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::VideoWriter::get(int propId)
//

using namespace cv;

JNIEXPORT jdouble JNICALL Java_org_opencv_videoio_VideoWriter_get_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT jdouble JNICALL Java_org_opencv_videoio_VideoWriter_get_10
  (JNIEnv* env, jclass , jlong self, jint propId)
{
    static const char method_name[] = "videoio::get_10()";
    try {
        LOGD("%s", method_name);
        cv::VideoWriter* me = (cv::VideoWriter*) self; //TODO: check for NULL
        return me->get( (int)propId );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// static int cv::VideoWriter::fourcc(char c1, char c2, char c3, char c4)
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_videoio_VideoWriter_fourcc_10 (JNIEnv*, jclass, jchar, jchar, jchar, jchar);

JNIEXPORT jint JNICALL Java_org_opencv_videoio_VideoWriter_fourcc_10
  (JNIEnv* env, jclass , jchar c1, jchar c2, jchar c3, jchar c4)
{
    static const char method_name[] = "videoio::fourcc_10()";
    try {
        LOGD("%s", method_name);
        return cv::VideoWriter::fourcc( (char)c1, (char)c2, (char)c3, (char)c4 );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::VideoWriter::release()
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_videoio_VideoWriter_release_10 (JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_videoio_VideoWriter_release_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "videoio::release_10()";
    try {
        LOGD("%s", method_name);
        cv::VideoWriter* me = (cv::VideoWriter*) self; //TODO: check for NULL
        me->release();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::VideoWriter::write(Mat image)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_videoio_VideoWriter_write_10 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_videoio_VideoWriter_write_10
  (JNIEnv* env, jclass , jlong self, jlong image_nativeObj)
{
    static const char method_name[] = "videoio::write_10()";
    try {
        LOGD("%s", method_name);
        cv::VideoWriter* me = (cv::VideoWriter*) self; //TODO: check for NULL
        Mat& image = *((Mat*)image_nativeObj);
        me->write( image );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void cv::VideoWriter::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_videoio_VideoWriter_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_videoio_VideoWriter_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (cv::VideoWriter*) self;
}


//
//  String cv::videoio_registry::getBackendName(VideoCaptureAPIs api)
//



JNIEXPORT jstring JNICALL Java_org_opencv_videoio_Videoio_getBackendName_10 (JNIEnv*, jclass, jint);

JNIEXPORT jstring JNICALL Java_org_opencv_videoio_Videoio_getBackendName_10
  (JNIEnv* env, jclass , jint api)
{
    static const char method_name[] = "videoio::getBackendName_10()";
    try {
        LOGD("%s", method_name);
        cv::String _retval_ = cv::videoio_registry::getBackendName( (cv::VideoCaptureAPIs)api );
        return env->NewStringUTF(_retval_.c_str());
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return env->NewStringUTF("");
}



//
//   cv::VideoCapture::VideoCapture()
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_videoio_VideoCapture_VideoCapture_10 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_videoio_VideoCapture_VideoCapture_10
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "videoio::VideoCapture_10()";
    try {
        LOGD("%s", method_name);
        cv::VideoCapture* _retval_ = new cv::VideoCapture();
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  String cv::VideoCapture::getBackendName()
//

using namespace cv;

JNIEXPORT jstring JNICALL Java_org_opencv_videoio_VideoCapture_getBackendName_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jstring JNICALL Java_org_opencv_videoio_VideoCapture_getBackendName_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "videoio::getBackendName_10()";
    try {
        LOGD("%s", method_name);
        cv::VideoCapture* me = (cv::VideoCapture*) self; //TODO: check for NULL
        cv::String _retval_ = me->getBackendName();
        return env->NewStringUTF(_retval_.c_str());
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return env->NewStringUTF("");
}



//
//  bool cv::VideoCapture::getExceptionMode()
//

using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_videoio_VideoCapture_getExceptionMode_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_videoio_VideoCapture_getExceptionMode_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "videoio::getExceptionMode_10()";
    try {
        LOGD("%s", method_name);
        cv::VideoCapture* me = (cv::VideoCapture*) self; //TODO: check for NULL
        return me->getExceptionMode();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  bool cv::VideoCapture::grab()
//

using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_videoio_VideoCapture_grab_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_videoio_VideoCapture_grab_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "videoio::grab_10()";
    try {
        LOGD("%s", method_name);
        cv::VideoCapture* me = (cv::VideoCapture*) self; //TODO: check for NULL
        return me->grab();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  bool cv::VideoCapture::isOpened()
//

using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_videoio_VideoCapture_isOpened_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_videoio_VideoCapture_isOpened_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "videoio::isOpened_10()";
    try {
        LOGD("%s", method_name);
        cv::VideoCapture* me = (cv::VideoCapture*) self; //TODO: check for NULL
        return me->isOpened();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  bool cv::VideoCapture::open(String filename, int apiPreference = CAP_ANY)
//

using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_videoio_VideoCapture_open_10 (JNIEnv*, jclass, jlong, jstring, jint);

JNIEXPORT jboolean JNICALL Java_org_opencv_videoio_VideoCapture_open_10
  (JNIEnv* env, jclass , jlong self, jstring filename, jint apiPreference)
{
    static const char method_name[] = "videoio::open_10()";
    try {
        LOGD("%s", method_name);
        cv::VideoCapture* me = (cv::VideoCapture*) self; //TODO: check for NULL
        const char* utf_filename = env->GetStringUTFChars(filename, 0); String n_filename( utf_filename ? utf_filename : "" ); env->ReleaseStringUTFChars(filename, utf_filename);
        return me->open( n_filename, (int)apiPreference );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_videoio_VideoCapture_open_11 (JNIEnv*, jclass, jlong, jstring);

JNIEXPORT jboolean JNICALL Java_org_opencv_videoio_VideoCapture_open_11
  (JNIEnv* env, jclass , jlong self, jstring filename)
{
    static const char method_name[] = "videoio::open_11()";
    try {
        LOGD("%s", method_name);
        cv::VideoCapture* me = (cv::VideoCapture*) self; //TODO: check for NULL
        const char* utf_filename = env->GetStringUTFChars(filename, 0); String n_filename( utf_filename ? utf_filename : "" ); env->ReleaseStringUTFChars(filename, utf_filename);
        return me->open( n_filename );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  bool cv::VideoCapture::open(int index, int apiPreference = CAP_ANY)
//

using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_videoio_VideoCapture_open_12 (JNIEnv*, jclass, jlong, jint, jint);

JNIEXPORT jboolean JNICALL Java_org_opencv_videoio_VideoCapture_open_12
  (JNIEnv* env, jclass , jlong self, jint index, jint apiPreference)
{
    static const char method_name[] = "videoio::open_12()";
    try {
        LOGD("%s", method_name);
        cv::VideoCapture* me = (cv::VideoCapture*) self; //TODO: check for NULL
        return me->open( (int)index, (int)apiPreference );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_videoio_VideoCapture_open_13 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT jboolean JNICALL Java_org_opencv_videoio_VideoCapture_open_13
  (JNIEnv* env, jclass , jlong self, jint index)
{
    static const char method_name[] = "videoio::open_13()";
    try {
        LOGD("%s", method_name);
        cv::VideoCapture* me = (cv::VideoCapture*) self; //TODO: check for NULL
        return me->open( (int)index );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  bool cv::VideoCapture::read(Mat& image)
//

using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_videoio_VideoCapture_read_10 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_videoio_VideoCapture_read_10
  (JNIEnv* env, jclass , jlong self, jlong image_nativeObj)
{
    static const char method_name[] = "videoio::read_10()";
    try {
        LOGD("%s", method_name);
        cv::VideoCapture* me = (cv::VideoCapture*) self; //TODO: check for NULL
        Mat& image = *((Mat*)image_nativeObj);
        return me->read( image );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  bool cv::VideoCapture::retrieve(Mat& image, int flag = 0)
//

using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_videoio_VideoCapture_retrieve_10 (JNIEnv*, jclass, jlong, jlong, jint);

JNIEXPORT jboolean JNICALL Java_org_opencv_videoio_VideoCapture_retrieve_10
  (JNIEnv* env, jclass , jlong self, jlong image_nativeObj, jint flag)
{
    static const char method_name[] = "videoio::retrieve_10()";
    try {
        LOGD("%s", method_name);
        cv::VideoCapture* me = (cv::VideoCapture*) self; //TODO: check for NULL
        Mat& image = *((Mat*)image_nativeObj);
        return me->retrieve( image, (int)flag );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_videoio_VideoCapture_retrieve_11 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_videoio_VideoCapture_retrieve_11
  (JNIEnv* env, jclass , jlong self, jlong image_nativeObj)
{
    static const char method_name[] = "videoio::retrieve_11()";
    try {
        LOGD("%s", method_name);
        cv::VideoCapture* me = (cv::VideoCapture*) self; //TODO: check for NULL
        Mat& image = *((Mat*)image_nativeObj);
        return me->retrieve( image );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  bool cv::VideoCapture::set(int propId, double value)
//

using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_videoio_VideoCapture_set_10 (JNIEnv*, jclass, jlong, jint, jdouble);

JNIEXPORT jboolean JNICALL Java_org_opencv_videoio_VideoCapture_set_10
  (JNIEnv* env, jclass , jlong self, jint propId, jdouble value)
{
    static const char method_name[] = "videoio::set_10()";
    try {
        LOGD("%s", method_name);
        cv::VideoCapture* me = (cv::VideoCapture*) self; //TODO: check for NULL
        return me->set( (int)propId, (double)value );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::VideoCapture::get(int propId)
//

using namespace cv;

JNIEXPORT jdouble JNICALL Java_org_opencv_videoio_VideoCapture_get_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT jdouble JNICALL Java_org_opencv_videoio_VideoCapture_get_10
  (JNIEnv* env, jclass , jlong self, jint propId)
{
    static const char method_name[] = "videoio::get_10()";
    try {
        LOGD("%s", method_name);
        cv::VideoCapture* me = (cv::VideoCapture*) self; //TODO: check for NULL
        return me->get( (int)propId );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::VideoCapture::release()
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_videoio_VideoCapture_release_10 (JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_videoio_VideoCapture_release_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "videoio::release_10()";
    try {
        LOGD("%s", method_name);
        cv::VideoCapture* me = (cv::VideoCapture*) self; //TODO: check for NULL
        me->release();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::VideoCapture::setExceptionMode(bool enable)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_videoio_VideoCapture_setExceptionMode_10 (JNIEnv*, jclass, jlong, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_videoio_VideoCapture_setExceptionMode_10
  (JNIEnv* env, jclass , jlong self, jboolean enable)
{
    static const char method_name[] = "videoio::setExceptionMode_10()";
    try {
        LOGD("%s", method_name);
        cv::VideoCapture* me = (cv::VideoCapture*) self; //TODO: check for NULL
        me->setExceptionMode( (bool)enable );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void cv::VideoCapture::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_videoio_VideoCapture_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_videoio_VideoCapture_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (cv::VideoCapture*) self;
}



} // extern "C"

#endif // HAVE_OPENCV_VIDEOIO
