//
// This file is auto-generated. Please don't modify it!
//

#undef LOG_TAG

#include "opencv2/opencv_modules.hpp"
#ifdef HAVE_OPENCV_FEATURES2D

#include <string>

#include "opencv2/features2d.hpp"

#include "/Users/virtualman/Downloads/MySource/opencv-4.3.0/modules/features2d/misc/java/src/cpp/features2d_converters.hpp"
#include "/Users/virtualman/Downloads/MySource/opencv-4.3.0/modules/features2d/include/opencv2/features2d.hpp"

#define LOG_TAG "org.opencv.features2d"
#include "common.h"

using namespace cv;

/// throw java exception
#undef throwJavaException
#define throwJavaException throwJavaException_features2d
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
//  Mat cv::BOWImgDescriptorExtractor::getVocabulary()
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BOWImgDescriptorExtractor_getVocabulary_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BOWImgDescriptorExtractor_getVocabulary_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getVocabulary_10()";
    try {
        LOGD("%s", method_name);
        cv::BOWImgDescriptorExtractor* me = (cv::BOWImgDescriptorExtractor*) self; //TODO: check for NULL
        ::Mat _retval_ = me->getVocabulary();
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::BOWImgDescriptorExtractor::descriptorSize()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_features2d_BOWImgDescriptorExtractor_descriptorSize_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_features2d_BOWImgDescriptorExtractor_descriptorSize_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::descriptorSize_10()";
    try {
        LOGD("%s", method_name);
        cv::BOWImgDescriptorExtractor* me = (cv::BOWImgDescriptorExtractor*) self; //TODO: check for NULL
        return me->descriptorSize();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::BOWImgDescriptorExtractor::descriptorType()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_features2d_BOWImgDescriptorExtractor_descriptorType_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_features2d_BOWImgDescriptorExtractor_descriptorType_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::descriptorType_10()";
    try {
        LOGD("%s", method_name);
        cv::BOWImgDescriptorExtractor* me = (cv::BOWImgDescriptorExtractor*) self; //TODO: check for NULL
        return me->descriptorType();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::BOWImgDescriptorExtractor::compute2(Mat image, vector_KeyPoint keypoints, Mat& imgDescriptor)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_BOWImgDescriptorExtractor_compute_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_features2d_BOWImgDescriptorExtractor_compute_10
  (JNIEnv* env, jclass , jlong self, jlong image_nativeObj, jlong keypoints_mat_nativeObj, jlong imgDescriptor_nativeObj)
{
    static const char method_name[] = "features2d::compute_10()";
    try {
        LOGD("%s", method_name);
        std::vector<KeyPoint> keypoints;
        Mat& keypoints_mat = *((Mat*)keypoints_mat_nativeObj);
        Mat_to_vector_KeyPoint( keypoints_mat, keypoints );
        cv::BOWImgDescriptorExtractor* me = (cv::BOWImgDescriptorExtractor*) self; //TODO: check for NULL
        Mat& image = *((Mat*)image_nativeObj);
        Mat& imgDescriptor = *((Mat*)imgDescriptor_nativeObj);
        me->compute2( image, keypoints, imgDescriptor );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::BOWImgDescriptorExtractor::setVocabulary(Mat vocabulary)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_BOWImgDescriptorExtractor_setVocabulary_10 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_features2d_BOWImgDescriptorExtractor_setVocabulary_10
  (JNIEnv* env, jclass , jlong self, jlong vocabulary_nativeObj)
{
    static const char method_name[] = "features2d::setVocabulary_10()";
    try {
        LOGD("%s", method_name);
        cv::BOWImgDescriptorExtractor* me = (cv::BOWImgDescriptorExtractor*) self; //TODO: check for NULL
        Mat& vocabulary = *((Mat*)vocabulary_nativeObj);
        me->setVocabulary( vocabulary );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void cv::BOWImgDescriptorExtractor::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_features2d_BOWImgDescriptorExtractor_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_features2d_BOWImgDescriptorExtractor_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (cv::BOWImgDescriptorExtractor*) self;
}


//
//  FastFeatureDetector_DetectorType cv::FastFeatureDetector::getType()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_features2d_FastFeatureDetector_getType_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_features2d_FastFeatureDetector_getType_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getType_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::FastFeatureDetector>* me = (Ptr<cv::FastFeatureDetector>*) self; //TODO: check for NULL
        return (*me)->getType();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// static Ptr_FastFeatureDetector cv::FastFeatureDetector::create(int threshold = 10, bool nonmaxSuppression = true, FastFeatureDetector_DetectorType type = FastFeatureDetector::TYPE_9_16)
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_FastFeatureDetector_create_10 (JNIEnv*, jclass, jint, jboolean, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_FastFeatureDetector_create_10
  (JNIEnv* env, jclass , jint threshold, jboolean nonmaxSuppression, jint type)
{
    static const char method_name[] = "features2d::create_10()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::FastFeatureDetector> Ptr_FastFeatureDetector;
        Ptr_FastFeatureDetector _retval_ = cv::FastFeatureDetector::create( (int)threshold, (bool)nonmaxSuppression, (cv::FastFeatureDetector::DetectorType)type );
        return (jlong)(new Ptr_FastFeatureDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_FastFeatureDetector_create_11 (JNIEnv*, jclass, jint, jboolean);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_FastFeatureDetector_create_11
  (JNIEnv* env, jclass , jint threshold, jboolean nonmaxSuppression)
{
    static const char method_name[] = "features2d::create_11()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::FastFeatureDetector> Ptr_FastFeatureDetector;
        Ptr_FastFeatureDetector _retval_ = cv::FastFeatureDetector::create( (int)threshold, (bool)nonmaxSuppression );
        return (jlong)(new Ptr_FastFeatureDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_FastFeatureDetector_create_12 (JNIEnv*, jclass, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_FastFeatureDetector_create_12
  (JNIEnv* env, jclass , jint threshold)
{
    static const char method_name[] = "features2d::create_12()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::FastFeatureDetector> Ptr_FastFeatureDetector;
        Ptr_FastFeatureDetector _retval_ = cv::FastFeatureDetector::create( (int)threshold );
        return (jlong)(new Ptr_FastFeatureDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_FastFeatureDetector_create_13 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_FastFeatureDetector_create_13
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "features2d::create_13()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::FastFeatureDetector> Ptr_FastFeatureDetector;
        Ptr_FastFeatureDetector _retval_ = cv::FastFeatureDetector::create();
        return (jlong)(new Ptr_FastFeatureDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  String cv::FastFeatureDetector::getDefaultName()
//

using namespace cv;

JNIEXPORT jstring JNICALL Java_org_opencv_features2d_FastFeatureDetector_getDefaultName_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jstring JNICALL Java_org_opencv_features2d_FastFeatureDetector_getDefaultName_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getDefaultName_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::FastFeatureDetector>* me = (Ptr<cv::FastFeatureDetector>*) self; //TODO: check for NULL
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
//  bool cv::FastFeatureDetector::getNonmaxSuppression()
//

using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_features2d_FastFeatureDetector_getNonmaxSuppression_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_features2d_FastFeatureDetector_getNonmaxSuppression_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getNonmaxSuppression_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::FastFeatureDetector>* me = (Ptr<cv::FastFeatureDetector>*) self; //TODO: check for NULL
        return (*me)->getNonmaxSuppression();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::FastFeatureDetector::getThreshold()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_features2d_FastFeatureDetector_getThreshold_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_features2d_FastFeatureDetector_getThreshold_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getThreshold_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::FastFeatureDetector>* me = (Ptr<cv::FastFeatureDetector>*) self; //TODO: check for NULL
        return (*me)->getThreshold();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::FastFeatureDetector::setNonmaxSuppression(bool f)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_FastFeatureDetector_setNonmaxSuppression_10 (JNIEnv*, jclass, jlong, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_features2d_FastFeatureDetector_setNonmaxSuppression_10
  (JNIEnv* env, jclass , jlong self, jboolean f)
{
    static const char method_name[] = "features2d::setNonmaxSuppression_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::FastFeatureDetector>* me = (Ptr<cv::FastFeatureDetector>*) self; //TODO: check for NULL
        (*me)->setNonmaxSuppression( (bool)f );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::FastFeatureDetector::setThreshold(int threshold)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_FastFeatureDetector_setThreshold_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_features2d_FastFeatureDetector_setThreshold_10
  (JNIEnv* env, jclass , jlong self, jint threshold)
{
    static const char method_name[] = "features2d::setThreshold_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::FastFeatureDetector>* me = (Ptr<cv::FastFeatureDetector>*) self; //TODO: check for NULL
        (*me)->setThreshold( (int)threshold );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::FastFeatureDetector::setType(FastFeatureDetector_DetectorType type)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_FastFeatureDetector_setType_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_features2d_FastFeatureDetector_setType_10
  (JNIEnv* env, jclass , jlong self, jint type)
{
    static const char method_name[] = "features2d::setType_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::FastFeatureDetector>* me = (Ptr<cv::FastFeatureDetector>*) self; //TODO: check for NULL
        (*me)->setType( (cv::FastFeatureDetector::DetectorType)type );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void Ptr<cv::FastFeatureDetector>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_features2d_FastFeatureDetector_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_features2d_FastFeatureDetector_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::FastFeatureDetector>*) self;
}


//
//  String cv::Feature2D::getDefaultName()
//

using namespace cv;

JNIEXPORT jstring JNICALL Java_org_opencv_features2d_Feature2D_getDefaultName_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jstring JNICALL Java_org_opencv_features2d_Feature2D_getDefaultName_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getDefaultName_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::Feature2D>* me = (Ptr<cv::Feature2D>*) self; //TODO: check for NULL
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
//  bool cv::Feature2D::empty()
//

using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_features2d_Feature2D_empty_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_features2d_Feature2D_empty_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::empty_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::Feature2D>* me = (Ptr<cv::Feature2D>*) self; //TODO: check for NULL
        return (*me)->empty();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::Feature2D::defaultNorm()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_features2d_Feature2D_defaultNorm_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_features2d_Feature2D_defaultNorm_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::defaultNorm_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::Feature2D>* me = (Ptr<cv::Feature2D>*) self; //TODO: check for NULL
        return (*me)->defaultNorm();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::Feature2D::descriptorSize()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_features2d_Feature2D_descriptorSize_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_features2d_Feature2D_descriptorSize_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::descriptorSize_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::Feature2D>* me = (Ptr<cv::Feature2D>*) self; //TODO: check for NULL
        return (*me)->descriptorSize();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::Feature2D::descriptorType()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_features2d_Feature2D_descriptorType_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_features2d_Feature2D_descriptorType_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::descriptorType_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::Feature2D>* me = (Ptr<cv::Feature2D>*) self; //TODO: check for NULL
        return (*me)->descriptorType();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::Feature2D::compute(Mat image, vector_KeyPoint& keypoints, Mat& descriptors)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_Feature2D_compute_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_features2d_Feature2D_compute_10
  (JNIEnv* env, jclass , jlong self, jlong image_nativeObj, jlong keypoints_mat_nativeObj, jlong descriptors_nativeObj)
{
    static const char method_name[] = "features2d::compute_10()";
    try {
        LOGD("%s", method_name);
        std::vector<KeyPoint> keypoints;
        Mat& keypoints_mat = *((Mat*)keypoints_mat_nativeObj);
        Mat_to_vector_KeyPoint( keypoints_mat, keypoints );
        Ptr<cv::Feature2D>* me = (Ptr<cv::Feature2D>*) self; //TODO: check for NULL
        Mat& image = *((Mat*)image_nativeObj);
        Mat& descriptors = *((Mat*)descriptors_nativeObj);
        (*me)->compute( image, keypoints, descriptors );
        vector_KeyPoint_to_Mat( keypoints, keypoints_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::Feature2D::compute(vector_Mat images, vector_vector_KeyPoint& keypoints, vector_Mat& descriptors)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_Feature2D_compute_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_features2d_Feature2D_compute_11
  (JNIEnv* env, jclass , jlong self, jlong images_mat_nativeObj, jlong keypoints_mat_nativeObj, jlong descriptors_mat_nativeObj)
{
    static const char method_name[] = "features2d::compute_11()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> images;
        Mat& images_mat = *((Mat*)images_mat_nativeObj);
        Mat_to_vector_Mat( images_mat, images );
        std::vector< std::vector<KeyPoint> > keypoints;
        Mat& keypoints_mat = *((Mat*)keypoints_mat_nativeObj);
        Mat_to_vector_vector_KeyPoint( keypoints_mat, keypoints );
        std::vector<Mat> descriptors;
        Mat& descriptors_mat = *((Mat*)descriptors_mat_nativeObj);
        Ptr<cv::Feature2D>* me = (Ptr<cv::Feature2D>*) self; //TODO: check for NULL
        (*me)->compute( images, keypoints, descriptors );
        vector_vector_KeyPoint_to_Mat( keypoints, keypoints_mat );
        vector_Mat_to_Mat( descriptors, descriptors_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::Feature2D::detect(Mat image, vector_KeyPoint& keypoints, Mat mask = Mat())
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_Feature2D_detect_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_features2d_Feature2D_detect_10
  (JNIEnv* env, jclass , jlong self, jlong image_nativeObj, jlong keypoints_mat_nativeObj, jlong mask_nativeObj)
{
    static const char method_name[] = "features2d::detect_10()";
    try {
        LOGD("%s", method_name);
        std::vector<KeyPoint> keypoints;
        Mat& keypoints_mat = *((Mat*)keypoints_mat_nativeObj);
        Ptr<cv::Feature2D>* me = (Ptr<cv::Feature2D>*) self; //TODO: check for NULL
        Mat& image = *((Mat*)image_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        (*me)->detect( image, keypoints, mask );
        vector_KeyPoint_to_Mat( keypoints, keypoints_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_Feature2D_detect_11 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_features2d_Feature2D_detect_11
  (JNIEnv* env, jclass , jlong self, jlong image_nativeObj, jlong keypoints_mat_nativeObj)
{
    static const char method_name[] = "features2d::detect_11()";
    try {
        LOGD("%s", method_name);
        std::vector<KeyPoint> keypoints;
        Mat& keypoints_mat = *((Mat*)keypoints_mat_nativeObj);
        Ptr<cv::Feature2D>* me = (Ptr<cv::Feature2D>*) self; //TODO: check for NULL
        Mat& image = *((Mat*)image_nativeObj);
        (*me)->detect( image, keypoints );
        vector_KeyPoint_to_Mat( keypoints, keypoints_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::Feature2D::detect(vector_Mat images, vector_vector_KeyPoint& keypoints, vector_Mat masks = vector_Mat())
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_Feature2D_detect_12 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_features2d_Feature2D_detect_12
  (JNIEnv* env, jclass , jlong self, jlong images_mat_nativeObj, jlong keypoints_mat_nativeObj, jlong masks_mat_nativeObj)
{
    static const char method_name[] = "features2d::detect_12()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> images;
        Mat& images_mat = *((Mat*)images_mat_nativeObj);
        Mat_to_vector_Mat( images_mat, images );
        std::vector< std::vector<KeyPoint> > keypoints;
        Mat& keypoints_mat = *((Mat*)keypoints_mat_nativeObj);
        std::vector<Mat> masks;
        Mat& masks_mat = *((Mat*)masks_mat_nativeObj);
        Mat_to_vector_Mat( masks_mat, masks );
        Ptr<cv::Feature2D>* me = (Ptr<cv::Feature2D>*) self; //TODO: check for NULL
        (*me)->detect( images, keypoints, masks );
        vector_vector_KeyPoint_to_Mat( keypoints, keypoints_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_Feature2D_detect_13 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_features2d_Feature2D_detect_13
  (JNIEnv* env, jclass , jlong self, jlong images_mat_nativeObj, jlong keypoints_mat_nativeObj)
{
    static const char method_name[] = "features2d::detect_13()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> images;
        Mat& images_mat = *((Mat*)images_mat_nativeObj);
        Mat_to_vector_Mat( images_mat, images );
        std::vector< std::vector<KeyPoint> > keypoints;
        Mat& keypoints_mat = *((Mat*)keypoints_mat_nativeObj);
        Ptr<cv::Feature2D>* me = (Ptr<cv::Feature2D>*) self; //TODO: check for NULL
        (*me)->detect( images, keypoints );
        vector_vector_KeyPoint_to_Mat( keypoints, keypoints_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::Feature2D::detectAndCompute(Mat image, Mat mask, vector_KeyPoint& keypoints, Mat& descriptors, bool useProvidedKeypoints = false)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_Feature2D_detectAndCompute_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_features2d_Feature2D_detectAndCompute_10
  (JNIEnv* env, jclass , jlong self, jlong image_nativeObj, jlong mask_nativeObj, jlong keypoints_mat_nativeObj, jlong descriptors_nativeObj, jboolean useProvidedKeypoints)
{
    static const char method_name[] = "features2d::detectAndCompute_10()";
    try {
        LOGD("%s", method_name);
        std::vector<KeyPoint> keypoints;
        Mat& keypoints_mat = *((Mat*)keypoints_mat_nativeObj);
        Ptr<cv::Feature2D>* me = (Ptr<cv::Feature2D>*) self; //TODO: check for NULL
        Mat& image = *((Mat*)image_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        Mat& descriptors = *((Mat*)descriptors_nativeObj);
        (*me)->detectAndCompute( image, mask, keypoints, descriptors, (bool)useProvidedKeypoints );
        vector_KeyPoint_to_Mat( keypoints, keypoints_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_Feature2D_detectAndCompute_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_features2d_Feature2D_detectAndCompute_11
  (JNIEnv* env, jclass , jlong self, jlong image_nativeObj, jlong mask_nativeObj, jlong keypoints_mat_nativeObj, jlong descriptors_nativeObj)
{
    static const char method_name[] = "features2d::detectAndCompute_11()";
    try {
        LOGD("%s", method_name);
        std::vector<KeyPoint> keypoints;
        Mat& keypoints_mat = *((Mat*)keypoints_mat_nativeObj);
        Ptr<cv::Feature2D>* me = (Ptr<cv::Feature2D>*) self; //TODO: check for NULL
        Mat& image = *((Mat*)image_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        Mat& descriptors = *((Mat*)descriptors_nativeObj);
        (*me)->detectAndCompute( image, mask, keypoints, descriptors );
        vector_KeyPoint_to_Mat( keypoints, keypoints_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::Feature2D::read(String fileName)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_Feature2D_read_10 (JNIEnv*, jclass, jlong, jstring);

JNIEXPORT void JNICALL Java_org_opencv_features2d_Feature2D_read_10
  (JNIEnv* env, jclass , jlong self, jstring fileName)
{
    static const char method_name[] = "features2d::read_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::Feature2D>* me = (Ptr<cv::Feature2D>*) self; //TODO: check for NULL
        const char* utf_fileName = env->GetStringUTFChars(fileName, 0); String n_fileName( utf_fileName ? utf_fileName : "" ); env->ReleaseStringUTFChars(fileName, utf_fileName);
        (*me)->read( n_fileName );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::Feature2D::write(String fileName)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_Feature2D_write_10 (JNIEnv*, jclass, jlong, jstring);

JNIEXPORT void JNICALL Java_org_opencv_features2d_Feature2D_write_10
  (JNIEnv* env, jclass , jlong self, jstring fileName)
{
    static const char method_name[] = "features2d::write_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::Feature2D>* me = (Ptr<cv::Feature2D>*) self; //TODO: check for NULL
        const char* utf_fileName = env->GetStringUTFChars(fileName, 0); String n_fileName( utf_fileName ? utf_fileName : "" ); env->ReleaseStringUTFChars(fileName, utf_fileName);
        (*me)->write( n_fileName );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void Ptr<cv::Feature2D>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_features2d_Feature2D_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_features2d_Feature2D_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::Feature2D>*) self;
}


//
// static Ptr_BRISK cv::BRISK::create(int thresh, int octaves, vector_float radiusList, vector_int numberList, float dMax = 5.85f, float dMin = 8.2f, vector_int indexChange = std::vector<int>())
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BRISK_create_10 (JNIEnv*, jclass, jint, jint, jlong, jlong, jfloat, jfloat, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BRISK_create_10
  (JNIEnv* env, jclass , jint thresh, jint octaves, jlong radiusList_mat_nativeObj, jlong numberList_mat_nativeObj, jfloat dMax, jfloat dMin, jlong indexChange_mat_nativeObj)
{
    static const char method_name[] = "features2d::create_10()";
    try {
        LOGD("%s", method_name);
        std::vector<float> radiusList;
        Mat& radiusList_mat = *((Mat*)radiusList_mat_nativeObj);
        Mat_to_vector_float( radiusList_mat, radiusList );
        std::vector<int> numberList;
        Mat& numberList_mat = *((Mat*)numberList_mat_nativeObj);
        Mat_to_vector_int( numberList_mat, numberList );
        std::vector<int> indexChange;
        Mat& indexChange_mat = *((Mat*)indexChange_mat_nativeObj);
        Mat_to_vector_int( indexChange_mat, indexChange );
        typedef Ptr<cv::BRISK> Ptr_BRISK;
        Ptr_BRISK _retval_ = cv::BRISK::create( (int)thresh, (int)octaves, radiusList, numberList, (float)dMax, (float)dMin, indexChange );
        return (jlong)(new Ptr_BRISK(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BRISK_create_11 (JNIEnv*, jclass, jint, jint, jlong, jlong, jfloat, jfloat);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BRISK_create_11
  (JNIEnv* env, jclass , jint thresh, jint octaves, jlong radiusList_mat_nativeObj, jlong numberList_mat_nativeObj, jfloat dMax, jfloat dMin)
{
    static const char method_name[] = "features2d::create_11()";
    try {
        LOGD("%s", method_name);
        std::vector<float> radiusList;
        Mat& radiusList_mat = *((Mat*)radiusList_mat_nativeObj);
        Mat_to_vector_float( radiusList_mat, radiusList );
        std::vector<int> numberList;
        Mat& numberList_mat = *((Mat*)numberList_mat_nativeObj);
        Mat_to_vector_int( numberList_mat, numberList );
        typedef Ptr<cv::BRISK> Ptr_BRISK;
        Ptr_BRISK _retval_ = cv::BRISK::create( (int)thresh, (int)octaves, radiusList, numberList, (float)dMax, (float)dMin );
        return (jlong)(new Ptr_BRISK(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BRISK_create_12 (JNIEnv*, jclass, jint, jint, jlong, jlong, jfloat);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BRISK_create_12
  (JNIEnv* env, jclass , jint thresh, jint octaves, jlong radiusList_mat_nativeObj, jlong numberList_mat_nativeObj, jfloat dMax)
{
    static const char method_name[] = "features2d::create_12()";
    try {
        LOGD("%s", method_name);
        std::vector<float> radiusList;
        Mat& radiusList_mat = *((Mat*)radiusList_mat_nativeObj);
        Mat_to_vector_float( radiusList_mat, radiusList );
        std::vector<int> numberList;
        Mat& numberList_mat = *((Mat*)numberList_mat_nativeObj);
        Mat_to_vector_int( numberList_mat, numberList );
        typedef Ptr<cv::BRISK> Ptr_BRISK;
        Ptr_BRISK _retval_ = cv::BRISK::create( (int)thresh, (int)octaves, radiusList, numberList, (float)dMax );
        return (jlong)(new Ptr_BRISK(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BRISK_create_13 (JNIEnv*, jclass, jint, jint, jlong, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BRISK_create_13
  (JNIEnv* env, jclass , jint thresh, jint octaves, jlong radiusList_mat_nativeObj, jlong numberList_mat_nativeObj)
{
    static const char method_name[] = "features2d::create_13()";
    try {
        LOGD("%s", method_name);
        std::vector<float> radiusList;
        Mat& radiusList_mat = *((Mat*)radiusList_mat_nativeObj);
        Mat_to_vector_float( radiusList_mat, radiusList );
        std::vector<int> numberList;
        Mat& numberList_mat = *((Mat*)numberList_mat_nativeObj);
        Mat_to_vector_int( numberList_mat, numberList );
        typedef Ptr<cv::BRISK> Ptr_BRISK;
        Ptr_BRISK _retval_ = cv::BRISK::create( (int)thresh, (int)octaves, radiusList, numberList );
        return (jlong)(new Ptr_BRISK(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// static Ptr_BRISK cv::BRISK::create(int thresh = 30, int octaves = 3, float patternScale = 1.0f)
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BRISK_create_14 (JNIEnv*, jclass, jint, jint, jfloat);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BRISK_create_14
  (JNIEnv* env, jclass , jint thresh, jint octaves, jfloat patternScale)
{
    static const char method_name[] = "features2d::create_14()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::BRISK> Ptr_BRISK;
        Ptr_BRISK _retval_ = cv::BRISK::create( (int)thresh, (int)octaves, (float)patternScale );
        return (jlong)(new Ptr_BRISK(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BRISK_create_15 (JNIEnv*, jclass, jint, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BRISK_create_15
  (JNIEnv* env, jclass , jint thresh, jint octaves)
{
    static const char method_name[] = "features2d::create_15()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::BRISK> Ptr_BRISK;
        Ptr_BRISK _retval_ = cv::BRISK::create( (int)thresh, (int)octaves );
        return (jlong)(new Ptr_BRISK(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BRISK_create_16 (JNIEnv*, jclass, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BRISK_create_16
  (JNIEnv* env, jclass , jint thresh)
{
    static const char method_name[] = "features2d::create_16()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::BRISK> Ptr_BRISK;
        Ptr_BRISK _retval_ = cv::BRISK::create( (int)thresh );
        return (jlong)(new Ptr_BRISK(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BRISK_create_17 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BRISK_create_17
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "features2d::create_17()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::BRISK> Ptr_BRISK;
        Ptr_BRISK _retval_ = cv::BRISK::create();
        return (jlong)(new Ptr_BRISK(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// static Ptr_BRISK cv::BRISK::create(vector_float radiusList, vector_int numberList, float dMax = 5.85f, float dMin = 8.2f, vector_int indexChange = std::vector<int>())
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BRISK_create_18 (JNIEnv*, jclass, jlong, jlong, jfloat, jfloat, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BRISK_create_18
  (JNIEnv* env, jclass , jlong radiusList_mat_nativeObj, jlong numberList_mat_nativeObj, jfloat dMax, jfloat dMin, jlong indexChange_mat_nativeObj)
{
    static const char method_name[] = "features2d::create_18()";
    try {
        LOGD("%s", method_name);
        std::vector<float> radiusList;
        Mat& radiusList_mat = *((Mat*)radiusList_mat_nativeObj);
        Mat_to_vector_float( radiusList_mat, radiusList );
        std::vector<int> numberList;
        Mat& numberList_mat = *((Mat*)numberList_mat_nativeObj);
        Mat_to_vector_int( numberList_mat, numberList );
        std::vector<int> indexChange;
        Mat& indexChange_mat = *((Mat*)indexChange_mat_nativeObj);
        Mat_to_vector_int( indexChange_mat, indexChange );
        typedef Ptr<cv::BRISK> Ptr_BRISK;
        Ptr_BRISK _retval_ = cv::BRISK::create( radiusList, numberList, (float)dMax, (float)dMin, indexChange );
        return (jlong)(new Ptr_BRISK(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BRISK_create_19 (JNIEnv*, jclass, jlong, jlong, jfloat, jfloat);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BRISK_create_19
  (JNIEnv* env, jclass , jlong radiusList_mat_nativeObj, jlong numberList_mat_nativeObj, jfloat dMax, jfloat dMin)
{
    static const char method_name[] = "features2d::create_19()";
    try {
        LOGD("%s", method_name);
        std::vector<float> radiusList;
        Mat& radiusList_mat = *((Mat*)radiusList_mat_nativeObj);
        Mat_to_vector_float( radiusList_mat, radiusList );
        std::vector<int> numberList;
        Mat& numberList_mat = *((Mat*)numberList_mat_nativeObj);
        Mat_to_vector_int( numberList_mat, numberList );
        typedef Ptr<cv::BRISK> Ptr_BRISK;
        Ptr_BRISK _retval_ = cv::BRISK::create( radiusList, numberList, (float)dMax, (float)dMin );
        return (jlong)(new Ptr_BRISK(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BRISK_create_110 (JNIEnv*, jclass, jlong, jlong, jfloat);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BRISK_create_110
  (JNIEnv* env, jclass , jlong radiusList_mat_nativeObj, jlong numberList_mat_nativeObj, jfloat dMax)
{
    static const char method_name[] = "features2d::create_110()";
    try {
        LOGD("%s", method_name);
        std::vector<float> radiusList;
        Mat& radiusList_mat = *((Mat*)radiusList_mat_nativeObj);
        Mat_to_vector_float( radiusList_mat, radiusList );
        std::vector<int> numberList;
        Mat& numberList_mat = *((Mat*)numberList_mat_nativeObj);
        Mat_to_vector_int( numberList_mat, numberList );
        typedef Ptr<cv::BRISK> Ptr_BRISK;
        Ptr_BRISK _retval_ = cv::BRISK::create( radiusList, numberList, (float)dMax );
        return (jlong)(new Ptr_BRISK(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BRISK_create_111 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BRISK_create_111
  (JNIEnv* env, jclass , jlong radiusList_mat_nativeObj, jlong numberList_mat_nativeObj)
{
    static const char method_name[] = "features2d::create_111()";
    try {
        LOGD("%s", method_name);
        std::vector<float> radiusList;
        Mat& radiusList_mat = *((Mat*)radiusList_mat_nativeObj);
        Mat_to_vector_float( radiusList_mat, radiusList );
        std::vector<int> numberList;
        Mat& numberList_mat = *((Mat*)numberList_mat_nativeObj);
        Mat_to_vector_int( numberList_mat, numberList );
        typedef Ptr<cv::BRISK> Ptr_BRISK;
        Ptr_BRISK _retval_ = cv::BRISK::create( radiusList, numberList );
        return (jlong)(new Ptr_BRISK(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  String cv::BRISK::getDefaultName()
//

using namespace cv;

JNIEXPORT jstring JNICALL Java_org_opencv_features2d_BRISK_getDefaultName_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jstring JNICALL Java_org_opencv_features2d_BRISK_getDefaultName_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getDefaultName_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::BRISK>* me = (Ptr<cv::BRISK>*) self; //TODO: check for NULL
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
//  int cv::BRISK::getOctaves()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_features2d_BRISK_getOctaves_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_features2d_BRISK_getOctaves_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getOctaves_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::BRISK>* me = (Ptr<cv::BRISK>*) self; //TODO: check for NULL
        return (*me)->getOctaves();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::BRISK::getThreshold()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_features2d_BRISK_getThreshold_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_features2d_BRISK_getThreshold_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getThreshold_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::BRISK>* me = (Ptr<cv::BRISK>*) self; //TODO: check for NULL
        return (*me)->getThreshold();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::BRISK::setOctaves(int octaves)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_BRISK_setOctaves_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_features2d_BRISK_setOctaves_10
  (JNIEnv* env, jclass , jlong self, jint octaves)
{
    static const char method_name[] = "features2d::setOctaves_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::BRISK>* me = (Ptr<cv::BRISK>*) self; //TODO: check for NULL
        (*me)->setOctaves( (int)octaves );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::BRISK::setThreshold(int threshold)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_BRISK_setThreshold_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_features2d_BRISK_setThreshold_10
  (JNIEnv* env, jclass , jlong self, jint threshold)
{
    static const char method_name[] = "features2d::setThreshold_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::BRISK>* me = (Ptr<cv::BRISK>*) self; //TODO: check for NULL
        (*me)->setThreshold( (int)threshold );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void Ptr<cv::BRISK>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_features2d_BRISK_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_features2d_BRISK_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::BRISK>*) self;
}


//
// static Ptr_SimpleBlobDetector cv::SimpleBlobDetector::create(SimpleBlobDetector_Params parameters = SimpleBlobDetector::Params())
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_SimpleBlobDetector_create_10 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_SimpleBlobDetector_create_10
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "features2d::create_10()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::SimpleBlobDetector> Ptr_SimpleBlobDetector;
        Ptr_SimpleBlobDetector _retval_ = cv::SimpleBlobDetector::create( SimpleBlobDetector::Params() );
        return (jlong)(new Ptr_SimpleBlobDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  String cv::SimpleBlobDetector::getDefaultName()
//

using namespace cv;

JNIEXPORT jstring JNICALL Java_org_opencv_features2d_SimpleBlobDetector_getDefaultName_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jstring JNICALL Java_org_opencv_features2d_SimpleBlobDetector_getDefaultName_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getDefaultName_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::SimpleBlobDetector>* me = (Ptr<cv::SimpleBlobDetector>*) self; //TODO: check for NULL
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
//  native support for java finalize()
//  static void Ptr<cv::SimpleBlobDetector>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_features2d_SimpleBlobDetector_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_features2d_SimpleBlobDetector_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::SimpleBlobDetector>*) self;
}


//
//  AgastFeatureDetector_DetectorType cv::AgastFeatureDetector::getType()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_features2d_AgastFeatureDetector_getType_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_features2d_AgastFeatureDetector_getType_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getType_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::AgastFeatureDetector>* me = (Ptr<cv::AgastFeatureDetector>*) self; //TODO: check for NULL
        return (*me)->getType();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// static Ptr_AgastFeatureDetector cv::AgastFeatureDetector::create(int threshold = 10, bool nonmaxSuppression = true, AgastFeatureDetector_DetectorType type = AgastFeatureDetector::OAST_9_16)
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_AgastFeatureDetector_create_10 (JNIEnv*, jclass, jint, jboolean, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_AgastFeatureDetector_create_10
  (JNIEnv* env, jclass , jint threshold, jboolean nonmaxSuppression, jint type)
{
    static const char method_name[] = "features2d::create_10()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::AgastFeatureDetector> Ptr_AgastFeatureDetector;
        Ptr_AgastFeatureDetector _retval_ = cv::AgastFeatureDetector::create( (int)threshold, (bool)nonmaxSuppression, (cv::AgastFeatureDetector::DetectorType)type );
        return (jlong)(new Ptr_AgastFeatureDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_AgastFeatureDetector_create_11 (JNIEnv*, jclass, jint, jboolean);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_AgastFeatureDetector_create_11
  (JNIEnv* env, jclass , jint threshold, jboolean nonmaxSuppression)
{
    static const char method_name[] = "features2d::create_11()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::AgastFeatureDetector> Ptr_AgastFeatureDetector;
        Ptr_AgastFeatureDetector _retval_ = cv::AgastFeatureDetector::create( (int)threshold, (bool)nonmaxSuppression );
        return (jlong)(new Ptr_AgastFeatureDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_AgastFeatureDetector_create_12 (JNIEnv*, jclass, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_AgastFeatureDetector_create_12
  (JNIEnv* env, jclass , jint threshold)
{
    static const char method_name[] = "features2d::create_12()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::AgastFeatureDetector> Ptr_AgastFeatureDetector;
        Ptr_AgastFeatureDetector _retval_ = cv::AgastFeatureDetector::create( (int)threshold );
        return (jlong)(new Ptr_AgastFeatureDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_AgastFeatureDetector_create_13 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_AgastFeatureDetector_create_13
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "features2d::create_13()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::AgastFeatureDetector> Ptr_AgastFeatureDetector;
        Ptr_AgastFeatureDetector _retval_ = cv::AgastFeatureDetector::create();
        return (jlong)(new Ptr_AgastFeatureDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  String cv::AgastFeatureDetector::getDefaultName()
//

using namespace cv;

JNIEXPORT jstring JNICALL Java_org_opencv_features2d_AgastFeatureDetector_getDefaultName_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jstring JNICALL Java_org_opencv_features2d_AgastFeatureDetector_getDefaultName_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getDefaultName_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::AgastFeatureDetector>* me = (Ptr<cv::AgastFeatureDetector>*) self; //TODO: check for NULL
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
//  bool cv::AgastFeatureDetector::getNonmaxSuppression()
//

using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_features2d_AgastFeatureDetector_getNonmaxSuppression_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_features2d_AgastFeatureDetector_getNonmaxSuppression_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getNonmaxSuppression_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::AgastFeatureDetector>* me = (Ptr<cv::AgastFeatureDetector>*) self; //TODO: check for NULL
        return (*me)->getNonmaxSuppression();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::AgastFeatureDetector::getThreshold()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_features2d_AgastFeatureDetector_getThreshold_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_features2d_AgastFeatureDetector_getThreshold_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getThreshold_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::AgastFeatureDetector>* me = (Ptr<cv::AgastFeatureDetector>*) self; //TODO: check for NULL
        return (*me)->getThreshold();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::AgastFeatureDetector::setNonmaxSuppression(bool f)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_AgastFeatureDetector_setNonmaxSuppression_10 (JNIEnv*, jclass, jlong, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_features2d_AgastFeatureDetector_setNonmaxSuppression_10
  (JNIEnv* env, jclass , jlong self, jboolean f)
{
    static const char method_name[] = "features2d::setNonmaxSuppression_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::AgastFeatureDetector>* me = (Ptr<cv::AgastFeatureDetector>*) self; //TODO: check for NULL
        (*me)->setNonmaxSuppression( (bool)f );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::AgastFeatureDetector::setThreshold(int threshold)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_AgastFeatureDetector_setThreshold_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_features2d_AgastFeatureDetector_setThreshold_10
  (JNIEnv* env, jclass , jlong self, jint threshold)
{
    static const char method_name[] = "features2d::setThreshold_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::AgastFeatureDetector>* me = (Ptr<cv::AgastFeatureDetector>*) self; //TODO: check for NULL
        (*me)->setThreshold( (int)threshold );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::AgastFeatureDetector::setType(AgastFeatureDetector_DetectorType type)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_AgastFeatureDetector_setType_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_features2d_AgastFeatureDetector_setType_10
  (JNIEnv* env, jclass , jlong self, jint type)
{
    static const char method_name[] = "features2d::setType_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::AgastFeatureDetector>* me = (Ptr<cv::AgastFeatureDetector>*) self; //TODO: check for NULL
        (*me)->setType( (cv::AgastFeatureDetector::DetectorType)type );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void Ptr<cv::AgastFeatureDetector>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_features2d_AgastFeatureDetector_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_features2d_AgastFeatureDetector_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::AgastFeatureDetector>*) self;
}


//
// static Ptr_GFTTDetector cv::GFTTDetector::create(int maxCorners, double qualityLevel, double minDistance, int blockSize, int gradiantSize, bool useHarrisDetector = false, double k = 0.04)
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_GFTTDetector_create_10 (JNIEnv*, jclass, jint, jdouble, jdouble, jint, jint, jboolean, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_GFTTDetector_create_10
  (JNIEnv* env, jclass , jint maxCorners, jdouble qualityLevel, jdouble minDistance, jint blockSize, jint gradiantSize, jboolean useHarrisDetector, jdouble k)
{
    static const char method_name[] = "features2d::create_10()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::GFTTDetector> Ptr_GFTTDetector;
        Ptr_GFTTDetector _retval_ = cv::GFTTDetector::create( (int)maxCorners, (double)qualityLevel, (double)minDistance, (int)blockSize, (int)gradiantSize, (bool)useHarrisDetector, (double)k );
        return (jlong)(new Ptr_GFTTDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_GFTTDetector_create_11 (JNIEnv*, jclass, jint, jdouble, jdouble, jint, jint, jboolean);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_GFTTDetector_create_11
  (JNIEnv* env, jclass , jint maxCorners, jdouble qualityLevel, jdouble minDistance, jint blockSize, jint gradiantSize, jboolean useHarrisDetector)
{
    static const char method_name[] = "features2d::create_11()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::GFTTDetector> Ptr_GFTTDetector;
        Ptr_GFTTDetector _retval_ = cv::GFTTDetector::create( (int)maxCorners, (double)qualityLevel, (double)minDistance, (int)blockSize, (int)gradiantSize, (bool)useHarrisDetector );
        return (jlong)(new Ptr_GFTTDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_GFTTDetector_create_12 (JNIEnv*, jclass, jint, jdouble, jdouble, jint, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_GFTTDetector_create_12
  (JNIEnv* env, jclass , jint maxCorners, jdouble qualityLevel, jdouble minDistance, jint blockSize, jint gradiantSize)
{
    static const char method_name[] = "features2d::create_12()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::GFTTDetector> Ptr_GFTTDetector;
        Ptr_GFTTDetector _retval_ = cv::GFTTDetector::create( (int)maxCorners, (double)qualityLevel, (double)minDistance, (int)blockSize, (int)gradiantSize );
        return (jlong)(new Ptr_GFTTDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// static Ptr_GFTTDetector cv::GFTTDetector::create(int maxCorners = 1000, double qualityLevel = 0.01, double minDistance = 1, int blockSize = 3, bool useHarrisDetector = false, double k = 0.04)
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_GFTTDetector_create_13 (JNIEnv*, jclass, jint, jdouble, jdouble, jint, jboolean, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_GFTTDetector_create_13
  (JNIEnv* env, jclass , jint maxCorners, jdouble qualityLevel, jdouble minDistance, jint blockSize, jboolean useHarrisDetector, jdouble k)
{
    static const char method_name[] = "features2d::create_13()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::GFTTDetector> Ptr_GFTTDetector;
        Ptr_GFTTDetector _retval_ = cv::GFTTDetector::create( (int)maxCorners, (double)qualityLevel, (double)minDistance, (int)blockSize, (bool)useHarrisDetector, (double)k );
        return (jlong)(new Ptr_GFTTDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_GFTTDetector_create_14 (JNIEnv*, jclass, jint, jdouble, jdouble, jint, jboolean);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_GFTTDetector_create_14
  (JNIEnv* env, jclass , jint maxCorners, jdouble qualityLevel, jdouble minDistance, jint blockSize, jboolean useHarrisDetector)
{
    static const char method_name[] = "features2d::create_14()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::GFTTDetector> Ptr_GFTTDetector;
        Ptr_GFTTDetector _retval_ = cv::GFTTDetector::create( (int)maxCorners, (double)qualityLevel, (double)minDistance, (int)blockSize, (bool)useHarrisDetector );
        return (jlong)(new Ptr_GFTTDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_GFTTDetector_create_15 (JNIEnv*, jclass, jint, jdouble, jdouble, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_GFTTDetector_create_15
  (JNIEnv* env, jclass , jint maxCorners, jdouble qualityLevel, jdouble minDistance, jint blockSize)
{
    static const char method_name[] = "features2d::create_15()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::GFTTDetector> Ptr_GFTTDetector;
        Ptr_GFTTDetector _retval_ = cv::GFTTDetector::create( (int)maxCorners, (double)qualityLevel, (double)minDistance, (int)blockSize );
        return (jlong)(new Ptr_GFTTDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_GFTTDetector_create_16 (JNIEnv*, jclass, jint, jdouble, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_GFTTDetector_create_16
  (JNIEnv* env, jclass , jint maxCorners, jdouble qualityLevel, jdouble minDistance)
{
    static const char method_name[] = "features2d::create_16()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::GFTTDetector> Ptr_GFTTDetector;
        Ptr_GFTTDetector _retval_ = cv::GFTTDetector::create( (int)maxCorners, (double)qualityLevel, (double)minDistance );
        return (jlong)(new Ptr_GFTTDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_GFTTDetector_create_17 (JNIEnv*, jclass, jint, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_GFTTDetector_create_17
  (JNIEnv* env, jclass , jint maxCorners, jdouble qualityLevel)
{
    static const char method_name[] = "features2d::create_17()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::GFTTDetector> Ptr_GFTTDetector;
        Ptr_GFTTDetector _retval_ = cv::GFTTDetector::create( (int)maxCorners, (double)qualityLevel );
        return (jlong)(new Ptr_GFTTDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_GFTTDetector_create_18 (JNIEnv*, jclass, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_GFTTDetector_create_18
  (JNIEnv* env, jclass , jint maxCorners)
{
    static const char method_name[] = "features2d::create_18()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::GFTTDetector> Ptr_GFTTDetector;
        Ptr_GFTTDetector _retval_ = cv::GFTTDetector::create( (int)maxCorners );
        return (jlong)(new Ptr_GFTTDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_GFTTDetector_create_19 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_GFTTDetector_create_19
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "features2d::create_19()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::GFTTDetector> Ptr_GFTTDetector;
        Ptr_GFTTDetector _retval_ = cv::GFTTDetector::create();
        return (jlong)(new Ptr_GFTTDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  String cv::GFTTDetector::getDefaultName()
//

using namespace cv;

JNIEXPORT jstring JNICALL Java_org_opencv_features2d_GFTTDetector_getDefaultName_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jstring JNICALL Java_org_opencv_features2d_GFTTDetector_getDefaultName_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getDefaultName_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GFTTDetector>* me = (Ptr<cv::GFTTDetector>*) self; //TODO: check for NULL
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
//  bool cv::GFTTDetector::getHarrisDetector()
//

using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_features2d_GFTTDetector_getHarrisDetector_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_features2d_GFTTDetector_getHarrisDetector_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getHarrisDetector_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GFTTDetector>* me = (Ptr<cv::GFTTDetector>*) self; //TODO: check for NULL
        return (*me)->getHarrisDetector();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::GFTTDetector::getK()
//

using namespace cv;

JNIEXPORT jdouble JNICALL Java_org_opencv_features2d_GFTTDetector_getK_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_features2d_GFTTDetector_getK_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getK_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GFTTDetector>* me = (Ptr<cv::GFTTDetector>*) self; //TODO: check for NULL
        return (*me)->getK();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::GFTTDetector::getMinDistance()
//

using namespace cv;

JNIEXPORT jdouble JNICALL Java_org_opencv_features2d_GFTTDetector_getMinDistance_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_features2d_GFTTDetector_getMinDistance_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getMinDistance_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GFTTDetector>* me = (Ptr<cv::GFTTDetector>*) self; //TODO: check for NULL
        return (*me)->getMinDistance();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::GFTTDetector::getQualityLevel()
//

using namespace cv;

JNIEXPORT jdouble JNICALL Java_org_opencv_features2d_GFTTDetector_getQualityLevel_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_features2d_GFTTDetector_getQualityLevel_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getQualityLevel_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GFTTDetector>* me = (Ptr<cv::GFTTDetector>*) self; //TODO: check for NULL
        return (*me)->getQualityLevel();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::GFTTDetector::getBlockSize()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_features2d_GFTTDetector_getBlockSize_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_features2d_GFTTDetector_getBlockSize_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getBlockSize_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GFTTDetector>* me = (Ptr<cv::GFTTDetector>*) self; //TODO: check for NULL
        return (*me)->getBlockSize();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::GFTTDetector::getMaxFeatures()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_features2d_GFTTDetector_getMaxFeatures_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_features2d_GFTTDetector_getMaxFeatures_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getMaxFeatures_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GFTTDetector>* me = (Ptr<cv::GFTTDetector>*) self; //TODO: check for NULL
        return (*me)->getMaxFeatures();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::GFTTDetector::setBlockSize(int blockSize)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_GFTTDetector_setBlockSize_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_features2d_GFTTDetector_setBlockSize_10
  (JNIEnv* env, jclass , jlong self, jint blockSize)
{
    static const char method_name[] = "features2d::setBlockSize_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GFTTDetector>* me = (Ptr<cv::GFTTDetector>*) self; //TODO: check for NULL
        (*me)->setBlockSize( (int)blockSize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::GFTTDetector::setHarrisDetector(bool val)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_GFTTDetector_setHarrisDetector_10 (JNIEnv*, jclass, jlong, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_features2d_GFTTDetector_setHarrisDetector_10
  (JNIEnv* env, jclass , jlong self, jboolean val)
{
    static const char method_name[] = "features2d::setHarrisDetector_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GFTTDetector>* me = (Ptr<cv::GFTTDetector>*) self; //TODO: check for NULL
        (*me)->setHarrisDetector( (bool)val );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::GFTTDetector::setK(double k)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_GFTTDetector_setK_10 (JNIEnv*, jclass, jlong, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_features2d_GFTTDetector_setK_10
  (JNIEnv* env, jclass , jlong self, jdouble k)
{
    static const char method_name[] = "features2d::setK_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GFTTDetector>* me = (Ptr<cv::GFTTDetector>*) self; //TODO: check for NULL
        (*me)->setK( (double)k );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::GFTTDetector::setMaxFeatures(int maxFeatures)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_GFTTDetector_setMaxFeatures_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_features2d_GFTTDetector_setMaxFeatures_10
  (JNIEnv* env, jclass , jlong self, jint maxFeatures)
{
    static const char method_name[] = "features2d::setMaxFeatures_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GFTTDetector>* me = (Ptr<cv::GFTTDetector>*) self; //TODO: check for NULL
        (*me)->setMaxFeatures( (int)maxFeatures );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::GFTTDetector::setMinDistance(double minDistance)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_GFTTDetector_setMinDistance_10 (JNIEnv*, jclass, jlong, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_features2d_GFTTDetector_setMinDistance_10
  (JNIEnv* env, jclass , jlong self, jdouble minDistance)
{
    static const char method_name[] = "features2d::setMinDistance_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GFTTDetector>* me = (Ptr<cv::GFTTDetector>*) self; //TODO: check for NULL
        (*me)->setMinDistance( (double)minDistance );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::GFTTDetector::setQualityLevel(double qlevel)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_GFTTDetector_setQualityLevel_10 (JNIEnv*, jclass, jlong, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_features2d_GFTTDetector_setQualityLevel_10
  (JNIEnv* env, jclass , jlong self, jdouble qlevel)
{
    static const char method_name[] = "features2d::setQualityLevel_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GFTTDetector>* me = (Ptr<cv::GFTTDetector>*) self; //TODO: check for NULL
        (*me)->setQualityLevel( (double)qlevel );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void Ptr<cv::GFTTDetector>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_features2d_GFTTDetector_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_features2d_GFTTDetector_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::GFTTDetector>*) self;
}


//
//  Ptr_DescriptorMatcher cv::DescriptorMatcher::clone(bool emptyTrainData = false)
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_DescriptorMatcher_clone_10 (JNIEnv*, jclass, jlong, jboolean);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_DescriptorMatcher_clone_10
  (JNIEnv* env, jclass , jlong self, jboolean emptyTrainData)
{
    static const char method_name[] = "features2d::clone_10()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::DescriptorMatcher> Ptr_DescriptorMatcher;
        Ptr<cv::DescriptorMatcher>* me = (Ptr<cv::DescriptorMatcher>*) self; //TODO: check for NULL
        Ptr_DescriptorMatcher _retval_ = (*me)->clone( (bool)emptyTrainData );
        return (jlong)(new Ptr_DescriptorMatcher(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_DescriptorMatcher_clone_11 (JNIEnv*, jclass, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_DescriptorMatcher_clone_11
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::clone_11()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::DescriptorMatcher> Ptr_DescriptorMatcher;
        Ptr<cv::DescriptorMatcher>* me = (Ptr<cv::DescriptorMatcher>*) self; //TODO: check for NULL
        Ptr_DescriptorMatcher _retval_ = (*me)->clone();
        return (jlong)(new Ptr_DescriptorMatcher(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// static Ptr_DescriptorMatcher cv::DescriptorMatcher::create(DescriptorMatcher_MatcherType matcherType)
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_DescriptorMatcher_create_10 (JNIEnv*, jclass, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_DescriptorMatcher_create_10
  (JNIEnv* env, jclass , jint matcherType)
{
    static const char method_name[] = "features2d::create_10()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::DescriptorMatcher> Ptr_DescriptorMatcher;
        Ptr_DescriptorMatcher _retval_ = cv::DescriptorMatcher::create( (cv::DescriptorMatcher::MatcherType)matcherType );
        return (jlong)(new Ptr_DescriptorMatcher(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// static Ptr_DescriptorMatcher cv::DescriptorMatcher::create(String descriptorMatcherType)
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_DescriptorMatcher_create_11 (JNIEnv*, jclass, jstring);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_DescriptorMatcher_create_11
  (JNIEnv* env, jclass , jstring descriptorMatcherType)
{
    static const char method_name[] = "features2d::create_11()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::DescriptorMatcher> Ptr_DescriptorMatcher;
        const char* utf_descriptorMatcherType = env->GetStringUTFChars(descriptorMatcherType, 0); String n_descriptorMatcherType( utf_descriptorMatcherType ? utf_descriptorMatcherType : "" ); env->ReleaseStringUTFChars(descriptorMatcherType, utf_descriptorMatcherType);
        Ptr_DescriptorMatcher _retval_ = cv::DescriptorMatcher::create( n_descriptorMatcherType );
        return (jlong)(new Ptr_DescriptorMatcher(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  bool cv::DescriptorMatcher::empty()
//

using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_features2d_DescriptorMatcher_empty_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_features2d_DescriptorMatcher_empty_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::empty_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::DescriptorMatcher>* me = (Ptr<cv::DescriptorMatcher>*) self; //TODO: check for NULL
        return (*me)->empty();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  bool cv::DescriptorMatcher::isMaskSupported()
//

using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_features2d_DescriptorMatcher_isMaskSupported_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_features2d_DescriptorMatcher_isMaskSupported_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::isMaskSupported_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::DescriptorMatcher>* me = (Ptr<cv::DescriptorMatcher>*) self; //TODO: check for NULL
        return (*me)->isMaskSupported();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  vector_Mat cv::DescriptorMatcher::getTrainDescriptors()
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_DescriptorMatcher_getTrainDescriptors_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_DescriptorMatcher_getTrainDescriptors_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getTrainDescriptors_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::DescriptorMatcher>* me = (Ptr<cv::DescriptorMatcher>*) self; //TODO: check for NULL
        std::vector<Mat> _ret_val_vector_ = (*me)->getTrainDescriptors();
        Mat* _retval_ = new Mat();
        vector_Mat_to_Mat(_ret_val_vector_, *_retval_);
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::DescriptorMatcher::add(vector_Mat descriptors)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_DescriptorMatcher_add_10 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_features2d_DescriptorMatcher_add_10
  (JNIEnv* env, jclass , jlong self, jlong descriptors_mat_nativeObj)
{
    static const char method_name[] = "features2d::add_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> descriptors;
        Mat& descriptors_mat = *((Mat*)descriptors_mat_nativeObj);
        Mat_to_vector_Mat( descriptors_mat, descriptors );
        Ptr<cv::DescriptorMatcher>* me = (Ptr<cv::DescriptorMatcher>*) self; //TODO: check for NULL
        (*me)->add( descriptors );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::DescriptorMatcher::clear()
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_DescriptorMatcher_clear_10 (JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_features2d_DescriptorMatcher_clear_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::clear_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::DescriptorMatcher>* me = (Ptr<cv::DescriptorMatcher>*) self; //TODO: check for NULL
        (*me)->clear();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::DescriptorMatcher::knnMatch(Mat queryDescriptors, Mat trainDescriptors, vector_vector_DMatch& matches, int k, Mat mask = Mat(), bool compactResult = false)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_DescriptorMatcher_knnMatch_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jint, jlong, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_features2d_DescriptorMatcher_knnMatch_10
  (JNIEnv* env, jclass , jlong self, jlong queryDescriptors_nativeObj, jlong trainDescriptors_nativeObj, jlong matches_mat_nativeObj, jint k, jlong mask_nativeObj, jboolean compactResult)
{
    static const char method_name[] = "features2d::knnMatch_10()";
    try {
        LOGD("%s", method_name);
        std::vector< std::vector<DMatch> > matches;
        Mat& matches_mat = *((Mat*)matches_mat_nativeObj);
        Ptr<cv::DescriptorMatcher>* me = (Ptr<cv::DescriptorMatcher>*) self; //TODO: check for NULL
        Mat& queryDescriptors = *((Mat*)queryDescriptors_nativeObj);
        Mat& trainDescriptors = *((Mat*)trainDescriptors_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        (*me)->knnMatch( queryDescriptors, trainDescriptors, matches, (int)k, mask, (bool)compactResult );
        vector_vector_DMatch_to_Mat( matches, matches_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_DescriptorMatcher_knnMatch_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jint, jlong);

JNIEXPORT void JNICALL Java_org_opencv_features2d_DescriptorMatcher_knnMatch_11
  (JNIEnv* env, jclass , jlong self, jlong queryDescriptors_nativeObj, jlong trainDescriptors_nativeObj, jlong matches_mat_nativeObj, jint k, jlong mask_nativeObj)
{
    static const char method_name[] = "features2d::knnMatch_11()";
    try {
        LOGD("%s", method_name);
        std::vector< std::vector<DMatch> > matches;
        Mat& matches_mat = *((Mat*)matches_mat_nativeObj);
        Ptr<cv::DescriptorMatcher>* me = (Ptr<cv::DescriptorMatcher>*) self; //TODO: check for NULL
        Mat& queryDescriptors = *((Mat*)queryDescriptors_nativeObj);
        Mat& trainDescriptors = *((Mat*)trainDescriptors_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        (*me)->knnMatch( queryDescriptors, trainDescriptors, matches, (int)k, mask );
        vector_vector_DMatch_to_Mat( matches, matches_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_DescriptorMatcher_knnMatch_12 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_features2d_DescriptorMatcher_knnMatch_12
  (JNIEnv* env, jclass , jlong self, jlong queryDescriptors_nativeObj, jlong trainDescriptors_nativeObj, jlong matches_mat_nativeObj, jint k)
{
    static const char method_name[] = "features2d::knnMatch_12()";
    try {
        LOGD("%s", method_name);
        std::vector< std::vector<DMatch> > matches;
        Mat& matches_mat = *((Mat*)matches_mat_nativeObj);
        Ptr<cv::DescriptorMatcher>* me = (Ptr<cv::DescriptorMatcher>*) self; //TODO: check for NULL
        Mat& queryDescriptors = *((Mat*)queryDescriptors_nativeObj);
        Mat& trainDescriptors = *((Mat*)trainDescriptors_nativeObj);
        (*me)->knnMatch( queryDescriptors, trainDescriptors, matches, (int)k );
        vector_vector_DMatch_to_Mat( matches, matches_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::DescriptorMatcher::knnMatch(Mat queryDescriptors, vector_vector_DMatch& matches, int k, vector_Mat masks = vector_Mat(), bool compactResult = false)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_DescriptorMatcher_knnMatch_13 (JNIEnv*, jclass, jlong, jlong, jlong, jint, jlong, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_features2d_DescriptorMatcher_knnMatch_13
  (JNIEnv* env, jclass , jlong self, jlong queryDescriptors_nativeObj, jlong matches_mat_nativeObj, jint k, jlong masks_mat_nativeObj, jboolean compactResult)
{
    static const char method_name[] = "features2d::knnMatch_13()";
    try {
        LOGD("%s", method_name);
        std::vector< std::vector<DMatch> > matches;
        Mat& matches_mat = *((Mat*)matches_mat_nativeObj);
        std::vector<Mat> masks;
        Mat& masks_mat = *((Mat*)masks_mat_nativeObj);
        Mat_to_vector_Mat( masks_mat, masks );
        Ptr<cv::DescriptorMatcher>* me = (Ptr<cv::DescriptorMatcher>*) self; //TODO: check for NULL
        Mat& queryDescriptors = *((Mat*)queryDescriptors_nativeObj);
        (*me)->knnMatch( queryDescriptors, matches, (int)k, masks, (bool)compactResult );
        vector_vector_DMatch_to_Mat( matches, matches_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_DescriptorMatcher_knnMatch_14 (JNIEnv*, jclass, jlong, jlong, jlong, jint, jlong);

JNIEXPORT void JNICALL Java_org_opencv_features2d_DescriptorMatcher_knnMatch_14
  (JNIEnv* env, jclass , jlong self, jlong queryDescriptors_nativeObj, jlong matches_mat_nativeObj, jint k, jlong masks_mat_nativeObj)
{
    static const char method_name[] = "features2d::knnMatch_14()";
    try {
        LOGD("%s", method_name);
        std::vector< std::vector<DMatch> > matches;
        Mat& matches_mat = *((Mat*)matches_mat_nativeObj);
        std::vector<Mat> masks;
        Mat& masks_mat = *((Mat*)masks_mat_nativeObj);
        Mat_to_vector_Mat( masks_mat, masks );
        Ptr<cv::DescriptorMatcher>* me = (Ptr<cv::DescriptorMatcher>*) self; //TODO: check for NULL
        Mat& queryDescriptors = *((Mat*)queryDescriptors_nativeObj);
        (*me)->knnMatch( queryDescriptors, matches, (int)k, masks );
        vector_vector_DMatch_to_Mat( matches, matches_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_DescriptorMatcher_knnMatch_15 (JNIEnv*, jclass, jlong, jlong, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_features2d_DescriptorMatcher_knnMatch_15
  (JNIEnv* env, jclass , jlong self, jlong queryDescriptors_nativeObj, jlong matches_mat_nativeObj, jint k)
{
    static const char method_name[] = "features2d::knnMatch_15()";
    try {
        LOGD("%s", method_name);
        std::vector< std::vector<DMatch> > matches;
        Mat& matches_mat = *((Mat*)matches_mat_nativeObj);
        Ptr<cv::DescriptorMatcher>* me = (Ptr<cv::DescriptorMatcher>*) self; //TODO: check for NULL
        Mat& queryDescriptors = *((Mat*)queryDescriptors_nativeObj);
        (*me)->knnMatch( queryDescriptors, matches, (int)k );
        vector_vector_DMatch_to_Mat( matches, matches_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::DescriptorMatcher::match(Mat queryDescriptors, Mat trainDescriptors, vector_DMatch& matches, Mat mask = Mat())
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_DescriptorMatcher_match_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_features2d_DescriptorMatcher_match_10
  (JNIEnv* env, jclass , jlong self, jlong queryDescriptors_nativeObj, jlong trainDescriptors_nativeObj, jlong matches_mat_nativeObj, jlong mask_nativeObj)
{
    static const char method_name[] = "features2d::match_10()";
    try {
        LOGD("%s", method_name);
        std::vector<DMatch> matches;
        Mat& matches_mat = *((Mat*)matches_mat_nativeObj);
        Ptr<cv::DescriptorMatcher>* me = (Ptr<cv::DescriptorMatcher>*) self; //TODO: check for NULL
        Mat& queryDescriptors = *((Mat*)queryDescriptors_nativeObj);
        Mat& trainDescriptors = *((Mat*)trainDescriptors_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        (*me)->match( queryDescriptors, trainDescriptors, matches, mask );
        vector_DMatch_to_Mat( matches, matches_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_DescriptorMatcher_match_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_features2d_DescriptorMatcher_match_11
  (JNIEnv* env, jclass , jlong self, jlong queryDescriptors_nativeObj, jlong trainDescriptors_nativeObj, jlong matches_mat_nativeObj)
{
    static const char method_name[] = "features2d::match_11()";
    try {
        LOGD("%s", method_name);
        std::vector<DMatch> matches;
        Mat& matches_mat = *((Mat*)matches_mat_nativeObj);
        Ptr<cv::DescriptorMatcher>* me = (Ptr<cv::DescriptorMatcher>*) self; //TODO: check for NULL
        Mat& queryDescriptors = *((Mat*)queryDescriptors_nativeObj);
        Mat& trainDescriptors = *((Mat*)trainDescriptors_nativeObj);
        (*me)->match( queryDescriptors, trainDescriptors, matches );
        vector_DMatch_to_Mat( matches, matches_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::DescriptorMatcher::match(Mat queryDescriptors, vector_DMatch& matches, vector_Mat masks = vector_Mat())
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_DescriptorMatcher_match_12 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_features2d_DescriptorMatcher_match_12
  (JNIEnv* env, jclass , jlong self, jlong queryDescriptors_nativeObj, jlong matches_mat_nativeObj, jlong masks_mat_nativeObj)
{
    static const char method_name[] = "features2d::match_12()";
    try {
        LOGD("%s", method_name);
        std::vector<DMatch> matches;
        Mat& matches_mat = *((Mat*)matches_mat_nativeObj);
        std::vector<Mat> masks;
        Mat& masks_mat = *((Mat*)masks_mat_nativeObj);
        Mat_to_vector_Mat( masks_mat, masks );
        Ptr<cv::DescriptorMatcher>* me = (Ptr<cv::DescriptorMatcher>*) self; //TODO: check for NULL
        Mat& queryDescriptors = *((Mat*)queryDescriptors_nativeObj);
        (*me)->match( queryDescriptors, matches, masks );
        vector_DMatch_to_Mat( matches, matches_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_DescriptorMatcher_match_13 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_features2d_DescriptorMatcher_match_13
  (JNIEnv* env, jclass , jlong self, jlong queryDescriptors_nativeObj, jlong matches_mat_nativeObj)
{
    static const char method_name[] = "features2d::match_13()";
    try {
        LOGD("%s", method_name);
        std::vector<DMatch> matches;
        Mat& matches_mat = *((Mat*)matches_mat_nativeObj);
        Ptr<cv::DescriptorMatcher>* me = (Ptr<cv::DescriptorMatcher>*) self; //TODO: check for NULL
        Mat& queryDescriptors = *((Mat*)queryDescriptors_nativeObj);
        (*me)->match( queryDescriptors, matches );
        vector_DMatch_to_Mat( matches, matches_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::DescriptorMatcher::radiusMatch(Mat queryDescriptors, Mat trainDescriptors, vector_vector_DMatch& matches, float maxDistance, Mat mask = Mat(), bool compactResult = false)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_DescriptorMatcher_radiusMatch_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jfloat, jlong, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_features2d_DescriptorMatcher_radiusMatch_10
  (JNIEnv* env, jclass , jlong self, jlong queryDescriptors_nativeObj, jlong trainDescriptors_nativeObj, jlong matches_mat_nativeObj, jfloat maxDistance, jlong mask_nativeObj, jboolean compactResult)
{
    static const char method_name[] = "features2d::radiusMatch_10()";
    try {
        LOGD("%s", method_name);
        std::vector< std::vector<DMatch> > matches;
        Mat& matches_mat = *((Mat*)matches_mat_nativeObj);
        Ptr<cv::DescriptorMatcher>* me = (Ptr<cv::DescriptorMatcher>*) self; //TODO: check for NULL
        Mat& queryDescriptors = *((Mat*)queryDescriptors_nativeObj);
        Mat& trainDescriptors = *((Mat*)trainDescriptors_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        (*me)->radiusMatch( queryDescriptors, trainDescriptors, matches, (float)maxDistance, mask, (bool)compactResult );
        vector_vector_DMatch_to_Mat( matches, matches_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_DescriptorMatcher_radiusMatch_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jfloat, jlong);

JNIEXPORT void JNICALL Java_org_opencv_features2d_DescriptorMatcher_radiusMatch_11
  (JNIEnv* env, jclass , jlong self, jlong queryDescriptors_nativeObj, jlong trainDescriptors_nativeObj, jlong matches_mat_nativeObj, jfloat maxDistance, jlong mask_nativeObj)
{
    static const char method_name[] = "features2d::radiusMatch_11()";
    try {
        LOGD("%s", method_name);
        std::vector< std::vector<DMatch> > matches;
        Mat& matches_mat = *((Mat*)matches_mat_nativeObj);
        Ptr<cv::DescriptorMatcher>* me = (Ptr<cv::DescriptorMatcher>*) self; //TODO: check for NULL
        Mat& queryDescriptors = *((Mat*)queryDescriptors_nativeObj);
        Mat& trainDescriptors = *((Mat*)trainDescriptors_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        (*me)->radiusMatch( queryDescriptors, trainDescriptors, matches, (float)maxDistance, mask );
        vector_vector_DMatch_to_Mat( matches, matches_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_DescriptorMatcher_radiusMatch_12 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_features2d_DescriptorMatcher_radiusMatch_12
  (JNIEnv* env, jclass , jlong self, jlong queryDescriptors_nativeObj, jlong trainDescriptors_nativeObj, jlong matches_mat_nativeObj, jfloat maxDistance)
{
    static const char method_name[] = "features2d::radiusMatch_12()";
    try {
        LOGD("%s", method_name);
        std::vector< std::vector<DMatch> > matches;
        Mat& matches_mat = *((Mat*)matches_mat_nativeObj);
        Ptr<cv::DescriptorMatcher>* me = (Ptr<cv::DescriptorMatcher>*) self; //TODO: check for NULL
        Mat& queryDescriptors = *((Mat*)queryDescriptors_nativeObj);
        Mat& trainDescriptors = *((Mat*)trainDescriptors_nativeObj);
        (*me)->radiusMatch( queryDescriptors, trainDescriptors, matches, (float)maxDistance );
        vector_vector_DMatch_to_Mat( matches, matches_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::DescriptorMatcher::radiusMatch(Mat queryDescriptors, vector_vector_DMatch& matches, float maxDistance, vector_Mat masks = vector_Mat(), bool compactResult = false)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_DescriptorMatcher_radiusMatch_13 (JNIEnv*, jclass, jlong, jlong, jlong, jfloat, jlong, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_features2d_DescriptorMatcher_radiusMatch_13
  (JNIEnv* env, jclass , jlong self, jlong queryDescriptors_nativeObj, jlong matches_mat_nativeObj, jfloat maxDistance, jlong masks_mat_nativeObj, jboolean compactResult)
{
    static const char method_name[] = "features2d::radiusMatch_13()";
    try {
        LOGD("%s", method_name);
        std::vector< std::vector<DMatch> > matches;
        Mat& matches_mat = *((Mat*)matches_mat_nativeObj);
        std::vector<Mat> masks;
        Mat& masks_mat = *((Mat*)masks_mat_nativeObj);
        Mat_to_vector_Mat( masks_mat, masks );
        Ptr<cv::DescriptorMatcher>* me = (Ptr<cv::DescriptorMatcher>*) self; //TODO: check for NULL
        Mat& queryDescriptors = *((Mat*)queryDescriptors_nativeObj);
        (*me)->radiusMatch( queryDescriptors, matches, (float)maxDistance, masks, (bool)compactResult );
        vector_vector_DMatch_to_Mat( matches, matches_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_DescriptorMatcher_radiusMatch_14 (JNIEnv*, jclass, jlong, jlong, jlong, jfloat, jlong);

JNIEXPORT void JNICALL Java_org_opencv_features2d_DescriptorMatcher_radiusMatch_14
  (JNIEnv* env, jclass , jlong self, jlong queryDescriptors_nativeObj, jlong matches_mat_nativeObj, jfloat maxDistance, jlong masks_mat_nativeObj)
{
    static const char method_name[] = "features2d::radiusMatch_14()";
    try {
        LOGD("%s", method_name);
        std::vector< std::vector<DMatch> > matches;
        Mat& matches_mat = *((Mat*)matches_mat_nativeObj);
        std::vector<Mat> masks;
        Mat& masks_mat = *((Mat*)masks_mat_nativeObj);
        Mat_to_vector_Mat( masks_mat, masks );
        Ptr<cv::DescriptorMatcher>* me = (Ptr<cv::DescriptorMatcher>*) self; //TODO: check for NULL
        Mat& queryDescriptors = *((Mat*)queryDescriptors_nativeObj);
        (*me)->radiusMatch( queryDescriptors, matches, (float)maxDistance, masks );
        vector_vector_DMatch_to_Mat( matches, matches_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_DescriptorMatcher_radiusMatch_15 (JNIEnv*, jclass, jlong, jlong, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_features2d_DescriptorMatcher_radiusMatch_15
  (JNIEnv* env, jclass , jlong self, jlong queryDescriptors_nativeObj, jlong matches_mat_nativeObj, jfloat maxDistance)
{
    static const char method_name[] = "features2d::radiusMatch_15()";
    try {
        LOGD("%s", method_name);
        std::vector< std::vector<DMatch> > matches;
        Mat& matches_mat = *((Mat*)matches_mat_nativeObj);
        Ptr<cv::DescriptorMatcher>* me = (Ptr<cv::DescriptorMatcher>*) self; //TODO: check for NULL
        Mat& queryDescriptors = *((Mat*)queryDescriptors_nativeObj);
        (*me)->radiusMatch( queryDescriptors, matches, (float)maxDistance );
        vector_vector_DMatch_to_Mat( matches, matches_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::DescriptorMatcher::read(String fileName)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_DescriptorMatcher_read_10 (JNIEnv*, jclass, jlong, jstring);

JNIEXPORT void JNICALL Java_org_opencv_features2d_DescriptorMatcher_read_10
  (JNIEnv* env, jclass , jlong self, jstring fileName)
{
    static const char method_name[] = "features2d::read_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::DescriptorMatcher>* me = (Ptr<cv::DescriptorMatcher>*) self; //TODO: check for NULL
        const char* utf_fileName = env->GetStringUTFChars(fileName, 0); String n_fileName( utf_fileName ? utf_fileName : "" ); env->ReleaseStringUTFChars(fileName, utf_fileName);
        (*me)->read( n_fileName );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::DescriptorMatcher::train()
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_DescriptorMatcher_train_10 (JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_features2d_DescriptorMatcher_train_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::train_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::DescriptorMatcher>* me = (Ptr<cv::DescriptorMatcher>*) self; //TODO: check for NULL
        (*me)->train();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::DescriptorMatcher::write(String fileName)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_DescriptorMatcher_write_10 (JNIEnv*, jclass, jlong, jstring);

JNIEXPORT void JNICALL Java_org_opencv_features2d_DescriptorMatcher_write_10
  (JNIEnv* env, jclass , jlong self, jstring fileName)
{
    static const char method_name[] = "features2d::write_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::DescriptorMatcher>* me = (Ptr<cv::DescriptorMatcher>*) self; //TODO: check for NULL
        const char* utf_fileName = env->GetStringUTFChars(fileName, 0); String n_fileName( utf_fileName ? utf_fileName : "" ); env->ReleaseStringUTFChars(fileName, utf_fileName);
        (*me)->write( n_fileName );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void Ptr<cv::DescriptorMatcher>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_features2d_DescriptorMatcher_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_features2d_DescriptorMatcher_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::DescriptorMatcher>*) self;
}


//
//  KAZE_DiffusivityType cv::KAZE::getDiffusivity()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_features2d_KAZE_getDiffusivity_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_features2d_KAZE_getDiffusivity_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getDiffusivity_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::KAZE>* me = (Ptr<cv::KAZE>*) self; //TODO: check for NULL
        return (*me)->getDiffusivity();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// static Ptr_KAZE cv::KAZE::create(bool extended = false, bool upright = false, float threshold = 0.001f, int nOctaves = 4, int nOctaveLayers = 4, KAZE_DiffusivityType diffusivity = KAZE::DIFF_PM_G2)
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_KAZE_create_10 (JNIEnv*, jclass, jboolean, jboolean, jfloat, jint, jint, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_KAZE_create_10
  (JNIEnv* env, jclass , jboolean extended, jboolean upright, jfloat threshold, jint nOctaves, jint nOctaveLayers, jint diffusivity)
{
    static const char method_name[] = "features2d::create_10()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::KAZE> Ptr_KAZE;
        Ptr_KAZE _retval_ = cv::KAZE::create( (bool)extended, (bool)upright, (float)threshold, (int)nOctaves, (int)nOctaveLayers, (cv::KAZE::DiffusivityType)diffusivity );
        return (jlong)(new Ptr_KAZE(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_KAZE_create_11 (JNIEnv*, jclass, jboolean, jboolean, jfloat, jint, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_KAZE_create_11
  (JNIEnv* env, jclass , jboolean extended, jboolean upright, jfloat threshold, jint nOctaves, jint nOctaveLayers)
{
    static const char method_name[] = "features2d::create_11()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::KAZE> Ptr_KAZE;
        Ptr_KAZE _retval_ = cv::KAZE::create( (bool)extended, (bool)upright, (float)threshold, (int)nOctaves, (int)nOctaveLayers );
        return (jlong)(new Ptr_KAZE(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_KAZE_create_12 (JNIEnv*, jclass, jboolean, jboolean, jfloat, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_KAZE_create_12
  (JNIEnv* env, jclass , jboolean extended, jboolean upright, jfloat threshold, jint nOctaves)
{
    static const char method_name[] = "features2d::create_12()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::KAZE> Ptr_KAZE;
        Ptr_KAZE _retval_ = cv::KAZE::create( (bool)extended, (bool)upright, (float)threshold, (int)nOctaves );
        return (jlong)(new Ptr_KAZE(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_KAZE_create_13 (JNIEnv*, jclass, jboolean, jboolean, jfloat);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_KAZE_create_13
  (JNIEnv* env, jclass , jboolean extended, jboolean upright, jfloat threshold)
{
    static const char method_name[] = "features2d::create_13()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::KAZE> Ptr_KAZE;
        Ptr_KAZE _retval_ = cv::KAZE::create( (bool)extended, (bool)upright, (float)threshold );
        return (jlong)(new Ptr_KAZE(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_KAZE_create_14 (JNIEnv*, jclass, jboolean, jboolean);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_KAZE_create_14
  (JNIEnv* env, jclass , jboolean extended, jboolean upright)
{
    static const char method_name[] = "features2d::create_14()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::KAZE> Ptr_KAZE;
        Ptr_KAZE _retval_ = cv::KAZE::create( (bool)extended, (bool)upright );
        return (jlong)(new Ptr_KAZE(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_KAZE_create_15 (JNIEnv*, jclass, jboolean);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_KAZE_create_15
  (JNIEnv* env, jclass , jboolean extended)
{
    static const char method_name[] = "features2d::create_15()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::KAZE> Ptr_KAZE;
        Ptr_KAZE _retval_ = cv::KAZE::create( (bool)extended );
        return (jlong)(new Ptr_KAZE(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_KAZE_create_16 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_KAZE_create_16
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "features2d::create_16()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::KAZE> Ptr_KAZE;
        Ptr_KAZE _retval_ = cv::KAZE::create();
        return (jlong)(new Ptr_KAZE(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  String cv::KAZE::getDefaultName()
//

using namespace cv;

JNIEXPORT jstring JNICALL Java_org_opencv_features2d_KAZE_getDefaultName_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jstring JNICALL Java_org_opencv_features2d_KAZE_getDefaultName_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getDefaultName_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::KAZE>* me = (Ptr<cv::KAZE>*) self; //TODO: check for NULL
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
//  bool cv::KAZE::getExtended()
//

using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_features2d_KAZE_getExtended_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_features2d_KAZE_getExtended_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getExtended_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::KAZE>* me = (Ptr<cv::KAZE>*) self; //TODO: check for NULL
        return (*me)->getExtended();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  bool cv::KAZE::getUpright()
//

using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_features2d_KAZE_getUpright_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_features2d_KAZE_getUpright_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getUpright_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::KAZE>* me = (Ptr<cv::KAZE>*) self; //TODO: check for NULL
        return (*me)->getUpright();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::KAZE::getThreshold()
//

using namespace cv;

JNIEXPORT jdouble JNICALL Java_org_opencv_features2d_KAZE_getThreshold_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_features2d_KAZE_getThreshold_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getThreshold_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::KAZE>* me = (Ptr<cv::KAZE>*) self; //TODO: check for NULL
        return (*me)->getThreshold();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::KAZE::getNOctaveLayers()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_features2d_KAZE_getNOctaveLayers_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_features2d_KAZE_getNOctaveLayers_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getNOctaveLayers_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::KAZE>* me = (Ptr<cv::KAZE>*) self; //TODO: check for NULL
        return (*me)->getNOctaveLayers();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::KAZE::getNOctaves()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_features2d_KAZE_getNOctaves_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_features2d_KAZE_getNOctaves_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getNOctaves_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::KAZE>* me = (Ptr<cv::KAZE>*) self; //TODO: check for NULL
        return (*me)->getNOctaves();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::KAZE::setDiffusivity(KAZE_DiffusivityType diff)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_KAZE_setDiffusivity_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_features2d_KAZE_setDiffusivity_10
  (JNIEnv* env, jclass , jlong self, jint diff)
{
    static const char method_name[] = "features2d::setDiffusivity_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::KAZE>* me = (Ptr<cv::KAZE>*) self; //TODO: check for NULL
        (*me)->setDiffusivity( (cv::KAZE::DiffusivityType)diff );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::KAZE::setExtended(bool extended)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_KAZE_setExtended_10 (JNIEnv*, jclass, jlong, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_features2d_KAZE_setExtended_10
  (JNIEnv* env, jclass , jlong self, jboolean extended)
{
    static const char method_name[] = "features2d::setExtended_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::KAZE>* me = (Ptr<cv::KAZE>*) self; //TODO: check for NULL
        (*me)->setExtended( (bool)extended );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::KAZE::setNOctaveLayers(int octaveLayers)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_KAZE_setNOctaveLayers_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_features2d_KAZE_setNOctaveLayers_10
  (JNIEnv* env, jclass , jlong self, jint octaveLayers)
{
    static const char method_name[] = "features2d::setNOctaveLayers_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::KAZE>* me = (Ptr<cv::KAZE>*) self; //TODO: check for NULL
        (*me)->setNOctaveLayers( (int)octaveLayers );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::KAZE::setNOctaves(int octaves)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_KAZE_setNOctaves_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_features2d_KAZE_setNOctaves_10
  (JNIEnv* env, jclass , jlong self, jint octaves)
{
    static const char method_name[] = "features2d::setNOctaves_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::KAZE>* me = (Ptr<cv::KAZE>*) self; //TODO: check for NULL
        (*me)->setNOctaves( (int)octaves );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::KAZE::setThreshold(double threshold)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_KAZE_setThreshold_10 (JNIEnv*, jclass, jlong, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_features2d_KAZE_setThreshold_10
  (JNIEnv* env, jclass , jlong self, jdouble threshold)
{
    static const char method_name[] = "features2d::setThreshold_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::KAZE>* me = (Ptr<cv::KAZE>*) self; //TODO: check for NULL
        (*me)->setThreshold( (double)threshold );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::KAZE::setUpright(bool upright)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_KAZE_setUpright_10 (JNIEnv*, jclass, jlong, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_features2d_KAZE_setUpright_10
  (JNIEnv* env, jclass , jlong self, jboolean upright)
{
    static const char method_name[] = "features2d::setUpright_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::KAZE>* me = (Ptr<cv::KAZE>*) self; //TODO: check for NULL
        (*me)->setUpright( (bool)upright );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void Ptr<cv::KAZE>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_features2d_KAZE_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_features2d_KAZE_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::KAZE>*) self;
}


//
//  void cv::drawKeypoints(Mat image, vector_KeyPoint keypoints, Mat& outImage, Scalar color = Scalar::all(-1), DrawMatchesFlags flags = DrawMatchesFlags::DEFAULT)
//



JNIEXPORT void JNICALL Java_org_opencv_features2d_Features2d_drawKeypoints_10 (JNIEnv*, jclass, jlong, jlong, jlong, jdouble, jdouble, jdouble, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_features2d_Features2d_drawKeypoints_10
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong keypoints_mat_nativeObj, jlong outImage_nativeObj, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3, jint flags)
{
    static const char method_name[] = "features2d::drawKeypoints_10()";
    try {
        LOGD("%s", method_name);
        std::vector<KeyPoint> keypoints;
        Mat& keypoints_mat = *((Mat*)keypoints_mat_nativeObj);
        Mat_to_vector_KeyPoint( keypoints_mat, keypoints );
        Mat& image = *((Mat*)image_nativeObj);
        Mat& outImage = *((Mat*)outImage_nativeObj);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::drawKeypoints( image, keypoints, outImage, color, (cv::DrawMatchesFlags)flags );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_features2d_Features2d_drawKeypoints_11 (JNIEnv*, jclass, jlong, jlong, jlong, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_features2d_Features2d_drawKeypoints_11
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong keypoints_mat_nativeObj, jlong outImage_nativeObj, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3)
{
    static const char method_name[] = "features2d::drawKeypoints_11()";
    try {
        LOGD("%s", method_name);
        std::vector<KeyPoint> keypoints;
        Mat& keypoints_mat = *((Mat*)keypoints_mat_nativeObj);
        Mat_to_vector_KeyPoint( keypoints_mat, keypoints );
        Mat& image = *((Mat*)image_nativeObj);
        Mat& outImage = *((Mat*)outImage_nativeObj);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::drawKeypoints( image, keypoints, outImage, color );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_features2d_Features2d_drawKeypoints_12 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_features2d_Features2d_drawKeypoints_12
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong keypoints_mat_nativeObj, jlong outImage_nativeObj)
{
    static const char method_name[] = "features2d::drawKeypoints_12()";
    try {
        LOGD("%s", method_name);
        std::vector<KeyPoint> keypoints;
        Mat& keypoints_mat = *((Mat*)keypoints_mat_nativeObj);
        Mat_to_vector_KeyPoint( keypoints_mat, keypoints );
        Mat& image = *((Mat*)image_nativeObj);
        Mat& outImage = *((Mat*)outImage_nativeObj);
        cv::drawKeypoints( image, keypoints, outImage );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::drawMatches(Mat img1, vector_KeyPoint keypoints1, Mat img2, vector_KeyPoint keypoints2, vector_DMatch matches1to2, Mat& outImg, Scalar matchColor = Scalar::all(-1), Scalar singlePointColor = Scalar::all(-1), vector_char matchesMask = std::vector<char>(), DrawMatchesFlags flags = DrawMatchesFlags::DEFAULT)
//



JNIEXPORT void JNICALL Java_org_opencv_features2d_Features2d_drawMatches_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_features2d_Features2d_drawMatches_10
  (JNIEnv* env, jclass , jlong img1_nativeObj, jlong keypoints1_mat_nativeObj, jlong img2_nativeObj, jlong keypoints2_mat_nativeObj, jlong matches1to2_mat_nativeObj, jlong outImg_nativeObj, jdouble matchColor_val0, jdouble matchColor_val1, jdouble matchColor_val2, jdouble matchColor_val3, jdouble singlePointColor_val0, jdouble singlePointColor_val1, jdouble singlePointColor_val2, jdouble singlePointColor_val3, jlong matchesMask_mat_nativeObj, jint flags)
{
    static const char method_name[] = "features2d::drawMatches_10()";
    try {
        LOGD("%s", method_name);
        std::vector<KeyPoint> keypoints1;
        Mat& keypoints1_mat = *((Mat*)keypoints1_mat_nativeObj);
        Mat_to_vector_KeyPoint( keypoints1_mat, keypoints1 );
        std::vector<KeyPoint> keypoints2;
        Mat& keypoints2_mat = *((Mat*)keypoints2_mat_nativeObj);
        Mat_to_vector_KeyPoint( keypoints2_mat, keypoints2 );
        std::vector<DMatch> matches1to2;
        Mat& matches1to2_mat = *((Mat*)matches1to2_mat_nativeObj);
        Mat_to_vector_DMatch( matches1to2_mat, matches1to2 );
        std::vector<char> matchesMask;
        Mat& matchesMask_mat = *((Mat*)matchesMask_mat_nativeObj);
        Mat_to_vector_char( matchesMask_mat, matchesMask );
        Mat& img1 = *((Mat*)img1_nativeObj);
        Mat& img2 = *((Mat*)img2_nativeObj);
        Mat& outImg = *((Mat*)outImg_nativeObj);
        Scalar matchColor(matchColor_val0, matchColor_val1, matchColor_val2, matchColor_val3);
        Scalar singlePointColor(singlePointColor_val0, singlePointColor_val1, singlePointColor_val2, singlePointColor_val3);
        cv::drawMatches( img1, keypoints1, img2, keypoints2, matches1to2, outImg, matchColor, singlePointColor, matchesMask, (cv::DrawMatchesFlags)flags );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_features2d_Features2d_drawMatches_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jlong);

JNIEXPORT void JNICALL Java_org_opencv_features2d_Features2d_drawMatches_11
  (JNIEnv* env, jclass , jlong img1_nativeObj, jlong keypoints1_mat_nativeObj, jlong img2_nativeObj, jlong keypoints2_mat_nativeObj, jlong matches1to2_mat_nativeObj, jlong outImg_nativeObj, jdouble matchColor_val0, jdouble matchColor_val1, jdouble matchColor_val2, jdouble matchColor_val3, jdouble singlePointColor_val0, jdouble singlePointColor_val1, jdouble singlePointColor_val2, jdouble singlePointColor_val3, jlong matchesMask_mat_nativeObj)
{
    static const char method_name[] = "features2d::drawMatches_11()";
    try {
        LOGD("%s", method_name);
        std::vector<KeyPoint> keypoints1;
        Mat& keypoints1_mat = *((Mat*)keypoints1_mat_nativeObj);
        Mat_to_vector_KeyPoint( keypoints1_mat, keypoints1 );
        std::vector<KeyPoint> keypoints2;
        Mat& keypoints2_mat = *((Mat*)keypoints2_mat_nativeObj);
        Mat_to_vector_KeyPoint( keypoints2_mat, keypoints2 );
        std::vector<DMatch> matches1to2;
        Mat& matches1to2_mat = *((Mat*)matches1to2_mat_nativeObj);
        Mat_to_vector_DMatch( matches1to2_mat, matches1to2 );
        std::vector<char> matchesMask;
        Mat& matchesMask_mat = *((Mat*)matchesMask_mat_nativeObj);
        Mat_to_vector_char( matchesMask_mat, matchesMask );
        Mat& img1 = *((Mat*)img1_nativeObj);
        Mat& img2 = *((Mat*)img2_nativeObj);
        Mat& outImg = *((Mat*)outImg_nativeObj);
        Scalar matchColor(matchColor_val0, matchColor_val1, matchColor_val2, matchColor_val3);
        Scalar singlePointColor(singlePointColor_val0, singlePointColor_val1, singlePointColor_val2, singlePointColor_val3);
        cv::drawMatches( img1, keypoints1, img2, keypoints2, matches1to2, outImg, matchColor, singlePointColor, matchesMask );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_features2d_Features2d_drawMatches_12 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_features2d_Features2d_drawMatches_12
  (JNIEnv* env, jclass , jlong img1_nativeObj, jlong keypoints1_mat_nativeObj, jlong img2_nativeObj, jlong keypoints2_mat_nativeObj, jlong matches1to2_mat_nativeObj, jlong outImg_nativeObj, jdouble matchColor_val0, jdouble matchColor_val1, jdouble matchColor_val2, jdouble matchColor_val3, jdouble singlePointColor_val0, jdouble singlePointColor_val1, jdouble singlePointColor_val2, jdouble singlePointColor_val3)
{
    static const char method_name[] = "features2d::drawMatches_12()";
    try {
        LOGD("%s", method_name);
        std::vector<KeyPoint> keypoints1;
        Mat& keypoints1_mat = *((Mat*)keypoints1_mat_nativeObj);
        Mat_to_vector_KeyPoint( keypoints1_mat, keypoints1 );
        std::vector<KeyPoint> keypoints2;
        Mat& keypoints2_mat = *((Mat*)keypoints2_mat_nativeObj);
        Mat_to_vector_KeyPoint( keypoints2_mat, keypoints2 );
        std::vector<DMatch> matches1to2;
        Mat& matches1to2_mat = *((Mat*)matches1to2_mat_nativeObj);
        Mat_to_vector_DMatch( matches1to2_mat, matches1to2 );
        Mat& img1 = *((Mat*)img1_nativeObj);
        Mat& img2 = *((Mat*)img2_nativeObj);
        Mat& outImg = *((Mat*)outImg_nativeObj);
        Scalar matchColor(matchColor_val0, matchColor_val1, matchColor_val2, matchColor_val3);
        Scalar singlePointColor(singlePointColor_val0, singlePointColor_val1, singlePointColor_val2, singlePointColor_val3);
        cv::drawMatches( img1, keypoints1, img2, keypoints2, matches1to2, outImg, matchColor, singlePointColor );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_features2d_Features2d_drawMatches_13 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_features2d_Features2d_drawMatches_13
  (JNIEnv* env, jclass , jlong img1_nativeObj, jlong keypoints1_mat_nativeObj, jlong img2_nativeObj, jlong keypoints2_mat_nativeObj, jlong matches1to2_mat_nativeObj, jlong outImg_nativeObj, jdouble matchColor_val0, jdouble matchColor_val1, jdouble matchColor_val2, jdouble matchColor_val3)
{
    static const char method_name[] = "features2d::drawMatches_13()";
    try {
        LOGD("%s", method_name);
        std::vector<KeyPoint> keypoints1;
        Mat& keypoints1_mat = *((Mat*)keypoints1_mat_nativeObj);
        Mat_to_vector_KeyPoint( keypoints1_mat, keypoints1 );
        std::vector<KeyPoint> keypoints2;
        Mat& keypoints2_mat = *((Mat*)keypoints2_mat_nativeObj);
        Mat_to_vector_KeyPoint( keypoints2_mat, keypoints2 );
        std::vector<DMatch> matches1to2;
        Mat& matches1to2_mat = *((Mat*)matches1to2_mat_nativeObj);
        Mat_to_vector_DMatch( matches1to2_mat, matches1to2 );
        Mat& img1 = *((Mat*)img1_nativeObj);
        Mat& img2 = *((Mat*)img2_nativeObj);
        Mat& outImg = *((Mat*)outImg_nativeObj);
        Scalar matchColor(matchColor_val0, matchColor_val1, matchColor_val2, matchColor_val3);
        cv::drawMatches( img1, keypoints1, img2, keypoints2, matches1to2, outImg, matchColor );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_features2d_Features2d_drawMatches_14 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_features2d_Features2d_drawMatches_14
  (JNIEnv* env, jclass , jlong img1_nativeObj, jlong keypoints1_mat_nativeObj, jlong img2_nativeObj, jlong keypoints2_mat_nativeObj, jlong matches1to2_mat_nativeObj, jlong outImg_nativeObj)
{
    static const char method_name[] = "features2d::drawMatches_14()";
    try {
        LOGD("%s", method_name);
        std::vector<KeyPoint> keypoints1;
        Mat& keypoints1_mat = *((Mat*)keypoints1_mat_nativeObj);
        Mat_to_vector_KeyPoint( keypoints1_mat, keypoints1 );
        std::vector<KeyPoint> keypoints2;
        Mat& keypoints2_mat = *((Mat*)keypoints2_mat_nativeObj);
        Mat_to_vector_KeyPoint( keypoints2_mat, keypoints2 );
        std::vector<DMatch> matches1to2;
        Mat& matches1to2_mat = *((Mat*)matches1to2_mat_nativeObj);
        Mat_to_vector_DMatch( matches1to2_mat, matches1to2 );
        Mat& img1 = *((Mat*)img1_nativeObj);
        Mat& img2 = *((Mat*)img2_nativeObj);
        Mat& outImg = *((Mat*)outImg_nativeObj);
        cv::drawMatches( img1, keypoints1, img2, keypoints2, matches1to2, outImg );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::drawMatches(Mat img1, vector_KeyPoint keypoints1, Mat img2, vector_KeyPoint keypoints2, vector_vector_DMatch matches1to2, Mat& outImg, Scalar matchColor = Scalar::all(-1), Scalar singlePointColor = Scalar::all(-1), vector_vector_char matchesMask = std::vector<std::vector<char> >(), DrawMatchesFlags flags = DrawMatchesFlags::DEFAULT)
//



JNIEXPORT void JNICALL Java_org_opencv_features2d_Features2d_drawMatchesKnn_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_features2d_Features2d_drawMatchesKnn_10
  (JNIEnv* env, jclass , jlong img1_nativeObj, jlong keypoints1_mat_nativeObj, jlong img2_nativeObj, jlong keypoints2_mat_nativeObj, jlong matches1to2_mat_nativeObj, jlong outImg_nativeObj, jdouble matchColor_val0, jdouble matchColor_val1, jdouble matchColor_val2, jdouble matchColor_val3, jdouble singlePointColor_val0, jdouble singlePointColor_val1, jdouble singlePointColor_val2, jdouble singlePointColor_val3, jlong matchesMask_mat_nativeObj, jint flags)
{
    static const char method_name[] = "features2d::drawMatchesKnn_10()";
    try {
        LOGD("%s", method_name);
        std::vector<KeyPoint> keypoints1;
        Mat& keypoints1_mat = *((Mat*)keypoints1_mat_nativeObj);
        Mat_to_vector_KeyPoint( keypoints1_mat, keypoints1 );
        std::vector<KeyPoint> keypoints2;
        Mat& keypoints2_mat = *((Mat*)keypoints2_mat_nativeObj);
        Mat_to_vector_KeyPoint( keypoints2_mat, keypoints2 );
        std::vector< std::vector<DMatch> > matches1to2;
        Mat& matches1to2_mat = *((Mat*)matches1to2_mat_nativeObj);
        Mat_to_vector_vector_DMatch( matches1to2_mat, matches1to2 );
        std::vector< std::vector<char> > matchesMask;
        Mat& matchesMask_mat = *((Mat*)matchesMask_mat_nativeObj);
        Mat_to_vector_vector_char( matchesMask_mat, matchesMask );
        Mat& img1 = *((Mat*)img1_nativeObj);
        Mat& img2 = *((Mat*)img2_nativeObj);
        Mat& outImg = *((Mat*)outImg_nativeObj);
        Scalar matchColor(matchColor_val0, matchColor_val1, matchColor_val2, matchColor_val3);
        Scalar singlePointColor(singlePointColor_val0, singlePointColor_val1, singlePointColor_val2, singlePointColor_val3);
        cv::drawMatches( img1, keypoints1, img2, keypoints2, matches1to2, outImg, matchColor, singlePointColor, matchesMask, (cv::DrawMatchesFlags)flags );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_features2d_Features2d_drawMatchesKnn_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jlong);

JNIEXPORT void JNICALL Java_org_opencv_features2d_Features2d_drawMatchesKnn_11
  (JNIEnv* env, jclass , jlong img1_nativeObj, jlong keypoints1_mat_nativeObj, jlong img2_nativeObj, jlong keypoints2_mat_nativeObj, jlong matches1to2_mat_nativeObj, jlong outImg_nativeObj, jdouble matchColor_val0, jdouble matchColor_val1, jdouble matchColor_val2, jdouble matchColor_val3, jdouble singlePointColor_val0, jdouble singlePointColor_val1, jdouble singlePointColor_val2, jdouble singlePointColor_val3, jlong matchesMask_mat_nativeObj)
{
    static const char method_name[] = "features2d::drawMatchesKnn_11()";
    try {
        LOGD("%s", method_name);
        std::vector<KeyPoint> keypoints1;
        Mat& keypoints1_mat = *((Mat*)keypoints1_mat_nativeObj);
        Mat_to_vector_KeyPoint( keypoints1_mat, keypoints1 );
        std::vector<KeyPoint> keypoints2;
        Mat& keypoints2_mat = *((Mat*)keypoints2_mat_nativeObj);
        Mat_to_vector_KeyPoint( keypoints2_mat, keypoints2 );
        std::vector< std::vector<DMatch> > matches1to2;
        Mat& matches1to2_mat = *((Mat*)matches1to2_mat_nativeObj);
        Mat_to_vector_vector_DMatch( matches1to2_mat, matches1to2 );
        std::vector< std::vector<char> > matchesMask;
        Mat& matchesMask_mat = *((Mat*)matchesMask_mat_nativeObj);
        Mat_to_vector_vector_char( matchesMask_mat, matchesMask );
        Mat& img1 = *((Mat*)img1_nativeObj);
        Mat& img2 = *((Mat*)img2_nativeObj);
        Mat& outImg = *((Mat*)outImg_nativeObj);
        Scalar matchColor(matchColor_val0, matchColor_val1, matchColor_val2, matchColor_val3);
        Scalar singlePointColor(singlePointColor_val0, singlePointColor_val1, singlePointColor_val2, singlePointColor_val3);
        cv::drawMatches( img1, keypoints1, img2, keypoints2, matches1to2, outImg, matchColor, singlePointColor, matchesMask );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_features2d_Features2d_drawMatchesKnn_12 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_features2d_Features2d_drawMatchesKnn_12
  (JNIEnv* env, jclass , jlong img1_nativeObj, jlong keypoints1_mat_nativeObj, jlong img2_nativeObj, jlong keypoints2_mat_nativeObj, jlong matches1to2_mat_nativeObj, jlong outImg_nativeObj, jdouble matchColor_val0, jdouble matchColor_val1, jdouble matchColor_val2, jdouble matchColor_val3, jdouble singlePointColor_val0, jdouble singlePointColor_val1, jdouble singlePointColor_val2, jdouble singlePointColor_val3)
{
    static const char method_name[] = "features2d::drawMatchesKnn_12()";
    try {
        LOGD("%s", method_name);
        std::vector<KeyPoint> keypoints1;
        Mat& keypoints1_mat = *((Mat*)keypoints1_mat_nativeObj);
        Mat_to_vector_KeyPoint( keypoints1_mat, keypoints1 );
        std::vector<KeyPoint> keypoints2;
        Mat& keypoints2_mat = *((Mat*)keypoints2_mat_nativeObj);
        Mat_to_vector_KeyPoint( keypoints2_mat, keypoints2 );
        std::vector< std::vector<DMatch> > matches1to2;
        Mat& matches1to2_mat = *((Mat*)matches1to2_mat_nativeObj);
        Mat_to_vector_vector_DMatch( matches1to2_mat, matches1to2 );
        Mat& img1 = *((Mat*)img1_nativeObj);
        Mat& img2 = *((Mat*)img2_nativeObj);
        Mat& outImg = *((Mat*)outImg_nativeObj);
        Scalar matchColor(matchColor_val0, matchColor_val1, matchColor_val2, matchColor_val3);
        Scalar singlePointColor(singlePointColor_val0, singlePointColor_val1, singlePointColor_val2, singlePointColor_val3);
        cv::drawMatches( img1, keypoints1, img2, keypoints2, matches1to2, outImg, matchColor, singlePointColor );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_features2d_Features2d_drawMatchesKnn_13 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_features2d_Features2d_drawMatchesKnn_13
  (JNIEnv* env, jclass , jlong img1_nativeObj, jlong keypoints1_mat_nativeObj, jlong img2_nativeObj, jlong keypoints2_mat_nativeObj, jlong matches1to2_mat_nativeObj, jlong outImg_nativeObj, jdouble matchColor_val0, jdouble matchColor_val1, jdouble matchColor_val2, jdouble matchColor_val3)
{
    static const char method_name[] = "features2d::drawMatchesKnn_13()";
    try {
        LOGD("%s", method_name);
        std::vector<KeyPoint> keypoints1;
        Mat& keypoints1_mat = *((Mat*)keypoints1_mat_nativeObj);
        Mat_to_vector_KeyPoint( keypoints1_mat, keypoints1 );
        std::vector<KeyPoint> keypoints2;
        Mat& keypoints2_mat = *((Mat*)keypoints2_mat_nativeObj);
        Mat_to_vector_KeyPoint( keypoints2_mat, keypoints2 );
        std::vector< std::vector<DMatch> > matches1to2;
        Mat& matches1to2_mat = *((Mat*)matches1to2_mat_nativeObj);
        Mat_to_vector_vector_DMatch( matches1to2_mat, matches1to2 );
        Mat& img1 = *((Mat*)img1_nativeObj);
        Mat& img2 = *((Mat*)img2_nativeObj);
        Mat& outImg = *((Mat*)outImg_nativeObj);
        Scalar matchColor(matchColor_val0, matchColor_val1, matchColor_val2, matchColor_val3);
        cv::drawMatches( img1, keypoints1, img2, keypoints2, matches1to2, outImg, matchColor );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_features2d_Features2d_drawMatchesKnn_14 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_features2d_Features2d_drawMatchesKnn_14
  (JNIEnv* env, jclass , jlong img1_nativeObj, jlong keypoints1_mat_nativeObj, jlong img2_nativeObj, jlong keypoints2_mat_nativeObj, jlong matches1to2_mat_nativeObj, jlong outImg_nativeObj)
{
    static const char method_name[] = "features2d::drawMatchesKnn_14()";
    try {
        LOGD("%s", method_name);
        std::vector<KeyPoint> keypoints1;
        Mat& keypoints1_mat = *((Mat*)keypoints1_mat_nativeObj);
        Mat_to_vector_KeyPoint( keypoints1_mat, keypoints1 );
        std::vector<KeyPoint> keypoints2;
        Mat& keypoints2_mat = *((Mat*)keypoints2_mat_nativeObj);
        Mat_to_vector_KeyPoint( keypoints2_mat, keypoints2 );
        std::vector< std::vector<DMatch> > matches1to2;
        Mat& matches1to2_mat = *((Mat*)matches1to2_mat_nativeObj);
        Mat_to_vector_vector_DMatch( matches1to2_mat, matches1to2 );
        Mat& img1 = *((Mat*)img1_nativeObj);
        Mat& img2 = *((Mat*)img2_nativeObj);
        Mat& outImg = *((Mat*)outImg_nativeObj);
        cv::drawMatches( img1, keypoints1, img2, keypoints2, matches1to2, outImg );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  AKAZE_DescriptorType cv::AKAZE::getDescriptorType()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_features2d_AKAZE_getDescriptorType_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_features2d_AKAZE_getDescriptorType_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getDescriptorType_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::AKAZE>* me = (Ptr<cv::AKAZE>*) self; //TODO: check for NULL
        return (*me)->getDescriptorType();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  KAZE_DiffusivityType cv::AKAZE::getDiffusivity()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_features2d_AKAZE_getDiffusivity_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_features2d_AKAZE_getDiffusivity_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getDiffusivity_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::AKAZE>* me = (Ptr<cv::AKAZE>*) self; //TODO: check for NULL
        return (*me)->getDiffusivity();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// static Ptr_AKAZE cv::AKAZE::create(AKAZE_DescriptorType descriptor_type = AKAZE::DESCRIPTOR_MLDB, int descriptor_size = 0, int descriptor_channels = 3, float threshold = 0.001f, int nOctaves = 4, int nOctaveLayers = 4, KAZE_DiffusivityType diffusivity = KAZE::DIFF_PM_G2)
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_AKAZE_create_10 (JNIEnv*, jclass, jint, jint, jint, jfloat, jint, jint, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_AKAZE_create_10
  (JNIEnv* env, jclass , jint descriptor_type, jint descriptor_size, jint descriptor_channels, jfloat threshold, jint nOctaves, jint nOctaveLayers, jint diffusivity)
{
    static const char method_name[] = "features2d::create_10()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::AKAZE> Ptr_AKAZE;
        Ptr_AKAZE _retval_ = cv::AKAZE::create( (cv::AKAZE::DescriptorType)descriptor_type, (int)descriptor_size, (int)descriptor_channels, (float)threshold, (int)nOctaves, (int)nOctaveLayers, (cv::KAZE::DiffusivityType)diffusivity );
        return (jlong)(new Ptr_AKAZE(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_AKAZE_create_11 (JNIEnv*, jclass, jint, jint, jint, jfloat, jint, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_AKAZE_create_11
  (JNIEnv* env, jclass , jint descriptor_type, jint descriptor_size, jint descriptor_channels, jfloat threshold, jint nOctaves, jint nOctaveLayers)
{
    static const char method_name[] = "features2d::create_11()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::AKAZE> Ptr_AKAZE;
        Ptr_AKAZE _retval_ = cv::AKAZE::create( (cv::AKAZE::DescriptorType)descriptor_type, (int)descriptor_size, (int)descriptor_channels, (float)threshold, (int)nOctaves, (int)nOctaveLayers );
        return (jlong)(new Ptr_AKAZE(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_AKAZE_create_12 (JNIEnv*, jclass, jint, jint, jint, jfloat, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_AKAZE_create_12
  (JNIEnv* env, jclass , jint descriptor_type, jint descriptor_size, jint descriptor_channels, jfloat threshold, jint nOctaves)
{
    static const char method_name[] = "features2d::create_12()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::AKAZE> Ptr_AKAZE;
        Ptr_AKAZE _retval_ = cv::AKAZE::create( (cv::AKAZE::DescriptorType)descriptor_type, (int)descriptor_size, (int)descriptor_channels, (float)threshold, (int)nOctaves );
        return (jlong)(new Ptr_AKAZE(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_AKAZE_create_13 (JNIEnv*, jclass, jint, jint, jint, jfloat);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_AKAZE_create_13
  (JNIEnv* env, jclass , jint descriptor_type, jint descriptor_size, jint descriptor_channels, jfloat threshold)
{
    static const char method_name[] = "features2d::create_13()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::AKAZE> Ptr_AKAZE;
        Ptr_AKAZE _retval_ = cv::AKAZE::create( (cv::AKAZE::DescriptorType)descriptor_type, (int)descriptor_size, (int)descriptor_channels, (float)threshold );
        return (jlong)(new Ptr_AKAZE(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_AKAZE_create_14 (JNIEnv*, jclass, jint, jint, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_AKAZE_create_14
  (JNIEnv* env, jclass , jint descriptor_type, jint descriptor_size, jint descriptor_channels)
{
    static const char method_name[] = "features2d::create_14()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::AKAZE> Ptr_AKAZE;
        Ptr_AKAZE _retval_ = cv::AKAZE::create( (cv::AKAZE::DescriptorType)descriptor_type, (int)descriptor_size, (int)descriptor_channels );
        return (jlong)(new Ptr_AKAZE(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_AKAZE_create_15 (JNIEnv*, jclass, jint, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_AKAZE_create_15
  (JNIEnv* env, jclass , jint descriptor_type, jint descriptor_size)
{
    static const char method_name[] = "features2d::create_15()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::AKAZE> Ptr_AKAZE;
        Ptr_AKAZE _retval_ = cv::AKAZE::create( (cv::AKAZE::DescriptorType)descriptor_type, (int)descriptor_size );
        return (jlong)(new Ptr_AKAZE(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_AKAZE_create_16 (JNIEnv*, jclass, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_AKAZE_create_16
  (JNIEnv* env, jclass , jint descriptor_type)
{
    static const char method_name[] = "features2d::create_16()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::AKAZE> Ptr_AKAZE;
        Ptr_AKAZE _retval_ = cv::AKAZE::create( (cv::AKAZE::DescriptorType)descriptor_type );
        return (jlong)(new Ptr_AKAZE(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_AKAZE_create_17 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_AKAZE_create_17
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "features2d::create_17()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::AKAZE> Ptr_AKAZE;
        Ptr_AKAZE _retval_ = cv::AKAZE::create();
        return (jlong)(new Ptr_AKAZE(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  String cv::AKAZE::getDefaultName()
//

using namespace cv;

JNIEXPORT jstring JNICALL Java_org_opencv_features2d_AKAZE_getDefaultName_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jstring JNICALL Java_org_opencv_features2d_AKAZE_getDefaultName_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getDefaultName_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::AKAZE>* me = (Ptr<cv::AKAZE>*) self; //TODO: check for NULL
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
//  double cv::AKAZE::getThreshold()
//

using namespace cv;

JNIEXPORT jdouble JNICALL Java_org_opencv_features2d_AKAZE_getThreshold_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_features2d_AKAZE_getThreshold_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getThreshold_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::AKAZE>* me = (Ptr<cv::AKAZE>*) self; //TODO: check for NULL
        return (*me)->getThreshold();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::AKAZE::getDescriptorChannels()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_features2d_AKAZE_getDescriptorChannels_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_features2d_AKAZE_getDescriptorChannels_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getDescriptorChannels_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::AKAZE>* me = (Ptr<cv::AKAZE>*) self; //TODO: check for NULL
        return (*me)->getDescriptorChannels();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::AKAZE::getDescriptorSize()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_features2d_AKAZE_getDescriptorSize_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_features2d_AKAZE_getDescriptorSize_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getDescriptorSize_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::AKAZE>* me = (Ptr<cv::AKAZE>*) self; //TODO: check for NULL
        return (*me)->getDescriptorSize();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::AKAZE::getNOctaveLayers()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_features2d_AKAZE_getNOctaveLayers_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_features2d_AKAZE_getNOctaveLayers_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getNOctaveLayers_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::AKAZE>* me = (Ptr<cv::AKAZE>*) self; //TODO: check for NULL
        return (*me)->getNOctaveLayers();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::AKAZE::getNOctaves()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_features2d_AKAZE_getNOctaves_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_features2d_AKAZE_getNOctaves_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getNOctaves_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::AKAZE>* me = (Ptr<cv::AKAZE>*) self; //TODO: check for NULL
        return (*me)->getNOctaves();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::AKAZE::setDescriptorChannels(int dch)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_AKAZE_setDescriptorChannels_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_features2d_AKAZE_setDescriptorChannels_10
  (JNIEnv* env, jclass , jlong self, jint dch)
{
    static const char method_name[] = "features2d::setDescriptorChannels_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::AKAZE>* me = (Ptr<cv::AKAZE>*) self; //TODO: check for NULL
        (*me)->setDescriptorChannels( (int)dch );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::AKAZE::setDescriptorSize(int dsize)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_AKAZE_setDescriptorSize_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_features2d_AKAZE_setDescriptorSize_10
  (JNIEnv* env, jclass , jlong self, jint dsize)
{
    static const char method_name[] = "features2d::setDescriptorSize_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::AKAZE>* me = (Ptr<cv::AKAZE>*) self; //TODO: check for NULL
        (*me)->setDescriptorSize( (int)dsize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::AKAZE::setDescriptorType(AKAZE_DescriptorType dtype)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_AKAZE_setDescriptorType_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_features2d_AKAZE_setDescriptorType_10
  (JNIEnv* env, jclass , jlong self, jint dtype)
{
    static const char method_name[] = "features2d::setDescriptorType_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::AKAZE>* me = (Ptr<cv::AKAZE>*) self; //TODO: check for NULL
        (*me)->setDescriptorType( (cv::AKAZE::DescriptorType)dtype );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::AKAZE::setDiffusivity(KAZE_DiffusivityType diff)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_AKAZE_setDiffusivity_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_features2d_AKAZE_setDiffusivity_10
  (JNIEnv* env, jclass , jlong self, jint diff)
{
    static const char method_name[] = "features2d::setDiffusivity_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::AKAZE>* me = (Ptr<cv::AKAZE>*) self; //TODO: check for NULL
        (*me)->setDiffusivity( (cv::KAZE::DiffusivityType)diff );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::AKAZE::setNOctaveLayers(int octaveLayers)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_AKAZE_setNOctaveLayers_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_features2d_AKAZE_setNOctaveLayers_10
  (JNIEnv* env, jclass , jlong self, jint octaveLayers)
{
    static const char method_name[] = "features2d::setNOctaveLayers_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::AKAZE>* me = (Ptr<cv::AKAZE>*) self; //TODO: check for NULL
        (*me)->setNOctaveLayers( (int)octaveLayers );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::AKAZE::setNOctaves(int octaves)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_AKAZE_setNOctaves_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_features2d_AKAZE_setNOctaves_10
  (JNIEnv* env, jclass , jlong self, jint octaves)
{
    static const char method_name[] = "features2d::setNOctaves_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::AKAZE>* me = (Ptr<cv::AKAZE>*) self; //TODO: check for NULL
        (*me)->setNOctaves( (int)octaves );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::AKAZE::setThreshold(double threshold)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_AKAZE_setThreshold_10 (JNIEnv*, jclass, jlong, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_features2d_AKAZE_setThreshold_10
  (JNIEnv* env, jclass , jlong self, jdouble threshold)
{
    static const char method_name[] = "features2d::setThreshold_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::AKAZE>* me = (Ptr<cv::AKAZE>*) self; //TODO: check for NULL
        (*me)->setThreshold( (double)threshold );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void Ptr<cv::AKAZE>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_features2d_AKAZE_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_features2d_AKAZE_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::AKAZE>*) self;
}


//
//   cv::SimpleBlobDetector::Params::Params()
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_Params_Params_10 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_Params_Params_10
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "features2d::Params_10()";
    try {
        LOGD("%s", method_name);
        cv::SimpleBlobDetector::Params* _retval_ = new cv::SimpleBlobDetector::Params();
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// float Params::thresholdStep
//

using namespace cv;

JNIEXPORT jfloat JNICALL Java_org_opencv_features2d_Params_get_1thresholdStep_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_features2d_Params_get_1thresholdStep_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::get_1thresholdStep_10()";
    try {
        LOGD("%s", method_name);
        cv::SimpleBlobDetector::Params* me = (cv::SimpleBlobDetector::Params*) self; //TODO: check for NULL
        return me->thresholdStep;//();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// void Params::thresholdStep
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_Params_set_1thresholdStep_10 (JNIEnv*, jclass, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_features2d_Params_set_1thresholdStep_10
  (JNIEnv* env, jclass , jlong self, jfloat thresholdStep)
{
    static const char method_name[] = "features2d::set_1thresholdStep_10()";
    try {
        LOGD("%s", method_name);
        cv::SimpleBlobDetector::Params* me = (cv::SimpleBlobDetector::Params*) self; //TODO: check for NULL
        me->thresholdStep = ( (float)thresholdStep );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
// float Params::minThreshold
//

using namespace cv;

JNIEXPORT jfloat JNICALL Java_org_opencv_features2d_Params_get_1minThreshold_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_features2d_Params_get_1minThreshold_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::get_1minThreshold_10()";
    try {
        LOGD("%s", method_name);
        cv::SimpleBlobDetector::Params* me = (cv::SimpleBlobDetector::Params*) self; //TODO: check for NULL
        return me->minThreshold;//();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// void Params::minThreshold
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_Params_set_1minThreshold_10 (JNIEnv*, jclass, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_features2d_Params_set_1minThreshold_10
  (JNIEnv* env, jclass , jlong self, jfloat minThreshold)
{
    static const char method_name[] = "features2d::set_1minThreshold_10()";
    try {
        LOGD("%s", method_name);
        cv::SimpleBlobDetector::Params* me = (cv::SimpleBlobDetector::Params*) self; //TODO: check for NULL
        me->minThreshold = ( (float)minThreshold );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
// float Params::maxThreshold
//

using namespace cv;

JNIEXPORT jfloat JNICALL Java_org_opencv_features2d_Params_get_1maxThreshold_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_features2d_Params_get_1maxThreshold_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::get_1maxThreshold_10()";
    try {
        LOGD("%s", method_name);
        cv::SimpleBlobDetector::Params* me = (cv::SimpleBlobDetector::Params*) self; //TODO: check for NULL
        return me->maxThreshold;//();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// void Params::maxThreshold
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_Params_set_1maxThreshold_10 (JNIEnv*, jclass, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_features2d_Params_set_1maxThreshold_10
  (JNIEnv* env, jclass , jlong self, jfloat maxThreshold)
{
    static const char method_name[] = "features2d::set_1maxThreshold_10()";
    try {
        LOGD("%s", method_name);
        cv::SimpleBlobDetector::Params* me = (cv::SimpleBlobDetector::Params*) self; //TODO: check for NULL
        me->maxThreshold = ( (float)maxThreshold );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
// size_t Params::minRepeatability
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_Params_get_1minRepeatability_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_Params_get_1minRepeatability_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::get_1minRepeatability_10()";
    try {
        LOGD("%s", method_name);
        cv::SimpleBlobDetector::Params* me = (cv::SimpleBlobDetector::Params*) self; //TODO: check for NULL
        return me->minRepeatability;//();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// void Params::minRepeatability
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_Params_set_1minRepeatability_10 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_features2d_Params_set_1minRepeatability_10
  (JNIEnv* env, jclass , jlong self, jlong minRepeatability)
{
    static const char method_name[] = "features2d::set_1minRepeatability_10()";
    try {
        LOGD("%s", method_name);
        cv::SimpleBlobDetector::Params* me = (cv::SimpleBlobDetector::Params*) self; //TODO: check for NULL
        me->minRepeatability = ( (size_t)minRepeatability );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
// float Params::minDistBetweenBlobs
//

using namespace cv;

JNIEXPORT jfloat JNICALL Java_org_opencv_features2d_Params_get_1minDistBetweenBlobs_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_features2d_Params_get_1minDistBetweenBlobs_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::get_1minDistBetweenBlobs_10()";
    try {
        LOGD("%s", method_name);
        cv::SimpleBlobDetector::Params* me = (cv::SimpleBlobDetector::Params*) self; //TODO: check for NULL
        return me->minDistBetweenBlobs;//();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// void Params::minDistBetweenBlobs
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_Params_set_1minDistBetweenBlobs_10 (JNIEnv*, jclass, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_features2d_Params_set_1minDistBetweenBlobs_10
  (JNIEnv* env, jclass , jlong self, jfloat minDistBetweenBlobs)
{
    static const char method_name[] = "features2d::set_1minDistBetweenBlobs_10()";
    try {
        LOGD("%s", method_name);
        cv::SimpleBlobDetector::Params* me = (cv::SimpleBlobDetector::Params*) self; //TODO: check for NULL
        me->minDistBetweenBlobs = ( (float)minDistBetweenBlobs );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
// bool Params::filterByColor
//

using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_features2d_Params_get_1filterByColor_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_features2d_Params_get_1filterByColor_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::get_1filterByColor_10()";
    try {
        LOGD("%s", method_name);
        cv::SimpleBlobDetector::Params* me = (cv::SimpleBlobDetector::Params*) self; //TODO: check for NULL
        return me->filterByColor;//();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// void Params::filterByColor
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_Params_set_1filterByColor_10 (JNIEnv*, jclass, jlong, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_features2d_Params_set_1filterByColor_10
  (JNIEnv* env, jclass , jlong self, jboolean filterByColor)
{
    static const char method_name[] = "features2d::set_1filterByColor_10()";
    try {
        LOGD("%s", method_name);
        cv::SimpleBlobDetector::Params* me = (cv::SimpleBlobDetector::Params*) self; //TODO: check for NULL
        me->filterByColor = ( (bool)filterByColor );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
// bool Params::filterByArea
//

using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_features2d_Params_get_1filterByArea_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_features2d_Params_get_1filterByArea_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::get_1filterByArea_10()";
    try {
        LOGD("%s", method_name);
        cv::SimpleBlobDetector::Params* me = (cv::SimpleBlobDetector::Params*) self; //TODO: check for NULL
        return me->filterByArea;//();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// void Params::filterByArea
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_Params_set_1filterByArea_10 (JNIEnv*, jclass, jlong, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_features2d_Params_set_1filterByArea_10
  (JNIEnv* env, jclass , jlong self, jboolean filterByArea)
{
    static const char method_name[] = "features2d::set_1filterByArea_10()";
    try {
        LOGD("%s", method_name);
        cv::SimpleBlobDetector::Params* me = (cv::SimpleBlobDetector::Params*) self; //TODO: check for NULL
        me->filterByArea = ( (bool)filterByArea );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
// float Params::minArea
//

using namespace cv;

JNIEXPORT jfloat JNICALL Java_org_opencv_features2d_Params_get_1minArea_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_features2d_Params_get_1minArea_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::get_1minArea_10()";
    try {
        LOGD("%s", method_name);
        cv::SimpleBlobDetector::Params* me = (cv::SimpleBlobDetector::Params*) self; //TODO: check for NULL
        return me->minArea;//();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// void Params::minArea
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_Params_set_1minArea_10 (JNIEnv*, jclass, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_features2d_Params_set_1minArea_10
  (JNIEnv* env, jclass , jlong self, jfloat minArea)
{
    static const char method_name[] = "features2d::set_1minArea_10()";
    try {
        LOGD("%s", method_name);
        cv::SimpleBlobDetector::Params* me = (cv::SimpleBlobDetector::Params*) self; //TODO: check for NULL
        me->minArea = ( (float)minArea );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
// float Params::maxArea
//

using namespace cv;

JNIEXPORT jfloat JNICALL Java_org_opencv_features2d_Params_get_1maxArea_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_features2d_Params_get_1maxArea_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::get_1maxArea_10()";
    try {
        LOGD("%s", method_name);
        cv::SimpleBlobDetector::Params* me = (cv::SimpleBlobDetector::Params*) self; //TODO: check for NULL
        return me->maxArea;//();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// void Params::maxArea
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_Params_set_1maxArea_10 (JNIEnv*, jclass, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_features2d_Params_set_1maxArea_10
  (JNIEnv* env, jclass , jlong self, jfloat maxArea)
{
    static const char method_name[] = "features2d::set_1maxArea_10()";
    try {
        LOGD("%s", method_name);
        cv::SimpleBlobDetector::Params* me = (cv::SimpleBlobDetector::Params*) self; //TODO: check for NULL
        me->maxArea = ( (float)maxArea );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
// bool Params::filterByCircularity
//

using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_features2d_Params_get_1filterByCircularity_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_features2d_Params_get_1filterByCircularity_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::get_1filterByCircularity_10()";
    try {
        LOGD("%s", method_name);
        cv::SimpleBlobDetector::Params* me = (cv::SimpleBlobDetector::Params*) self; //TODO: check for NULL
        return me->filterByCircularity;//();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// void Params::filterByCircularity
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_Params_set_1filterByCircularity_10 (JNIEnv*, jclass, jlong, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_features2d_Params_set_1filterByCircularity_10
  (JNIEnv* env, jclass , jlong self, jboolean filterByCircularity)
{
    static const char method_name[] = "features2d::set_1filterByCircularity_10()";
    try {
        LOGD("%s", method_name);
        cv::SimpleBlobDetector::Params* me = (cv::SimpleBlobDetector::Params*) self; //TODO: check for NULL
        me->filterByCircularity = ( (bool)filterByCircularity );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
// float Params::minCircularity
//

using namespace cv;

JNIEXPORT jfloat JNICALL Java_org_opencv_features2d_Params_get_1minCircularity_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_features2d_Params_get_1minCircularity_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::get_1minCircularity_10()";
    try {
        LOGD("%s", method_name);
        cv::SimpleBlobDetector::Params* me = (cv::SimpleBlobDetector::Params*) self; //TODO: check for NULL
        return me->minCircularity;//();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// void Params::minCircularity
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_Params_set_1minCircularity_10 (JNIEnv*, jclass, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_features2d_Params_set_1minCircularity_10
  (JNIEnv* env, jclass , jlong self, jfloat minCircularity)
{
    static const char method_name[] = "features2d::set_1minCircularity_10()";
    try {
        LOGD("%s", method_name);
        cv::SimpleBlobDetector::Params* me = (cv::SimpleBlobDetector::Params*) self; //TODO: check for NULL
        me->minCircularity = ( (float)minCircularity );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
// float Params::maxCircularity
//

using namespace cv;

JNIEXPORT jfloat JNICALL Java_org_opencv_features2d_Params_get_1maxCircularity_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_features2d_Params_get_1maxCircularity_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::get_1maxCircularity_10()";
    try {
        LOGD("%s", method_name);
        cv::SimpleBlobDetector::Params* me = (cv::SimpleBlobDetector::Params*) self; //TODO: check for NULL
        return me->maxCircularity;//();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// void Params::maxCircularity
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_Params_set_1maxCircularity_10 (JNIEnv*, jclass, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_features2d_Params_set_1maxCircularity_10
  (JNIEnv* env, jclass , jlong self, jfloat maxCircularity)
{
    static const char method_name[] = "features2d::set_1maxCircularity_10()";
    try {
        LOGD("%s", method_name);
        cv::SimpleBlobDetector::Params* me = (cv::SimpleBlobDetector::Params*) self; //TODO: check for NULL
        me->maxCircularity = ( (float)maxCircularity );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
// bool Params::filterByInertia
//

using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_features2d_Params_get_1filterByInertia_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_features2d_Params_get_1filterByInertia_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::get_1filterByInertia_10()";
    try {
        LOGD("%s", method_name);
        cv::SimpleBlobDetector::Params* me = (cv::SimpleBlobDetector::Params*) self; //TODO: check for NULL
        return me->filterByInertia;//();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// void Params::filterByInertia
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_Params_set_1filterByInertia_10 (JNIEnv*, jclass, jlong, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_features2d_Params_set_1filterByInertia_10
  (JNIEnv* env, jclass , jlong self, jboolean filterByInertia)
{
    static const char method_name[] = "features2d::set_1filterByInertia_10()";
    try {
        LOGD("%s", method_name);
        cv::SimpleBlobDetector::Params* me = (cv::SimpleBlobDetector::Params*) self; //TODO: check for NULL
        me->filterByInertia = ( (bool)filterByInertia );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
// float Params::minInertiaRatio
//

using namespace cv;

JNIEXPORT jfloat JNICALL Java_org_opencv_features2d_Params_get_1minInertiaRatio_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_features2d_Params_get_1minInertiaRatio_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::get_1minInertiaRatio_10()";
    try {
        LOGD("%s", method_name);
        cv::SimpleBlobDetector::Params* me = (cv::SimpleBlobDetector::Params*) self; //TODO: check for NULL
        return me->minInertiaRatio;//();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// void Params::minInertiaRatio
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_Params_set_1minInertiaRatio_10 (JNIEnv*, jclass, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_features2d_Params_set_1minInertiaRatio_10
  (JNIEnv* env, jclass , jlong self, jfloat minInertiaRatio)
{
    static const char method_name[] = "features2d::set_1minInertiaRatio_10()";
    try {
        LOGD("%s", method_name);
        cv::SimpleBlobDetector::Params* me = (cv::SimpleBlobDetector::Params*) self; //TODO: check for NULL
        me->minInertiaRatio = ( (float)minInertiaRatio );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
// float Params::maxInertiaRatio
//

using namespace cv;

JNIEXPORT jfloat JNICALL Java_org_opencv_features2d_Params_get_1maxInertiaRatio_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_features2d_Params_get_1maxInertiaRatio_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::get_1maxInertiaRatio_10()";
    try {
        LOGD("%s", method_name);
        cv::SimpleBlobDetector::Params* me = (cv::SimpleBlobDetector::Params*) self; //TODO: check for NULL
        return me->maxInertiaRatio;//();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// void Params::maxInertiaRatio
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_Params_set_1maxInertiaRatio_10 (JNIEnv*, jclass, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_features2d_Params_set_1maxInertiaRatio_10
  (JNIEnv* env, jclass , jlong self, jfloat maxInertiaRatio)
{
    static const char method_name[] = "features2d::set_1maxInertiaRatio_10()";
    try {
        LOGD("%s", method_name);
        cv::SimpleBlobDetector::Params* me = (cv::SimpleBlobDetector::Params*) self; //TODO: check for NULL
        me->maxInertiaRatio = ( (float)maxInertiaRatio );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
// bool Params::filterByConvexity
//

using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_features2d_Params_get_1filterByConvexity_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_features2d_Params_get_1filterByConvexity_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::get_1filterByConvexity_10()";
    try {
        LOGD("%s", method_name);
        cv::SimpleBlobDetector::Params* me = (cv::SimpleBlobDetector::Params*) self; //TODO: check for NULL
        return me->filterByConvexity;//();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// void Params::filterByConvexity
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_Params_set_1filterByConvexity_10 (JNIEnv*, jclass, jlong, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_features2d_Params_set_1filterByConvexity_10
  (JNIEnv* env, jclass , jlong self, jboolean filterByConvexity)
{
    static const char method_name[] = "features2d::set_1filterByConvexity_10()";
    try {
        LOGD("%s", method_name);
        cv::SimpleBlobDetector::Params* me = (cv::SimpleBlobDetector::Params*) self; //TODO: check for NULL
        me->filterByConvexity = ( (bool)filterByConvexity );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
// float Params::minConvexity
//

using namespace cv;

JNIEXPORT jfloat JNICALL Java_org_opencv_features2d_Params_get_1minConvexity_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_features2d_Params_get_1minConvexity_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::get_1minConvexity_10()";
    try {
        LOGD("%s", method_name);
        cv::SimpleBlobDetector::Params* me = (cv::SimpleBlobDetector::Params*) self; //TODO: check for NULL
        return me->minConvexity;//();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// void Params::minConvexity
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_Params_set_1minConvexity_10 (JNIEnv*, jclass, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_features2d_Params_set_1minConvexity_10
  (JNIEnv* env, jclass , jlong self, jfloat minConvexity)
{
    static const char method_name[] = "features2d::set_1minConvexity_10()";
    try {
        LOGD("%s", method_name);
        cv::SimpleBlobDetector::Params* me = (cv::SimpleBlobDetector::Params*) self; //TODO: check for NULL
        me->minConvexity = ( (float)minConvexity );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
// float Params::maxConvexity
//

using namespace cv;

JNIEXPORT jfloat JNICALL Java_org_opencv_features2d_Params_get_1maxConvexity_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_features2d_Params_get_1maxConvexity_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::get_1maxConvexity_10()";
    try {
        LOGD("%s", method_name);
        cv::SimpleBlobDetector::Params* me = (cv::SimpleBlobDetector::Params*) self; //TODO: check for NULL
        return me->maxConvexity;//();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// void Params::maxConvexity
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_Params_set_1maxConvexity_10 (JNIEnv*, jclass, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_features2d_Params_set_1maxConvexity_10
  (JNIEnv* env, jclass , jlong self, jfloat maxConvexity)
{
    static const char method_name[] = "features2d::set_1maxConvexity_10()";
    try {
        LOGD("%s", method_name);
        cv::SimpleBlobDetector::Params* me = (cv::SimpleBlobDetector::Params*) self; //TODO: check for NULL
        me->maxConvexity = ( (float)maxConvexity );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void cv::SimpleBlobDetector::Params::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_features2d_Params_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_features2d_Params_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (cv::SimpleBlobDetector::Params*) self;
}


//
//   cv::BFMatcher::BFMatcher(int normType = NORM_L2, bool crossCheck = false)
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BFMatcher_BFMatcher_10 (JNIEnv*, jclass, jint, jboolean);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BFMatcher_BFMatcher_10
  (JNIEnv* env, jclass , jint normType, jboolean crossCheck)
{
    static const char method_name[] = "features2d::BFMatcher_10()";
    try {
        LOGD("%s", method_name);
        cv::BFMatcher* _retval_ = new cv::BFMatcher( (int)normType, (bool)crossCheck );
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BFMatcher_BFMatcher_11 (JNIEnv*, jclass, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BFMatcher_BFMatcher_11
  (JNIEnv* env, jclass , jint normType)
{
    static const char method_name[] = "features2d::BFMatcher_11()";
    try {
        LOGD("%s", method_name);
        cv::BFMatcher* _retval_ = new cv::BFMatcher( (int)normType );
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BFMatcher_BFMatcher_12 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BFMatcher_BFMatcher_12
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "features2d::BFMatcher_12()";
    try {
        LOGD("%s", method_name);
        cv::BFMatcher* _retval_ = new cv::BFMatcher();
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// static Ptr_BFMatcher cv::BFMatcher::create(int normType = NORM_L2, bool crossCheck = false)
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BFMatcher_create_10 (JNIEnv*, jclass, jint, jboolean);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BFMatcher_create_10
  (JNIEnv* env, jclass , jint normType, jboolean crossCheck)
{
    static const char method_name[] = "features2d::create_10()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::BFMatcher> Ptr_BFMatcher;
        Ptr_BFMatcher _retval_ = cv::BFMatcher::create( (int)normType, (bool)crossCheck );
        return (jlong)(new Ptr_BFMatcher(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BFMatcher_create_11 (JNIEnv*, jclass, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BFMatcher_create_11
  (JNIEnv* env, jclass , jint normType)
{
    static const char method_name[] = "features2d::create_11()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::BFMatcher> Ptr_BFMatcher;
        Ptr_BFMatcher _retval_ = cv::BFMatcher::create( (int)normType );
        return (jlong)(new Ptr_BFMatcher(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BFMatcher_create_12 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BFMatcher_create_12
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "features2d::create_12()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::BFMatcher> Ptr_BFMatcher;
        Ptr_BFMatcher _retval_ = cv::BFMatcher::create();
        return (jlong)(new Ptr_BFMatcher(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  native support for java finalize()
//  static void Ptr<cv::BFMatcher>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_features2d_BFMatcher_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_features2d_BFMatcher_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::BFMatcher>*) self;
}


//
//  Mat cv::BOWTrainer::cluster(Mat descriptors)
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BOWTrainer_cluster_10 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BOWTrainer_cluster_10
  (JNIEnv* env, jclass , jlong self, jlong descriptors_nativeObj)
{
    static const char method_name[] = "features2d::cluster_10()";
    try {
        LOGD("%s", method_name);
        cv::BOWTrainer* me = (cv::BOWTrainer*) self; //TODO: check for NULL
        Mat& descriptors = *((Mat*)descriptors_nativeObj);
        ::Mat _retval_ = me->cluster( descriptors );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Mat cv::BOWTrainer::cluster()
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BOWTrainer_cluster_11 (JNIEnv*, jclass, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BOWTrainer_cluster_11
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::cluster_11()";
    try {
        LOGD("%s", method_name);
        cv::BOWTrainer* me = (cv::BOWTrainer*) self; //TODO: check for NULL
        ::Mat _retval_ = me->cluster();
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::BOWTrainer::descriptorsCount()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_features2d_BOWTrainer_descriptorsCount_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_features2d_BOWTrainer_descriptorsCount_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::descriptorsCount_10()";
    try {
        LOGD("%s", method_name);
        cv::BOWTrainer* me = (cv::BOWTrainer*) self; //TODO: check for NULL
        return me->descriptorsCount();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  vector_Mat cv::BOWTrainer::getDescriptors()
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BOWTrainer_getDescriptors_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BOWTrainer_getDescriptors_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getDescriptors_10()";
    try {
        LOGD("%s", method_name);
        cv::BOWTrainer* me = (cv::BOWTrainer*) self; //TODO: check for NULL
        std::vector<Mat> _ret_val_vector_ = me->getDescriptors();
        Mat* _retval_ = new Mat();
        vector_Mat_to_Mat(_ret_val_vector_, *_retval_);
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::BOWTrainer::add(Mat descriptors)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_BOWTrainer_add_10 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_features2d_BOWTrainer_add_10
  (JNIEnv* env, jclass , jlong self, jlong descriptors_nativeObj)
{
    static const char method_name[] = "features2d::add_10()";
    try {
        LOGD("%s", method_name);
        cv::BOWTrainer* me = (cv::BOWTrainer*) self; //TODO: check for NULL
        Mat& descriptors = *((Mat*)descriptors_nativeObj);
        me->add( descriptors );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::BOWTrainer::clear()
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_BOWTrainer_clear_10 (JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_features2d_BOWTrainer_clear_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::clear_10()";
    try {
        LOGD("%s", method_name);
        cv::BOWTrainer* me = (cv::BOWTrainer*) self; //TODO: check for NULL
        me->clear();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void cv::BOWTrainer::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_features2d_BOWTrainer_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_features2d_BOWTrainer_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (cv::BOWTrainer*) self;
}


//
//  ORB_ScoreType cv::ORB::getScoreType()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_features2d_ORB_getScoreType_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_features2d_ORB_getScoreType_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getScoreType_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::ORB>* me = (Ptr<cv::ORB>*) self; //TODO: check for NULL
        return (*me)->getScoreType();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// static Ptr_ORB cv::ORB::create(int nfeatures = 500, float scaleFactor = 1.2f, int nlevels = 8, int edgeThreshold = 31, int firstLevel = 0, int WTA_K = 2, ORB_ScoreType scoreType = ORB::HARRIS_SCORE, int patchSize = 31, int fastThreshold = 20)
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_ORB_create_10 (JNIEnv*, jclass, jint, jfloat, jint, jint, jint, jint, jint, jint, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_ORB_create_10
  (JNIEnv* env, jclass , jint nfeatures, jfloat scaleFactor, jint nlevels, jint edgeThreshold, jint firstLevel, jint WTA_K, jint scoreType, jint patchSize, jint fastThreshold)
{
    static const char method_name[] = "features2d::create_10()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::ORB> Ptr_ORB;
        Ptr_ORB _retval_ = cv::ORB::create( (int)nfeatures, (float)scaleFactor, (int)nlevels, (int)edgeThreshold, (int)firstLevel, (int)WTA_K, (cv::ORB::ScoreType)scoreType, (int)patchSize, (int)fastThreshold );
        return (jlong)(new Ptr_ORB(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_ORB_create_11 (JNIEnv*, jclass, jint, jfloat, jint, jint, jint, jint, jint, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_ORB_create_11
  (JNIEnv* env, jclass , jint nfeatures, jfloat scaleFactor, jint nlevels, jint edgeThreshold, jint firstLevel, jint WTA_K, jint scoreType, jint patchSize)
{
    static const char method_name[] = "features2d::create_11()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::ORB> Ptr_ORB;
        Ptr_ORB _retval_ = cv::ORB::create( (int)nfeatures, (float)scaleFactor, (int)nlevels, (int)edgeThreshold, (int)firstLevel, (int)WTA_K, (cv::ORB::ScoreType)scoreType, (int)patchSize );
        return (jlong)(new Ptr_ORB(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_ORB_create_12 (JNIEnv*, jclass, jint, jfloat, jint, jint, jint, jint, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_ORB_create_12
  (JNIEnv* env, jclass , jint nfeatures, jfloat scaleFactor, jint nlevels, jint edgeThreshold, jint firstLevel, jint WTA_K, jint scoreType)
{
    static const char method_name[] = "features2d::create_12()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::ORB> Ptr_ORB;
        Ptr_ORB _retval_ = cv::ORB::create( (int)nfeatures, (float)scaleFactor, (int)nlevels, (int)edgeThreshold, (int)firstLevel, (int)WTA_K, (cv::ORB::ScoreType)scoreType );
        return (jlong)(new Ptr_ORB(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_ORB_create_13 (JNIEnv*, jclass, jint, jfloat, jint, jint, jint, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_ORB_create_13
  (JNIEnv* env, jclass , jint nfeatures, jfloat scaleFactor, jint nlevels, jint edgeThreshold, jint firstLevel, jint WTA_K)
{
    static const char method_name[] = "features2d::create_13()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::ORB> Ptr_ORB;
        Ptr_ORB _retval_ = cv::ORB::create( (int)nfeatures, (float)scaleFactor, (int)nlevels, (int)edgeThreshold, (int)firstLevel, (int)WTA_K );
        return (jlong)(new Ptr_ORB(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_ORB_create_14 (JNIEnv*, jclass, jint, jfloat, jint, jint, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_ORB_create_14
  (JNIEnv* env, jclass , jint nfeatures, jfloat scaleFactor, jint nlevels, jint edgeThreshold, jint firstLevel)
{
    static const char method_name[] = "features2d::create_14()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::ORB> Ptr_ORB;
        Ptr_ORB _retval_ = cv::ORB::create( (int)nfeatures, (float)scaleFactor, (int)nlevels, (int)edgeThreshold, (int)firstLevel );
        return (jlong)(new Ptr_ORB(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_ORB_create_15 (JNIEnv*, jclass, jint, jfloat, jint, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_ORB_create_15
  (JNIEnv* env, jclass , jint nfeatures, jfloat scaleFactor, jint nlevels, jint edgeThreshold)
{
    static const char method_name[] = "features2d::create_15()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::ORB> Ptr_ORB;
        Ptr_ORB _retval_ = cv::ORB::create( (int)nfeatures, (float)scaleFactor, (int)nlevels, (int)edgeThreshold );
        return (jlong)(new Ptr_ORB(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_ORB_create_16 (JNIEnv*, jclass, jint, jfloat, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_ORB_create_16
  (JNIEnv* env, jclass , jint nfeatures, jfloat scaleFactor, jint nlevels)
{
    static const char method_name[] = "features2d::create_16()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::ORB> Ptr_ORB;
        Ptr_ORB _retval_ = cv::ORB::create( (int)nfeatures, (float)scaleFactor, (int)nlevels );
        return (jlong)(new Ptr_ORB(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_ORB_create_17 (JNIEnv*, jclass, jint, jfloat);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_ORB_create_17
  (JNIEnv* env, jclass , jint nfeatures, jfloat scaleFactor)
{
    static const char method_name[] = "features2d::create_17()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::ORB> Ptr_ORB;
        Ptr_ORB _retval_ = cv::ORB::create( (int)nfeatures, (float)scaleFactor );
        return (jlong)(new Ptr_ORB(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_ORB_create_18 (JNIEnv*, jclass, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_ORB_create_18
  (JNIEnv* env, jclass , jint nfeatures)
{
    static const char method_name[] = "features2d::create_18()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::ORB> Ptr_ORB;
        Ptr_ORB _retval_ = cv::ORB::create( (int)nfeatures );
        return (jlong)(new Ptr_ORB(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_ORB_create_19 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_ORB_create_19
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "features2d::create_19()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::ORB> Ptr_ORB;
        Ptr_ORB _retval_ = cv::ORB::create();
        return (jlong)(new Ptr_ORB(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  String cv::ORB::getDefaultName()
//

using namespace cv;

JNIEXPORT jstring JNICALL Java_org_opencv_features2d_ORB_getDefaultName_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jstring JNICALL Java_org_opencv_features2d_ORB_getDefaultName_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getDefaultName_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::ORB>* me = (Ptr<cv::ORB>*) self; //TODO: check for NULL
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
//  double cv::ORB::getScaleFactor()
//

using namespace cv;

JNIEXPORT jdouble JNICALL Java_org_opencv_features2d_ORB_getScaleFactor_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_features2d_ORB_getScaleFactor_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getScaleFactor_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::ORB>* me = (Ptr<cv::ORB>*) self; //TODO: check for NULL
        return (*me)->getScaleFactor();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::ORB::getEdgeThreshold()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_features2d_ORB_getEdgeThreshold_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_features2d_ORB_getEdgeThreshold_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getEdgeThreshold_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::ORB>* me = (Ptr<cv::ORB>*) self; //TODO: check for NULL
        return (*me)->getEdgeThreshold();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::ORB::getFastThreshold()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_features2d_ORB_getFastThreshold_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_features2d_ORB_getFastThreshold_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getFastThreshold_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::ORB>* me = (Ptr<cv::ORB>*) self; //TODO: check for NULL
        return (*me)->getFastThreshold();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::ORB::getFirstLevel()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_features2d_ORB_getFirstLevel_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_features2d_ORB_getFirstLevel_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getFirstLevel_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::ORB>* me = (Ptr<cv::ORB>*) self; //TODO: check for NULL
        return (*me)->getFirstLevel();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::ORB::getMaxFeatures()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_features2d_ORB_getMaxFeatures_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_features2d_ORB_getMaxFeatures_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getMaxFeatures_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::ORB>* me = (Ptr<cv::ORB>*) self; //TODO: check for NULL
        return (*me)->getMaxFeatures();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::ORB::getNLevels()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_features2d_ORB_getNLevels_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_features2d_ORB_getNLevels_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getNLevels_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::ORB>* me = (Ptr<cv::ORB>*) self; //TODO: check for NULL
        return (*me)->getNLevels();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::ORB::getPatchSize()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_features2d_ORB_getPatchSize_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_features2d_ORB_getPatchSize_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getPatchSize_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::ORB>* me = (Ptr<cv::ORB>*) self; //TODO: check for NULL
        return (*me)->getPatchSize();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::ORB::getWTA_K()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_features2d_ORB_getWTA_1K_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_features2d_ORB_getWTA_1K_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getWTA_1K_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::ORB>* me = (Ptr<cv::ORB>*) self; //TODO: check for NULL
        return (*me)->getWTA_K();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::ORB::setEdgeThreshold(int edgeThreshold)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_ORB_setEdgeThreshold_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_features2d_ORB_setEdgeThreshold_10
  (JNIEnv* env, jclass , jlong self, jint edgeThreshold)
{
    static const char method_name[] = "features2d::setEdgeThreshold_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::ORB>* me = (Ptr<cv::ORB>*) self; //TODO: check for NULL
        (*me)->setEdgeThreshold( (int)edgeThreshold );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::ORB::setFastThreshold(int fastThreshold)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_ORB_setFastThreshold_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_features2d_ORB_setFastThreshold_10
  (JNIEnv* env, jclass , jlong self, jint fastThreshold)
{
    static const char method_name[] = "features2d::setFastThreshold_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::ORB>* me = (Ptr<cv::ORB>*) self; //TODO: check for NULL
        (*me)->setFastThreshold( (int)fastThreshold );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::ORB::setFirstLevel(int firstLevel)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_ORB_setFirstLevel_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_features2d_ORB_setFirstLevel_10
  (JNIEnv* env, jclass , jlong self, jint firstLevel)
{
    static const char method_name[] = "features2d::setFirstLevel_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::ORB>* me = (Ptr<cv::ORB>*) self; //TODO: check for NULL
        (*me)->setFirstLevel( (int)firstLevel );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::ORB::setMaxFeatures(int maxFeatures)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_ORB_setMaxFeatures_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_features2d_ORB_setMaxFeatures_10
  (JNIEnv* env, jclass , jlong self, jint maxFeatures)
{
    static const char method_name[] = "features2d::setMaxFeatures_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::ORB>* me = (Ptr<cv::ORB>*) self; //TODO: check for NULL
        (*me)->setMaxFeatures( (int)maxFeatures );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::ORB::setNLevels(int nlevels)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_ORB_setNLevels_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_features2d_ORB_setNLevels_10
  (JNIEnv* env, jclass , jlong self, jint nlevels)
{
    static const char method_name[] = "features2d::setNLevels_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::ORB>* me = (Ptr<cv::ORB>*) self; //TODO: check for NULL
        (*me)->setNLevels( (int)nlevels );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::ORB::setPatchSize(int patchSize)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_ORB_setPatchSize_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_features2d_ORB_setPatchSize_10
  (JNIEnv* env, jclass , jlong self, jint patchSize)
{
    static const char method_name[] = "features2d::setPatchSize_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::ORB>* me = (Ptr<cv::ORB>*) self; //TODO: check for NULL
        (*me)->setPatchSize( (int)patchSize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::ORB::setScaleFactor(double scaleFactor)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_ORB_setScaleFactor_10 (JNIEnv*, jclass, jlong, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_features2d_ORB_setScaleFactor_10
  (JNIEnv* env, jclass , jlong self, jdouble scaleFactor)
{
    static const char method_name[] = "features2d::setScaleFactor_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::ORB>* me = (Ptr<cv::ORB>*) self; //TODO: check for NULL
        (*me)->setScaleFactor( (double)scaleFactor );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::ORB::setScoreType(ORB_ScoreType scoreType)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_ORB_setScoreType_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_features2d_ORB_setScoreType_10
  (JNIEnv* env, jclass , jlong self, jint scoreType)
{
    static const char method_name[] = "features2d::setScoreType_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::ORB>* me = (Ptr<cv::ORB>*) self; //TODO: check for NULL
        (*me)->setScoreType( (cv::ORB::ScoreType)scoreType );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::ORB::setWTA_K(int wta_k)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_ORB_setWTA_1K_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_features2d_ORB_setWTA_1K_10
  (JNIEnv* env, jclass , jlong self, jint wta_k)
{
    static const char method_name[] = "features2d::setWTA_1K_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::ORB>* me = (Ptr<cv::ORB>*) self; //TODO: check for NULL
        (*me)->setWTA_K( (int)wta_k );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void Ptr<cv::ORB>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_features2d_ORB_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_features2d_ORB_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::ORB>*) self;
}


//
// static Ptr_MSER cv::MSER::create(int _delta = 5, int _min_area = 60, int _max_area = 14400, double _max_variation = 0.25, double _min_diversity = .2, int _max_evolution = 200, double _area_threshold = 1.01, double _min_margin = 0.003, int _edge_blur_size = 5)
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_MSER_create_10 (JNIEnv*, jclass, jint, jint, jint, jdouble, jdouble, jint, jdouble, jdouble, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_MSER_create_10
  (JNIEnv* env, jclass , jint _delta, jint _min_area, jint _max_area, jdouble _max_variation, jdouble _min_diversity, jint _max_evolution, jdouble _area_threshold, jdouble _min_margin, jint _edge_blur_size)
{
    static const char method_name[] = "features2d::create_10()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::MSER> Ptr_MSER;
        Ptr_MSER _retval_ = cv::MSER::create( (int)_delta, (int)_min_area, (int)_max_area, (double)_max_variation, (double)_min_diversity, (int)_max_evolution, (double)_area_threshold, (double)_min_margin, (int)_edge_blur_size );
        return (jlong)(new Ptr_MSER(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_MSER_create_11 (JNIEnv*, jclass, jint, jint, jint, jdouble, jdouble, jint, jdouble, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_MSER_create_11
  (JNIEnv* env, jclass , jint _delta, jint _min_area, jint _max_area, jdouble _max_variation, jdouble _min_diversity, jint _max_evolution, jdouble _area_threshold, jdouble _min_margin)
{
    static const char method_name[] = "features2d::create_11()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::MSER> Ptr_MSER;
        Ptr_MSER _retval_ = cv::MSER::create( (int)_delta, (int)_min_area, (int)_max_area, (double)_max_variation, (double)_min_diversity, (int)_max_evolution, (double)_area_threshold, (double)_min_margin );
        return (jlong)(new Ptr_MSER(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_MSER_create_12 (JNIEnv*, jclass, jint, jint, jint, jdouble, jdouble, jint, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_MSER_create_12
  (JNIEnv* env, jclass , jint _delta, jint _min_area, jint _max_area, jdouble _max_variation, jdouble _min_diversity, jint _max_evolution, jdouble _area_threshold)
{
    static const char method_name[] = "features2d::create_12()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::MSER> Ptr_MSER;
        Ptr_MSER _retval_ = cv::MSER::create( (int)_delta, (int)_min_area, (int)_max_area, (double)_max_variation, (double)_min_diversity, (int)_max_evolution, (double)_area_threshold );
        return (jlong)(new Ptr_MSER(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_MSER_create_13 (JNIEnv*, jclass, jint, jint, jint, jdouble, jdouble, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_MSER_create_13
  (JNIEnv* env, jclass , jint _delta, jint _min_area, jint _max_area, jdouble _max_variation, jdouble _min_diversity, jint _max_evolution)
{
    static const char method_name[] = "features2d::create_13()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::MSER> Ptr_MSER;
        Ptr_MSER _retval_ = cv::MSER::create( (int)_delta, (int)_min_area, (int)_max_area, (double)_max_variation, (double)_min_diversity, (int)_max_evolution );
        return (jlong)(new Ptr_MSER(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_MSER_create_14 (JNIEnv*, jclass, jint, jint, jint, jdouble, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_MSER_create_14
  (JNIEnv* env, jclass , jint _delta, jint _min_area, jint _max_area, jdouble _max_variation, jdouble _min_diversity)
{
    static const char method_name[] = "features2d::create_14()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::MSER> Ptr_MSER;
        Ptr_MSER _retval_ = cv::MSER::create( (int)_delta, (int)_min_area, (int)_max_area, (double)_max_variation, (double)_min_diversity );
        return (jlong)(new Ptr_MSER(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_MSER_create_15 (JNIEnv*, jclass, jint, jint, jint, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_MSER_create_15
  (JNIEnv* env, jclass , jint _delta, jint _min_area, jint _max_area, jdouble _max_variation)
{
    static const char method_name[] = "features2d::create_15()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::MSER> Ptr_MSER;
        Ptr_MSER _retval_ = cv::MSER::create( (int)_delta, (int)_min_area, (int)_max_area, (double)_max_variation );
        return (jlong)(new Ptr_MSER(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_MSER_create_16 (JNIEnv*, jclass, jint, jint, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_MSER_create_16
  (JNIEnv* env, jclass , jint _delta, jint _min_area, jint _max_area)
{
    static const char method_name[] = "features2d::create_16()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::MSER> Ptr_MSER;
        Ptr_MSER _retval_ = cv::MSER::create( (int)_delta, (int)_min_area, (int)_max_area );
        return (jlong)(new Ptr_MSER(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_MSER_create_17 (JNIEnv*, jclass, jint, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_MSER_create_17
  (JNIEnv* env, jclass , jint _delta, jint _min_area)
{
    static const char method_name[] = "features2d::create_17()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::MSER> Ptr_MSER;
        Ptr_MSER _retval_ = cv::MSER::create( (int)_delta, (int)_min_area );
        return (jlong)(new Ptr_MSER(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_MSER_create_18 (JNIEnv*, jclass, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_MSER_create_18
  (JNIEnv* env, jclass , jint _delta)
{
    static const char method_name[] = "features2d::create_18()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::MSER> Ptr_MSER;
        Ptr_MSER _retval_ = cv::MSER::create( (int)_delta );
        return (jlong)(new Ptr_MSER(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_MSER_create_19 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_MSER_create_19
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "features2d::create_19()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::MSER> Ptr_MSER;
        Ptr_MSER _retval_ = cv::MSER::create();
        return (jlong)(new Ptr_MSER(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  String cv::MSER::getDefaultName()
//

using namespace cv;

JNIEXPORT jstring JNICALL Java_org_opencv_features2d_MSER_getDefaultName_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jstring JNICALL Java_org_opencv_features2d_MSER_getDefaultName_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getDefaultName_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::MSER>* me = (Ptr<cv::MSER>*) self; //TODO: check for NULL
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
//  bool cv::MSER::getPass2Only()
//

using namespace cv;

JNIEXPORT jboolean JNICALL Java_org_opencv_features2d_MSER_getPass2Only_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_features2d_MSER_getPass2Only_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getPass2Only_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::MSER>* me = (Ptr<cv::MSER>*) self; //TODO: check for NULL
        return (*me)->getPass2Only();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::MSER::getDelta()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_features2d_MSER_getDelta_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_features2d_MSER_getDelta_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getDelta_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::MSER>* me = (Ptr<cv::MSER>*) self; //TODO: check for NULL
        return (*me)->getDelta();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::MSER::getMaxArea()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_features2d_MSER_getMaxArea_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_features2d_MSER_getMaxArea_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getMaxArea_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::MSER>* me = (Ptr<cv::MSER>*) self; //TODO: check for NULL
        return (*me)->getMaxArea();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::MSER::getMinArea()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_features2d_MSER_getMinArea_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_features2d_MSER_getMinArea_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::getMinArea_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::MSER>* me = (Ptr<cv::MSER>*) self; //TODO: check for NULL
        return (*me)->getMinArea();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::MSER::detectRegions(Mat image, vector_vector_Point& msers, vector_Rect& bboxes)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_MSER_detectRegions_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_features2d_MSER_detectRegions_10
  (JNIEnv* env, jclass , jlong self, jlong image_nativeObj, jlong msers_mat_nativeObj, jlong bboxes_mat_nativeObj)
{
    static const char method_name[] = "features2d::detectRegions_10()";
    try {
        LOGD("%s", method_name);
        std::vector< std::vector<Point> > msers;
        Mat& msers_mat = *((Mat*)msers_mat_nativeObj);
        std::vector<Rect> bboxes;
        Mat& bboxes_mat = *((Mat*)bboxes_mat_nativeObj);
        Ptr<cv::MSER>* me = (Ptr<cv::MSER>*) self; //TODO: check for NULL
        Mat& image = *((Mat*)image_nativeObj);
        (*me)->detectRegions( image, msers, bboxes );
        vector_vector_Point_to_Mat( msers, msers_mat );
        vector_Rect_to_Mat( bboxes, bboxes_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::MSER::setDelta(int delta)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_MSER_setDelta_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_features2d_MSER_setDelta_10
  (JNIEnv* env, jclass , jlong self, jint delta)
{
    static const char method_name[] = "features2d::setDelta_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::MSER>* me = (Ptr<cv::MSER>*) self; //TODO: check for NULL
        (*me)->setDelta( (int)delta );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::MSER::setMaxArea(int maxArea)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_MSER_setMaxArea_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_features2d_MSER_setMaxArea_10
  (JNIEnv* env, jclass , jlong self, jint maxArea)
{
    static const char method_name[] = "features2d::setMaxArea_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::MSER>* me = (Ptr<cv::MSER>*) self; //TODO: check for NULL
        (*me)->setMaxArea( (int)maxArea );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::MSER::setMinArea(int minArea)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_MSER_setMinArea_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_features2d_MSER_setMinArea_10
  (JNIEnv* env, jclass , jlong self, jint minArea)
{
    static const char method_name[] = "features2d::setMinArea_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::MSER>* me = (Ptr<cv::MSER>*) self; //TODO: check for NULL
        (*me)->setMinArea( (int)minArea );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::MSER::setPass2Only(bool f)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_features2d_MSER_setPass2Only_10 (JNIEnv*, jclass, jlong, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_features2d_MSER_setPass2Only_10
  (JNIEnv* env, jclass , jlong self, jboolean f)
{
    static const char method_name[] = "features2d::setPass2Only_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::MSER>* me = (Ptr<cv::MSER>*) self; //TODO: check for NULL
        (*me)->setPass2Only( (bool)f );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void Ptr<cv::MSER>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_features2d_MSER_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_features2d_MSER_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::MSER>*) self;
}


//
//   cv::BOWKMeansTrainer::BOWKMeansTrainer(int clusterCount, TermCriteria termcrit = TermCriteria(), int attempts = 3, int flags = KMEANS_PP_CENTERS)
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BOWKMeansTrainer_BOWKMeansTrainer_10 (JNIEnv*, jclass, jint, jint, jint, jdouble, jint, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BOWKMeansTrainer_BOWKMeansTrainer_10
  (JNIEnv* env, jclass , jint clusterCount, jint termcrit_type, jint termcrit_maxCount, jdouble termcrit_epsilon, jint attempts, jint flags)
{
    static const char method_name[] = "features2d::BOWKMeansTrainer_10()";
    try {
        LOGD("%s", method_name);
        TermCriteria termcrit(termcrit_type, termcrit_maxCount, termcrit_epsilon);
        cv::BOWKMeansTrainer* _retval_ = new cv::BOWKMeansTrainer( (int)clusterCount, termcrit, (int)attempts, (int)flags );
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BOWKMeansTrainer_BOWKMeansTrainer_11 (JNIEnv*, jclass, jint, jint, jint, jdouble, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BOWKMeansTrainer_BOWKMeansTrainer_11
  (JNIEnv* env, jclass , jint clusterCount, jint termcrit_type, jint termcrit_maxCount, jdouble termcrit_epsilon, jint attempts)
{
    static const char method_name[] = "features2d::BOWKMeansTrainer_11()";
    try {
        LOGD("%s", method_name);
        TermCriteria termcrit(termcrit_type, termcrit_maxCount, termcrit_epsilon);
        cv::BOWKMeansTrainer* _retval_ = new cv::BOWKMeansTrainer( (int)clusterCount, termcrit, (int)attempts );
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BOWKMeansTrainer_BOWKMeansTrainer_12 (JNIEnv*, jclass, jint, jint, jint, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BOWKMeansTrainer_BOWKMeansTrainer_12
  (JNIEnv* env, jclass , jint clusterCount, jint termcrit_type, jint termcrit_maxCount, jdouble termcrit_epsilon)
{
    static const char method_name[] = "features2d::BOWKMeansTrainer_12()";
    try {
        LOGD("%s", method_name);
        TermCriteria termcrit(termcrit_type, termcrit_maxCount, termcrit_epsilon);
        cv::BOWKMeansTrainer* _retval_ = new cv::BOWKMeansTrainer( (int)clusterCount, termcrit );
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BOWKMeansTrainer_BOWKMeansTrainer_13 (JNIEnv*, jclass, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BOWKMeansTrainer_BOWKMeansTrainer_13
  (JNIEnv* env, jclass , jint clusterCount)
{
    static const char method_name[] = "features2d::BOWKMeansTrainer_13()";
    try {
        LOGD("%s", method_name);
        cv::BOWKMeansTrainer* _retval_ = new cv::BOWKMeansTrainer( (int)clusterCount );
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Mat cv::BOWKMeansTrainer::cluster(Mat descriptors)
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BOWKMeansTrainer_cluster_10 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BOWKMeansTrainer_cluster_10
  (JNIEnv* env, jclass , jlong self, jlong descriptors_nativeObj)
{
    static const char method_name[] = "features2d::cluster_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::BOWKMeansTrainer>* me = (Ptr<cv::BOWKMeansTrainer>*) self; //TODO: check for NULL
        Mat& descriptors = *((Mat*)descriptors_nativeObj);
        ::Mat _retval_ = (*me)->cluster( descriptors );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Mat cv::BOWKMeansTrainer::cluster()
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BOWKMeansTrainer_cluster_11 (JNIEnv*, jclass, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_BOWKMeansTrainer_cluster_11
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "features2d::cluster_11()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::BOWKMeansTrainer>* me = (Ptr<cv::BOWKMeansTrainer>*) self; //TODO: check for NULL
        ::Mat _retval_ = (*me)->cluster();
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  native support for java finalize()
//  static void Ptr<cv::BOWKMeansTrainer>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_features2d_BOWKMeansTrainer_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_features2d_BOWKMeansTrainer_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::BOWKMeansTrainer>*) self;
}


//
//   cv::FlannBasedMatcher::FlannBasedMatcher(Ptr_flann_IndexParams indexParams = makePtr<flann::KDTreeIndexParams>(), Ptr_flann_SearchParams searchParams = makePtr<flann::SearchParams>())
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_FlannBasedMatcher_FlannBasedMatcher_10 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_FlannBasedMatcher_FlannBasedMatcher_10
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "features2d::FlannBasedMatcher_10()";
    try {
        LOGD("%s", method_name);
        cv::FlannBasedMatcher* _retval_ = new cv::FlannBasedMatcher( makePtr<flann::KDTreeIndexParams>(), makePtr<flann::SearchParams>() );
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// static Ptr_FlannBasedMatcher cv::FlannBasedMatcher::create()
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_FlannBasedMatcher_create_10 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_features2d_FlannBasedMatcher_create_10
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "features2d::create_10()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::FlannBasedMatcher> Ptr_FlannBasedMatcher;
        Ptr_FlannBasedMatcher _retval_ = cv::FlannBasedMatcher::create();
        return (jlong)(new Ptr_FlannBasedMatcher(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  native support for java finalize()
//  static void Ptr<cv::FlannBasedMatcher>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_features2d_FlannBasedMatcher_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_features2d_FlannBasedMatcher_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::FlannBasedMatcher>*) self;
}



} // extern "C"

#endif // HAVE_OPENCV_FEATURES2D
