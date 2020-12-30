//
// This file is auto-generated. Please don't modify it!
//

#undef LOG_TAG

#include "opencv2/opencv_modules.hpp"
#ifdef HAVE_OPENCV_OBJDETECT

#include <string>

#include "opencv2/objdetect.hpp"

#include "/Users/virtualman/Downloads/MySource/opencv-4.3.0/modules/objdetect/include/opencv2/objdetect.hpp"
#include "/Users/virtualman/Downloads/MySource/opencv-4.3.0/modules/objdetect/include/opencv2/objdetect/detection_based_tracker.hpp"

#define LOG_TAG "org.opencv.objdetect"
#include "common.h"

using namespace cv;

/// throw java exception
#undef throwJavaException
#define throwJavaException throwJavaException_objdetect
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
//   cv::HOGDescriptor::HOGDescriptor(Size _winSize, Size _blockSize, Size _blockStride, Size _cellSize, int _nbins, int _derivAperture = 1, double _winSigma = -1, HOGDescriptor_HistogramNormType _histogramNormType = HOGDescriptor::L2Hys, double _L2HysThreshold = 0.2, bool _gammaCorrection = false, int _nlevels = HOGDescriptor::DEFAULT_NLEVELS, bool _signedGradient = false)
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_objdetect_HOGDescriptor_HOGDescriptor_10 (JNIEnv*, jclass, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jint, jint, jdouble, jint, jdouble, jboolean, jint, jboolean);

