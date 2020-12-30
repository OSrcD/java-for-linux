//
// This file is auto-generated. Please don't modify it!
//

#undef LOG_TAG

#include "opencv2/opencv_modules.hpp"
#ifdef HAVE_OPENCV_CORE

#include <string>

#include "opencv2/core.hpp"

#include "/Users/virtualman/Downloads/MySource/opencv-4.3.0/modules/core/include/opencv2/core/base.hpp"
#include "/Users/virtualman/Downloads/MySource/opencv-4.3.0/modules/core/include/opencv2/core.hpp"
#include "/Users/virtualman/Downloads/MySource/opencv-4.3.0/modules/core/include/opencv2/core/utility.hpp"
#include "/Users/virtualman/Downloads/MySource/opencv-4.3.0/modules/core/misc/java/src/cpp/core_manual.hpp"

#define LOG_TAG "org.opencv.core"
#include "common.h"

using namespace cv;

/// throw java exception
#undef throwJavaException
#define throwJavaException throwJavaException_core
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
//  Scalar cv::mean(Mat src, Mat mask = Mat())
//



JNIEXPORT jdoubleArray JNICALL Java_org_opencv_core_Core_mean_10 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT jdoubleArray JNICALL Java_org_opencv_core_Core_mean_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong mask_nativeObj)
{
    static const char method_name[] = "core::mean_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        Scalar _retval_ = cv::mean( src, mask );
        jdoubleArray _da_retval_ = env->NewDoubleArray(4);  jdouble _tmp_retval_[4] = {(jdouble)_retval_.val[0], (jdouble)_retval_.val[1], (jdouble)_retval_.val[2], (jdouble)_retval_.val[3]}; env->SetDoubleArrayRegion(_da_retval_, 0, 4, _tmp_retval_);
        return _da_retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jdoubleArray JNICALL Java_org_opencv_core_Core_mean_11 (JNIEnv*, jclass, jlong);

JNIEXPORT jdoubleArray JNICALL Java_org_opencv_core_Core_mean_11
  (JNIEnv* env, jclass , jlong src_nativeObj)
{
    static const char method_name[] = "core::mean_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Scalar _retval_ = cv::mean( src );
        jdoubleArray _da_retval_ = env->NewDoubleArray(4);  jdouble _tmp_retval_[4] = {(jdouble)_retval_.val[0], (jdouble)_retval_.val[1], (jdouble)_retval_.val[2], (jdouble)_retval_.val[3]}; env->SetDoubleArrayRegion(_da_retval_, 0, 4, _tmp_retval_);
        return _da_retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Scalar cv::sum(Mat src)
//



JNIEXPORT jdoubleArray JNICALL Java_org_opencv_core_Core_sumElems_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jdoubleArray JNICALL Java_org_opencv_core_Core_sumElems_10
  (JNIEnv* env, jclass , jlong src_nativeObj)
{
    static const char method_name[] = "core::sumElems_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Scalar _retval_ = cv::sum( src );
        jdoubleArray _da_retval_ = env->NewDoubleArray(4);  jdouble _tmp_retval_[4] = {(jdouble)_retval_.val[0], (jdouble)_retval_.val[1], (jdouble)_retval_.val[2], (jdouble)_retval_.val[3]}; env->SetDoubleArrayRegion(_da_retval_, 0, 4, _tmp_retval_);
        return _da_retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Scalar cv::trace(Mat mtx)
//



JNIEXPORT jdoubleArray JNICALL Java_org_opencv_core_Core_trace_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jdoubleArray JNICALL Java_org_opencv_core_Core_trace_10
  (JNIEnv* env, jclass , jlong mtx_nativeObj)
{
    static const char method_name[] = "core::trace_10()";
    try {
        LOGD("%s", method_name);
        Mat& mtx = *((Mat*)mtx_nativeObj);
        Scalar _retval_ = cv::trace( mtx );
        jdoubleArray _da_retval_ = env->NewDoubleArray(4);  jdouble _tmp_retval_[4] = {(jdouble)_retval_.val[0], (jdouble)_retval_.val[1], (jdouble)_retval_.val[2], (jdouble)_retval_.val[3]}; env->SetDoubleArrayRegion(_da_retval_, 0, 4, _tmp_retval_);
        return _da_retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  String cv::getBuildInformation()
//



JNIEXPORT jstring JNICALL Java_org_opencv_core_Core_getBuildInformation_10 (JNIEnv*, jclass);

JNIEXPORT jstring JNICALL Java_org_opencv_core_Core_getBuildInformation_10
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "core::getBuildInformation_10()";
    try {
        LOGD("%s", method_name);
        cv::String _retval_ = cv::getBuildInformation();
        return env->NewStringUTF(_retval_.c_str());
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return env->NewStringUTF("");
}



//
//  String cv::getHardwareFeatureName(int feature)
//



JNIEXPORT jstring JNICALL Java_org_opencv_core_Core_getHardwareFeatureName_10 (JNIEnv*, jclass, jint);

JNIEXPORT jstring JNICALL Java_org_opencv_core_Core_getHardwareFeatureName_10
  (JNIEnv* env, jclass , jint feature)
{
    static const char method_name[] = "core::getHardwareFeatureName_10()";
    try {
        LOGD("%s", method_name);
        cv::String _retval_ = cv::getHardwareFeatureName( (int)feature );
        return env->NewStringUTF(_retval_.c_str());
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return env->NewStringUTF("");
}



//
//  String cv::getVersionString()
//



JNIEXPORT jstring JNICALL Java_org_opencv_core_Core_getVersionString_10 (JNIEnv*, jclass);

JNIEXPORT jstring JNICALL Java_org_opencv_core_Core_getVersionString_10
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "core::getVersionString_10()";
    try {
        LOGD("%s", method_name);
        cv::String _retval_ = cv::getVersionString();
        return env->NewStringUTF(_retval_.c_str());
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return env->NewStringUTF("");
}



//
//  String cv::ipp::getIppVersion()
//



JNIEXPORT jstring JNICALL Java_org_opencv_core_Core_getIppVersion_10 (JNIEnv*, jclass);

JNIEXPORT jstring JNICALL Java_org_opencv_core_Core_getIppVersion_10
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "core::getIppVersion_10()";
    try {
        LOGD("%s", method_name);
        cv::String _retval_ = cv::ipp::getIppVersion();
        return env->NewStringUTF(_retval_.c_str());
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return env->NewStringUTF("");
}



//
//  String cv::samples::findFile(String relative_path, bool required = true, bool silentMode = false)
//



JNIEXPORT jstring JNICALL Java_org_opencv_core_Core_findFile_10 (JNIEnv*, jclass, jstring, jboolean, jboolean);

JNIEXPORT jstring JNICALL Java_org_opencv_core_Core_findFile_10
  (JNIEnv* env, jclass , jstring relative_path, jboolean required, jboolean silentMode)
{
    static const char method_name[] = "core::findFile_10()";
    try {
        LOGD("%s", method_name);
        const char* utf_relative_path = env->GetStringUTFChars(relative_path, 0); String n_relative_path( utf_relative_path ? utf_relative_path : "" ); env->ReleaseStringUTFChars(relative_path, utf_relative_path);
        cv::String _retval_ = cv::samples::findFile( n_relative_path, (bool)required, (bool)silentMode );
        return env->NewStringUTF(_retval_.c_str());
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return env->NewStringUTF("");
}





JNIEXPORT jstring JNICALL Java_org_opencv_core_Core_findFile_11 (JNIEnv*, jclass, jstring, jboolean);

JNIEXPORT jstring JNICALL Java_org_opencv_core_Core_findFile_11
  (JNIEnv* env, jclass , jstring relative_path, jboolean required)
{
    static const char method_name[] = "core::findFile_11()";
    try {
        LOGD("%s", method_name);
        const char* utf_relative_path = env->GetStringUTFChars(relative_path, 0); String n_relative_path( utf_relative_path ? utf_relative_path : "" ); env->ReleaseStringUTFChars(relative_path, utf_relative_path);
        cv::String _retval_ = cv::samples::findFile( n_relative_path, (bool)required );
        return env->NewStringUTF(_retval_.c_str());
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return env->NewStringUTF("");
}





JNIEXPORT jstring JNICALL Java_org_opencv_core_Core_findFile_12 (JNIEnv*, jclass, jstring);

JNIEXPORT jstring JNICALL Java_org_opencv_core_Core_findFile_12
  (JNIEnv* env, jclass , jstring relative_path)
{
    static const char method_name[] = "core::findFile_12()";
    try {
        LOGD("%s", method_name);
        const char* utf_relative_path = env->GetStringUTFChars(relative_path, 0); String n_relative_path( utf_relative_path ? utf_relative_path : "" ); env->ReleaseStringUTFChars(relative_path, utf_relative_path);
        cv::String _retval_ = cv::samples::findFile( n_relative_path );
        return env->NewStringUTF(_retval_.c_str());
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return env->NewStringUTF("");
}



//
//  String cv::samples::findFileOrKeep(String relative_path, bool silentMode = false)
//



JNIEXPORT jstring JNICALL Java_org_opencv_core_Core_findFileOrKeep_10 (JNIEnv*, jclass, jstring, jboolean);

JNIEXPORT jstring JNICALL Java_org_opencv_core_Core_findFileOrKeep_10
  (JNIEnv* env, jclass , jstring relative_path, jboolean silentMode)
{
    static const char method_name[] = "core::findFileOrKeep_10()";
    try {
        LOGD("%s", method_name);
        const char* utf_relative_path = env->GetStringUTFChars(relative_path, 0); String n_relative_path( utf_relative_path ? utf_relative_path : "" ); env->ReleaseStringUTFChars(relative_path, utf_relative_path);
        cv::String _retval_ = cv::samples::findFileOrKeep( n_relative_path, (bool)silentMode );
        return env->NewStringUTF(_retval_.c_str());
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return env->NewStringUTF("");
}





JNIEXPORT jstring JNICALL Java_org_opencv_core_Core_findFileOrKeep_11 (JNIEnv*, jclass, jstring);

JNIEXPORT jstring JNICALL Java_org_opencv_core_Core_findFileOrKeep_11
  (JNIEnv* env, jclass , jstring relative_path)
{
    static const char method_name[] = "core::findFileOrKeep_11()";
    try {
        LOGD("%s", method_name);
        const char* utf_relative_path = env->GetStringUTFChars(relative_path, 0); String n_relative_path( utf_relative_path ? utf_relative_path : "" ); env->ReleaseStringUTFChars(relative_path, utf_relative_path);
        cv::String _retval_ = cv::samples::findFileOrKeep( n_relative_path );
        return env->NewStringUTF(_retval_.c_str());
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return env->NewStringUTF("");
}



//
//  bool cv::checkRange(Mat a, bool quiet = true,  _hidden_ * pos = 0, double minVal = -DBL_MAX, double maxVal = DBL_MAX)
//



JNIEXPORT jboolean JNICALL Java_org_opencv_core_Core_checkRange_10 (JNIEnv*, jclass, jlong, jboolean, jdouble, jdouble);

JNIEXPORT jboolean JNICALL Java_org_opencv_core_Core_checkRange_10
  (JNIEnv* env, jclass , jlong a_nativeObj, jboolean quiet, jdouble minVal, jdouble maxVal)
{
    static const char method_name[] = "core::checkRange_10()";
    try {
        LOGD("%s", method_name);
        Mat& a = *((Mat*)a_nativeObj);
        return cv::checkRange( a, (bool)quiet, 0, (double)minVal, (double)maxVal );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jboolean JNICALL Java_org_opencv_core_Core_checkRange_11 (JNIEnv*, jclass, jlong, jboolean, jdouble);

JNIEXPORT jboolean JNICALL Java_org_opencv_core_Core_checkRange_11
  (JNIEnv* env, jclass , jlong a_nativeObj, jboolean quiet, jdouble minVal)
{
    static const char method_name[] = "core::checkRange_11()";
    try {
        LOGD("%s", method_name);
        Mat& a = *((Mat*)a_nativeObj);
        return cv::checkRange( a, (bool)quiet, 0, (double)minVal );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jboolean JNICALL Java_org_opencv_core_Core_checkRange_12 (JNIEnv*, jclass, jlong, jboolean);

JNIEXPORT jboolean JNICALL Java_org_opencv_core_Core_checkRange_12
  (JNIEnv* env, jclass , jlong a_nativeObj, jboolean quiet)
{
    static const char method_name[] = "core::checkRange_12()";
    try {
        LOGD("%s", method_name);
        Mat& a = *((Mat*)a_nativeObj);
        return cv::checkRange( a, (bool)quiet, 0 );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jboolean JNICALL Java_org_opencv_core_Core_checkRange_14 (JNIEnv*, jclass, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_core_Core_checkRange_14
  (JNIEnv* env, jclass , jlong a_nativeObj)
{
    static const char method_name[] = "core::checkRange_14()";
    try {
        LOGD("%s", method_name);
        Mat& a = *((Mat*)a_nativeObj);
        return cv::checkRange( a );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  bool cv::eigen(Mat src, Mat& eigenvalues, Mat& eigenvectors = Mat())
//



JNIEXPORT jboolean JNICALL Java_org_opencv_core_Core_eigen_10 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_core_Core_eigen_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong eigenvalues_nativeObj, jlong eigenvectors_nativeObj)
{
    static const char method_name[] = "core::eigen_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& eigenvalues = *((Mat*)eigenvalues_nativeObj);
        Mat& eigenvectors = *((Mat*)eigenvectors_nativeObj);
        return cv::eigen( src, eigenvalues, eigenvectors );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jboolean JNICALL Java_org_opencv_core_Core_eigen_11 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_core_Core_eigen_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong eigenvalues_nativeObj)
{
    static const char method_name[] = "core::eigen_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& eigenvalues = *((Mat*)eigenvalues_nativeObj);
        return cv::eigen( src, eigenvalues );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  bool cv::solve(Mat src1, Mat src2, Mat& dst, int flags = DECOMP_LU)
//



JNIEXPORT jboolean JNICALL Java_org_opencv_core_Core_solve_10 (JNIEnv*, jclass, jlong, jlong, jlong, jint);

JNIEXPORT jboolean JNICALL Java_org_opencv_core_Core_solve_10
  (JNIEnv* env, jclass , jlong src1_nativeObj, jlong src2_nativeObj, jlong dst_nativeObj, jint flags)
{
    static const char method_name[] = "core::solve_10()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Mat& src2 = *((Mat*)src2_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        return cv::solve( src1, src2, dst, (int)flags );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jboolean JNICALL Java_org_opencv_core_Core_solve_11 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_core_Core_solve_11
  (JNIEnv* env, jclass , jlong src1_nativeObj, jlong src2_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "core::solve_11()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Mat& src2 = *((Mat*)src2_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        return cv::solve( src1, src2, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  bool cv::ipp::useIPP()
//



JNIEXPORT jboolean JNICALL Java_org_opencv_core_Core_useIPP_10 (JNIEnv*, jclass);

JNIEXPORT jboolean JNICALL Java_org_opencv_core_Core_useIPP_10
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "core::useIPP_10()";
    try {
        LOGD("%s", method_name);
        return cv::ipp::useIPP();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  bool cv::ipp::useIPP_NotExact()
//



JNIEXPORT jboolean JNICALL Java_org_opencv_core_Core_useIPP_1NotExact_10 (JNIEnv*, jclass);

JNIEXPORT jboolean JNICALL Java_org_opencv_core_Core_useIPP_1NotExact_10
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "core::useIPP_1NotExact_10()";
    try {
        LOGD("%s", method_name);
        return cv::ipp::useIPP_NotExact();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::Mahalanobis(Mat v1, Mat v2, Mat icovar)
//



JNIEXPORT jdouble JNICALL Java_org_opencv_core_Core_Mahalanobis_10 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_core_Core_Mahalanobis_10
  (JNIEnv* env, jclass , jlong v1_nativeObj, jlong v2_nativeObj, jlong icovar_nativeObj)
{
    static const char method_name[] = "core::Mahalanobis_10()";
    try {
        LOGD("%s", method_name);
        Mat& v1 = *((Mat*)v1_nativeObj);
        Mat& v2 = *((Mat*)v2_nativeObj);
        Mat& icovar = *((Mat*)icovar_nativeObj);
        return cv::Mahalanobis( v1, v2, icovar );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::PSNR(Mat src1, Mat src2, double R = 255.)
//



JNIEXPORT jdouble JNICALL Java_org_opencv_core_Core_PSNR_10 (JNIEnv*, jclass, jlong, jlong, jdouble);

JNIEXPORT jdouble JNICALL Java_org_opencv_core_Core_PSNR_10
  (JNIEnv* env, jclass , jlong src1_nativeObj, jlong src2_nativeObj, jdouble R)
{
    static const char method_name[] = "core::PSNR_10()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Mat& src2 = *((Mat*)src2_nativeObj);
        return cv::PSNR( src1, src2, (double)R );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jdouble JNICALL Java_org_opencv_core_Core_PSNR_11 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_core_Core_PSNR_11
  (JNIEnv* env, jclass , jlong src1_nativeObj, jlong src2_nativeObj)
{
    static const char method_name[] = "core::PSNR_11()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Mat& src2 = *((Mat*)src2_nativeObj);
        return cv::PSNR( src1, src2 );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::determinant(Mat mtx)
//



JNIEXPORT jdouble JNICALL Java_org_opencv_core_Core_determinant_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_core_Core_determinant_10
  (JNIEnv* env, jclass , jlong mtx_nativeObj)
{
    static const char method_name[] = "core::determinant_10()";
    try {
        LOGD("%s", method_name);
        Mat& mtx = *((Mat*)mtx_nativeObj);
        return cv::determinant( mtx );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::getTickFrequency()
//



JNIEXPORT jdouble JNICALL Java_org_opencv_core_Core_getTickFrequency_10 (JNIEnv*, jclass);

JNIEXPORT jdouble JNICALL Java_org_opencv_core_Core_getTickFrequency_10
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "core::getTickFrequency_10()";
    try {
        LOGD("%s", method_name);
        return cv::getTickFrequency();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::invert(Mat src, Mat& dst, int flags = DECOMP_LU)
//



JNIEXPORT jdouble JNICALL Java_org_opencv_core_Core_invert_10 (JNIEnv*, jclass, jlong, jlong, jint);

JNIEXPORT jdouble JNICALL Java_org_opencv_core_Core_invert_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint flags)
{
    static const char method_name[] = "core::invert_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        return cv::invert( src, dst, (int)flags );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jdouble JNICALL Java_org_opencv_core_Core_invert_11 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_core_Core_invert_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "core::invert_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        return cv::invert( src, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::kmeans(Mat data, int K, Mat& bestLabels, TermCriteria criteria, int attempts, int flags, Mat& centers = Mat())
//



JNIEXPORT jdouble JNICALL Java_org_opencv_core_Core_kmeans_10 (JNIEnv*, jclass, jlong, jint, jlong, jint, jint, jdouble, jint, jint, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_core_Core_kmeans_10
  (JNIEnv* env, jclass , jlong data_nativeObj, jint K, jlong bestLabels_nativeObj, jint criteria_type, jint criteria_maxCount, jdouble criteria_epsilon, jint attempts, jint flags, jlong centers_nativeObj)
{
    static const char method_name[] = "core::kmeans_10()";
    try {
        LOGD("%s", method_name);
        Mat& data = *((Mat*)data_nativeObj);
        Mat& bestLabels = *((Mat*)bestLabels_nativeObj);
        TermCriteria criteria(criteria_type, criteria_maxCount, criteria_epsilon);
        Mat& centers = *((Mat*)centers_nativeObj);
        return cv::kmeans( data, (int)K, bestLabels, criteria, (int)attempts, (int)flags, centers );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jdouble JNICALL Java_org_opencv_core_Core_kmeans_11 (JNIEnv*, jclass, jlong, jint, jlong, jint, jint, jdouble, jint, jint);

JNIEXPORT jdouble JNICALL Java_org_opencv_core_Core_kmeans_11
  (JNIEnv* env, jclass , jlong data_nativeObj, jint K, jlong bestLabels_nativeObj, jint criteria_type, jint criteria_maxCount, jdouble criteria_epsilon, jint attempts, jint flags)
{
    static const char method_name[] = "core::kmeans_11()";
    try {
        LOGD("%s", method_name);
        Mat& data = *((Mat*)data_nativeObj);
        Mat& bestLabels = *((Mat*)bestLabels_nativeObj);
        TermCriteria criteria(criteria_type, criteria_maxCount, criteria_epsilon);
        return cv::kmeans( data, (int)K, bestLabels, criteria, (int)attempts, (int)flags );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::norm(Mat src1, Mat src2, int normType = NORM_L2, Mat mask = Mat())
//



JNIEXPORT jdouble JNICALL Java_org_opencv_core_Core_norm_10 (JNIEnv*, jclass, jlong, jlong, jint, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_core_Core_norm_10
  (JNIEnv* env, jclass , jlong src1_nativeObj, jlong src2_nativeObj, jint normType, jlong mask_nativeObj)
{
    static const char method_name[] = "core::norm_10()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Mat& src2 = *((Mat*)src2_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        return cv::norm( src1, src2, (int)normType, mask );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jdouble JNICALL Java_org_opencv_core_Core_norm_11 (JNIEnv*, jclass, jlong, jlong, jint);

JNIEXPORT jdouble JNICALL Java_org_opencv_core_Core_norm_11
  (JNIEnv* env, jclass , jlong src1_nativeObj, jlong src2_nativeObj, jint normType)
{
    static const char method_name[] = "core::norm_11()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Mat& src2 = *((Mat*)src2_nativeObj);
        return cv::norm( src1, src2, (int)normType );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jdouble JNICALL Java_org_opencv_core_Core_norm_12 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_core_Core_norm_12
  (JNIEnv* env, jclass , jlong src1_nativeObj, jlong src2_nativeObj)
{
    static const char method_name[] = "core::norm_12()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Mat& src2 = *((Mat*)src2_nativeObj);
        return cv::norm( src1, src2 );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::norm(Mat src1, int normType = NORM_L2, Mat mask = Mat())
//



JNIEXPORT jdouble JNICALL Java_org_opencv_core_Core_norm_13 (JNIEnv*, jclass, jlong, jint, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_core_Core_norm_13
  (JNIEnv* env, jclass , jlong src1_nativeObj, jint normType, jlong mask_nativeObj)
{
    static const char method_name[] = "core::norm_13()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        return cv::norm( src1, (int)normType, mask );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jdouble JNICALL Java_org_opencv_core_Core_norm_14 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT jdouble JNICALL Java_org_opencv_core_Core_norm_14
  (JNIEnv* env, jclass , jlong src1_nativeObj, jint normType)
{
    static const char method_name[] = "core::norm_14()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        return cv::norm( src1, (int)normType );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jdouble JNICALL Java_org_opencv_core_Core_norm_15 (JNIEnv*, jclass, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_core_Core_norm_15
  (JNIEnv* env, jclass , jlong src1_nativeObj)
{
    static const char method_name[] = "core::norm_15()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        return cv::norm( src1 );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::solvePoly(Mat coeffs, Mat& roots, int maxIters = 300)
//



JNIEXPORT jdouble JNICALL Java_org_opencv_core_Core_solvePoly_10 (JNIEnv*, jclass, jlong, jlong, jint);

JNIEXPORT jdouble JNICALL Java_org_opencv_core_Core_solvePoly_10
  (JNIEnv* env, jclass , jlong coeffs_nativeObj, jlong roots_nativeObj, jint maxIters)
{
    static const char method_name[] = "core::solvePoly_10()";
    try {
        LOGD("%s", method_name);
        Mat& coeffs = *((Mat*)coeffs_nativeObj);
        Mat& roots = *((Mat*)roots_nativeObj);
        return cv::solvePoly( coeffs, roots, (int)maxIters );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jdouble JNICALL Java_org_opencv_core_Core_solvePoly_11 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_core_Core_solvePoly_11
  (JNIEnv* env, jclass , jlong coeffs_nativeObj, jlong roots_nativeObj)
{
    static const char method_name[] = "core::solvePoly_11()";
    try {
        LOGD("%s", method_name);
        Mat& coeffs = *((Mat*)coeffs_nativeObj);
        Mat& roots = *((Mat*)roots_nativeObj);
        return cv::solvePoly( coeffs, roots );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  float cv::cubeRoot(float val)
//



JNIEXPORT jfloat JNICALL Java_org_opencv_core_Core_cubeRoot_10 (JNIEnv*, jclass, jfloat);

JNIEXPORT jfloat JNICALL Java_org_opencv_core_Core_cubeRoot_10
  (JNIEnv* env, jclass , jfloat val)
{
    static const char method_name[] = "core::cubeRoot_10()";
    try {
        LOGD("%s", method_name);
        return cv::cubeRoot( (float)val );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  float cv::fastAtan2(float y, float x)
//



JNIEXPORT jfloat JNICALL Java_org_opencv_core_Core_fastAtan2_10 (JNIEnv*, jclass, jfloat, jfloat);

JNIEXPORT jfloat JNICALL Java_org_opencv_core_Core_fastAtan2_10
  (JNIEnv* env, jclass , jfloat y, jfloat x)
{
    static const char method_name[] = "core::fastAtan2_10()";
    try {
        LOGD("%s", method_name);
        return cv::fastAtan2( (float)y, (float)x );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::borderInterpolate(int p, int len, int borderType)
//



JNIEXPORT jint JNICALL Java_org_opencv_core_Core_borderInterpolate_10 (JNIEnv*, jclass, jint, jint, jint);

JNIEXPORT jint JNICALL Java_org_opencv_core_Core_borderInterpolate_10
  (JNIEnv* env, jclass , jint p, jint len, jint borderType)
{
    static const char method_name[] = "core::borderInterpolate_10()";
    try {
        LOGD("%s", method_name);
        return cv::borderInterpolate( (int)p, (int)len, (int)borderType );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::countNonZero(Mat src)
//



JNIEXPORT jint JNICALL Java_org_opencv_core_Core_countNonZero_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_core_Core_countNonZero_10
  (JNIEnv* env, jclass , jlong src_nativeObj)
{
    static const char method_name[] = "core::countNonZero_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        return cv::countNonZero( src );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::getNumThreads()
//



JNIEXPORT jint JNICALL Java_org_opencv_core_Core_getNumThreads_10 (JNIEnv*, jclass);

JNIEXPORT jint JNICALL Java_org_opencv_core_Core_getNumThreads_10
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "core::getNumThreads_10()";
    try {
        LOGD("%s", method_name);
        return cv::getNumThreads();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::getNumberOfCPUs()
//



JNIEXPORT jint JNICALL Java_org_opencv_core_Core_getNumberOfCPUs_10 (JNIEnv*, jclass);

JNIEXPORT jint JNICALL Java_org_opencv_core_Core_getNumberOfCPUs_10
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "core::getNumberOfCPUs_10()";
    try {
        LOGD("%s", method_name);
        return cv::getNumberOfCPUs();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::getOptimalDFTSize(int vecsize)
//



JNIEXPORT jint JNICALL Java_org_opencv_core_Core_getOptimalDFTSize_10 (JNIEnv*, jclass, jint);

JNIEXPORT jint JNICALL Java_org_opencv_core_Core_getOptimalDFTSize_10
  (JNIEnv* env, jclass , jint vecsize)
{
    static const char method_name[] = "core::getOptimalDFTSize_10()";
    try {
        LOGD("%s", method_name);
        return cv::getOptimalDFTSize( (int)vecsize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::getThreadNum()
//



JNIEXPORT jint JNICALL Java_org_opencv_core_Core_getThreadNum_10 (JNIEnv*, jclass);

JNIEXPORT jint JNICALL Java_org_opencv_core_Core_getThreadNum_10
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "core::getThreadNum_10()";
    try {
        LOGD("%s", method_name);
        return cv::getThreadNum();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::getVersionMajor()
//



JNIEXPORT jint JNICALL Java_org_opencv_core_Core_getVersionMajor_10 (JNIEnv*, jclass);

JNIEXPORT jint JNICALL Java_org_opencv_core_Core_getVersionMajor_10
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "core::getVersionMajor_10()";
    try {
        LOGD("%s", method_name);
        return cv::getVersionMajor();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::getVersionMinor()
//



JNIEXPORT jint JNICALL Java_org_opencv_core_Core_getVersionMinor_10 (JNIEnv*, jclass);

JNIEXPORT jint JNICALL Java_org_opencv_core_Core_getVersionMinor_10
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "core::getVersionMinor_10()";
    try {
        LOGD("%s", method_name);
        return cv::getVersionMinor();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::getVersionRevision()
//



JNIEXPORT jint JNICALL Java_org_opencv_core_Core_getVersionRevision_10 (JNIEnv*, jclass);

JNIEXPORT jint JNICALL Java_org_opencv_core_Core_getVersionRevision_10
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "core::getVersionRevision_10()";
    try {
        LOGD("%s", method_name);
        return cv::getVersionRevision();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::solveCubic(Mat coeffs, Mat& roots)
//



JNIEXPORT jint JNICALL Java_org_opencv_core_Core_solveCubic_10 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_core_Core_solveCubic_10
  (JNIEnv* env, jclass , jlong coeffs_nativeObj, jlong roots_nativeObj)
{
    static const char method_name[] = "core::solveCubic_10()";
    try {
        LOGD("%s", method_name);
        Mat& coeffs = *((Mat*)coeffs_nativeObj);
        Mat& roots = *((Mat*)roots_nativeObj);
        return cv::solveCubic( coeffs, roots );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int64 cv::getCPUTickCount()
//



JNIEXPORT jlong JNICALL Java_org_opencv_core_Core_getCPUTickCount_10 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_core_Core_getCPUTickCount_10
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "core::getCPUTickCount_10()";
    try {
        LOGD("%s", method_name);
        return cv::getCPUTickCount();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int64 cv::getTickCount()
//



JNIEXPORT jlong JNICALL Java_org_opencv_core_Core_getTickCount_10 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_core_Core_getTickCount_10
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "core::getTickCount_10()";
    try {
        LOGD("%s", method_name);
        return cv::getTickCount();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  string cv::getCPUFeaturesLine()
//



JNIEXPORT jstring JNICALL Java_org_opencv_core_Core_getCPUFeaturesLine_10 (JNIEnv*, jclass);

JNIEXPORT jstring JNICALL Java_org_opencv_core_Core_getCPUFeaturesLine_10
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "core::getCPUFeaturesLine_10()";
    try {
        LOGD("%s", method_name);
        std::string _retval_ = cv::getCPUFeaturesLine();
        return env->NewStringUTF(_retval_.c_str());
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return env->NewStringUTF("");
}



//
//  void cv::LUT(Mat src, Mat lut, Mat& dst)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_LUT_10 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_LUT_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong lut_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "core::LUT_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& lut = *((Mat*)lut_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::LUT( src, lut, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::PCABackProject(Mat data, Mat mean, Mat eigenvectors, Mat& result)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_PCABackProject_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_PCABackProject_10
  (JNIEnv* env, jclass , jlong data_nativeObj, jlong mean_nativeObj, jlong eigenvectors_nativeObj, jlong result_nativeObj)
{
    static const char method_name[] = "core::PCABackProject_10()";
    try {
        LOGD("%s", method_name);
        Mat& data = *((Mat*)data_nativeObj);
        Mat& mean = *((Mat*)mean_nativeObj);
        Mat& eigenvectors = *((Mat*)eigenvectors_nativeObj);
        Mat& result = *((Mat*)result_nativeObj);
        cv::PCABackProject( data, mean, eigenvectors, result );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::PCACompute(Mat data, Mat& mean, Mat& eigenvectors, Mat& eigenvalues, double retainedVariance)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_PCACompute2_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_PCACompute2_10
  (JNIEnv* env, jclass , jlong data_nativeObj, jlong mean_nativeObj, jlong eigenvectors_nativeObj, jlong eigenvalues_nativeObj, jdouble retainedVariance)
{
    static const char method_name[] = "core::PCACompute2_10()";
    try {
        LOGD("%s", method_name);
        Mat& data = *((Mat*)data_nativeObj);
        Mat& mean = *((Mat*)mean_nativeObj);
        Mat& eigenvectors = *((Mat*)eigenvectors_nativeObj);
        Mat& eigenvalues = *((Mat*)eigenvalues_nativeObj);
        cv::PCACompute( data, mean, eigenvectors, eigenvalues, (double)retainedVariance );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::PCACompute(Mat data, Mat& mean, Mat& eigenvectors, Mat& eigenvalues, int maxComponents = 0)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_PCACompute2_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_PCACompute2_11
  (JNIEnv* env, jclass , jlong data_nativeObj, jlong mean_nativeObj, jlong eigenvectors_nativeObj, jlong eigenvalues_nativeObj, jint maxComponents)
{
    static const char method_name[] = "core::PCACompute2_11()";
    try {
        LOGD("%s", method_name);
        Mat& data = *((Mat*)data_nativeObj);
        Mat& mean = *((Mat*)mean_nativeObj);
        Mat& eigenvectors = *((Mat*)eigenvectors_nativeObj);
        Mat& eigenvalues = *((Mat*)eigenvalues_nativeObj);
        cv::PCACompute( data, mean, eigenvectors, eigenvalues, (int)maxComponents );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_PCACompute2_12 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_PCACompute2_12
  (JNIEnv* env, jclass , jlong data_nativeObj, jlong mean_nativeObj, jlong eigenvectors_nativeObj, jlong eigenvalues_nativeObj)
{
    static const char method_name[] = "core::PCACompute2_12()";
    try {
        LOGD("%s", method_name);
        Mat& data = *((Mat*)data_nativeObj);
        Mat& mean = *((Mat*)mean_nativeObj);
        Mat& eigenvectors = *((Mat*)eigenvectors_nativeObj);
        Mat& eigenvalues = *((Mat*)eigenvalues_nativeObj);
        cv::PCACompute( data, mean, eigenvectors, eigenvalues );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::PCACompute(Mat data, Mat& mean, Mat& eigenvectors, double retainedVariance)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_PCACompute_10 (JNIEnv*, jclass, jlong, jlong, jlong, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_PCACompute_10
  (JNIEnv* env, jclass , jlong data_nativeObj, jlong mean_nativeObj, jlong eigenvectors_nativeObj, jdouble retainedVariance)
{
    static const char method_name[] = "core::PCACompute_10()";
    try {
        LOGD("%s", method_name);
        Mat& data = *((Mat*)data_nativeObj);
        Mat& mean = *((Mat*)mean_nativeObj);
        Mat& eigenvectors = *((Mat*)eigenvectors_nativeObj);
        cv::PCACompute( data, mean, eigenvectors, (double)retainedVariance );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::PCACompute(Mat data, Mat& mean, Mat& eigenvectors, int maxComponents = 0)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_PCACompute_11 (JNIEnv*, jclass, jlong, jlong, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_PCACompute_11
  (JNIEnv* env, jclass , jlong data_nativeObj, jlong mean_nativeObj, jlong eigenvectors_nativeObj, jint maxComponents)
{
    static const char method_name[] = "core::PCACompute_11()";
    try {
        LOGD("%s", method_name);
        Mat& data = *((Mat*)data_nativeObj);
        Mat& mean = *((Mat*)mean_nativeObj);
        Mat& eigenvectors = *((Mat*)eigenvectors_nativeObj);
        cv::PCACompute( data, mean, eigenvectors, (int)maxComponents );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_PCACompute_12 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_PCACompute_12
  (JNIEnv* env, jclass , jlong data_nativeObj, jlong mean_nativeObj, jlong eigenvectors_nativeObj)
{
    static const char method_name[] = "core::PCACompute_12()";
    try {
        LOGD("%s", method_name);
        Mat& data = *((Mat*)data_nativeObj);
        Mat& mean = *((Mat*)mean_nativeObj);
        Mat& eigenvectors = *((Mat*)eigenvectors_nativeObj);
        cv::PCACompute( data, mean, eigenvectors );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::PCAProject(Mat data, Mat mean, Mat eigenvectors, Mat& result)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_PCAProject_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_PCAProject_10
  (JNIEnv* env, jclass , jlong data_nativeObj, jlong mean_nativeObj, jlong eigenvectors_nativeObj, jlong result_nativeObj)
{
    static const char method_name[] = "core::PCAProject_10()";
    try {
        LOGD("%s", method_name);
        Mat& data = *((Mat*)data_nativeObj);
        Mat& mean = *((Mat*)mean_nativeObj);
        Mat& eigenvectors = *((Mat*)eigenvectors_nativeObj);
        Mat& result = *((Mat*)result_nativeObj);
        cv::PCAProject( data, mean, eigenvectors, result );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::SVBackSubst(Mat w, Mat u, Mat vt, Mat rhs, Mat& dst)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_SVBackSubst_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_SVBackSubst_10
  (JNIEnv* env, jclass , jlong w_nativeObj, jlong u_nativeObj, jlong vt_nativeObj, jlong rhs_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "core::SVBackSubst_10()";
    try {
        LOGD("%s", method_name);
        Mat& w = *((Mat*)w_nativeObj);
        Mat& u = *((Mat*)u_nativeObj);
        Mat& vt = *((Mat*)vt_nativeObj);
        Mat& rhs = *((Mat*)rhs_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::SVBackSubst( w, u, vt, rhs, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::SVDecomp(Mat src, Mat& w, Mat& u, Mat& vt, int flags = 0)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_SVDecomp_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_SVDecomp_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong w_nativeObj, jlong u_nativeObj, jlong vt_nativeObj, jint flags)
{
    static const char method_name[] = "core::SVDecomp_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& w = *((Mat*)w_nativeObj);
        Mat& u = *((Mat*)u_nativeObj);
        Mat& vt = *((Mat*)vt_nativeObj);
        cv::SVDecomp( src, w, u, vt, (int)flags );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_SVDecomp_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_SVDecomp_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong w_nativeObj, jlong u_nativeObj, jlong vt_nativeObj)
{
    static const char method_name[] = "core::SVDecomp_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& w = *((Mat*)w_nativeObj);
        Mat& u = *((Mat*)u_nativeObj);
        Mat& vt = *((Mat*)vt_nativeObj);
        cv::SVDecomp( src, w, u, vt );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::absdiff(Mat src1, Mat src2, Mat& dst)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_absdiff_10 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_absdiff_10
  (JNIEnv* env, jclass , jlong src1_nativeObj, jlong src2_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "core::absdiff_10()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Mat& src2 = *((Mat*)src2_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::absdiff( src1, src2, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::absdiff(Mat src1, Scalar src2, Mat& dst)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_absdiff_11 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_absdiff_11
  (JNIEnv* env, jclass , jlong src1_nativeObj, jdouble src2_val0, jdouble src2_val1, jdouble src2_val2, jdouble src2_val3, jlong dst_nativeObj)
{
    static const char method_name[] = "core::absdiff_11()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Scalar src2(src2_val0, src2_val1, src2_val2, src2_val3);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::absdiff( src1, src2, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::add(Mat src1, Mat src2, Mat& dst, Mat mask = Mat(), int dtype = -1)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_add_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_add_10
  (JNIEnv* env, jclass , jlong src1_nativeObj, jlong src2_nativeObj, jlong dst_nativeObj, jlong mask_nativeObj, jint dtype)
{
    static const char method_name[] = "core::add_10()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Mat& src2 = *((Mat*)src2_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        cv::add( src1, src2, dst, mask, (int)dtype );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_add_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_add_11
  (JNIEnv* env, jclass , jlong src1_nativeObj, jlong src2_nativeObj, jlong dst_nativeObj, jlong mask_nativeObj)
{
    static const char method_name[] = "core::add_11()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Mat& src2 = *((Mat*)src2_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        cv::add( src1, src2, dst, mask );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_add_12 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_add_12
  (JNIEnv* env, jclass , jlong src1_nativeObj, jlong src2_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "core::add_12()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Mat& src2 = *((Mat*)src2_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::add( src1, src2, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::add(Mat src1, Scalar src2, Mat& dst, Mat mask = Mat(), int dtype = -1)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_add_13 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jlong, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_add_13
  (JNIEnv* env, jclass , jlong src1_nativeObj, jdouble src2_val0, jdouble src2_val1, jdouble src2_val2, jdouble src2_val3, jlong dst_nativeObj, jlong mask_nativeObj, jint dtype)
{
    static const char method_name[] = "core::add_13()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Scalar src2(src2_val0, src2_val1, src2_val2, src2_val3);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        cv::add( src1, src2, dst, mask, (int)dtype );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_add_14 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_add_14
  (JNIEnv* env, jclass , jlong src1_nativeObj, jdouble src2_val0, jdouble src2_val1, jdouble src2_val2, jdouble src2_val3, jlong dst_nativeObj, jlong mask_nativeObj)
{
    static const char method_name[] = "core::add_14()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Scalar src2(src2_val0, src2_val1, src2_val2, src2_val3);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        cv::add( src1, src2, dst, mask );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_add_15 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_add_15
  (JNIEnv* env, jclass , jlong src1_nativeObj, jdouble src2_val0, jdouble src2_val1, jdouble src2_val2, jdouble src2_val3, jlong dst_nativeObj)
{
    static const char method_name[] = "core::add_15()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Scalar src2(src2_val0, src2_val1, src2_val2, src2_val3);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::add( src1, src2, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::addWeighted(Mat src1, double alpha, Mat src2, double beta, double gamma, Mat& dst, int dtype = -1)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_addWeighted_10 (JNIEnv*, jclass, jlong, jdouble, jlong, jdouble, jdouble, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_addWeighted_10
  (JNIEnv* env, jclass , jlong src1_nativeObj, jdouble alpha, jlong src2_nativeObj, jdouble beta, jdouble gamma, jlong dst_nativeObj, jint dtype)
{
    static const char method_name[] = "core::addWeighted_10()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Mat& src2 = *((Mat*)src2_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::addWeighted( src1, (double)alpha, src2, (double)beta, (double)gamma, dst, (int)dtype );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_addWeighted_11 (JNIEnv*, jclass, jlong, jdouble, jlong, jdouble, jdouble, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_addWeighted_11
  (JNIEnv* env, jclass , jlong src1_nativeObj, jdouble alpha, jlong src2_nativeObj, jdouble beta, jdouble gamma, jlong dst_nativeObj)
{
    static const char method_name[] = "core::addWeighted_11()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Mat& src2 = *((Mat*)src2_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::addWeighted( src1, (double)alpha, src2, (double)beta, (double)gamma, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::batchDistance(Mat src1, Mat src2, Mat& dist, int dtype, Mat& nidx, int normType = NORM_L2, int K = 0, Mat mask = Mat(), int update = 0, bool crosscheck = false)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_batchDistance_10 (JNIEnv*, jclass, jlong, jlong, jlong, jint, jlong, jint, jint, jlong, jint, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_batchDistance_10
  (JNIEnv* env, jclass , jlong src1_nativeObj, jlong src2_nativeObj, jlong dist_nativeObj, jint dtype, jlong nidx_nativeObj, jint normType, jint K, jlong mask_nativeObj, jint update, jboolean crosscheck)
{
    static const char method_name[] = "core::batchDistance_10()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Mat& src2 = *((Mat*)src2_nativeObj);
        Mat& dist = *((Mat*)dist_nativeObj);
        Mat& nidx = *((Mat*)nidx_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        cv::batchDistance( src1, src2, dist, (int)dtype, nidx, (int)normType, (int)K, mask, (int)update, (bool)crosscheck );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_batchDistance_11 (JNIEnv*, jclass, jlong, jlong, jlong, jint, jlong, jint, jint, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_batchDistance_11
  (JNIEnv* env, jclass , jlong src1_nativeObj, jlong src2_nativeObj, jlong dist_nativeObj, jint dtype, jlong nidx_nativeObj, jint normType, jint K, jlong mask_nativeObj, jint update)
{
    static const char method_name[] = "core::batchDistance_11()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Mat& src2 = *((Mat*)src2_nativeObj);
        Mat& dist = *((Mat*)dist_nativeObj);
        Mat& nidx = *((Mat*)nidx_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        cv::batchDistance( src1, src2, dist, (int)dtype, nidx, (int)normType, (int)K, mask, (int)update );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_batchDistance_12 (JNIEnv*, jclass, jlong, jlong, jlong, jint, jlong, jint, jint, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_batchDistance_12
  (JNIEnv* env, jclass , jlong src1_nativeObj, jlong src2_nativeObj, jlong dist_nativeObj, jint dtype, jlong nidx_nativeObj, jint normType, jint K, jlong mask_nativeObj)
{
    static const char method_name[] = "core::batchDistance_12()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Mat& src2 = *((Mat*)src2_nativeObj);
        Mat& dist = *((Mat*)dist_nativeObj);
        Mat& nidx = *((Mat*)nidx_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        cv::batchDistance( src1, src2, dist, (int)dtype, nidx, (int)normType, (int)K, mask );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_batchDistance_13 (JNIEnv*, jclass, jlong, jlong, jlong, jint, jlong, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_batchDistance_13
  (JNIEnv* env, jclass , jlong src1_nativeObj, jlong src2_nativeObj, jlong dist_nativeObj, jint dtype, jlong nidx_nativeObj, jint normType, jint K)
{
    static const char method_name[] = "core::batchDistance_13()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Mat& src2 = *((Mat*)src2_nativeObj);
        Mat& dist = *((Mat*)dist_nativeObj);
        Mat& nidx = *((Mat*)nidx_nativeObj);
        cv::batchDistance( src1, src2, dist, (int)dtype, nidx, (int)normType, (int)K );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_batchDistance_14 (JNIEnv*, jclass, jlong, jlong, jlong, jint, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_batchDistance_14
  (JNIEnv* env, jclass , jlong src1_nativeObj, jlong src2_nativeObj, jlong dist_nativeObj, jint dtype, jlong nidx_nativeObj, jint normType)
{
    static const char method_name[] = "core::batchDistance_14()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Mat& src2 = *((Mat*)src2_nativeObj);
        Mat& dist = *((Mat*)dist_nativeObj);
        Mat& nidx = *((Mat*)nidx_nativeObj);
        cv::batchDistance( src1, src2, dist, (int)dtype, nidx, (int)normType );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_batchDistance_15 (JNIEnv*, jclass, jlong, jlong, jlong, jint, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_batchDistance_15
  (JNIEnv* env, jclass , jlong src1_nativeObj, jlong src2_nativeObj, jlong dist_nativeObj, jint dtype, jlong nidx_nativeObj)
{
    static const char method_name[] = "core::batchDistance_15()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Mat& src2 = *((Mat*)src2_nativeObj);
        Mat& dist = *((Mat*)dist_nativeObj);
        Mat& nidx = *((Mat*)nidx_nativeObj);
        cv::batchDistance( src1, src2, dist, (int)dtype, nidx );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::bitwise_and(Mat src1, Mat src2, Mat& dst, Mat mask = Mat())
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_bitwise_1and_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_bitwise_1and_10
  (JNIEnv* env, jclass , jlong src1_nativeObj, jlong src2_nativeObj, jlong dst_nativeObj, jlong mask_nativeObj)
{
    static const char method_name[] = "core::bitwise_1and_10()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Mat& src2 = *((Mat*)src2_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        cv::bitwise_and( src1, src2, dst, mask );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_bitwise_1and_11 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_bitwise_1and_11
  (JNIEnv* env, jclass , jlong src1_nativeObj, jlong src2_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "core::bitwise_1and_11()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Mat& src2 = *((Mat*)src2_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::bitwise_and( src1, src2, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::bitwise_not(Mat src, Mat& dst, Mat mask = Mat())
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_bitwise_1not_10 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_bitwise_1not_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jlong mask_nativeObj)
{
    static const char method_name[] = "core::bitwise_1not_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        cv::bitwise_not( src, dst, mask );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_bitwise_1not_11 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_bitwise_1not_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "core::bitwise_1not_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::bitwise_not( src, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::bitwise_or(Mat src1, Mat src2, Mat& dst, Mat mask = Mat())
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_bitwise_1or_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_bitwise_1or_10
  (JNIEnv* env, jclass , jlong src1_nativeObj, jlong src2_nativeObj, jlong dst_nativeObj, jlong mask_nativeObj)
{
    static const char method_name[] = "core::bitwise_1or_10()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Mat& src2 = *((Mat*)src2_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        cv::bitwise_or( src1, src2, dst, mask );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_bitwise_1or_11 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_bitwise_1or_11
  (JNIEnv* env, jclass , jlong src1_nativeObj, jlong src2_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "core::bitwise_1or_11()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Mat& src2 = *((Mat*)src2_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::bitwise_or( src1, src2, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::bitwise_xor(Mat src1, Mat src2, Mat& dst, Mat mask = Mat())
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_bitwise_1xor_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_bitwise_1xor_10
  (JNIEnv* env, jclass , jlong src1_nativeObj, jlong src2_nativeObj, jlong dst_nativeObj, jlong mask_nativeObj)
{
    static const char method_name[] = "core::bitwise_1xor_10()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Mat& src2 = *((Mat*)src2_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        cv::bitwise_xor( src1, src2, dst, mask );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_bitwise_1xor_11 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_bitwise_1xor_11
  (JNIEnv* env, jclass , jlong src1_nativeObj, jlong src2_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "core::bitwise_1xor_11()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Mat& src2 = *((Mat*)src2_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::bitwise_xor( src1, src2, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::calcCovarMatrix(Mat samples, Mat& covar, Mat& mean, int flags, int ctype = CV_64F)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_calcCovarMatrix_10 (JNIEnv*, jclass, jlong, jlong, jlong, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_calcCovarMatrix_10
  (JNIEnv* env, jclass , jlong samples_nativeObj, jlong covar_nativeObj, jlong mean_nativeObj, jint flags, jint ctype)
{
    static const char method_name[] = "core::calcCovarMatrix_10()";
    try {
        LOGD("%s", method_name);
        Mat& samples = *((Mat*)samples_nativeObj);
        Mat& covar = *((Mat*)covar_nativeObj);
        Mat& mean = *((Mat*)mean_nativeObj);
        cv::calcCovarMatrix( samples, covar, mean, (int)flags, (int)ctype );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_calcCovarMatrix_11 (JNIEnv*, jclass, jlong, jlong, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_calcCovarMatrix_11
  (JNIEnv* env, jclass , jlong samples_nativeObj, jlong covar_nativeObj, jlong mean_nativeObj, jint flags)
{
    static const char method_name[] = "core::calcCovarMatrix_11()";
    try {
        LOGD("%s", method_name);
        Mat& samples = *((Mat*)samples_nativeObj);
        Mat& covar = *((Mat*)covar_nativeObj);
        Mat& mean = *((Mat*)mean_nativeObj);
        cv::calcCovarMatrix( samples, covar, mean, (int)flags );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::cartToPolar(Mat x, Mat y, Mat& magnitude, Mat& angle, bool angleInDegrees = false)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_cartToPolar_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_cartToPolar_10
  (JNIEnv* env, jclass , jlong x_nativeObj, jlong y_nativeObj, jlong magnitude_nativeObj, jlong angle_nativeObj, jboolean angleInDegrees)
{
    static const char method_name[] = "core::cartToPolar_10()";
    try {
        LOGD("%s", method_name);
        Mat& x = *((Mat*)x_nativeObj);
        Mat& y = *((Mat*)y_nativeObj);
        Mat& magnitude = *((Mat*)magnitude_nativeObj);
        Mat& angle = *((Mat*)angle_nativeObj);
        cv::cartToPolar( x, y, magnitude, angle, (bool)angleInDegrees );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_cartToPolar_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_cartToPolar_11
  (JNIEnv* env, jclass , jlong x_nativeObj, jlong y_nativeObj, jlong magnitude_nativeObj, jlong angle_nativeObj)
{
    static const char method_name[] = "core::cartToPolar_11()";
    try {
        LOGD("%s", method_name);
        Mat& x = *((Mat*)x_nativeObj);
        Mat& y = *((Mat*)y_nativeObj);
        Mat& magnitude = *((Mat*)magnitude_nativeObj);
        Mat& angle = *((Mat*)angle_nativeObj);
        cv::cartToPolar( x, y, magnitude, angle );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::compare(Mat src1, Mat src2, Mat& dst, int cmpop)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_compare_10 (JNIEnv*, jclass, jlong, jlong, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_compare_10
  (JNIEnv* env, jclass , jlong src1_nativeObj, jlong src2_nativeObj, jlong dst_nativeObj, jint cmpop)
{
    static const char method_name[] = "core::compare_10()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Mat& src2 = *((Mat*)src2_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::compare( src1, src2, dst, (int)cmpop );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::compare(Mat src1, Scalar src2, Mat& dst, int cmpop)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_compare_11 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_compare_11
  (JNIEnv* env, jclass , jlong src1_nativeObj, jdouble src2_val0, jdouble src2_val1, jdouble src2_val2, jdouble src2_val3, jlong dst_nativeObj, jint cmpop)
{
    static const char method_name[] = "core::compare_11()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Scalar src2(src2_val0, src2_val1, src2_val2, src2_val3);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::compare( src1, src2, dst, (int)cmpop );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::completeSymm(Mat& m, bool lowerToUpper = false)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_completeSymm_10 (JNIEnv*, jclass, jlong, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_completeSymm_10
  (JNIEnv* env, jclass , jlong m_nativeObj, jboolean lowerToUpper)
{
    static const char method_name[] = "core::completeSymm_10()";
    try {
        LOGD("%s", method_name);
        Mat& m = *((Mat*)m_nativeObj);
        cv::completeSymm( m, (bool)lowerToUpper );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_completeSymm_11 (JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_completeSymm_11
  (JNIEnv* env, jclass , jlong m_nativeObj)
{
    static const char method_name[] = "core::completeSymm_11()";
    try {
        LOGD("%s", method_name);
        Mat& m = *((Mat*)m_nativeObj);
        cv::completeSymm( m );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::convertFp16(Mat src, Mat& dst)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_convertFp16_10 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_convertFp16_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "core::convertFp16_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::convertFp16( src, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::convertScaleAbs(Mat src, Mat& dst, double alpha = 1, double beta = 0)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_convertScaleAbs_10 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_convertScaleAbs_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jdouble alpha, jdouble beta)
{
    static const char method_name[] = "core::convertScaleAbs_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::convertScaleAbs( src, dst, (double)alpha, (double)beta );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_convertScaleAbs_11 (JNIEnv*, jclass, jlong, jlong, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_convertScaleAbs_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jdouble alpha)
{
    static const char method_name[] = "core::convertScaleAbs_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::convertScaleAbs( src, dst, (double)alpha );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_convertScaleAbs_12 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_convertScaleAbs_12
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "core::convertScaleAbs_12()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::convertScaleAbs( src, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::copyMakeBorder(Mat src, Mat& dst, int top, int bottom, int left, int right, int borderType, Scalar value = Scalar())
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_copyMakeBorder_10 (JNIEnv*, jclass, jlong, jlong, jint, jint, jint, jint, jint, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_copyMakeBorder_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint top, jint bottom, jint left, jint right, jint borderType, jdouble value_val0, jdouble value_val1, jdouble value_val2, jdouble value_val3)
{
    static const char method_name[] = "core::copyMakeBorder_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Scalar value(value_val0, value_val1, value_val2, value_val3);
        cv::copyMakeBorder( src, dst, (int)top, (int)bottom, (int)left, (int)right, (int)borderType, value );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_copyMakeBorder_11 (JNIEnv*, jclass, jlong, jlong, jint, jint, jint, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_copyMakeBorder_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint top, jint bottom, jint left, jint right, jint borderType)
{
    static const char method_name[] = "core::copyMakeBorder_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::copyMakeBorder( src, dst, (int)top, (int)bottom, (int)left, (int)right, (int)borderType );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::copyTo(Mat src, Mat& dst, Mat mask)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_copyTo_10 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_copyTo_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jlong mask_nativeObj)
{
    static const char method_name[] = "core::copyTo_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        cv::copyTo( src, dst, mask );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::dct(Mat src, Mat& dst, int flags = 0)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_dct_10 (JNIEnv*, jclass, jlong, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_dct_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint flags)
{
    static const char method_name[] = "core::dct_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::dct( src, dst, (int)flags );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_dct_11 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_dct_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "core::dct_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::dct( src, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::dft(Mat src, Mat& dst, int flags = 0, int nonzeroRows = 0)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_dft_10 (JNIEnv*, jclass, jlong, jlong, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_dft_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint flags, jint nonzeroRows)
{
    static const char method_name[] = "core::dft_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::dft( src, dst, (int)flags, (int)nonzeroRows );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_dft_11 (JNIEnv*, jclass, jlong, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_dft_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint flags)
{
    static const char method_name[] = "core::dft_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::dft( src, dst, (int)flags );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_dft_12 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_dft_12
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "core::dft_12()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::dft( src, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::divide(Mat src1, Mat src2, Mat& dst, double scale = 1, int dtype = -1)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_divide_10 (JNIEnv*, jclass, jlong, jlong, jlong, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_divide_10
  (JNIEnv* env, jclass , jlong src1_nativeObj, jlong src2_nativeObj, jlong dst_nativeObj, jdouble scale, jint dtype)
{
    static const char method_name[] = "core::divide_10()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Mat& src2 = *((Mat*)src2_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::divide( src1, src2, dst, (double)scale, (int)dtype );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_divide_11 (JNIEnv*, jclass, jlong, jlong, jlong, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_divide_11
  (JNIEnv* env, jclass , jlong src1_nativeObj, jlong src2_nativeObj, jlong dst_nativeObj, jdouble scale)
{
    static const char method_name[] = "core::divide_11()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Mat& src2 = *((Mat*)src2_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::divide( src1, src2, dst, (double)scale );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_divide_12 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_divide_12
  (JNIEnv* env, jclass , jlong src1_nativeObj, jlong src2_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "core::divide_12()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Mat& src2 = *((Mat*)src2_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::divide( src1, src2, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::divide(Mat src1, Scalar src2, Mat& dst, double scale = 1, int dtype = -1)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_divide_13 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jlong, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_divide_13
  (JNIEnv* env, jclass , jlong src1_nativeObj, jdouble src2_val0, jdouble src2_val1, jdouble src2_val2, jdouble src2_val3, jlong dst_nativeObj, jdouble scale, jint dtype)
{
    static const char method_name[] = "core::divide_13()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Scalar src2(src2_val0, src2_val1, src2_val2, src2_val3);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::divide( src1, src2, dst, (double)scale, (int)dtype );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_divide_14 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jlong, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_divide_14
  (JNIEnv* env, jclass , jlong src1_nativeObj, jdouble src2_val0, jdouble src2_val1, jdouble src2_val2, jdouble src2_val3, jlong dst_nativeObj, jdouble scale)
{
    static const char method_name[] = "core::divide_14()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Scalar src2(src2_val0, src2_val1, src2_val2, src2_val3);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::divide( src1, src2, dst, (double)scale );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_divide_15 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_divide_15
  (JNIEnv* env, jclass , jlong src1_nativeObj, jdouble src2_val0, jdouble src2_val1, jdouble src2_val2, jdouble src2_val3, jlong dst_nativeObj)
{
    static const char method_name[] = "core::divide_15()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Scalar src2(src2_val0, src2_val1, src2_val2, src2_val3);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::divide( src1, src2, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::divide(double scale, Mat src2, Mat& dst, int dtype = -1)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_divide_16 (JNIEnv*, jclass, jdouble, jlong, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_divide_16
  (JNIEnv* env, jclass , jdouble scale, jlong src2_nativeObj, jlong dst_nativeObj, jint dtype)
{
    static const char method_name[] = "core::divide_16()";
    try {
        LOGD("%s", method_name);
        Mat& src2 = *((Mat*)src2_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::divide( (double)scale, src2, dst, (int)dtype );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_divide_17 (JNIEnv*, jclass, jdouble, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_divide_17
  (JNIEnv* env, jclass , jdouble scale, jlong src2_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "core::divide_17()";
    try {
        LOGD("%s", method_name);
        Mat& src2 = *((Mat*)src2_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::divide( (double)scale, src2, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::eigenNonSymmetric(Mat src, Mat& eigenvalues, Mat& eigenvectors)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_eigenNonSymmetric_10 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_eigenNonSymmetric_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong eigenvalues_nativeObj, jlong eigenvectors_nativeObj)
{
    static const char method_name[] = "core::eigenNonSymmetric_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& eigenvalues = *((Mat*)eigenvalues_nativeObj);
        Mat& eigenvectors = *((Mat*)eigenvectors_nativeObj);
        cv::eigenNonSymmetric( src, eigenvalues, eigenvectors );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::exp(Mat src, Mat& dst)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_exp_10 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_exp_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "core::exp_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::exp( src, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::extractChannel(Mat src, Mat& dst, int coi)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_extractChannel_10 (JNIEnv*, jclass, jlong, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_extractChannel_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint coi)
{
    static const char method_name[] = "core::extractChannel_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::extractChannel( src, dst, (int)coi );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::findNonZero(Mat src, Mat& idx)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_findNonZero_10 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_findNonZero_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong idx_nativeObj)
{
    static const char method_name[] = "core::findNonZero_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& idx = *((Mat*)idx_nativeObj);
        cv::findNonZero( src, idx );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::flip(Mat src, Mat& dst, int flipCode)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_flip_10 (JNIEnv*, jclass, jlong, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_flip_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint flipCode)
{
    static const char method_name[] = "core::flip_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::flip( src, dst, (int)flipCode );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::gemm(Mat src1, Mat src2, double alpha, Mat src3, double beta, Mat& dst, int flags = 0)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_gemm_10 (JNIEnv*, jclass, jlong, jlong, jdouble, jlong, jdouble, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_gemm_10
  (JNIEnv* env, jclass , jlong src1_nativeObj, jlong src2_nativeObj, jdouble alpha, jlong src3_nativeObj, jdouble beta, jlong dst_nativeObj, jint flags)
{
    static const char method_name[] = "core::gemm_10()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Mat& src2 = *((Mat*)src2_nativeObj);
        Mat& src3 = *((Mat*)src3_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::gemm( src1, src2, (double)alpha, src3, (double)beta, dst, (int)flags );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_gemm_11 (JNIEnv*, jclass, jlong, jlong, jdouble, jlong, jdouble, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_gemm_11
  (JNIEnv* env, jclass , jlong src1_nativeObj, jlong src2_nativeObj, jdouble alpha, jlong src3_nativeObj, jdouble beta, jlong dst_nativeObj)
{
    static const char method_name[] = "core::gemm_11()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Mat& src2 = *((Mat*)src2_nativeObj);
        Mat& src3 = *((Mat*)src3_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::gemm( src1, src2, (double)alpha, src3, (double)beta, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::hconcat(vector_Mat src, Mat& dst)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_hconcat_10 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_hconcat_10
  (JNIEnv* env, jclass , jlong src_mat_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "core::hconcat_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> src;
        Mat& src_mat = *((Mat*)src_mat_nativeObj);
        Mat_to_vector_Mat( src_mat, src );
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::hconcat( src, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::idct(Mat src, Mat& dst, int flags = 0)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_idct_10 (JNIEnv*, jclass, jlong, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_idct_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint flags)
{
    static const char method_name[] = "core::idct_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::idct( src, dst, (int)flags );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_idct_11 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_idct_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "core::idct_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::idct( src, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::idft(Mat src, Mat& dst, int flags = 0, int nonzeroRows = 0)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_idft_10 (JNIEnv*, jclass, jlong, jlong, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_idft_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint flags, jint nonzeroRows)
{
    static const char method_name[] = "core::idft_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::idft( src, dst, (int)flags, (int)nonzeroRows );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_idft_11 (JNIEnv*, jclass, jlong, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_idft_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint flags)
{
    static const char method_name[] = "core::idft_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::idft( src, dst, (int)flags );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_idft_12 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_idft_12
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "core::idft_12()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::idft( src, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::inRange(Mat src, Scalar lowerb, Scalar upperb, Mat& dst)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_inRange_10 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_inRange_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jdouble lowerb_val0, jdouble lowerb_val1, jdouble lowerb_val2, jdouble lowerb_val3, jdouble upperb_val0, jdouble upperb_val1, jdouble upperb_val2, jdouble upperb_val3, jlong dst_nativeObj)
{
    static const char method_name[] = "core::inRange_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Scalar lowerb(lowerb_val0, lowerb_val1, lowerb_val2, lowerb_val3);
        Scalar upperb(upperb_val0, upperb_val1, upperb_val2, upperb_val3);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::inRange( src, lowerb, upperb, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::insertChannel(Mat src, Mat& dst, int coi)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_insertChannel_10 (JNIEnv*, jclass, jlong, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_insertChannel_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint coi)
{
    static const char method_name[] = "core::insertChannel_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::insertChannel( src, dst, (int)coi );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::log(Mat src, Mat& dst)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_log_10 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_log_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "core::log_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::log( src, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::magnitude(Mat x, Mat y, Mat& magnitude)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_magnitude_10 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_magnitude_10
  (JNIEnv* env, jclass , jlong x_nativeObj, jlong y_nativeObj, jlong magnitude_nativeObj)
{
    static const char method_name[] = "core::magnitude_10()";
    try {
        LOGD("%s", method_name);
        Mat& x = *((Mat*)x_nativeObj);
        Mat& y = *((Mat*)y_nativeObj);
        Mat& magnitude = *((Mat*)magnitude_nativeObj);
        cv::magnitude( x, y, magnitude );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::max(Mat src1, Mat src2, Mat& dst)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_max_10 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_max_10
  (JNIEnv* env, jclass , jlong src1_nativeObj, jlong src2_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "core::max_10()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Mat& src2 = *((Mat*)src2_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::max( src1, src2, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::max(Mat src1, Scalar src2, Mat& dst)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_max_11 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_max_11
  (JNIEnv* env, jclass , jlong src1_nativeObj, jdouble src2_val0, jdouble src2_val1, jdouble src2_val2, jdouble src2_val3, jlong dst_nativeObj)
{
    static const char method_name[] = "core::max_11()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Scalar src2(src2_val0, src2_val1, src2_val2, src2_val3);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::max( src1, src2, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::meanStdDev(Mat src, vector_double& mean, vector_double& stddev, Mat mask = Mat())
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_meanStdDev_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_meanStdDev_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong mean_mat_nativeObj, jlong stddev_mat_nativeObj, jlong mask_nativeObj)
{
    static const char method_name[] = "core::meanStdDev_10()";
    try {
        LOGD("%s", method_name);
        std::vector<double> mean;
        Mat& mean_mat = *((Mat*)mean_mat_nativeObj);
        std::vector<double> stddev;
        Mat& stddev_mat = *((Mat*)stddev_mat_nativeObj);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        cv::meanStdDev( src, mean, stddev, mask );
        vector_double_to_Mat( mean, mean_mat );
        vector_double_to_Mat( stddev, stddev_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_meanStdDev_11 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_meanStdDev_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong mean_mat_nativeObj, jlong stddev_mat_nativeObj)
{
    static const char method_name[] = "core::meanStdDev_11()";
    try {
        LOGD("%s", method_name);
        std::vector<double> mean;
        Mat& mean_mat = *((Mat*)mean_mat_nativeObj);
        std::vector<double> stddev;
        Mat& stddev_mat = *((Mat*)stddev_mat_nativeObj);
        Mat& src = *((Mat*)src_nativeObj);
        cv::meanStdDev( src, mean, stddev );
        vector_double_to_Mat( mean, mean_mat );
        vector_double_to_Mat( stddev, stddev_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::merge(vector_Mat mv, Mat& dst)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_merge_10 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_merge_10
  (JNIEnv* env, jclass , jlong mv_mat_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "core::merge_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> mv;
        Mat& mv_mat = *((Mat*)mv_mat_nativeObj);
        Mat_to_vector_Mat( mv_mat, mv );
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::merge( mv, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::min(Mat src1, Mat src2, Mat& dst)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_min_10 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_min_10
  (JNIEnv* env, jclass , jlong src1_nativeObj, jlong src2_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "core::min_10()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Mat& src2 = *((Mat*)src2_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::min( src1, src2, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::min(Mat src1, Scalar src2, Mat& dst)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_min_11 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_min_11
  (JNIEnv* env, jclass , jlong src1_nativeObj, jdouble src2_val0, jdouble src2_val1, jdouble src2_val2, jdouble src2_val3, jlong dst_nativeObj)
{
    static const char method_name[] = "core::min_11()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Scalar src2(src2_val0, src2_val1, src2_val2, src2_val3);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::min( src1, src2, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::mixChannels(vector_Mat src, vector_Mat dst, vector_int fromTo)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_mixChannels_10 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_mixChannels_10
  (JNIEnv* env, jclass , jlong src_mat_nativeObj, jlong dst_mat_nativeObj, jlong fromTo_mat_nativeObj)
{
    static const char method_name[] = "core::mixChannels_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> src;
        Mat& src_mat = *((Mat*)src_mat_nativeObj);
        Mat_to_vector_Mat( src_mat, src );
        std::vector<Mat> dst;
        Mat& dst_mat = *((Mat*)dst_mat_nativeObj);
        Mat_to_vector_Mat( dst_mat, dst );
        std::vector<int> fromTo;
        Mat& fromTo_mat = *((Mat*)fromTo_mat_nativeObj);
        Mat_to_vector_int( fromTo_mat, fromTo );
        cv::mixChannels( src, dst, fromTo );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::mulSpectrums(Mat a, Mat b, Mat& c, int flags, bool conjB = false)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_mulSpectrums_10 (JNIEnv*, jclass, jlong, jlong, jlong, jint, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_mulSpectrums_10
  (JNIEnv* env, jclass , jlong a_nativeObj, jlong b_nativeObj, jlong c_nativeObj, jint flags, jboolean conjB)
{
    static const char method_name[] = "core::mulSpectrums_10()";
    try {
        LOGD("%s", method_name);
        Mat& a = *((Mat*)a_nativeObj);
        Mat& b = *((Mat*)b_nativeObj);
        Mat& c = *((Mat*)c_nativeObj);
        cv::mulSpectrums( a, b, c, (int)flags, (bool)conjB );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_mulSpectrums_11 (JNIEnv*, jclass, jlong, jlong, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_mulSpectrums_11
  (JNIEnv* env, jclass , jlong a_nativeObj, jlong b_nativeObj, jlong c_nativeObj, jint flags)
{
    static const char method_name[] = "core::mulSpectrums_11()";
    try {
        LOGD("%s", method_name);
        Mat& a = *((Mat*)a_nativeObj);
        Mat& b = *((Mat*)b_nativeObj);
        Mat& c = *((Mat*)c_nativeObj);
        cv::mulSpectrums( a, b, c, (int)flags );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::mulTransposed(Mat src, Mat& dst, bool aTa, Mat delta = Mat(), double scale = 1, int dtype = -1)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_mulTransposed_10 (JNIEnv*, jclass, jlong, jlong, jboolean, jlong, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_mulTransposed_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jboolean aTa, jlong delta_nativeObj, jdouble scale, jint dtype)
{
    static const char method_name[] = "core::mulTransposed_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& delta = *((Mat*)delta_nativeObj);
        cv::mulTransposed( src, dst, (bool)aTa, delta, (double)scale, (int)dtype );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_mulTransposed_11 (JNIEnv*, jclass, jlong, jlong, jboolean, jlong, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_mulTransposed_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jboolean aTa, jlong delta_nativeObj, jdouble scale)
{
    static const char method_name[] = "core::mulTransposed_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& delta = *((Mat*)delta_nativeObj);
        cv::mulTransposed( src, dst, (bool)aTa, delta, (double)scale );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_mulTransposed_12 (JNIEnv*, jclass, jlong, jlong, jboolean, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_mulTransposed_12
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jboolean aTa, jlong delta_nativeObj)
{
    static const char method_name[] = "core::mulTransposed_12()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& delta = *((Mat*)delta_nativeObj);
        cv::mulTransposed( src, dst, (bool)aTa, delta );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_mulTransposed_13 (JNIEnv*, jclass, jlong, jlong, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_mulTransposed_13
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jboolean aTa)
{
    static const char method_name[] = "core::mulTransposed_13()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::mulTransposed( src, dst, (bool)aTa );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::multiply(Mat src1, Mat src2, Mat& dst, double scale = 1, int dtype = -1)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_multiply_10 (JNIEnv*, jclass, jlong, jlong, jlong, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_multiply_10
  (JNIEnv* env, jclass , jlong src1_nativeObj, jlong src2_nativeObj, jlong dst_nativeObj, jdouble scale, jint dtype)
{
    static const char method_name[] = "core::multiply_10()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Mat& src2 = *((Mat*)src2_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::multiply( src1, src2, dst, (double)scale, (int)dtype );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_multiply_11 (JNIEnv*, jclass, jlong, jlong, jlong, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_multiply_11
  (JNIEnv* env, jclass , jlong src1_nativeObj, jlong src2_nativeObj, jlong dst_nativeObj, jdouble scale)
{
    static const char method_name[] = "core::multiply_11()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Mat& src2 = *((Mat*)src2_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::multiply( src1, src2, dst, (double)scale );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_multiply_12 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_multiply_12
  (JNIEnv* env, jclass , jlong src1_nativeObj, jlong src2_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "core::multiply_12()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Mat& src2 = *((Mat*)src2_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::multiply( src1, src2, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::multiply(Mat src1, Scalar src2, Mat& dst, double scale = 1, int dtype = -1)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_multiply_13 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jlong, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_multiply_13
  (JNIEnv* env, jclass , jlong src1_nativeObj, jdouble src2_val0, jdouble src2_val1, jdouble src2_val2, jdouble src2_val3, jlong dst_nativeObj, jdouble scale, jint dtype)
{
    static const char method_name[] = "core::multiply_13()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Scalar src2(src2_val0, src2_val1, src2_val2, src2_val3);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::multiply( src1, src2, dst, (double)scale, (int)dtype );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_multiply_14 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jlong, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_multiply_14
  (JNIEnv* env, jclass , jlong src1_nativeObj, jdouble src2_val0, jdouble src2_val1, jdouble src2_val2, jdouble src2_val3, jlong dst_nativeObj, jdouble scale)
{
    static const char method_name[] = "core::multiply_14()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Scalar src2(src2_val0, src2_val1, src2_val2, src2_val3);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::multiply( src1, src2, dst, (double)scale );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_multiply_15 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_multiply_15
  (JNIEnv* env, jclass , jlong src1_nativeObj, jdouble src2_val0, jdouble src2_val1, jdouble src2_val2, jdouble src2_val3, jlong dst_nativeObj)
{
    static const char method_name[] = "core::multiply_15()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Scalar src2(src2_val0, src2_val1, src2_val2, src2_val3);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::multiply( src1, src2, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::normalize(Mat src, Mat& dst, double alpha = 1, double beta = 0, int norm_type = NORM_L2, int dtype = -1, Mat mask = Mat())
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_normalize_10 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jint, jint, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_normalize_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jdouble alpha, jdouble beta, jint norm_type, jint dtype, jlong mask_nativeObj)
{
    static const char method_name[] = "core::normalize_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        cv::normalize( src, dst, (double)alpha, (double)beta, (int)norm_type, (int)dtype, mask );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_normalize_11 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_normalize_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jdouble alpha, jdouble beta, jint norm_type, jint dtype)
{
    static const char method_name[] = "core::normalize_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::normalize( src, dst, (double)alpha, (double)beta, (int)norm_type, (int)dtype );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_normalize_12 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_normalize_12
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jdouble alpha, jdouble beta, jint norm_type)
{
    static const char method_name[] = "core::normalize_12()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::normalize( src, dst, (double)alpha, (double)beta, (int)norm_type );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_normalize_13 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_normalize_13
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jdouble alpha, jdouble beta)
{
    static const char method_name[] = "core::normalize_13()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::normalize( src, dst, (double)alpha, (double)beta );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_normalize_14 (JNIEnv*, jclass, jlong, jlong, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_normalize_14
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jdouble alpha)
{
    static const char method_name[] = "core::normalize_14()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::normalize( src, dst, (double)alpha );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_normalize_15 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_normalize_15
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "core::normalize_15()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::normalize( src, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::patchNaNs(Mat& a, double val = 0)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_patchNaNs_10 (JNIEnv*, jclass, jlong, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_patchNaNs_10
  (JNIEnv* env, jclass , jlong a_nativeObj, jdouble val)
{
    static const char method_name[] = "core::patchNaNs_10()";
    try {
        LOGD("%s", method_name);
        Mat& a = *((Mat*)a_nativeObj);
        cv::patchNaNs( a, (double)val );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_patchNaNs_11 (JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_patchNaNs_11
  (JNIEnv* env, jclass , jlong a_nativeObj)
{
    static const char method_name[] = "core::patchNaNs_11()";
    try {
        LOGD("%s", method_name);
        Mat& a = *((Mat*)a_nativeObj);
        cv::patchNaNs( a );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::perspectiveTransform(Mat src, Mat& dst, Mat m)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_perspectiveTransform_10 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_perspectiveTransform_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jlong m_nativeObj)
{
    static const char method_name[] = "core::perspectiveTransform_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& m = *((Mat*)m_nativeObj);
        cv::perspectiveTransform( src, dst, m );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::phase(Mat x, Mat y, Mat& angle, bool angleInDegrees = false)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_phase_10 (JNIEnv*, jclass, jlong, jlong, jlong, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_phase_10
  (JNIEnv* env, jclass , jlong x_nativeObj, jlong y_nativeObj, jlong angle_nativeObj, jboolean angleInDegrees)
{
    static const char method_name[] = "core::phase_10()";
    try {
        LOGD("%s", method_name);
        Mat& x = *((Mat*)x_nativeObj);
        Mat& y = *((Mat*)y_nativeObj);
        Mat& angle = *((Mat*)angle_nativeObj);
        cv::phase( x, y, angle, (bool)angleInDegrees );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_phase_11 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_phase_11
  (JNIEnv* env, jclass , jlong x_nativeObj, jlong y_nativeObj, jlong angle_nativeObj)
{
    static const char method_name[] = "core::phase_11()";
    try {
        LOGD("%s", method_name);
        Mat& x = *((Mat*)x_nativeObj);
        Mat& y = *((Mat*)y_nativeObj);
        Mat& angle = *((Mat*)angle_nativeObj);
        cv::phase( x, y, angle );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::polarToCart(Mat magnitude, Mat angle, Mat& x, Mat& y, bool angleInDegrees = false)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_polarToCart_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_polarToCart_10
  (JNIEnv* env, jclass , jlong magnitude_nativeObj, jlong angle_nativeObj, jlong x_nativeObj, jlong y_nativeObj, jboolean angleInDegrees)
{
    static const char method_name[] = "core::polarToCart_10()";
    try {
        LOGD("%s", method_name);
        Mat& magnitude = *((Mat*)magnitude_nativeObj);
        Mat& angle = *((Mat*)angle_nativeObj);
        Mat& x = *((Mat*)x_nativeObj);
        Mat& y = *((Mat*)y_nativeObj);
        cv::polarToCart( magnitude, angle, x, y, (bool)angleInDegrees );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_polarToCart_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_polarToCart_11
  (JNIEnv* env, jclass , jlong magnitude_nativeObj, jlong angle_nativeObj, jlong x_nativeObj, jlong y_nativeObj)
{
    static const char method_name[] = "core::polarToCart_11()";
    try {
        LOGD("%s", method_name);
        Mat& magnitude = *((Mat*)magnitude_nativeObj);
        Mat& angle = *((Mat*)angle_nativeObj);
        Mat& x = *((Mat*)x_nativeObj);
        Mat& y = *((Mat*)y_nativeObj);
        cv::polarToCart( magnitude, angle, x, y );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::pow(Mat src, double power, Mat& dst)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_pow_10 (JNIEnv*, jclass, jlong, jdouble, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_pow_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jdouble power, jlong dst_nativeObj)
{
    static const char method_name[] = "core::pow_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::pow( src, (double)power, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::randShuffle(Mat& dst, double iterFactor = 1., RNG* rng = 0)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_randShuffle_10 (JNIEnv*, jclass, jlong, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_randShuffle_10
  (JNIEnv* env, jclass , jlong dst_nativeObj, jdouble iterFactor)
{
    static const char method_name[] = "core::randShuffle_10()";
    try {
        LOGD("%s", method_name);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::randShuffle( dst, (double)iterFactor, 0 );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_randShuffle_12 (JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_randShuffle_12
  (JNIEnv* env, jclass , jlong dst_nativeObj)
{
    static const char method_name[] = "core::randShuffle_12()";
    try {
        LOGD("%s", method_name);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::randShuffle( dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::randn(Mat& dst, double mean, double stddev)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_randn_10 (JNIEnv*, jclass, jlong, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_randn_10
  (JNIEnv* env, jclass , jlong dst_nativeObj, jdouble mean, jdouble stddev)
{
    static const char method_name[] = "core::randn_10()";
    try {
        LOGD("%s", method_name);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::randn( dst, (double)mean, (double)stddev );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::randu(Mat& dst, double low, double high)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_randu_10 (JNIEnv*, jclass, jlong, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_randu_10
  (JNIEnv* env, jclass , jlong dst_nativeObj, jdouble low, jdouble high)
{
    static const char method_name[] = "core::randu_10()";
    try {
        LOGD("%s", method_name);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::randu( dst, (double)low, (double)high );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::reduce(Mat src, Mat& dst, int dim, int rtype, int dtype = -1)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_reduce_10 (JNIEnv*, jclass, jlong, jlong, jint, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_reduce_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint dim, jint rtype, jint dtype)
{
    static const char method_name[] = "core::reduce_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::reduce( src, dst, (int)dim, (int)rtype, (int)dtype );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_reduce_11 (JNIEnv*, jclass, jlong, jlong, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_reduce_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint dim, jint rtype)
{
    static const char method_name[] = "core::reduce_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::reduce( src, dst, (int)dim, (int)rtype );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::repeat(Mat src, int ny, int nx, Mat& dst)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_repeat_10 (JNIEnv*, jclass, jlong, jint, jint, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_repeat_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jint ny, jint nx, jlong dst_nativeObj)
{
    static const char method_name[] = "core::repeat_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::repeat( src, (int)ny, (int)nx, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::rotate(Mat src, Mat& dst, int rotateCode)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_rotate_10 (JNIEnv*, jclass, jlong, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_rotate_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint rotateCode)
{
    static const char method_name[] = "core::rotate_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::rotate( src, dst, (int)rotateCode );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::scaleAdd(Mat src1, double alpha, Mat src2, Mat& dst)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_scaleAdd_10 (JNIEnv*, jclass, jlong, jdouble, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_scaleAdd_10
  (JNIEnv* env, jclass , jlong src1_nativeObj, jdouble alpha, jlong src2_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "core::scaleAdd_10()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Mat& src2 = *((Mat*)src2_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::scaleAdd( src1, (double)alpha, src2, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::setErrorVerbosity(bool verbose)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_setErrorVerbosity_10 (JNIEnv*, jclass, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_setErrorVerbosity_10
  (JNIEnv* env, jclass , jboolean verbose)
{
    static const char method_name[] = "core::setErrorVerbosity_10()";
    try {
        LOGD("%s", method_name);
        cv::setErrorVerbosity( (bool)verbose );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::setIdentity(Mat& mtx, Scalar s = Scalar(1))
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_setIdentity_10 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_setIdentity_10
  (JNIEnv* env, jclass , jlong mtx_nativeObj, jdouble s_val0, jdouble s_val1, jdouble s_val2, jdouble s_val3)
{
    static const char method_name[] = "core::setIdentity_10()";
    try {
        LOGD("%s", method_name);
        Mat& mtx = *((Mat*)mtx_nativeObj);
        Scalar s(s_val0, s_val1, s_val2, s_val3);
        cv::setIdentity( mtx, s );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_setIdentity_11 (JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_setIdentity_11
  (JNIEnv* env, jclass , jlong mtx_nativeObj)
{
    static const char method_name[] = "core::setIdentity_11()";
    try {
        LOGD("%s", method_name);
        Mat& mtx = *((Mat*)mtx_nativeObj);
        cv::setIdentity( mtx );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::setNumThreads(int nthreads)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_setNumThreads_10 (JNIEnv*, jclass, jint);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_setNumThreads_10
  (JNIEnv* env, jclass , jint nthreads)
{
    static const char method_name[] = "core::setNumThreads_10()";
    try {
        LOGD("%s", method_name);
        cv::setNumThreads( (int)nthreads );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::setRNGSeed(int seed)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_setRNGSeed_10 (JNIEnv*, jclass, jint);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_setRNGSeed_10
  (JNIEnv* env, jclass , jint seed)
{
    static const char method_name[] = "core::setRNGSeed_10()";
    try {
        LOGD("%s", method_name);
        cv::setRNGSeed( (int)seed );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::sort(Mat src, Mat& dst, int flags)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_sort_10 (JNIEnv*, jclass, jlong, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_sort_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint flags)
{
    static const char method_name[] = "core::sort_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::sort( src, dst, (int)flags );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::sortIdx(Mat src, Mat& dst, int flags)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_sortIdx_10 (JNIEnv*, jclass, jlong, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_sortIdx_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint flags)
{
    static const char method_name[] = "core::sortIdx_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::sortIdx( src, dst, (int)flags );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::split(Mat m, vector_Mat& mv)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_split_10 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_split_10
  (JNIEnv* env, jclass , jlong m_nativeObj, jlong mv_mat_nativeObj)
{
    static const char method_name[] = "core::split_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> mv;
        Mat& mv_mat = *((Mat*)mv_mat_nativeObj);
        Mat& m = *((Mat*)m_nativeObj);
        cv::split( m, mv );
        vector_Mat_to_Mat( mv, mv_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::sqrt(Mat src, Mat& dst)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_sqrt_10 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_sqrt_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "core::sqrt_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::sqrt( src, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::subtract(Mat src1, Mat src2, Mat& dst, Mat mask = Mat(), int dtype = -1)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_subtract_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_subtract_10
  (JNIEnv* env, jclass , jlong src1_nativeObj, jlong src2_nativeObj, jlong dst_nativeObj, jlong mask_nativeObj, jint dtype)
{
    static const char method_name[] = "core::subtract_10()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Mat& src2 = *((Mat*)src2_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        cv::subtract( src1, src2, dst, mask, (int)dtype );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_subtract_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_subtract_11
  (JNIEnv* env, jclass , jlong src1_nativeObj, jlong src2_nativeObj, jlong dst_nativeObj, jlong mask_nativeObj)
{
    static const char method_name[] = "core::subtract_11()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Mat& src2 = *((Mat*)src2_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        cv::subtract( src1, src2, dst, mask );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_subtract_12 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_subtract_12
  (JNIEnv* env, jclass , jlong src1_nativeObj, jlong src2_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "core::subtract_12()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Mat& src2 = *((Mat*)src2_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::subtract( src1, src2, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::subtract(Mat src1, Scalar src2, Mat& dst, Mat mask = Mat(), int dtype = -1)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_subtract_13 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jlong, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_subtract_13
  (JNIEnv* env, jclass , jlong src1_nativeObj, jdouble src2_val0, jdouble src2_val1, jdouble src2_val2, jdouble src2_val3, jlong dst_nativeObj, jlong mask_nativeObj, jint dtype)
{
    static const char method_name[] = "core::subtract_13()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Scalar src2(src2_val0, src2_val1, src2_val2, src2_val3);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        cv::subtract( src1, src2, dst, mask, (int)dtype );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_subtract_14 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_subtract_14
  (JNIEnv* env, jclass , jlong src1_nativeObj, jdouble src2_val0, jdouble src2_val1, jdouble src2_val2, jdouble src2_val3, jlong dst_nativeObj, jlong mask_nativeObj)
{
    static const char method_name[] = "core::subtract_14()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Scalar src2(src2_val0, src2_val1, src2_val2, src2_val3);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        cv::subtract( src1, src2, dst, mask );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_core_Core_subtract_15 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_subtract_15
  (JNIEnv* env, jclass , jlong src1_nativeObj, jdouble src2_val0, jdouble src2_val1, jdouble src2_val2, jdouble src2_val3, jlong dst_nativeObj)
{
    static const char method_name[] = "core::subtract_15()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Scalar src2(src2_val0, src2_val1, src2_val2, src2_val3);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::subtract( src1, src2, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::transform(Mat src, Mat& dst, Mat m)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_transform_10 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_transform_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jlong m_nativeObj)
{
    static const char method_name[] = "core::transform_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& m = *((Mat*)m_nativeObj);
        cv::transform( src, dst, m );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::transpose(Mat src, Mat& dst)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_transpose_10 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_transpose_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "core::transpose_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::transpose( src, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::vconcat(vector_Mat src, Mat& dst)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_vconcat_10 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_vconcat_10
  (JNIEnv* env, jclass , jlong src_mat_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "core::vconcat_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> src;
        Mat& src_mat = *((Mat*)src_mat_nativeObj);
        Mat_to_vector_Mat( src_mat, src );
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::vconcat( src, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::ipp::setUseIPP(bool flag)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_setUseIPP_10 (JNIEnv*, jclass, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_setUseIPP_10
  (JNIEnv* env, jclass , jboolean flag)
{
    static const char method_name[] = "core::setUseIPP_10()";
    try {
        LOGD("%s", method_name);
        cv::ipp::setUseIPP( (bool)flag );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::ipp::setUseIPP_NotExact(bool flag)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_setUseIPP_1NotExact_10 (JNIEnv*, jclass, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_setUseIPP_1NotExact_10
  (JNIEnv* env, jclass , jboolean flag)
{
    static const char method_name[] = "core::setUseIPP_1NotExact_10()";
    try {
        LOGD("%s", method_name);
        cv::ipp::setUseIPP_NotExact( (bool)flag );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::samples::addSamplesDataSearchPath(String path)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_addSamplesDataSearchPath_10 (JNIEnv*, jclass, jstring);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_addSamplesDataSearchPath_10
  (JNIEnv* env, jclass , jstring path)
{
    static const char method_name[] = "core::addSamplesDataSearchPath_10()";
    try {
        LOGD("%s", method_name);
        const char* utf_path = env->GetStringUTFChars(path, 0); String n_path( utf_path ? utf_path : "" ); env->ReleaseStringUTFChars(path, utf_path);
        cv::samples::addSamplesDataSearchPath( n_path );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::samples::addSamplesDataSearchSubDirectory(String subdir)
//



JNIEXPORT void JNICALL Java_org_opencv_core_Core_addSamplesDataSearchSubDirectory_10 (JNIEnv*, jclass, jstring);

JNIEXPORT void JNICALL Java_org_opencv_core_Core_addSamplesDataSearchSubDirectory_10
  (JNIEnv* env, jclass , jstring subdir)
{
    static const char method_name[] = "core::addSamplesDataSearchSubDirectory_10()";
    try {
        LOGD("%s", method_name);
        const char* utf_subdir = env->GetStringUTFChars(subdir, 0); String n_subdir( utf_subdir ? utf_subdir : "" ); env->ReleaseStringUTFChars(subdir, utf_subdir);
        cv::samples::addSamplesDataSearchSubDirectory( n_subdir );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}


// C++: minMaxLoc(Mat src, double* minVal, double* maxVal=0, Point* minLoc=0, Point* maxLoc=0, InputArray mask=noArray())
JNIEXPORT jdoubleArray JNICALL Java_org_opencv_core_Core_n_1minMaxLocManual (JNIEnv*, jclass, jlong, jlong);


JNIEXPORT jdoubleArray JNICALL Java_org_opencv_core_Core_n_1minMaxLocManual
  (JNIEnv* env, jclass, jlong src_nativeObj, jlong mask_nativeObj)
{
    try {
        LOGD("Core::n_1minMaxLoc()");
        jdoubleArray result;
        result = env->NewDoubleArray(6);
        if (result == NULL) {
            return NULL; /* out of memory error thrown */
        }


        Mat& src = *((Mat*)src_nativeObj);


        double minVal, maxVal;
        Point minLoc, maxLoc;
        if (mask_nativeObj != 0) {
            Mat& mask = *((Mat*)mask_nativeObj);
            minMaxLoc(src, &minVal, &maxVal, &minLoc, &maxLoc, mask);
        } else {
            minMaxLoc(src, &minVal, &maxVal, &minLoc, &maxLoc);
        }


        jdouble fill[6];
        fill[0]=minVal;
        fill[1]=maxVal;
        fill[2]=minLoc.x;
        fill[3]=minLoc.y;
        fill[4]=maxLoc.x;
        fill[5]=maxLoc.y;


        env->SetDoubleArrayRegion(result, 0, 6, fill);


    return result;


    } catch(const cv::Exception& e) {
        LOGD("Core::n_1minMaxLoc() caught cv::Exception: %s", e.what());
        jclass je = env->FindClass("org/opencv/core/CvException");
        if(!je) je = env->FindClass("java/lang/Exception");
        env->ThrowNew(je, e.what());
        return NULL;
    } catch (...) {
        LOGD("Core::n_1minMaxLoc() caught unknown exception (...)");
        jclass je = env->FindClass("java/lang/Exception");
        env->ThrowNew(je, "Unknown exception in JNI code {core::minMaxLoc()}");
        return NULL;
    }
}


//
//  String cv::Algorithm::getDefaultName()
//

using namespace cv;

JNIEXPORT jstring JNICALL Java_org_opencv_core_Algorithm_getDefaultName_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jstring JNICALL Java_org_opencv_core_Algorithm_getDefaultName_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "core::getDefaultName_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::Algorithm>* me = (Ptr<cv::Algorithm>*) self; //TODO: check for NULL
        cv::String _retval_ = (*me)->getDefaultName();
        return env->NewStringUTF(_retval_.c_str());
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return env->NewStringUTF("");
}



//
//  bool cv::Algorithm::empty()
//

using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_core_Algorithm_empty_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_core_Algorithm_empty_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "core::empty_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::Algorithm>* me = (Ptr<cv::Algorithm>*) self; //TODO: check for NULL
        return (*me)->empty();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::Algorithm::clear()
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_core_Algorithm_clear_10 (JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Algorithm_clear_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "core::clear_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::Algorithm>* me = (Ptr<cv::Algorithm>*) self; //TODO: check for NULL
        (*me)->clear();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::Algorithm::save(String filename)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_core_Algorithm_save_10 (JNIEnv*, jclass, jlong, jstring);

JNIEXPORT void JNICALL Java_org_opencv_core_Algorithm_save_10
  (JNIEnv* env, jclass , jlong self, jstring filename)
{
    static const char method_name[] = "core::save_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::Algorithm>* me = (Ptr<cv::Algorithm>*) self; //TODO: check for NULL
        const char* utf_filename = env->GetStringUTFChars(filename, 0); String n_filename( utf_filename ? utf_filename : "" ); env->ReleaseStringUTFChars(filename, utf_filename);
        (*me)->save( n_filename );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void Ptr<cv::Algorithm>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_core_Algorithm_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_Algorithm_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::Algorithm>*) self;
}


//
//   cv::TickMeter::TickMeter()
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_core_TickMeter_TickMeter_10 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_core_TickMeter_TickMeter_10
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "core::TickMeter_10()";
    try {
        LOGD("%s", method_name);
        cv::TickMeter* _retval_ = new cv::TickMeter();
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::TickMeter::getTimeMicro()
//

using namespace cv;

JNIEXPORT jdouble JNICALL Java_org_opencv_core_TickMeter_getTimeMicro_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_core_TickMeter_getTimeMicro_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "core::getTimeMicro_10()";
    try {
        LOGD("%s", method_name);
        cv::TickMeter* me = (cv::TickMeter*) self; //TODO: check for NULL
        return me->getTimeMicro();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::TickMeter::getTimeMilli()
//

using namespace cv;

JNIEXPORT jdouble JNICALL Java_org_opencv_core_TickMeter_getTimeMilli_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_core_TickMeter_getTimeMilli_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "core::getTimeMilli_10()";
    try {
        LOGD("%s", method_name);
        cv::TickMeter* me = (cv::TickMeter*) self; //TODO: check for NULL
        return me->getTimeMilli();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::TickMeter::getTimeSec()
//

using namespace cv;

JNIEXPORT jdouble JNICALL Java_org_opencv_core_TickMeter_getTimeSec_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_core_TickMeter_getTimeSec_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "core::getTimeSec_10()";
    try {
        LOGD("%s", method_name);
        cv::TickMeter* me = (cv::TickMeter*) self; //TODO: check for NULL
        return me->getTimeSec();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int64 cv::TickMeter::getCounter()
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_core_TickMeter_getCounter_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_core_TickMeter_getCounter_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "core::getCounter_10()";
    try {
        LOGD("%s", method_name);
        cv::TickMeter* me = (cv::TickMeter*) self; //TODO: check for NULL
        return me->getCounter();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int64 cv::TickMeter::getTimeTicks()
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_core_TickMeter_getTimeTicks_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_core_TickMeter_getTimeTicks_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "core::getTimeTicks_10()";
    try {
        LOGD("%s", method_name);
        cv::TickMeter* me = (cv::TickMeter*) self; //TODO: check for NULL
        return me->getTimeTicks();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::TickMeter::reset()
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_core_TickMeter_reset_10 (JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_TickMeter_reset_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "core::reset_10()";
    try {
        LOGD("%s", method_name);
        cv::TickMeter* me = (cv::TickMeter*) self; //TODO: check for NULL
        me->reset();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::TickMeter::start()
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_core_TickMeter_start_10 (JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_TickMeter_start_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "core::start_10()";
    try {
        LOGD("%s", method_name);
        cv::TickMeter* me = (cv::TickMeter*) self; //TODO: check for NULL
        me->start();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::TickMeter::stop()
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_core_TickMeter_stop_10 (JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_TickMeter_stop_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "core::stop_10()";
    try {
        LOGD("%s", method_name);
        cv::TickMeter* me = (cv::TickMeter*) self; //TODO: check for NULL
        me->stop();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void cv::TickMeter::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_core_TickMeter_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_core_TickMeter_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (cv::TickMeter*) self;
}



} // extern "C"

#endif // HAVE_OPENCV_CORE
