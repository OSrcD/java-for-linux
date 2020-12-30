//
// This file is auto-generated. Please don't modify it!
//

#undef LOG_TAG

#include "opencv2/opencv_modules.hpp"
#ifdef HAVE_OPENCV_PHOTO

#include <string>

#include "opencv2/photo.hpp"

#include "/Users/virtualman/Downloads/MySource/opencv-4.3.0/modules/photo/include/opencv2/photo.hpp"

#define LOG_TAG "org.opencv.photo"
#include "common.h"

using namespace cv;

/// throw java exception
#undef throwJavaException
#define throwJavaException throwJavaException_photo
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
//  float cv::MergeMertens::getContrastWeight()
//

using namespace cv;

JNIEXPORT jfloat JNICALL Java_org_opencv_photo_MergeMertens_getContrastWeight_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_photo_MergeMertens_getContrastWeight_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "photo::getContrastWeight_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::MergeMertens>* me = (Ptr<cv::MergeMertens>*) self; //TODO: check for NULL
        return (*me)->getContrastWeight();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  float cv::MergeMertens::getExposureWeight()
//

using namespace cv;

JNIEXPORT jfloat JNICALL Java_org_opencv_photo_MergeMertens_getExposureWeight_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_photo_MergeMertens_getExposureWeight_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "photo::getExposureWeight_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::MergeMertens>* me = (Ptr<cv::MergeMertens>*) self; //TODO: check for NULL
        return (*me)->getExposureWeight();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  float cv::MergeMertens::getSaturationWeight()
//

using namespace cv;