JNIEXPORT jlong JNICALL Java_org_opencv_objdetect_HOGDescriptor_HOGDescriptor_10
  (JNIEnv* env, jclass , jdouble _winSize_width, jdouble _winSize_height, jdouble _blockSize_width, jdouble _blockSize_height, jdouble _blockStride_width, jdouble _blockStride_height, jdouble _cellSize_width, jdouble _cellSize_height, jint _nbins, jint _derivAperture, jdouble _winSigma, jint _histogramNormType, jdouble _L2HysThreshold, jboolean _gammaCorrection, jint _nlevels, jboolean _signedGradient)
{
    static const char method_name[] = "objdetect::HOGDescriptor_10()";
    try {
        LOGD("%s", method_name);
        Size _winSize((int)_winSize_width, (int)_winSize_height);
        Size _blockSize((int)_blockSize_width, (int)_blockSize_height);
        Size _blockStride((int)_blockStride_width, (int)_blockStride_height);
        Size _cellSize((int)_cellSize_width, (int)_cellSize_height);
        cv::HOGDescriptor* _retval_ = new cv::HOGDescriptor( _winSize, _blockSize, _blockStride, _cellSize, (int)_nbins, (int)_derivAperture, (double)_winSigma, (cv::HOGDescriptor::HistogramNormType)_histogramNormType, (double)_L2HysThreshold, (bool)_gammaCorrection, (int)_nlevels, (bool)_signedGradient );
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_objdetect_HOGDescriptor_HOGDescriptor_11 (JNIEnv*, jclass, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jint, jint, jdouble, jint, jdouble, jboolean, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_objdetect_HOGDescriptor_HOGDescriptor_11
  (JNIEnv* env, jclass , jdouble _winSize_width, jdouble _winSize_height, jdouble _blockSize_width, jdouble _blockSize_height, jdouble _blockStride_width, jdouble _blockStride_height, jdouble _cellSize_width, jdouble _cellSize_height, jint _nbins, jint _derivAperture, jdouble _winSigma, jint _histogramNormType, jdouble _L2HysThreshold, jboolean _gammaCorrection, jint _nlevels)
{
    static const char method_name[] = "objdetect::HOGDescriptor_11()";
    try {
        LOGD("%s", method_name);
        Size _winSize((int)_winSize_width, (int)_winSize_height);
        Size _blockSize((int)_blockSize_width, (int)_blockSize_height);
        Size _blockStride((int)_blockStride_width, (int)_blockStride_height);
        Size _cellSize((int)_cellSize_width, (int)_cellSize_height);
        cv::HOGDescriptor* _retval_ = new cv::HOGDescriptor( _winSize, _blockSize, _blockStride, _cellSize, (int)_nbins, (int)_derivAperture, (double)_winSigma, (cv::HOGDescriptor::HistogramNormType)_histogramNormType, (double)_L2HysThreshold, (bool)_gammaCorrection, (int)_nlevels );
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_objdetect_HOGDescriptor_HOGDescriptor_12 (JNIEnv*, jclass, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jint, jint, jdouble, jint, jdouble, jboolean);

JNIEXPORT jlong JNICALL Java_org_opencv_objdetect_HOGDescriptor_HOGDescriptor_12
  (JNIEnv* env, jclass , jdouble _winSize_width, jdouble _winSize_height, jdouble _blockSize_width, jdouble _blockSize_height, jdouble _blockStride_width, jdouble _blockStride_height, jdouble _cellSize_width, jdouble _cellSize_height, jint _nbins, jint _derivAperture, jdouble _winSigma, jint _histogramNormType, jdouble _L2HysThreshold, jboolean _gammaCorrection)
{
    static const char method_name[] = "objdetect::HOGDescriptor_12()";
    try {
        LOGD("%s", method_name);
        Size _winSize((int)_winSize_width, (int)_winSize_height);
        Size _blockSize((int)_blockSize_width, (int)_blockSize_height);
        Size _blockStride((int)_blockStride_width, (int)_blockStride_height);
        Size _cellSize((int)_cellSize_width, (int)_cellSize_height);
        cv::HOGDescriptor* _retval_ = new cv::HOGDescriptor( _winSize, _blockSize, _blockStride, _cellSize, (int)_nbins, (int)_derivAperture, (double)_winSigma, (cv::HOGDescriptor::HistogramNormType)_histogramNormType, (double)_L2HysThreshold, (bool)_gammaCorrection );
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_objdetect_HOGDescriptor_HOGDescriptor_13 (JNIEnv*, jclass, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jint, jint, jdouble, jint, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_objdetect_HOGDescriptor_HOGDescriptor_13
  (JNIEnv* env, jclass , jdouble _winSize_width, jdouble _winSize_height, jdouble _blockSize_width, jdouble _blockSize_height, jdouble _blockStride_width, jdouble _blockStride_height, jdouble _cellSize_width, jdouble _cellSize_height, jint _nbins, jint _derivAperture, jdouble _winSigma, jint _histogramNormType, jdouble _L2HysThreshold)
{
    static const char method_name[] = "objdetect::HOGDescriptor_13()";
    try {
        LOGD("%s", method_name);
        Size _winSize((int)_winSize_width, (int)_winSize_height);
        Size _blockSize((int)_blockSize_width, (int)_blockSize_height);
        Size _blockStride((int)_blockStride_width, (int)_blockStride_height);
        Size _cellSize((int)_cellSize_width, (int)_cellSize_height);
        cv::HOGDescriptor* _retval_ = new cv::HOGDescriptor( _winSize, _blockSize, _blockStride, _cellSize, (int)_nbins, (int)_derivAperture, (double)_winSigma, (cv::HOGDescriptor::HistogramNormType)_histogramNormType, (double)_L2HysThreshold );
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_objdetect_HOGDescriptor_HOGDescriptor_14 (JNIEnv*, jclass, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jint, jint, jdouble, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_objdetect_HOGDescriptor_HOGDescriptor_14
  (JNIEnv* env, jclass , jdouble _winSize_width, jdouble _winSize_height, jdouble _blockSize_width, jdouble _blockSize_height, jdouble _blockStride_width, jdouble _blockStride_height, jdouble _cellSize_width, jdouble _cellSize_height, jint _nbins, jint _derivAperture, jdouble _winSigma, jint _histogramNormType)
{
    static const char method_name[] = "objdetect::HOGDescriptor_14()";
    try {
        LOGD("%s", method_name);
        Size _winSize((int)_winSize_width, (int)_winSize_height);
        Size _blockSize((int)_blockSize_width, (int)_blockSize_height);
        Size _blockStride((int)_blockStride_width, (int)_blockStride_height);
        Size _cellSize((int)_cellSize_width, (int)_cellSize_height);
        cv::HOGDescriptor* _retval_ = new cv::HOGDescriptor( _winSize, _blockSize, _blockStride, _cellSize, (int)_nbins, (int)_derivAperture, (double)_winSigma, (cv::HOGDescriptor::HistogramNormType)_histogramNormType );
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_objdetect_HOGDescriptor_HOGDescriptor_15 (JNIEnv*, jclass, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jint, jint, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_objdetect_HOGDescriptor_HOGDescriptor_15
  (JNIEnv* env, jclass , jdouble _winSize_width, jdouble _winSize_height, jdouble _blockSize_width, jdouble _blockSize_height, jdouble _blockStride_width, jdouble _blockStride_height, jdouble _cellSize_width, jdouble _cellSize_height, jint _nbins, jint _derivAperture, jdouble _winSigma)
{
    static const char method_name[] = "objdetect::HOGDescriptor_15()";
    try {
        LOGD("%s", method_name);
        Size _winSize((int)_winSize_width, (int)_winSize_height);
        Size _blockSize((int)_blockSize_width, (int)_blockSize_height);
        Size _blockStride((int)_blockStride_width, (int)_blockStride_height);
        Size _cellSize((int)_cellSize_width, (int)_cellSize_height);
        cv::HOGDescriptor* _retval_ = new cv::HOGDescriptor( _winSize, _blockSize, _blockStride, _cellSize, (int)_nbins, (int)_derivAperture, (double)_winSigma );
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_objdetect_HOGDescriptor_HOGDescriptor_16 (JNIEnv*, jclass, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jint, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_objdetect_HOGDescriptor_HOGDescriptor_16
  (JNIEnv* env, jclass , jdouble _winSize_width, jdouble _winSize_height, jdouble _blockSize_width, jdouble _blockSize_height, jdouble _blockStride_width, jdouble _blockStride_height, jdouble _cellSize_width, jdouble _cellSize_height, jint _nbins, jint _derivAperture)
{
    static const char method_name[] = "objdetect::HOGDescriptor_16()";
    try {
        LOGD("%s", method_name);
        Size _winSize((int)_winSize_width, (int)_winSize_height);
        Size _blockSize((int)_blockSize_width, (int)_blockSize_height);
        Size _blockStride((int)_blockStride_width, (int)_blockStride_height);
        Size _cellSize((int)_cellSize_width, (int)_cellSize_height);
        cv::HOGDescriptor* _retval_ = new cv::HOGDescriptor( _winSize, _blockSize, _blockStride, _cellSize, (int)_nbins, (int)_derivAperture );
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_objdetect_HOGDescriptor_HOGDescriptor_17 (JNIEnv*, jclass, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_objdetect_HOGDescriptor_HOGDescriptor_17
  (JNIEnv* env, jclass , jdouble _winSize_width, jdouble _winSize_height, jdouble _blockSize_width, jdouble _blockSize_height, jdouble _blockStride_width, jdouble _blockStride_height, jdouble _cellSize_width, jdouble _cellSize_height, jint _nbins)
{
    static const char method_name[] = "objdetect::HOGDescriptor_17()";
    try {
        LOGD("%s", method_name);
        Size _winSize((int)_winSize_width, (int)_winSize_height);
        Size _blockSize((int)_blockSize_width, (int)_blockSize_height);
        Size _blockStride((int)_blockStride_width, (int)_blockStride_height);
        Size _cellSize((int)_cellSize_width, (int)_cellSize_height);
        cv::HOGDescriptor* _retval_ = new cv::HOGDescriptor( _winSize, _blockSize, _blockStride, _cellSize, (int)_nbins );
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//   cv::HOGDescriptor::HOGDescriptor(String filename)
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_objdetect_HOGDescriptor_HOGDescriptor_18 (JNIEnv*, jclass, jstring);

JNIEXPORT jlong JNICALL Java_org_opencv_objdetect_HOGDescriptor_HOGDescriptor_18
  (JNIEnv* env, jclass , jstring filename)
{
    static const char method_name[] = "objdetect::HOGDescriptor_18()";
    try {
        LOGD("%s", method_name);
        const char* utf_filename = env->GetStringUTFChars(filename, 0); String n_filename( utf_filename ? utf_filename : "" ); env->ReleaseStringUTFChars(filename, utf_filename);
        cv::HOGDescriptor* _retval_ = new cv::HOGDescriptor( n_filename );
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//   cv::HOGDescriptor::HOGDescriptor()
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_objdetect_HOGDescriptor_HOGDescriptor_19 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_objdetect_HOGDescriptor_HOGDescriptor_19
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "objdetect::HOGDescriptor_19()";
    try {
        LOGD("%s", method_name);
        cv::HOGDescriptor* _retval_ = new cv::HOGDescriptor();
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  bool cv::HOGDescriptor::checkDetectorSize()
//

using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_objdetect_HOGDescriptor_checkDetectorSize_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_objdetect_HOGDescriptor_checkDetectorSize_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "objdetect::checkDetectorSize_10()";
    try {
        LOGD("%s", method_name);
        cv::HOGDescriptor* me = (cv::HOGDescriptor*) self; //TODO: check for NULL
        return me->checkDetectorSize();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  bool cv::HOGDescriptor::load(String filename, String objname = String())
//

using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_objdetect_HOGDescriptor_load_10 (JNIEnv*, jclass, jlong, jstring, jstring);

JNIEXPORT jboolean JNICALL Java_org_opencv_objdetect_HOGDescriptor_load_10
  (JNIEnv* env, jclass , jlong self, jstring filename, jstring objname)
{
    static const char method_name[] = "objdetect::load_10()";
    try {
        LOGD("%s", method_name);
        cv::HOGDescriptor* me = (cv::HOGDescriptor*) self; //TODO: check for NULL
        const char* utf_filename = env->GetStringUTFChars(filename, 0); String n_filename( utf_filename ? utf_filename : "" ); env->ReleaseStringUTFChars(filename, utf_filename);
        const char* utf_objname = env->GetStringUTFChars(objname, 0); String n_objname( utf_objname ? utf_objname : "" ); env->ReleaseStringUTFChars(objname, utf_objname);
        return me->load( n_filename, n_objname );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_objdetect_HOGDescriptor_load_11 (JNIEnv*, jclass, jlong, jstring);

JNIEXPORT jboolean JNICALL Java_org_opencv_objdetect_HOGDescriptor_load_11
  (JNIEnv* env, jclass , jlong self, jstring filename)
{
    static const char method_name[] = "objdetect::load_11()";
    try {
        LOGD("%s", method_name);
        cv::HOGDescriptor* me = (cv::HOGDescriptor*) self; //TODO: check for NULL
        const char* utf_filename = env->GetStringUTFChars(filename, 0); String n_filename( utf_filename ? utf_filename : "" ); env->ReleaseStringUTFChars(filename, utf_filename);
        return me->load( n_filename );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::HOGDescriptor::getWinSigma()
//

using namespace cv;

JNIEXPORT jdouble JNICALL Java_org_opencv_objdetect_HOGDescriptor_getWinSigma_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_objdetect_HOGDescriptor_getWinSigma_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "objdetect::getWinSigma_10()";
    try {
        LOGD("%s", method_name);
        cv::HOGDescriptor* me = (cv::HOGDescriptor*) self; //TODO: check for NULL
        return me->getWinSigma();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  size_t cv::HOGDescriptor::getDescriptorSize()
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_objdetect_HOGDescriptor_getDescriptorSize_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_objdetect_HOGDescriptor_getDescriptorSize_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "objdetect::getDescriptorSize_10()";
    try {
        LOGD("%s", method_name);
        cv::HOGDescriptor* me = (cv::HOGDescriptor*) self; //TODO: check for NULL
        return me->getDescriptorSize();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// static vector_float cv::HOGDescriptor::getDaimlerPeopleDetector()
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_objdetect_HOGDescriptor_getDaimlerPeopleDetector_10 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_objdetect_HOGDescriptor_getDaimlerPeopleDetector_10
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "objdetect::getDaimlerPeopleDetector_10()";
    try {
        LOGD("%s", method_name);
        std::vector<float> _ret_val_vector_ = cv::HOGDescriptor::getDaimlerPeopleDetector();
        Mat* _retval_ = new Mat();
        vector_float_to_Mat(_ret_val_vector_, *_retval_);
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// static vector_float cv::HOGDescriptor::getDefaultPeopleDetector()
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_objdetect_HOGDescriptor_getDefaultPeopleDetector_10 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_objdetect_HOGDescriptor_getDefaultPeopleDetector_10
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "objdetect::getDefaultPeopleDetector_10()";
    try {
        LOGD("%s", method_name);
        std::vector<float> _ret_val_vector_ = cv::HOGDescriptor::getDefaultPeopleDetector();
        Mat* _retval_ = new Mat();
        vector_float_to_Mat(_ret_val_vector_, *_retval_);
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::HOGDescriptor::compute(Mat img, vector_float& descriptors, Size winStride = Size(), Size padding = Size(), vector_Point locations = std::vector<Point>())
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_objdetect_HOGDescriptor_compute_10 (JNIEnv*, jclass, jlong, jlong, jlong, jdouble, jdouble, jdouble, jdouble, jlong);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_HOGDescriptor_compute_10
  (JNIEnv* env, jclass , jlong self, jlong img_nativeObj, jlong descriptors_mat_nativeObj, jdouble winStride_width, jdouble winStride_height, jdouble padding_width, jdouble padding_height, jlong locations_mat_nativeObj)
{
    static const char method_name[] = "objdetect::compute_10()";
    try {
        LOGD("%s", method_name);
        std::vector<float> descriptors;
        Mat& descriptors_mat = *((Mat*)descriptors_mat_nativeObj);
        std::vector<Point> locations;
        Mat& locations_mat = *((Mat*)locations_mat_nativeObj);
        Mat_to_vector_Point( locations_mat, locations );
        cv::HOGDescriptor* me = (cv::HOGDescriptor*) self; //TODO: check for NULL
        Mat& img = *((Mat*)img_nativeObj);
        Size winStride((int)winStride_width, (int)winStride_height);
        Size padding((int)padding_width, (int)padding_height);
        me->compute( img, descriptors, winStride, padding, locations );
        vector_float_to_Mat( descriptors, descriptors_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_objdetect_HOGDescriptor_compute_11 (JNIEnv*, jclass, jlong, jlong, jlong, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_HOGDescriptor_compute_11
  (JNIEnv* env, jclass , jlong self, jlong img_nativeObj, jlong descriptors_mat_nativeObj, jdouble winStride_width, jdouble winStride_height, jdouble padding_width, jdouble padding_height)
{
    static const char method_name[] = "objdetect::compute_11()";
    try {
        LOGD("%s", method_name);
        std::vector<float> descriptors;
        Mat& descriptors_mat = *((Mat*)descriptors_mat_nativeObj);
        cv::HOGDescriptor* me = (cv::HOGDescriptor*) self; //TODO: check for NULL
        Mat& img = *((Mat*)img_nativeObj);
        Size winStride((int)winStride_width, (int)winStride_height);
        Size padding((int)padding_width, (int)padding_height);
        me->compute( img, descriptors, winStride, padding );
        vector_float_to_Mat( descriptors, descriptors_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_objdetect_HOGDescriptor_compute_12 (JNIEnv*, jclass, jlong, jlong, jlong, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_HOGDescriptor_compute_12
  (JNIEnv* env, jclass , jlong self, jlong img_nativeObj, jlong descriptors_mat_nativeObj, jdouble winStride_width, jdouble winStride_height)
{
    static const char method_name[] = "objdetect::compute_12()";
    try {
        LOGD("%s", method_name);
        std::vector<float> descriptors;
        Mat& descriptors_mat = *((Mat*)descriptors_mat_nativeObj);
        cv::HOGDescriptor* me = (cv::HOGDescriptor*) self; //TODO: check for NULL
        Mat& img = *((Mat*)img_nativeObj);
        Size winStride((int)winStride_width, (int)winStride_height);
        me->compute( img, descriptors, winStride );
        vector_float_to_Mat( descriptors, descriptors_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_objdetect_HOGDescriptor_compute_13 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_HOGDescriptor_compute_13
  (JNIEnv* env, jclass , jlong self, jlong img_nativeObj, jlong descriptors_mat_nativeObj)
{
    static const char method_name[] = "objdetect::compute_13()";
    try {
        LOGD("%s", method_name);
        std::vector<float> descriptors;
        Mat& descriptors_mat = *((Mat*)descriptors_mat_nativeObj);
        cv::HOGDescriptor* me = (cv::HOGDescriptor*) self; //TODO: check for NULL
        Mat& img = *((Mat*)img_nativeObj);
        me->compute( img, descriptors );
        vector_float_to_Mat( descriptors, descriptors_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::HOGDescriptor::computeGradient(Mat img, Mat& grad, Mat& angleOfs, Size paddingTL = Size(), Size paddingBR = Size())
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_objdetect_HOGDescriptor_computeGradient_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_HOGDescriptor_computeGradient_10
  (JNIEnv* env, jclass , jlong self, jlong img_nativeObj, jlong grad_nativeObj, jlong angleOfs_nativeObj, jdouble paddingTL_width, jdouble paddingTL_height, jdouble paddingBR_width, jdouble paddingBR_height)
{
    static const char method_name[] = "objdetect::computeGradient_10()";
    try {
        LOGD("%s", method_name);
        cv::HOGDescriptor* me = (cv::HOGDescriptor*) self; //TODO: check for NULL
        Mat& img = *((Mat*)img_nativeObj);
        Mat& grad = *((Mat*)grad_nativeObj);
        Mat& angleOfs = *((Mat*)angleOfs_nativeObj);
        Size paddingTL((int)paddingTL_width, (int)paddingTL_height);
        Size paddingBR((int)paddingBR_width, (int)paddingBR_height);
        me->computeGradient( img, grad, angleOfs, paddingTL, paddingBR );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_objdetect_HOGDescriptor_computeGradient_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_HOGDescriptor_computeGradient_11
  (JNIEnv* env, jclass , jlong self, jlong img_nativeObj, jlong grad_nativeObj, jlong angleOfs_nativeObj, jdouble paddingTL_width, jdouble paddingTL_height)
{
    static const char method_name[] = "objdetect::computeGradient_11()";
    try {
        LOGD("%s", method_name);
        cv::HOGDescriptor* me = (cv::HOGDescriptor*) self; //TODO: check for NULL
        Mat& img = *((Mat*)img_nativeObj);
        Mat& grad = *((Mat*)grad_nativeObj);
        Mat& angleOfs = *((Mat*)angleOfs_nativeObj);
        Size paddingTL((int)paddingTL_width, (int)paddingTL_height);
        me->computeGradient( img, grad, angleOfs, paddingTL );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_objdetect_HOGDescriptor_computeGradient_12 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_HOGDescriptor_computeGradient_12
  (JNIEnv* env, jclass , jlong self, jlong img_nativeObj, jlong grad_nativeObj, jlong angleOfs_nativeObj)
{
    static const char method_name[] = "objdetect::computeGradient_12()";
    try {
        LOGD("%s", method_name);
        cv::HOGDescriptor* me = (cv::HOGDescriptor*) self; //TODO: check for NULL
        Mat& img = *((Mat*)img_nativeObj);
        Mat& grad = *((Mat*)grad_nativeObj);
        Mat& angleOfs = *((Mat*)angleOfs_nativeObj);
        me->computeGradient( img, grad, angleOfs );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::HOGDescriptor::detect(Mat img, vector_Point& foundLocations, vector_double& weights, double hitThreshold = 0, Size winStride = Size(), Size padding = Size(), vector_Point searchLocations = std::vector<Point>())
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_objdetect_HOGDescriptor_detect_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jlong);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_HOGDescriptor_detect_10
  (JNIEnv* env, jclass , jlong self, jlong img_nativeObj, jlong foundLocations_mat_nativeObj, jlong weights_mat_nativeObj, jdouble hitThreshold, jdouble winStride_width, jdouble winStride_height, jdouble padding_width, jdouble padding_height, jlong searchLocations_mat_nativeObj)
{
    static const char method_name[] = "objdetect::detect_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Point> foundLocations;
        Mat& foundLocations_mat = *((Mat*)foundLocations_mat_nativeObj);
        std::vector<double> weights;
        Mat& weights_mat = *((Mat*)weights_mat_nativeObj);
        std::vector<Point> searchLocations;
        Mat& searchLocations_mat = *((Mat*)searchLocations_mat_nativeObj);
        Mat_to_vector_Point( searchLocations_mat, searchLocations );
        cv::HOGDescriptor* me = (cv::HOGDescriptor*) self; //TODO: check for NULL
        Mat& img = *((Mat*)img_nativeObj);
        Size winStride((int)winStride_width, (int)winStride_height);
        Size padding((int)padding_width, (int)padding_height);
        me->detect( img, foundLocations, weights, (double)hitThreshold, winStride, padding, searchLocations );
        vector_Point_to_Mat( foundLocations, foundLocations_mat );
        vector_double_to_Mat( weights, weights_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_objdetect_HOGDescriptor_detect_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jdouble, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_HOGDescriptor_detect_11
  (JNIEnv* env, jclass , jlong self, jlong img_nativeObj, jlong foundLocations_mat_nativeObj, jlong weights_mat_nativeObj, jdouble hitThreshold, jdouble winStride_width, jdouble winStride_height, jdouble padding_width, jdouble padding_height)
{
    static const char method_name[] = "objdetect::detect_11()";
    try {
        LOGD("%s", method_name);
        std::vector<Point> foundLocations;
        Mat& foundLocations_mat = *((Mat*)foundLocations_mat_nativeObj);
        std::vector<double> weights;
        Mat& weights_mat = *((Mat*)weights_mat_nativeObj);
        cv::HOGDescriptor* me = (cv::HOGDescriptor*) self; //TODO: check for NULL
        Mat& img = *((Mat*)img_nativeObj);
        Size winStride((int)winStride_width, (int)winStride_height);
        Size padding((int)padding_width, (int)padding_height);
        me->detect( img, foundLocations, weights, (double)hitThreshold, winStride, padding );
        vector_Point_to_Mat( foundLocations, foundLocations_mat );
        vector_double_to_Mat( weights, weights_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_objdetect_HOGDescriptor_detect_12 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_HOGDescriptor_detect_12
  (JNIEnv* env, jclass , jlong self, jlong img_nativeObj, jlong foundLocations_mat_nativeObj, jlong weights_mat_nativeObj, jdouble hitThreshold, jdouble winStride_width, jdouble winStride_height)
{
    static const char method_name[] = "objdetect::detect_12()";
    try {
        LOGD("%s", method_name);
        std::vector<Point> foundLocations;
        Mat& foundLocations_mat = *((Mat*)foundLocations_mat_nativeObj);
        std::vector<double> weights;
        Mat& weights_mat = *((Mat*)weights_mat_nativeObj);
        cv::HOGDescriptor* me = (cv::HOGDescriptor*) self; //TODO: check for NULL
        Mat& img = *((Mat*)img_nativeObj);
        Size winStride((int)winStride_width, (int)winStride_height);
        me->detect( img, foundLocations, weights, (double)hitThreshold, winStride );
        vector_Point_to_Mat( foundLocations, foundLocations_mat );
        vector_double_to_Mat( weights, weights_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_objdetect_HOGDescriptor_detect_13 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_HOGDescriptor_detect_13
  (JNIEnv* env, jclass , jlong self, jlong img_nativeObj, jlong foundLocations_mat_nativeObj, jlong weights_mat_nativeObj, jdouble hitThreshold)
{
    static const char method_name[] = "objdetect::detect_13()";
    try {
        LOGD("%s", method_name);
        std::vector<Point> foundLocations;
        Mat& foundLocations_mat = *((Mat*)foundLocations_mat_nativeObj);
        std::vector<double> weights;
        Mat& weights_mat = *((Mat*)weights_mat_nativeObj);
        cv::HOGDescriptor* me = (cv::HOGDescriptor*) self; //TODO: check for NULL
        Mat& img = *((Mat*)img_nativeObj);
        me->detect( img, foundLocations, weights, (double)hitThreshold );
        vector_Point_to_Mat( foundLocations, foundLocations_mat );
        vector_double_to_Mat( weights, weights_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_objdetect_HOGDescriptor_detect_14 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_HOGDescriptor_detect_14
  (JNIEnv* env, jclass , jlong self, jlong img_nativeObj, jlong foundLocations_mat_nativeObj, jlong weights_mat_nativeObj)
{
    static const char method_name[] = "objdetect::detect_14()";
    try {
        LOGD("%s", method_name);
        std::vector<Point> foundLocations;
        Mat& foundLocations_mat = *((Mat*)foundLocations_mat_nativeObj);
        std::vector<double> weights;
        Mat& weights_mat = *((Mat*)weights_mat_nativeObj);
        cv::HOGDescriptor* me = (cv::HOGDescriptor*) self; //TODO: check for NULL
        Mat& img = *((Mat*)img_nativeObj);
        me->detect( img, foundLocations, weights );
        vector_Point_to_Mat( foundLocations, foundLocations_mat );
        vector_double_to_Mat( weights, weights_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::HOGDescriptor::detectMultiScale(Mat img, vector_Rect& foundLocations, vector_double& foundWeights, double hitThreshold = 0, Size winStride = Size(), Size padding = Size(), double scale = 1.05, double finalThreshold = 2.0, bool useMeanshiftGrouping = false)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_objdetect_HOGDescriptor_detectMultiScale_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_HOGDescriptor_detectMultiScale_10
  (JNIEnv* env, jclass , jlong self, jlong img_nativeObj, jlong foundLocations_mat_nativeObj, jlong foundWeights_mat_nativeObj, jdouble hitThreshold, jdouble winStride_width, jdouble winStride_height, jdouble padding_width, jdouble padding_height, jdouble scale, jdouble finalThreshold, jboolean useMeanshiftGrouping)
{
    static const char method_name[] = "objdetect::detectMultiScale_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Rect> foundLocations;
        Mat& foundLocations_mat = *((Mat*)foundLocations_mat_nativeObj);
        std::vector<double> foundWeights;
        Mat& foundWeights_mat = *((Mat*)foundWeights_mat_nativeObj);
        cv::HOGDescriptor* me = (cv::HOGDescriptor*) self; //TODO: check for NULL
        Mat& img = *((Mat*)img_nativeObj);
        Size winStride((int)winStride_width, (int)winStride_height);
        Size padding((int)padding_width, (int)padding_height);
        me->detectMultiScale( img, foundLocations, foundWeights, (double)hitThreshold, winStride, padding, (double)scale, (double)finalThreshold, (bool)useMeanshiftGrouping );
        vector_Rect_to_Mat( foundLocations, foundLocations_mat );
        vector_double_to_Mat( foundWeights, foundWeights_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_objdetect_HOGDescriptor_detectMultiScale_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_HOGDescriptor_detectMultiScale_11
  (JNIEnv* env, jclass , jlong self, jlong img_nativeObj, jlong foundLocations_mat_nativeObj, jlong foundWeights_mat_nativeObj, jdouble hitThreshold, jdouble winStride_width, jdouble winStride_height, jdouble padding_width, jdouble padding_height, jdouble scale, jdouble finalThreshold)
{
    static const char method_name[] = "objdetect::detectMultiScale_11()";
    try {
        LOGD("%s", method_name);
        std::vector<Rect> foundLocations;
        Mat& foundLocations_mat = *((Mat*)foundLocations_mat_nativeObj);
        std::vector<double> foundWeights;
        Mat& foundWeights_mat = *((Mat*)foundWeights_mat_nativeObj);
        cv::HOGDescriptor* me = (cv::HOGDescriptor*) self; //TODO: check for NULL
        Mat& img = *((Mat*)img_nativeObj);
        Size winStride((int)winStride_width, (int)winStride_height);
        Size padding((int)padding_width, (int)padding_height);
        me->detectMultiScale( img, foundLocations, foundWeights, (double)hitThreshold, winStride, padding, (double)scale, (double)finalThreshold );
        vector_Rect_to_Mat( foundLocations, foundLocations_mat );
        vector_double_to_Mat( foundWeights, foundWeights_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_objdetect_HOGDescriptor_detectMultiScale_12 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_HOGDescriptor_detectMultiScale_12
  (JNIEnv* env, jclass , jlong self, jlong img_nativeObj, jlong foundLocations_mat_nativeObj, jlong foundWeights_mat_nativeObj, jdouble hitThreshold, jdouble winStride_width, jdouble winStride_height, jdouble padding_width, jdouble padding_height, jdouble scale)
{
    static const char method_name[] = "objdetect::detectMultiScale_12()";
    try {
        LOGD("%s", method_name);
        std::vector<Rect> foundLocations;
        Mat& foundLocations_mat = *((Mat*)foundLocations_mat_nativeObj);
        std::vector<double> foundWeights;
        Mat& foundWeights_mat = *((Mat*)foundWeights_mat_nativeObj);
        cv::HOGDescriptor* me = (cv::HOGDescriptor*) self; //TODO: check for NULL
        Mat& img = *((Mat*)img_nativeObj);
        Size winStride((int)winStride_width, (int)winStride_height);
        Size padding((int)padding_width, (int)padding_height);
        me->detectMultiScale( img, foundLocations, foundWeights, (double)hitThreshold, winStride, padding, (double)scale );
        vector_Rect_to_Mat( foundLocations, foundLocations_mat );
        vector_double_to_Mat( foundWeights, foundWeights_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_objdetect_HOGDescriptor_detectMultiScale_13 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jdouble, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_HOGDescriptor_detectMultiScale_13
  (JNIEnv* env, jclass , jlong self, jlong img_nativeObj, jlong foundLocations_mat_nativeObj, jlong foundWeights_mat_nativeObj, jdouble hitThreshold, jdouble winStride_width, jdouble winStride_height, jdouble padding_width, jdouble padding_height)
{
    static const char method_name[] = "objdetect::detectMultiScale_13()";
    try {
        LOGD("%s", method_name);
        std::vector<Rect> foundLocations;
        Mat& foundLocations_mat = *((Mat*)foundLocations_mat_nativeObj);
        std::vector<double> foundWeights;
        Mat& foundWeights_mat = *((Mat*)foundWeights_mat_nativeObj);
        cv::HOGDescriptor* me = (cv::HOGDescriptor*) self; //TODO: check for NULL
        Mat& img = *((Mat*)img_nativeObj);
        Size winStride((int)winStride_width, (int)winStride_height);
        Size padding((int)padding_width, (int)padding_height);
        me->detectMultiScale( img, foundLocations, foundWeights, (double)hitThreshold, winStride, padding );
        vector_Rect_to_Mat( foundLocations, foundLocations_mat );
        vector_double_to_Mat( foundWeights, foundWeights_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_objdetect_HOGDescriptor_detectMultiScale_14 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_HOGDescriptor_detectMultiScale_14
  (JNIEnv* env, jclass , jlong self, jlong img_nativeObj, jlong foundLocations_mat_nativeObj, jlong foundWeights_mat_nativeObj, jdouble hitThreshold, jdouble winStride_width, jdouble winStride_height)
{
    static const char method_name[] = "objdetect::detectMultiScale_14()";
    try {
        LOGD("%s", method_name);
        std::vector<Rect> foundLocations;
        Mat& foundLocations_mat = *((Mat*)foundLocations_mat_nativeObj);
        std::vector<double> foundWeights;
        Mat& foundWeights_mat = *((Mat*)foundWeights_mat_nativeObj);
        cv::HOGDescriptor* me = (cv::HOGDescriptor*) self; //TODO: check for NULL
        Mat& img = *((Mat*)img_nativeObj);
        Size winStride((int)winStride_width, (int)winStride_height);
        me->detectMultiScale( img, foundLocations, foundWeights, (double)hitThreshold, winStride );
        vector_Rect_to_Mat( foundLocations, foundLocations_mat );
        vector_double_to_Mat( foundWeights, foundWeights_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_objdetect_HOGDescriptor_detectMultiScale_15 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_HOGDescriptor_detectMultiScale_15
  (JNIEnv* env, jclass , jlong self, jlong img_nativeObj, jlong foundLocations_mat_nativeObj, jlong foundWeights_mat_nativeObj, jdouble hitThreshold)
{
    static const char method_name[] = "objdetect::detectMultiScale_15()";
    try {
        LOGD("%s", method_name);
        std::vector<Rect> foundLocations;
        Mat& foundLocations_mat = *((Mat*)foundLocations_mat_nativeObj);
        std::vector<double> foundWeights;
        Mat& foundWeights_mat = *((Mat*)foundWeights_mat_nativeObj);
        cv::HOGDescriptor* me = (cv::HOGDescriptor*) self; //TODO: check for NULL
        Mat& img = *((Mat*)img_nativeObj);
        me->detectMultiScale( img, foundLocations, foundWeights, (double)hitThreshold );
        vector_Rect_to_Mat( foundLocations, foundLocations_mat );
        vector_double_to_Mat( foundWeights, foundWeights_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_objdetect_HOGDescriptor_detectMultiScale_16 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_HOGDescriptor_detectMultiScale_16
  (JNIEnv* env, jclass , jlong self, jlong img_nativeObj, jlong foundLocations_mat_nativeObj, jlong foundWeights_mat_nativeObj)
{
    static const char method_name[] = "objdetect::detectMultiScale_16()";
    try {
        LOGD("%s", method_name);
        std::vector<Rect> foundLocations;
        Mat& foundLocations_mat = *((Mat*)foundLocations_mat_nativeObj);
        std::vector<double> foundWeights;
        Mat& foundWeights_mat = *((Mat*)foundWeights_mat_nativeObj);
        cv::HOGDescriptor* me = (cv::HOGDescriptor*) self; //TODO: check for NULL
        Mat& img = *((Mat*)img_nativeObj);
        me->detectMultiScale( img, foundLocations, foundWeights );
        vector_Rect_to_Mat( foundLocations, foundLocations_mat );
        vector_double_to_Mat( foundWeights, foundWeights_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::HOGDescriptor::save(String filename, String objname = String())
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_objdetect_HOGDescriptor_save_10 (JNIEnv*, jclass, jlong, jstring, jstring);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_HOGDescriptor_save_10
  (JNIEnv* env, jclass , jlong self, jstring filename, jstring objname)
{
    static const char method_name[] = "objdetect::save_10()";
    try {
        LOGD("%s", method_name);
        cv::HOGDescriptor* me = (cv::HOGDescriptor*) self; //TODO: check for NULL
        const char* utf_filename = env->GetStringUTFChars(filename, 0); String n_filename( utf_filename ? utf_filename : "" ); env->ReleaseStringUTFChars(filename, utf_filename);
        const char* utf_objname = env->GetStringUTFChars(objname, 0); String n_objname( utf_objname ? utf_objname : "" ); env->ReleaseStringUTFChars(objname, utf_objname);
        me->save( n_filename, n_objname );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_objdetect_HOGDescriptor_save_11 (JNIEnv*, jclass, jlong, jstring);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_HOGDescriptor_save_11
  (JNIEnv* env, jclass , jlong self, jstring filename)
{
    static const char method_name[] = "objdetect::save_11()";
    try {
        LOGD("%s", method_name);
        cv::HOGDescriptor* me = (cv::HOGDescriptor*) self; //TODO: check for NULL
        const char* utf_filename = env->GetStringUTFChars(filename, 0); String n_filename( utf_filename ? utf_filename : "" ); env->ReleaseStringUTFChars(filename, utf_filename);
        me->save( n_filename );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::HOGDescriptor::setSVMDetector(Mat svmdetector)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_objdetect_HOGDescriptor_setSVMDetector_10 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_HOGDescriptor_setSVMDetector_10
  (JNIEnv* env, jclass , jlong self, jlong svmdetector_nativeObj)
{
    static const char method_name[] = "objdetect::setSVMDetector_10()";
    try {
        LOGD("%s", method_name);
        cv::HOGDescriptor* me = (cv::HOGDescriptor*) self; //TODO: check for NULL
        Mat& svmdetector = *((Mat*)svmdetector_nativeObj);
        me->setSVMDetector( svmdetector );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
// Size HOGDescriptor::winSize
//

using namespace cv;

JNIEXPORT jdoubleArray JNICALL Java_org_opencv_objdetect_HOGDescriptor_get_1winSize_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jdoubleArray JNICALL Java_org_opencv_objdetect_HOGDescriptor_get_1winSize_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "objdetect::get_1winSize_10()";
    try {
        LOGD("%s", method_name);
        cv::HOGDescriptor* me = (cv::HOGDescriptor*) self; //TODO: check for NULL
        Size _retval_ = me->winSize;//();
        jdoubleArray _da_retval_ = env->NewDoubleArray(2);  jdouble _tmp_retval_[2] = {(jdouble)_retval_.width, (jdouble)_retval_.height}; env->SetDoubleArrayRegion(_da_retval_, 0, 2, _tmp_retval_);
        return _da_retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// Size HOGDescriptor::blockSize
//

using namespace cv;

JNIEXPORT jdoubleArray JNICALL Java_org_opencv_objdetect_HOGDescriptor_get_1blockSize_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jdoubleArray JNICALL Java_org_opencv_objdetect_HOGDescriptor_get_1blockSize_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "objdetect::get_1blockSize_10()";
    try {
        LOGD("%s", method_name);
        cv::HOGDescriptor* me = (cv::HOGDescriptor*) self; //TODO: check for NULL
        Size _retval_ = me->blockSize;//();
        jdoubleArray _da_retval_ = env->NewDoubleArray(2);  jdouble _tmp_retval_[2] = {(jdouble)_retval_.width, (jdouble)_retval_.height}; env->SetDoubleArrayRegion(_da_retval_, 0, 2, _tmp_retval_);
        return _da_retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// Size HOGDescriptor::blockStride
//

using namespace cv;

JNIEXPORT jdoubleArray JNICALL Java_org_opencv_objdetect_HOGDescriptor_get_1blockStride_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jdoubleArray JNICALL Java_org_opencv_objdetect_HOGDescriptor_get_1blockStride_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "objdetect::get_1blockStride_10()";
    try {
        LOGD("%s", method_name);
        cv::HOGDescriptor* me = (cv::HOGDescriptor*) self; //TODO: check for NULL
        Size _retval_ = me->blockStride;//();
        jdoubleArray _da_retval_ = env->NewDoubleArray(2);  jdouble _tmp_retval_[2] = {(jdouble)_retval_.width, (jdouble)_retval_.height}; env->SetDoubleArrayRegion(_da_retval_, 0, 2, _tmp_retval_);
        return _da_retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// Size HOGDescriptor::cellSize
//

using namespace cv;

JNIEXPORT jdoubleArray JNICALL Java_org_opencv_objdetect_HOGDescriptor_get_1cellSize_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jdoubleArray JNICALL Java_org_opencv_objdetect_HOGDescriptor_get_1cellSize_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "objdetect::get_1cellSize_10()";
    try {
        LOGD("%s", method_name);
        cv::HOGDescriptor* me = (cv::HOGDescriptor*) self; //TODO: check for NULL
        Size _retval_ = me->cellSize;//();
        jdoubleArray _da_retval_ = env->NewDoubleArray(2);  jdouble _tmp_retval_[2] = {(jdouble)_retval_.width, (jdouble)_retval_.height}; env->SetDoubleArrayRegion(_da_retval_, 0, 2, _tmp_retval_);
        return _da_retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// int HOGDescriptor::nbins
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_objdetect_HOGDescriptor_get_1nbins_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_objdetect_HOGDescriptor_get_1nbins_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "objdetect::get_1nbins_10()";
    try {
        LOGD("%s", method_name);
        cv::HOGDescriptor* me = (cv::HOGDescriptor*) self; //TODO: check for NULL
        return me->nbins;//();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// int HOGDescriptor::derivAperture
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_objdetect_HOGDescriptor_get_1derivAperture_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_objdetect_HOGDescriptor_get_1derivAperture_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "objdetect::get_1derivAperture_10()";
    try {
        LOGD("%s", method_name);
        cv::HOGDescriptor* me = (cv::HOGDescriptor*) self; //TODO: check for NULL
        return me->derivAperture;//();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// double HOGDescriptor::winSigma
//

using namespace cv;

JNIEXPORT jdouble JNICALL Java_org_opencv_objdetect_HOGDescriptor_get_1winSigma_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_objdetect_HOGDescriptor_get_1winSigma_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "objdetect::get_1winSigma_10()";
    try {
        LOGD("%s", method_name);
        cv::HOGDescriptor* me = (cv::HOGDescriptor*) self; //TODO: check for NULL
        return me->winSigma;//();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// HOGDescriptor_HistogramNormType HOGDescriptor::histogramNormType
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_objdetect_HOGDescriptor_get_1histogramNormType_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_objdetect_HOGDescriptor_get_1histogramNormType_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "objdetect::get_1histogramNormType_10()";
    try {
        LOGD("%s", method_name);
        cv::HOGDescriptor* me = (cv::HOGDescriptor*) self; //TODO: check for NULL
        return me->histogramNormType;//();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// double HOGDescriptor::L2HysThreshold
//

using namespace cv;

JNIEXPORT jdouble JNICALL Java_org_opencv_objdetect_HOGDescriptor_get_1L2HysThreshold_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_objdetect_HOGDescriptor_get_1L2HysThreshold_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "objdetect::get_1L2HysThreshold_10()";
    try {
        LOGD("%s", method_name);
        cv::HOGDescriptor* me = (cv::HOGDescriptor*) self; //TODO: check for NULL
        return me->L2HysThreshold;//();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// bool HOGDescriptor::gammaCorrection
//

using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_objdetect_HOGDescriptor_get_1gammaCorrection_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_objdetect_HOGDescriptor_get_1gammaCorrection_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "objdetect::get_1gammaCorrection_10()";
    try {
        LOGD("%s", method_name);
        cv::HOGDescriptor* me = (cv::HOGDescriptor*) self; //TODO: check for NULL
        return me->gammaCorrection;//();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// vector_float HOGDescriptor::svmDetector
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_objdetect_HOGDescriptor_get_1svmDetector_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_objdetect_HOGDescriptor_get_1svmDetector_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "objdetect::get_1svmDetector_10()";
    try {
        LOGD("%s", method_name);
        cv::HOGDescriptor* me = (cv::HOGDescriptor*) self; //TODO: check for NULL
        std::vector<float> _ret_val_vector_ = me->svmDetector;//();
        Mat* _retval_ = new Mat();
        vector_float_to_Mat(_ret_val_vector_, *_retval_);
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// int HOGDescriptor::nlevels
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_objdetect_HOGDescriptor_get_1nlevels_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_objdetect_HOGDescriptor_get_1nlevels_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "objdetect::get_1nlevels_10()";
    try {
        LOGD("%s", method_name);
        cv::HOGDescriptor* me = (cv::HOGDescriptor*) self; //TODO: check for NULL
        return me->nlevels;//();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// bool HOGDescriptor::signedGradient
//

using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_objdetect_HOGDescriptor_get_1signedGradient_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_objdetect_HOGDescriptor_get_1signedGradient_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "objdetect::get_1signedGradient_10()";
    try {
        LOGD("%s", method_name);
        cv::HOGDescriptor* me = (cv::HOGDescriptor*) self; //TODO: check for NULL
        return me->signedGradient;//();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  native support for java finalize()
//  static void cv::HOGDescriptor::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_objdetect_HOGDescriptor_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_HOGDescriptor_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (cv::HOGDescriptor*) self;
}


//
//   cv::QRCodeDetector::QRCodeDetector()
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_objdetect_QRCodeDetector_QRCodeDetector_10 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_objdetect_QRCodeDetector_QRCodeDetector_10
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "objdetect::QRCodeDetector_10()";
    try {
        LOGD("%s", method_name);
        cv::QRCodeDetector* _retval_ = new cv::QRCodeDetector();
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  bool cv::QRCodeDetector::decodeMulti(Mat img, Mat points, vector_string& decoded_info, vector_Mat& straight_qrcode = vector_Mat())
//

using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_objdetect_QRCodeDetector_decodeMulti_10 (JNIEnv*, jclass, jlong, jlong, jlong, jobject, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_objdetect_QRCodeDetector_decodeMulti_10
  (JNIEnv* env, jclass , jlong self, jlong img_nativeObj, jlong points_nativeObj, jobject decoded_info_list, jlong straight_qrcode_mat_nativeObj)
{
    static const char method_name[] = "objdetect::decodeMulti_10()";
    try {
        LOGD("%s", method_name);
        std::vector< std::string > decoded_info;
        std::vector<Mat> straight_qrcode;
        Mat& straight_qrcode_mat = *((Mat*)straight_qrcode_mat_nativeObj);
        cv::QRCodeDetector* me = (cv::QRCodeDetector*) self; //TODO: check for NULL
        Mat& img = *((Mat*)img_nativeObj);
        Mat& points = *((Mat*)points_nativeObj);
        bool _retval_ = me->decodeMulti( img, points, decoded_info, straight_qrcode );
        Copy_vector_string_to_List(env,decoded_info,decoded_info_list);
        vector_Mat_to_Mat( straight_qrcode, straight_qrcode_mat );
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_objdetect_QRCodeDetector_decodeMulti_11 (JNIEnv*, jclass, jlong, jlong, jlong, jobject);

JNIEXPORT jboolean JNICALL Java_org_opencv_objdetect_QRCodeDetector_decodeMulti_11
  (JNIEnv* env, jclass , jlong self, jlong img_nativeObj, jlong points_nativeObj, jobject decoded_info_list)
{
    static const char method_name[] = "objdetect::decodeMulti_11()";
    try {
        LOGD("%s", method_name);
        std::vector< std::string > decoded_info;
        cv::QRCodeDetector* me = (cv::QRCodeDetector*) self; //TODO: check for NULL
        Mat& img = *((Mat*)img_nativeObj);
        Mat& points = *((Mat*)points_nativeObj);
        bool _retval_ = me->decodeMulti( img, points, decoded_info );
        Copy_vector_string_to_List(env,decoded_info,decoded_info_list);
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  bool cv::QRCodeDetector::detect(Mat img, Mat& points)
//

using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_objdetect_QRCodeDetector_detect_10 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_objdetect_QRCodeDetector_detect_10
  (JNIEnv* env, jclass , jlong self, jlong img_nativeObj, jlong points_nativeObj)
{
    static const char method_name[] = "objdetect::detect_10()";
    try {
        LOGD("%s", method_name);
        cv::QRCodeDetector* me = (cv::QRCodeDetector*) self; //TODO: check for NULL
        Mat& img = *((Mat*)img_nativeObj);
        Mat& points = *((Mat*)points_nativeObj);
        return me->detect( img, points );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  bool cv::QRCodeDetector::detectAndDecodeMulti(Mat img, vector_string& decoded_info, Mat& points = Mat(), vector_Mat& straight_qrcode = vector_Mat())
//

using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_objdetect_QRCodeDetector_detectAndDecodeMulti_10 (JNIEnv*, jclass, jlong, jlong, jobject, jlong, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_objdetect_QRCodeDetector_detectAndDecodeMulti_10
  (JNIEnv* env, jclass , jlong self, jlong img_nativeObj, jobject decoded_info_list, jlong points_nativeObj, jlong straight_qrcode_mat_nativeObj)
{
    static const char method_name[] = "objdetect::detectAndDecodeMulti_10()";
    try {
        LOGD("%s", method_name);
        std::vector< std::string > decoded_info;
        std::vector<Mat> straight_qrcode;
        Mat& straight_qrcode_mat = *((Mat*)straight_qrcode_mat_nativeObj);
        cv::QRCodeDetector* me = (cv::QRCodeDetector*) self; //TODO: check for NULL
        Mat& img = *((Mat*)img_nativeObj);
        Mat& points = *((Mat*)points_nativeObj);
        bool _retval_ = me->detectAndDecodeMulti( img, decoded_info, points, straight_qrcode );
        Copy_vector_string_to_List(env,decoded_info,decoded_info_list);
        vector_Mat_to_Mat( straight_qrcode, straight_qrcode_mat );
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_objdetect_QRCodeDetector_detectAndDecodeMulti_11 (JNIEnv*, jclass, jlong, jlong, jobject, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_objdetect_QRCodeDetector_detectAndDecodeMulti_11
  (JNIEnv* env, jclass , jlong self, jlong img_nativeObj, jobject decoded_info_list, jlong points_nativeObj)
{
    static const char method_name[] = "objdetect::detectAndDecodeMulti_11()";
    try {
        LOGD("%s", method_name);
        std::vector< std::string > decoded_info;
        cv::QRCodeDetector* me = (cv::QRCodeDetector*) self; //TODO: check for NULL
        Mat& img = *((Mat*)img_nativeObj);
        Mat& points = *((Mat*)points_nativeObj);
        bool _retval_ = me->detectAndDecodeMulti( img, decoded_info, points );
        Copy_vector_string_to_List(env,decoded_info,decoded_info_list);
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_objdetect_QRCodeDetector_detectAndDecodeMulti_12 (JNIEnv*, jclass, jlong, jlong, jobject);

JNIEXPORT jboolean JNICALL Java_org_opencv_objdetect_QRCodeDetector_detectAndDecodeMulti_12
  (JNIEnv* env, jclass , jlong self, jlong img_nativeObj, jobject decoded_info_list)
{
    static const char method_name[] = "objdetect::detectAndDecodeMulti_12()";
    try {
        LOGD("%s", method_name);
        std::vector< std::string > decoded_info;
        cv::QRCodeDetector* me = (cv::QRCodeDetector*) self; //TODO: check for NULL
        Mat& img = *((Mat*)img_nativeObj);
        bool _retval_ = me->detectAndDecodeMulti( img, decoded_info );
        Copy_vector_string_to_List(env,decoded_info,decoded_info_list);
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  bool cv::QRCodeDetector::detectMulti(Mat img, Mat& points)
//

using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_objdetect_QRCodeDetector_detectMulti_10 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_objdetect_QRCodeDetector_detectMulti_10
  (JNIEnv* env, jclass , jlong self, jlong img_nativeObj, jlong points_nativeObj)
{
    static const char method_name[] = "objdetect::detectMulti_10()";
    try {
        LOGD("%s", method_name);
        cv::QRCodeDetector* me = (cv::QRCodeDetector*) self; //TODO: check for NULL
        Mat& img = *((Mat*)img_nativeObj);
        Mat& points = *((Mat*)points_nativeObj);
        return me->detectMulti( img, points );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  string cv::QRCodeDetector::decode(Mat img, Mat points, Mat& straight_qrcode = Mat())
//

using namespace cv;

JNIEXPORT jstring JNICALL Java_org_opencv_objdetect_QRCodeDetector_decode_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT jstring JNICALL Java_org_opencv_objdetect_QRCodeDetector_decode_10
  (JNIEnv* env, jclass , jlong self, jlong img_nativeObj, jlong points_nativeObj, jlong straight_qrcode_nativeObj)
{
    static const char method_name[] = "objdetect::decode_10()";
    try {
        LOGD("%s", method_name);
        cv::QRCodeDetector* me = (cv::QRCodeDetector*) self; //TODO: check for NULL
        Mat& img = *((Mat*)img_nativeObj);
        Mat& points = *((Mat*)points_nativeObj);
        Mat& straight_qrcode = *((Mat*)straight_qrcode_nativeObj);
        std::string _retval_ = me->decode( img, points, straight_qrcode );
        return env->NewStringUTF(_retval_.c_str());
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return env->NewStringUTF("");
}



using namespace cv;

JNIEXPORT jstring JNICALL Java_org_opencv_objdetect_QRCodeDetector_decode_11 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT jstring JNICALL Java_org_opencv_objdetect_QRCodeDetector_decode_11
  (JNIEnv* env, jclass , jlong self, jlong img_nativeObj, jlong points_nativeObj)
{
    static const char method_name[] = "objdetect::decode_11()";
    try {
        LOGD("%s", method_name);
        cv::QRCodeDetector* me = (cv::QRCodeDetector*) self; //TODO: check for NULL
        Mat& img = *((Mat*)img_nativeObj);
        Mat& points = *((Mat*)points_nativeObj);
        std::string _retval_ = me->decode( img, points );
        return env->NewStringUTF(_retval_.c_str());
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return env->NewStringUTF("");
}



//
//  string cv::QRCodeDetector::detectAndDecode(Mat img, Mat& points = Mat(), Mat& straight_qrcode = Mat())
//

using namespace cv;

JNIEXPORT jstring JNICALL Java_org_opencv_objdetect_QRCodeDetector_detectAndDecode_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT jstring JNICALL Java_org_opencv_objdetect_QRCodeDetector_detectAndDecode_10
  (JNIEnv* env, jclass , jlong self, jlong img_nativeObj, jlong points_nativeObj, jlong straight_qrcode_nativeObj)
{
    static const char method_name[] = "objdetect::detectAndDecode_10()";
    try {
        LOGD("%s", method_name);
        cv::QRCodeDetector* me = (cv::QRCodeDetector*) self; //TODO: check for NULL
        Mat& img = *((Mat*)img_nativeObj);
        Mat& points = *((Mat*)points_nativeObj);
        Mat& straight_qrcode = *((Mat*)straight_qrcode_nativeObj);
        std::string _retval_ = me->detectAndDecode( img, points, straight_qrcode );
        return env->NewStringUTF(_retval_.c_str());
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return env->NewStringUTF("");
}



using namespace cv;

JNIEXPORT jstring JNICALL Java_org_opencv_objdetect_QRCodeDetector_detectAndDecode_11 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT jstring JNICALL Java_org_opencv_objdetect_QRCodeDetector_detectAndDecode_11
  (JNIEnv* env, jclass , jlong self, jlong img_nativeObj, jlong points_nativeObj)
{
    static const char method_name[] = "objdetect::detectAndDecode_11()";
    try {
        LOGD("%s", method_name);
        cv::QRCodeDetector* me = (cv::QRCodeDetector*) self; //TODO: check for NULL
        Mat& img = *((Mat*)img_nativeObj);
        Mat& points = *((Mat*)points_nativeObj);
        std::string _retval_ = me->detectAndDecode( img, points );
        return env->NewStringUTF(_retval_.c_str());
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return env->NewStringUTF("");
}



using namespace cv;

JNIEXPORT jstring JNICALL Java_org_opencv_objdetect_QRCodeDetector_detectAndDecode_12 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT jstring JNICALL Java_org_opencv_objdetect_QRCodeDetector_detectAndDecode_12
  (JNIEnv* env, jclass , jlong self, jlong img_nativeObj)
{
    static const char method_name[] = "objdetect::detectAndDecode_12()";
    try {
        LOGD("%s", method_name);
        cv::QRCodeDetector* me = (cv::QRCodeDetector*) self; //TODO: check for NULL
        Mat& img = *((Mat*)img_nativeObj);
        std::string _retval_ = me->detectAndDecode( img );
        return env->NewStringUTF(_retval_.c_str());
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return env->NewStringUTF("");
}



//
//  void cv::QRCodeDetector::setEpsX(double epsX)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_objdetect_QRCodeDetector_setEpsX_10 (JNIEnv*, jclass, jlong, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_QRCodeDetector_setEpsX_10
  (JNIEnv* env, jclass , jlong self, jdouble epsX)
{
    static const char method_name[] = "objdetect::setEpsX_10()";
    try {
        LOGD("%s", method_name);
        cv::QRCodeDetector* me = (cv::QRCodeDetector*) self; //TODO: check for NULL
        me->setEpsX( (double)epsX );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::QRCodeDetector::setEpsY(double epsY)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_objdetect_QRCodeDetector_setEpsY_10 (JNIEnv*, jclass, jlong, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_QRCodeDetector_setEpsY_10
  (JNIEnv* env, jclass , jlong self, jdouble epsY)
{
    static const char method_name[] = "objdetect::setEpsY_10()";
    try {
        LOGD("%s", method_name);
        cv::QRCodeDetector* me = (cv::QRCodeDetector*) self; //TODO: check for NULL
        me->setEpsY( (double)epsY );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void cv::QRCodeDetector::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_objdetect_QRCodeDetector_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_QRCodeDetector_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (cv::QRCodeDetector*) self;
}


//
//   cv::CascadeClassifier::CascadeClassifier(String filename)
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_objdetect_CascadeClassifier_CascadeClassifier_10 (JNIEnv*, jclass, jstring);

JNIEXPORT jlong JNICALL Java_org_opencv_objdetect_CascadeClassifier_CascadeClassifier_10
  (JNIEnv* env, jclass , jstring filename)
{
    static const char method_name[] = "objdetect::CascadeClassifier_10()";
    try {
        LOGD("%s", method_name);
        const char* utf_filename = env->GetStringUTFChars(filename, 0); String n_filename( utf_filename ? utf_filename : "" ); env->ReleaseStringUTFChars(filename, utf_filename);
        cv::CascadeClassifier* _retval_ = new cv::CascadeClassifier( n_filename );
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//   cv::CascadeClassifier::CascadeClassifier()
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_objdetect_CascadeClassifier_CascadeClassifier_11 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_objdetect_CascadeClassifier_CascadeClassifier_11
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "objdetect::CascadeClassifier_11()";
    try {
        LOGD("%s", method_name);
        cv::CascadeClassifier* _retval_ = new cv::CascadeClassifier();
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Size cv::CascadeClassifier::getOriginalWindowSize()
//

using namespace cv;

JNIEXPORT jdoubleArray JNICALL Java_org_opencv_objdetect_CascadeClassifier_getOriginalWindowSize_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jdoubleArray JNICALL Java_org_opencv_objdetect_CascadeClassifier_getOriginalWindowSize_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "objdetect::getOriginalWindowSize_10()";
    try {
        LOGD("%s", method_name);
        cv::CascadeClassifier* me = (cv::CascadeClassifier*) self; //TODO: check for NULL
        Size _retval_ = me->getOriginalWindowSize();
        jdoubleArray _da_retval_ = env->NewDoubleArray(2);  jdouble _tmp_retval_[2] = {(jdouble)_retval_.width, (jdouble)_retval_.height}; env->SetDoubleArrayRegion(_da_retval_, 0, 2, _tmp_retval_);
        return _da_retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// static bool cv::CascadeClassifier::convert(String oldcascade, String newcascade)
//

using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_objdetect_CascadeClassifier_convert_10 (JNIEnv*, jclass, jstring, jstring);

JNIEXPORT jboolean JNICALL Java_org_opencv_objdetect_CascadeClassifier_convert_10
  (JNIEnv* env, jclass , jstring oldcascade, jstring newcascade)
{
    static const char method_name[] = "objdetect::convert_10()";
    try {
        LOGD("%s", method_name);
        const char* utf_oldcascade = env->GetStringUTFChars(oldcascade, 0); String n_oldcascade( utf_oldcascade ? utf_oldcascade : "" ); env->ReleaseStringUTFChars(oldcascade, utf_oldcascade);
        const char* utf_newcascade = env->GetStringUTFChars(newcascade, 0); String n_newcascade( utf_newcascade ? utf_newcascade : "" ); env->ReleaseStringUTFChars(newcascade, utf_newcascade);
        return cv::CascadeClassifier::convert( n_oldcascade, n_newcascade );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  bool cv::CascadeClassifier::empty()
//

using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_objdetect_CascadeClassifier_empty_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_objdetect_CascadeClassifier_empty_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "objdetect::empty_10()";
    try {
        LOGD("%s", method_name);
        cv::CascadeClassifier* me = (cv::CascadeClassifier*) self; //TODO: check for NULL
        return me->empty();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  bool cv::CascadeClassifier::isOldFormatCascade()
//

using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_objdetect_CascadeClassifier_isOldFormatCascade_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_objdetect_CascadeClassifier_isOldFormatCascade_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "objdetect::isOldFormatCascade_10()";
    try {
        LOGD("%s", method_name);
        cv::CascadeClassifier* me = (cv::CascadeClassifier*) self; //TODO: check for NULL
        return me->isOldFormatCascade();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  bool cv::CascadeClassifier::load(String filename)
//

using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_objdetect_CascadeClassifier_load_10 (JNIEnv*, jclass, jlong, jstring);

JNIEXPORT jboolean JNICALL Java_org_opencv_objdetect_CascadeClassifier_load_10
  (JNIEnv* env, jclass , jlong self, jstring filename)
{
    static const char method_name[] = "objdetect::load_10()";
    try {
        LOGD("%s", method_name);
        cv::CascadeClassifier* me = (cv::CascadeClassifier*) self; //TODO: check for NULL
        const char* utf_filename = env->GetStringUTFChars(filename, 0); String n_filename( utf_filename ? utf_filename : "" ); env->ReleaseStringUTFChars(filename, utf_filename);
        return me->load( n_filename );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::CascadeClassifier::getFeatureType()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_objdetect_CascadeClassifier_getFeatureType_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_objdetect_CascadeClassifier_getFeatureType_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "objdetect::getFeatureType_10()";
    try {
        LOGD("%s", method_name);
        cv::CascadeClassifier* me = (cv::CascadeClassifier*) self; //TODO: check for NULL
        return me->getFeatureType();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::CascadeClassifier::detectMultiScale(Mat image, vector_Rect& objects, double scaleFactor = 1.1, int minNeighbors = 3, int flags = 0, Size minSize = Size(), Size maxSize = Size())
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_objdetect_CascadeClassifier_detectMultiScale_10 (JNIEnv*, jclass, jlong, jlong, jlong, jdouble, jint, jint, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_CascadeClassifier_detectMultiScale_10
  (JNIEnv* env, jclass , jlong self, jlong image_nativeObj, jlong objects_mat_nativeObj, jdouble scaleFactor, jint minNeighbors, jint flags, jdouble minSize_width, jdouble minSize_height, jdouble maxSize_width, jdouble maxSize_height)
{
    static const char method_name[] = "objdetect::detectMultiScale_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Rect> objects;
        Mat& objects_mat = *((Mat*)objects_mat_nativeObj);
        cv::CascadeClassifier* me = (cv::CascadeClassifier*) self; //TODO: check for NULL
        Mat& image = *((Mat*)image_nativeObj);
        Size minSize((int)minSize_width, (int)minSize_height);
        Size maxSize((int)maxSize_width, (int)maxSize_height);
        me->detectMultiScale( image, objects, (double)scaleFactor, (int)minNeighbors, (int)flags, minSize, maxSize );
        vector_Rect_to_Mat( objects, objects_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_objdetect_CascadeClassifier_detectMultiScale_11 (JNIEnv*, jclass, jlong, jlong, jlong, jdouble, jint, jint, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_CascadeClassifier_detectMultiScale_11
  (JNIEnv* env, jclass , jlong self, jlong image_nativeObj, jlong objects_mat_nativeObj, jdouble scaleFactor, jint minNeighbors, jint flags, jdouble minSize_width, jdouble minSize_height)
{
    static const char method_name[] = "objdetect::detectMultiScale_11()";
    try {
        LOGD("%s", method_name);
        std::vector<Rect> objects;
        Mat& objects_mat = *((Mat*)objects_mat_nativeObj);
        cv::CascadeClassifier* me = (cv::CascadeClassifier*) self; //TODO: check for NULL
        Mat& image = *((Mat*)image_nativeObj);
        Size minSize((int)minSize_width, (int)minSize_height);
        me->detectMultiScale( image, objects, (double)scaleFactor, (int)minNeighbors, (int)flags, minSize );
        vector_Rect_to_Mat( objects, objects_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_objdetect_CascadeClassifier_detectMultiScale_12 (JNIEnv*, jclass, jlong, jlong, jlong, jdouble, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_CascadeClassifier_detectMultiScale_12
  (JNIEnv* env, jclass , jlong self, jlong image_nativeObj, jlong objects_mat_nativeObj, jdouble scaleFactor, jint minNeighbors, jint flags)
{
    static const char method_name[] = "objdetect::detectMultiScale_12()";
    try {
        LOGD("%s", method_name);
        std::vector<Rect> objects;
        Mat& objects_mat = *((Mat*)objects_mat_nativeObj);
        cv::CascadeClassifier* me = (cv::CascadeClassifier*) self; //TODO: check for NULL
        Mat& image = *((Mat*)image_nativeObj);
        me->detectMultiScale( image, objects, (double)scaleFactor, (int)minNeighbors, (int)flags );
        vector_Rect_to_Mat( objects, objects_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_objdetect_CascadeClassifier_detectMultiScale_13 (JNIEnv*, jclass, jlong, jlong, jlong, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_CascadeClassifier_detectMultiScale_13
  (JNIEnv* env, jclass , jlong self, jlong image_nativeObj, jlong objects_mat_nativeObj, jdouble scaleFactor, jint minNeighbors)
{
    static const char method_name[] = "objdetect::detectMultiScale_13()";
    try {
        LOGD("%s", method_name);
        std::vector<Rect> objects;
        Mat& objects_mat = *((Mat*)objects_mat_nativeObj);
        cv::CascadeClassifier* me = (cv::CascadeClassifier*) self; //TODO: check for NULL
        Mat& image = *((Mat*)image_nativeObj);
        me->detectMultiScale( image, objects, (double)scaleFactor, (int)minNeighbors );
        vector_Rect_to_Mat( objects, objects_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_objdetect_CascadeClassifier_detectMultiScale_14 (JNIEnv*, jclass, jlong, jlong, jlong, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_CascadeClassifier_detectMultiScale_14
  (JNIEnv* env, jclass , jlong self, jlong image_nativeObj, jlong objects_mat_nativeObj, jdouble scaleFactor)
{
    static const char method_name[] = "objdetect::detectMultiScale_14()";
    try {
        LOGD("%s", method_name);
        std::vector<Rect> objects;
        Mat& objects_mat = *((Mat*)objects_mat_nativeObj);
        cv::CascadeClassifier* me = (cv::CascadeClassifier*) self; //TODO: check for NULL
        Mat& image = *((Mat*)image_nativeObj);
        me->detectMultiScale( image, objects, (double)scaleFactor );
        vector_Rect_to_Mat( objects, objects_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_objdetect_CascadeClassifier_detectMultiScale_15 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_CascadeClassifier_detectMultiScale_15
  (JNIEnv* env, jclass , jlong self, jlong image_nativeObj, jlong objects_mat_nativeObj)
{
    static const char method_name[] = "objdetect::detectMultiScale_15()";
    try {
        LOGD("%s", method_name);
        std::vector<Rect> objects;
        Mat& objects_mat = *((Mat*)objects_mat_nativeObj);
        cv::CascadeClassifier* me = (cv::CascadeClassifier*) self; //TODO: check for NULL
        Mat& image = *((Mat*)image_nativeObj);
        me->detectMultiScale( image, objects );
        vector_Rect_to_Mat( objects, objects_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::CascadeClassifier::detectMultiScale(Mat image, vector_Rect& objects, vector_int& numDetections, double scaleFactor = 1.1, int minNeighbors = 3, int flags = 0, Size minSize = Size(), Size maxSize = Size())
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_objdetect_CascadeClassifier_detectMultiScale2_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jdouble, jint, jint, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_CascadeClassifier_detectMultiScale2_10
  (JNIEnv* env, jclass , jlong self, jlong image_nativeObj, jlong objects_mat_nativeObj, jlong numDetections_mat_nativeObj, jdouble scaleFactor, jint minNeighbors, jint flags, jdouble minSize_width, jdouble minSize_height, jdouble maxSize_width, jdouble maxSize_height)
{
    static const char method_name[] = "objdetect::detectMultiScale2_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Rect> objects;
        Mat& objects_mat = *((Mat*)objects_mat_nativeObj);
        std::vector<int> numDetections;
        Mat& numDetections_mat = *((Mat*)numDetections_mat_nativeObj);
        cv::CascadeClassifier* me = (cv::CascadeClassifier*) self; //TODO: check for NULL
        Mat& image = *((Mat*)image_nativeObj);
        Size minSize((int)minSize_width, (int)minSize_height);
        Size maxSize((int)maxSize_width, (int)maxSize_height);
        me->detectMultiScale( image, objects, numDetections, (double)scaleFactor, (int)minNeighbors, (int)flags, minSize, maxSize );
        vector_Rect_to_Mat( objects, objects_mat );
        vector_int_to_Mat( numDetections, numDetections_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_objdetect_CascadeClassifier_detectMultiScale2_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jdouble, jint, jint, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_CascadeClassifier_detectMultiScale2_11
  (JNIEnv* env, jclass , jlong self, jlong image_nativeObj, jlong objects_mat_nativeObj, jlong numDetections_mat_nativeObj, jdouble scaleFactor, jint minNeighbors, jint flags, jdouble minSize_width, jdouble minSize_height)
{
    static const char method_name[] = "objdetect::detectMultiScale2_11()";
    try {
        LOGD("%s", method_name);
        std::vector<Rect> objects;
        Mat& objects_mat = *((Mat*)objects_mat_nativeObj);
        std::vector<int> numDetections;
        Mat& numDetections_mat = *((Mat*)numDetections_mat_nativeObj);
        cv::CascadeClassifier* me = (cv::CascadeClassifier*) self; //TODO: check for NULL
        Mat& image = *((Mat*)image_nativeObj);
        Size minSize((int)minSize_width, (int)minSize_height);
        me->detectMultiScale( image, objects, numDetections, (double)scaleFactor, (int)minNeighbors, (int)flags, minSize );
        vector_Rect_to_Mat( objects, objects_mat );
        vector_int_to_Mat( numDetections, numDetections_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_objdetect_CascadeClassifier_detectMultiScale2_12 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jdouble, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_CascadeClassifier_detectMultiScale2_12
  (JNIEnv* env, jclass , jlong self, jlong image_nativeObj, jlong objects_mat_nativeObj, jlong numDetections_mat_nativeObj, jdouble scaleFactor, jint minNeighbors, jint flags)
{
    static const char method_name[] = "objdetect::detectMultiScale2_12()";
    try {
        LOGD("%s", method_name);
        std::vector<Rect> objects;
        Mat& objects_mat = *((Mat*)objects_mat_nativeObj);
        std::vector<int> numDetections;
        Mat& numDetections_mat = *((Mat*)numDetections_mat_nativeObj);
        cv::CascadeClassifier* me = (cv::CascadeClassifier*) self; //TODO: check for NULL
        Mat& image = *((Mat*)image_nativeObj);
        me->detectMultiScale( image, objects, numDetections, (double)scaleFactor, (int)minNeighbors, (int)flags );
        vector_Rect_to_Mat( objects, objects_mat );
        vector_int_to_Mat( numDetections, numDetections_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_objdetect_CascadeClassifier_detectMultiScale2_13 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_CascadeClassifier_detectMultiScale2_13
  (JNIEnv* env, jclass , jlong self, jlong image_nativeObj, jlong objects_mat_nativeObj, jlong numDetections_mat_nativeObj, jdouble scaleFactor, jint minNeighbors)
{
    static const char method_name[] = "objdetect::detectMultiScale2_13()";
    try {
        LOGD("%s", method_name);
        std::vector<Rect> objects;
        Mat& objects_mat = *((Mat*)objects_mat_nativeObj);
        std::vector<int> numDetections;
        Mat& numDetections_mat = *((Mat*)numDetections_mat_nativeObj);
        cv::CascadeClassifier* me = (cv::CascadeClassifier*) self; //TODO: check for NULL
        Mat& image = *((Mat*)image_nativeObj);
        me->detectMultiScale( image, objects, numDetections, (double)scaleFactor, (int)minNeighbors );
        vector_Rect_to_Mat( objects, objects_mat );
        vector_int_to_Mat( numDetections, numDetections_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_objdetect_CascadeClassifier_detectMultiScale2_14 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_CascadeClassifier_detectMultiScale2_14
  (JNIEnv* env, jclass , jlong self, jlong image_nativeObj, jlong objects_mat_nativeObj, jlong numDetections_mat_nativeObj, jdouble scaleFactor)
{
    static const char method_name[] = "objdetect::detectMultiScale2_14()";
    try {
        LOGD("%s", method_name);
        std::vector<Rect> objects;
        Mat& objects_mat = *((Mat*)objects_mat_nativeObj);
        std::vector<int> numDetections;
        Mat& numDetections_mat = *((Mat*)numDetections_mat_nativeObj);
        cv::CascadeClassifier* me = (cv::CascadeClassifier*) self; //TODO: check for NULL
        Mat& image = *((Mat*)image_nativeObj);
        me->detectMultiScale( image, objects, numDetections, (double)scaleFactor );
        vector_Rect_to_Mat( objects, objects_mat );
        vector_int_to_Mat( numDetections, numDetections_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_objdetect_CascadeClassifier_detectMultiScale2_15 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_CascadeClassifier_detectMultiScale2_15
  (JNIEnv* env, jclass , jlong self, jlong image_nativeObj, jlong objects_mat_nativeObj, jlong numDetections_mat_nativeObj)
{
    static const char method_name[] = "objdetect::detectMultiScale2_15()";
    try {
        LOGD("%s", method_name);
        std::vector<Rect> objects;
        Mat& objects_mat = *((Mat*)objects_mat_nativeObj);
        std::vector<int> numDetections;
        Mat& numDetections_mat = *((Mat*)numDetections_mat_nativeObj);
        cv::CascadeClassifier* me = (cv::CascadeClassifier*) self; //TODO: check for NULL
        Mat& image = *((Mat*)image_nativeObj);
        me->detectMultiScale( image, objects, numDetections );
        vector_Rect_to_Mat( objects, objects_mat );
        vector_int_to_Mat( numDetections, numDetections_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::CascadeClassifier::detectMultiScale(Mat image, vector_Rect& objects, vector_int& rejectLevels, vector_double& levelWeights, double scaleFactor = 1.1, int minNeighbors = 3, int flags = 0, Size minSize = Size(), Size maxSize = Size(), bool outputRejectLevels = false)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_objdetect_CascadeClassifier_detectMultiScale3_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jdouble, jint, jint, jdouble, jdouble, jdouble, jdouble, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_CascadeClassifier_detectMultiScale3_10
  (JNIEnv* env, jclass , jlong self, jlong image_nativeObj, jlong objects_mat_nativeObj, jlong rejectLevels_mat_nativeObj, jlong levelWeights_mat_nativeObj, jdouble scaleFactor, jint minNeighbors, jint flags, jdouble minSize_width, jdouble minSize_height, jdouble maxSize_width, jdouble maxSize_height, jboolean outputRejectLevels)
{
    static const char method_name[] = "objdetect::detectMultiScale3_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Rect> objects;
        Mat& objects_mat = *((Mat*)objects_mat_nativeObj);
        std::vector<int> rejectLevels;
        Mat& rejectLevels_mat = *((Mat*)rejectLevels_mat_nativeObj);
        std::vector<double> levelWeights;
        Mat& levelWeights_mat = *((Mat*)levelWeights_mat_nativeObj);
        cv::CascadeClassifier* me = (cv::CascadeClassifier*) self; //TODO: check for NULL
        Mat& image = *((Mat*)image_nativeObj);
        Size minSize((int)minSize_width, (int)minSize_height);
        Size maxSize((int)maxSize_width, (int)maxSize_height);
        me->detectMultiScale( image, objects, rejectLevels, levelWeights, (double)scaleFactor, (int)minNeighbors, (int)flags, minSize, maxSize, (bool)outputRejectLevels );
        vector_Rect_to_Mat( objects, objects_mat );
        vector_int_to_Mat( rejectLevels, rejectLevels_mat );
        vector_double_to_Mat( levelWeights, levelWeights_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_objdetect_CascadeClassifier_detectMultiScale3_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jdouble, jint, jint, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_CascadeClassifier_detectMultiScale3_11
  (JNIEnv* env, jclass , jlong self, jlong image_nativeObj, jlong objects_mat_nativeObj, jlong rejectLevels_mat_nativeObj, jlong levelWeights_mat_nativeObj, jdouble scaleFactor, jint minNeighbors, jint flags, jdouble minSize_width, jdouble minSize_height, jdouble maxSize_width, jdouble maxSize_height)
{
    static const char method_name[] = "objdetect::detectMultiScale3_11()";
    try {
        LOGD("%s", method_name);
        std::vector<Rect> objects;
        Mat& objects_mat = *((Mat*)objects_mat_nativeObj);
        std::vector<int> rejectLevels;
        Mat& rejectLevels_mat = *((Mat*)rejectLevels_mat_nativeObj);
        std::vector<double> levelWeights;
        Mat& levelWeights_mat = *((Mat*)levelWeights_mat_nativeObj);
        cv::CascadeClassifier* me = (cv::CascadeClassifier*) self; //TODO: check for NULL
        Mat& image = *((Mat*)image_nativeObj);
        Size minSize((int)minSize_width, (int)minSize_height);
        Size maxSize((int)maxSize_width, (int)maxSize_height);
        me->detectMultiScale( image, objects, rejectLevels, levelWeights, (double)scaleFactor, (int)minNeighbors, (int)flags, minSize, maxSize );
        vector_Rect_to_Mat( objects, objects_mat );
        vector_int_to_Mat( rejectLevels, rejectLevels_mat );
        vector_double_to_Mat( levelWeights, levelWeights_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_objdetect_CascadeClassifier_detectMultiScale3_12 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jdouble, jint, jint, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_CascadeClassifier_detectMultiScale3_12
  (JNIEnv* env, jclass , jlong self, jlong image_nativeObj, jlong objects_mat_nativeObj, jlong rejectLevels_mat_nativeObj, jlong levelWeights_mat_nativeObj, jdouble scaleFactor, jint minNeighbors, jint flags, jdouble minSize_width, jdouble minSize_height)
{
    static const char method_name[] = "objdetect::detectMultiScale3_12()";
    try {
        LOGD("%s", method_name);
        std::vector<Rect> objects;
        Mat& objects_mat = *((Mat*)objects_mat_nativeObj);
        std::vector<int> rejectLevels;
        Mat& rejectLevels_mat = *((Mat*)rejectLevels_mat_nativeObj);
        std::vector<double> levelWeights;
        Mat& levelWeights_mat = *((Mat*)levelWeights_mat_nativeObj);
        cv::CascadeClassifier* me = (cv::CascadeClassifier*) self; //TODO: check for NULL
        Mat& image = *((Mat*)image_nativeObj);
        Size minSize((int)minSize_width, (int)minSize_height);
        me->detectMultiScale( image, objects, rejectLevels, levelWeights, (double)scaleFactor, (int)minNeighbors, (int)flags, minSize );
        vector_Rect_to_Mat( objects, objects_mat );
        vector_int_to_Mat( rejectLevels, rejectLevels_mat );
        vector_double_to_Mat( levelWeights, levelWeights_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_objdetect_CascadeClassifier_detectMultiScale3_13 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jdouble, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_CascadeClassifier_detectMultiScale3_13
  (JNIEnv* env, jclass , jlong self, jlong image_nativeObj, jlong objects_mat_nativeObj, jlong rejectLevels_mat_nativeObj, jlong levelWeights_mat_nativeObj, jdouble scaleFactor, jint minNeighbors, jint flags)
{
    static const char method_name[] = "objdetect::detectMultiScale3_13()";
    try {
        LOGD("%s", method_name);
        std::vector<Rect> objects;
        Mat& objects_mat = *((Mat*)objects_mat_nativeObj);
        std::vector<int> rejectLevels;
        Mat& rejectLevels_mat = *((Mat*)rejectLevels_mat_nativeObj);
        std::vector<double> levelWeights;
        Mat& levelWeights_mat = *((Mat*)levelWeights_mat_nativeObj);
        cv::CascadeClassifier* me = (cv::CascadeClassifier*) self; //TODO: check for NULL
        Mat& image = *((Mat*)image_nativeObj);
        me->detectMultiScale( image, objects, rejectLevels, levelWeights, (double)scaleFactor, (int)minNeighbors, (int)flags );
        vector_Rect_to_Mat( objects, objects_mat );
        vector_int_to_Mat( rejectLevels, rejectLevels_mat );
        vector_double_to_Mat( levelWeights, levelWeights_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_objdetect_CascadeClassifier_detectMultiScale3_14 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_CascadeClassifier_detectMultiScale3_14
  (JNIEnv* env, jclass , jlong self, jlong image_nativeObj, jlong objects_mat_nativeObj, jlong rejectLevels_mat_nativeObj, jlong levelWeights_mat_nativeObj, jdouble scaleFactor, jint minNeighbors)
{
    static const char method_name[] = "objdetect::detectMultiScale3_14()";
    try {
        LOGD("%s", method_name);
        std::vector<Rect> objects;
        Mat& objects_mat = *((Mat*)objects_mat_nativeObj);
        std::vector<int> rejectLevels;
        Mat& rejectLevels_mat = *((Mat*)rejectLevels_mat_nativeObj);
        std::vector<double> levelWeights;
        Mat& levelWeights_mat = *((Mat*)levelWeights_mat_nativeObj);
        cv::CascadeClassifier* me = (cv::CascadeClassifier*) self; //TODO: check for NULL
        Mat& image = *((Mat*)image_nativeObj);
        me->detectMultiScale( image, objects, rejectLevels, levelWeights, (double)scaleFactor, (int)minNeighbors );
        vector_Rect_to_Mat( objects, objects_mat );
        vector_int_to_Mat( rejectLevels, rejectLevels_mat );
        vector_double_to_Mat( levelWeights, levelWeights_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_objdetect_CascadeClassifier_detectMultiScale3_15 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_CascadeClassifier_detectMultiScale3_15
  (JNIEnv* env, jclass , jlong self, jlong image_nativeObj, jlong objects_mat_nativeObj, jlong rejectLevels_mat_nativeObj, jlong levelWeights_mat_nativeObj, jdouble scaleFactor)
{
    static const char method_name[] = "objdetect::detectMultiScale3_15()";
    try {
        LOGD("%s", method_name);
        std::vector<Rect> objects;
        Mat& objects_mat = *((Mat*)objects_mat_nativeObj);
        std::vector<int> rejectLevels;
        Mat& rejectLevels_mat = *((Mat*)rejectLevels_mat_nativeObj);
        std::vector<double> levelWeights;
        Mat& levelWeights_mat = *((Mat*)levelWeights_mat_nativeObj);
        cv::CascadeClassifier* me = (cv::CascadeClassifier*) self; //TODO: check for NULL
        Mat& image = *((Mat*)image_nativeObj);
        me->detectMultiScale( image, objects, rejectLevels, levelWeights, (double)scaleFactor );
        vector_Rect_to_Mat( objects, objects_mat );
        vector_int_to_Mat( rejectLevels, rejectLevels_mat );
        vector_double_to_Mat( levelWeights, levelWeights_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_objdetect_CascadeClassifier_detectMultiScale3_16 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_CascadeClassifier_detectMultiScale3_16
  (JNIEnv* env, jclass , jlong self, jlong image_nativeObj, jlong objects_mat_nativeObj, jlong rejectLevels_mat_nativeObj, jlong levelWeights_mat_nativeObj)
{
    static const char method_name[] = "objdetect::detectMultiScale3_16()";
    try {
        LOGD("%s", method_name);
        std::vector<Rect> objects;
        Mat& objects_mat = *((Mat*)objects_mat_nativeObj);
        std::vector<int> rejectLevels;
        Mat& rejectLevels_mat = *((Mat*)rejectLevels_mat_nativeObj);
        std::vector<double> levelWeights;
        Mat& levelWeights_mat = *((Mat*)levelWeights_mat_nativeObj);
        cv::CascadeClassifier* me = (cv::CascadeClassifier*) self; //TODO: check for NULL
        Mat& image = *((Mat*)image_nativeObj);
        me->detectMultiScale( image, objects, rejectLevels, levelWeights );
        vector_Rect_to_Mat( objects, objects_mat );
        vector_int_to_Mat( rejectLevels, rejectLevels_mat );
        vector_double_to_Mat( levelWeights, levelWeights_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void cv::CascadeClassifier::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_objdetect_CascadeClassifier_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_CascadeClassifier_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (cv::CascadeClassifier*) self;
}


//
//  native support for java finalize()
//  static void Ptr<cv::BaseCascadeClassifier>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_objdetect_BaseCascadeClassifier_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_BaseCascadeClassifier_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::BaseCascadeClassifier>*) self;
}


//
//  void cv::groupRectangles(vector_Rect& rectList, vector_int& weights, int groupThreshold, double eps = 0.2)
//



JNIEXPORT void JNICALL Java_org_opencv_objdetect_Objdetect_groupRectangles_10 (JNIEnv*, jclass, jlong, jlong, jint, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_Objdetect_groupRectangles_10
  (JNIEnv* env, jclass , jlong rectList_mat_nativeObj, jlong weights_mat_nativeObj, jint groupThreshold, jdouble eps)
{
    static const char method_name[] = "objdetect::groupRectangles_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Rect> rectList;
        Mat& rectList_mat = *((Mat*)rectList_mat_nativeObj);
        Mat_to_vector_Rect( rectList_mat, rectList );
        std::vector<int> weights;
        Mat& weights_mat = *((Mat*)weights_mat_nativeObj);
        cv::groupRectangles( rectList, weights, (int)groupThreshold, (double)eps );
        vector_Rect_to_Mat( rectList, rectList_mat );
        vector_int_to_Mat( weights, weights_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_objdetect_Objdetect_groupRectangles_11 (JNIEnv*, jclass, jlong, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_objdetect_Objdetect_groupRectangles_11
  (JNIEnv* env, jclass , jlong rectList_mat_nativeObj, jlong weights_mat_nativeObj, jint groupThreshold)
{
    static const char method_name[] = "objdetect::groupRectangles_11()";
    try {
        LOGD("%s", method_name);
        std::vector<Rect> rectList;
        Mat& rectList_mat = *((Mat*)rectList_mat_nativeObj);
        Mat_to_vector_Rect( rectList_mat, rectList );
        std::vector<int> weights;
        Mat& weights_mat = *((Mat*)weights_mat_nativeObj);
        cv::groupRectangles( rectList, weights, (int)groupThreshold );
        vector_Rect_to_Mat( rectList, rectList_mat );
        vector_int_to_Mat( weights, weights_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}




} // extern "C"

#endif // HAVE_OPENCV_OBJDETECT
