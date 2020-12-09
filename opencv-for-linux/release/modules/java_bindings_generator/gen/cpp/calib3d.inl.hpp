//
// This file is auto-generated. Please don't modify it!
//

#undef LOG_TAG

#include "opencv2/opencv_modules.hpp"
#ifdef HAVE_OPENCV_CALIB3D

#include <string>

#include "opencv2/calib3d.hpp"

#include "/Users/virtualman/Downloads/MySource/opencv-4.3.0/modules/calib3d/include/opencv2/calib3d/calib3d_c.h"
#include "/Users/virtualman/Downloads/MySource/opencv-4.3.0/modules/calib3d/include/opencv2/calib3d.hpp"

#define LOG_TAG "org.opencv.calib3d"
#include "common.h"

using namespace cv;

/// throw java exception
#undef throwJavaException
#define throwJavaException throwJavaException_calib3d
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
// static Ptr_StereoSGBM cv::StereoSGBM::create(int minDisparity = 0, int numDisparities = 16, int blockSize = 3, int P1 = 0, int P2 = 0, int disp12MaxDiff = 0, int preFilterCap = 0, int uniquenessRatio = 0, int speckleWindowSize = 0, int speckleRange = 0, int mode = StereoSGBM::MODE_SGBM)
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_StereoSGBM_create_10 (JNIEnv*, jclass, jint, jint, jint, jint, jint, jint, jint, jint, jint, jint, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_StereoSGBM_create_10
  (JNIEnv* env, jclass , jint minDisparity, jint numDisparities, jint blockSize, jint P1, jint P2, jint disp12MaxDiff, jint preFilterCap, jint uniquenessRatio, jint speckleWindowSize, jint speckleRange, jint mode)
{
    static const char method_name[] = "calib3d::create_10()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::StereoSGBM> Ptr_StereoSGBM;
        Ptr_StereoSGBM _retval_ = cv::StereoSGBM::create( (int)minDisparity, (int)numDisparities, (int)blockSize, (int)P1, (int)P2, (int)disp12MaxDiff, (int)preFilterCap, (int)uniquenessRatio, (int)speckleWindowSize, (int)speckleRange, (int)mode );
        return (jlong)(new Ptr_StereoSGBM(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_StereoSGBM_create_11 (JNIEnv*, jclass, jint, jint, jint, jint, jint, jint, jint, jint, jint, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_StereoSGBM_create_11
  (JNIEnv* env, jclass , jint minDisparity, jint numDisparities, jint blockSize, jint P1, jint P2, jint disp12MaxDiff, jint preFilterCap, jint uniquenessRatio, jint speckleWindowSize, jint speckleRange)
{
    static const char method_name[] = "calib3d::create_11()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::StereoSGBM> Ptr_StereoSGBM;
        Ptr_StereoSGBM _retval_ = cv::StereoSGBM::create( (int)minDisparity, (int)numDisparities, (int)blockSize, (int)P1, (int)P2, (int)disp12MaxDiff, (int)preFilterCap, (int)uniquenessRatio, (int)speckleWindowSize, (int)speckleRange );
        return (jlong)(new Ptr_StereoSGBM(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_StereoSGBM_create_12 (JNIEnv*, jclass, jint, jint, jint, jint, jint, jint, jint, jint, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_StereoSGBM_create_12
  (JNIEnv* env, jclass , jint minDisparity, jint numDisparities, jint blockSize, jint P1, jint P2, jint disp12MaxDiff, jint preFilterCap, jint uniquenessRatio, jint speckleWindowSize)
{
    static const char method_name[] = "calib3d::create_12()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::StereoSGBM> Ptr_StereoSGBM;
        Ptr_StereoSGBM _retval_ = cv::StereoSGBM::create( (int)minDisparity, (int)numDisparities, (int)blockSize, (int)P1, (int)P2, (int)disp12MaxDiff, (int)preFilterCap, (int)uniquenessRatio, (int)speckleWindowSize );
        return (jlong)(new Ptr_StereoSGBM(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_StereoSGBM_create_13 (JNIEnv*, jclass, jint, jint, jint, jint, jint, jint, jint, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_StereoSGBM_create_13
  (JNIEnv* env, jclass , jint minDisparity, jint numDisparities, jint blockSize, jint P1, jint P2, jint disp12MaxDiff, jint preFilterCap, jint uniquenessRatio)
{
    static const char method_name[] = "calib3d::create_13()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::StereoSGBM> Ptr_StereoSGBM;
        Ptr_StereoSGBM _retval_ = cv::StereoSGBM::create( (int)minDisparity, (int)numDisparities, (int)blockSize, (int)P1, (int)P2, (int)disp12MaxDiff, (int)preFilterCap, (int)uniquenessRatio );
        return (jlong)(new Ptr_StereoSGBM(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_StereoSGBM_create_14 (JNIEnv*, jclass, jint, jint, jint, jint, jint, jint, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_StereoSGBM_create_14
  (JNIEnv* env, jclass , jint minDisparity, jint numDisparities, jint blockSize, jint P1, jint P2, jint disp12MaxDiff, jint preFilterCap)
{
    static const char method_name[] = "calib3d::create_14()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::StereoSGBM> Ptr_StereoSGBM;
        Ptr_StereoSGBM _retval_ = cv::StereoSGBM::create( (int)minDisparity, (int)numDisparities, (int)blockSize, (int)P1, (int)P2, (int)disp12MaxDiff, (int)preFilterCap );
        return (jlong)(new Ptr_StereoSGBM(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_StereoSGBM_create_15 (JNIEnv*, jclass, jint, jint, jint, jint, jint, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_StereoSGBM_create_15
  (JNIEnv* env, jclass , jint minDisparity, jint numDisparities, jint blockSize, jint P1, jint P2, jint disp12MaxDiff)
{
    static const char method_name[] = "calib3d::create_15()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::StereoSGBM> Ptr_StereoSGBM;
        Ptr_StereoSGBM _retval_ = cv::StereoSGBM::create( (int)minDisparity, (int)numDisparities, (int)blockSize, (int)P1, (int)P2, (int)disp12MaxDiff );
        return (jlong)(new Ptr_StereoSGBM(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_StereoSGBM_create_16 (JNIEnv*, jclass, jint, jint, jint, jint, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_StereoSGBM_create_16
  (JNIEnv* env, jclass , jint minDisparity, jint numDisparities, jint blockSize, jint P1, jint P2)
{
    static const char method_name[] = "calib3d::create_16()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::StereoSGBM> Ptr_StereoSGBM;
        Ptr_StereoSGBM _retval_ = cv::StereoSGBM::create( (int)minDisparity, (int)numDisparities, (int)blockSize, (int)P1, (int)P2 );
        return (jlong)(new Ptr_StereoSGBM(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_StereoSGBM_create_17 (JNIEnv*, jclass, jint, jint, jint, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_StereoSGBM_create_17
  (JNIEnv* env, jclass , jint minDisparity, jint numDisparities, jint blockSize, jint P1)
{
    static const char method_name[] = "calib3d::create_17()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::StereoSGBM> Ptr_StereoSGBM;
        Ptr_StereoSGBM _retval_ = cv::StereoSGBM::create( (int)minDisparity, (int)numDisparities, (int)blockSize, (int)P1 );
        return (jlong)(new Ptr_StereoSGBM(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_StereoSGBM_create_18 (JNIEnv*, jclass, jint, jint, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_StereoSGBM_create_18
  (JNIEnv* env, jclass , jint minDisparity, jint numDisparities, jint blockSize)
{
    static const char method_name[] = "calib3d::create_18()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::StereoSGBM> Ptr_StereoSGBM;
        Ptr_StereoSGBM _retval_ = cv::StereoSGBM::create( (int)minDisparity, (int)numDisparities, (int)blockSize );
        return (jlong)(new Ptr_StereoSGBM(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_StereoSGBM_create_19 (JNIEnv*, jclass, jint, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_StereoSGBM_create_19
  (JNIEnv* env, jclass , jint minDisparity, jint numDisparities)
{
    static const char method_name[] = "calib3d::create_19()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::StereoSGBM> Ptr_StereoSGBM;
        Ptr_StereoSGBM _retval_ = cv::StereoSGBM::create( (int)minDisparity, (int)numDisparities );
        return (jlong)(new Ptr_StereoSGBM(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_StereoSGBM_create_110 (JNIEnv*, jclass, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_StereoSGBM_create_110
  (JNIEnv* env, jclass , jint minDisparity)
{
    static const char method_name[] = "calib3d::create_110()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::StereoSGBM> Ptr_StereoSGBM;
        Ptr_StereoSGBM _retval_ = cv::StereoSGBM::create( (int)minDisparity );
        return (jlong)(new Ptr_StereoSGBM(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_StereoSGBM_create_111 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_StereoSGBM_create_111
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "calib3d::create_111()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::StereoSGBM> Ptr_StereoSGBM;
        Ptr_StereoSGBM _retval_ = cv::StereoSGBM::create();
        return (jlong)(new Ptr_StereoSGBM(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::StereoSGBM::getMode()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_StereoSGBM_getMode_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_StereoSGBM_getMode_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "calib3d::getMode_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::StereoSGBM>* me = (Ptr<cv::StereoSGBM>*) self; //TODO: check for NULL
        return (*me)->getMode();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::StereoSGBM::getP1()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_StereoSGBM_getP1_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_StereoSGBM_getP1_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "calib3d::getP1_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::StereoSGBM>* me = (Ptr<cv::StereoSGBM>*) self; //TODO: check for NULL
        return (*me)->getP1();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::StereoSGBM::getP2()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_StereoSGBM_getP2_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_StereoSGBM_getP2_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "calib3d::getP2_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::StereoSGBM>* me = (Ptr<cv::StereoSGBM>*) self; //TODO: check for NULL
        return (*me)->getP2();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::StereoSGBM::getPreFilterCap()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_StereoSGBM_getPreFilterCap_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_StereoSGBM_getPreFilterCap_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "calib3d::getPreFilterCap_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::StereoSGBM>* me = (Ptr<cv::StereoSGBM>*) self; //TODO: check for NULL
        return (*me)->getPreFilterCap();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::StereoSGBM::getUniquenessRatio()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_StereoSGBM_getUniquenessRatio_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_StereoSGBM_getUniquenessRatio_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "calib3d::getUniquenessRatio_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::StereoSGBM>* me = (Ptr<cv::StereoSGBM>*) self; //TODO: check for NULL
        return (*me)->getUniquenessRatio();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::StereoSGBM::setMode(int mode)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_calib3d_StereoSGBM_setMode_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_StereoSGBM_setMode_10
  (JNIEnv* env, jclass , jlong self, jint mode)
{
    static const char method_name[] = "calib3d::setMode_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::StereoSGBM>* me = (Ptr<cv::StereoSGBM>*) self; //TODO: check for NULL
        (*me)->setMode( (int)mode );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::StereoSGBM::setP1(int P1)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_calib3d_StereoSGBM_setP1_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_StereoSGBM_setP1_10
  (JNIEnv* env, jclass , jlong self, jint P1)
{
    static const char method_name[] = "calib3d::setP1_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::StereoSGBM>* me = (Ptr<cv::StereoSGBM>*) self; //TODO: check for NULL
        (*me)->setP1( (int)P1 );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::StereoSGBM::setP2(int P2)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_calib3d_StereoSGBM_setP2_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_StereoSGBM_setP2_10
  (JNIEnv* env, jclass , jlong self, jint P2)
{
    static const char method_name[] = "calib3d::setP2_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::StereoSGBM>* me = (Ptr<cv::StereoSGBM>*) self; //TODO: check for NULL
        (*me)->setP2( (int)P2 );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::StereoSGBM::setPreFilterCap(int preFilterCap)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_calib3d_StereoSGBM_setPreFilterCap_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_StereoSGBM_setPreFilterCap_10
  (JNIEnv* env, jclass , jlong self, jint preFilterCap)
{
    static const char method_name[] = "calib3d::setPreFilterCap_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::StereoSGBM>* me = (Ptr<cv::StereoSGBM>*) self; //TODO: check for NULL
        (*me)->setPreFilterCap( (int)preFilterCap );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::StereoSGBM::setUniquenessRatio(int uniquenessRatio)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_calib3d_StereoSGBM_setUniquenessRatio_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_StereoSGBM_setUniquenessRatio_10
  (JNIEnv* env, jclass , jlong self, jint uniquenessRatio)
{
    static const char method_name[] = "calib3d::setUniquenessRatio_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::StereoSGBM>* me = (Ptr<cv::StereoSGBM>*) self; //TODO: check for NULL
        (*me)->setUniquenessRatio( (int)uniquenessRatio );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void Ptr<cv::StereoSGBM>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_calib3d_StereoSGBM_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_StereoSGBM_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::StereoSGBM>*) self;
}


//
// static Ptr_StereoBM cv::StereoBM::create(int numDisparities = 0, int blockSize = 21)
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_StereoBM_create_10 (JNIEnv*, jclass, jint, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_StereoBM_create_10
  (JNIEnv* env, jclass , jint numDisparities, jint blockSize)
{
    static const char method_name[] = "calib3d::create_10()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::StereoBM> Ptr_StereoBM;
        Ptr_StereoBM _retval_ = cv::StereoBM::create( (int)numDisparities, (int)blockSize );
        return (jlong)(new Ptr_StereoBM(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_StereoBM_create_11 (JNIEnv*, jclass, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_StereoBM_create_11
  (JNIEnv* env, jclass , jint numDisparities)
{
    static const char method_name[] = "calib3d::create_11()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::StereoBM> Ptr_StereoBM;
        Ptr_StereoBM _retval_ = cv::StereoBM::create( (int)numDisparities );
        return (jlong)(new Ptr_StereoBM(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_StereoBM_create_12 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_StereoBM_create_12
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "calib3d::create_12()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::StereoBM> Ptr_StereoBM;
        Ptr_StereoBM _retval_ = cv::StereoBM::create();
        return (jlong)(new Ptr_StereoBM(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Rect cv::StereoBM::getROI1()
//

using namespace cv;

JNIEXPORT jdoubleArray JNICALL Java_org_opencv_calib3d_StereoBM_getROI1_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jdoubleArray JNICALL Java_org_opencv_calib3d_StereoBM_getROI1_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "calib3d::getROI1_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::StereoBM>* me = (Ptr<cv::StereoBM>*) self; //TODO: check for NULL
        Rect _retval_ = (*me)->getROI1();
        jdoubleArray _da_retval_ = env->NewDoubleArray(4);  jdouble _tmp_retval_[4] = {(jdouble)_retval_.x, (jdouble)_retval_.y, (jdouble)_retval_.width, (jdouble)_retval_.height}; env->SetDoubleArrayRegion(_da_retval_, 0, 4, _tmp_retval_);
        return _da_retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Rect cv::StereoBM::getROI2()
//

using namespace cv;

JNIEXPORT jdoubleArray JNICALL Java_org_opencv_calib3d_StereoBM_getROI2_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jdoubleArray JNICALL Java_org_opencv_calib3d_StereoBM_getROI2_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "calib3d::getROI2_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::StereoBM>* me = (Ptr<cv::StereoBM>*) self; //TODO: check for NULL
        Rect _retval_ = (*me)->getROI2();
        jdoubleArray _da_retval_ = env->NewDoubleArray(4);  jdouble _tmp_retval_[4] = {(jdouble)_retval_.x, (jdouble)_retval_.y, (jdouble)_retval_.width, (jdouble)_retval_.height}; env->SetDoubleArrayRegion(_da_retval_, 0, 4, _tmp_retval_);
        return _da_retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::StereoBM::getPreFilterCap()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_StereoBM_getPreFilterCap_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_StereoBM_getPreFilterCap_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "calib3d::getPreFilterCap_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::StereoBM>* me = (Ptr<cv::StereoBM>*) self; //TODO: check for NULL
        return (*me)->getPreFilterCap();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::StereoBM::getPreFilterSize()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_StereoBM_getPreFilterSize_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_StereoBM_getPreFilterSize_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "calib3d::getPreFilterSize_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::StereoBM>* me = (Ptr<cv::StereoBM>*) self; //TODO: check for NULL
        return (*me)->getPreFilterSize();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::StereoBM::getPreFilterType()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_StereoBM_getPreFilterType_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_StereoBM_getPreFilterType_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "calib3d::getPreFilterType_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::StereoBM>* me = (Ptr<cv::StereoBM>*) self; //TODO: check for NULL
        return (*me)->getPreFilterType();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::StereoBM::getSmallerBlockSize()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_StereoBM_getSmallerBlockSize_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_StereoBM_getSmallerBlockSize_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "calib3d::getSmallerBlockSize_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::StereoBM>* me = (Ptr<cv::StereoBM>*) self; //TODO: check for NULL
        return (*me)->getSmallerBlockSize();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::StereoBM::getTextureThreshold()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_StereoBM_getTextureThreshold_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_StereoBM_getTextureThreshold_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "calib3d::getTextureThreshold_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::StereoBM>* me = (Ptr<cv::StereoBM>*) self; //TODO: check for NULL
        return (*me)->getTextureThreshold();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::StereoBM::getUniquenessRatio()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_StereoBM_getUniquenessRatio_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_StereoBM_getUniquenessRatio_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "calib3d::getUniquenessRatio_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::StereoBM>* me = (Ptr<cv::StereoBM>*) self; //TODO: check for NULL
        return (*me)->getUniquenessRatio();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::StereoBM::setPreFilterCap(int preFilterCap)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_calib3d_StereoBM_setPreFilterCap_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_StereoBM_setPreFilterCap_10
  (JNIEnv* env, jclass , jlong self, jint preFilterCap)
{
    static const char method_name[] = "calib3d::setPreFilterCap_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::StereoBM>* me = (Ptr<cv::StereoBM>*) self; //TODO: check for NULL
        (*me)->setPreFilterCap( (int)preFilterCap );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::StereoBM::setPreFilterSize(int preFilterSize)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_calib3d_StereoBM_setPreFilterSize_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_StereoBM_setPreFilterSize_10
  (JNIEnv* env, jclass , jlong self, jint preFilterSize)
{
    static const char method_name[] = "calib3d::setPreFilterSize_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::StereoBM>* me = (Ptr<cv::StereoBM>*) self; //TODO: check for NULL
        (*me)->setPreFilterSize( (int)preFilterSize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::StereoBM::setPreFilterType(int preFilterType)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_calib3d_StereoBM_setPreFilterType_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_StereoBM_setPreFilterType_10
  (JNIEnv* env, jclass , jlong self, jint preFilterType)
{
    static const char method_name[] = "calib3d::setPreFilterType_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::StereoBM>* me = (Ptr<cv::StereoBM>*) self; //TODO: check for NULL
        (*me)->setPreFilterType( (int)preFilterType );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::StereoBM::setROI1(Rect roi1)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_calib3d_StereoBM_setROI1_10 (JNIEnv*, jclass, jlong, jint, jint, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_StereoBM_setROI1_10
  (JNIEnv* env, jclass , jlong self, jint roi1_x, jint roi1_y, jint roi1_width, jint roi1_height)
{
    static const char method_name[] = "calib3d::setROI1_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::StereoBM>* me = (Ptr<cv::StereoBM>*) self; //TODO: check for NULL
        Rect roi1(roi1_x, roi1_y, roi1_width, roi1_height);
        (*me)->setROI1( roi1 );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::StereoBM::setROI2(Rect roi2)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_calib3d_StereoBM_setROI2_10 (JNIEnv*, jclass, jlong, jint, jint, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_StereoBM_setROI2_10
  (JNIEnv* env, jclass , jlong self, jint roi2_x, jint roi2_y, jint roi2_width, jint roi2_height)
{
    static const char method_name[] = "calib3d::setROI2_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::StereoBM>* me = (Ptr<cv::StereoBM>*) self; //TODO: check for NULL
        Rect roi2(roi2_x, roi2_y, roi2_width, roi2_height);
        (*me)->setROI2( roi2 );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::StereoBM::setSmallerBlockSize(int blockSize)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_calib3d_StereoBM_setSmallerBlockSize_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_StereoBM_setSmallerBlockSize_10
  (JNIEnv* env, jclass , jlong self, jint blockSize)
{
    static const char method_name[] = "calib3d::setSmallerBlockSize_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::StereoBM>* me = (Ptr<cv::StereoBM>*) self; //TODO: check for NULL
        (*me)->setSmallerBlockSize( (int)blockSize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::StereoBM::setTextureThreshold(int textureThreshold)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_calib3d_StereoBM_setTextureThreshold_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_StereoBM_setTextureThreshold_10
  (JNIEnv* env, jclass , jlong self, jint textureThreshold)
{
    static const char method_name[] = "calib3d::setTextureThreshold_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::StereoBM>* me = (Ptr<cv::StereoBM>*) self; //TODO: check for NULL
        (*me)->setTextureThreshold( (int)textureThreshold );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::StereoBM::setUniquenessRatio(int uniquenessRatio)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_calib3d_StereoBM_setUniquenessRatio_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_StereoBM_setUniquenessRatio_10
  (JNIEnv* env, jclass , jlong self, jint uniquenessRatio)
{
    static const char method_name[] = "calib3d::setUniquenessRatio_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::StereoBM>* me = (Ptr<cv::StereoBM>*) self; //TODO: check for NULL
        (*me)->setUniquenessRatio( (int)uniquenessRatio );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void Ptr<cv::StereoBM>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_calib3d_StereoBM_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_StereoBM_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::StereoBM>*) self;
}


//
//  int cv::StereoMatcher::getBlockSize()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_StereoMatcher_getBlockSize_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_StereoMatcher_getBlockSize_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "calib3d::getBlockSize_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::StereoMatcher>* me = (Ptr<cv::StereoMatcher>*) self; //TODO: check for NULL
        return (*me)->getBlockSize();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::StereoMatcher::getDisp12MaxDiff()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_StereoMatcher_getDisp12MaxDiff_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_StereoMatcher_getDisp12MaxDiff_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "calib3d::getDisp12MaxDiff_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::StereoMatcher>* me = (Ptr<cv::StereoMatcher>*) self; //TODO: check for NULL
        return (*me)->getDisp12MaxDiff();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::StereoMatcher::getMinDisparity()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_StereoMatcher_getMinDisparity_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_StereoMatcher_getMinDisparity_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "calib3d::getMinDisparity_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::StereoMatcher>* me = (Ptr<cv::StereoMatcher>*) self; //TODO: check for NULL
        return (*me)->getMinDisparity();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::StereoMatcher::getNumDisparities()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_StereoMatcher_getNumDisparities_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_StereoMatcher_getNumDisparities_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "calib3d::getNumDisparities_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::StereoMatcher>* me = (Ptr<cv::StereoMatcher>*) self; //TODO: check for NULL
        return (*me)->getNumDisparities();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::StereoMatcher::getSpeckleRange()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_StereoMatcher_getSpeckleRange_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_StereoMatcher_getSpeckleRange_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "calib3d::getSpeckleRange_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::StereoMatcher>* me = (Ptr<cv::StereoMatcher>*) self; //TODO: check for NULL
        return (*me)->getSpeckleRange();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::StereoMatcher::getSpeckleWindowSize()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_StereoMatcher_getSpeckleWindowSize_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_StereoMatcher_getSpeckleWindowSize_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "calib3d::getSpeckleWindowSize_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::StereoMatcher>* me = (Ptr<cv::StereoMatcher>*) self; //TODO: check for NULL
        return (*me)->getSpeckleWindowSize();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::StereoMatcher::compute(Mat left, Mat right, Mat& disparity)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_calib3d_StereoMatcher_compute_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_StereoMatcher_compute_10
  (JNIEnv* env, jclass , jlong self, jlong left_nativeObj, jlong right_nativeObj, jlong disparity_nativeObj)
{
    static const char method_name[] = "calib3d::compute_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::StereoMatcher>* me = (Ptr<cv::StereoMatcher>*) self; //TODO: check for NULL
        Mat& left = *((Mat*)left_nativeObj);
        Mat& right = *((Mat*)right_nativeObj);
        Mat& disparity = *((Mat*)disparity_nativeObj);
        (*me)->compute( left, right, disparity );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::StereoMatcher::setBlockSize(int blockSize)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_calib3d_StereoMatcher_setBlockSize_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_StereoMatcher_setBlockSize_10
  (JNIEnv* env, jclass , jlong self, jint blockSize)
{
    static const char method_name[] = "calib3d::setBlockSize_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::StereoMatcher>* me = (Ptr<cv::StereoMatcher>*) self; //TODO: check for NULL
        (*me)->setBlockSize( (int)blockSize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::StereoMatcher::setDisp12MaxDiff(int disp12MaxDiff)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_calib3d_StereoMatcher_setDisp12MaxDiff_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_StereoMatcher_setDisp12MaxDiff_10
  (JNIEnv* env, jclass , jlong self, jint disp12MaxDiff)
{
    static const char method_name[] = "calib3d::setDisp12MaxDiff_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::StereoMatcher>* me = (Ptr<cv::StereoMatcher>*) self; //TODO: check for NULL
        (*me)->setDisp12MaxDiff( (int)disp12MaxDiff );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::StereoMatcher::setMinDisparity(int minDisparity)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_calib3d_StereoMatcher_setMinDisparity_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_StereoMatcher_setMinDisparity_10
  (JNIEnv* env, jclass , jlong self, jint minDisparity)
{
    static const char method_name[] = "calib3d::setMinDisparity_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::StereoMatcher>* me = (Ptr<cv::StereoMatcher>*) self; //TODO: check for NULL
        (*me)->setMinDisparity( (int)minDisparity );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::StereoMatcher::setNumDisparities(int numDisparities)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_calib3d_StereoMatcher_setNumDisparities_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_StereoMatcher_setNumDisparities_10
  (JNIEnv* env, jclass , jlong self, jint numDisparities)
{
    static const char method_name[] = "calib3d::setNumDisparities_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::StereoMatcher>* me = (Ptr<cv::StereoMatcher>*) self; //TODO: check for NULL
        (*me)->setNumDisparities( (int)numDisparities );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::StereoMatcher::setSpeckleRange(int speckleRange)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_calib3d_StereoMatcher_setSpeckleRange_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_StereoMatcher_setSpeckleRange_10
  (JNIEnv* env, jclass , jlong self, jint speckleRange)
{
    static const char method_name[] = "calib3d::setSpeckleRange_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::StereoMatcher>* me = (Ptr<cv::StereoMatcher>*) self; //TODO: check for NULL
        (*me)->setSpeckleRange( (int)speckleRange );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::StereoMatcher::setSpeckleWindowSize(int speckleWindowSize)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_calib3d_StereoMatcher_setSpeckleWindowSize_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_StereoMatcher_setSpeckleWindowSize_10
  (JNIEnv* env, jclass , jlong self, jint speckleWindowSize)
{
    static const char method_name[] = "calib3d::setSpeckleWindowSize_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::StereoMatcher>* me = (Ptr<cv::StereoMatcher>*) self; //TODO: check for NULL
        (*me)->setSpeckleWindowSize( (int)speckleWindowSize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void Ptr<cv::StereoMatcher>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_calib3d_StereoMatcher_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_StereoMatcher_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::StereoMatcher>*) self;
}


//
//  Mat cv::estimateAffine2D(Mat from, Mat to, Mat& inliers = Mat(), int method = RANSAC, double ransacReprojThreshold = 3, size_t maxIters = 2000, double confidence = 0.99, size_t refineIters = 10)
//



JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_estimateAffine2D_10 (JNIEnv*, jclass, jlong, jlong, jlong, jint, jdouble, jlong, jdouble, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_estimateAffine2D_10
  (JNIEnv* env, jclass , jlong from_nativeObj, jlong to_nativeObj, jlong inliers_nativeObj, jint method, jdouble ransacReprojThreshold, jlong maxIters, jdouble confidence, jlong refineIters)
{
    static const char method_name[] = "calib3d::estimateAffine2D_10()";
    try {
        LOGD("%s", method_name);
        Mat& from = *((Mat*)from_nativeObj);
        Mat& to = *((Mat*)to_nativeObj);
        Mat& inliers = *((Mat*)inliers_nativeObj);
        ::Mat _retval_ = cv::estimateAffine2D( from, to, inliers, (int)method, (double)ransacReprojThreshold, (size_t)maxIters, (double)confidence, (size_t)refineIters );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_estimateAffine2D_11 (JNIEnv*, jclass, jlong, jlong, jlong, jint, jdouble, jlong, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_estimateAffine2D_11
  (JNIEnv* env, jclass , jlong from_nativeObj, jlong to_nativeObj, jlong inliers_nativeObj, jint method, jdouble ransacReprojThreshold, jlong maxIters, jdouble confidence)
{
    static const char method_name[] = "calib3d::estimateAffine2D_11()";
    try {
        LOGD("%s", method_name);
        Mat& from = *((Mat*)from_nativeObj);
        Mat& to = *((Mat*)to_nativeObj);
        Mat& inliers = *((Mat*)inliers_nativeObj);
        ::Mat _retval_ = cv::estimateAffine2D( from, to, inliers, (int)method, (double)ransacReprojThreshold, (size_t)maxIters, (double)confidence );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_estimateAffine2D_12 (JNIEnv*, jclass, jlong, jlong, jlong, jint, jdouble, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_estimateAffine2D_12
  (JNIEnv* env, jclass , jlong from_nativeObj, jlong to_nativeObj, jlong inliers_nativeObj, jint method, jdouble ransacReprojThreshold, jlong maxIters)
{
    static const char method_name[] = "calib3d::estimateAffine2D_12()";
    try {
        LOGD("%s", method_name);
        Mat& from = *((Mat*)from_nativeObj);
        Mat& to = *((Mat*)to_nativeObj);
        Mat& inliers = *((Mat*)inliers_nativeObj);
        ::Mat _retval_ = cv::estimateAffine2D( from, to, inliers, (int)method, (double)ransacReprojThreshold, (size_t)maxIters );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_estimateAffine2D_13 (JNIEnv*, jclass, jlong, jlong, jlong, jint, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_estimateAffine2D_13
  (JNIEnv* env, jclass , jlong from_nativeObj, jlong to_nativeObj, jlong inliers_nativeObj, jint method, jdouble ransacReprojThreshold)
{
    static const char method_name[] = "calib3d::estimateAffine2D_13()";
    try {
        LOGD("%s", method_name);
        Mat& from = *((Mat*)from_nativeObj);
        Mat& to = *((Mat*)to_nativeObj);
        Mat& inliers = *((Mat*)inliers_nativeObj);
        ::Mat _retval_ = cv::estimateAffine2D( from, to, inliers, (int)method, (double)ransacReprojThreshold );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_estimateAffine2D_14 (JNIEnv*, jclass, jlong, jlong, jlong, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_estimateAffine2D_14
  (JNIEnv* env, jclass , jlong from_nativeObj, jlong to_nativeObj, jlong inliers_nativeObj, jint method)
{
    static const char method_name[] = "calib3d::estimateAffine2D_14()";
    try {
        LOGD("%s", method_name);
        Mat& from = *((Mat*)from_nativeObj);
        Mat& to = *((Mat*)to_nativeObj);
        Mat& inliers = *((Mat*)inliers_nativeObj);
        ::Mat _retval_ = cv::estimateAffine2D( from, to, inliers, (int)method );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_estimateAffine2D_15 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_estimateAffine2D_15
  (JNIEnv* env, jclass , jlong from_nativeObj, jlong to_nativeObj, jlong inliers_nativeObj)
{
    static const char method_name[] = "calib3d::estimateAffine2D_15()";
    try {
        LOGD("%s", method_name);
        Mat& from = *((Mat*)from_nativeObj);
        Mat& to = *((Mat*)to_nativeObj);
        Mat& inliers = *((Mat*)inliers_nativeObj);
        ::Mat _retval_ = cv::estimateAffine2D( from, to, inliers );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_estimateAffine2D_16 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_estimateAffine2D_16
  (JNIEnv* env, jclass , jlong from_nativeObj, jlong to_nativeObj)
{
    static const char method_name[] = "calib3d::estimateAffine2D_16()";
    try {
        LOGD("%s", method_name);
        Mat& from = *((Mat*)from_nativeObj);
        Mat& to = *((Mat*)to_nativeObj);
        ::Mat _retval_ = cv::estimateAffine2D( from, to );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Mat cv::estimateAffinePartial2D(Mat from, Mat to, Mat& inliers = Mat(), int method = RANSAC, double ransacReprojThreshold = 3, size_t maxIters = 2000, double confidence = 0.99, size_t refineIters = 10)
//



JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_estimateAffinePartial2D_10 (JNIEnv*, jclass, jlong, jlong, jlong, jint, jdouble, jlong, jdouble, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_estimateAffinePartial2D_10
  (JNIEnv* env, jclass , jlong from_nativeObj, jlong to_nativeObj, jlong inliers_nativeObj, jint method, jdouble ransacReprojThreshold, jlong maxIters, jdouble confidence, jlong refineIters)
{
    static const char method_name[] = "calib3d::estimateAffinePartial2D_10()";
    try {
        LOGD("%s", method_name);
        Mat& from = *((Mat*)from_nativeObj);
        Mat& to = *((Mat*)to_nativeObj);
        Mat& inliers = *((Mat*)inliers_nativeObj);
        ::Mat _retval_ = cv::estimateAffinePartial2D( from, to, inliers, (int)method, (double)ransacReprojThreshold, (size_t)maxIters, (double)confidence, (size_t)refineIters );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_estimateAffinePartial2D_11 (JNIEnv*, jclass, jlong, jlong, jlong, jint, jdouble, jlong, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_estimateAffinePartial2D_11
  (JNIEnv* env, jclass , jlong from_nativeObj, jlong to_nativeObj, jlong inliers_nativeObj, jint method, jdouble ransacReprojThreshold, jlong maxIters, jdouble confidence)
{
    static const char method_name[] = "calib3d::estimateAffinePartial2D_11()";
    try {
        LOGD("%s", method_name);
        Mat& from = *((Mat*)from_nativeObj);
        Mat& to = *((Mat*)to_nativeObj);
        Mat& inliers = *((Mat*)inliers_nativeObj);
        ::Mat _retval_ = cv::estimateAffinePartial2D( from, to, inliers, (int)method, (double)ransacReprojThreshold, (size_t)maxIters, (double)confidence );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_estimateAffinePartial2D_12 (JNIEnv*, jclass, jlong, jlong, jlong, jint, jdouble, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_estimateAffinePartial2D_12
  (JNIEnv* env, jclass , jlong from_nativeObj, jlong to_nativeObj, jlong inliers_nativeObj, jint method, jdouble ransacReprojThreshold, jlong maxIters)
{
    static const char method_name[] = "calib3d::estimateAffinePartial2D_12()";
    try {
        LOGD("%s", method_name);
        Mat& from = *((Mat*)from_nativeObj);
        Mat& to = *((Mat*)to_nativeObj);
        Mat& inliers = *((Mat*)inliers_nativeObj);
        ::Mat _retval_ = cv::estimateAffinePartial2D( from, to, inliers, (int)method, (double)ransacReprojThreshold, (size_t)maxIters );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_estimateAffinePartial2D_13 (JNIEnv*, jclass, jlong, jlong, jlong, jint, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_estimateAffinePartial2D_13
  (JNIEnv* env, jclass , jlong from_nativeObj, jlong to_nativeObj, jlong inliers_nativeObj, jint method, jdouble ransacReprojThreshold)
{
    static const char method_name[] = "calib3d::estimateAffinePartial2D_13()";
    try {
        LOGD("%s", method_name);
        Mat& from = *((Mat*)from_nativeObj);
        Mat& to = *((Mat*)to_nativeObj);
        Mat& inliers = *((Mat*)inliers_nativeObj);
        ::Mat _retval_ = cv::estimateAffinePartial2D( from, to, inliers, (int)method, (double)ransacReprojThreshold );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_estimateAffinePartial2D_14 (JNIEnv*, jclass, jlong, jlong, jlong, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_estimateAffinePartial2D_14
  (JNIEnv* env, jclass , jlong from_nativeObj, jlong to_nativeObj, jlong inliers_nativeObj, jint method)
{
    static const char method_name[] = "calib3d::estimateAffinePartial2D_14()";
    try {
        LOGD("%s", method_name);
        Mat& from = *((Mat*)from_nativeObj);
        Mat& to = *((Mat*)to_nativeObj);
        Mat& inliers = *((Mat*)inliers_nativeObj);
        ::Mat _retval_ = cv::estimateAffinePartial2D( from, to, inliers, (int)method );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_estimateAffinePartial2D_15 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_estimateAffinePartial2D_15
  (JNIEnv* env, jclass , jlong from_nativeObj, jlong to_nativeObj, jlong inliers_nativeObj)
{
    static const char method_name[] = "calib3d::estimateAffinePartial2D_15()";
    try {
        LOGD("%s", method_name);
        Mat& from = *((Mat*)from_nativeObj);
        Mat& to = *((Mat*)to_nativeObj);
        Mat& inliers = *((Mat*)inliers_nativeObj);
        ::Mat _retval_ = cv::estimateAffinePartial2D( from, to, inliers );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_estimateAffinePartial2D_16 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_estimateAffinePartial2D_16
  (JNIEnv* env, jclass , jlong from_nativeObj, jlong to_nativeObj)
{
    static const char method_name[] = "calib3d::estimateAffinePartial2D_16()";
    try {
        LOGD("%s", method_name);
        Mat& from = *((Mat*)from_nativeObj);
        Mat& to = *((Mat*)to_nativeObj);
        ::Mat _retval_ = cv::estimateAffinePartial2D( from, to );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Mat cv::findEssentialMat(Mat points1, Mat points2, Mat cameraMatrix, int method = RANSAC, double prob = 0.999, double threshold = 1.0, Mat& mask = Mat())
//



JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findEssentialMat_10 (JNIEnv*, jclass, jlong, jlong, jlong, jint, jdouble, jdouble, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findEssentialMat_10
  (JNIEnv* env, jclass , jlong points1_nativeObj, jlong points2_nativeObj, jlong cameraMatrix_nativeObj, jint method, jdouble prob, jdouble threshold, jlong mask_nativeObj)
{
    static const char method_name[] = "calib3d::findEssentialMat_10()";
    try {
        LOGD("%s", method_name);
        Mat& points1 = *((Mat*)points1_nativeObj);
        Mat& points2 = *((Mat*)points2_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        ::Mat _retval_ = cv::findEssentialMat( points1, points2, cameraMatrix, (int)method, (double)prob, (double)threshold, mask );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findEssentialMat_11 (JNIEnv*, jclass, jlong, jlong, jlong, jint, jdouble, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findEssentialMat_11
  (JNIEnv* env, jclass , jlong points1_nativeObj, jlong points2_nativeObj, jlong cameraMatrix_nativeObj, jint method, jdouble prob, jdouble threshold)
{
    static const char method_name[] = "calib3d::findEssentialMat_11()";
    try {
        LOGD("%s", method_name);
        Mat& points1 = *((Mat*)points1_nativeObj);
        Mat& points2 = *((Mat*)points2_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        ::Mat _retval_ = cv::findEssentialMat( points1, points2, cameraMatrix, (int)method, (double)prob, (double)threshold );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findEssentialMat_12 (JNIEnv*, jclass, jlong, jlong, jlong, jint, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findEssentialMat_12
  (JNIEnv* env, jclass , jlong points1_nativeObj, jlong points2_nativeObj, jlong cameraMatrix_nativeObj, jint method, jdouble prob)
{
    static const char method_name[] = "calib3d::findEssentialMat_12()";
    try {
        LOGD("%s", method_name);
        Mat& points1 = *((Mat*)points1_nativeObj);
        Mat& points2 = *((Mat*)points2_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        ::Mat _retval_ = cv::findEssentialMat( points1, points2, cameraMatrix, (int)method, (double)prob );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findEssentialMat_13 (JNIEnv*, jclass, jlong, jlong, jlong, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findEssentialMat_13
  (JNIEnv* env, jclass , jlong points1_nativeObj, jlong points2_nativeObj, jlong cameraMatrix_nativeObj, jint method)
{
    static const char method_name[] = "calib3d::findEssentialMat_13()";
    try {
        LOGD("%s", method_name);
        Mat& points1 = *((Mat*)points1_nativeObj);
        Mat& points2 = *((Mat*)points2_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        ::Mat _retval_ = cv::findEssentialMat( points1, points2, cameraMatrix, (int)method );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findEssentialMat_14 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findEssentialMat_14
  (JNIEnv* env, jclass , jlong points1_nativeObj, jlong points2_nativeObj, jlong cameraMatrix_nativeObj)
{
    static const char method_name[] = "calib3d::findEssentialMat_14()";
    try {
        LOGD("%s", method_name);
        Mat& points1 = *((Mat*)points1_nativeObj);
        Mat& points2 = *((Mat*)points2_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        ::Mat _retval_ = cv::findEssentialMat( points1, points2, cameraMatrix );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Mat cv::findEssentialMat(Mat points1, Mat points2, double focal = 1.0, Point2d pp = Point2d(0, 0), int method = RANSAC, double prob = 0.999, double threshold = 1.0, Mat& mask = Mat())
//



JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findEssentialMat_15 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jdouble, jint, jdouble, jdouble, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findEssentialMat_15
  (JNIEnv* env, jclass , jlong points1_nativeObj, jlong points2_nativeObj, jdouble focal, jdouble pp_x, jdouble pp_y, jint method, jdouble prob, jdouble threshold, jlong mask_nativeObj)
{
    static const char method_name[] = "calib3d::findEssentialMat_15()";
    try {
        LOGD("%s", method_name);
        Mat& points1 = *((Mat*)points1_nativeObj);
        Mat& points2 = *((Mat*)points2_nativeObj);
        Point2d pp(pp_x, pp_y);
        Mat& mask = *((Mat*)mask_nativeObj);
        ::Mat _retval_ = cv::findEssentialMat( points1, points2, (double)focal, pp, (int)method, (double)prob, (double)threshold, mask );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findEssentialMat_16 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jdouble, jint, jdouble, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findEssentialMat_16
  (JNIEnv* env, jclass , jlong points1_nativeObj, jlong points2_nativeObj, jdouble focal, jdouble pp_x, jdouble pp_y, jint method, jdouble prob, jdouble threshold)
{
    static const char method_name[] = "calib3d::findEssentialMat_16()";
    try {
        LOGD("%s", method_name);
        Mat& points1 = *((Mat*)points1_nativeObj);
        Mat& points2 = *((Mat*)points2_nativeObj);
        Point2d pp(pp_x, pp_y);
        ::Mat _retval_ = cv::findEssentialMat( points1, points2, (double)focal, pp, (int)method, (double)prob, (double)threshold );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findEssentialMat_17 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jdouble, jint, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findEssentialMat_17
  (JNIEnv* env, jclass , jlong points1_nativeObj, jlong points2_nativeObj, jdouble focal, jdouble pp_x, jdouble pp_y, jint method, jdouble prob)
{
    static const char method_name[] = "calib3d::findEssentialMat_17()";
    try {
        LOGD("%s", method_name);
        Mat& points1 = *((Mat*)points1_nativeObj);
        Mat& points2 = *((Mat*)points2_nativeObj);
        Point2d pp(pp_x, pp_y);
        ::Mat _retval_ = cv::findEssentialMat( points1, points2, (double)focal, pp, (int)method, (double)prob );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findEssentialMat_18 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jdouble, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findEssentialMat_18
  (JNIEnv* env, jclass , jlong points1_nativeObj, jlong points2_nativeObj, jdouble focal, jdouble pp_x, jdouble pp_y, jint method)
{
    static const char method_name[] = "calib3d::findEssentialMat_18()";
    try {
        LOGD("%s", method_name);
        Mat& points1 = *((Mat*)points1_nativeObj);
        Mat& points2 = *((Mat*)points2_nativeObj);
        Point2d pp(pp_x, pp_y);
        ::Mat _retval_ = cv::findEssentialMat( points1, points2, (double)focal, pp, (int)method );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findEssentialMat_19 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findEssentialMat_19
  (JNIEnv* env, jclass , jlong points1_nativeObj, jlong points2_nativeObj, jdouble focal, jdouble pp_x, jdouble pp_y)
{
    static const char method_name[] = "calib3d::findEssentialMat_19()";
    try {
        LOGD("%s", method_name);
        Mat& points1 = *((Mat*)points1_nativeObj);
        Mat& points2 = *((Mat*)points2_nativeObj);
        Point2d pp(pp_x, pp_y);
        ::Mat _retval_ = cv::findEssentialMat( points1, points2, (double)focal, pp );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findEssentialMat_110 (JNIEnv*, jclass, jlong, jlong, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findEssentialMat_110
  (JNIEnv* env, jclass , jlong points1_nativeObj, jlong points2_nativeObj, jdouble focal)
{
    static const char method_name[] = "calib3d::findEssentialMat_110()";
    try {
        LOGD("%s", method_name);
        Mat& points1 = *((Mat*)points1_nativeObj);
        Mat& points2 = *((Mat*)points2_nativeObj);
        ::Mat _retval_ = cv::findEssentialMat( points1, points2, (double)focal );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findEssentialMat_111 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findEssentialMat_111
  (JNIEnv* env, jclass , jlong points1_nativeObj, jlong points2_nativeObj)
{
    static const char method_name[] = "calib3d::findEssentialMat_111()";
    try {
        LOGD("%s", method_name);
        Mat& points1 = *((Mat*)points1_nativeObj);
        Mat& points2 = *((Mat*)points2_nativeObj);
        ::Mat _retval_ = cv::findEssentialMat( points1, points2 );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Mat cv::findFundamentalMat(vector_Point2f points1, vector_Point2f points2, int method, double ransacReprojThreshold, double confidence, int maxIters, Mat& mask = Mat())
//



JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findFundamentalMat_10 (JNIEnv*, jclass, jlong, jlong, jint, jdouble, jdouble, jint, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findFundamentalMat_10
  (JNIEnv* env, jclass , jlong points1_mat_nativeObj, jlong points2_mat_nativeObj, jint method, jdouble ransacReprojThreshold, jdouble confidence, jint maxIters, jlong mask_nativeObj)
{
    static const char method_name[] = "calib3d::findFundamentalMat_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Point2f> points1;
        Mat& points1_mat = *((Mat*)points1_mat_nativeObj);
        Mat_to_vector_Point2f( points1_mat, points1 );
        std::vector<Point2f> points2;
        Mat& points2_mat = *((Mat*)points2_mat_nativeObj);
        Mat_to_vector_Point2f( points2_mat, points2 );
        Mat& mask = *((Mat*)mask_nativeObj);
        ::Mat _retval_ = cv::findFundamentalMat( points1, points2, (int)method, (double)ransacReprojThreshold, (double)confidence, (int)maxIters, mask );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findFundamentalMat_11 (JNIEnv*, jclass, jlong, jlong, jint, jdouble, jdouble, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findFundamentalMat_11
  (JNIEnv* env, jclass , jlong points1_mat_nativeObj, jlong points2_mat_nativeObj, jint method, jdouble ransacReprojThreshold, jdouble confidence, jint maxIters)
{
    static const char method_name[] = "calib3d::findFundamentalMat_11()";
    try {
        LOGD("%s", method_name);
        std::vector<Point2f> points1;
        Mat& points1_mat = *((Mat*)points1_mat_nativeObj);
        Mat_to_vector_Point2f( points1_mat, points1 );
        std::vector<Point2f> points2;
        Mat& points2_mat = *((Mat*)points2_mat_nativeObj);
        Mat_to_vector_Point2f( points2_mat, points2 );
        ::Mat _retval_ = cv::findFundamentalMat( points1, points2, (int)method, (double)ransacReprojThreshold, (double)confidence, (int)maxIters );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Mat cv::findFundamentalMat(vector_Point2f points1, vector_Point2f points2, int method = FM_RANSAC, double ransacReprojThreshold = 3., double confidence = 0.99, Mat& mask = Mat())
//



JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findFundamentalMat_12 (JNIEnv*, jclass, jlong, jlong, jint, jdouble, jdouble, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findFundamentalMat_12
  (JNIEnv* env, jclass , jlong points1_mat_nativeObj, jlong points2_mat_nativeObj, jint method, jdouble ransacReprojThreshold, jdouble confidence, jlong mask_nativeObj)
{
    static const char method_name[] = "calib3d::findFundamentalMat_12()";
    try {
        LOGD("%s", method_name);
        std::vector<Point2f> points1;
        Mat& points1_mat = *((Mat*)points1_mat_nativeObj);
        Mat_to_vector_Point2f( points1_mat, points1 );
        std::vector<Point2f> points2;
        Mat& points2_mat = *((Mat*)points2_mat_nativeObj);
        Mat_to_vector_Point2f( points2_mat, points2 );
        Mat& mask = *((Mat*)mask_nativeObj);
        ::Mat _retval_ = cv::findFundamentalMat( points1, points2, (int)method, (double)ransacReprojThreshold, (double)confidence, mask );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findFundamentalMat_13 (JNIEnv*, jclass, jlong, jlong, jint, jdouble, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findFundamentalMat_13
  (JNIEnv* env, jclass , jlong points1_mat_nativeObj, jlong points2_mat_nativeObj, jint method, jdouble ransacReprojThreshold, jdouble confidence)
{
    static const char method_name[] = "calib3d::findFundamentalMat_13()";
    try {
        LOGD("%s", method_name);
        std::vector<Point2f> points1;
        Mat& points1_mat = *((Mat*)points1_mat_nativeObj);
        Mat_to_vector_Point2f( points1_mat, points1 );
        std::vector<Point2f> points2;
        Mat& points2_mat = *((Mat*)points2_mat_nativeObj);
        Mat_to_vector_Point2f( points2_mat, points2 );
        ::Mat _retval_ = cv::findFundamentalMat( points1, points2, (int)method, (double)ransacReprojThreshold, (double)confidence );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findFundamentalMat_14 (JNIEnv*, jclass, jlong, jlong, jint, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findFundamentalMat_14
  (JNIEnv* env, jclass , jlong points1_mat_nativeObj, jlong points2_mat_nativeObj, jint method, jdouble ransacReprojThreshold)
{
    static const char method_name[] = "calib3d::findFundamentalMat_14()";
    try {
        LOGD("%s", method_name);
        std::vector<Point2f> points1;
        Mat& points1_mat = *((Mat*)points1_mat_nativeObj);
        Mat_to_vector_Point2f( points1_mat, points1 );
        std::vector<Point2f> points2;
        Mat& points2_mat = *((Mat*)points2_mat_nativeObj);
        Mat_to_vector_Point2f( points2_mat, points2 );
        ::Mat _retval_ = cv::findFundamentalMat( points1, points2, (int)method, (double)ransacReprojThreshold );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findFundamentalMat_15 (JNIEnv*, jclass, jlong, jlong, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findFundamentalMat_15
  (JNIEnv* env, jclass , jlong points1_mat_nativeObj, jlong points2_mat_nativeObj, jint method)
{
    static const char method_name[] = "calib3d::findFundamentalMat_15()";
    try {
        LOGD("%s", method_name);
        std::vector<Point2f> points1;
        Mat& points1_mat = *((Mat*)points1_mat_nativeObj);
        Mat_to_vector_Point2f( points1_mat, points1 );
        std::vector<Point2f> points2;
        Mat& points2_mat = *((Mat*)points2_mat_nativeObj);
        Mat_to_vector_Point2f( points2_mat, points2 );
        ::Mat _retval_ = cv::findFundamentalMat( points1, points2, (int)method );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findFundamentalMat_16 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findFundamentalMat_16
  (JNIEnv* env, jclass , jlong points1_mat_nativeObj, jlong points2_mat_nativeObj)
{
    static const char method_name[] = "calib3d::findFundamentalMat_16()";
    try {
        LOGD("%s", method_name);
        std::vector<Point2f> points1;
        Mat& points1_mat = *((Mat*)points1_mat_nativeObj);
        Mat_to_vector_Point2f( points1_mat, points1 );
        std::vector<Point2f> points2;
        Mat& points2_mat = *((Mat*)points2_mat_nativeObj);
        Mat_to_vector_Point2f( points2_mat, points2 );
        ::Mat _retval_ = cv::findFundamentalMat( points1, points2 );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Mat cv::findHomography(vector_Point2f srcPoints, vector_Point2f dstPoints, int method = 0, double ransacReprojThreshold = 3, Mat& mask = Mat(), int maxIters = 2000, double confidence = 0.995)
//



JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findHomography_10 (JNIEnv*, jclass, jlong, jlong, jint, jdouble, jlong, jint, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findHomography_10
  (JNIEnv* env, jclass , jlong srcPoints_mat_nativeObj, jlong dstPoints_mat_nativeObj, jint method, jdouble ransacReprojThreshold, jlong mask_nativeObj, jint maxIters, jdouble confidence)
{
    static const char method_name[] = "calib3d::findHomography_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Point2f> srcPoints;
        Mat& srcPoints_mat = *((Mat*)srcPoints_mat_nativeObj);
        Mat_to_vector_Point2f( srcPoints_mat, srcPoints );
        std::vector<Point2f> dstPoints;
        Mat& dstPoints_mat = *((Mat*)dstPoints_mat_nativeObj);
        Mat_to_vector_Point2f( dstPoints_mat, dstPoints );
        Mat& mask = *((Mat*)mask_nativeObj);
        ::Mat _retval_ = cv::findHomography( srcPoints, dstPoints, (int)method, (double)ransacReprojThreshold, mask, (int)maxIters, (double)confidence );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findHomography_11 (JNIEnv*, jclass, jlong, jlong, jint, jdouble, jlong, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findHomography_11
  (JNIEnv* env, jclass , jlong srcPoints_mat_nativeObj, jlong dstPoints_mat_nativeObj, jint method, jdouble ransacReprojThreshold, jlong mask_nativeObj, jint maxIters)
{
    static const char method_name[] = "calib3d::findHomography_11()";
    try {
        LOGD("%s", method_name);
        std::vector<Point2f> srcPoints;
        Mat& srcPoints_mat = *((Mat*)srcPoints_mat_nativeObj);
        Mat_to_vector_Point2f( srcPoints_mat, srcPoints );
        std::vector<Point2f> dstPoints;
        Mat& dstPoints_mat = *((Mat*)dstPoints_mat_nativeObj);
        Mat_to_vector_Point2f( dstPoints_mat, dstPoints );
        Mat& mask = *((Mat*)mask_nativeObj);
        ::Mat _retval_ = cv::findHomography( srcPoints, dstPoints, (int)method, (double)ransacReprojThreshold, mask, (int)maxIters );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findHomography_12 (JNIEnv*, jclass, jlong, jlong, jint, jdouble, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findHomography_12
  (JNIEnv* env, jclass , jlong srcPoints_mat_nativeObj, jlong dstPoints_mat_nativeObj, jint method, jdouble ransacReprojThreshold, jlong mask_nativeObj)
{
    static const char method_name[] = "calib3d::findHomography_12()";
    try {
        LOGD("%s", method_name);
        std::vector<Point2f> srcPoints;
        Mat& srcPoints_mat = *((Mat*)srcPoints_mat_nativeObj);
        Mat_to_vector_Point2f( srcPoints_mat, srcPoints );
        std::vector<Point2f> dstPoints;
        Mat& dstPoints_mat = *((Mat*)dstPoints_mat_nativeObj);
        Mat_to_vector_Point2f( dstPoints_mat, dstPoints );
        Mat& mask = *((Mat*)mask_nativeObj);
        ::Mat _retval_ = cv::findHomography( srcPoints, dstPoints, (int)method, (double)ransacReprojThreshold, mask );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findHomography_13 (JNIEnv*, jclass, jlong, jlong, jint, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findHomography_13
  (JNIEnv* env, jclass , jlong srcPoints_mat_nativeObj, jlong dstPoints_mat_nativeObj, jint method, jdouble ransacReprojThreshold)
{
    static const char method_name[] = "calib3d::findHomography_13()";
    try {
        LOGD("%s", method_name);
        std::vector<Point2f> srcPoints;
        Mat& srcPoints_mat = *((Mat*)srcPoints_mat_nativeObj);
        Mat_to_vector_Point2f( srcPoints_mat, srcPoints );
        std::vector<Point2f> dstPoints;
        Mat& dstPoints_mat = *((Mat*)dstPoints_mat_nativeObj);
        Mat_to_vector_Point2f( dstPoints_mat, dstPoints );
        ::Mat _retval_ = cv::findHomography( srcPoints, dstPoints, (int)method, (double)ransacReprojThreshold );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findHomography_14 (JNIEnv*, jclass, jlong, jlong, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findHomography_14
  (JNIEnv* env, jclass , jlong srcPoints_mat_nativeObj, jlong dstPoints_mat_nativeObj, jint method)
{
    static const char method_name[] = "calib3d::findHomography_14()";
    try {
        LOGD("%s", method_name);
        std::vector<Point2f> srcPoints;
        Mat& srcPoints_mat = *((Mat*)srcPoints_mat_nativeObj);
        Mat_to_vector_Point2f( srcPoints_mat, srcPoints );
        std::vector<Point2f> dstPoints;
        Mat& dstPoints_mat = *((Mat*)dstPoints_mat_nativeObj);
        Mat_to_vector_Point2f( dstPoints_mat, dstPoints );
        ::Mat _retval_ = cv::findHomography( srcPoints, dstPoints, (int)method );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findHomography_15 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_findHomography_15
  (JNIEnv* env, jclass , jlong srcPoints_mat_nativeObj, jlong dstPoints_mat_nativeObj)
{
    static const char method_name[] = "calib3d::findHomography_15()";
    try {
        LOGD("%s", method_name);
        std::vector<Point2f> srcPoints;
        Mat& srcPoints_mat = *((Mat*)srcPoints_mat_nativeObj);
        Mat_to_vector_Point2f( srcPoints_mat, srcPoints );
        std::vector<Point2f> dstPoints;
        Mat& dstPoints_mat = *((Mat*)dstPoints_mat_nativeObj);
        Mat_to_vector_Point2f( dstPoints_mat, dstPoints );
        ::Mat _retval_ = cv::findHomography( srcPoints, dstPoints );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Mat cv::getDefaultNewCameraMatrix(Mat cameraMatrix, Size imgsize = Size(), bool centerPrincipalPoint = false)
//



JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_getDefaultNewCameraMatrix_10 (JNIEnv*, jclass, jlong, jdouble, jdouble, jboolean);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_getDefaultNewCameraMatrix_10
  (JNIEnv* env, jclass , jlong cameraMatrix_nativeObj, jdouble imgsize_width, jdouble imgsize_height, jboolean centerPrincipalPoint)
{
    static const char method_name[] = "calib3d::getDefaultNewCameraMatrix_10()";
    try {
        LOGD("%s", method_name);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Size imgsize((int)imgsize_width, (int)imgsize_height);
        ::Mat _retval_ = cv::getDefaultNewCameraMatrix( cameraMatrix, imgsize, (bool)centerPrincipalPoint );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_getDefaultNewCameraMatrix_11 (JNIEnv*, jclass, jlong, jdouble, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_getDefaultNewCameraMatrix_11
  (JNIEnv* env, jclass , jlong cameraMatrix_nativeObj, jdouble imgsize_width, jdouble imgsize_height)
{
    static const char method_name[] = "calib3d::getDefaultNewCameraMatrix_11()";
    try {
        LOGD("%s", method_name);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Size imgsize((int)imgsize_width, (int)imgsize_height);
        ::Mat _retval_ = cv::getDefaultNewCameraMatrix( cameraMatrix, imgsize );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_getDefaultNewCameraMatrix_12 (JNIEnv*, jclass, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_getDefaultNewCameraMatrix_12
  (JNIEnv* env, jclass , jlong cameraMatrix_nativeObj)
{
    static const char method_name[] = "calib3d::getDefaultNewCameraMatrix_12()";
    try {
        LOGD("%s", method_name);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        ::Mat _retval_ = cv::getDefaultNewCameraMatrix( cameraMatrix );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Mat cv::getOptimalNewCameraMatrix(Mat cameraMatrix, Mat distCoeffs, Size imageSize, double alpha, Size newImgSize = Size(), Rect* validPixROI = 0, bool centerPrincipalPoint = false)
//



JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_getOptimalNewCameraMatrix_10 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdoubleArray, jboolean);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_getOptimalNewCameraMatrix_10
  (JNIEnv* env, jclass , jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jdouble alpha, jdouble newImgSize_width, jdouble newImgSize_height, jdoubleArray validPixROI_out, jboolean centerPrincipalPoint)
{
    static const char method_name[] = "calib3d::getOptimalNewCameraMatrix_10()";
    try {
        LOGD("%s", method_name);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Size newImgSize((int)newImgSize_width, (int)newImgSize_height);
        Rect validPixROI;
        ::Mat _retval_ = cv::getOptimalNewCameraMatrix( cameraMatrix, distCoeffs, imageSize, (double)alpha, newImgSize, &validPixROI, (bool)centerPrincipalPoint );
        jdouble tmp_validPixROI[4] = {(jdouble)validPixROI.x, (jdouble)validPixROI.y, (jdouble)validPixROI.width, (jdouble)validPixROI.height}; env->SetDoubleArrayRegion(validPixROI_out, 0, 4, tmp_validPixROI);
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_getOptimalNewCameraMatrix_11 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdoubleArray);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_getOptimalNewCameraMatrix_11
  (JNIEnv* env, jclass , jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jdouble alpha, jdouble newImgSize_width, jdouble newImgSize_height, jdoubleArray validPixROI_out)
{
    static const char method_name[] = "calib3d::getOptimalNewCameraMatrix_11()";
    try {
        LOGD("%s", method_name);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Size newImgSize((int)newImgSize_width, (int)newImgSize_height);
        Rect validPixROI;
        ::Mat _retval_ = cv::getOptimalNewCameraMatrix( cameraMatrix, distCoeffs, imageSize, (double)alpha, newImgSize, &validPixROI );
        jdouble tmp_validPixROI[4] = {(jdouble)validPixROI.x, (jdouble)validPixROI.y, (jdouble)validPixROI.width, (jdouble)validPixROI.height}; env->SetDoubleArrayRegion(validPixROI_out, 0, 4, tmp_validPixROI);
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_getOptimalNewCameraMatrix_12 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_getOptimalNewCameraMatrix_12
  (JNIEnv* env, jclass , jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jdouble alpha, jdouble newImgSize_width, jdouble newImgSize_height)
{
    static const char method_name[] = "calib3d::getOptimalNewCameraMatrix_12()";
    try {
        LOGD("%s", method_name);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Size newImgSize((int)newImgSize_width, (int)newImgSize_height);
        ::Mat _retval_ = cv::getOptimalNewCameraMatrix( cameraMatrix, distCoeffs, imageSize, (double)alpha, newImgSize );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_getOptimalNewCameraMatrix_13 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_getOptimalNewCameraMatrix_13
  (JNIEnv* env, jclass , jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jdouble alpha)
{
    static const char method_name[] = "calib3d::getOptimalNewCameraMatrix_13()";
    try {
        LOGD("%s", method_name);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        ::Mat _retval_ = cv::getOptimalNewCameraMatrix( cameraMatrix, distCoeffs, imageSize, (double)alpha );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Mat cv::initCameraMatrix2D(vector_vector_Point3f objectPoints, vector_vector_Point2f imagePoints, Size imageSize, double aspectRatio = 1.0)
//



JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_initCameraMatrix2D_10 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_initCameraMatrix2D_10
  (JNIEnv* env, jclass , jlong objectPoints_mat_nativeObj, jlong imagePoints_mat_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jdouble aspectRatio)
{
    static const char method_name[] = "calib3d::initCameraMatrix2D_10()";
    try {
        LOGD("%s", method_name);
        std::vector< std::vector<Point3f> > objectPoints;
        Mat& objectPoints_mat = *((Mat*)objectPoints_mat_nativeObj);
        Mat_to_vector_vector_Point3f( objectPoints_mat, objectPoints );
        std::vector< std::vector<Point2f> > imagePoints;
        Mat& imagePoints_mat = *((Mat*)imagePoints_mat_nativeObj);
        Mat_to_vector_vector_Point2f( imagePoints_mat, imagePoints );
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        ::Mat _retval_ = cv::initCameraMatrix2D( objectPoints, imagePoints, imageSize, (double)aspectRatio );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_initCameraMatrix2D_11 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_calib3d_Calib3d_initCameraMatrix2D_11
  (JNIEnv* env, jclass , jlong objectPoints_mat_nativeObj, jlong imagePoints_mat_nativeObj, jdouble imageSize_width, jdouble imageSize_height)
{
    static const char method_name[] = "calib3d::initCameraMatrix2D_11()";
    try {
        LOGD("%s", method_name);
        std::vector< std::vector<Point3f> > objectPoints;
        Mat& objectPoints_mat = *((Mat*)objectPoints_mat_nativeObj);
        Mat_to_vector_vector_Point3f( objectPoints_mat, objectPoints );
        std::vector< std::vector<Point2f> > imagePoints;
        Mat& imagePoints_mat = *((Mat*)imagePoints_mat_nativeObj);
        Mat_to_vector_vector_Point2f( imagePoints_mat, imagePoints );
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        ::Mat _retval_ = cv::initCameraMatrix2D( objectPoints, imagePoints, imageSize );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Rect cv::getValidDisparityROI(Rect roi1, Rect roi2, int minDisparity, int numberOfDisparities, int blockSize)
//



JNIEXPORT jdoubleArray JNICALL Java_org_opencv_calib3d_Calib3d_getValidDisparityROI_10 (JNIEnv*, jclass, jint, jint, jint, jint, jint, jint, jint, jint, jint, jint, jint);

JNIEXPORT jdoubleArray JNICALL Java_org_opencv_calib3d_Calib3d_getValidDisparityROI_10
  (JNIEnv* env, jclass , jint roi1_x, jint roi1_y, jint roi1_width, jint roi1_height, jint roi2_x, jint roi2_y, jint roi2_width, jint roi2_height, jint minDisparity, jint numberOfDisparities, jint blockSize)
{
    static const char method_name[] = "calib3d::getValidDisparityROI_10()";
    try {
        LOGD("%s", method_name);
        Rect roi1(roi1_x, roi1_y, roi1_width, roi1_height);
        Rect roi2(roi2_x, roi2_y, roi2_width, roi2_height);
        Rect _retval_ = cv::getValidDisparityROI( roi1, roi2, (int)minDisparity, (int)numberOfDisparities, (int)blockSize );
        jdoubleArray _da_retval_ = env->NewDoubleArray(4);  jdouble _tmp_retval_[4] = {(jdouble)_retval_.x, (jdouble)_retval_.y, (jdouble)_retval_.width, (jdouble)_retval_.height}; env->SetDoubleArrayRegion(_da_retval_, 0, 4, _tmp_retval_);
        return _da_retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Scalar cv::estimateChessboardSharpness(Mat image, Size patternSize, Mat corners, float rise_distance = 0.8F, bool vertical = false, Mat& sharpness = Mat())
//



JNIEXPORT jdoubleArray JNICALL Java_org_opencv_calib3d_Calib3d_estimateChessboardSharpness_10 (JNIEnv*, jclass, jlong, jdouble, jdouble, jlong, jfloat, jboolean, jlong);

JNIEXPORT jdoubleArray JNICALL Java_org_opencv_calib3d_Calib3d_estimateChessboardSharpness_10
  (JNIEnv* env, jclass , jlong image_nativeObj, jdouble patternSize_width, jdouble patternSize_height, jlong corners_nativeObj, jfloat rise_distance, jboolean vertical, jlong sharpness_nativeObj)
{
    static const char method_name[] = "calib3d::estimateChessboardSharpness_10()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Size patternSize((int)patternSize_width, (int)patternSize_height);
        Mat& corners = *((Mat*)corners_nativeObj);
        Mat& sharpness = *((Mat*)sharpness_nativeObj);
        Scalar _retval_ = cv::estimateChessboardSharpness( image, patternSize, corners, (float)rise_distance, (bool)vertical, sharpness );
        jdoubleArray _da_retval_ = env->NewDoubleArray(4);  jdouble _tmp_retval_[4] = {(jdouble)_retval_.val[0], (jdouble)_retval_.val[1], (jdouble)_retval_.val[2], (jdouble)_retval_.val[3]}; env->SetDoubleArrayRegion(_da_retval_, 0, 4, _tmp_retval_);
        return _da_retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jdoubleArray JNICALL Java_org_opencv_calib3d_Calib3d_estimateChessboardSharpness_11 (JNIEnv*, jclass, jlong, jdouble, jdouble, jlong, jfloat, jboolean);

JNIEXPORT jdoubleArray JNICALL Java_org_opencv_calib3d_Calib3d_estimateChessboardSharpness_11
  (JNIEnv* env, jclass , jlong image_nativeObj, jdouble patternSize_width, jdouble patternSize_height, jlong corners_nativeObj, jfloat rise_distance, jboolean vertical)
{
    static const char method_name[] = "calib3d::estimateChessboardSharpness_11()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Size patternSize((int)patternSize_width, (int)patternSize_height);
        Mat& corners = *((Mat*)corners_nativeObj);
        Scalar _retval_ = cv::estimateChessboardSharpness( image, patternSize, corners, (float)rise_distance, (bool)vertical );
        jdoubleArray _da_retval_ = env->NewDoubleArray(4);  jdouble _tmp_retval_[4] = {(jdouble)_retval_.val[0], (jdouble)_retval_.val[1], (jdouble)_retval_.val[2], (jdouble)_retval_.val[3]}; env->SetDoubleArrayRegion(_da_retval_, 0, 4, _tmp_retval_);
        return _da_retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jdoubleArray JNICALL Java_org_opencv_calib3d_Calib3d_estimateChessboardSharpness_12 (JNIEnv*, jclass, jlong, jdouble, jdouble, jlong, jfloat);

JNIEXPORT jdoubleArray JNICALL Java_org_opencv_calib3d_Calib3d_estimateChessboardSharpness_12
  (JNIEnv* env, jclass , jlong image_nativeObj, jdouble patternSize_width, jdouble patternSize_height, jlong corners_nativeObj, jfloat rise_distance)
{
    static const char method_name[] = "calib3d::estimateChessboardSharpness_12()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Size patternSize((int)patternSize_width, (int)patternSize_height);
        Mat& corners = *((Mat*)corners_nativeObj);
        Scalar _retval_ = cv::estimateChessboardSharpness( image, patternSize, corners, (float)rise_distance );
        jdoubleArray _da_retval_ = env->NewDoubleArray(4);  jdouble _tmp_retval_[4] = {(jdouble)_retval_.val[0], (jdouble)_retval_.val[1], (jdouble)_retval_.val[2], (jdouble)_retval_.val[3]}; env->SetDoubleArrayRegion(_da_retval_, 0, 4, _tmp_retval_);
        return _da_retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jdoubleArray JNICALL Java_org_opencv_calib3d_Calib3d_estimateChessboardSharpness_13 (JNIEnv*, jclass, jlong, jdouble, jdouble, jlong);

JNIEXPORT jdoubleArray JNICALL Java_org_opencv_calib3d_Calib3d_estimateChessboardSharpness_13
  (JNIEnv* env, jclass , jlong image_nativeObj, jdouble patternSize_width, jdouble patternSize_height, jlong corners_nativeObj)
{
    static const char method_name[] = "calib3d::estimateChessboardSharpness_13()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Size patternSize((int)patternSize_width, (int)patternSize_height);
        Mat& corners = *((Mat*)corners_nativeObj);
        Scalar _retval_ = cv::estimateChessboardSharpness( image, patternSize, corners );
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
//  Vec3d cv::RQDecomp3x3(Mat src, Mat& mtxR, Mat& mtxQ, Mat& Qx = Mat(), Mat& Qy = Mat(), Mat& Qz = Mat())
//



JNIEXPORT jdoubleArray JNICALL Java_org_opencv_calib3d_Calib3d_RQDecomp3x3_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT jdoubleArray JNICALL Java_org_opencv_calib3d_Calib3d_RQDecomp3x3_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong mtxR_nativeObj, jlong mtxQ_nativeObj, jlong Qx_nativeObj, jlong Qy_nativeObj, jlong Qz_nativeObj)
{
    static const char method_name[] = "calib3d::RQDecomp3x3_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& mtxR = *((Mat*)mtxR_nativeObj);
        Mat& mtxQ = *((Mat*)mtxQ_nativeObj);
        Mat& Qx = *((Mat*)Qx_nativeObj);
        Mat& Qy = *((Mat*)Qy_nativeObj);
        Mat& Qz = *((Mat*)Qz_nativeObj);
        Vec3d _retval_ = cv::RQDecomp3x3( src, mtxR, mtxQ, Qx, Qy, Qz );
        jdoubleArray _da_retval_ = env->NewDoubleArray(3);  jdouble _tmp_retval_[3] = {(jdouble)_retval_.val[0], (jdouble)_retval_.val[1], (jdouble)_retval_.val[2]}; env->SetDoubleArrayRegion(_da_retval_, 0, 3, _tmp_retval_);
        return _da_retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jdoubleArray JNICALL Java_org_opencv_calib3d_Calib3d_RQDecomp3x3_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT jdoubleArray JNICALL Java_org_opencv_calib3d_Calib3d_RQDecomp3x3_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong mtxR_nativeObj, jlong mtxQ_nativeObj, jlong Qx_nativeObj, jlong Qy_nativeObj)
{
    static const char method_name[] = "calib3d::RQDecomp3x3_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& mtxR = *((Mat*)mtxR_nativeObj);
        Mat& mtxQ = *((Mat*)mtxQ_nativeObj);
        Mat& Qx = *((Mat*)Qx_nativeObj);
        Mat& Qy = *((Mat*)Qy_nativeObj);
        Vec3d _retval_ = cv::RQDecomp3x3( src, mtxR, mtxQ, Qx, Qy );
        jdoubleArray _da_retval_ = env->NewDoubleArray(3);  jdouble _tmp_retval_[3] = {(jdouble)_retval_.val[0], (jdouble)_retval_.val[1], (jdouble)_retval_.val[2]}; env->SetDoubleArrayRegion(_da_retval_, 0, 3, _tmp_retval_);
        return _da_retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jdoubleArray JNICALL Java_org_opencv_calib3d_Calib3d_RQDecomp3x3_12 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT jdoubleArray JNICALL Java_org_opencv_calib3d_Calib3d_RQDecomp3x3_12
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong mtxR_nativeObj, jlong mtxQ_nativeObj, jlong Qx_nativeObj)
{
    static const char method_name[] = "calib3d::RQDecomp3x3_12()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& mtxR = *((Mat*)mtxR_nativeObj);
        Mat& mtxQ = *((Mat*)mtxQ_nativeObj);
        Mat& Qx = *((Mat*)Qx_nativeObj);
        Vec3d _retval_ = cv::RQDecomp3x3( src, mtxR, mtxQ, Qx );
        jdoubleArray _da_retval_ = env->NewDoubleArray(3);  jdouble _tmp_retval_[3] = {(jdouble)_retval_.val[0], (jdouble)_retval_.val[1], (jdouble)_retval_.val[2]}; env->SetDoubleArrayRegion(_da_retval_, 0, 3, _tmp_retval_);
        return _da_retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jdoubleArray JNICALL Java_org_opencv_calib3d_Calib3d_RQDecomp3x3_13 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT jdoubleArray JNICALL Java_org_opencv_calib3d_Calib3d_RQDecomp3x3_13
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong mtxR_nativeObj, jlong mtxQ_nativeObj)
{
    static const char method_name[] = "calib3d::RQDecomp3x3_13()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& mtxR = *((Mat*)mtxR_nativeObj);
        Mat& mtxQ = *((Mat*)mtxQ_nativeObj);
        Vec3d _retval_ = cv::RQDecomp3x3( src, mtxR, mtxQ );
        jdoubleArray _da_retval_ = env->NewDoubleArray(3);  jdouble _tmp_retval_[3] = {(jdouble)_retval_.val[0], (jdouble)_retval_.val[1], (jdouble)_retval_.val[2]}; env->SetDoubleArrayRegion(_da_retval_, 0, 3, _tmp_retval_);
        return _da_retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  bool cv::checkChessboard(Mat img, Size size)
//



JNIEXPORT jboolean JNICALL Java_org_opencv_calib3d_Calib3d_checkChessboard_10 (JNIEnv*, jclass, jlong, jdouble, jdouble);

JNIEXPORT jboolean JNICALL Java_org_opencv_calib3d_Calib3d_checkChessboard_10
  (JNIEnv* env, jclass , jlong img_nativeObj, jdouble size_width, jdouble size_height)
{
    static const char method_name[] = "calib3d::checkChessboard_10()";
    try {
        LOGD("%s", method_name);
        Mat& img = *((Mat*)img_nativeObj);
        Size size((int)size_width, (int)size_height);
        return cv::checkChessboard( img, size );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  bool cv::find4QuadCornerSubpix(Mat img, Mat& corners, Size region_size)
//



JNIEXPORT jboolean JNICALL Java_org_opencv_calib3d_Calib3d_find4QuadCornerSubpix_10 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble);

JNIEXPORT jboolean JNICALL Java_org_opencv_calib3d_Calib3d_find4QuadCornerSubpix_10
  (JNIEnv* env, jclass , jlong img_nativeObj, jlong corners_nativeObj, jdouble region_size_width, jdouble region_size_height)
{
    static const char method_name[] = "calib3d::find4QuadCornerSubpix_10()";
    try {
        LOGD("%s", method_name);
        Mat& img = *((Mat*)img_nativeObj);
        Mat& corners = *((Mat*)corners_nativeObj);
        Size region_size((int)region_size_width, (int)region_size_height);
        return cv::find4QuadCornerSubpix( img, corners, region_size );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  bool cv::findChessboardCorners(Mat image, Size patternSize, vector_Point2f& corners, int flags = CALIB_CB_ADAPTIVE_THRESH + CALIB_CB_NORMALIZE_IMAGE)
//



JNIEXPORT jboolean JNICALL Java_org_opencv_calib3d_Calib3d_findChessboardCorners_10 (JNIEnv*, jclass, jlong, jdouble, jdouble, jlong, jint);

JNIEXPORT jboolean JNICALL Java_org_opencv_calib3d_Calib3d_findChessboardCorners_10
  (JNIEnv* env, jclass , jlong image_nativeObj, jdouble patternSize_width, jdouble patternSize_height, jlong corners_mat_nativeObj, jint flags)
{
    static const char method_name[] = "calib3d::findChessboardCorners_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Point2f> corners;
        Mat& corners_mat = *((Mat*)corners_mat_nativeObj);
        Mat& image = *((Mat*)image_nativeObj);
        Size patternSize((int)patternSize_width, (int)patternSize_height);
        bool _retval_ = cv::findChessboardCorners( image, patternSize, corners, (int)flags );
        vector_Point2f_to_Mat( corners, corners_mat );
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jboolean JNICALL Java_org_opencv_calib3d_Calib3d_findChessboardCorners_11 (JNIEnv*, jclass, jlong, jdouble, jdouble, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_calib3d_Calib3d_findChessboardCorners_11
  (JNIEnv* env, jclass , jlong image_nativeObj, jdouble patternSize_width, jdouble patternSize_height, jlong corners_mat_nativeObj)
{
    static const char method_name[] = "calib3d::findChessboardCorners_11()";
    try {
        LOGD("%s", method_name);
        std::vector<Point2f> corners;
        Mat& corners_mat = *((Mat*)corners_mat_nativeObj);
        Mat& image = *((Mat*)image_nativeObj);
        Size patternSize((int)patternSize_width, (int)patternSize_height);
        bool _retval_ = cv::findChessboardCorners( image, patternSize, corners );
        vector_Point2f_to_Mat( corners, corners_mat );
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  bool cv::findChessboardCornersSB(Mat image, Size patternSize, Mat& corners, int flags, Mat& meta)
//



JNIEXPORT jboolean JNICALL Java_org_opencv_calib3d_Calib3d_findChessboardCornersSBWithMeta_10 (JNIEnv*, jclass, jlong, jdouble, jdouble, jlong, jint, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_calib3d_Calib3d_findChessboardCornersSBWithMeta_10
  (JNIEnv* env, jclass , jlong image_nativeObj, jdouble patternSize_width, jdouble patternSize_height, jlong corners_nativeObj, jint flags, jlong meta_nativeObj)
{
    static const char method_name[] = "calib3d::findChessboardCornersSBWithMeta_10()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Size patternSize((int)patternSize_width, (int)patternSize_height);
        Mat& corners = *((Mat*)corners_nativeObj);
        Mat& meta = *((Mat*)meta_nativeObj);
        return cv::findChessboardCornersSB( image, patternSize, corners, (int)flags, meta );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  bool cv::findChessboardCornersSB(Mat image, Size patternSize, Mat& corners, int flags = 0)
//



JNIEXPORT jboolean JNICALL Java_org_opencv_calib3d_Calib3d_findChessboardCornersSB_10 (JNIEnv*, jclass, jlong, jdouble, jdouble, jlong, jint);

JNIEXPORT jboolean JNICALL Java_org_opencv_calib3d_Calib3d_findChessboardCornersSB_10
  (JNIEnv* env, jclass , jlong image_nativeObj, jdouble patternSize_width, jdouble patternSize_height, jlong corners_nativeObj, jint flags)
{
    static const char method_name[] = "calib3d::findChessboardCornersSB_10()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Size patternSize((int)patternSize_width, (int)patternSize_height);
        Mat& corners = *((Mat*)corners_nativeObj);
        return cv::findChessboardCornersSB( image, patternSize, corners, (int)flags );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jboolean JNICALL Java_org_opencv_calib3d_Calib3d_findChessboardCornersSB_11 (JNIEnv*, jclass, jlong, jdouble, jdouble, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_calib3d_Calib3d_findChessboardCornersSB_11
  (JNIEnv* env, jclass , jlong image_nativeObj, jdouble patternSize_width, jdouble patternSize_height, jlong corners_nativeObj)
{
    static const char method_name[] = "calib3d::findChessboardCornersSB_11()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Size patternSize((int)patternSize_width, (int)patternSize_height);
        Mat& corners = *((Mat*)corners_nativeObj);
        return cv::findChessboardCornersSB( image, patternSize, corners );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  bool cv::findCirclesGrid(Mat image, Size patternSize, Mat& centers, int flags = CALIB_CB_SYMMETRIC_GRID, Ptr_FeatureDetector blobDetector = SimpleBlobDetector::create())
//



JNIEXPORT jboolean JNICALL Java_org_opencv_calib3d_Calib3d_findCirclesGrid_10 (JNIEnv*, jclass, jlong, jdouble, jdouble, jlong, jint);

JNIEXPORT jboolean JNICALL Java_org_opencv_calib3d_Calib3d_findCirclesGrid_10
  (JNIEnv* env, jclass , jlong image_nativeObj, jdouble patternSize_width, jdouble patternSize_height, jlong centers_nativeObj, jint flags)
{
    static const char method_name[] = "calib3d::findCirclesGrid_10()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Size patternSize((int)patternSize_width, (int)patternSize_height);
        Mat& centers = *((Mat*)centers_nativeObj);
        return cv::findCirclesGrid( image, patternSize, centers, (int)flags, SimpleBlobDetector::create() );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jboolean JNICALL Java_org_opencv_calib3d_Calib3d_findCirclesGrid_12 (JNIEnv*, jclass, jlong, jdouble, jdouble, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_calib3d_Calib3d_findCirclesGrid_12
  (JNIEnv* env, jclass , jlong image_nativeObj, jdouble patternSize_width, jdouble patternSize_height, jlong centers_nativeObj)
{
    static const char method_name[] = "calib3d::findCirclesGrid_12()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Size patternSize((int)patternSize_width, (int)patternSize_height);
        Mat& centers = *((Mat*)centers_nativeObj);
        return cv::findCirclesGrid( image, patternSize, centers );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  bool cv::solvePnP(vector_Point3f objectPoints, vector_Point2f imagePoints, Mat cameraMatrix, vector_double distCoeffs, Mat& rvec, Mat& tvec, bool useExtrinsicGuess = false, int flags = SOLVEPNP_ITERATIVE)
//



JNIEXPORT jboolean JNICALL Java_org_opencv_calib3d_Calib3d_solvePnP_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jboolean, jint);

JNIEXPORT jboolean JNICALL Java_org_opencv_calib3d_Calib3d_solvePnP_10
  (JNIEnv* env, jclass , jlong objectPoints_mat_nativeObj, jlong imagePoints_mat_nativeObj, jlong cameraMatrix_nativeObj, jlong distCoeffs_mat_nativeObj, jlong rvec_nativeObj, jlong tvec_nativeObj, jboolean useExtrinsicGuess, jint flags)
{
    static const char method_name[] = "calib3d::solvePnP_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Point3f> objectPoints;
        Mat& objectPoints_mat = *((Mat*)objectPoints_mat_nativeObj);
        Mat_to_vector_Point3f( objectPoints_mat, objectPoints );
        std::vector<Point2f> imagePoints;
        Mat& imagePoints_mat = *((Mat*)imagePoints_mat_nativeObj);
        Mat_to_vector_Point2f( imagePoints_mat, imagePoints );
        std::vector<double> distCoeffs;
        Mat& distCoeffs_mat = *((Mat*)distCoeffs_mat_nativeObj);
        Mat_to_vector_double( distCoeffs_mat, distCoeffs );
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& rvec = *((Mat*)rvec_nativeObj);
        Mat& tvec = *((Mat*)tvec_nativeObj);
        return cv::solvePnP( objectPoints, imagePoints, cameraMatrix, distCoeffs, rvec, tvec, (bool)useExtrinsicGuess, (int)flags );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jboolean JNICALL Java_org_opencv_calib3d_Calib3d_solvePnP_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jboolean);

JNIEXPORT jboolean JNICALL Java_org_opencv_calib3d_Calib3d_solvePnP_11
  (JNIEnv* env, jclass , jlong objectPoints_mat_nativeObj, jlong imagePoints_mat_nativeObj, jlong cameraMatrix_nativeObj, jlong distCoeffs_mat_nativeObj, jlong rvec_nativeObj, jlong tvec_nativeObj, jboolean useExtrinsicGuess)
{
    static const char method_name[] = "calib3d::solvePnP_11()";
    try {
        LOGD("%s", method_name);
        std::vector<Point3f> objectPoints;
        Mat& objectPoints_mat = *((Mat*)objectPoints_mat_nativeObj);
        Mat_to_vector_Point3f( objectPoints_mat, objectPoints );
        std::vector<Point2f> imagePoints;
        Mat& imagePoints_mat = *((Mat*)imagePoints_mat_nativeObj);
        Mat_to_vector_Point2f( imagePoints_mat, imagePoints );
        std::vector<double> distCoeffs;
        Mat& distCoeffs_mat = *((Mat*)distCoeffs_mat_nativeObj);
        Mat_to_vector_double( distCoeffs_mat, distCoeffs );
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& rvec = *((Mat*)rvec_nativeObj);
        Mat& tvec = *((Mat*)tvec_nativeObj);
        return cv::solvePnP( objectPoints, imagePoints, cameraMatrix, distCoeffs, rvec, tvec, (bool)useExtrinsicGuess );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jboolean JNICALL Java_org_opencv_calib3d_Calib3d_solvePnP_12 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_calib3d_Calib3d_solvePnP_12
  (JNIEnv* env, jclass , jlong objectPoints_mat_nativeObj, jlong imagePoints_mat_nativeObj, jlong cameraMatrix_nativeObj, jlong distCoeffs_mat_nativeObj, jlong rvec_nativeObj, jlong tvec_nativeObj)
{
    static const char method_name[] = "calib3d::solvePnP_12()";
    try {
        LOGD("%s", method_name);
        std::vector<Point3f> objectPoints;
        Mat& objectPoints_mat = *((Mat*)objectPoints_mat_nativeObj);
        Mat_to_vector_Point3f( objectPoints_mat, objectPoints );
        std::vector<Point2f> imagePoints;
        Mat& imagePoints_mat = *((Mat*)imagePoints_mat_nativeObj);
        Mat_to_vector_Point2f( imagePoints_mat, imagePoints );
        std::vector<double> distCoeffs;
        Mat& distCoeffs_mat = *((Mat*)distCoeffs_mat_nativeObj);
        Mat_to_vector_double( distCoeffs_mat, distCoeffs );
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& rvec = *((Mat*)rvec_nativeObj);
        Mat& tvec = *((Mat*)tvec_nativeObj);
        return cv::solvePnP( objectPoints, imagePoints, cameraMatrix, distCoeffs, rvec, tvec );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  bool cv::solvePnPRansac(vector_Point3f objectPoints, vector_Point2f imagePoints, Mat cameraMatrix, vector_double distCoeffs, Mat& rvec, Mat& tvec, bool useExtrinsicGuess = false, int iterationsCount = 100, float reprojectionError = 8.0, double confidence = 0.99, Mat& inliers = Mat(), int flags = SOLVEPNP_ITERATIVE)
//



JNIEXPORT jboolean JNICALL Java_org_opencv_calib3d_Calib3d_solvePnPRansac_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jboolean, jint, jfloat, jdouble, jlong, jint);

JNIEXPORT jboolean JNICALL Java_org_opencv_calib3d_Calib3d_solvePnPRansac_10
  (JNIEnv* env, jclass , jlong objectPoints_mat_nativeObj, jlong imagePoints_mat_nativeObj, jlong cameraMatrix_nativeObj, jlong distCoeffs_mat_nativeObj, jlong rvec_nativeObj, jlong tvec_nativeObj, jboolean useExtrinsicGuess, jint iterationsCount, jfloat reprojectionError, jdouble confidence, jlong inliers_nativeObj, jint flags)
{
    static const char method_name[] = "calib3d::solvePnPRansac_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Point3f> objectPoints;
        Mat& objectPoints_mat = *((Mat*)objectPoints_mat_nativeObj);
        Mat_to_vector_Point3f( objectPoints_mat, objectPoints );
        std::vector<Point2f> imagePoints;
        Mat& imagePoints_mat = *((Mat*)imagePoints_mat_nativeObj);
        Mat_to_vector_Point2f( imagePoints_mat, imagePoints );
        std::vector<double> distCoeffs;
        Mat& distCoeffs_mat = *((Mat*)distCoeffs_mat_nativeObj);
        Mat_to_vector_double( distCoeffs_mat, distCoeffs );
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& rvec = *((Mat*)rvec_nativeObj);
        Mat& tvec = *((Mat*)tvec_nativeObj);
        Mat& inliers = *((Mat*)inliers_nativeObj);
        return cv::solvePnPRansac( objectPoints, imagePoints, cameraMatrix, distCoeffs, rvec, tvec, (bool)useExtrinsicGuess, (int)iterationsCount, (float)reprojectionError, (double)confidence, inliers, (int)flags );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jboolean JNICALL Java_org_opencv_calib3d_Calib3d_solvePnPRansac_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jboolean, jint, jfloat, jdouble, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_calib3d_Calib3d_solvePnPRansac_11
  (JNIEnv* env, jclass , jlong objectPoints_mat_nativeObj, jlong imagePoints_mat_nativeObj, jlong cameraMatrix_nativeObj, jlong distCoeffs_mat_nativeObj, jlong rvec_nativeObj, jlong tvec_nativeObj, jboolean useExtrinsicGuess, jint iterationsCount, jfloat reprojectionError, jdouble confidence, jlong inliers_nativeObj)
{
    static const char method_name[] = "calib3d::solvePnPRansac_11()";
    try {
        LOGD("%s", method_name);
        std::vector<Point3f> objectPoints;
        Mat& objectPoints_mat = *((Mat*)objectPoints_mat_nativeObj);
        Mat_to_vector_Point3f( objectPoints_mat, objectPoints );
        std::vector<Point2f> imagePoints;
        Mat& imagePoints_mat = *((Mat*)imagePoints_mat_nativeObj);
        Mat_to_vector_Point2f( imagePoints_mat, imagePoints );
        std::vector<double> distCoeffs;
        Mat& distCoeffs_mat = *((Mat*)distCoeffs_mat_nativeObj);
        Mat_to_vector_double( distCoeffs_mat, distCoeffs );
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& rvec = *((Mat*)rvec_nativeObj);
        Mat& tvec = *((Mat*)tvec_nativeObj);
        Mat& inliers = *((Mat*)inliers_nativeObj);
        return cv::solvePnPRansac( objectPoints, imagePoints, cameraMatrix, distCoeffs, rvec, tvec, (bool)useExtrinsicGuess, (int)iterationsCount, (float)reprojectionError, (double)confidence, inliers );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jboolean JNICALL Java_org_opencv_calib3d_Calib3d_solvePnPRansac_12 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jboolean, jint, jfloat, jdouble);

JNIEXPORT jboolean JNICALL Java_org_opencv_calib3d_Calib3d_solvePnPRansac_12
  (JNIEnv* env, jclass , jlong objectPoints_mat_nativeObj, jlong imagePoints_mat_nativeObj, jlong cameraMatrix_nativeObj, jlong distCoeffs_mat_nativeObj, jlong rvec_nativeObj, jlong tvec_nativeObj, jboolean useExtrinsicGuess, jint iterationsCount, jfloat reprojectionError, jdouble confidence)
{
    static const char method_name[] = "calib3d::solvePnPRansac_12()";
    try {
        LOGD("%s", method_name);
        std::vector<Point3f> objectPoints;
        Mat& objectPoints_mat = *((Mat*)objectPoints_mat_nativeObj);
        Mat_to_vector_Point3f( objectPoints_mat, objectPoints );
        std::vector<Point2f> imagePoints;
        Mat& imagePoints_mat = *((Mat*)imagePoints_mat_nativeObj);
        Mat_to_vector_Point2f( imagePoints_mat, imagePoints );
        std::vector<double> distCoeffs;
        Mat& distCoeffs_mat = *((Mat*)distCoeffs_mat_nativeObj);
        Mat_to_vector_double( distCoeffs_mat, distCoeffs );
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& rvec = *((Mat*)rvec_nativeObj);
        Mat& tvec = *((Mat*)tvec_nativeObj);
        return cv::solvePnPRansac( objectPoints, imagePoints, cameraMatrix, distCoeffs, rvec, tvec, (bool)useExtrinsicGuess, (int)iterationsCount, (float)reprojectionError, (double)confidence );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jboolean JNICALL Java_org_opencv_calib3d_Calib3d_solvePnPRansac_13 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jboolean, jint, jfloat);

JNIEXPORT jboolean JNICALL Java_org_opencv_calib3d_Calib3d_solvePnPRansac_13
  (JNIEnv* env, jclass , jlong objectPoints_mat_nativeObj, jlong imagePoints_mat_nativeObj, jlong cameraMatrix_nativeObj, jlong distCoeffs_mat_nativeObj, jlong rvec_nativeObj, jlong tvec_nativeObj, jboolean useExtrinsicGuess, jint iterationsCount, jfloat reprojectionError)
{
    static const char method_name[] = "calib3d::solvePnPRansac_13()";
    try {
        LOGD("%s", method_name);
        std::vector<Point3f> objectPoints;
        Mat& objectPoints_mat = *((Mat*)objectPoints_mat_nativeObj);
        Mat_to_vector_Point3f( objectPoints_mat, objectPoints );
        std::vector<Point2f> imagePoints;
        Mat& imagePoints_mat = *((Mat*)imagePoints_mat_nativeObj);
        Mat_to_vector_Point2f( imagePoints_mat, imagePoints );
        std::vector<double> distCoeffs;
        Mat& distCoeffs_mat = *((Mat*)distCoeffs_mat_nativeObj);
        Mat_to_vector_double( distCoeffs_mat, distCoeffs );
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& rvec = *((Mat*)rvec_nativeObj);
        Mat& tvec = *((Mat*)tvec_nativeObj);
        return cv::solvePnPRansac( objectPoints, imagePoints, cameraMatrix, distCoeffs, rvec, tvec, (bool)useExtrinsicGuess, (int)iterationsCount, (float)reprojectionError );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jboolean JNICALL Java_org_opencv_calib3d_Calib3d_solvePnPRansac_14 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jboolean, jint);

JNIEXPORT jboolean JNICALL Java_org_opencv_calib3d_Calib3d_solvePnPRansac_14
  (JNIEnv* env, jclass , jlong objectPoints_mat_nativeObj, jlong imagePoints_mat_nativeObj, jlong cameraMatrix_nativeObj, jlong distCoeffs_mat_nativeObj, jlong rvec_nativeObj, jlong tvec_nativeObj, jboolean useExtrinsicGuess, jint iterationsCount)
{
    static const char method_name[] = "calib3d::solvePnPRansac_14()";
    try {
        LOGD("%s", method_name);
        std::vector<Point3f> objectPoints;
        Mat& objectPoints_mat = *((Mat*)objectPoints_mat_nativeObj);
        Mat_to_vector_Point3f( objectPoints_mat, objectPoints );
        std::vector<Point2f> imagePoints;
        Mat& imagePoints_mat = *((Mat*)imagePoints_mat_nativeObj);
        Mat_to_vector_Point2f( imagePoints_mat, imagePoints );
        std::vector<double> distCoeffs;
        Mat& distCoeffs_mat = *((Mat*)distCoeffs_mat_nativeObj);
        Mat_to_vector_double( distCoeffs_mat, distCoeffs );
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& rvec = *((Mat*)rvec_nativeObj);
        Mat& tvec = *((Mat*)tvec_nativeObj);
        return cv::solvePnPRansac( objectPoints, imagePoints, cameraMatrix, distCoeffs, rvec, tvec, (bool)useExtrinsicGuess, (int)iterationsCount );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jboolean JNICALL Java_org_opencv_calib3d_Calib3d_solvePnPRansac_15 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jboolean);

JNIEXPORT jboolean JNICALL Java_org_opencv_calib3d_Calib3d_solvePnPRansac_15
  (JNIEnv* env, jclass , jlong objectPoints_mat_nativeObj, jlong imagePoints_mat_nativeObj, jlong cameraMatrix_nativeObj, jlong distCoeffs_mat_nativeObj, jlong rvec_nativeObj, jlong tvec_nativeObj, jboolean useExtrinsicGuess)
{
    static const char method_name[] = "calib3d::solvePnPRansac_15()";
    try {
        LOGD("%s", method_name);
        std::vector<Point3f> objectPoints;
        Mat& objectPoints_mat = *((Mat*)objectPoints_mat_nativeObj);
        Mat_to_vector_Point3f( objectPoints_mat, objectPoints );
        std::vector<Point2f> imagePoints;
        Mat& imagePoints_mat = *((Mat*)imagePoints_mat_nativeObj);
        Mat_to_vector_Point2f( imagePoints_mat, imagePoints );
        std::vector<double> distCoeffs;
        Mat& distCoeffs_mat = *((Mat*)distCoeffs_mat_nativeObj);
        Mat_to_vector_double( distCoeffs_mat, distCoeffs );
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& rvec = *((Mat*)rvec_nativeObj);
        Mat& tvec = *((Mat*)tvec_nativeObj);
        return cv::solvePnPRansac( objectPoints, imagePoints, cameraMatrix, distCoeffs, rvec, tvec, (bool)useExtrinsicGuess );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jboolean JNICALL Java_org_opencv_calib3d_Calib3d_solvePnPRansac_16 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_calib3d_Calib3d_solvePnPRansac_16
  (JNIEnv* env, jclass , jlong objectPoints_mat_nativeObj, jlong imagePoints_mat_nativeObj, jlong cameraMatrix_nativeObj, jlong distCoeffs_mat_nativeObj, jlong rvec_nativeObj, jlong tvec_nativeObj)
{
    static const char method_name[] = "calib3d::solvePnPRansac_16()";
    try {
        LOGD("%s", method_name);
        std::vector<Point3f> objectPoints;
        Mat& objectPoints_mat = *((Mat*)objectPoints_mat_nativeObj);
        Mat_to_vector_Point3f( objectPoints_mat, objectPoints );
        std::vector<Point2f> imagePoints;
        Mat& imagePoints_mat = *((Mat*)imagePoints_mat_nativeObj);
        Mat_to_vector_Point2f( imagePoints_mat, imagePoints );
        std::vector<double> distCoeffs;
        Mat& distCoeffs_mat = *((Mat*)distCoeffs_mat_nativeObj);
        Mat_to_vector_double( distCoeffs_mat, distCoeffs );
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& rvec = *((Mat*)rvec_nativeObj);
        Mat& tvec = *((Mat*)tvec_nativeObj);
        return cv::solvePnPRansac( objectPoints, imagePoints, cameraMatrix, distCoeffs, rvec, tvec );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  bool cv::stereoRectifyUncalibrated(Mat points1, Mat points2, Mat F, Size imgSize, Mat& H1, Mat& H2, double threshold = 5)
//



JNIEXPORT jboolean JNICALL Java_org_opencv_calib3d_Calib3d_stereoRectifyUncalibrated_10 (JNIEnv*, jclass, jlong, jlong, jlong, jdouble, jdouble, jlong, jlong, jdouble);

JNIEXPORT jboolean JNICALL Java_org_opencv_calib3d_Calib3d_stereoRectifyUncalibrated_10
  (JNIEnv* env, jclass , jlong points1_nativeObj, jlong points2_nativeObj, jlong F_nativeObj, jdouble imgSize_width, jdouble imgSize_height, jlong H1_nativeObj, jlong H2_nativeObj, jdouble threshold)
{
    static const char method_name[] = "calib3d::stereoRectifyUncalibrated_10()";
    try {
        LOGD("%s", method_name);
        Mat& points1 = *((Mat*)points1_nativeObj);
        Mat& points2 = *((Mat*)points2_nativeObj);
        Mat& F = *((Mat*)F_nativeObj);
        Size imgSize((int)imgSize_width, (int)imgSize_height);
        Mat& H1 = *((Mat*)H1_nativeObj);
        Mat& H2 = *((Mat*)H2_nativeObj);
        return cv::stereoRectifyUncalibrated( points1, points2, F, imgSize, H1, H2, (double)threshold );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jboolean JNICALL Java_org_opencv_calib3d_Calib3d_stereoRectifyUncalibrated_11 (JNIEnv*, jclass, jlong, jlong, jlong, jdouble, jdouble, jlong, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_calib3d_Calib3d_stereoRectifyUncalibrated_11
  (JNIEnv* env, jclass , jlong points1_nativeObj, jlong points2_nativeObj, jlong F_nativeObj, jdouble imgSize_width, jdouble imgSize_height, jlong H1_nativeObj, jlong H2_nativeObj)
{
    static const char method_name[] = "calib3d::stereoRectifyUncalibrated_11()";
    try {
        LOGD("%s", method_name);
        Mat& points1 = *((Mat*)points1_nativeObj);
        Mat& points2 = *((Mat*)points2_nativeObj);
        Mat& F = *((Mat*)F_nativeObj);
        Size imgSize((int)imgSize_width, (int)imgSize_height);
        Mat& H1 = *((Mat*)H1_nativeObj);
        Mat& H2 = *((Mat*)H2_nativeObj);
        return cv::stereoRectifyUncalibrated( points1, points2, F, imgSize, H1, H2 );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::calibrateCamera(vector_Mat objectPoints, vector_Mat imagePoints, Size imageSize, Mat& cameraMatrix, Mat& distCoeffs, vector_Mat& rvecs, vector_Mat& tvecs, Mat& stdDeviationsIntrinsics, Mat& stdDeviationsExtrinsics, Mat& perViewErrors, int flags = 0, TermCriteria criteria = TermCriteria( TermCriteria::COUNT + TermCriteria::EPS, 30, DBL_EPSILON))
//



JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_calibrateCameraExtended_10 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jint, jint, jint, jdouble);

JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_calibrateCameraExtended_10
  (JNIEnv* env, jclass , jlong objectPoints_mat_nativeObj, jlong imagePoints_mat_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong rvecs_mat_nativeObj, jlong tvecs_mat_nativeObj, jlong stdDeviationsIntrinsics_nativeObj, jlong stdDeviationsExtrinsics_nativeObj, jlong perViewErrors_nativeObj, jint flags, jint criteria_type, jint criteria_maxCount, jdouble criteria_epsilon)
{
    static const char method_name[] = "calib3d::calibrateCameraExtended_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> objectPoints;
        Mat& objectPoints_mat = *((Mat*)objectPoints_mat_nativeObj);
        Mat_to_vector_Mat( objectPoints_mat, objectPoints );
        std::vector<Mat> imagePoints;
        Mat& imagePoints_mat = *((Mat*)imagePoints_mat_nativeObj);
        Mat_to_vector_Mat( imagePoints_mat, imagePoints );
        std::vector<Mat> rvecs;
        Mat& rvecs_mat = *((Mat*)rvecs_mat_nativeObj);
        std::vector<Mat> tvecs;
        Mat& tvecs_mat = *((Mat*)tvecs_mat_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        Mat& stdDeviationsIntrinsics = *((Mat*)stdDeviationsIntrinsics_nativeObj);
        Mat& stdDeviationsExtrinsics = *((Mat*)stdDeviationsExtrinsics_nativeObj);
        Mat& perViewErrors = *((Mat*)perViewErrors_nativeObj);
        TermCriteria criteria(criteria_type, criteria_maxCount, criteria_epsilon);
        double _retval_ = cv::calibrateCamera( objectPoints, imagePoints, imageSize, cameraMatrix, distCoeffs, rvecs, tvecs, stdDeviationsIntrinsics, stdDeviationsExtrinsics, perViewErrors, (int)flags, criteria );
        vector_Mat_to_Mat( rvecs, rvecs_mat );
        vector_Mat_to_Mat( tvecs, tvecs_mat );
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_calibrateCameraExtended_11 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jint);

JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_calibrateCameraExtended_11
  (JNIEnv* env, jclass , jlong objectPoints_mat_nativeObj, jlong imagePoints_mat_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong rvecs_mat_nativeObj, jlong tvecs_mat_nativeObj, jlong stdDeviationsIntrinsics_nativeObj, jlong stdDeviationsExtrinsics_nativeObj, jlong perViewErrors_nativeObj, jint flags)
{
    static const char method_name[] = "calib3d::calibrateCameraExtended_11()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> objectPoints;
        Mat& objectPoints_mat = *((Mat*)objectPoints_mat_nativeObj);
        Mat_to_vector_Mat( objectPoints_mat, objectPoints );
        std::vector<Mat> imagePoints;
        Mat& imagePoints_mat = *((Mat*)imagePoints_mat_nativeObj);
        Mat_to_vector_Mat( imagePoints_mat, imagePoints );
        std::vector<Mat> rvecs;
        Mat& rvecs_mat = *((Mat*)rvecs_mat_nativeObj);
        std::vector<Mat> tvecs;
        Mat& tvecs_mat = *((Mat*)tvecs_mat_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        Mat& stdDeviationsIntrinsics = *((Mat*)stdDeviationsIntrinsics_nativeObj);
        Mat& stdDeviationsExtrinsics = *((Mat*)stdDeviationsExtrinsics_nativeObj);
        Mat& perViewErrors = *((Mat*)perViewErrors_nativeObj);
        double _retval_ = cv::calibrateCamera( objectPoints, imagePoints, imageSize, cameraMatrix, distCoeffs, rvecs, tvecs, stdDeviationsIntrinsics, stdDeviationsExtrinsics, perViewErrors, (int)flags );
        vector_Mat_to_Mat( rvecs, rvecs_mat );
        vector_Mat_to_Mat( tvecs, tvecs_mat );
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_calibrateCameraExtended_12 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jlong, jlong, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_calibrateCameraExtended_12
  (JNIEnv* env, jclass , jlong objectPoints_mat_nativeObj, jlong imagePoints_mat_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong rvecs_mat_nativeObj, jlong tvecs_mat_nativeObj, jlong stdDeviationsIntrinsics_nativeObj, jlong stdDeviationsExtrinsics_nativeObj, jlong perViewErrors_nativeObj)
{
    static const char method_name[] = "calib3d::calibrateCameraExtended_12()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> objectPoints;
        Mat& objectPoints_mat = *((Mat*)objectPoints_mat_nativeObj);
        Mat_to_vector_Mat( objectPoints_mat, objectPoints );
        std::vector<Mat> imagePoints;
        Mat& imagePoints_mat = *((Mat*)imagePoints_mat_nativeObj);
        Mat_to_vector_Mat( imagePoints_mat, imagePoints );
        std::vector<Mat> rvecs;
        Mat& rvecs_mat = *((Mat*)rvecs_mat_nativeObj);
        std::vector<Mat> tvecs;
        Mat& tvecs_mat = *((Mat*)tvecs_mat_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        Mat& stdDeviationsIntrinsics = *((Mat*)stdDeviationsIntrinsics_nativeObj);
        Mat& stdDeviationsExtrinsics = *((Mat*)stdDeviationsExtrinsics_nativeObj);
        Mat& perViewErrors = *((Mat*)perViewErrors_nativeObj);
        double _retval_ = cv::calibrateCamera( objectPoints, imagePoints, imageSize, cameraMatrix, distCoeffs, rvecs, tvecs, stdDeviationsIntrinsics, stdDeviationsExtrinsics, perViewErrors );
        vector_Mat_to_Mat( rvecs, rvecs_mat );
        vector_Mat_to_Mat( tvecs, tvecs_mat );
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::calibrateCamera(vector_Mat objectPoints, vector_Mat imagePoints, Size imageSize, Mat& cameraMatrix, Mat& distCoeffs, vector_Mat& rvecs, vector_Mat& tvecs, int flags = 0, TermCriteria criteria = TermCriteria( TermCriteria::COUNT + TermCriteria::EPS, 30, DBL_EPSILON))
//



JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_calibrateCamera_10 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jlong, jlong, jlong, jlong, jint, jint, jint, jdouble);

JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_calibrateCamera_10
  (JNIEnv* env, jclass , jlong objectPoints_mat_nativeObj, jlong imagePoints_mat_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong rvecs_mat_nativeObj, jlong tvecs_mat_nativeObj, jint flags, jint criteria_type, jint criteria_maxCount, jdouble criteria_epsilon)
{
    static const char method_name[] = "calib3d::calibrateCamera_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> objectPoints;
        Mat& objectPoints_mat = *((Mat*)objectPoints_mat_nativeObj);
        Mat_to_vector_Mat( objectPoints_mat, objectPoints );
        std::vector<Mat> imagePoints;
        Mat& imagePoints_mat = *((Mat*)imagePoints_mat_nativeObj);
        Mat_to_vector_Mat( imagePoints_mat, imagePoints );
        std::vector<Mat> rvecs;
        Mat& rvecs_mat = *((Mat*)rvecs_mat_nativeObj);
        std::vector<Mat> tvecs;
        Mat& tvecs_mat = *((Mat*)tvecs_mat_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        TermCriteria criteria(criteria_type, criteria_maxCount, criteria_epsilon);
        double _retval_ = cv::calibrateCamera( objectPoints, imagePoints, imageSize, cameraMatrix, distCoeffs, rvecs, tvecs, (int)flags, criteria );
        vector_Mat_to_Mat( rvecs, rvecs_mat );
        vector_Mat_to_Mat( tvecs, tvecs_mat );
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_calibrateCamera_11 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jlong, jlong, jlong, jlong, jint);

JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_calibrateCamera_11
  (JNIEnv* env, jclass , jlong objectPoints_mat_nativeObj, jlong imagePoints_mat_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong rvecs_mat_nativeObj, jlong tvecs_mat_nativeObj, jint flags)
{
    static const char method_name[] = "calib3d::calibrateCamera_11()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> objectPoints;
        Mat& objectPoints_mat = *((Mat*)objectPoints_mat_nativeObj);
        Mat_to_vector_Mat( objectPoints_mat, objectPoints );
        std::vector<Mat> imagePoints;
        Mat& imagePoints_mat = *((Mat*)imagePoints_mat_nativeObj);
        Mat_to_vector_Mat( imagePoints_mat, imagePoints );
        std::vector<Mat> rvecs;
        Mat& rvecs_mat = *((Mat*)rvecs_mat_nativeObj);
        std::vector<Mat> tvecs;
        Mat& tvecs_mat = *((Mat*)tvecs_mat_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        double _retval_ = cv::calibrateCamera( objectPoints, imagePoints, imageSize, cameraMatrix, distCoeffs, rvecs, tvecs, (int)flags );
        vector_Mat_to_Mat( rvecs, rvecs_mat );
        vector_Mat_to_Mat( tvecs, tvecs_mat );
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_calibrateCamera_12 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jlong, jlong, jlong, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_calibrateCamera_12
  (JNIEnv* env, jclass , jlong objectPoints_mat_nativeObj, jlong imagePoints_mat_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong rvecs_mat_nativeObj, jlong tvecs_mat_nativeObj)
{
    static const char method_name[] = "calib3d::calibrateCamera_12()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> objectPoints;
        Mat& objectPoints_mat = *((Mat*)objectPoints_mat_nativeObj);
        Mat_to_vector_Mat( objectPoints_mat, objectPoints );
        std::vector<Mat> imagePoints;
        Mat& imagePoints_mat = *((Mat*)imagePoints_mat_nativeObj);
        Mat_to_vector_Mat( imagePoints_mat, imagePoints );
        std::vector<Mat> rvecs;
        Mat& rvecs_mat = *((Mat*)rvecs_mat_nativeObj);
        std::vector<Mat> tvecs;
        Mat& tvecs_mat = *((Mat*)tvecs_mat_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        double _retval_ = cv::calibrateCamera( objectPoints, imagePoints, imageSize, cameraMatrix, distCoeffs, rvecs, tvecs );
        vector_Mat_to_Mat( rvecs, rvecs_mat );
        vector_Mat_to_Mat( tvecs, tvecs_mat );
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::calibrateCameraRO(vector_Mat objectPoints, vector_Mat imagePoints, Size imageSize, int iFixedPoint, Mat& cameraMatrix, Mat& distCoeffs, vector_Mat& rvecs, vector_Mat& tvecs, Mat& newObjPoints, Mat& stdDeviationsIntrinsics, Mat& stdDeviationsExtrinsics, Mat& stdDeviationsObjPoints, Mat& perViewErrors, int flags = 0, TermCriteria criteria = TermCriteria( TermCriteria::COUNT + TermCriteria::EPS, 30, DBL_EPSILON))
//



JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_calibrateCameraROExtended_10 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jint, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jint, jint, jint, jdouble);

JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_calibrateCameraROExtended_10
  (JNIEnv* env, jclass , jlong objectPoints_mat_nativeObj, jlong imagePoints_mat_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jint iFixedPoint, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong rvecs_mat_nativeObj, jlong tvecs_mat_nativeObj, jlong newObjPoints_nativeObj, jlong stdDeviationsIntrinsics_nativeObj, jlong stdDeviationsExtrinsics_nativeObj, jlong stdDeviationsObjPoints_nativeObj, jlong perViewErrors_nativeObj, jint flags, jint criteria_type, jint criteria_maxCount, jdouble criteria_epsilon)
{
    static const char method_name[] = "calib3d::calibrateCameraROExtended_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> objectPoints;
        Mat& objectPoints_mat = *((Mat*)objectPoints_mat_nativeObj);
        Mat_to_vector_Mat( objectPoints_mat, objectPoints );
        std::vector<Mat> imagePoints;
        Mat& imagePoints_mat = *((Mat*)imagePoints_mat_nativeObj);
        Mat_to_vector_Mat( imagePoints_mat, imagePoints );
        std::vector<Mat> rvecs;
        Mat& rvecs_mat = *((Mat*)rvecs_mat_nativeObj);
        std::vector<Mat> tvecs;
        Mat& tvecs_mat = *((Mat*)tvecs_mat_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        Mat& newObjPoints = *((Mat*)newObjPoints_nativeObj);
        Mat& stdDeviationsIntrinsics = *((Mat*)stdDeviationsIntrinsics_nativeObj);
        Mat& stdDeviationsExtrinsics = *((Mat*)stdDeviationsExtrinsics_nativeObj);
        Mat& stdDeviationsObjPoints = *((Mat*)stdDeviationsObjPoints_nativeObj);
        Mat& perViewErrors = *((Mat*)perViewErrors_nativeObj);
        TermCriteria criteria(criteria_type, criteria_maxCount, criteria_epsilon);
        double _retval_ = cv::calibrateCameraRO( objectPoints, imagePoints, imageSize, (int)iFixedPoint, cameraMatrix, distCoeffs, rvecs, tvecs, newObjPoints, stdDeviationsIntrinsics, stdDeviationsExtrinsics, stdDeviationsObjPoints, perViewErrors, (int)flags, criteria );
        vector_Mat_to_Mat( rvecs, rvecs_mat );
        vector_Mat_to_Mat( tvecs, tvecs_mat );
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_calibrateCameraROExtended_11 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jint, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jint);

JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_calibrateCameraROExtended_11
  (JNIEnv* env, jclass , jlong objectPoints_mat_nativeObj, jlong imagePoints_mat_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jint iFixedPoint, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong rvecs_mat_nativeObj, jlong tvecs_mat_nativeObj, jlong newObjPoints_nativeObj, jlong stdDeviationsIntrinsics_nativeObj, jlong stdDeviationsExtrinsics_nativeObj, jlong stdDeviationsObjPoints_nativeObj, jlong perViewErrors_nativeObj, jint flags)
{
    static const char method_name[] = "calib3d::calibrateCameraROExtended_11()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> objectPoints;
        Mat& objectPoints_mat = *((Mat*)objectPoints_mat_nativeObj);
        Mat_to_vector_Mat( objectPoints_mat, objectPoints );
        std::vector<Mat> imagePoints;
        Mat& imagePoints_mat = *((Mat*)imagePoints_mat_nativeObj);
        Mat_to_vector_Mat( imagePoints_mat, imagePoints );
        std::vector<Mat> rvecs;
        Mat& rvecs_mat = *((Mat*)rvecs_mat_nativeObj);
        std::vector<Mat> tvecs;
        Mat& tvecs_mat = *((Mat*)tvecs_mat_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        Mat& newObjPoints = *((Mat*)newObjPoints_nativeObj);
        Mat& stdDeviationsIntrinsics = *((Mat*)stdDeviationsIntrinsics_nativeObj);
        Mat& stdDeviationsExtrinsics = *((Mat*)stdDeviationsExtrinsics_nativeObj);
        Mat& stdDeviationsObjPoints = *((Mat*)stdDeviationsObjPoints_nativeObj);
        Mat& perViewErrors = *((Mat*)perViewErrors_nativeObj);
        double _retval_ = cv::calibrateCameraRO( objectPoints, imagePoints, imageSize, (int)iFixedPoint, cameraMatrix, distCoeffs, rvecs, tvecs, newObjPoints, stdDeviationsIntrinsics, stdDeviationsExtrinsics, stdDeviationsObjPoints, perViewErrors, (int)flags );
        vector_Mat_to_Mat( rvecs, rvecs_mat );
        vector_Mat_to_Mat( tvecs, tvecs_mat );
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_calibrateCameraROExtended_12 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jint, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_calibrateCameraROExtended_12
  (JNIEnv* env, jclass , jlong objectPoints_mat_nativeObj, jlong imagePoints_mat_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jint iFixedPoint, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong rvecs_mat_nativeObj, jlong tvecs_mat_nativeObj, jlong newObjPoints_nativeObj, jlong stdDeviationsIntrinsics_nativeObj, jlong stdDeviationsExtrinsics_nativeObj, jlong stdDeviationsObjPoints_nativeObj, jlong perViewErrors_nativeObj)
{
    static const char method_name[] = "calib3d::calibrateCameraROExtended_12()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> objectPoints;
        Mat& objectPoints_mat = *((Mat*)objectPoints_mat_nativeObj);
        Mat_to_vector_Mat( objectPoints_mat, objectPoints );
        std::vector<Mat> imagePoints;
        Mat& imagePoints_mat = *((Mat*)imagePoints_mat_nativeObj);
        Mat_to_vector_Mat( imagePoints_mat, imagePoints );
        std::vector<Mat> rvecs;
        Mat& rvecs_mat = *((Mat*)rvecs_mat_nativeObj);
        std::vector<Mat> tvecs;
        Mat& tvecs_mat = *((Mat*)tvecs_mat_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        Mat& newObjPoints = *((Mat*)newObjPoints_nativeObj);
        Mat& stdDeviationsIntrinsics = *((Mat*)stdDeviationsIntrinsics_nativeObj);
        Mat& stdDeviationsExtrinsics = *((Mat*)stdDeviationsExtrinsics_nativeObj);
        Mat& stdDeviationsObjPoints = *((Mat*)stdDeviationsObjPoints_nativeObj);
        Mat& perViewErrors = *((Mat*)perViewErrors_nativeObj);
        double _retval_ = cv::calibrateCameraRO( objectPoints, imagePoints, imageSize, (int)iFixedPoint, cameraMatrix, distCoeffs, rvecs, tvecs, newObjPoints, stdDeviationsIntrinsics, stdDeviationsExtrinsics, stdDeviationsObjPoints, perViewErrors );
        vector_Mat_to_Mat( rvecs, rvecs_mat );
        vector_Mat_to_Mat( tvecs, tvecs_mat );
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::calibrateCameraRO(vector_Mat objectPoints, vector_Mat imagePoints, Size imageSize, int iFixedPoint, Mat& cameraMatrix, Mat& distCoeffs, vector_Mat& rvecs, vector_Mat& tvecs, Mat& newObjPoints, int flags = 0, TermCriteria criteria = TermCriteria( TermCriteria::COUNT + TermCriteria::EPS, 30, DBL_EPSILON))
//



JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_calibrateCameraRO_10 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jint, jlong, jlong, jlong, jlong, jlong, jint, jint, jint, jdouble);

JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_calibrateCameraRO_10
  (JNIEnv* env, jclass , jlong objectPoints_mat_nativeObj, jlong imagePoints_mat_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jint iFixedPoint, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong rvecs_mat_nativeObj, jlong tvecs_mat_nativeObj, jlong newObjPoints_nativeObj, jint flags, jint criteria_type, jint criteria_maxCount, jdouble criteria_epsilon)
{
    static const char method_name[] = "calib3d::calibrateCameraRO_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> objectPoints;
        Mat& objectPoints_mat = *((Mat*)objectPoints_mat_nativeObj);
        Mat_to_vector_Mat( objectPoints_mat, objectPoints );
        std::vector<Mat> imagePoints;
        Mat& imagePoints_mat = *((Mat*)imagePoints_mat_nativeObj);
        Mat_to_vector_Mat( imagePoints_mat, imagePoints );
        std::vector<Mat> rvecs;
        Mat& rvecs_mat = *((Mat*)rvecs_mat_nativeObj);
        std::vector<Mat> tvecs;
        Mat& tvecs_mat = *((Mat*)tvecs_mat_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        Mat& newObjPoints = *((Mat*)newObjPoints_nativeObj);
        TermCriteria criteria(criteria_type, criteria_maxCount, criteria_epsilon);
        double _retval_ = cv::calibrateCameraRO( objectPoints, imagePoints, imageSize, (int)iFixedPoint, cameraMatrix, distCoeffs, rvecs, tvecs, newObjPoints, (int)flags, criteria );
        vector_Mat_to_Mat( rvecs, rvecs_mat );
        vector_Mat_to_Mat( tvecs, tvecs_mat );
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_calibrateCameraRO_11 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jint, jlong, jlong, jlong, jlong, jlong, jint);

JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_calibrateCameraRO_11
  (JNIEnv* env, jclass , jlong objectPoints_mat_nativeObj, jlong imagePoints_mat_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jint iFixedPoint, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong rvecs_mat_nativeObj, jlong tvecs_mat_nativeObj, jlong newObjPoints_nativeObj, jint flags)
{
    static const char method_name[] = "calib3d::calibrateCameraRO_11()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> objectPoints;
        Mat& objectPoints_mat = *((Mat*)objectPoints_mat_nativeObj);
        Mat_to_vector_Mat( objectPoints_mat, objectPoints );
        std::vector<Mat> imagePoints;
        Mat& imagePoints_mat = *((Mat*)imagePoints_mat_nativeObj);
        Mat_to_vector_Mat( imagePoints_mat, imagePoints );
        std::vector<Mat> rvecs;
        Mat& rvecs_mat = *((Mat*)rvecs_mat_nativeObj);
        std::vector<Mat> tvecs;
        Mat& tvecs_mat = *((Mat*)tvecs_mat_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        Mat& newObjPoints = *((Mat*)newObjPoints_nativeObj);
        double _retval_ = cv::calibrateCameraRO( objectPoints, imagePoints, imageSize, (int)iFixedPoint, cameraMatrix, distCoeffs, rvecs, tvecs, newObjPoints, (int)flags );
        vector_Mat_to_Mat( rvecs, rvecs_mat );
        vector_Mat_to_Mat( tvecs, tvecs_mat );
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_calibrateCameraRO_12 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jint, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_calibrateCameraRO_12
  (JNIEnv* env, jclass , jlong objectPoints_mat_nativeObj, jlong imagePoints_mat_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jint iFixedPoint, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong rvecs_mat_nativeObj, jlong tvecs_mat_nativeObj, jlong newObjPoints_nativeObj)
{
    static const char method_name[] = "calib3d::calibrateCameraRO_12()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> objectPoints;
        Mat& objectPoints_mat = *((Mat*)objectPoints_mat_nativeObj);
        Mat_to_vector_Mat( objectPoints_mat, objectPoints );
        std::vector<Mat> imagePoints;
        Mat& imagePoints_mat = *((Mat*)imagePoints_mat_nativeObj);
        Mat_to_vector_Mat( imagePoints_mat, imagePoints );
        std::vector<Mat> rvecs;
        Mat& rvecs_mat = *((Mat*)rvecs_mat_nativeObj);
        std::vector<Mat> tvecs;
        Mat& tvecs_mat = *((Mat*)tvecs_mat_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        Mat& newObjPoints = *((Mat*)newObjPoints_nativeObj);
        double _retval_ = cv::calibrateCameraRO( objectPoints, imagePoints, imageSize, (int)iFixedPoint, cameraMatrix, distCoeffs, rvecs, tvecs, newObjPoints );
        vector_Mat_to_Mat( rvecs, rvecs_mat );
        vector_Mat_to_Mat( tvecs, tvecs_mat );
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::sampsonDistance(Mat pt1, Mat pt2, Mat F)
//



JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_sampsonDistance_10 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_sampsonDistance_10
  (JNIEnv* env, jclass , jlong pt1_nativeObj, jlong pt2_nativeObj, jlong F_nativeObj)
{
    static const char method_name[] = "calib3d::sampsonDistance_10()";
    try {
        LOGD("%s", method_name);
        Mat& pt1 = *((Mat*)pt1_nativeObj);
        Mat& pt2 = *((Mat*)pt2_nativeObj);
        Mat& F = *((Mat*)F_nativeObj);
        return cv::sampsonDistance( pt1, pt2, F );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::stereoCalibrate(vector_Mat objectPoints, vector_Mat imagePoints1, vector_Mat imagePoints2, Mat& cameraMatrix1, Mat& distCoeffs1, Mat& cameraMatrix2, Mat& distCoeffs2, Size imageSize, Mat& R, Mat& T, Mat& E, Mat& F, Mat& perViewErrors, int flags = CALIB_FIX_INTRINSIC, TermCriteria criteria = TermCriteria(TermCriteria::COUNT+TermCriteria::EPS, 30, 1e-6))
//



JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_stereoCalibrateExtended_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jdouble, jdouble, jlong, jlong, jlong, jlong, jlong, jint, jint, jint, jdouble);

JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_stereoCalibrateExtended_10
  (JNIEnv* env, jclass , jlong objectPoints_mat_nativeObj, jlong imagePoints1_mat_nativeObj, jlong imagePoints2_mat_nativeObj, jlong cameraMatrix1_nativeObj, jlong distCoeffs1_nativeObj, jlong cameraMatrix2_nativeObj, jlong distCoeffs2_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jlong R_nativeObj, jlong T_nativeObj, jlong E_nativeObj, jlong F_nativeObj, jlong perViewErrors_nativeObj, jint flags, jint criteria_type, jint criteria_maxCount, jdouble criteria_epsilon)
{
    static const char method_name[] = "calib3d::stereoCalibrateExtended_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> objectPoints;
        Mat& objectPoints_mat = *((Mat*)objectPoints_mat_nativeObj);
        Mat_to_vector_Mat( objectPoints_mat, objectPoints );
        std::vector<Mat> imagePoints1;
        Mat& imagePoints1_mat = *((Mat*)imagePoints1_mat_nativeObj);
        Mat_to_vector_Mat( imagePoints1_mat, imagePoints1 );
        std::vector<Mat> imagePoints2;
        Mat& imagePoints2_mat = *((Mat*)imagePoints2_mat_nativeObj);
        Mat_to_vector_Mat( imagePoints2_mat, imagePoints2 );
        Mat& cameraMatrix1 = *((Mat*)cameraMatrix1_nativeObj);
        Mat& distCoeffs1 = *((Mat*)distCoeffs1_nativeObj);
        Mat& cameraMatrix2 = *((Mat*)cameraMatrix2_nativeObj);
        Mat& distCoeffs2 = *((Mat*)distCoeffs2_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Mat& R = *((Mat*)R_nativeObj);
        Mat& T = *((Mat*)T_nativeObj);
        Mat& E = *((Mat*)E_nativeObj);
        Mat& F = *((Mat*)F_nativeObj);
        Mat& perViewErrors = *((Mat*)perViewErrors_nativeObj);
        TermCriteria criteria(criteria_type, criteria_maxCount, criteria_epsilon);
        return cv::stereoCalibrate( objectPoints, imagePoints1, imagePoints2, cameraMatrix1, distCoeffs1, cameraMatrix2, distCoeffs2, imageSize, R, T, E, F, perViewErrors, (int)flags, criteria );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_stereoCalibrateExtended_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jdouble, jdouble, jlong, jlong, jlong, jlong, jlong, jint);

JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_stereoCalibrateExtended_11
  (JNIEnv* env, jclass , jlong objectPoints_mat_nativeObj, jlong imagePoints1_mat_nativeObj, jlong imagePoints2_mat_nativeObj, jlong cameraMatrix1_nativeObj, jlong distCoeffs1_nativeObj, jlong cameraMatrix2_nativeObj, jlong distCoeffs2_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jlong R_nativeObj, jlong T_nativeObj, jlong E_nativeObj, jlong F_nativeObj, jlong perViewErrors_nativeObj, jint flags)
{
    static const char method_name[] = "calib3d::stereoCalibrateExtended_11()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> objectPoints;
        Mat& objectPoints_mat = *((Mat*)objectPoints_mat_nativeObj);
        Mat_to_vector_Mat( objectPoints_mat, objectPoints );
        std::vector<Mat> imagePoints1;
        Mat& imagePoints1_mat = *((Mat*)imagePoints1_mat_nativeObj);
        Mat_to_vector_Mat( imagePoints1_mat, imagePoints1 );
        std::vector<Mat> imagePoints2;
        Mat& imagePoints2_mat = *((Mat*)imagePoints2_mat_nativeObj);
        Mat_to_vector_Mat( imagePoints2_mat, imagePoints2 );
        Mat& cameraMatrix1 = *((Mat*)cameraMatrix1_nativeObj);
        Mat& distCoeffs1 = *((Mat*)distCoeffs1_nativeObj);
        Mat& cameraMatrix2 = *((Mat*)cameraMatrix2_nativeObj);
        Mat& distCoeffs2 = *((Mat*)distCoeffs2_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Mat& R = *((Mat*)R_nativeObj);
        Mat& T = *((Mat*)T_nativeObj);
        Mat& E = *((Mat*)E_nativeObj);
        Mat& F = *((Mat*)F_nativeObj);
        Mat& perViewErrors = *((Mat*)perViewErrors_nativeObj);
        return cv::stereoCalibrate( objectPoints, imagePoints1, imagePoints2, cameraMatrix1, distCoeffs1, cameraMatrix2, distCoeffs2, imageSize, R, T, E, F, perViewErrors, (int)flags );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_stereoCalibrateExtended_12 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jdouble, jdouble, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_stereoCalibrateExtended_12
  (JNIEnv* env, jclass , jlong objectPoints_mat_nativeObj, jlong imagePoints1_mat_nativeObj, jlong imagePoints2_mat_nativeObj, jlong cameraMatrix1_nativeObj, jlong distCoeffs1_nativeObj, jlong cameraMatrix2_nativeObj, jlong distCoeffs2_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jlong R_nativeObj, jlong T_nativeObj, jlong E_nativeObj, jlong F_nativeObj, jlong perViewErrors_nativeObj)
{
    static const char method_name[] = "calib3d::stereoCalibrateExtended_12()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> objectPoints;
        Mat& objectPoints_mat = *((Mat*)objectPoints_mat_nativeObj);
        Mat_to_vector_Mat( objectPoints_mat, objectPoints );
        std::vector<Mat> imagePoints1;
        Mat& imagePoints1_mat = *((Mat*)imagePoints1_mat_nativeObj);
        Mat_to_vector_Mat( imagePoints1_mat, imagePoints1 );
        std::vector<Mat> imagePoints2;
        Mat& imagePoints2_mat = *((Mat*)imagePoints2_mat_nativeObj);
        Mat_to_vector_Mat( imagePoints2_mat, imagePoints2 );
        Mat& cameraMatrix1 = *((Mat*)cameraMatrix1_nativeObj);
        Mat& distCoeffs1 = *((Mat*)distCoeffs1_nativeObj);
        Mat& cameraMatrix2 = *((Mat*)cameraMatrix2_nativeObj);
        Mat& distCoeffs2 = *((Mat*)distCoeffs2_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Mat& R = *((Mat*)R_nativeObj);
        Mat& T = *((Mat*)T_nativeObj);
        Mat& E = *((Mat*)E_nativeObj);
        Mat& F = *((Mat*)F_nativeObj);
        Mat& perViewErrors = *((Mat*)perViewErrors_nativeObj);
        return cv::stereoCalibrate( objectPoints, imagePoints1, imagePoints2, cameraMatrix1, distCoeffs1, cameraMatrix2, distCoeffs2, imageSize, R, T, E, F, perViewErrors );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::stereoCalibrate(vector_Mat objectPoints, vector_Mat imagePoints1, vector_Mat imagePoints2, Mat& cameraMatrix1, Mat& distCoeffs1, Mat& cameraMatrix2, Mat& distCoeffs2, Size imageSize, Mat& R, Mat& T, Mat& E, Mat& F, int flags = CALIB_FIX_INTRINSIC, TermCriteria criteria = TermCriteria(TermCriteria::COUNT+TermCriteria::EPS, 30, 1e-6))
//



JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_stereoCalibrate_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jdouble, jdouble, jlong, jlong, jlong, jlong, jint, jint, jint, jdouble);

JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_stereoCalibrate_10
  (JNIEnv* env, jclass , jlong objectPoints_mat_nativeObj, jlong imagePoints1_mat_nativeObj, jlong imagePoints2_mat_nativeObj, jlong cameraMatrix1_nativeObj, jlong distCoeffs1_nativeObj, jlong cameraMatrix2_nativeObj, jlong distCoeffs2_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jlong R_nativeObj, jlong T_nativeObj, jlong E_nativeObj, jlong F_nativeObj, jint flags, jint criteria_type, jint criteria_maxCount, jdouble criteria_epsilon)
{
    static const char method_name[] = "calib3d::stereoCalibrate_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> objectPoints;
        Mat& objectPoints_mat = *((Mat*)objectPoints_mat_nativeObj);
        Mat_to_vector_Mat( objectPoints_mat, objectPoints );
        std::vector<Mat> imagePoints1;
        Mat& imagePoints1_mat = *((Mat*)imagePoints1_mat_nativeObj);
        Mat_to_vector_Mat( imagePoints1_mat, imagePoints1 );
        std::vector<Mat> imagePoints2;
        Mat& imagePoints2_mat = *((Mat*)imagePoints2_mat_nativeObj);
        Mat_to_vector_Mat( imagePoints2_mat, imagePoints2 );
        Mat& cameraMatrix1 = *((Mat*)cameraMatrix1_nativeObj);
        Mat& distCoeffs1 = *((Mat*)distCoeffs1_nativeObj);
        Mat& cameraMatrix2 = *((Mat*)cameraMatrix2_nativeObj);
        Mat& distCoeffs2 = *((Mat*)distCoeffs2_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Mat& R = *((Mat*)R_nativeObj);
        Mat& T = *((Mat*)T_nativeObj);
        Mat& E = *((Mat*)E_nativeObj);
        Mat& F = *((Mat*)F_nativeObj);
        TermCriteria criteria(criteria_type, criteria_maxCount, criteria_epsilon);
        return cv::stereoCalibrate( objectPoints, imagePoints1, imagePoints2, cameraMatrix1, distCoeffs1, cameraMatrix2, distCoeffs2, imageSize, R, T, E, F, (int)flags, criteria );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_stereoCalibrate_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jdouble, jdouble, jlong, jlong, jlong, jlong, jint);

JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_stereoCalibrate_11
  (JNIEnv* env, jclass , jlong objectPoints_mat_nativeObj, jlong imagePoints1_mat_nativeObj, jlong imagePoints2_mat_nativeObj, jlong cameraMatrix1_nativeObj, jlong distCoeffs1_nativeObj, jlong cameraMatrix2_nativeObj, jlong distCoeffs2_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jlong R_nativeObj, jlong T_nativeObj, jlong E_nativeObj, jlong F_nativeObj, jint flags)
{
    static const char method_name[] = "calib3d::stereoCalibrate_11()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> objectPoints;
        Mat& objectPoints_mat = *((Mat*)objectPoints_mat_nativeObj);
        Mat_to_vector_Mat( objectPoints_mat, objectPoints );
        std::vector<Mat> imagePoints1;
        Mat& imagePoints1_mat = *((Mat*)imagePoints1_mat_nativeObj);
        Mat_to_vector_Mat( imagePoints1_mat, imagePoints1 );
        std::vector<Mat> imagePoints2;
        Mat& imagePoints2_mat = *((Mat*)imagePoints2_mat_nativeObj);
        Mat_to_vector_Mat( imagePoints2_mat, imagePoints2 );
        Mat& cameraMatrix1 = *((Mat*)cameraMatrix1_nativeObj);
        Mat& distCoeffs1 = *((Mat*)distCoeffs1_nativeObj);
        Mat& cameraMatrix2 = *((Mat*)cameraMatrix2_nativeObj);
        Mat& distCoeffs2 = *((Mat*)distCoeffs2_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Mat& R = *((Mat*)R_nativeObj);
        Mat& T = *((Mat*)T_nativeObj);
        Mat& E = *((Mat*)E_nativeObj);
        Mat& F = *((Mat*)F_nativeObj);
        return cv::stereoCalibrate( objectPoints, imagePoints1, imagePoints2, cameraMatrix1, distCoeffs1, cameraMatrix2, distCoeffs2, imageSize, R, T, E, F, (int)flags );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_stereoCalibrate_12 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jdouble, jdouble, jlong, jlong, jlong, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_stereoCalibrate_12
  (JNIEnv* env, jclass , jlong objectPoints_mat_nativeObj, jlong imagePoints1_mat_nativeObj, jlong imagePoints2_mat_nativeObj, jlong cameraMatrix1_nativeObj, jlong distCoeffs1_nativeObj, jlong cameraMatrix2_nativeObj, jlong distCoeffs2_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jlong R_nativeObj, jlong T_nativeObj, jlong E_nativeObj, jlong F_nativeObj)
{
    static const char method_name[] = "calib3d::stereoCalibrate_12()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> objectPoints;
        Mat& objectPoints_mat = *((Mat*)objectPoints_mat_nativeObj);
        Mat_to_vector_Mat( objectPoints_mat, objectPoints );
        std::vector<Mat> imagePoints1;
        Mat& imagePoints1_mat = *((Mat*)imagePoints1_mat_nativeObj);
        Mat_to_vector_Mat( imagePoints1_mat, imagePoints1 );
        std::vector<Mat> imagePoints2;
        Mat& imagePoints2_mat = *((Mat*)imagePoints2_mat_nativeObj);
        Mat_to_vector_Mat( imagePoints2_mat, imagePoints2 );
        Mat& cameraMatrix1 = *((Mat*)cameraMatrix1_nativeObj);
        Mat& distCoeffs1 = *((Mat*)distCoeffs1_nativeObj);
        Mat& cameraMatrix2 = *((Mat*)cameraMatrix2_nativeObj);
        Mat& distCoeffs2 = *((Mat*)distCoeffs2_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Mat& R = *((Mat*)R_nativeObj);
        Mat& T = *((Mat*)T_nativeObj);
        Mat& E = *((Mat*)E_nativeObj);
        Mat& F = *((Mat*)F_nativeObj);
        return cv::stereoCalibrate( objectPoints, imagePoints1, imagePoints2, cameraMatrix1, distCoeffs1, cameraMatrix2, distCoeffs2, imageSize, R, T, E, F );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::fisheye::calibrate(vector_Mat objectPoints, vector_Mat imagePoints, Size image_size, Mat& K, Mat& D, vector_Mat& rvecs, vector_Mat& tvecs, int flags = 0, TermCriteria criteria = TermCriteria(TermCriteria::COUNT + TermCriteria::EPS, 100, DBL_EPSILON))
//



JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1calibrate_10 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jlong, jlong, jlong, jlong, jint, jint, jint, jdouble);

JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1calibrate_10
  (JNIEnv* env, jclass , jlong objectPoints_mat_nativeObj, jlong imagePoints_mat_nativeObj, jdouble image_size_width, jdouble image_size_height, jlong K_nativeObj, jlong D_nativeObj, jlong rvecs_mat_nativeObj, jlong tvecs_mat_nativeObj, jint flags, jint criteria_type, jint criteria_maxCount, jdouble criteria_epsilon)
{
    static const char method_name[] = "calib3d::fisheye_1calibrate_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> objectPoints;
        Mat& objectPoints_mat = *((Mat*)objectPoints_mat_nativeObj);
        Mat_to_vector_Mat( objectPoints_mat, objectPoints );
        std::vector<Mat> imagePoints;
        Mat& imagePoints_mat = *((Mat*)imagePoints_mat_nativeObj);
        Mat_to_vector_Mat( imagePoints_mat, imagePoints );
        std::vector<Mat> rvecs;
        Mat& rvecs_mat = *((Mat*)rvecs_mat_nativeObj);
        std::vector<Mat> tvecs;
        Mat& tvecs_mat = *((Mat*)tvecs_mat_nativeObj);
        Size image_size((int)image_size_width, (int)image_size_height);
        Mat& K = *((Mat*)K_nativeObj);
        Mat& D = *((Mat*)D_nativeObj);
        TermCriteria criteria(criteria_type, criteria_maxCount, criteria_epsilon);
        double _retval_ = cv::fisheye::calibrate( objectPoints, imagePoints, image_size, K, D, rvecs, tvecs, (int)flags, criteria );
        vector_Mat_to_Mat( rvecs, rvecs_mat );
        vector_Mat_to_Mat( tvecs, tvecs_mat );
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1calibrate_11 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jlong, jlong, jlong, jlong, jint);

JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1calibrate_11
  (JNIEnv* env, jclass , jlong objectPoints_mat_nativeObj, jlong imagePoints_mat_nativeObj, jdouble image_size_width, jdouble image_size_height, jlong K_nativeObj, jlong D_nativeObj, jlong rvecs_mat_nativeObj, jlong tvecs_mat_nativeObj, jint flags)
{
    static const char method_name[] = "calib3d::fisheye_1calibrate_11()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> objectPoints;
        Mat& objectPoints_mat = *((Mat*)objectPoints_mat_nativeObj);
        Mat_to_vector_Mat( objectPoints_mat, objectPoints );
        std::vector<Mat> imagePoints;
        Mat& imagePoints_mat = *((Mat*)imagePoints_mat_nativeObj);
        Mat_to_vector_Mat( imagePoints_mat, imagePoints );
        std::vector<Mat> rvecs;
        Mat& rvecs_mat = *((Mat*)rvecs_mat_nativeObj);
        std::vector<Mat> tvecs;
        Mat& tvecs_mat = *((Mat*)tvecs_mat_nativeObj);
        Size image_size((int)image_size_width, (int)image_size_height);
        Mat& K = *((Mat*)K_nativeObj);
        Mat& D = *((Mat*)D_nativeObj);
        double _retval_ = cv::fisheye::calibrate( objectPoints, imagePoints, image_size, K, D, rvecs, tvecs, (int)flags );
        vector_Mat_to_Mat( rvecs, rvecs_mat );
        vector_Mat_to_Mat( tvecs, tvecs_mat );
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1calibrate_12 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jlong, jlong, jlong, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1calibrate_12
  (JNIEnv* env, jclass , jlong objectPoints_mat_nativeObj, jlong imagePoints_mat_nativeObj, jdouble image_size_width, jdouble image_size_height, jlong K_nativeObj, jlong D_nativeObj, jlong rvecs_mat_nativeObj, jlong tvecs_mat_nativeObj)
{
    static const char method_name[] = "calib3d::fisheye_1calibrate_12()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> objectPoints;
        Mat& objectPoints_mat = *((Mat*)objectPoints_mat_nativeObj);
        Mat_to_vector_Mat( objectPoints_mat, objectPoints );
        std::vector<Mat> imagePoints;
        Mat& imagePoints_mat = *((Mat*)imagePoints_mat_nativeObj);
        Mat_to_vector_Mat( imagePoints_mat, imagePoints );
        std::vector<Mat> rvecs;
        Mat& rvecs_mat = *((Mat*)rvecs_mat_nativeObj);
        std::vector<Mat> tvecs;
        Mat& tvecs_mat = *((Mat*)tvecs_mat_nativeObj);
        Size image_size((int)image_size_width, (int)image_size_height);
        Mat& K = *((Mat*)K_nativeObj);
        Mat& D = *((Mat*)D_nativeObj);
        double _retval_ = cv::fisheye::calibrate( objectPoints, imagePoints, image_size, K, D, rvecs, tvecs );
        vector_Mat_to_Mat( rvecs, rvecs_mat );
        vector_Mat_to_Mat( tvecs, tvecs_mat );
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::fisheye::stereoCalibrate(vector_Mat objectPoints, vector_Mat imagePoints1, vector_Mat imagePoints2, Mat& K1, Mat& D1, Mat& K2, Mat& D2, Size imageSize, Mat& R, Mat& T, int flags = fisheye::CALIB_FIX_INTRINSIC, TermCriteria criteria = TermCriteria(TermCriteria::COUNT + TermCriteria::EPS, 100, DBL_EPSILON))
//



JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1stereoCalibrate_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jdouble, jdouble, jlong, jlong, jint, jint, jint, jdouble);

JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1stereoCalibrate_10
  (JNIEnv* env, jclass , jlong objectPoints_mat_nativeObj, jlong imagePoints1_mat_nativeObj, jlong imagePoints2_mat_nativeObj, jlong K1_nativeObj, jlong D1_nativeObj, jlong K2_nativeObj, jlong D2_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jlong R_nativeObj, jlong T_nativeObj, jint flags, jint criteria_type, jint criteria_maxCount, jdouble criteria_epsilon)
{
    static const char method_name[] = "calib3d::fisheye_1stereoCalibrate_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> objectPoints;
        Mat& objectPoints_mat = *((Mat*)objectPoints_mat_nativeObj);
        Mat_to_vector_Mat( objectPoints_mat, objectPoints );
        std::vector<Mat> imagePoints1;
        Mat& imagePoints1_mat = *((Mat*)imagePoints1_mat_nativeObj);
        Mat_to_vector_Mat( imagePoints1_mat, imagePoints1 );
        std::vector<Mat> imagePoints2;
        Mat& imagePoints2_mat = *((Mat*)imagePoints2_mat_nativeObj);
        Mat_to_vector_Mat( imagePoints2_mat, imagePoints2 );
        Mat& K1 = *((Mat*)K1_nativeObj);
        Mat& D1 = *((Mat*)D1_nativeObj);
        Mat& K2 = *((Mat*)K2_nativeObj);
        Mat& D2 = *((Mat*)D2_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Mat& R = *((Mat*)R_nativeObj);
        Mat& T = *((Mat*)T_nativeObj);
        TermCriteria criteria(criteria_type, criteria_maxCount, criteria_epsilon);
        return cv::fisheye::stereoCalibrate( objectPoints, imagePoints1, imagePoints2, K1, D1, K2, D2, imageSize, R, T, (int)flags, criteria );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1stereoCalibrate_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jdouble, jdouble, jlong, jlong, jint);

JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1stereoCalibrate_11
  (JNIEnv* env, jclass , jlong objectPoints_mat_nativeObj, jlong imagePoints1_mat_nativeObj, jlong imagePoints2_mat_nativeObj, jlong K1_nativeObj, jlong D1_nativeObj, jlong K2_nativeObj, jlong D2_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jlong R_nativeObj, jlong T_nativeObj, jint flags)
{
    static const char method_name[] = "calib3d::fisheye_1stereoCalibrate_11()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> objectPoints;
        Mat& objectPoints_mat = *((Mat*)objectPoints_mat_nativeObj);
        Mat_to_vector_Mat( objectPoints_mat, objectPoints );
        std::vector<Mat> imagePoints1;
        Mat& imagePoints1_mat = *((Mat*)imagePoints1_mat_nativeObj);
        Mat_to_vector_Mat( imagePoints1_mat, imagePoints1 );
        std::vector<Mat> imagePoints2;
        Mat& imagePoints2_mat = *((Mat*)imagePoints2_mat_nativeObj);
        Mat_to_vector_Mat( imagePoints2_mat, imagePoints2 );
        Mat& K1 = *((Mat*)K1_nativeObj);
        Mat& D1 = *((Mat*)D1_nativeObj);
        Mat& K2 = *((Mat*)K2_nativeObj);
        Mat& D2 = *((Mat*)D2_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Mat& R = *((Mat*)R_nativeObj);
        Mat& T = *((Mat*)T_nativeObj);
        return cv::fisheye::stereoCalibrate( objectPoints, imagePoints1, imagePoints2, K1, D1, K2, D2, imageSize, R, T, (int)flags );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1stereoCalibrate_12 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jdouble, jdouble, jlong, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1stereoCalibrate_12
  (JNIEnv* env, jclass , jlong objectPoints_mat_nativeObj, jlong imagePoints1_mat_nativeObj, jlong imagePoints2_mat_nativeObj, jlong K1_nativeObj, jlong D1_nativeObj, jlong K2_nativeObj, jlong D2_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jlong R_nativeObj, jlong T_nativeObj)
{
    static const char method_name[] = "calib3d::fisheye_1stereoCalibrate_12()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> objectPoints;
        Mat& objectPoints_mat = *((Mat*)objectPoints_mat_nativeObj);
        Mat_to_vector_Mat( objectPoints_mat, objectPoints );
        std::vector<Mat> imagePoints1;
        Mat& imagePoints1_mat = *((Mat*)imagePoints1_mat_nativeObj);
        Mat_to_vector_Mat( imagePoints1_mat, imagePoints1 );
        std::vector<Mat> imagePoints2;
        Mat& imagePoints2_mat = *((Mat*)imagePoints2_mat_nativeObj);
        Mat_to_vector_Mat( imagePoints2_mat, imagePoints2 );
        Mat& K1 = *((Mat*)K1_nativeObj);
        Mat& D1 = *((Mat*)D1_nativeObj);
        Mat& K2 = *((Mat*)K2_nativeObj);
        Mat& D2 = *((Mat*)D2_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Mat& R = *((Mat*)R_nativeObj);
        Mat& T = *((Mat*)T_nativeObj);
        return cv::fisheye::stereoCalibrate( objectPoints, imagePoints1, imagePoints2, K1, D1, K2, D2, imageSize, R, T );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  float cv::rectify3Collinear(Mat cameraMatrix1, Mat distCoeffs1, Mat cameraMatrix2, Mat distCoeffs2, Mat cameraMatrix3, Mat distCoeffs3, vector_Mat imgpt1, vector_Mat imgpt3, Size imageSize, Mat R12, Mat T12, Mat R13, Mat T13, Mat& R1, Mat& R2, Mat& R3, Mat& P1, Mat& P2, Mat& P3, Mat& Q, double alpha, Size newImgSize, Rect* roi1, Rect* roi2, int flags)
//



JNIEXPORT jfloat JNICALL Java_org_opencv_calib3d_Calib3d_rectify3Collinear_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jdouble, jdouble, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jdouble, jdouble, jdouble, jdoubleArray, jdoubleArray, jint);

JNIEXPORT jfloat JNICALL Java_org_opencv_calib3d_Calib3d_rectify3Collinear_10
  (JNIEnv* env, jclass , jlong cameraMatrix1_nativeObj, jlong distCoeffs1_nativeObj, jlong cameraMatrix2_nativeObj, jlong distCoeffs2_nativeObj, jlong cameraMatrix3_nativeObj, jlong distCoeffs3_nativeObj, jlong imgpt1_mat_nativeObj, jlong imgpt3_mat_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jlong R12_nativeObj, jlong T12_nativeObj, jlong R13_nativeObj, jlong T13_nativeObj, jlong R1_nativeObj, jlong R2_nativeObj, jlong R3_nativeObj, jlong P1_nativeObj, jlong P2_nativeObj, jlong P3_nativeObj, jlong Q_nativeObj, jdouble alpha, jdouble newImgSize_width, jdouble newImgSize_height, jdoubleArray roi1_out, jdoubleArray roi2_out, jint flags)
{
    static const char method_name[] = "calib3d::rectify3Collinear_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> imgpt1;
        Mat& imgpt1_mat = *((Mat*)imgpt1_mat_nativeObj);
        Mat_to_vector_Mat( imgpt1_mat, imgpt1 );
        std::vector<Mat> imgpt3;
        Mat& imgpt3_mat = *((Mat*)imgpt3_mat_nativeObj);
        Mat_to_vector_Mat( imgpt3_mat, imgpt3 );
        Mat& cameraMatrix1 = *((Mat*)cameraMatrix1_nativeObj);
        Mat& distCoeffs1 = *((Mat*)distCoeffs1_nativeObj);
        Mat& cameraMatrix2 = *((Mat*)cameraMatrix2_nativeObj);
        Mat& distCoeffs2 = *((Mat*)distCoeffs2_nativeObj);
        Mat& cameraMatrix3 = *((Mat*)cameraMatrix3_nativeObj);
        Mat& distCoeffs3 = *((Mat*)distCoeffs3_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Mat& R12 = *((Mat*)R12_nativeObj);
        Mat& T12 = *((Mat*)T12_nativeObj);
        Mat& R13 = *((Mat*)R13_nativeObj);
        Mat& T13 = *((Mat*)T13_nativeObj);
        Mat& R1 = *((Mat*)R1_nativeObj);
        Mat& R2 = *((Mat*)R2_nativeObj);
        Mat& R3 = *((Mat*)R3_nativeObj);
        Mat& P1 = *((Mat*)P1_nativeObj);
        Mat& P2 = *((Mat*)P2_nativeObj);
        Mat& P3 = *((Mat*)P3_nativeObj);
        Mat& Q = *((Mat*)Q_nativeObj);
        Size newImgSize((int)newImgSize_width, (int)newImgSize_height);
        Rect roi1;
        Rect roi2;
        float _retval_ = cv::rectify3Collinear( cameraMatrix1, distCoeffs1, cameraMatrix2, distCoeffs2, cameraMatrix3, distCoeffs3, imgpt1, imgpt3, imageSize, R12, T12, R13, T13, R1, R2, R3, P1, P2, P3, Q, (double)alpha, newImgSize, &roi1, &roi2, (int)flags );
        jdouble tmp_roi1[4] = {(jdouble)roi1.x, (jdouble)roi1.y, (jdouble)roi1.width, (jdouble)roi1.height}; env->SetDoubleArrayRegion(roi1_out, 0, 4, tmp_roi1);
        jdouble tmp_roi2[4] = {(jdouble)roi2.x, (jdouble)roi2.y, (jdouble)roi2.width, (jdouble)roi2.height}; env->SetDoubleArrayRegion(roi2_out, 0, 4, tmp_roi2);
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::decomposeHomographyMat(Mat H, Mat K, vector_Mat& rotations, vector_Mat& translations, vector_Mat& normals)
//



JNIEXPORT jint JNICALL Java_org_opencv_calib3d_Calib3d_decomposeHomographyMat_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_Calib3d_decomposeHomographyMat_10
  (JNIEnv* env, jclass , jlong H_nativeObj, jlong K_nativeObj, jlong rotations_mat_nativeObj, jlong translations_mat_nativeObj, jlong normals_mat_nativeObj)
{
    static const char method_name[] = "calib3d::decomposeHomographyMat_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> rotations;
        Mat& rotations_mat = *((Mat*)rotations_mat_nativeObj);
        std::vector<Mat> translations;
        Mat& translations_mat = *((Mat*)translations_mat_nativeObj);
        std::vector<Mat> normals;
        Mat& normals_mat = *((Mat*)normals_mat_nativeObj);
        Mat& H = *((Mat*)H_nativeObj);
        Mat& K = *((Mat*)K_nativeObj);
        int _retval_ = cv::decomposeHomographyMat( H, K, rotations, translations, normals );
        vector_Mat_to_Mat( rotations, rotations_mat );
        vector_Mat_to_Mat( translations, translations_mat );
        vector_Mat_to_Mat( normals, normals_mat );
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::estimateAffine3D(Mat src, Mat dst, Mat& out, Mat& inliers, double ransacThreshold = 3, double confidence = 0.99)
//



JNIEXPORT jint JNICALL Java_org_opencv_calib3d_Calib3d_estimateAffine3D_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jdouble, jdouble);

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_Calib3d_estimateAffine3D_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jlong out_nativeObj, jlong inliers_nativeObj, jdouble ransacThreshold, jdouble confidence)
{
    static const char method_name[] = "calib3d::estimateAffine3D_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& out = *((Mat*)out_nativeObj);
        Mat& inliers = *((Mat*)inliers_nativeObj);
        return cv::estimateAffine3D( src, dst, out, inliers, (double)ransacThreshold, (double)confidence );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jint JNICALL Java_org_opencv_calib3d_Calib3d_estimateAffine3D_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jdouble);

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_Calib3d_estimateAffine3D_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jlong out_nativeObj, jlong inliers_nativeObj, jdouble ransacThreshold)
{
    static const char method_name[] = "calib3d::estimateAffine3D_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& out = *((Mat*)out_nativeObj);
        Mat& inliers = *((Mat*)inliers_nativeObj);
        return cv::estimateAffine3D( src, dst, out, inliers, (double)ransacThreshold );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jint JNICALL Java_org_opencv_calib3d_Calib3d_estimateAffine3D_12 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_Calib3d_estimateAffine3D_12
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jlong out_nativeObj, jlong inliers_nativeObj)
{
    static const char method_name[] = "calib3d::estimateAffine3D_12()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& out = *((Mat*)out_nativeObj);
        Mat& inliers = *((Mat*)inliers_nativeObj);
        return cv::estimateAffine3D( src, dst, out, inliers );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::recoverPose(Mat E, Mat points1, Mat points2, Mat& R, Mat& t, double focal = 1.0, Point2d pp = Point2d(0, 0), Mat& mask = Mat())
//



JNIEXPORT jint JNICALL Java_org_opencv_calib3d_Calib3d_recoverPose_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jdouble, jdouble, jdouble, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_Calib3d_recoverPose_10
  (JNIEnv* env, jclass , jlong E_nativeObj, jlong points1_nativeObj, jlong points2_nativeObj, jlong R_nativeObj, jlong t_nativeObj, jdouble focal, jdouble pp_x, jdouble pp_y, jlong mask_nativeObj)
{
    static const char method_name[] = "calib3d::recoverPose_10()";
    try {
        LOGD("%s", method_name);
        Mat& E = *((Mat*)E_nativeObj);
        Mat& points1 = *((Mat*)points1_nativeObj);
        Mat& points2 = *((Mat*)points2_nativeObj);
        Mat& R = *((Mat*)R_nativeObj);
        Mat& t = *((Mat*)t_nativeObj);
        Point2d pp(pp_x, pp_y);
        Mat& mask = *((Mat*)mask_nativeObj);
        return cv::recoverPose( E, points1, points2, R, t, (double)focal, pp, mask );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jint JNICALL Java_org_opencv_calib3d_Calib3d_recoverPose_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jdouble, jdouble, jdouble);

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_Calib3d_recoverPose_11
  (JNIEnv* env, jclass , jlong E_nativeObj, jlong points1_nativeObj, jlong points2_nativeObj, jlong R_nativeObj, jlong t_nativeObj, jdouble focal, jdouble pp_x, jdouble pp_y)
{
    static const char method_name[] = "calib3d::recoverPose_11()";
    try {
        LOGD("%s", method_name);
        Mat& E = *((Mat*)E_nativeObj);
        Mat& points1 = *((Mat*)points1_nativeObj);
        Mat& points2 = *((Mat*)points2_nativeObj);
        Mat& R = *((Mat*)R_nativeObj);
        Mat& t = *((Mat*)t_nativeObj);
        Point2d pp(pp_x, pp_y);
        return cv::recoverPose( E, points1, points2, R, t, (double)focal, pp );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jint JNICALL Java_org_opencv_calib3d_Calib3d_recoverPose_12 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jdouble);

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_Calib3d_recoverPose_12
  (JNIEnv* env, jclass , jlong E_nativeObj, jlong points1_nativeObj, jlong points2_nativeObj, jlong R_nativeObj, jlong t_nativeObj, jdouble focal)
{
    static const char method_name[] = "calib3d::recoverPose_12()";
    try {
        LOGD("%s", method_name);
        Mat& E = *((Mat*)E_nativeObj);
        Mat& points1 = *((Mat*)points1_nativeObj);
        Mat& points2 = *((Mat*)points2_nativeObj);
        Mat& R = *((Mat*)R_nativeObj);
        Mat& t = *((Mat*)t_nativeObj);
        return cv::recoverPose( E, points1, points2, R, t, (double)focal );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jint JNICALL Java_org_opencv_calib3d_Calib3d_recoverPose_13 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_Calib3d_recoverPose_13
  (JNIEnv* env, jclass , jlong E_nativeObj, jlong points1_nativeObj, jlong points2_nativeObj, jlong R_nativeObj, jlong t_nativeObj)
{
    static const char method_name[] = "calib3d::recoverPose_13()";
    try {
        LOGD("%s", method_name);
        Mat& E = *((Mat*)E_nativeObj);
        Mat& points1 = *((Mat*)points1_nativeObj);
        Mat& points2 = *((Mat*)points2_nativeObj);
        Mat& R = *((Mat*)R_nativeObj);
        Mat& t = *((Mat*)t_nativeObj);
        return cv::recoverPose( E, points1, points2, R, t );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::recoverPose(Mat E, Mat points1, Mat points2, Mat cameraMatrix, Mat& R, Mat& t, Mat& mask = Mat())
//



JNIEXPORT jint JNICALL Java_org_opencv_calib3d_Calib3d_recoverPose_14 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_Calib3d_recoverPose_14
  (JNIEnv* env, jclass , jlong E_nativeObj, jlong points1_nativeObj, jlong points2_nativeObj, jlong cameraMatrix_nativeObj, jlong R_nativeObj, jlong t_nativeObj, jlong mask_nativeObj)
{
    static const char method_name[] = "calib3d::recoverPose_14()";
    try {
        LOGD("%s", method_name);
        Mat& E = *((Mat*)E_nativeObj);
        Mat& points1 = *((Mat*)points1_nativeObj);
        Mat& points2 = *((Mat*)points2_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& R = *((Mat*)R_nativeObj);
        Mat& t = *((Mat*)t_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        return cv::recoverPose( E, points1, points2, cameraMatrix, R, t, mask );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jint JNICALL Java_org_opencv_calib3d_Calib3d_recoverPose_15 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_Calib3d_recoverPose_15
  (JNIEnv* env, jclass , jlong E_nativeObj, jlong points1_nativeObj, jlong points2_nativeObj, jlong cameraMatrix_nativeObj, jlong R_nativeObj, jlong t_nativeObj)
{
    static const char method_name[] = "calib3d::recoverPose_15()";
    try {
        LOGD("%s", method_name);
        Mat& E = *((Mat*)E_nativeObj);
        Mat& points1 = *((Mat*)points1_nativeObj);
        Mat& points2 = *((Mat*)points2_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& R = *((Mat*)R_nativeObj);
        Mat& t = *((Mat*)t_nativeObj);
        return cv::recoverPose( E, points1, points2, cameraMatrix, R, t );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::recoverPose(Mat E, Mat points1, Mat points2, Mat cameraMatrix, Mat& R, Mat& t, double distanceThresh, Mat& mask = Mat(), Mat& triangulatedPoints = Mat())
//



JNIEXPORT jint JNICALL Java_org_opencv_calib3d_Calib3d_recoverPose_16 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jdouble, jlong, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_Calib3d_recoverPose_16
  (JNIEnv* env, jclass , jlong E_nativeObj, jlong points1_nativeObj, jlong points2_nativeObj, jlong cameraMatrix_nativeObj, jlong R_nativeObj, jlong t_nativeObj, jdouble distanceThresh, jlong mask_nativeObj, jlong triangulatedPoints_nativeObj)
{
    static const char method_name[] = "calib3d::recoverPose_16()";
    try {
        LOGD("%s", method_name);
        Mat& E = *((Mat*)E_nativeObj);
        Mat& points1 = *((Mat*)points1_nativeObj);
        Mat& points2 = *((Mat*)points2_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& R = *((Mat*)R_nativeObj);
        Mat& t = *((Mat*)t_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        Mat& triangulatedPoints = *((Mat*)triangulatedPoints_nativeObj);
        return cv::recoverPose( E, points1, points2, cameraMatrix, R, t, (double)distanceThresh, mask, triangulatedPoints );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jint JNICALL Java_org_opencv_calib3d_Calib3d_recoverPose_17 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jdouble, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_Calib3d_recoverPose_17
  (JNIEnv* env, jclass , jlong E_nativeObj, jlong points1_nativeObj, jlong points2_nativeObj, jlong cameraMatrix_nativeObj, jlong R_nativeObj, jlong t_nativeObj, jdouble distanceThresh, jlong mask_nativeObj)
{
    static const char method_name[] = "calib3d::recoverPose_17()";
    try {
        LOGD("%s", method_name);
        Mat& E = *((Mat*)E_nativeObj);
        Mat& points1 = *((Mat*)points1_nativeObj);
        Mat& points2 = *((Mat*)points2_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& R = *((Mat*)R_nativeObj);
        Mat& t = *((Mat*)t_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        return cv::recoverPose( E, points1, points2, cameraMatrix, R, t, (double)distanceThresh, mask );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jint JNICALL Java_org_opencv_calib3d_Calib3d_recoverPose_18 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jdouble);

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_Calib3d_recoverPose_18
  (JNIEnv* env, jclass , jlong E_nativeObj, jlong points1_nativeObj, jlong points2_nativeObj, jlong cameraMatrix_nativeObj, jlong R_nativeObj, jlong t_nativeObj, jdouble distanceThresh)
{
    static const char method_name[] = "calib3d::recoverPose_18()";
    try {
        LOGD("%s", method_name);
        Mat& E = *((Mat*)E_nativeObj);
        Mat& points1 = *((Mat*)points1_nativeObj);
        Mat& points2 = *((Mat*)points2_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& R = *((Mat*)R_nativeObj);
        Mat& t = *((Mat*)t_nativeObj);
        return cv::recoverPose( E, points1, points2, cameraMatrix, R, t, (double)distanceThresh );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::solveP3P(Mat objectPoints, Mat imagePoints, Mat cameraMatrix, Mat distCoeffs, vector_Mat& rvecs, vector_Mat& tvecs, int flags)
//



JNIEXPORT jint JNICALL Java_org_opencv_calib3d_Calib3d_solveP3P_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jint);

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_Calib3d_solveP3P_10
  (JNIEnv* env, jclass , jlong objectPoints_nativeObj, jlong imagePoints_nativeObj, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong rvecs_mat_nativeObj, jlong tvecs_mat_nativeObj, jint flags)
{
    static const char method_name[] = "calib3d::solveP3P_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> rvecs;
        Mat& rvecs_mat = *((Mat*)rvecs_mat_nativeObj);
        std::vector<Mat> tvecs;
        Mat& tvecs_mat = *((Mat*)tvecs_mat_nativeObj);
        Mat& objectPoints = *((Mat*)objectPoints_nativeObj);
        Mat& imagePoints = *((Mat*)imagePoints_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        int _retval_ = cv::solveP3P( objectPoints, imagePoints, cameraMatrix, distCoeffs, rvecs, tvecs, (int)flags );
        vector_Mat_to_Mat( rvecs, rvecs_mat );
        vector_Mat_to_Mat( tvecs, tvecs_mat );
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::solvePnPGeneric(Mat objectPoints, Mat imagePoints, Mat cameraMatrix, Mat distCoeffs, vector_Mat& rvecs, vector_Mat& tvecs, bool useExtrinsicGuess = false, SolvePnPMethod flags = SOLVEPNP_ITERATIVE, Mat rvec = Mat(), Mat tvec = Mat(), Mat& reprojectionError = Mat())
//



JNIEXPORT jint JNICALL Java_org_opencv_calib3d_Calib3d_solvePnPGeneric_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jboolean, jint, jlong, jlong, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_Calib3d_solvePnPGeneric_10
  (JNIEnv* env, jclass , jlong objectPoints_nativeObj, jlong imagePoints_nativeObj, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong rvecs_mat_nativeObj, jlong tvecs_mat_nativeObj, jboolean useExtrinsicGuess, jint flags, jlong rvec_nativeObj, jlong tvec_nativeObj, jlong reprojectionError_nativeObj)
{
    static const char method_name[] = "calib3d::solvePnPGeneric_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> rvecs;
        Mat& rvecs_mat = *((Mat*)rvecs_mat_nativeObj);
        std::vector<Mat> tvecs;
        Mat& tvecs_mat = *((Mat*)tvecs_mat_nativeObj);
        Mat& objectPoints = *((Mat*)objectPoints_nativeObj);
        Mat& imagePoints = *((Mat*)imagePoints_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        Mat& rvec = *((Mat*)rvec_nativeObj);
        Mat& tvec = *((Mat*)tvec_nativeObj);
        Mat& reprojectionError = *((Mat*)reprojectionError_nativeObj);
        int _retval_ = cv::solvePnPGeneric( objectPoints, imagePoints, cameraMatrix, distCoeffs, rvecs, tvecs, (bool)useExtrinsicGuess, (cv::SolvePnPMethod)flags, rvec, tvec, reprojectionError );
        vector_Mat_to_Mat( rvecs, rvecs_mat );
        vector_Mat_to_Mat( tvecs, tvecs_mat );
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jint JNICALL Java_org_opencv_calib3d_Calib3d_solvePnPGeneric_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jboolean, jint, jlong, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_Calib3d_solvePnPGeneric_11
  (JNIEnv* env, jclass , jlong objectPoints_nativeObj, jlong imagePoints_nativeObj, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong rvecs_mat_nativeObj, jlong tvecs_mat_nativeObj, jboolean useExtrinsicGuess, jint flags, jlong rvec_nativeObj, jlong tvec_nativeObj)
{
    static const char method_name[] = "calib3d::solvePnPGeneric_11()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> rvecs;
        Mat& rvecs_mat = *((Mat*)rvecs_mat_nativeObj);
        std::vector<Mat> tvecs;
        Mat& tvecs_mat = *((Mat*)tvecs_mat_nativeObj);
        Mat& objectPoints = *((Mat*)objectPoints_nativeObj);
        Mat& imagePoints = *((Mat*)imagePoints_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        Mat& rvec = *((Mat*)rvec_nativeObj);
        Mat& tvec = *((Mat*)tvec_nativeObj);
        int _retval_ = cv::solvePnPGeneric( objectPoints, imagePoints, cameraMatrix, distCoeffs, rvecs, tvecs, (bool)useExtrinsicGuess, (cv::SolvePnPMethod)flags, rvec, tvec );
        vector_Mat_to_Mat( rvecs, rvecs_mat );
        vector_Mat_to_Mat( tvecs, tvecs_mat );
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jint JNICALL Java_org_opencv_calib3d_Calib3d_solvePnPGeneric_12 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jboolean, jint, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_Calib3d_solvePnPGeneric_12
  (JNIEnv* env, jclass , jlong objectPoints_nativeObj, jlong imagePoints_nativeObj, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong rvecs_mat_nativeObj, jlong tvecs_mat_nativeObj, jboolean useExtrinsicGuess, jint flags, jlong rvec_nativeObj)
{
    static const char method_name[] = "calib3d::solvePnPGeneric_12()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> rvecs;
        Mat& rvecs_mat = *((Mat*)rvecs_mat_nativeObj);
        std::vector<Mat> tvecs;
        Mat& tvecs_mat = *((Mat*)tvecs_mat_nativeObj);
        Mat& objectPoints = *((Mat*)objectPoints_nativeObj);
        Mat& imagePoints = *((Mat*)imagePoints_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        Mat& rvec = *((Mat*)rvec_nativeObj);
        int _retval_ = cv::solvePnPGeneric( objectPoints, imagePoints, cameraMatrix, distCoeffs, rvecs, tvecs, (bool)useExtrinsicGuess, (cv::SolvePnPMethod)flags, rvec );
        vector_Mat_to_Mat( rvecs, rvecs_mat );
        vector_Mat_to_Mat( tvecs, tvecs_mat );
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jint JNICALL Java_org_opencv_calib3d_Calib3d_solvePnPGeneric_13 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jboolean, jint);

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_Calib3d_solvePnPGeneric_13
  (JNIEnv* env, jclass , jlong objectPoints_nativeObj, jlong imagePoints_nativeObj, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong rvecs_mat_nativeObj, jlong tvecs_mat_nativeObj, jboolean useExtrinsicGuess, jint flags)
{
    static const char method_name[] = "calib3d::solvePnPGeneric_13()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> rvecs;
        Mat& rvecs_mat = *((Mat*)rvecs_mat_nativeObj);
        std::vector<Mat> tvecs;
        Mat& tvecs_mat = *((Mat*)tvecs_mat_nativeObj);
        Mat& objectPoints = *((Mat*)objectPoints_nativeObj);
        Mat& imagePoints = *((Mat*)imagePoints_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        int _retval_ = cv::solvePnPGeneric( objectPoints, imagePoints, cameraMatrix, distCoeffs, rvecs, tvecs, (bool)useExtrinsicGuess, (cv::SolvePnPMethod)flags );
        vector_Mat_to_Mat( rvecs, rvecs_mat );
        vector_Mat_to_Mat( tvecs, tvecs_mat );
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jint JNICALL Java_org_opencv_calib3d_Calib3d_solvePnPGeneric_14 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jboolean);

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_Calib3d_solvePnPGeneric_14
  (JNIEnv* env, jclass , jlong objectPoints_nativeObj, jlong imagePoints_nativeObj, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong rvecs_mat_nativeObj, jlong tvecs_mat_nativeObj, jboolean useExtrinsicGuess)
{
    static const char method_name[] = "calib3d::solvePnPGeneric_14()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> rvecs;
        Mat& rvecs_mat = *((Mat*)rvecs_mat_nativeObj);
        std::vector<Mat> tvecs;
        Mat& tvecs_mat = *((Mat*)tvecs_mat_nativeObj);
        Mat& objectPoints = *((Mat*)objectPoints_nativeObj);
        Mat& imagePoints = *((Mat*)imagePoints_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        int _retval_ = cv::solvePnPGeneric( objectPoints, imagePoints, cameraMatrix, distCoeffs, rvecs, tvecs, (bool)useExtrinsicGuess );
        vector_Mat_to_Mat( rvecs, rvecs_mat );
        vector_Mat_to_Mat( tvecs, tvecs_mat );
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jint JNICALL Java_org_opencv_calib3d_Calib3d_solvePnPGeneric_15 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_calib3d_Calib3d_solvePnPGeneric_15
  (JNIEnv* env, jclass , jlong objectPoints_nativeObj, jlong imagePoints_nativeObj, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong rvecs_mat_nativeObj, jlong tvecs_mat_nativeObj)
{
    static const char method_name[] = "calib3d::solvePnPGeneric_15()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> rvecs;
        Mat& rvecs_mat = *((Mat*)rvecs_mat_nativeObj);
        std::vector<Mat> tvecs;
        Mat& tvecs_mat = *((Mat*)tvecs_mat_nativeObj);
        Mat& objectPoints = *((Mat*)objectPoints_nativeObj);
        Mat& imagePoints = *((Mat*)imagePoints_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        int _retval_ = cv::solvePnPGeneric( objectPoints, imagePoints, cameraMatrix, distCoeffs, rvecs, tvecs );
        vector_Mat_to_Mat( rvecs, rvecs_mat );
        vector_Mat_to_Mat( tvecs, tvecs_mat );
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::Rodrigues(Mat src, Mat& dst, Mat& jacobian = Mat())
//



JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_Rodrigues_10 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_Rodrigues_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jlong jacobian_nativeObj)
{
    static const char method_name[] = "calib3d::Rodrigues_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& jacobian = *((Mat*)jacobian_nativeObj);
        cv::Rodrigues( src, dst, jacobian );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_Rodrigues_11 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_Rodrigues_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "calib3d::Rodrigues_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::Rodrigues( src, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::calibrateHandEye(vector_Mat R_gripper2base, vector_Mat t_gripper2base, vector_Mat R_target2cam, vector_Mat t_target2cam, Mat& R_cam2gripper, Mat& t_cam2gripper, HandEyeCalibrationMethod method = CALIB_HAND_EYE_TSAI)
//



JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_calibrateHandEye_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_calibrateHandEye_10
  (JNIEnv* env, jclass , jlong R_gripper2base_mat_nativeObj, jlong t_gripper2base_mat_nativeObj, jlong R_target2cam_mat_nativeObj, jlong t_target2cam_mat_nativeObj, jlong R_cam2gripper_nativeObj, jlong t_cam2gripper_nativeObj, jint method)
{
    static const char method_name[] = "calib3d::calibrateHandEye_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> R_gripper2base;
        Mat& R_gripper2base_mat = *((Mat*)R_gripper2base_mat_nativeObj);
        Mat_to_vector_Mat( R_gripper2base_mat, R_gripper2base );
        std::vector<Mat> t_gripper2base;
        Mat& t_gripper2base_mat = *((Mat*)t_gripper2base_mat_nativeObj);
        Mat_to_vector_Mat( t_gripper2base_mat, t_gripper2base );
        std::vector<Mat> R_target2cam;
        Mat& R_target2cam_mat = *((Mat*)R_target2cam_mat_nativeObj);
        Mat_to_vector_Mat( R_target2cam_mat, R_target2cam );
        std::vector<Mat> t_target2cam;
        Mat& t_target2cam_mat = *((Mat*)t_target2cam_mat_nativeObj);
        Mat_to_vector_Mat( t_target2cam_mat, t_target2cam );
        Mat& R_cam2gripper = *((Mat*)R_cam2gripper_nativeObj);
        Mat& t_cam2gripper = *((Mat*)t_cam2gripper_nativeObj);
        cv::calibrateHandEye( R_gripper2base, t_gripper2base, R_target2cam, t_target2cam, R_cam2gripper, t_cam2gripper, (cv::HandEyeCalibrationMethod)method );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_calibrateHandEye_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_calibrateHandEye_11
  (JNIEnv* env, jclass , jlong R_gripper2base_mat_nativeObj, jlong t_gripper2base_mat_nativeObj, jlong R_target2cam_mat_nativeObj, jlong t_target2cam_mat_nativeObj, jlong R_cam2gripper_nativeObj, jlong t_cam2gripper_nativeObj)
{
    static const char method_name[] = "calib3d::calibrateHandEye_11()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> R_gripper2base;
        Mat& R_gripper2base_mat = *((Mat*)R_gripper2base_mat_nativeObj);
        Mat_to_vector_Mat( R_gripper2base_mat, R_gripper2base );
        std::vector<Mat> t_gripper2base;
        Mat& t_gripper2base_mat = *((Mat*)t_gripper2base_mat_nativeObj);
        Mat_to_vector_Mat( t_gripper2base_mat, t_gripper2base );
        std::vector<Mat> R_target2cam;
        Mat& R_target2cam_mat = *((Mat*)R_target2cam_mat_nativeObj);
        Mat_to_vector_Mat( R_target2cam_mat, R_target2cam );
        std::vector<Mat> t_target2cam;
        Mat& t_target2cam_mat = *((Mat*)t_target2cam_mat_nativeObj);
        Mat_to_vector_Mat( t_target2cam_mat, t_target2cam );
        Mat& R_cam2gripper = *((Mat*)R_cam2gripper_nativeObj);
        Mat& t_cam2gripper = *((Mat*)t_cam2gripper_nativeObj);
        cv::calibrateHandEye( R_gripper2base, t_gripper2base, R_target2cam, t_target2cam, R_cam2gripper, t_cam2gripper );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::calibrationMatrixValues(Mat cameraMatrix, Size imageSize, double apertureWidth, double apertureHeight, double& fovx, double& fovy, double& focalLength, Point2d& principalPoint, double& aspectRatio)
//



JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_calibrationMatrixValues_10 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jdoubleArray, jdoubleArray, jdoubleArray, jdoubleArray, jdoubleArray);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_calibrationMatrixValues_10
  (JNIEnv* env, jclass , jlong cameraMatrix_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jdouble apertureWidth, jdouble apertureHeight, jdoubleArray fovx_out, jdoubleArray fovy_out, jdoubleArray focalLength_out, jdoubleArray principalPoint_out, jdoubleArray aspectRatio_out)
{
    static const char method_name[] = "calib3d::calibrationMatrixValues_10()";
    try {
        LOGD("%s", method_name);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        double fovx;
        double fovy;
        double focalLength;
        Point2d principalPoint;
        double aspectRatio;
        cv::calibrationMatrixValues( cameraMatrix, imageSize, (double)apertureWidth, (double)apertureHeight, fovx, fovy, focalLength, principalPoint, aspectRatio );
        jdouble tmp_fovx[1] = {(jdouble)fovx}; env->SetDoubleArrayRegion(fovx_out, 0, 1, tmp_fovx);
        jdouble tmp_fovy[1] = {(jdouble)fovy}; env->SetDoubleArrayRegion(fovy_out, 0, 1, tmp_fovy);
        jdouble tmp_focalLength[1] = {(jdouble)focalLength}; env->SetDoubleArrayRegion(focalLength_out, 0, 1, tmp_focalLength);
        jdouble tmp_principalPoint[2] = {(jdouble)principalPoint.x, (jdouble)principalPoint.y}; env->SetDoubleArrayRegion(principalPoint_out, 0, 2, tmp_principalPoint);
        jdouble tmp_aspectRatio[1] = {(jdouble)aspectRatio}; env->SetDoubleArrayRegion(aspectRatio_out, 0, 1, tmp_aspectRatio);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::composeRT(Mat rvec1, Mat tvec1, Mat rvec2, Mat tvec2, Mat& rvec3, Mat& tvec3, Mat& dr3dr1 = Mat(), Mat& dr3dt1 = Mat(), Mat& dr3dr2 = Mat(), Mat& dr3dt2 = Mat(), Mat& dt3dr1 = Mat(), Mat& dt3dt1 = Mat(), Mat& dt3dr2 = Mat(), Mat& dt3dt2 = Mat())
//



JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_composeRT_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_composeRT_10
  (JNIEnv* env, jclass , jlong rvec1_nativeObj, jlong tvec1_nativeObj, jlong rvec2_nativeObj, jlong tvec2_nativeObj, jlong rvec3_nativeObj, jlong tvec3_nativeObj, jlong dr3dr1_nativeObj, jlong dr3dt1_nativeObj, jlong dr3dr2_nativeObj, jlong dr3dt2_nativeObj, jlong dt3dr1_nativeObj, jlong dt3dt1_nativeObj, jlong dt3dr2_nativeObj, jlong dt3dt2_nativeObj)
{
    static const char method_name[] = "calib3d::composeRT_10()";
    try {
        LOGD("%s", method_name);
        Mat& rvec1 = *((Mat*)rvec1_nativeObj);
        Mat& tvec1 = *((Mat*)tvec1_nativeObj);
        Mat& rvec2 = *((Mat*)rvec2_nativeObj);
        Mat& tvec2 = *((Mat*)tvec2_nativeObj);
        Mat& rvec3 = *((Mat*)rvec3_nativeObj);
        Mat& tvec3 = *((Mat*)tvec3_nativeObj);
        Mat& dr3dr1 = *((Mat*)dr3dr1_nativeObj);
        Mat& dr3dt1 = *((Mat*)dr3dt1_nativeObj);
        Mat& dr3dr2 = *((Mat*)dr3dr2_nativeObj);
        Mat& dr3dt2 = *((Mat*)dr3dt2_nativeObj);
        Mat& dt3dr1 = *((Mat*)dt3dr1_nativeObj);
        Mat& dt3dt1 = *((Mat*)dt3dt1_nativeObj);
        Mat& dt3dr2 = *((Mat*)dt3dr2_nativeObj);
        Mat& dt3dt2 = *((Mat*)dt3dt2_nativeObj);
        cv::composeRT( rvec1, tvec1, rvec2, tvec2, rvec3, tvec3, dr3dr1, dr3dt1, dr3dr2, dr3dt2, dt3dr1, dt3dt1, dt3dr2, dt3dt2 );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_composeRT_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_composeRT_11
  (JNIEnv* env, jclass , jlong rvec1_nativeObj, jlong tvec1_nativeObj, jlong rvec2_nativeObj, jlong tvec2_nativeObj, jlong rvec3_nativeObj, jlong tvec3_nativeObj, jlong dr3dr1_nativeObj, jlong dr3dt1_nativeObj, jlong dr3dr2_nativeObj, jlong dr3dt2_nativeObj, jlong dt3dr1_nativeObj, jlong dt3dt1_nativeObj, jlong dt3dr2_nativeObj)
{
    static const char method_name[] = "calib3d::composeRT_11()";
    try {
        LOGD("%s", method_name);
        Mat& rvec1 = *((Mat*)rvec1_nativeObj);
        Mat& tvec1 = *((Mat*)tvec1_nativeObj);
        Mat& rvec2 = *((Mat*)rvec2_nativeObj);
        Mat& tvec2 = *((Mat*)tvec2_nativeObj);
        Mat& rvec3 = *((Mat*)rvec3_nativeObj);
        Mat& tvec3 = *((Mat*)tvec3_nativeObj);
        Mat& dr3dr1 = *((Mat*)dr3dr1_nativeObj);
        Mat& dr3dt1 = *((Mat*)dr3dt1_nativeObj);
        Mat& dr3dr2 = *((Mat*)dr3dr2_nativeObj);
        Mat& dr3dt2 = *((Mat*)dr3dt2_nativeObj);
        Mat& dt3dr1 = *((Mat*)dt3dr1_nativeObj);
        Mat& dt3dt1 = *((Mat*)dt3dt1_nativeObj);
        Mat& dt3dr2 = *((Mat*)dt3dr2_nativeObj);
        cv::composeRT( rvec1, tvec1, rvec2, tvec2, rvec3, tvec3, dr3dr1, dr3dt1, dr3dr2, dr3dt2, dt3dr1, dt3dt1, dt3dr2 );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_composeRT_12 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_composeRT_12
  (JNIEnv* env, jclass , jlong rvec1_nativeObj, jlong tvec1_nativeObj, jlong rvec2_nativeObj, jlong tvec2_nativeObj, jlong rvec3_nativeObj, jlong tvec3_nativeObj, jlong dr3dr1_nativeObj, jlong dr3dt1_nativeObj, jlong dr3dr2_nativeObj, jlong dr3dt2_nativeObj, jlong dt3dr1_nativeObj, jlong dt3dt1_nativeObj)
{
    static const char method_name[] = "calib3d::composeRT_12()";
    try {
        LOGD("%s", method_name);
        Mat& rvec1 = *((Mat*)rvec1_nativeObj);
        Mat& tvec1 = *((Mat*)tvec1_nativeObj);
        Mat& rvec2 = *((Mat*)rvec2_nativeObj);
        Mat& tvec2 = *((Mat*)tvec2_nativeObj);
        Mat& rvec3 = *((Mat*)rvec3_nativeObj);
        Mat& tvec3 = *((Mat*)tvec3_nativeObj);
        Mat& dr3dr1 = *((Mat*)dr3dr1_nativeObj);
        Mat& dr3dt1 = *((Mat*)dr3dt1_nativeObj);
        Mat& dr3dr2 = *((Mat*)dr3dr2_nativeObj);
        Mat& dr3dt2 = *((Mat*)dr3dt2_nativeObj);
        Mat& dt3dr1 = *((Mat*)dt3dr1_nativeObj);
        Mat& dt3dt1 = *((Mat*)dt3dt1_nativeObj);
        cv::composeRT( rvec1, tvec1, rvec2, tvec2, rvec3, tvec3, dr3dr1, dr3dt1, dr3dr2, dr3dt2, dt3dr1, dt3dt1 );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_composeRT_13 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_composeRT_13
  (JNIEnv* env, jclass , jlong rvec1_nativeObj, jlong tvec1_nativeObj, jlong rvec2_nativeObj, jlong tvec2_nativeObj, jlong rvec3_nativeObj, jlong tvec3_nativeObj, jlong dr3dr1_nativeObj, jlong dr3dt1_nativeObj, jlong dr3dr2_nativeObj, jlong dr3dt2_nativeObj, jlong dt3dr1_nativeObj)
{
    static const char method_name[] = "calib3d::composeRT_13()";
    try {
        LOGD("%s", method_name);
        Mat& rvec1 = *((Mat*)rvec1_nativeObj);
        Mat& tvec1 = *((Mat*)tvec1_nativeObj);
        Mat& rvec2 = *((Mat*)rvec2_nativeObj);
        Mat& tvec2 = *((Mat*)tvec2_nativeObj);
        Mat& rvec3 = *((Mat*)rvec3_nativeObj);
        Mat& tvec3 = *((Mat*)tvec3_nativeObj);
        Mat& dr3dr1 = *((Mat*)dr3dr1_nativeObj);
        Mat& dr3dt1 = *((Mat*)dr3dt1_nativeObj);
        Mat& dr3dr2 = *((Mat*)dr3dr2_nativeObj);
        Mat& dr3dt2 = *((Mat*)dr3dt2_nativeObj);
        Mat& dt3dr1 = *((Mat*)dt3dr1_nativeObj);
        cv::composeRT( rvec1, tvec1, rvec2, tvec2, rvec3, tvec3, dr3dr1, dr3dt1, dr3dr2, dr3dt2, dt3dr1 );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_composeRT_14 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_composeRT_14
  (JNIEnv* env, jclass , jlong rvec1_nativeObj, jlong tvec1_nativeObj, jlong rvec2_nativeObj, jlong tvec2_nativeObj, jlong rvec3_nativeObj, jlong tvec3_nativeObj, jlong dr3dr1_nativeObj, jlong dr3dt1_nativeObj, jlong dr3dr2_nativeObj, jlong dr3dt2_nativeObj)
{
    static const char method_name[] = "calib3d::composeRT_14()";
    try {
        LOGD("%s", method_name);
        Mat& rvec1 = *((Mat*)rvec1_nativeObj);
        Mat& tvec1 = *((Mat*)tvec1_nativeObj);
        Mat& rvec2 = *((Mat*)rvec2_nativeObj);
        Mat& tvec2 = *((Mat*)tvec2_nativeObj);
        Mat& rvec3 = *((Mat*)rvec3_nativeObj);
        Mat& tvec3 = *((Mat*)tvec3_nativeObj);
        Mat& dr3dr1 = *((Mat*)dr3dr1_nativeObj);
        Mat& dr3dt1 = *((Mat*)dr3dt1_nativeObj);
        Mat& dr3dr2 = *((Mat*)dr3dr2_nativeObj);
        Mat& dr3dt2 = *((Mat*)dr3dt2_nativeObj);
        cv::composeRT( rvec1, tvec1, rvec2, tvec2, rvec3, tvec3, dr3dr1, dr3dt1, dr3dr2, dr3dt2 );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_composeRT_15 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_composeRT_15
  (JNIEnv* env, jclass , jlong rvec1_nativeObj, jlong tvec1_nativeObj, jlong rvec2_nativeObj, jlong tvec2_nativeObj, jlong rvec3_nativeObj, jlong tvec3_nativeObj, jlong dr3dr1_nativeObj, jlong dr3dt1_nativeObj, jlong dr3dr2_nativeObj)
{
    static const char method_name[] = "calib3d::composeRT_15()";
    try {
        LOGD("%s", method_name);
        Mat& rvec1 = *((Mat*)rvec1_nativeObj);
        Mat& tvec1 = *((Mat*)tvec1_nativeObj);
        Mat& rvec2 = *((Mat*)rvec2_nativeObj);
        Mat& tvec2 = *((Mat*)tvec2_nativeObj);
        Mat& rvec3 = *((Mat*)rvec3_nativeObj);
        Mat& tvec3 = *((Mat*)tvec3_nativeObj);
        Mat& dr3dr1 = *((Mat*)dr3dr1_nativeObj);
        Mat& dr3dt1 = *((Mat*)dr3dt1_nativeObj);
        Mat& dr3dr2 = *((Mat*)dr3dr2_nativeObj);
        cv::composeRT( rvec1, tvec1, rvec2, tvec2, rvec3, tvec3, dr3dr1, dr3dt1, dr3dr2 );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_composeRT_16 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_composeRT_16
  (JNIEnv* env, jclass , jlong rvec1_nativeObj, jlong tvec1_nativeObj, jlong rvec2_nativeObj, jlong tvec2_nativeObj, jlong rvec3_nativeObj, jlong tvec3_nativeObj, jlong dr3dr1_nativeObj, jlong dr3dt1_nativeObj)
{
    static const char method_name[] = "calib3d::composeRT_16()";
    try {
        LOGD("%s", method_name);
        Mat& rvec1 = *((Mat*)rvec1_nativeObj);
        Mat& tvec1 = *((Mat*)tvec1_nativeObj);
        Mat& rvec2 = *((Mat*)rvec2_nativeObj);
        Mat& tvec2 = *((Mat*)tvec2_nativeObj);
        Mat& rvec3 = *((Mat*)rvec3_nativeObj);
        Mat& tvec3 = *((Mat*)tvec3_nativeObj);
        Mat& dr3dr1 = *((Mat*)dr3dr1_nativeObj);
        Mat& dr3dt1 = *((Mat*)dr3dt1_nativeObj);
        cv::composeRT( rvec1, tvec1, rvec2, tvec2, rvec3, tvec3, dr3dr1, dr3dt1 );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_composeRT_17 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_composeRT_17
  (JNIEnv* env, jclass , jlong rvec1_nativeObj, jlong tvec1_nativeObj, jlong rvec2_nativeObj, jlong tvec2_nativeObj, jlong rvec3_nativeObj, jlong tvec3_nativeObj, jlong dr3dr1_nativeObj)
{
    static const char method_name[] = "calib3d::composeRT_17()";
    try {
        LOGD("%s", method_name);
        Mat& rvec1 = *((Mat*)rvec1_nativeObj);
        Mat& tvec1 = *((Mat*)tvec1_nativeObj);
        Mat& rvec2 = *((Mat*)rvec2_nativeObj);
        Mat& tvec2 = *((Mat*)tvec2_nativeObj);
        Mat& rvec3 = *((Mat*)rvec3_nativeObj);
        Mat& tvec3 = *((Mat*)tvec3_nativeObj);
        Mat& dr3dr1 = *((Mat*)dr3dr1_nativeObj);
        cv::composeRT( rvec1, tvec1, rvec2, tvec2, rvec3, tvec3, dr3dr1 );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_composeRT_18 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_composeRT_18
  (JNIEnv* env, jclass , jlong rvec1_nativeObj, jlong tvec1_nativeObj, jlong rvec2_nativeObj, jlong tvec2_nativeObj, jlong rvec3_nativeObj, jlong tvec3_nativeObj)
{
    static const char method_name[] = "calib3d::composeRT_18()";
    try {
        LOGD("%s", method_name);
        Mat& rvec1 = *((Mat*)rvec1_nativeObj);
        Mat& tvec1 = *((Mat*)tvec1_nativeObj);
        Mat& rvec2 = *((Mat*)rvec2_nativeObj);
        Mat& tvec2 = *((Mat*)tvec2_nativeObj);
        Mat& rvec3 = *((Mat*)rvec3_nativeObj);
        Mat& tvec3 = *((Mat*)tvec3_nativeObj);
        cv::composeRT( rvec1, tvec1, rvec2, tvec2, rvec3, tvec3 );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::computeCorrespondEpilines(Mat points, int whichImage, Mat F, Mat& lines)
//



JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_computeCorrespondEpilines_10 (JNIEnv*, jclass, jlong, jint, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_computeCorrespondEpilines_10
  (JNIEnv* env, jclass , jlong points_nativeObj, jint whichImage, jlong F_nativeObj, jlong lines_nativeObj)
{
    static const char method_name[] = "calib3d::computeCorrespondEpilines_10()";
    try {
        LOGD("%s", method_name);
        Mat& points = *((Mat*)points_nativeObj);
        Mat& F = *((Mat*)F_nativeObj);
        Mat& lines = *((Mat*)lines_nativeObj);
        cv::computeCorrespondEpilines( points, (int)whichImage, F, lines );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::convertPointsFromHomogeneous(Mat src, Mat& dst)
//



JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_convertPointsFromHomogeneous_10 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_convertPointsFromHomogeneous_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "calib3d::convertPointsFromHomogeneous_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::convertPointsFromHomogeneous( src, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::convertPointsToHomogeneous(Mat src, Mat& dst)
//



JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_convertPointsToHomogeneous_10 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_convertPointsToHomogeneous_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "calib3d::convertPointsToHomogeneous_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::convertPointsToHomogeneous( src, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::correctMatches(Mat F, Mat points1, Mat points2, Mat& newPoints1, Mat& newPoints2)
//



JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_correctMatches_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_correctMatches_10
  (JNIEnv* env, jclass , jlong F_nativeObj, jlong points1_nativeObj, jlong points2_nativeObj, jlong newPoints1_nativeObj, jlong newPoints2_nativeObj)
{
    static const char method_name[] = "calib3d::correctMatches_10()";
    try {
        LOGD("%s", method_name);
        Mat& F = *((Mat*)F_nativeObj);
        Mat& points1 = *((Mat*)points1_nativeObj);
        Mat& points2 = *((Mat*)points2_nativeObj);
        Mat& newPoints1 = *((Mat*)newPoints1_nativeObj);
        Mat& newPoints2 = *((Mat*)newPoints2_nativeObj);
        cv::correctMatches( F, points1, points2, newPoints1, newPoints2 );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::decomposeEssentialMat(Mat E, Mat& R1, Mat& R2, Mat& t)
//



JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_decomposeEssentialMat_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_decomposeEssentialMat_10
  (JNIEnv* env, jclass , jlong E_nativeObj, jlong R1_nativeObj, jlong R2_nativeObj, jlong t_nativeObj)
{
    static const char method_name[] = "calib3d::decomposeEssentialMat_10()";
    try {
        LOGD("%s", method_name);
        Mat& E = *((Mat*)E_nativeObj);
        Mat& R1 = *((Mat*)R1_nativeObj);
        Mat& R2 = *((Mat*)R2_nativeObj);
        Mat& t = *((Mat*)t_nativeObj);
        cv::decomposeEssentialMat( E, R1, R2, t );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::decomposeProjectionMatrix(Mat projMatrix, Mat& cameraMatrix, Mat& rotMatrix, Mat& transVect, Mat& rotMatrixX = Mat(), Mat& rotMatrixY = Mat(), Mat& rotMatrixZ = Mat(), Mat& eulerAngles = Mat())
//



JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_decomposeProjectionMatrix_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_decomposeProjectionMatrix_10
  (JNIEnv* env, jclass , jlong projMatrix_nativeObj, jlong cameraMatrix_nativeObj, jlong rotMatrix_nativeObj, jlong transVect_nativeObj, jlong rotMatrixX_nativeObj, jlong rotMatrixY_nativeObj, jlong rotMatrixZ_nativeObj, jlong eulerAngles_nativeObj)
{
    static const char method_name[] = "calib3d::decomposeProjectionMatrix_10()";
    try {
        LOGD("%s", method_name);
        Mat& projMatrix = *((Mat*)projMatrix_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& rotMatrix = *((Mat*)rotMatrix_nativeObj);
        Mat& transVect = *((Mat*)transVect_nativeObj);
        Mat& rotMatrixX = *((Mat*)rotMatrixX_nativeObj);
        Mat& rotMatrixY = *((Mat*)rotMatrixY_nativeObj);
        Mat& rotMatrixZ = *((Mat*)rotMatrixZ_nativeObj);
        Mat& eulerAngles = *((Mat*)eulerAngles_nativeObj);
        cv::decomposeProjectionMatrix( projMatrix, cameraMatrix, rotMatrix, transVect, rotMatrixX, rotMatrixY, rotMatrixZ, eulerAngles );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_decomposeProjectionMatrix_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_decomposeProjectionMatrix_11
  (JNIEnv* env, jclass , jlong projMatrix_nativeObj, jlong cameraMatrix_nativeObj, jlong rotMatrix_nativeObj, jlong transVect_nativeObj, jlong rotMatrixX_nativeObj, jlong rotMatrixY_nativeObj, jlong rotMatrixZ_nativeObj)
{
    static const char method_name[] = "calib3d::decomposeProjectionMatrix_11()";
    try {
        LOGD("%s", method_name);
        Mat& projMatrix = *((Mat*)projMatrix_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& rotMatrix = *((Mat*)rotMatrix_nativeObj);
        Mat& transVect = *((Mat*)transVect_nativeObj);
        Mat& rotMatrixX = *((Mat*)rotMatrixX_nativeObj);
        Mat& rotMatrixY = *((Mat*)rotMatrixY_nativeObj);
        Mat& rotMatrixZ = *((Mat*)rotMatrixZ_nativeObj);
        cv::decomposeProjectionMatrix( projMatrix, cameraMatrix, rotMatrix, transVect, rotMatrixX, rotMatrixY, rotMatrixZ );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_decomposeProjectionMatrix_12 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_decomposeProjectionMatrix_12
  (JNIEnv* env, jclass , jlong projMatrix_nativeObj, jlong cameraMatrix_nativeObj, jlong rotMatrix_nativeObj, jlong transVect_nativeObj, jlong rotMatrixX_nativeObj, jlong rotMatrixY_nativeObj)
{
    static const char method_name[] = "calib3d::decomposeProjectionMatrix_12()";
    try {
        LOGD("%s", method_name);
        Mat& projMatrix = *((Mat*)projMatrix_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& rotMatrix = *((Mat*)rotMatrix_nativeObj);
        Mat& transVect = *((Mat*)transVect_nativeObj);
        Mat& rotMatrixX = *((Mat*)rotMatrixX_nativeObj);
        Mat& rotMatrixY = *((Mat*)rotMatrixY_nativeObj);
        cv::decomposeProjectionMatrix( projMatrix, cameraMatrix, rotMatrix, transVect, rotMatrixX, rotMatrixY );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_decomposeProjectionMatrix_13 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_decomposeProjectionMatrix_13
  (JNIEnv* env, jclass , jlong projMatrix_nativeObj, jlong cameraMatrix_nativeObj, jlong rotMatrix_nativeObj, jlong transVect_nativeObj, jlong rotMatrixX_nativeObj)
{
    static const char method_name[] = "calib3d::decomposeProjectionMatrix_13()";
    try {
        LOGD("%s", method_name);
        Mat& projMatrix = *((Mat*)projMatrix_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& rotMatrix = *((Mat*)rotMatrix_nativeObj);
        Mat& transVect = *((Mat*)transVect_nativeObj);
        Mat& rotMatrixX = *((Mat*)rotMatrixX_nativeObj);
        cv::decomposeProjectionMatrix( projMatrix, cameraMatrix, rotMatrix, transVect, rotMatrixX );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_decomposeProjectionMatrix_14 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_decomposeProjectionMatrix_14
  (JNIEnv* env, jclass , jlong projMatrix_nativeObj, jlong cameraMatrix_nativeObj, jlong rotMatrix_nativeObj, jlong transVect_nativeObj)
{
    static const char method_name[] = "calib3d::decomposeProjectionMatrix_14()";
    try {
        LOGD("%s", method_name);
        Mat& projMatrix = *((Mat*)projMatrix_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& rotMatrix = *((Mat*)rotMatrix_nativeObj);
        Mat& transVect = *((Mat*)transVect_nativeObj);
        cv::decomposeProjectionMatrix( projMatrix, cameraMatrix, rotMatrix, transVect );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::drawChessboardCorners(Mat& image, Size patternSize, vector_Point2f corners, bool patternWasFound)
//



JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_drawChessboardCorners_10 (JNIEnv*, jclass, jlong, jdouble, jdouble, jlong, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_drawChessboardCorners_10
  (JNIEnv* env, jclass , jlong image_nativeObj, jdouble patternSize_width, jdouble patternSize_height, jlong corners_mat_nativeObj, jboolean patternWasFound)
{
    static const char method_name[] = "calib3d::drawChessboardCorners_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Point2f> corners;
        Mat& corners_mat = *((Mat*)corners_mat_nativeObj);
        Mat_to_vector_Point2f( corners_mat, corners );
        Mat& image = *((Mat*)image_nativeObj);
        Size patternSize((int)patternSize_width, (int)patternSize_height);
        cv::drawChessboardCorners( image, patternSize, corners, (bool)patternWasFound );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::drawFrameAxes(Mat& image, Mat cameraMatrix, Mat distCoeffs, Mat rvec, Mat tvec, float length, int thickness = 3)
//



JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_drawFrameAxes_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jfloat, jint);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_drawFrameAxes_10
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong rvec_nativeObj, jlong tvec_nativeObj, jfloat length, jint thickness)
{
    static const char method_name[] = "calib3d::drawFrameAxes_10()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        Mat& rvec = *((Mat*)rvec_nativeObj);
        Mat& tvec = *((Mat*)tvec_nativeObj);
        cv::drawFrameAxes( image, cameraMatrix, distCoeffs, rvec, tvec, (float)length, (int)thickness );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_drawFrameAxes_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_drawFrameAxes_11
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong rvec_nativeObj, jlong tvec_nativeObj, jfloat length)
{
    static const char method_name[] = "calib3d::drawFrameAxes_11()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        Mat& rvec = *((Mat*)rvec_nativeObj);
        Mat& tvec = *((Mat*)tvec_nativeObj);
        cv::drawFrameAxes( image, cameraMatrix, distCoeffs, rvec, tvec, (float)length );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::filterHomographyDecompByVisibleRefpoints(vector_Mat rotations, vector_Mat normals, Mat beforePoints, Mat afterPoints, Mat& possibleSolutions, Mat pointsMask = Mat())
//



JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_filterHomographyDecompByVisibleRefpoints_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_filterHomographyDecompByVisibleRefpoints_10
  (JNIEnv* env, jclass , jlong rotations_mat_nativeObj, jlong normals_mat_nativeObj, jlong beforePoints_nativeObj, jlong afterPoints_nativeObj, jlong possibleSolutions_nativeObj, jlong pointsMask_nativeObj)
{
    static const char method_name[] = "calib3d::filterHomographyDecompByVisibleRefpoints_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> rotations;
        Mat& rotations_mat = *((Mat*)rotations_mat_nativeObj);
        Mat_to_vector_Mat( rotations_mat, rotations );
        std::vector<Mat> normals;
        Mat& normals_mat = *((Mat*)normals_mat_nativeObj);
        Mat_to_vector_Mat( normals_mat, normals );
        Mat& beforePoints = *((Mat*)beforePoints_nativeObj);
        Mat& afterPoints = *((Mat*)afterPoints_nativeObj);
        Mat& possibleSolutions = *((Mat*)possibleSolutions_nativeObj);
        Mat& pointsMask = *((Mat*)pointsMask_nativeObj);
        cv::filterHomographyDecompByVisibleRefpoints( rotations, normals, beforePoints, afterPoints, possibleSolutions, pointsMask );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_filterHomographyDecompByVisibleRefpoints_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_filterHomographyDecompByVisibleRefpoints_11
  (JNIEnv* env, jclass , jlong rotations_mat_nativeObj, jlong normals_mat_nativeObj, jlong beforePoints_nativeObj, jlong afterPoints_nativeObj, jlong possibleSolutions_nativeObj)
{
    static const char method_name[] = "calib3d::filterHomographyDecompByVisibleRefpoints_11()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> rotations;
        Mat& rotations_mat = *((Mat*)rotations_mat_nativeObj);
        Mat_to_vector_Mat( rotations_mat, rotations );
        std::vector<Mat> normals;
        Mat& normals_mat = *((Mat*)normals_mat_nativeObj);
        Mat_to_vector_Mat( normals_mat, normals );
        Mat& beforePoints = *((Mat*)beforePoints_nativeObj);
        Mat& afterPoints = *((Mat*)afterPoints_nativeObj);
        Mat& possibleSolutions = *((Mat*)possibleSolutions_nativeObj);
        cv::filterHomographyDecompByVisibleRefpoints( rotations, normals, beforePoints, afterPoints, possibleSolutions );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::filterSpeckles(Mat& img, double newVal, int maxSpeckleSize, double maxDiff, Mat& buf = Mat())
//



JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_filterSpeckles_10 (JNIEnv*, jclass, jlong, jdouble, jint, jdouble, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_filterSpeckles_10
  (JNIEnv* env, jclass , jlong img_nativeObj, jdouble newVal, jint maxSpeckleSize, jdouble maxDiff, jlong buf_nativeObj)
{
    static const char method_name[] = "calib3d::filterSpeckles_10()";
    try {
        LOGD("%s", method_name);
        Mat& img = *((Mat*)img_nativeObj);
        Mat& buf = *((Mat*)buf_nativeObj);
        cv::filterSpeckles( img, (double)newVal, (int)maxSpeckleSize, (double)maxDiff, buf );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_filterSpeckles_11 (JNIEnv*, jclass, jlong, jdouble, jint, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_filterSpeckles_11
  (JNIEnv* env, jclass , jlong img_nativeObj, jdouble newVal, jint maxSpeckleSize, jdouble maxDiff)
{
    static const char method_name[] = "calib3d::filterSpeckles_11()";
    try {
        LOGD("%s", method_name);
        Mat& img = *((Mat*)img_nativeObj);
        cv::filterSpeckles( img, (double)newVal, (int)maxSpeckleSize, (double)maxDiff );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::initUndistortRectifyMap(Mat cameraMatrix, Mat distCoeffs, Mat R, Mat newCameraMatrix, Size size, int m1type, Mat& map1, Mat& map2)
//



JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_initUndistortRectifyMap_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jdouble, jdouble, jint, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_initUndistortRectifyMap_10
  (JNIEnv* env, jclass , jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong R_nativeObj, jlong newCameraMatrix_nativeObj, jdouble size_width, jdouble size_height, jint m1type, jlong map1_nativeObj, jlong map2_nativeObj)
{
    static const char method_name[] = "calib3d::initUndistortRectifyMap_10()";
    try {
        LOGD("%s", method_name);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        Mat& R = *((Mat*)R_nativeObj);
        Mat& newCameraMatrix = *((Mat*)newCameraMatrix_nativeObj);
        Size size((int)size_width, (int)size_height);
        Mat& map1 = *((Mat*)map1_nativeObj);
        Mat& map2 = *((Mat*)map2_nativeObj);
        cv::initUndistortRectifyMap( cameraMatrix, distCoeffs, R, newCameraMatrix, size, (int)m1type, map1, map2 );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::matMulDeriv(Mat A, Mat B, Mat& dABdA, Mat& dABdB)
//



JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_matMulDeriv_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_matMulDeriv_10
  (JNIEnv* env, jclass , jlong A_nativeObj, jlong B_nativeObj, jlong dABdA_nativeObj, jlong dABdB_nativeObj)
{
    static const char method_name[] = "calib3d::matMulDeriv_10()";
    try {
        LOGD("%s", method_name);
        Mat& A = *((Mat*)A_nativeObj);
        Mat& B = *((Mat*)B_nativeObj);
        Mat& dABdA = *((Mat*)dABdA_nativeObj);
        Mat& dABdB = *((Mat*)dABdB_nativeObj);
        cv::matMulDeriv( A, B, dABdA, dABdB );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::projectPoints(vector_Point3f objectPoints, Mat rvec, Mat tvec, Mat cameraMatrix, vector_double distCoeffs, vector_Point2f& imagePoints, Mat& jacobian = Mat(), double aspectRatio = 0)
//



JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_projectPoints_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_projectPoints_10
  (JNIEnv* env, jclass , jlong objectPoints_mat_nativeObj, jlong rvec_nativeObj, jlong tvec_nativeObj, jlong cameraMatrix_nativeObj, jlong distCoeffs_mat_nativeObj, jlong imagePoints_mat_nativeObj, jlong jacobian_nativeObj, jdouble aspectRatio)
{
    static const char method_name[] = "calib3d::projectPoints_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Point3f> objectPoints;
        Mat& objectPoints_mat = *((Mat*)objectPoints_mat_nativeObj);
        Mat_to_vector_Point3f( objectPoints_mat, objectPoints );
        std::vector<double> distCoeffs;
        Mat& distCoeffs_mat = *((Mat*)distCoeffs_mat_nativeObj);
        Mat_to_vector_double( distCoeffs_mat, distCoeffs );
        std::vector<Point2f> imagePoints;
        Mat& imagePoints_mat = *((Mat*)imagePoints_mat_nativeObj);
        Mat& rvec = *((Mat*)rvec_nativeObj);
        Mat& tvec = *((Mat*)tvec_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& jacobian = *((Mat*)jacobian_nativeObj);
        cv::projectPoints( objectPoints, rvec, tvec, cameraMatrix, distCoeffs, imagePoints, jacobian, (double)aspectRatio );
        vector_Point2f_to_Mat( imagePoints, imagePoints_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_projectPoints_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_projectPoints_11
  (JNIEnv* env, jclass , jlong objectPoints_mat_nativeObj, jlong rvec_nativeObj, jlong tvec_nativeObj, jlong cameraMatrix_nativeObj, jlong distCoeffs_mat_nativeObj, jlong imagePoints_mat_nativeObj, jlong jacobian_nativeObj)
{
    static const char method_name[] = "calib3d::projectPoints_11()";
    try {
        LOGD("%s", method_name);
        std::vector<Point3f> objectPoints;
        Mat& objectPoints_mat = *((Mat*)objectPoints_mat_nativeObj);
        Mat_to_vector_Point3f( objectPoints_mat, objectPoints );
        std::vector<double> distCoeffs;
        Mat& distCoeffs_mat = *((Mat*)distCoeffs_mat_nativeObj);
        Mat_to_vector_double( distCoeffs_mat, distCoeffs );
        std::vector<Point2f> imagePoints;
        Mat& imagePoints_mat = *((Mat*)imagePoints_mat_nativeObj);
        Mat& rvec = *((Mat*)rvec_nativeObj);
        Mat& tvec = *((Mat*)tvec_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& jacobian = *((Mat*)jacobian_nativeObj);
        cv::projectPoints( objectPoints, rvec, tvec, cameraMatrix, distCoeffs, imagePoints, jacobian );
        vector_Point2f_to_Mat( imagePoints, imagePoints_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_projectPoints_12 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_projectPoints_12
  (JNIEnv* env, jclass , jlong objectPoints_mat_nativeObj, jlong rvec_nativeObj, jlong tvec_nativeObj, jlong cameraMatrix_nativeObj, jlong distCoeffs_mat_nativeObj, jlong imagePoints_mat_nativeObj)
{
    static const char method_name[] = "calib3d::projectPoints_12()";
    try {
        LOGD("%s", method_name);
        std::vector<Point3f> objectPoints;
        Mat& objectPoints_mat = *((Mat*)objectPoints_mat_nativeObj);
        Mat_to_vector_Point3f( objectPoints_mat, objectPoints );
        std::vector<double> distCoeffs;
        Mat& distCoeffs_mat = *((Mat*)distCoeffs_mat_nativeObj);
        Mat_to_vector_double( distCoeffs_mat, distCoeffs );
        std::vector<Point2f> imagePoints;
        Mat& imagePoints_mat = *((Mat*)imagePoints_mat_nativeObj);
        Mat& rvec = *((Mat*)rvec_nativeObj);
        Mat& tvec = *((Mat*)tvec_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        cv::projectPoints( objectPoints, rvec, tvec, cameraMatrix, distCoeffs, imagePoints );
        vector_Point2f_to_Mat( imagePoints, imagePoints_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::reprojectImageTo3D(Mat disparity, Mat& _3dImage, Mat Q, bool handleMissingValues = false, int ddepth = -1)
//



JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_reprojectImageTo3D_10 (JNIEnv*, jclass, jlong, jlong, jlong, jboolean, jint);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_reprojectImageTo3D_10
  (JNIEnv* env, jclass , jlong disparity_nativeObj, jlong _3dImage_nativeObj, jlong Q_nativeObj, jboolean handleMissingValues, jint ddepth)
{
    static const char method_name[] = "calib3d::reprojectImageTo3D_10()";
    try {
        LOGD("%s", method_name);
        Mat& disparity = *((Mat*)disparity_nativeObj);
        Mat& _3dImage = *((Mat*)_3dImage_nativeObj);
        Mat& Q = *((Mat*)Q_nativeObj);
        cv::reprojectImageTo3D( disparity, _3dImage, Q, (bool)handleMissingValues, (int)ddepth );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_reprojectImageTo3D_11 (JNIEnv*, jclass, jlong, jlong, jlong, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_reprojectImageTo3D_11
  (JNIEnv* env, jclass , jlong disparity_nativeObj, jlong _3dImage_nativeObj, jlong Q_nativeObj, jboolean handleMissingValues)
{
    static const char method_name[] = "calib3d::reprojectImageTo3D_11()";
    try {
        LOGD("%s", method_name);
        Mat& disparity = *((Mat*)disparity_nativeObj);
        Mat& _3dImage = *((Mat*)_3dImage_nativeObj);
        Mat& Q = *((Mat*)Q_nativeObj);
        cv::reprojectImageTo3D( disparity, _3dImage, Q, (bool)handleMissingValues );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_reprojectImageTo3D_12 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_reprojectImageTo3D_12
  (JNIEnv* env, jclass , jlong disparity_nativeObj, jlong _3dImage_nativeObj, jlong Q_nativeObj)
{
    static const char method_name[] = "calib3d::reprojectImageTo3D_12()";
    try {
        LOGD("%s", method_name);
        Mat& disparity = *((Mat*)disparity_nativeObj);
        Mat& _3dImage = *((Mat*)_3dImage_nativeObj);
        Mat& Q = *((Mat*)Q_nativeObj);
        cv::reprojectImageTo3D( disparity, _3dImage, Q );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::solvePnPRefineLM(Mat objectPoints, Mat imagePoints, Mat cameraMatrix, Mat distCoeffs, Mat& rvec, Mat& tvec, TermCriteria criteria = TermCriteria(TermCriteria::EPS + TermCriteria::COUNT, 20, FLT_EPSILON))
//



JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_solvePnPRefineLM_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jint, jint, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_solvePnPRefineLM_10
  (JNIEnv* env, jclass , jlong objectPoints_nativeObj, jlong imagePoints_nativeObj, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong rvec_nativeObj, jlong tvec_nativeObj, jint criteria_type, jint criteria_maxCount, jdouble criteria_epsilon)
{
    static const char method_name[] = "calib3d::solvePnPRefineLM_10()";
    try {
        LOGD("%s", method_name);
        Mat& objectPoints = *((Mat*)objectPoints_nativeObj);
        Mat& imagePoints = *((Mat*)imagePoints_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        Mat& rvec = *((Mat*)rvec_nativeObj);
        Mat& tvec = *((Mat*)tvec_nativeObj);
        TermCriteria criteria(criteria_type, criteria_maxCount, criteria_epsilon);
        cv::solvePnPRefineLM( objectPoints, imagePoints, cameraMatrix, distCoeffs, rvec, tvec, criteria );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_solvePnPRefineLM_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_solvePnPRefineLM_11
  (JNIEnv* env, jclass , jlong objectPoints_nativeObj, jlong imagePoints_nativeObj, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong rvec_nativeObj, jlong tvec_nativeObj)
{
    static const char method_name[] = "calib3d::solvePnPRefineLM_11()";
    try {
        LOGD("%s", method_name);
        Mat& objectPoints = *((Mat*)objectPoints_nativeObj);
        Mat& imagePoints = *((Mat*)imagePoints_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        Mat& rvec = *((Mat*)rvec_nativeObj);
        Mat& tvec = *((Mat*)tvec_nativeObj);
        cv::solvePnPRefineLM( objectPoints, imagePoints, cameraMatrix, distCoeffs, rvec, tvec );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::solvePnPRefineVVS(Mat objectPoints, Mat imagePoints, Mat cameraMatrix, Mat distCoeffs, Mat& rvec, Mat& tvec, TermCriteria criteria = TermCriteria(TermCriteria::EPS + TermCriteria::COUNT, 20, FLT_EPSILON), double VVSlambda = 1)
//



JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_solvePnPRefineVVS_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jint, jint, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_solvePnPRefineVVS_10
  (JNIEnv* env, jclass , jlong objectPoints_nativeObj, jlong imagePoints_nativeObj, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong rvec_nativeObj, jlong tvec_nativeObj, jint criteria_type, jint criteria_maxCount, jdouble criteria_epsilon, jdouble VVSlambda)
{
    static const char method_name[] = "calib3d::solvePnPRefineVVS_10()";
    try {
        LOGD("%s", method_name);
        Mat& objectPoints = *((Mat*)objectPoints_nativeObj);
        Mat& imagePoints = *((Mat*)imagePoints_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        Mat& rvec = *((Mat*)rvec_nativeObj);
        Mat& tvec = *((Mat*)tvec_nativeObj);
        TermCriteria criteria(criteria_type, criteria_maxCount, criteria_epsilon);
        cv::solvePnPRefineVVS( objectPoints, imagePoints, cameraMatrix, distCoeffs, rvec, tvec, criteria, (double)VVSlambda );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_solvePnPRefineVVS_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jint, jint, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_solvePnPRefineVVS_11
  (JNIEnv* env, jclass , jlong objectPoints_nativeObj, jlong imagePoints_nativeObj, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong rvec_nativeObj, jlong tvec_nativeObj, jint criteria_type, jint criteria_maxCount, jdouble criteria_epsilon)
{
    static const char method_name[] = "calib3d::solvePnPRefineVVS_11()";
    try {
        LOGD("%s", method_name);
        Mat& objectPoints = *((Mat*)objectPoints_nativeObj);
        Mat& imagePoints = *((Mat*)imagePoints_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        Mat& rvec = *((Mat*)rvec_nativeObj);
        Mat& tvec = *((Mat*)tvec_nativeObj);
        TermCriteria criteria(criteria_type, criteria_maxCount, criteria_epsilon);
        cv::solvePnPRefineVVS( objectPoints, imagePoints, cameraMatrix, distCoeffs, rvec, tvec, criteria );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_solvePnPRefineVVS_12 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_solvePnPRefineVVS_12
  (JNIEnv* env, jclass , jlong objectPoints_nativeObj, jlong imagePoints_nativeObj, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong rvec_nativeObj, jlong tvec_nativeObj)
{
    static const char method_name[] = "calib3d::solvePnPRefineVVS_12()";
    try {
        LOGD("%s", method_name);
        Mat& objectPoints = *((Mat*)objectPoints_nativeObj);
        Mat& imagePoints = *((Mat*)imagePoints_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        Mat& rvec = *((Mat*)rvec_nativeObj);
        Mat& tvec = *((Mat*)tvec_nativeObj);
        cv::solvePnPRefineVVS( objectPoints, imagePoints, cameraMatrix, distCoeffs, rvec, tvec );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::stereoRectify(Mat cameraMatrix1, Mat distCoeffs1, Mat cameraMatrix2, Mat distCoeffs2, Size imageSize, Mat R, Mat T, Mat& R1, Mat& R2, Mat& P1, Mat& P2, Mat& Q, int flags = CALIB_ZERO_DISPARITY, double alpha = -1, Size newImageSize = Size(), Rect* validPixROI1 = 0, Rect* validPixROI2 = 0)
//



JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_stereoRectify_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jdouble, jdouble, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jint, jdouble, jdouble, jdouble, jdoubleArray, jdoubleArray);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_stereoRectify_10
  (JNIEnv* env, jclass , jlong cameraMatrix1_nativeObj, jlong distCoeffs1_nativeObj, jlong cameraMatrix2_nativeObj, jlong distCoeffs2_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jlong R_nativeObj, jlong T_nativeObj, jlong R1_nativeObj, jlong R2_nativeObj, jlong P1_nativeObj, jlong P2_nativeObj, jlong Q_nativeObj, jint flags, jdouble alpha, jdouble newImageSize_width, jdouble newImageSize_height, jdoubleArray validPixROI1_out, jdoubleArray validPixROI2_out)
{
    static const char method_name[] = "calib3d::stereoRectify_10()";
    try {
        LOGD("%s", method_name);
        Mat& cameraMatrix1 = *((Mat*)cameraMatrix1_nativeObj);
        Mat& distCoeffs1 = *((Mat*)distCoeffs1_nativeObj);
        Mat& cameraMatrix2 = *((Mat*)cameraMatrix2_nativeObj);
        Mat& distCoeffs2 = *((Mat*)distCoeffs2_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Mat& R = *((Mat*)R_nativeObj);
        Mat& T = *((Mat*)T_nativeObj);
        Mat& R1 = *((Mat*)R1_nativeObj);
        Mat& R2 = *((Mat*)R2_nativeObj);
        Mat& P1 = *((Mat*)P1_nativeObj);
        Mat& P2 = *((Mat*)P2_nativeObj);
        Mat& Q = *((Mat*)Q_nativeObj);
        Size newImageSize((int)newImageSize_width, (int)newImageSize_height);
        Rect validPixROI1;
        Rect validPixROI2;
        cv::stereoRectify( cameraMatrix1, distCoeffs1, cameraMatrix2, distCoeffs2, imageSize, R, T, R1, R2, P1, P2, Q, (int)flags, (double)alpha, newImageSize, &validPixROI1, &validPixROI2 );
        jdouble tmp_validPixROI1[4] = {(jdouble)validPixROI1.x, (jdouble)validPixROI1.y, (jdouble)validPixROI1.width, (jdouble)validPixROI1.height}; env->SetDoubleArrayRegion(validPixROI1_out, 0, 4, tmp_validPixROI1);
        jdouble tmp_validPixROI2[4] = {(jdouble)validPixROI2.x, (jdouble)validPixROI2.y, (jdouble)validPixROI2.width, (jdouble)validPixROI2.height}; env->SetDoubleArrayRegion(validPixROI2_out, 0, 4, tmp_validPixROI2);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_stereoRectify_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jdouble, jdouble, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jint, jdouble, jdouble, jdouble, jdoubleArray);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_stereoRectify_11
  (JNIEnv* env, jclass , jlong cameraMatrix1_nativeObj, jlong distCoeffs1_nativeObj, jlong cameraMatrix2_nativeObj, jlong distCoeffs2_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jlong R_nativeObj, jlong T_nativeObj, jlong R1_nativeObj, jlong R2_nativeObj, jlong P1_nativeObj, jlong P2_nativeObj, jlong Q_nativeObj, jint flags, jdouble alpha, jdouble newImageSize_width, jdouble newImageSize_height, jdoubleArray validPixROI1_out)
{
    static const char method_name[] = "calib3d::stereoRectify_11()";
    try {
        LOGD("%s", method_name);
        Mat& cameraMatrix1 = *((Mat*)cameraMatrix1_nativeObj);
        Mat& distCoeffs1 = *((Mat*)distCoeffs1_nativeObj);
        Mat& cameraMatrix2 = *((Mat*)cameraMatrix2_nativeObj);
        Mat& distCoeffs2 = *((Mat*)distCoeffs2_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Mat& R = *((Mat*)R_nativeObj);
        Mat& T = *((Mat*)T_nativeObj);
        Mat& R1 = *((Mat*)R1_nativeObj);
        Mat& R2 = *((Mat*)R2_nativeObj);
        Mat& P1 = *((Mat*)P1_nativeObj);
        Mat& P2 = *((Mat*)P2_nativeObj);
        Mat& Q = *((Mat*)Q_nativeObj);
        Size newImageSize((int)newImageSize_width, (int)newImageSize_height);
        Rect validPixROI1;
        cv::stereoRectify( cameraMatrix1, distCoeffs1, cameraMatrix2, distCoeffs2, imageSize, R, T, R1, R2, P1, P2, Q, (int)flags, (double)alpha, newImageSize, &validPixROI1 );
        jdouble tmp_validPixROI1[4] = {(jdouble)validPixROI1.x, (jdouble)validPixROI1.y, (jdouble)validPixROI1.width, (jdouble)validPixROI1.height}; env->SetDoubleArrayRegion(validPixROI1_out, 0, 4, tmp_validPixROI1);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_stereoRectify_12 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jdouble, jdouble, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jint, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_stereoRectify_12
  (JNIEnv* env, jclass , jlong cameraMatrix1_nativeObj, jlong distCoeffs1_nativeObj, jlong cameraMatrix2_nativeObj, jlong distCoeffs2_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jlong R_nativeObj, jlong T_nativeObj, jlong R1_nativeObj, jlong R2_nativeObj, jlong P1_nativeObj, jlong P2_nativeObj, jlong Q_nativeObj, jint flags, jdouble alpha, jdouble newImageSize_width, jdouble newImageSize_height)
{
    static const char method_name[] = "calib3d::stereoRectify_12()";
    try {
        LOGD("%s", method_name);
        Mat& cameraMatrix1 = *((Mat*)cameraMatrix1_nativeObj);
        Mat& distCoeffs1 = *((Mat*)distCoeffs1_nativeObj);
        Mat& cameraMatrix2 = *((Mat*)cameraMatrix2_nativeObj);
        Mat& distCoeffs2 = *((Mat*)distCoeffs2_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Mat& R = *((Mat*)R_nativeObj);
        Mat& T = *((Mat*)T_nativeObj);
        Mat& R1 = *((Mat*)R1_nativeObj);
        Mat& R2 = *((Mat*)R2_nativeObj);
        Mat& P1 = *((Mat*)P1_nativeObj);
        Mat& P2 = *((Mat*)P2_nativeObj);
        Mat& Q = *((Mat*)Q_nativeObj);
        Size newImageSize((int)newImageSize_width, (int)newImageSize_height);
        cv::stereoRectify( cameraMatrix1, distCoeffs1, cameraMatrix2, distCoeffs2, imageSize, R, T, R1, R2, P1, P2, Q, (int)flags, (double)alpha, newImageSize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_stereoRectify_13 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jdouble, jdouble, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jint, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_stereoRectify_13
  (JNIEnv* env, jclass , jlong cameraMatrix1_nativeObj, jlong distCoeffs1_nativeObj, jlong cameraMatrix2_nativeObj, jlong distCoeffs2_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jlong R_nativeObj, jlong T_nativeObj, jlong R1_nativeObj, jlong R2_nativeObj, jlong P1_nativeObj, jlong P2_nativeObj, jlong Q_nativeObj, jint flags, jdouble alpha)
{
    static const char method_name[] = "calib3d::stereoRectify_13()";
    try {
        LOGD("%s", method_name);
        Mat& cameraMatrix1 = *((Mat*)cameraMatrix1_nativeObj);
        Mat& distCoeffs1 = *((Mat*)distCoeffs1_nativeObj);
        Mat& cameraMatrix2 = *((Mat*)cameraMatrix2_nativeObj);
        Mat& distCoeffs2 = *((Mat*)distCoeffs2_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Mat& R = *((Mat*)R_nativeObj);
        Mat& T = *((Mat*)T_nativeObj);
        Mat& R1 = *((Mat*)R1_nativeObj);
        Mat& R2 = *((Mat*)R2_nativeObj);
        Mat& P1 = *((Mat*)P1_nativeObj);
        Mat& P2 = *((Mat*)P2_nativeObj);
        Mat& Q = *((Mat*)Q_nativeObj);
        cv::stereoRectify( cameraMatrix1, distCoeffs1, cameraMatrix2, distCoeffs2, imageSize, R, T, R1, R2, P1, P2, Q, (int)flags, (double)alpha );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_stereoRectify_14 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jdouble, jdouble, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_stereoRectify_14
  (JNIEnv* env, jclass , jlong cameraMatrix1_nativeObj, jlong distCoeffs1_nativeObj, jlong cameraMatrix2_nativeObj, jlong distCoeffs2_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jlong R_nativeObj, jlong T_nativeObj, jlong R1_nativeObj, jlong R2_nativeObj, jlong P1_nativeObj, jlong P2_nativeObj, jlong Q_nativeObj, jint flags)
{
    static const char method_name[] = "calib3d::stereoRectify_14()";
    try {
        LOGD("%s", method_name);
        Mat& cameraMatrix1 = *((Mat*)cameraMatrix1_nativeObj);
        Mat& distCoeffs1 = *((Mat*)distCoeffs1_nativeObj);
        Mat& cameraMatrix2 = *((Mat*)cameraMatrix2_nativeObj);
        Mat& distCoeffs2 = *((Mat*)distCoeffs2_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Mat& R = *((Mat*)R_nativeObj);
        Mat& T = *((Mat*)T_nativeObj);
        Mat& R1 = *((Mat*)R1_nativeObj);
        Mat& R2 = *((Mat*)R2_nativeObj);
        Mat& P1 = *((Mat*)P1_nativeObj);
        Mat& P2 = *((Mat*)P2_nativeObj);
        Mat& Q = *((Mat*)Q_nativeObj);
        cv::stereoRectify( cameraMatrix1, distCoeffs1, cameraMatrix2, distCoeffs2, imageSize, R, T, R1, R2, P1, P2, Q, (int)flags );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_stereoRectify_15 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jdouble, jdouble, jlong, jlong, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_stereoRectify_15
  (JNIEnv* env, jclass , jlong cameraMatrix1_nativeObj, jlong distCoeffs1_nativeObj, jlong cameraMatrix2_nativeObj, jlong distCoeffs2_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jlong R_nativeObj, jlong T_nativeObj, jlong R1_nativeObj, jlong R2_nativeObj, jlong P1_nativeObj, jlong P2_nativeObj, jlong Q_nativeObj)
{
    static const char method_name[] = "calib3d::stereoRectify_15()";
    try {
        LOGD("%s", method_name);
        Mat& cameraMatrix1 = *((Mat*)cameraMatrix1_nativeObj);
        Mat& distCoeffs1 = *((Mat*)distCoeffs1_nativeObj);
        Mat& cameraMatrix2 = *((Mat*)cameraMatrix2_nativeObj);
        Mat& distCoeffs2 = *((Mat*)distCoeffs2_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Mat& R = *((Mat*)R_nativeObj);
        Mat& T = *((Mat*)T_nativeObj);
        Mat& R1 = *((Mat*)R1_nativeObj);
        Mat& R2 = *((Mat*)R2_nativeObj);
        Mat& P1 = *((Mat*)P1_nativeObj);
        Mat& P2 = *((Mat*)P2_nativeObj);
        Mat& Q = *((Mat*)Q_nativeObj);
        cv::stereoRectify( cameraMatrix1, distCoeffs1, cameraMatrix2, distCoeffs2, imageSize, R, T, R1, R2, P1, P2, Q );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::triangulatePoints(Mat projMatr1, Mat projMatr2, Mat projPoints1, Mat projPoints2, Mat& points4D)
//



JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_triangulatePoints_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_triangulatePoints_10
  (JNIEnv* env, jclass , jlong projMatr1_nativeObj, jlong projMatr2_nativeObj, jlong projPoints1_nativeObj, jlong projPoints2_nativeObj, jlong points4D_nativeObj)
{
    static const char method_name[] = "calib3d::triangulatePoints_10()";
    try {
        LOGD("%s", method_name);
        Mat& projMatr1 = *((Mat*)projMatr1_nativeObj);
        Mat& projMatr2 = *((Mat*)projMatr2_nativeObj);
        Mat& projPoints1 = *((Mat*)projPoints1_nativeObj);
        Mat& projPoints2 = *((Mat*)projPoints2_nativeObj);
        Mat& points4D = *((Mat*)points4D_nativeObj);
        cv::triangulatePoints( projMatr1, projMatr2, projPoints1, projPoints2, points4D );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::undistort(Mat src, Mat& dst, Mat cameraMatrix, Mat distCoeffs, Mat newCameraMatrix = Mat())
//



JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_undistort_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_undistort_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong newCameraMatrix_nativeObj)
{
    static const char method_name[] = "calib3d::undistort_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        Mat& newCameraMatrix = *((Mat*)newCameraMatrix_nativeObj);
        cv::undistort( src, dst, cameraMatrix, distCoeffs, newCameraMatrix );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_undistort_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_undistort_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj)
{
    static const char method_name[] = "calib3d::undistort_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        cv::undistort( src, dst, cameraMatrix, distCoeffs );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::undistortPoints(Mat src, Mat& dst, Mat cameraMatrix, Mat distCoeffs, Mat R, Mat P, TermCriteria criteria)
//



JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_undistortPointsIter_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jint, jint, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_undistortPointsIter_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong R_nativeObj, jlong P_nativeObj, jint criteria_type, jint criteria_maxCount, jdouble criteria_epsilon)
{
    static const char method_name[] = "calib3d::undistortPointsIter_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        Mat& R = *((Mat*)R_nativeObj);
        Mat& P = *((Mat*)P_nativeObj);
        TermCriteria criteria(criteria_type, criteria_maxCount, criteria_epsilon);
        cv::undistortPoints( src, dst, cameraMatrix, distCoeffs, R, P, criteria );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::undistortPoints(vector_Point2f src, vector_Point2f& dst, Mat cameraMatrix, Mat distCoeffs, Mat R = Mat(), Mat P = Mat())
//



JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_undistortPoints_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_undistortPoints_10
  (JNIEnv* env, jclass , jlong src_mat_nativeObj, jlong dst_mat_nativeObj, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong R_nativeObj, jlong P_nativeObj)
{
    static const char method_name[] = "calib3d::undistortPoints_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Point2f> src;
        Mat& src_mat = *((Mat*)src_mat_nativeObj);
        Mat_to_vector_Point2f( src_mat, src );
        std::vector<Point2f> dst;
        Mat& dst_mat = *((Mat*)dst_mat_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        Mat& R = *((Mat*)R_nativeObj);
        Mat& P = *((Mat*)P_nativeObj);
        cv::undistortPoints( src, dst, cameraMatrix, distCoeffs, R, P );
        vector_Point2f_to_Mat( dst, dst_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_undistortPoints_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_undistortPoints_11
  (JNIEnv* env, jclass , jlong src_mat_nativeObj, jlong dst_mat_nativeObj, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong R_nativeObj)
{
    static const char method_name[] = "calib3d::undistortPoints_11()";
    try {
        LOGD("%s", method_name);
        std::vector<Point2f> src;
        Mat& src_mat = *((Mat*)src_mat_nativeObj);
        Mat_to_vector_Point2f( src_mat, src );
        std::vector<Point2f> dst;
        Mat& dst_mat = *((Mat*)dst_mat_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        Mat& R = *((Mat*)R_nativeObj);
        cv::undistortPoints( src, dst, cameraMatrix, distCoeffs, R );
        vector_Point2f_to_Mat( dst, dst_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_undistortPoints_12 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_undistortPoints_12
  (JNIEnv* env, jclass , jlong src_mat_nativeObj, jlong dst_mat_nativeObj, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj)
{
    static const char method_name[] = "calib3d::undistortPoints_12()";
    try {
        LOGD("%s", method_name);
        std::vector<Point2f> src;
        Mat& src_mat = *((Mat*)src_mat_nativeObj);
        Mat_to_vector_Point2f( src_mat, src );
        std::vector<Point2f> dst;
        Mat& dst_mat = *((Mat*)dst_mat_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        cv::undistortPoints( src, dst, cameraMatrix, distCoeffs );
        vector_Point2f_to_Mat( dst, dst_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::validateDisparity(Mat& disparity, Mat cost, int minDisparity, int numberOfDisparities, int disp12MaxDisp = 1)
//



JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_validateDisparity_10 (JNIEnv*, jclass, jlong, jlong, jint, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_validateDisparity_10
  (JNIEnv* env, jclass , jlong disparity_nativeObj, jlong cost_nativeObj, jint minDisparity, jint numberOfDisparities, jint disp12MaxDisp)
{
    static const char method_name[] = "calib3d::validateDisparity_10()";
    try {
        LOGD("%s", method_name);
        Mat& disparity = *((Mat*)disparity_nativeObj);
        Mat& cost = *((Mat*)cost_nativeObj);
        cv::validateDisparity( disparity, cost, (int)minDisparity, (int)numberOfDisparities, (int)disp12MaxDisp );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_validateDisparity_11 (JNIEnv*, jclass, jlong, jlong, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_validateDisparity_11
  (JNIEnv* env, jclass , jlong disparity_nativeObj, jlong cost_nativeObj, jint minDisparity, jint numberOfDisparities)
{
    static const char method_name[] = "calib3d::validateDisparity_11()";
    try {
        LOGD("%s", method_name);
        Mat& disparity = *((Mat*)disparity_nativeObj);
        Mat& cost = *((Mat*)cost_nativeObj);
        cv::validateDisparity( disparity, cost, (int)minDisparity, (int)numberOfDisparities );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::fisheye::distortPoints(Mat undistorted, Mat& distorted, Mat K, Mat D, double alpha = 0)
//



JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1distortPoints_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1distortPoints_10
  (JNIEnv* env, jclass , jlong undistorted_nativeObj, jlong distorted_nativeObj, jlong K_nativeObj, jlong D_nativeObj, jdouble alpha)
{
    static const char method_name[] = "calib3d::fisheye_1distortPoints_10()";
    try {
        LOGD("%s", method_name);
        Mat& undistorted = *((Mat*)undistorted_nativeObj);
        Mat& distorted = *((Mat*)distorted_nativeObj);
        Mat& K = *((Mat*)K_nativeObj);
        Mat& D = *((Mat*)D_nativeObj);
        cv::fisheye::distortPoints( undistorted, distorted, K, D, (double)alpha );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1distortPoints_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1distortPoints_11
  (JNIEnv* env, jclass , jlong undistorted_nativeObj, jlong distorted_nativeObj, jlong K_nativeObj, jlong D_nativeObj)
{
    static const char method_name[] = "calib3d::fisheye_1distortPoints_11()";
    try {
        LOGD("%s", method_name);
        Mat& undistorted = *((Mat*)undistorted_nativeObj);
        Mat& distorted = *((Mat*)distorted_nativeObj);
        Mat& K = *((Mat*)K_nativeObj);
        Mat& D = *((Mat*)D_nativeObj);
        cv::fisheye::distortPoints( undistorted, distorted, K, D );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::fisheye::estimateNewCameraMatrixForUndistortRectify(Mat K, Mat D, Size image_size, Mat R, Mat& P, double balance = 0.0, Size new_size = Size(), double fov_scale = 1.0)
//



JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1estimateNewCameraMatrixForUndistortRectify_10 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jlong, jlong, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1estimateNewCameraMatrixForUndistortRectify_10
  (JNIEnv* env, jclass , jlong K_nativeObj, jlong D_nativeObj, jdouble image_size_width, jdouble image_size_height, jlong R_nativeObj, jlong P_nativeObj, jdouble balance, jdouble new_size_width, jdouble new_size_height, jdouble fov_scale)
{
    static const char method_name[] = "calib3d::fisheye_1estimateNewCameraMatrixForUndistortRectify_10()";
    try {
        LOGD("%s", method_name);
        Mat& K = *((Mat*)K_nativeObj);
        Mat& D = *((Mat*)D_nativeObj);
        Size image_size((int)image_size_width, (int)image_size_height);
        Mat& R = *((Mat*)R_nativeObj);
        Mat& P = *((Mat*)P_nativeObj);
        Size new_size((int)new_size_width, (int)new_size_height);
        cv::fisheye::estimateNewCameraMatrixForUndistortRectify( K, D, image_size, R, P, (double)balance, new_size, (double)fov_scale );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1estimateNewCameraMatrixForUndistortRectify_11 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jlong, jlong, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1estimateNewCameraMatrixForUndistortRectify_11
  (JNIEnv* env, jclass , jlong K_nativeObj, jlong D_nativeObj, jdouble image_size_width, jdouble image_size_height, jlong R_nativeObj, jlong P_nativeObj, jdouble balance, jdouble new_size_width, jdouble new_size_height)
{
    static const char method_name[] = "calib3d::fisheye_1estimateNewCameraMatrixForUndistortRectify_11()";
    try {
        LOGD("%s", method_name);
        Mat& K = *((Mat*)K_nativeObj);
        Mat& D = *((Mat*)D_nativeObj);
        Size image_size((int)image_size_width, (int)image_size_height);
        Mat& R = *((Mat*)R_nativeObj);
        Mat& P = *((Mat*)P_nativeObj);
        Size new_size((int)new_size_width, (int)new_size_height);
        cv::fisheye::estimateNewCameraMatrixForUndistortRectify( K, D, image_size, R, P, (double)balance, new_size );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1estimateNewCameraMatrixForUndistortRectify_12 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jlong, jlong, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1estimateNewCameraMatrixForUndistortRectify_12
  (JNIEnv* env, jclass , jlong K_nativeObj, jlong D_nativeObj, jdouble image_size_width, jdouble image_size_height, jlong R_nativeObj, jlong P_nativeObj, jdouble balance)
{
    static const char method_name[] = "calib3d::fisheye_1estimateNewCameraMatrixForUndistortRectify_12()";
    try {
        LOGD("%s", method_name);
        Mat& K = *((Mat*)K_nativeObj);
        Mat& D = *((Mat*)D_nativeObj);
        Size image_size((int)image_size_width, (int)image_size_height);
        Mat& R = *((Mat*)R_nativeObj);
        Mat& P = *((Mat*)P_nativeObj);
        cv::fisheye::estimateNewCameraMatrixForUndistortRectify( K, D, image_size, R, P, (double)balance );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1estimateNewCameraMatrixForUndistortRectify_13 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1estimateNewCameraMatrixForUndistortRectify_13
  (JNIEnv* env, jclass , jlong K_nativeObj, jlong D_nativeObj, jdouble image_size_width, jdouble image_size_height, jlong R_nativeObj, jlong P_nativeObj)
{
    static const char method_name[] = "calib3d::fisheye_1estimateNewCameraMatrixForUndistortRectify_13()";
    try {
        LOGD("%s", method_name);
        Mat& K = *((Mat*)K_nativeObj);
        Mat& D = *((Mat*)D_nativeObj);
        Size image_size((int)image_size_width, (int)image_size_height);
        Mat& R = *((Mat*)R_nativeObj);
        Mat& P = *((Mat*)P_nativeObj);
        cv::fisheye::estimateNewCameraMatrixForUndistortRectify( K, D, image_size, R, P );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::fisheye::initUndistortRectifyMap(Mat K, Mat D, Mat R, Mat P, Size size, int m1type, Mat& map1, Mat& map2)
//



JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1initUndistortRectifyMap_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jdouble, jdouble, jint, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1initUndistortRectifyMap_10
  (JNIEnv* env, jclass , jlong K_nativeObj, jlong D_nativeObj, jlong R_nativeObj, jlong P_nativeObj, jdouble size_width, jdouble size_height, jint m1type, jlong map1_nativeObj, jlong map2_nativeObj)
{
    static const char method_name[] = "calib3d::fisheye_1initUndistortRectifyMap_10()";
    try {
        LOGD("%s", method_name);
        Mat& K = *((Mat*)K_nativeObj);
        Mat& D = *((Mat*)D_nativeObj);
        Mat& R = *((Mat*)R_nativeObj);
        Mat& P = *((Mat*)P_nativeObj);
        Size size((int)size_width, (int)size_height);
        Mat& map1 = *((Mat*)map1_nativeObj);
        Mat& map2 = *((Mat*)map2_nativeObj);
        cv::fisheye::initUndistortRectifyMap( K, D, R, P, size, (int)m1type, map1, map2 );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::fisheye::projectPoints(Mat objectPoints, Mat& imagePoints, Mat rvec, Mat tvec, Mat K, Mat D, double alpha = 0, Mat& jacobian = Mat())
//



JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1projectPoints_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jdouble, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1projectPoints_10
  (JNIEnv* env, jclass , jlong objectPoints_nativeObj, jlong imagePoints_nativeObj, jlong rvec_nativeObj, jlong tvec_nativeObj, jlong K_nativeObj, jlong D_nativeObj, jdouble alpha, jlong jacobian_nativeObj)
{
    static const char method_name[] = "calib3d::fisheye_1projectPoints_10()";
    try {
        LOGD("%s", method_name);
        Mat& objectPoints = *((Mat*)objectPoints_nativeObj);
        Mat& imagePoints = *((Mat*)imagePoints_nativeObj);
        Mat& rvec = *((Mat*)rvec_nativeObj);
        Mat& tvec = *((Mat*)tvec_nativeObj);
        Mat& K = *((Mat*)K_nativeObj);
        Mat& D = *((Mat*)D_nativeObj);
        Mat& jacobian = *((Mat*)jacobian_nativeObj);
        cv::fisheye::projectPoints( objectPoints, imagePoints, rvec, tvec, K, D, (double)alpha, jacobian );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1projectPoints_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1projectPoints_11
  (JNIEnv* env, jclass , jlong objectPoints_nativeObj, jlong imagePoints_nativeObj, jlong rvec_nativeObj, jlong tvec_nativeObj, jlong K_nativeObj, jlong D_nativeObj, jdouble alpha)
{
    static const char method_name[] = "calib3d::fisheye_1projectPoints_11()";
    try {
        LOGD("%s", method_name);
        Mat& objectPoints = *((Mat*)objectPoints_nativeObj);
        Mat& imagePoints = *((Mat*)imagePoints_nativeObj);
        Mat& rvec = *((Mat*)rvec_nativeObj);
        Mat& tvec = *((Mat*)tvec_nativeObj);
        Mat& K = *((Mat*)K_nativeObj);
        Mat& D = *((Mat*)D_nativeObj);
        cv::fisheye::projectPoints( objectPoints, imagePoints, rvec, tvec, K, D, (double)alpha );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1projectPoints_12 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1projectPoints_12
  (JNIEnv* env, jclass , jlong objectPoints_nativeObj, jlong imagePoints_nativeObj, jlong rvec_nativeObj, jlong tvec_nativeObj, jlong K_nativeObj, jlong D_nativeObj)
{
    static const char method_name[] = "calib3d::fisheye_1projectPoints_12()";
    try {
        LOGD("%s", method_name);
        Mat& objectPoints = *((Mat*)objectPoints_nativeObj);
        Mat& imagePoints = *((Mat*)imagePoints_nativeObj);
        Mat& rvec = *((Mat*)rvec_nativeObj);
        Mat& tvec = *((Mat*)tvec_nativeObj);
        Mat& K = *((Mat*)K_nativeObj);
        Mat& D = *((Mat*)D_nativeObj);
        cv::fisheye::projectPoints( objectPoints, imagePoints, rvec, tvec, K, D );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::fisheye::stereoRectify(Mat K1, Mat D1, Mat K2, Mat D2, Size imageSize, Mat R, Mat tvec, Mat& R1, Mat& R2, Mat& P1, Mat& P2, Mat& Q, int flags, Size newImageSize = Size(), double balance = 0.0, double fov_scale = 1.0)
//



JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1stereoRectify_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jdouble, jdouble, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jint, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1stereoRectify_10
  (JNIEnv* env, jclass , jlong K1_nativeObj, jlong D1_nativeObj, jlong K2_nativeObj, jlong D2_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jlong R_nativeObj, jlong tvec_nativeObj, jlong R1_nativeObj, jlong R2_nativeObj, jlong P1_nativeObj, jlong P2_nativeObj, jlong Q_nativeObj, jint flags, jdouble newImageSize_width, jdouble newImageSize_height, jdouble balance, jdouble fov_scale)
{
    static const char method_name[] = "calib3d::fisheye_1stereoRectify_10()";
    try {
        LOGD("%s", method_name);
        Mat& K1 = *((Mat*)K1_nativeObj);
        Mat& D1 = *((Mat*)D1_nativeObj);
        Mat& K2 = *((Mat*)K2_nativeObj);
        Mat& D2 = *((Mat*)D2_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Mat& R = *((Mat*)R_nativeObj);
        Mat& tvec = *((Mat*)tvec_nativeObj);
        Mat& R1 = *((Mat*)R1_nativeObj);
        Mat& R2 = *((Mat*)R2_nativeObj);
        Mat& P1 = *((Mat*)P1_nativeObj);
        Mat& P2 = *((Mat*)P2_nativeObj);
        Mat& Q = *((Mat*)Q_nativeObj);
        Size newImageSize((int)newImageSize_width, (int)newImageSize_height);
        cv::fisheye::stereoRectify( K1, D1, K2, D2, imageSize, R, tvec, R1, R2, P1, P2, Q, (int)flags, newImageSize, (double)balance, (double)fov_scale );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1stereoRectify_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jdouble, jdouble, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jint, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1stereoRectify_11
  (JNIEnv* env, jclass , jlong K1_nativeObj, jlong D1_nativeObj, jlong K2_nativeObj, jlong D2_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jlong R_nativeObj, jlong tvec_nativeObj, jlong R1_nativeObj, jlong R2_nativeObj, jlong P1_nativeObj, jlong P2_nativeObj, jlong Q_nativeObj, jint flags, jdouble newImageSize_width, jdouble newImageSize_height, jdouble balance)
{
    static const char method_name[] = "calib3d::fisheye_1stereoRectify_11()";
    try {
        LOGD("%s", method_name);
        Mat& K1 = *((Mat*)K1_nativeObj);
        Mat& D1 = *((Mat*)D1_nativeObj);
        Mat& K2 = *((Mat*)K2_nativeObj);
        Mat& D2 = *((Mat*)D2_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Mat& R = *((Mat*)R_nativeObj);
        Mat& tvec = *((Mat*)tvec_nativeObj);
        Mat& R1 = *((Mat*)R1_nativeObj);
        Mat& R2 = *((Mat*)R2_nativeObj);
        Mat& P1 = *((Mat*)P1_nativeObj);
        Mat& P2 = *((Mat*)P2_nativeObj);
        Mat& Q = *((Mat*)Q_nativeObj);
        Size newImageSize((int)newImageSize_width, (int)newImageSize_height);
        cv::fisheye::stereoRectify( K1, D1, K2, D2, imageSize, R, tvec, R1, R2, P1, P2, Q, (int)flags, newImageSize, (double)balance );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1stereoRectify_12 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jdouble, jdouble, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jint, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1stereoRectify_12
  (JNIEnv* env, jclass , jlong K1_nativeObj, jlong D1_nativeObj, jlong K2_nativeObj, jlong D2_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jlong R_nativeObj, jlong tvec_nativeObj, jlong R1_nativeObj, jlong R2_nativeObj, jlong P1_nativeObj, jlong P2_nativeObj, jlong Q_nativeObj, jint flags, jdouble newImageSize_width, jdouble newImageSize_height)
{
    static const char method_name[] = "calib3d::fisheye_1stereoRectify_12()";
    try {
        LOGD("%s", method_name);
        Mat& K1 = *((Mat*)K1_nativeObj);
        Mat& D1 = *((Mat*)D1_nativeObj);
        Mat& K2 = *((Mat*)K2_nativeObj);
        Mat& D2 = *((Mat*)D2_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Mat& R = *((Mat*)R_nativeObj);
        Mat& tvec = *((Mat*)tvec_nativeObj);
        Mat& R1 = *((Mat*)R1_nativeObj);
        Mat& R2 = *((Mat*)R2_nativeObj);
        Mat& P1 = *((Mat*)P1_nativeObj);
        Mat& P2 = *((Mat*)P2_nativeObj);
        Mat& Q = *((Mat*)Q_nativeObj);
        Size newImageSize((int)newImageSize_width, (int)newImageSize_height);
        cv::fisheye::stereoRectify( K1, D1, K2, D2, imageSize, R, tvec, R1, R2, P1, P2, Q, (int)flags, newImageSize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1stereoRectify_13 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jdouble, jdouble, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1stereoRectify_13
  (JNIEnv* env, jclass , jlong K1_nativeObj, jlong D1_nativeObj, jlong K2_nativeObj, jlong D2_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jlong R_nativeObj, jlong tvec_nativeObj, jlong R1_nativeObj, jlong R2_nativeObj, jlong P1_nativeObj, jlong P2_nativeObj, jlong Q_nativeObj, jint flags)
{
    static const char method_name[] = "calib3d::fisheye_1stereoRectify_13()";
    try {
        LOGD("%s", method_name);
        Mat& K1 = *((Mat*)K1_nativeObj);
        Mat& D1 = *((Mat*)D1_nativeObj);
        Mat& K2 = *((Mat*)K2_nativeObj);
        Mat& D2 = *((Mat*)D2_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Mat& R = *((Mat*)R_nativeObj);
        Mat& tvec = *((Mat*)tvec_nativeObj);
        Mat& R1 = *((Mat*)R1_nativeObj);
        Mat& R2 = *((Mat*)R2_nativeObj);
        Mat& P1 = *((Mat*)P1_nativeObj);
        Mat& P2 = *((Mat*)P2_nativeObj);
        Mat& Q = *((Mat*)Q_nativeObj);
        cv::fisheye::stereoRectify( K1, D1, K2, D2, imageSize, R, tvec, R1, R2, P1, P2, Q, (int)flags );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::fisheye::undistortImage(Mat distorted, Mat& undistorted, Mat K, Mat D, Mat Knew = cv::Mat(), Size new_size = Size())
//



JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1undistortImage_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1undistortImage_10
  (JNIEnv* env, jclass , jlong distorted_nativeObj, jlong undistorted_nativeObj, jlong K_nativeObj, jlong D_nativeObj, jlong Knew_nativeObj, jdouble new_size_width, jdouble new_size_height)
{
    static const char method_name[] = "calib3d::fisheye_1undistortImage_10()";
    try {
        LOGD("%s", method_name);
        Mat& distorted = *((Mat*)distorted_nativeObj);
        Mat& undistorted = *((Mat*)undistorted_nativeObj);
        Mat& K = *((Mat*)K_nativeObj);
        Mat& D = *((Mat*)D_nativeObj);
        Mat& Knew = *((Mat*)Knew_nativeObj);
        Size new_size((int)new_size_width, (int)new_size_height);
        cv::fisheye::undistortImage( distorted, undistorted, K, D, Knew, new_size );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1undistortImage_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1undistortImage_11
  (JNIEnv* env, jclass , jlong distorted_nativeObj, jlong undistorted_nativeObj, jlong K_nativeObj, jlong D_nativeObj, jlong Knew_nativeObj)
{
    static const char method_name[] = "calib3d::fisheye_1undistortImage_11()";
    try {
        LOGD("%s", method_name);
        Mat& distorted = *((Mat*)distorted_nativeObj);
        Mat& undistorted = *((Mat*)undistorted_nativeObj);
        Mat& K = *((Mat*)K_nativeObj);
        Mat& D = *((Mat*)D_nativeObj);
        Mat& Knew = *((Mat*)Knew_nativeObj);
        cv::fisheye::undistortImage( distorted, undistorted, K, D, Knew );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1undistortImage_12 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1undistortImage_12
  (JNIEnv* env, jclass , jlong distorted_nativeObj, jlong undistorted_nativeObj, jlong K_nativeObj, jlong D_nativeObj)
{
    static const char method_name[] = "calib3d::fisheye_1undistortImage_12()";
    try {
        LOGD("%s", method_name);
        Mat& distorted = *((Mat*)distorted_nativeObj);
        Mat& undistorted = *((Mat*)undistorted_nativeObj);
        Mat& K = *((Mat*)K_nativeObj);
        Mat& D = *((Mat*)D_nativeObj);
        cv::fisheye::undistortImage( distorted, undistorted, K, D );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::fisheye::undistortPoints(Mat distorted, Mat& undistorted, Mat K, Mat D, Mat R = Mat(), Mat P = Mat())
//



JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1undistortPoints_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1undistortPoints_10
  (JNIEnv* env, jclass , jlong distorted_nativeObj, jlong undistorted_nativeObj, jlong K_nativeObj, jlong D_nativeObj, jlong R_nativeObj, jlong P_nativeObj)
{
    static const char method_name[] = "calib3d::fisheye_1undistortPoints_10()";
    try {
        LOGD("%s", method_name);
        Mat& distorted = *((Mat*)distorted_nativeObj);
        Mat& undistorted = *((Mat*)undistorted_nativeObj);
        Mat& K = *((Mat*)K_nativeObj);
        Mat& D = *((Mat*)D_nativeObj);
        Mat& R = *((Mat*)R_nativeObj);
        Mat& P = *((Mat*)P_nativeObj);
        cv::fisheye::undistortPoints( distorted, undistorted, K, D, R, P );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1undistortPoints_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1undistortPoints_11
  (JNIEnv* env, jclass , jlong distorted_nativeObj, jlong undistorted_nativeObj, jlong K_nativeObj, jlong D_nativeObj, jlong R_nativeObj)
{
    static const char method_name[] = "calib3d::fisheye_1undistortPoints_11()";
    try {
        LOGD("%s", method_name);
        Mat& distorted = *((Mat*)distorted_nativeObj);
        Mat& undistorted = *((Mat*)undistorted_nativeObj);
        Mat& K = *((Mat*)K_nativeObj);
        Mat& D = *((Mat*)D_nativeObj);
        Mat& R = *((Mat*)R_nativeObj);
        cv::fisheye::undistortPoints( distorted, undistorted, K, D, R );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1undistortPoints_12 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_calib3d_Calib3d_fisheye_1undistortPoints_12
  (JNIEnv* env, jclass , jlong distorted_nativeObj, jlong undistorted_nativeObj, jlong K_nativeObj, jlong D_nativeObj)
{
    static const char method_name[] = "calib3d::fisheye_1undistortPoints_12()";
    try {
        LOGD("%s", method_name);
        Mat& distorted = *((Mat*)distorted_nativeObj);
        Mat& undistorted = *((Mat*)undistorted_nativeObj);
        Mat& K = *((Mat*)K_nativeObj);
        Mat& D = *((Mat*)D_nativeObj);
        cv::fisheye::undistortPoints( distorted, undistorted, K, D );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}




} // extern "C"

#endif // HAVE_OPENCV_CALIB3D