JNIEXPORT jfloat JNICALL Java_org_opencv_photo_MergeMertens_getSaturationWeight_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_photo_MergeMertens_getSaturationWeight_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "photo::getSaturationWeight_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::MergeMertens>* me = (Ptr<cv::MergeMertens>*) self; //TODO: check for NULL
        return (*me)->getSaturationWeight();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::MergeMertens::process(vector_Mat src, Mat& dst, Mat times, Mat response)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_photo_MergeMertens_process_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_photo_MergeMertens_process_10
  (JNIEnv* env, jclass , jlong self, jlong src_mat_nativeObj, jlong dst_nativeObj, jlong times_nativeObj, jlong response_nativeObj)
{
    static const char method_name[] = "photo::process_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> src;
        Mat& src_mat = *((Mat*)src_mat_nativeObj);
        Mat_to_vector_Mat( src_mat, src );
        Ptr<cv::MergeMertens>* me = (Ptr<cv::MergeMertens>*) self; //TODO: check for NULL
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& times = *((Mat*)times_nativeObj);
        Mat& response = *((Mat*)response_nativeObj);
        (*me)->process( src, dst, times, response );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::MergeMertens::process(vector_Mat src, Mat& dst)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_photo_MergeMertens_process_11 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_photo_MergeMertens_process_11
  (JNIEnv* env, jclass , jlong self, jlong src_mat_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "photo::process_11()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> src;
        Mat& src_mat = *((Mat*)src_mat_nativeObj);
        Mat_to_vector_Mat( src_mat, src );
        Ptr<cv::MergeMertens>* me = (Ptr<cv::MergeMertens>*) self; //TODO: check for NULL
        Mat& dst = *((Mat*)dst_nativeObj);
        (*me)->process( src, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::MergeMertens::setContrastWeight(float contrast_weiht)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_photo_MergeMertens_setContrastWeight_10 (JNIEnv*, jclass, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_photo_MergeMertens_setContrastWeight_10
  (JNIEnv* env, jclass , jlong self, jfloat contrast_weiht)
{
    static const char method_name[] = "photo::setContrastWeight_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::MergeMertens>* me = (Ptr<cv::MergeMertens>*) self; //TODO: check for NULL
        (*me)->setContrastWeight( (float)contrast_weiht );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::MergeMertens::setExposureWeight(float exposure_weight)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_photo_MergeMertens_setExposureWeight_10 (JNIEnv*, jclass, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_photo_MergeMertens_setExposureWeight_10
  (JNIEnv* env, jclass , jlong self, jfloat exposure_weight)
{
    static const char method_name[] = "photo::setExposureWeight_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::MergeMertens>* me = (Ptr<cv::MergeMertens>*) self; //TODO: check for NULL
        (*me)->setExposureWeight( (float)exposure_weight );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::MergeMertens::setSaturationWeight(float saturation_weight)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_photo_MergeMertens_setSaturationWeight_10 (JNIEnv*, jclass, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_photo_MergeMertens_setSaturationWeight_10
  (JNIEnv* env, jclass , jlong self, jfloat saturation_weight)
{
    static const char method_name[] = "photo::setSaturationWeight_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::MergeMertens>* me = (Ptr<cv::MergeMertens>*) self; //TODO: check for NULL
        (*me)->setSaturationWeight( (float)saturation_weight );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void Ptr<cv::MergeMertens>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_photo_MergeMertens_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_photo_MergeMertens_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::MergeMertens>*) self;
}


//
//  float cv::TonemapMantiuk::getSaturation()
//

using namespace cv;

JNIEXPORT jfloat JNICALL Java_org_opencv_photo_TonemapMantiuk_getSaturation_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_photo_TonemapMantiuk_getSaturation_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "photo::getSaturation_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::TonemapMantiuk>* me = (Ptr<cv::TonemapMantiuk>*) self; //TODO: check for NULL
        return (*me)->getSaturation();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  float cv::TonemapMantiuk::getScale()
//

using namespace cv;

JNIEXPORT jfloat JNICALL Java_org_opencv_photo_TonemapMantiuk_getScale_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_photo_TonemapMantiuk_getScale_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "photo::getScale_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::TonemapMantiuk>* me = (Ptr<cv::TonemapMantiuk>*) self; //TODO: check for NULL
        return (*me)->getScale();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::TonemapMantiuk::setSaturation(float saturation)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_photo_TonemapMantiuk_setSaturation_10 (JNIEnv*, jclass, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_photo_TonemapMantiuk_setSaturation_10
  (JNIEnv* env, jclass , jlong self, jfloat saturation)
{
    static const char method_name[] = "photo::setSaturation_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::TonemapMantiuk>* me = (Ptr<cv::TonemapMantiuk>*) self; //TODO: check for NULL
        (*me)->setSaturation( (float)saturation );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::TonemapMantiuk::setScale(float scale)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_photo_TonemapMantiuk_setScale_10 (JNIEnv*, jclass, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_photo_TonemapMantiuk_setScale_10
  (JNIEnv* env, jclass , jlong self, jfloat scale)
{
    static const char method_name[] = "photo::setScale_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::TonemapMantiuk>* me = (Ptr<cv::TonemapMantiuk>*) self; //TODO: check for NULL
        (*me)->setScale( (float)scale );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void Ptr<cv::TonemapMantiuk>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_photo_TonemapMantiuk_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_photo_TonemapMantiuk_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::TonemapMantiuk>*) self;
}


//
//  Mat cv::CalibrateRobertson::getRadiance()
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_photo_CalibrateRobertson_getRadiance_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_photo_CalibrateRobertson_getRadiance_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "photo::getRadiance_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::CalibrateRobertson>* me = (Ptr<cv::CalibrateRobertson>*) self; //TODO: check for NULL
        ::Mat _retval_ = (*me)->getRadiance();
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  float cv::CalibrateRobertson::getThreshold()
//

using namespace cv;

JNIEXPORT jfloat JNICALL Java_org_opencv_photo_CalibrateRobertson_getThreshold_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_photo_CalibrateRobertson_getThreshold_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "photo::getThreshold_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::CalibrateRobertson>* me = (Ptr<cv::CalibrateRobertson>*) self; //TODO: check for NULL
        return (*me)->getThreshold();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::CalibrateRobertson::getMaxIter()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_photo_CalibrateRobertson_getMaxIter_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_photo_CalibrateRobertson_getMaxIter_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "photo::getMaxIter_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::CalibrateRobertson>* me = (Ptr<cv::CalibrateRobertson>*) self; //TODO: check for NULL
        return (*me)->getMaxIter();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::CalibrateRobertson::setMaxIter(int max_iter)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_photo_CalibrateRobertson_setMaxIter_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_photo_CalibrateRobertson_setMaxIter_10
  (JNIEnv* env, jclass , jlong self, jint max_iter)
{
    static const char method_name[] = "photo::setMaxIter_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::CalibrateRobertson>* me = (Ptr<cv::CalibrateRobertson>*) self; //TODO: check for NULL
        (*me)->setMaxIter( (int)max_iter );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::CalibrateRobertson::setThreshold(float threshold)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_photo_CalibrateRobertson_setThreshold_10 (JNIEnv*, jclass, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_photo_CalibrateRobertson_setThreshold_10
  (JNIEnv* env, jclass , jlong self, jfloat threshold)
{
    static const char method_name[] = "photo::setThreshold_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::CalibrateRobertson>* me = (Ptr<cv::CalibrateRobertson>*) self; //TODO: check for NULL
        (*me)->setThreshold( (float)threshold );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void Ptr<cv::CalibrateRobertson>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_photo_CalibrateRobertson_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_photo_CalibrateRobertson_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::CalibrateRobertson>*) self;
}


//
//  bool cv::CalibrateDebevec::getRandom()
//

using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_photo_CalibrateDebevec_getRandom_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_photo_CalibrateDebevec_getRandom_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "photo::getRandom_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::CalibrateDebevec>* me = (Ptr<cv::CalibrateDebevec>*) self; //TODO: check for NULL
        return (*me)->getRandom();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  float cv::CalibrateDebevec::getLambda()
//

using namespace cv;

JNIEXPORT jfloat JNICALL Java_org_opencv_photo_CalibrateDebevec_getLambda_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_photo_CalibrateDebevec_getLambda_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "photo::getLambda_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::CalibrateDebevec>* me = (Ptr<cv::CalibrateDebevec>*) self; //TODO: check for NULL
        return (*me)->getLambda();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::CalibrateDebevec::getSamples()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_photo_CalibrateDebevec_getSamples_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_photo_CalibrateDebevec_getSamples_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "photo::getSamples_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::CalibrateDebevec>* me = (Ptr<cv::CalibrateDebevec>*) self; //TODO: check for NULL
        return (*me)->getSamples();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::CalibrateDebevec::setLambda(float lambda)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_photo_CalibrateDebevec_setLambda_10 (JNIEnv*, jclass, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_photo_CalibrateDebevec_setLambda_10
  (JNIEnv* env, jclass , jlong self, jfloat lambda)
{
    static const char method_name[] = "photo::setLambda_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::CalibrateDebevec>* me = (Ptr<cv::CalibrateDebevec>*) self; //TODO: check for NULL
        (*me)->setLambda( (float)lambda );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::CalibrateDebevec::setRandom(bool random)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_photo_CalibrateDebevec_setRandom_10 (JNIEnv*, jclass, jlong, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_photo_CalibrateDebevec_setRandom_10
  (JNIEnv* env, jclass , jlong self, jboolean random)
{
    static const char method_name[] = "photo::setRandom_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::CalibrateDebevec>* me = (Ptr<cv::CalibrateDebevec>*) self; //TODO: check for NULL
        (*me)->setRandom( (bool)random );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::CalibrateDebevec::setSamples(int samples)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_photo_CalibrateDebevec_setSamples_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_photo_CalibrateDebevec_setSamples_10
  (JNIEnv* env, jclass , jlong self, jint samples)
{
    static const char method_name[] = "photo::setSamples_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::CalibrateDebevec>* me = (Ptr<cv::CalibrateDebevec>*) self; //TODO: check for NULL
        (*me)->setSamples( (int)samples );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void Ptr<cv::CalibrateDebevec>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_photo_CalibrateDebevec_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_photo_CalibrateDebevec_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::CalibrateDebevec>*) self;
}


//
//  float cv::TonemapReinhard::getColorAdaptation()
//

using namespace cv;

JNIEXPORT jfloat JNICALL Java_org_opencv_photo_TonemapReinhard_getColorAdaptation_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_photo_TonemapReinhard_getColorAdaptation_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "photo::getColorAdaptation_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::TonemapReinhard>* me = (Ptr<cv::TonemapReinhard>*) self; //TODO: check for NULL
        return (*me)->getColorAdaptation();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  float cv::TonemapReinhard::getIntensity()
//

using namespace cv;

JNIEXPORT jfloat JNICALL Java_org_opencv_photo_TonemapReinhard_getIntensity_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_photo_TonemapReinhard_getIntensity_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "photo::getIntensity_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::TonemapReinhard>* me = (Ptr<cv::TonemapReinhard>*) self; //TODO: check for NULL
        return (*me)->getIntensity();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  float cv::TonemapReinhard::getLightAdaptation()
//

using namespace cv;

JNIEXPORT jfloat JNICALL Java_org_opencv_photo_TonemapReinhard_getLightAdaptation_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_photo_TonemapReinhard_getLightAdaptation_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "photo::getLightAdaptation_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::TonemapReinhard>* me = (Ptr<cv::TonemapReinhard>*) self; //TODO: check for NULL
        return (*me)->getLightAdaptation();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::TonemapReinhard::setColorAdaptation(float color_adapt)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_photo_TonemapReinhard_setColorAdaptation_10 (JNIEnv*, jclass, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_photo_TonemapReinhard_setColorAdaptation_10
  (JNIEnv* env, jclass , jlong self, jfloat color_adapt)
{
    static const char method_name[] = "photo::setColorAdaptation_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::TonemapReinhard>* me = (Ptr<cv::TonemapReinhard>*) self; //TODO: check for NULL
        (*me)->setColorAdaptation( (float)color_adapt );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::TonemapReinhard::setIntensity(float intensity)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_photo_TonemapReinhard_setIntensity_10 (JNIEnv*, jclass, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_photo_TonemapReinhard_setIntensity_10
  (JNIEnv* env, jclass , jlong self, jfloat intensity)
{
    static const char method_name[] = "photo::setIntensity_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::TonemapReinhard>* me = (Ptr<cv::TonemapReinhard>*) self; //TODO: check for NULL
        (*me)->setIntensity( (float)intensity );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::TonemapReinhard::setLightAdaptation(float light_adapt)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_photo_TonemapReinhard_setLightAdaptation_10 (JNIEnv*, jclass, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_photo_TonemapReinhard_setLightAdaptation_10
  (JNIEnv* env, jclass , jlong self, jfloat light_adapt)
{
    static const char method_name[] = "photo::setLightAdaptation_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::TonemapReinhard>* me = (Ptr<cv::TonemapReinhard>*) self; //TODO: check for NULL
        (*me)->setLightAdaptation( (float)light_adapt );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void Ptr<cv::TonemapReinhard>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_photo_TonemapReinhard_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_photo_TonemapReinhard_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::TonemapReinhard>*) self;
}


//
//  Ptr_AlignMTB cv::createAlignMTB(int max_bits = 6, int exclude_range = 4, bool cut = true)
//



JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createAlignMTB_10 (JNIEnv*, jclass, jint, jint, jboolean);

JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createAlignMTB_10
  (JNIEnv* env, jclass , jint max_bits, jint exclude_range, jboolean cut)
{
    static const char method_name[] = "photo::createAlignMTB_10()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::AlignMTB> Ptr_AlignMTB;
        Ptr_AlignMTB _retval_ = cv::createAlignMTB( (int)max_bits, (int)exclude_range, (bool)cut );
        return (jlong)(new Ptr_AlignMTB(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createAlignMTB_11 (JNIEnv*, jclass, jint, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createAlignMTB_11
  (JNIEnv* env, jclass , jint max_bits, jint exclude_range)
{
    static const char method_name[] = "photo::createAlignMTB_11()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::AlignMTB> Ptr_AlignMTB;
        Ptr_AlignMTB _retval_ = cv::createAlignMTB( (int)max_bits, (int)exclude_range );
        return (jlong)(new Ptr_AlignMTB(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createAlignMTB_12 (JNIEnv*, jclass, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createAlignMTB_12
  (JNIEnv* env, jclass , jint max_bits)
{
    static const char method_name[] = "photo::createAlignMTB_12()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::AlignMTB> Ptr_AlignMTB;
        Ptr_AlignMTB _retval_ = cv::createAlignMTB( (int)max_bits );
        return (jlong)(new Ptr_AlignMTB(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createAlignMTB_13 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createAlignMTB_13
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "photo::createAlignMTB_13()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::AlignMTB> Ptr_AlignMTB;
        Ptr_AlignMTB _retval_ = cv::createAlignMTB();
        return (jlong)(new Ptr_AlignMTB(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Ptr_CalibrateDebevec cv::createCalibrateDebevec(int samples = 70, float lambda = 10.0f, bool random = false)
//



JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createCalibrateDebevec_10 (JNIEnv*, jclass, jint, jfloat, jboolean);

JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createCalibrateDebevec_10
  (JNIEnv* env, jclass , jint samples, jfloat lambda, jboolean random)
{
    static const char method_name[] = "photo::createCalibrateDebevec_10()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::CalibrateDebevec> Ptr_CalibrateDebevec;
        Ptr_CalibrateDebevec _retval_ = cv::createCalibrateDebevec( (int)samples, (float)lambda, (bool)random );
        return (jlong)(new Ptr_CalibrateDebevec(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createCalibrateDebevec_11 (JNIEnv*, jclass, jint, jfloat);

JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createCalibrateDebevec_11
  (JNIEnv* env, jclass , jint samples, jfloat lambda)
{
    static const char method_name[] = "photo::createCalibrateDebevec_11()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::CalibrateDebevec> Ptr_CalibrateDebevec;
        Ptr_CalibrateDebevec _retval_ = cv::createCalibrateDebevec( (int)samples, (float)lambda );
        return (jlong)(new Ptr_CalibrateDebevec(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createCalibrateDebevec_12 (JNIEnv*, jclass, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createCalibrateDebevec_12
  (JNIEnv* env, jclass , jint samples)
{
    static const char method_name[] = "photo::createCalibrateDebevec_12()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::CalibrateDebevec> Ptr_CalibrateDebevec;
        Ptr_CalibrateDebevec _retval_ = cv::createCalibrateDebevec( (int)samples );
        return (jlong)(new Ptr_CalibrateDebevec(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createCalibrateDebevec_13 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createCalibrateDebevec_13
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "photo::createCalibrateDebevec_13()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::CalibrateDebevec> Ptr_CalibrateDebevec;
        Ptr_CalibrateDebevec _retval_ = cv::createCalibrateDebevec();
        return (jlong)(new Ptr_CalibrateDebevec(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Ptr_CalibrateRobertson cv::createCalibrateRobertson(int max_iter = 30, float threshold = 0.01f)
//



JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createCalibrateRobertson_10 (JNIEnv*, jclass, jint, jfloat);

JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createCalibrateRobertson_10
  (JNIEnv* env, jclass , jint max_iter, jfloat threshold)
{
    static const char method_name[] = "photo::createCalibrateRobertson_10()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::CalibrateRobertson> Ptr_CalibrateRobertson;
        Ptr_CalibrateRobertson _retval_ = cv::createCalibrateRobertson( (int)max_iter, (float)threshold );
        return (jlong)(new Ptr_CalibrateRobertson(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createCalibrateRobertson_11 (JNIEnv*, jclass, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createCalibrateRobertson_11
  (JNIEnv* env, jclass , jint max_iter)
{
    static const char method_name[] = "photo::createCalibrateRobertson_11()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::CalibrateRobertson> Ptr_CalibrateRobertson;
        Ptr_CalibrateRobertson _retval_ = cv::createCalibrateRobertson( (int)max_iter );
        return (jlong)(new Ptr_CalibrateRobertson(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createCalibrateRobertson_12 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createCalibrateRobertson_12
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "photo::createCalibrateRobertson_12()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::CalibrateRobertson> Ptr_CalibrateRobertson;
        Ptr_CalibrateRobertson _retval_ = cv::createCalibrateRobertson();
        return (jlong)(new Ptr_CalibrateRobertson(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Ptr_MergeDebevec cv::createMergeDebevec()
//



JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createMergeDebevec_10 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createMergeDebevec_10
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "photo::createMergeDebevec_10()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::MergeDebevec> Ptr_MergeDebevec;
        Ptr_MergeDebevec _retval_ = cv::createMergeDebevec();
        return (jlong)(new Ptr_MergeDebevec(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Ptr_MergeMertens cv::createMergeMertens(float contrast_weight = 1.0f, float saturation_weight = 1.0f, float exposure_weight = 0.0f)
//



JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createMergeMertens_10 (JNIEnv*, jclass, jfloat, jfloat, jfloat);

JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createMergeMertens_10
  (JNIEnv* env, jclass , jfloat contrast_weight, jfloat saturation_weight, jfloat exposure_weight)
{
    static const char method_name[] = "photo::createMergeMertens_10()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::MergeMertens> Ptr_MergeMertens;
        Ptr_MergeMertens _retval_ = cv::createMergeMertens( (float)contrast_weight, (float)saturation_weight, (float)exposure_weight );
        return (jlong)(new Ptr_MergeMertens(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createMergeMertens_11 (JNIEnv*, jclass, jfloat, jfloat);

JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createMergeMertens_11
  (JNIEnv* env, jclass , jfloat contrast_weight, jfloat saturation_weight)
{
    static const char method_name[] = "photo::createMergeMertens_11()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::MergeMertens> Ptr_MergeMertens;
        Ptr_MergeMertens _retval_ = cv::createMergeMertens( (float)contrast_weight, (float)saturation_weight );
        return (jlong)(new Ptr_MergeMertens(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createMergeMertens_12 (JNIEnv*, jclass, jfloat);

JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createMergeMertens_12
  (JNIEnv* env, jclass , jfloat contrast_weight)
{
    static const char method_name[] = "photo::createMergeMertens_12()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::MergeMertens> Ptr_MergeMertens;
        Ptr_MergeMertens _retval_ = cv::createMergeMertens( (float)contrast_weight );
        return (jlong)(new Ptr_MergeMertens(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createMergeMertens_13 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createMergeMertens_13
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "photo::createMergeMertens_13()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::MergeMertens> Ptr_MergeMertens;
        Ptr_MergeMertens _retval_ = cv::createMergeMertens();
        return (jlong)(new Ptr_MergeMertens(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Ptr_MergeRobertson cv::createMergeRobertson()
//



JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createMergeRobertson_10 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createMergeRobertson_10
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "photo::createMergeRobertson_10()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::MergeRobertson> Ptr_MergeRobertson;
        Ptr_MergeRobertson _retval_ = cv::createMergeRobertson();
        return (jlong)(new Ptr_MergeRobertson(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Ptr_Tonemap cv::createTonemap(float gamma = 1.0f)
//



JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createTonemap_10 (JNIEnv*, jclass, jfloat);

JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createTonemap_10
  (JNIEnv* env, jclass , jfloat gamma)
{
    static const char method_name[] = "photo::createTonemap_10()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::Tonemap> Ptr_Tonemap;
        Ptr_Tonemap _retval_ = cv::createTonemap( (float)gamma );
        return (jlong)(new Ptr_Tonemap(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createTonemap_11 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createTonemap_11
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "photo::createTonemap_11()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::Tonemap> Ptr_Tonemap;
        Ptr_Tonemap _retval_ = cv::createTonemap();
        return (jlong)(new Ptr_Tonemap(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Ptr_TonemapDrago cv::createTonemapDrago(float gamma = 1.0f, float saturation = 1.0f, float bias = 0.85f)
//



JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createTonemapDrago_10 (JNIEnv*, jclass, jfloat, jfloat, jfloat);

JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createTonemapDrago_10
  (JNIEnv* env, jclass , jfloat gamma, jfloat saturation, jfloat bias)
{
    static const char method_name[] = "photo::createTonemapDrago_10()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::TonemapDrago> Ptr_TonemapDrago;
        Ptr_TonemapDrago _retval_ = cv::createTonemapDrago( (float)gamma, (float)saturation, (float)bias );
        return (jlong)(new Ptr_TonemapDrago(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createTonemapDrago_11 (JNIEnv*, jclass, jfloat, jfloat);

JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createTonemapDrago_11
  (JNIEnv* env, jclass , jfloat gamma, jfloat saturation)
{
    static const char method_name[] = "photo::createTonemapDrago_11()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::TonemapDrago> Ptr_TonemapDrago;
        Ptr_TonemapDrago _retval_ = cv::createTonemapDrago( (float)gamma, (float)saturation );
        return (jlong)(new Ptr_TonemapDrago(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createTonemapDrago_12 (JNIEnv*, jclass, jfloat);

JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createTonemapDrago_12
  (JNIEnv* env, jclass , jfloat gamma)
{
    static const char method_name[] = "photo::createTonemapDrago_12()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::TonemapDrago> Ptr_TonemapDrago;
        Ptr_TonemapDrago _retval_ = cv::createTonemapDrago( (float)gamma );
        return (jlong)(new Ptr_TonemapDrago(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createTonemapDrago_13 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createTonemapDrago_13
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "photo::createTonemapDrago_13()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::TonemapDrago> Ptr_TonemapDrago;
        Ptr_TonemapDrago _retval_ = cv::createTonemapDrago();
        return (jlong)(new Ptr_TonemapDrago(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Ptr_TonemapMantiuk cv::createTonemapMantiuk(float gamma = 1.0f, float scale = 0.7f, float saturation = 1.0f)
//



JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createTonemapMantiuk_10 (JNIEnv*, jclass, jfloat, jfloat, jfloat);

JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createTonemapMantiuk_10
  (JNIEnv* env, jclass , jfloat gamma, jfloat scale, jfloat saturation)
{
    static const char method_name[] = "photo::createTonemapMantiuk_10()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::TonemapMantiuk> Ptr_TonemapMantiuk;
        Ptr_TonemapMantiuk _retval_ = cv::createTonemapMantiuk( (float)gamma, (float)scale, (float)saturation );
        return (jlong)(new Ptr_TonemapMantiuk(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createTonemapMantiuk_11 (JNIEnv*, jclass, jfloat, jfloat);

JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createTonemapMantiuk_11
  (JNIEnv* env, jclass , jfloat gamma, jfloat scale)
{
    static const char method_name[] = "photo::createTonemapMantiuk_11()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::TonemapMantiuk> Ptr_TonemapMantiuk;
        Ptr_TonemapMantiuk _retval_ = cv::createTonemapMantiuk( (float)gamma, (float)scale );
        return (jlong)(new Ptr_TonemapMantiuk(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createTonemapMantiuk_12 (JNIEnv*, jclass, jfloat);

JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createTonemapMantiuk_12
  (JNIEnv* env, jclass , jfloat gamma)
{
    static const char method_name[] = "photo::createTonemapMantiuk_12()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::TonemapMantiuk> Ptr_TonemapMantiuk;
        Ptr_TonemapMantiuk _retval_ = cv::createTonemapMantiuk( (float)gamma );
        return (jlong)(new Ptr_TonemapMantiuk(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createTonemapMantiuk_13 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createTonemapMantiuk_13
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "photo::createTonemapMantiuk_13()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::TonemapMantiuk> Ptr_TonemapMantiuk;
        Ptr_TonemapMantiuk _retval_ = cv::createTonemapMantiuk();
        return (jlong)(new Ptr_TonemapMantiuk(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Ptr_TonemapReinhard cv::createTonemapReinhard(float gamma = 1.0f, float intensity = 0.0f, float light_adapt = 1.0f, float color_adapt = 0.0f)
//



JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createTonemapReinhard_10 (JNIEnv*, jclass, jfloat, jfloat, jfloat, jfloat);

JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createTonemapReinhard_10
  (JNIEnv* env, jclass , jfloat gamma, jfloat intensity, jfloat light_adapt, jfloat color_adapt)
{
    static const char method_name[] = "photo::createTonemapReinhard_10()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::TonemapReinhard> Ptr_TonemapReinhard;
        Ptr_TonemapReinhard _retval_ = cv::createTonemapReinhard( (float)gamma, (float)intensity, (float)light_adapt, (float)color_adapt );
        return (jlong)(new Ptr_TonemapReinhard(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createTonemapReinhard_11 (JNIEnv*, jclass, jfloat, jfloat, jfloat);

JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createTonemapReinhard_11
  (JNIEnv* env, jclass , jfloat gamma, jfloat intensity, jfloat light_adapt)
{
    static const char method_name[] = "photo::createTonemapReinhard_11()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::TonemapReinhard> Ptr_TonemapReinhard;
        Ptr_TonemapReinhard _retval_ = cv::createTonemapReinhard( (float)gamma, (float)intensity, (float)light_adapt );
        return (jlong)(new Ptr_TonemapReinhard(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createTonemapReinhard_12 (JNIEnv*, jclass, jfloat, jfloat);

JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createTonemapReinhard_12
  (JNIEnv* env, jclass , jfloat gamma, jfloat intensity)
{
    static const char method_name[] = "photo::createTonemapReinhard_12()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::TonemapReinhard> Ptr_TonemapReinhard;
        Ptr_TonemapReinhard _retval_ = cv::createTonemapReinhard( (float)gamma, (float)intensity );
        return (jlong)(new Ptr_TonemapReinhard(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createTonemapReinhard_13 (JNIEnv*, jclass, jfloat);

JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createTonemapReinhard_13
  (JNIEnv* env, jclass , jfloat gamma)
{
    static const char method_name[] = "photo::createTonemapReinhard_13()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::TonemapReinhard> Ptr_TonemapReinhard;
        Ptr_TonemapReinhard _retval_ = cv::createTonemapReinhard( (float)gamma );
        return (jlong)(new Ptr_TonemapReinhard(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createTonemapReinhard_14 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_photo_Photo_createTonemapReinhard_14
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "photo::createTonemapReinhard_14()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::TonemapReinhard> Ptr_TonemapReinhard;
        Ptr_TonemapReinhard _retval_ = cv::createTonemapReinhard();
        return (jlong)(new Ptr_TonemapReinhard(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::colorChange(Mat src, Mat mask, Mat& dst, float red_mul = 1.0f, float green_mul = 1.0f, float blue_mul = 1.0f)
//



JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_colorChange_10 (JNIEnv*, jclass, jlong, jlong, jlong, jfloat, jfloat, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_colorChange_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong mask_nativeObj, jlong dst_nativeObj, jfloat red_mul, jfloat green_mul, jfloat blue_mul)
{
    static const char method_name[] = "photo::colorChange_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::colorChange( src, mask, dst, (float)red_mul, (float)green_mul, (float)blue_mul );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_colorChange_11 (JNIEnv*, jclass, jlong, jlong, jlong, jfloat, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_colorChange_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong mask_nativeObj, jlong dst_nativeObj, jfloat red_mul, jfloat green_mul)
{
    static const char method_name[] = "photo::colorChange_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::colorChange( src, mask, dst, (float)red_mul, (float)green_mul );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_colorChange_12 (JNIEnv*, jclass, jlong, jlong, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_colorChange_12
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong mask_nativeObj, jlong dst_nativeObj, jfloat red_mul)
{
    static const char method_name[] = "photo::colorChange_12()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::colorChange( src, mask, dst, (float)red_mul );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_colorChange_13 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_colorChange_13
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong mask_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "photo::colorChange_13()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::colorChange( src, mask, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::decolor(Mat src, Mat& grayscale, Mat& color_boost)
//



JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_decolor_10 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_decolor_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong grayscale_nativeObj, jlong color_boost_nativeObj)
{
    static const char method_name[] = "photo::decolor_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& grayscale = *((Mat*)grayscale_nativeObj);
        Mat& color_boost = *((Mat*)color_boost_nativeObj);
        cv::decolor( src, grayscale, color_boost );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::denoise_TVL1(vector_Mat observations, Mat result, double lambda = 1.0, int niters = 30)
//



JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_denoise_1TVL1_10 (JNIEnv*, jclass, jlong, jlong, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_denoise_1TVL1_10
  (JNIEnv* env, jclass , jlong observations_mat_nativeObj, jlong result_nativeObj, jdouble lambda, jint niters)
{
    static const char method_name[] = "photo::denoise_1TVL1_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> observations;
        Mat& observations_mat = *((Mat*)observations_mat_nativeObj);
        Mat_to_vector_Mat( observations_mat, observations );
        Mat& result = *((Mat*)result_nativeObj);
        cv::denoise_TVL1( observations, result, (double)lambda, (int)niters );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_denoise_1TVL1_11 (JNIEnv*, jclass, jlong, jlong, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_denoise_1TVL1_11
  (JNIEnv* env, jclass , jlong observations_mat_nativeObj, jlong result_nativeObj, jdouble lambda)
{
    static const char method_name[] = "photo::denoise_1TVL1_11()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> observations;
        Mat& observations_mat = *((Mat*)observations_mat_nativeObj);
        Mat_to_vector_Mat( observations_mat, observations );
        Mat& result = *((Mat*)result_nativeObj);
        cv::denoise_TVL1( observations, result, (double)lambda );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_denoise_1TVL1_12 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_denoise_1TVL1_12
  (JNIEnv* env, jclass , jlong observations_mat_nativeObj, jlong result_nativeObj)
{
    static const char method_name[] = "photo::denoise_1TVL1_12()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> observations;
        Mat& observations_mat = *((Mat*)observations_mat_nativeObj);
        Mat_to_vector_Mat( observations_mat, observations );
        Mat& result = *((Mat*)result_nativeObj);
        cv::denoise_TVL1( observations, result );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::detailEnhance(Mat src, Mat& dst, float sigma_s = 10, float sigma_r = 0.15f)
//



JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_detailEnhance_10 (JNIEnv*, jclass, jlong, jlong, jfloat, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_detailEnhance_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jfloat sigma_s, jfloat sigma_r)
{
    static const char method_name[] = "photo::detailEnhance_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::detailEnhance( src, dst, (float)sigma_s, (float)sigma_r );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_detailEnhance_11 (JNIEnv*, jclass, jlong, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_detailEnhance_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jfloat sigma_s)
{
    static const char method_name[] = "photo::detailEnhance_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::detailEnhance( src, dst, (float)sigma_s );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_detailEnhance_12 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_detailEnhance_12
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "photo::detailEnhance_12()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::detailEnhance( src, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::edgePreservingFilter(Mat src, Mat& dst, int flags = 1, float sigma_s = 60, float sigma_r = 0.4f)
//



JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_edgePreservingFilter_10 (JNIEnv*, jclass, jlong, jlong, jint, jfloat, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_edgePreservingFilter_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint flags, jfloat sigma_s, jfloat sigma_r)
{
    static const char method_name[] = "photo::edgePreservingFilter_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::edgePreservingFilter( src, dst, (int)flags, (float)sigma_s, (float)sigma_r );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_edgePreservingFilter_11 (JNIEnv*, jclass, jlong, jlong, jint, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_edgePreservingFilter_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint flags, jfloat sigma_s)
{
    static const char method_name[] = "photo::edgePreservingFilter_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::edgePreservingFilter( src, dst, (int)flags, (float)sigma_s );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_edgePreservingFilter_12 (JNIEnv*, jclass, jlong, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_edgePreservingFilter_12
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint flags)
{
    static const char method_name[] = "photo::edgePreservingFilter_12()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::edgePreservingFilter( src, dst, (int)flags );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_edgePreservingFilter_13 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_edgePreservingFilter_13
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "photo::edgePreservingFilter_13()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::edgePreservingFilter( src, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::fastNlMeansDenoising(Mat src, Mat& dst, float h = 3, int templateWindowSize = 7, int searchWindowSize = 21)
//



JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoising_10 (JNIEnv*, jclass, jlong, jlong, jfloat, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoising_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jfloat h, jint templateWindowSize, jint searchWindowSize)
{
    static const char method_name[] = "photo::fastNlMeansDenoising_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::fastNlMeansDenoising( src, dst, (float)h, (int)templateWindowSize, (int)searchWindowSize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoising_11 (JNIEnv*, jclass, jlong, jlong, jfloat, jint);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoising_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jfloat h, jint templateWindowSize)
{
    static const char method_name[] = "photo::fastNlMeansDenoising_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::fastNlMeansDenoising( src, dst, (float)h, (int)templateWindowSize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoising_12 (JNIEnv*, jclass, jlong, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoising_12
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jfloat h)
{
    static const char method_name[] = "photo::fastNlMeansDenoising_12()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::fastNlMeansDenoising( src, dst, (float)h );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoising_13 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoising_13
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "photo::fastNlMeansDenoising_13()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::fastNlMeansDenoising( src, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::fastNlMeansDenoising(Mat src, Mat& dst, vector_float h, int templateWindowSize = 7, int searchWindowSize = 21, int normType = NORM_L2)
//



JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoising_14 (JNIEnv*, jclass, jlong, jlong, jlong, jint, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoising_14
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jlong h_mat_nativeObj, jint templateWindowSize, jint searchWindowSize, jint normType)
{
    static const char method_name[] = "photo::fastNlMeansDenoising_14()";
    try {
        LOGD("%s", method_name);
        std::vector<float> h;
        Mat& h_mat = *((Mat*)h_mat_nativeObj);
        Mat_to_vector_float( h_mat, h );
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::fastNlMeansDenoising( src, dst, h, (int)templateWindowSize, (int)searchWindowSize, (int)normType );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoising_15 (JNIEnv*, jclass, jlong, jlong, jlong, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoising_15
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jlong h_mat_nativeObj, jint templateWindowSize, jint searchWindowSize)
{
    static const char method_name[] = "photo::fastNlMeansDenoising_15()";
    try {
        LOGD("%s", method_name);
        std::vector<float> h;
        Mat& h_mat = *((Mat*)h_mat_nativeObj);
        Mat_to_vector_float( h_mat, h );
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::fastNlMeansDenoising( src, dst, h, (int)templateWindowSize, (int)searchWindowSize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoising_16 (JNIEnv*, jclass, jlong, jlong, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoising_16
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jlong h_mat_nativeObj, jint templateWindowSize)
{
    static const char method_name[] = "photo::fastNlMeansDenoising_16()";
    try {
        LOGD("%s", method_name);
        std::vector<float> h;
        Mat& h_mat = *((Mat*)h_mat_nativeObj);
        Mat_to_vector_float( h_mat, h );
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::fastNlMeansDenoising( src, dst, h, (int)templateWindowSize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoising_17 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoising_17
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jlong h_mat_nativeObj)
{
    static const char method_name[] = "photo::fastNlMeansDenoising_17()";
    try {
        LOGD("%s", method_name);
        std::vector<float> h;
        Mat& h_mat = *((Mat*)h_mat_nativeObj);
        Mat_to_vector_float( h_mat, h );
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::fastNlMeansDenoising( src, dst, h );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::fastNlMeansDenoisingColored(Mat src, Mat& dst, float h = 3, float hColor = 3, int templateWindowSize = 7, int searchWindowSize = 21)
//



JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoisingColored_10 (JNIEnv*, jclass, jlong, jlong, jfloat, jfloat, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoisingColored_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jfloat h, jfloat hColor, jint templateWindowSize, jint searchWindowSize)
{
    static const char method_name[] = "photo::fastNlMeansDenoisingColored_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::fastNlMeansDenoisingColored( src, dst, (float)h, (float)hColor, (int)templateWindowSize, (int)searchWindowSize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoisingColored_11 (JNIEnv*, jclass, jlong, jlong, jfloat, jfloat, jint);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoisingColored_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jfloat h, jfloat hColor, jint templateWindowSize)
{
    static const char method_name[] = "photo::fastNlMeansDenoisingColored_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::fastNlMeansDenoisingColored( src, dst, (float)h, (float)hColor, (int)templateWindowSize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoisingColored_12 (JNIEnv*, jclass, jlong, jlong, jfloat, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoisingColored_12
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jfloat h, jfloat hColor)
{
    static const char method_name[] = "photo::fastNlMeansDenoisingColored_12()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::fastNlMeansDenoisingColored( src, dst, (float)h, (float)hColor );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoisingColored_13 (JNIEnv*, jclass, jlong, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoisingColored_13
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jfloat h)
{
    static const char method_name[] = "photo::fastNlMeansDenoisingColored_13()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::fastNlMeansDenoisingColored( src, dst, (float)h );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoisingColored_14 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoisingColored_14
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "photo::fastNlMeansDenoisingColored_14()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::fastNlMeansDenoisingColored( src, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::fastNlMeansDenoisingColoredMulti(vector_Mat srcImgs, Mat& dst, int imgToDenoiseIndex, int temporalWindowSize, float h = 3, float hColor = 3, int templateWindowSize = 7, int searchWindowSize = 21)
//



JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoisingColoredMulti_10 (JNIEnv*, jclass, jlong, jlong, jint, jint, jfloat, jfloat, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoisingColoredMulti_10
  (JNIEnv* env, jclass , jlong srcImgs_mat_nativeObj, jlong dst_nativeObj, jint imgToDenoiseIndex, jint temporalWindowSize, jfloat h, jfloat hColor, jint templateWindowSize, jint searchWindowSize)
{
    static const char method_name[] = "photo::fastNlMeansDenoisingColoredMulti_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> srcImgs;
        Mat& srcImgs_mat = *((Mat*)srcImgs_mat_nativeObj);
        Mat_to_vector_Mat( srcImgs_mat, srcImgs );
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::fastNlMeansDenoisingColoredMulti( srcImgs, dst, (int)imgToDenoiseIndex, (int)temporalWindowSize, (float)h, (float)hColor, (int)templateWindowSize, (int)searchWindowSize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoisingColoredMulti_11 (JNIEnv*, jclass, jlong, jlong, jint, jint, jfloat, jfloat, jint);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoisingColoredMulti_11
  (JNIEnv* env, jclass , jlong srcImgs_mat_nativeObj, jlong dst_nativeObj, jint imgToDenoiseIndex, jint temporalWindowSize, jfloat h, jfloat hColor, jint templateWindowSize)
{
    static const char method_name[] = "photo::fastNlMeansDenoisingColoredMulti_11()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> srcImgs;
        Mat& srcImgs_mat = *((Mat*)srcImgs_mat_nativeObj);
        Mat_to_vector_Mat( srcImgs_mat, srcImgs );
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::fastNlMeansDenoisingColoredMulti( srcImgs, dst, (int)imgToDenoiseIndex, (int)temporalWindowSize, (float)h, (float)hColor, (int)templateWindowSize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoisingColoredMulti_12 (JNIEnv*, jclass, jlong, jlong, jint, jint, jfloat, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoisingColoredMulti_12
  (JNIEnv* env, jclass , jlong srcImgs_mat_nativeObj, jlong dst_nativeObj, jint imgToDenoiseIndex, jint temporalWindowSize, jfloat h, jfloat hColor)
{
    static const char method_name[] = "photo::fastNlMeansDenoisingColoredMulti_12()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> srcImgs;
        Mat& srcImgs_mat = *((Mat*)srcImgs_mat_nativeObj);
        Mat_to_vector_Mat( srcImgs_mat, srcImgs );
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::fastNlMeansDenoisingColoredMulti( srcImgs, dst, (int)imgToDenoiseIndex, (int)temporalWindowSize, (float)h, (float)hColor );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoisingColoredMulti_13 (JNIEnv*, jclass, jlong, jlong, jint, jint, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoisingColoredMulti_13
  (JNIEnv* env, jclass , jlong srcImgs_mat_nativeObj, jlong dst_nativeObj, jint imgToDenoiseIndex, jint temporalWindowSize, jfloat h)
{
    static const char method_name[] = "photo::fastNlMeansDenoisingColoredMulti_13()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> srcImgs;
        Mat& srcImgs_mat = *((Mat*)srcImgs_mat_nativeObj);
        Mat_to_vector_Mat( srcImgs_mat, srcImgs );
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::fastNlMeansDenoisingColoredMulti( srcImgs, dst, (int)imgToDenoiseIndex, (int)temporalWindowSize, (float)h );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoisingColoredMulti_14 (JNIEnv*, jclass, jlong, jlong, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoisingColoredMulti_14
  (JNIEnv* env, jclass , jlong srcImgs_mat_nativeObj, jlong dst_nativeObj, jint imgToDenoiseIndex, jint temporalWindowSize)
{
    static const char method_name[] = "photo::fastNlMeansDenoisingColoredMulti_14()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> srcImgs;
        Mat& srcImgs_mat = *((Mat*)srcImgs_mat_nativeObj);
        Mat_to_vector_Mat( srcImgs_mat, srcImgs );
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::fastNlMeansDenoisingColoredMulti( srcImgs, dst, (int)imgToDenoiseIndex, (int)temporalWindowSize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::fastNlMeansDenoisingMulti(vector_Mat srcImgs, Mat& dst, int imgToDenoiseIndex, int temporalWindowSize, float h = 3, int templateWindowSize = 7, int searchWindowSize = 21)
//



JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoisingMulti_10 (JNIEnv*, jclass, jlong, jlong, jint, jint, jfloat, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoisingMulti_10
  (JNIEnv* env, jclass , jlong srcImgs_mat_nativeObj, jlong dst_nativeObj, jint imgToDenoiseIndex, jint temporalWindowSize, jfloat h, jint templateWindowSize, jint searchWindowSize)
{
    static const char method_name[] = "photo::fastNlMeansDenoisingMulti_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> srcImgs;
        Mat& srcImgs_mat = *((Mat*)srcImgs_mat_nativeObj);
        Mat_to_vector_Mat( srcImgs_mat, srcImgs );
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::fastNlMeansDenoisingMulti( srcImgs, dst, (int)imgToDenoiseIndex, (int)temporalWindowSize, (float)h, (int)templateWindowSize, (int)searchWindowSize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoisingMulti_11 (JNIEnv*, jclass, jlong, jlong, jint, jint, jfloat, jint);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoisingMulti_11
  (JNIEnv* env, jclass , jlong srcImgs_mat_nativeObj, jlong dst_nativeObj, jint imgToDenoiseIndex, jint temporalWindowSize, jfloat h, jint templateWindowSize)
{
    static const char method_name[] = "photo::fastNlMeansDenoisingMulti_11()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> srcImgs;
        Mat& srcImgs_mat = *((Mat*)srcImgs_mat_nativeObj);
        Mat_to_vector_Mat( srcImgs_mat, srcImgs );
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::fastNlMeansDenoisingMulti( srcImgs, dst, (int)imgToDenoiseIndex, (int)temporalWindowSize, (float)h, (int)templateWindowSize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoisingMulti_12 (JNIEnv*, jclass, jlong, jlong, jint, jint, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoisingMulti_12
  (JNIEnv* env, jclass , jlong srcImgs_mat_nativeObj, jlong dst_nativeObj, jint imgToDenoiseIndex, jint temporalWindowSize, jfloat h)
{
    static const char method_name[] = "photo::fastNlMeansDenoisingMulti_12()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> srcImgs;
        Mat& srcImgs_mat = *((Mat*)srcImgs_mat_nativeObj);
        Mat_to_vector_Mat( srcImgs_mat, srcImgs );
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::fastNlMeansDenoisingMulti( srcImgs, dst, (int)imgToDenoiseIndex, (int)temporalWindowSize, (float)h );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoisingMulti_13 (JNIEnv*, jclass, jlong, jlong, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoisingMulti_13
  (JNIEnv* env, jclass , jlong srcImgs_mat_nativeObj, jlong dst_nativeObj, jint imgToDenoiseIndex, jint temporalWindowSize)
{
    static const char method_name[] = "photo::fastNlMeansDenoisingMulti_13()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> srcImgs;
        Mat& srcImgs_mat = *((Mat*)srcImgs_mat_nativeObj);
        Mat_to_vector_Mat( srcImgs_mat, srcImgs );
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::fastNlMeansDenoisingMulti( srcImgs, dst, (int)imgToDenoiseIndex, (int)temporalWindowSize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::fastNlMeansDenoisingMulti(vector_Mat srcImgs, Mat& dst, int imgToDenoiseIndex, int temporalWindowSize, vector_float h, int templateWindowSize = 7, int searchWindowSize = 21, int normType = NORM_L2)
//



JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoisingMulti_14 (JNIEnv*, jclass, jlong, jlong, jint, jint, jlong, jint, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoisingMulti_14
  (JNIEnv* env, jclass , jlong srcImgs_mat_nativeObj, jlong dst_nativeObj, jint imgToDenoiseIndex, jint temporalWindowSize, jlong h_mat_nativeObj, jint templateWindowSize, jint searchWindowSize, jint normType)
{
    static const char method_name[] = "photo::fastNlMeansDenoisingMulti_14()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> srcImgs;
        Mat& srcImgs_mat = *((Mat*)srcImgs_mat_nativeObj);
        Mat_to_vector_Mat( srcImgs_mat, srcImgs );
        std::vector<float> h;
        Mat& h_mat = *((Mat*)h_mat_nativeObj);
        Mat_to_vector_float( h_mat, h );
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::fastNlMeansDenoisingMulti( srcImgs, dst, (int)imgToDenoiseIndex, (int)temporalWindowSize, h, (int)templateWindowSize, (int)searchWindowSize, (int)normType );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoisingMulti_15 (JNIEnv*, jclass, jlong, jlong, jint, jint, jlong, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoisingMulti_15
  (JNIEnv* env, jclass , jlong srcImgs_mat_nativeObj, jlong dst_nativeObj, jint imgToDenoiseIndex, jint temporalWindowSize, jlong h_mat_nativeObj, jint templateWindowSize, jint searchWindowSize)
{
    static const char method_name[] = "photo::fastNlMeansDenoisingMulti_15()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> srcImgs;
        Mat& srcImgs_mat = *((Mat*)srcImgs_mat_nativeObj);
        Mat_to_vector_Mat( srcImgs_mat, srcImgs );
        std::vector<float> h;
        Mat& h_mat = *((Mat*)h_mat_nativeObj);
        Mat_to_vector_float( h_mat, h );
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::fastNlMeansDenoisingMulti( srcImgs, dst, (int)imgToDenoiseIndex, (int)temporalWindowSize, h, (int)templateWindowSize, (int)searchWindowSize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoisingMulti_16 (JNIEnv*, jclass, jlong, jlong, jint, jint, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoisingMulti_16
  (JNIEnv* env, jclass , jlong srcImgs_mat_nativeObj, jlong dst_nativeObj, jint imgToDenoiseIndex, jint temporalWindowSize, jlong h_mat_nativeObj, jint templateWindowSize)
{
    static const char method_name[] = "photo::fastNlMeansDenoisingMulti_16()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> srcImgs;
        Mat& srcImgs_mat = *((Mat*)srcImgs_mat_nativeObj);
        Mat_to_vector_Mat( srcImgs_mat, srcImgs );
        std::vector<float> h;
        Mat& h_mat = *((Mat*)h_mat_nativeObj);
        Mat_to_vector_float( h_mat, h );
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::fastNlMeansDenoisingMulti( srcImgs, dst, (int)imgToDenoiseIndex, (int)temporalWindowSize, h, (int)templateWindowSize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoisingMulti_17 (JNIEnv*, jclass, jlong, jlong, jint, jint, jlong);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_fastNlMeansDenoisingMulti_17
  (JNIEnv* env, jclass , jlong srcImgs_mat_nativeObj, jlong dst_nativeObj, jint imgToDenoiseIndex, jint temporalWindowSize, jlong h_mat_nativeObj)
{
    static const char method_name[] = "photo::fastNlMeansDenoisingMulti_17()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> srcImgs;
        Mat& srcImgs_mat = *((Mat*)srcImgs_mat_nativeObj);
        Mat_to_vector_Mat( srcImgs_mat, srcImgs );
        std::vector<float> h;
        Mat& h_mat = *((Mat*)h_mat_nativeObj);
        Mat_to_vector_float( h_mat, h );
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::fastNlMeansDenoisingMulti( srcImgs, dst, (int)imgToDenoiseIndex, (int)temporalWindowSize, h );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::illuminationChange(Mat src, Mat mask, Mat& dst, float alpha = 0.2f, float beta = 0.4f)
//



JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_illuminationChange_10 (JNIEnv*, jclass, jlong, jlong, jlong, jfloat, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_illuminationChange_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong mask_nativeObj, jlong dst_nativeObj, jfloat alpha, jfloat beta)
{
    static const char method_name[] = "photo::illuminationChange_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::illuminationChange( src, mask, dst, (float)alpha, (float)beta );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_illuminationChange_11 (JNIEnv*, jclass, jlong, jlong, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_illuminationChange_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong mask_nativeObj, jlong dst_nativeObj, jfloat alpha)
{
    static const char method_name[] = "photo::illuminationChange_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::illuminationChange( src, mask, dst, (float)alpha );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_illuminationChange_12 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_illuminationChange_12
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong mask_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "photo::illuminationChange_12()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::illuminationChange( src, mask, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::inpaint(Mat src, Mat inpaintMask, Mat& dst, double inpaintRadius, int flags)
//



JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_inpaint_10 (JNIEnv*, jclass, jlong, jlong, jlong, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_inpaint_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong inpaintMask_nativeObj, jlong dst_nativeObj, jdouble inpaintRadius, jint flags)
{
    static const char method_name[] = "photo::inpaint_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& inpaintMask = *((Mat*)inpaintMask_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::inpaint( src, inpaintMask, dst, (double)inpaintRadius, (int)flags );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::pencilSketch(Mat src, Mat& dst1, Mat& dst2, float sigma_s = 60, float sigma_r = 0.07f, float shade_factor = 0.02f)
//



JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_pencilSketch_10 (JNIEnv*, jclass, jlong, jlong, jlong, jfloat, jfloat, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_pencilSketch_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst1_nativeObj, jlong dst2_nativeObj, jfloat sigma_s, jfloat sigma_r, jfloat shade_factor)
{
    static const char method_name[] = "photo::pencilSketch_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst1 = *((Mat*)dst1_nativeObj);
        Mat& dst2 = *((Mat*)dst2_nativeObj);
        cv::pencilSketch( src, dst1, dst2, (float)sigma_s, (float)sigma_r, (float)shade_factor );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_pencilSketch_11 (JNIEnv*, jclass, jlong, jlong, jlong, jfloat, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_pencilSketch_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst1_nativeObj, jlong dst2_nativeObj, jfloat sigma_s, jfloat sigma_r)
{
    static const char method_name[] = "photo::pencilSketch_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst1 = *((Mat*)dst1_nativeObj);
        Mat& dst2 = *((Mat*)dst2_nativeObj);
        cv::pencilSketch( src, dst1, dst2, (float)sigma_s, (float)sigma_r );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_pencilSketch_12 (JNIEnv*, jclass, jlong, jlong, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_pencilSketch_12
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst1_nativeObj, jlong dst2_nativeObj, jfloat sigma_s)
{
    static const char method_name[] = "photo::pencilSketch_12()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst1 = *((Mat*)dst1_nativeObj);
        Mat& dst2 = *((Mat*)dst2_nativeObj);
        cv::pencilSketch( src, dst1, dst2, (float)sigma_s );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_pencilSketch_13 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_pencilSketch_13
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst1_nativeObj, jlong dst2_nativeObj)
{
    static const char method_name[] = "photo::pencilSketch_13()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst1 = *((Mat*)dst1_nativeObj);
        Mat& dst2 = *((Mat*)dst2_nativeObj);
        cv::pencilSketch( src, dst1, dst2 );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::seamlessClone(Mat src, Mat dst, Mat mask, Point p, Mat& blend, int flags)
//



JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_seamlessClone_10 (JNIEnv*, jclass, jlong, jlong, jlong, jdouble, jdouble, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_seamlessClone_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jlong mask_nativeObj, jdouble p_x, jdouble p_y, jlong blend_nativeObj, jint flags)
{
    static const char method_name[] = "photo::seamlessClone_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        Point p((int)p_x, (int)p_y);
        Mat& blend = *((Mat*)blend_nativeObj);
        cv::seamlessClone( src, dst, mask, p, blend, (int)flags );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::stylization(Mat src, Mat& dst, float sigma_s = 60, float sigma_r = 0.45f)
//



JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_stylization_10 (JNIEnv*, jclass, jlong, jlong, jfloat, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_stylization_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jfloat sigma_s, jfloat sigma_r)
{
    static const char method_name[] = "photo::stylization_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::stylization( src, dst, (float)sigma_s, (float)sigma_r );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_stylization_11 (JNIEnv*, jclass, jlong, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_stylization_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jfloat sigma_s)
{
    static const char method_name[] = "photo::stylization_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::stylization( src, dst, (float)sigma_s );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_stylization_12 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_stylization_12
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "photo::stylization_12()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::stylization( src, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::textureFlattening(Mat src, Mat mask, Mat& dst, float low_threshold = 30, float high_threshold = 45, int kernel_size = 3)
//



JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_textureFlattening_10 (JNIEnv*, jclass, jlong, jlong, jlong, jfloat, jfloat, jint);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_textureFlattening_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong mask_nativeObj, jlong dst_nativeObj, jfloat low_threshold, jfloat high_threshold, jint kernel_size)
{
    static const char method_name[] = "photo::textureFlattening_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::textureFlattening( src, mask, dst, (float)low_threshold, (float)high_threshold, (int)kernel_size );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_textureFlattening_11 (JNIEnv*, jclass, jlong, jlong, jlong, jfloat, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_textureFlattening_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong mask_nativeObj, jlong dst_nativeObj, jfloat low_threshold, jfloat high_threshold)
{
    static const char method_name[] = "photo::textureFlattening_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::textureFlattening( src, mask, dst, (float)low_threshold, (float)high_threshold );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_textureFlattening_12 (JNIEnv*, jclass, jlong, jlong, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_textureFlattening_12
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong mask_nativeObj, jlong dst_nativeObj, jfloat low_threshold)
{
    static const char method_name[] = "photo::textureFlattening_12()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::textureFlattening( src, mask, dst, (float)low_threshold );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_textureFlattening_13 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_photo_Photo_textureFlattening_13
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong mask_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "photo::textureFlattening_13()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::textureFlattening( src, mask, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::AlignExposures::process(vector_Mat src, vector_Mat dst, Mat times, Mat response)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_photo_AlignExposures_process_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_photo_AlignExposures_process_10
  (JNIEnv* env, jclass , jlong self, jlong src_mat_nativeObj, jlong dst_mat_nativeObj, jlong times_nativeObj, jlong response_nativeObj)
{
    static const char method_name[] = "photo::process_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> src;
        Mat& src_mat = *((Mat*)src_mat_nativeObj);
        Mat_to_vector_Mat( src_mat, src );
        std::vector<Mat> dst;
        Mat& dst_mat = *((Mat*)dst_mat_nativeObj);
        Mat_to_vector_Mat( dst_mat, dst );
        Ptr<cv::AlignExposures>* me = (Ptr<cv::AlignExposures>*) self; //TODO: check for NULL
        Mat& times = *((Mat*)times_nativeObj);
        Mat& response = *((Mat*)response_nativeObj);
        (*me)->process( src, dst, times, response );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void Ptr<cv::AlignExposures>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_photo_AlignExposures_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_photo_AlignExposures_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::AlignExposures>*) self;
}


//
//  void cv::CalibrateCRF::process(vector_Mat src, Mat& dst, Mat times)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_photo_CalibrateCRF_process_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_photo_CalibrateCRF_process_10
  (JNIEnv* env, jclass , jlong self, jlong src_mat_nativeObj, jlong dst_nativeObj, jlong times_nativeObj)
{
    static const char method_name[] = "photo::process_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> src;
        Mat& src_mat = *((Mat*)src_mat_nativeObj);
        Mat_to_vector_Mat( src_mat, src );
        Ptr<cv::CalibrateCRF>* me = (Ptr<cv::CalibrateCRF>*) self; //TODO: check for NULL
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& times = *((Mat*)times_nativeObj);
        (*me)->process( src, dst, times );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void Ptr<cv::CalibrateCRF>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_photo_CalibrateCRF_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_photo_CalibrateCRF_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::CalibrateCRF>*) self;
}


//
//  float cv::TonemapDrago::getBias()
//

using namespace cv;

JNIEXPORT jfloat JNICALL Java_org_opencv_photo_TonemapDrago_getBias_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_photo_TonemapDrago_getBias_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "photo::getBias_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::TonemapDrago>* me = (Ptr<cv::TonemapDrago>*) self; //TODO: check for NULL
        return (*me)->getBias();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  float cv::TonemapDrago::getSaturation()
//

using namespace cv;

JNIEXPORT jfloat JNICALL Java_org_opencv_photo_TonemapDrago_getSaturation_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_photo_TonemapDrago_getSaturation_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "photo::getSaturation_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::TonemapDrago>* me = (Ptr<cv::TonemapDrago>*) self; //TODO: check for NULL
        return (*me)->getSaturation();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::TonemapDrago::setBias(float bias)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_photo_TonemapDrago_setBias_10 (JNIEnv*, jclass, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_photo_TonemapDrago_setBias_10
  (JNIEnv* env, jclass , jlong self, jfloat bias)
{
    static const char method_name[] = "photo::setBias_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::TonemapDrago>* me = (Ptr<cv::TonemapDrago>*) self; //TODO: check for NULL
        (*me)->setBias( (float)bias );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::TonemapDrago::setSaturation(float saturation)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_photo_TonemapDrago_setSaturation_10 (JNIEnv*, jclass, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_photo_TonemapDrago_setSaturation_10
  (JNIEnv* env, jclass , jlong self, jfloat saturation)
{
    static const char method_name[] = "photo::setSaturation_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::TonemapDrago>* me = (Ptr<cv::TonemapDrago>*) self; //TODO: check for NULL
        (*me)->setSaturation( (float)saturation );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void Ptr<cv::TonemapDrago>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_photo_TonemapDrago_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_photo_TonemapDrago_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::TonemapDrago>*) self;
}


//
//  Point cv::AlignMTB::calculateShift(Mat img0, Mat img1)
//

using namespace cv;

JNIEXPORT jdoubleArray JNICALL Java_org_opencv_photo_AlignMTB_calculateShift_10 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT jdoubleArray JNICALL Java_org_opencv_photo_AlignMTB_calculateShift_10
  (JNIEnv* env, jclass , jlong self, jlong img0_nativeObj, jlong img1_nativeObj)
{
    static const char method_name[] = "photo::calculateShift_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::AlignMTB>* me = (Ptr<cv::AlignMTB>*) self; //TODO: check for NULL
        Mat& img0 = *((Mat*)img0_nativeObj);
        Mat& img1 = *((Mat*)img1_nativeObj);
        Point _retval_ = (*me)->calculateShift( img0, img1 );
        jdoubleArray _da_retval_ = env->NewDoubleArray(2);  jdouble _tmp_retval_[2] = {(jdouble)_retval_.x, (jdouble)_retval_.y}; env->SetDoubleArrayRegion(_da_retval_, 0, 2, _tmp_retval_);
        return _da_retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  bool cv::AlignMTB::getCut()
//

using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_photo_AlignMTB_getCut_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_photo_AlignMTB_getCut_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "photo::getCut_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::AlignMTB>* me = (Ptr<cv::AlignMTB>*) self; //TODO: check for NULL
        return (*me)->getCut();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::AlignMTB::getExcludeRange()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_photo_AlignMTB_getExcludeRange_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_photo_AlignMTB_getExcludeRange_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "photo::getExcludeRange_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::AlignMTB>* me = (Ptr<cv::AlignMTB>*) self; //TODO: check for NULL
        return (*me)->getExcludeRange();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::AlignMTB::getMaxBits()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_photo_AlignMTB_getMaxBits_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_photo_AlignMTB_getMaxBits_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "photo::getMaxBits_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::AlignMTB>* me = (Ptr<cv::AlignMTB>*) self; //TODO: check for NULL
        return (*me)->getMaxBits();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::AlignMTB::computeBitmaps(Mat img, Mat& tb, Mat& eb)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_photo_AlignMTB_computeBitmaps_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_photo_AlignMTB_computeBitmaps_10
  (JNIEnv* env, jclass , jlong self, jlong img_nativeObj, jlong tb_nativeObj, jlong eb_nativeObj)
{
    static const char method_name[] = "photo::computeBitmaps_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::AlignMTB>* me = (Ptr<cv::AlignMTB>*) self; //TODO: check for NULL
        Mat& img = *((Mat*)img_nativeObj);
        Mat& tb = *((Mat*)tb_nativeObj);
        Mat& eb = *((Mat*)eb_nativeObj);
        (*me)->computeBitmaps( img, tb, eb );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::AlignMTB::process(vector_Mat src, vector_Mat dst, Mat times, Mat response)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_photo_AlignMTB_process_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_photo_AlignMTB_process_10
  (JNIEnv* env, jclass , jlong self, jlong src_mat_nativeObj, jlong dst_mat_nativeObj, jlong times_nativeObj, jlong response_nativeObj)
{
    static const char method_name[] = "photo::process_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> src;
        Mat& src_mat = *((Mat*)src_mat_nativeObj);
        Mat_to_vector_Mat( src_mat, src );
        std::vector<Mat> dst;
        Mat& dst_mat = *((Mat*)dst_mat_nativeObj);
        Mat_to_vector_Mat( dst_mat, dst );
        Ptr<cv::AlignMTB>* me = (Ptr<cv::AlignMTB>*) self; //TODO: check for NULL
        Mat& times = *((Mat*)times_nativeObj);
        Mat& response = *((Mat*)response_nativeObj);
        (*me)->process( src, dst, times, response );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::AlignMTB::process(vector_Mat src, vector_Mat dst)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_photo_AlignMTB_process_11 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_photo_AlignMTB_process_11
  (JNIEnv* env, jclass , jlong self, jlong src_mat_nativeObj, jlong dst_mat_nativeObj)
{
    static const char method_name[] = "photo::process_11()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> src;
        Mat& src_mat = *((Mat*)src_mat_nativeObj);
        Mat_to_vector_Mat( src_mat, src );
        std::vector<Mat> dst;
        Mat& dst_mat = *((Mat*)dst_mat_nativeObj);
        Mat_to_vector_Mat( dst_mat, dst );
        Ptr<cv::AlignMTB>* me = (Ptr<cv::AlignMTB>*) self; //TODO: check for NULL
        (*me)->process( src, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::AlignMTB::setCut(bool value)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_photo_AlignMTB_setCut_10 (JNIEnv*, jclass, jlong, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_photo_AlignMTB_setCut_10
  (JNIEnv* env, jclass , jlong self, jboolean value)
{
    static const char method_name[] = "photo::setCut_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::AlignMTB>* me = (Ptr<cv::AlignMTB>*) self; //TODO: check for NULL
        (*me)->setCut( (bool)value );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::AlignMTB::setExcludeRange(int exclude_range)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_photo_AlignMTB_setExcludeRange_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_photo_AlignMTB_setExcludeRange_10
  (JNIEnv* env, jclass , jlong self, jint exclude_range)
{
    static const char method_name[] = "photo::setExcludeRange_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::AlignMTB>* me = (Ptr<cv::AlignMTB>*) self; //TODO: check for NULL
        (*me)->setExcludeRange( (int)exclude_range );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::AlignMTB::setMaxBits(int max_bits)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_photo_AlignMTB_setMaxBits_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_photo_AlignMTB_setMaxBits_10
  (JNIEnv* env, jclass , jlong self, jint max_bits)
{
    static const char method_name[] = "photo::setMaxBits_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::AlignMTB>* me = (Ptr<cv::AlignMTB>*) self; //TODO: check for NULL
        (*me)->setMaxBits( (int)max_bits );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::AlignMTB::shiftMat(Mat src, Mat& dst, Point shift)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_photo_AlignMTB_shiftMat_10 (JNIEnv*, jclass, jlong, jlong, jlong, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_photo_AlignMTB_shiftMat_10
  (JNIEnv* env, jclass , jlong self, jlong src_nativeObj, jlong dst_nativeObj, jdouble shift_x, jdouble shift_y)
{
    static const char method_name[] = "photo::shiftMat_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::AlignMTB>* me = (Ptr<cv::AlignMTB>*) self; //TODO: check for NULL
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Point shift((int)shift_x, (int)shift_y);
        (*me)->shiftMat( src, dst, shift );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void Ptr<cv::AlignMTB>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_photo_AlignMTB_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_photo_AlignMTB_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::AlignMTB>*) self;
}


//
//  void cv::MergeDebevec::process(vector_Mat src, Mat& dst, Mat times, Mat response)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_photo_MergeDebevec_process_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_photo_MergeDebevec_process_10
  (JNIEnv* env, jclass , jlong self, jlong src_mat_nativeObj, jlong dst_nativeObj, jlong times_nativeObj, jlong response_nativeObj)
{
    static const char method_name[] = "photo::process_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> src;
        Mat& src_mat = *((Mat*)src_mat_nativeObj);
        Mat_to_vector_Mat( src_mat, src );
        Ptr<cv::MergeDebevec>* me = (Ptr<cv::MergeDebevec>*) self; //TODO: check for NULL
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& times = *((Mat*)times_nativeObj);
        Mat& response = *((Mat*)response_nativeObj);
        (*me)->process( src, dst, times, response );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::MergeDebevec::process(vector_Mat src, Mat& dst, Mat times)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_photo_MergeDebevec_process_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_photo_MergeDebevec_process_11
  (JNIEnv* env, jclass , jlong self, jlong src_mat_nativeObj, jlong dst_nativeObj, jlong times_nativeObj)
{
    static const char method_name[] = "photo::process_11()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> src;
        Mat& src_mat = *((Mat*)src_mat_nativeObj);
        Mat_to_vector_Mat( src_mat, src );
        Ptr<cv::MergeDebevec>* me = (Ptr<cv::MergeDebevec>*) self; //TODO: check for NULL
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& times = *((Mat*)times_nativeObj);
        (*me)->process( src, dst, times );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void Ptr<cv::MergeDebevec>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_photo_MergeDebevec_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_photo_MergeDebevec_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::MergeDebevec>*) self;
}


//
//  void cv::MergeExposures::process(vector_Mat src, Mat& dst, Mat times, Mat response)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_photo_MergeExposures_process_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_photo_MergeExposures_process_10
  (JNIEnv* env, jclass , jlong self, jlong src_mat_nativeObj, jlong dst_nativeObj, jlong times_nativeObj, jlong response_nativeObj)
{
    static const char method_name[] = "photo::process_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> src;
        Mat& src_mat = *((Mat*)src_mat_nativeObj);
        Mat_to_vector_Mat( src_mat, src );
        Ptr<cv::MergeExposures>* me = (Ptr<cv::MergeExposures>*) self; //TODO: check for NULL
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& times = *((Mat*)times_nativeObj);
        Mat& response = *((Mat*)response_nativeObj);
        (*me)->process( src, dst, times, response );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void Ptr<cv::MergeExposures>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_photo_MergeExposures_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_photo_MergeExposures_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::MergeExposures>*) self;
}


//
//  void cv::MergeRobertson::process(vector_Mat src, Mat& dst, Mat times, Mat response)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_photo_MergeRobertson_process_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_photo_MergeRobertson_process_10
  (JNIEnv* env, jclass , jlong self, jlong src_mat_nativeObj, jlong dst_nativeObj, jlong times_nativeObj, jlong response_nativeObj)
{
    static const char method_name[] = "photo::process_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> src;
        Mat& src_mat = *((Mat*)src_mat_nativeObj);
        Mat_to_vector_Mat( src_mat, src );
        Ptr<cv::MergeRobertson>* me = (Ptr<cv::MergeRobertson>*) self; //TODO: check for NULL
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& times = *((Mat*)times_nativeObj);
        Mat& response = *((Mat*)response_nativeObj);
        (*me)->process( src, dst, times, response );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::MergeRobertson::process(vector_Mat src, Mat& dst, Mat times)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_photo_MergeRobertson_process_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_photo_MergeRobertson_process_11
  (JNIEnv* env, jclass , jlong self, jlong src_mat_nativeObj, jlong dst_nativeObj, jlong times_nativeObj)
{
    static const char method_name[] = "photo::process_11()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> src;
        Mat& src_mat = *((Mat*)src_mat_nativeObj);
        Mat_to_vector_Mat( src_mat, src );
        Ptr<cv::MergeRobertson>* me = (Ptr<cv::MergeRobertson>*) self; //TODO: check for NULL
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& times = *((Mat*)times_nativeObj);
        (*me)->process( src, dst, times );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void Ptr<cv::MergeRobertson>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_photo_MergeRobertson_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_photo_MergeRobertson_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::MergeRobertson>*) self;
}


//
//  float cv::Tonemap::getGamma()
//

using namespace cv;

JNIEXPORT jfloat JNICALL Java_org_opencv_photo_Tonemap_getGamma_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_photo_Tonemap_getGamma_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "photo::getGamma_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::Tonemap>* me = (Ptr<cv::Tonemap>*) self; //TODO: check for NULL
        return (*me)->getGamma();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::Tonemap::process(Mat src, Mat& dst)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_photo_Tonemap_process_10 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_photo_Tonemap_process_10
  (JNIEnv* env, jclass , jlong self, jlong src_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "photo::process_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::Tonemap>* me = (Ptr<cv::Tonemap>*) self; //TODO: check for NULL
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        (*me)->process( src, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::Tonemap::setGamma(float gamma)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_photo_Tonemap_setGamma_10 (JNIEnv*, jclass, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_photo_Tonemap_setGamma_10
  (JNIEnv* env, jclass , jlong self, jfloat gamma)
{
    static const char method_name[] = "photo::setGamma_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::Tonemap>* me = (Ptr<cv::Tonemap>*) self; //TODO: check for NULL
        (*me)->setGamma( (float)gamma );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void Ptr<cv::Tonemap>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_photo_Tonemap_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_photo_Tonemap_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::Tonemap>*) self;
}



} // extern "C"

#endif // HAVE_OPENCV_PHOTO
