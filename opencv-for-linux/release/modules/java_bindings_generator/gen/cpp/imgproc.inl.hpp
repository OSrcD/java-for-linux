//
// This file is auto-generated. Please don't modify it!
//

#undef LOG_TAG

#include "opencv2/opencv_modules.hpp"
#ifdef HAVE_OPENCV_IMGPROC

#include <string>

#include "opencv2/imgproc.hpp"

#include "/Users/virtualman/Downloads/MySource/opencv-4.3.0/modules/imgproc/include/opencv2/imgproc/types_c.h"
#include "/Users/virtualman/Downloads/MySource/opencv-4.3.0/modules/imgproc/include/opencv2/imgproc.hpp"

#define LOG_TAG "org.opencv.imgproc"
#include "common.h"

using namespace cv;

/// throw java exception
#undef throwJavaException
#define throwJavaException throwJavaException_imgproc
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
//  Mat cv::getAffineTransform(vector_Point2f src, vector_Point2f dst)
//



JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_getAffineTransform_10 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_getAffineTransform_10
  (JNIEnv* env, jclass , jlong src_mat_nativeObj, jlong dst_mat_nativeObj)
{
    static const char method_name[] = "imgproc::getAffineTransform_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Point2f> src;
        Mat& src_mat = *((Mat*)src_mat_nativeObj);
        Mat_to_vector_Point2f( src_mat, src );
        std::vector<Point2f> dst;
        Mat& dst_mat = *((Mat*)dst_mat_nativeObj);
        Mat_to_vector_Point2f( dst_mat, dst );
        ::Mat _retval_ = cv::getAffineTransform( src, dst );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Mat cv::getGaborKernel(Size ksize, double sigma, double theta, double lambd, double gamma, double psi = CV_PI*0.5, int ktype = CV_64F)
//



JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_getGaborKernel_10 (JNIEnv*, jclass, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_getGaborKernel_10
  (JNIEnv* env, jclass , jdouble ksize_width, jdouble ksize_height, jdouble sigma, jdouble theta, jdouble lambd, jdouble gamma, jdouble psi, jint ktype)
{
    static const char method_name[] = "imgproc::getGaborKernel_10()";
    try {
        LOGD("%s", method_name);
        Size ksize((int)ksize_width, (int)ksize_height);
        ::Mat _retval_ = cv::getGaborKernel( ksize, (double)sigma, (double)theta, (double)lambd, (double)gamma, (double)psi, (int)ktype );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_getGaborKernel_11 (JNIEnv*, jclass, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_getGaborKernel_11
  (JNIEnv* env, jclass , jdouble ksize_width, jdouble ksize_height, jdouble sigma, jdouble theta, jdouble lambd, jdouble gamma, jdouble psi)
{
    static const char method_name[] = "imgproc::getGaborKernel_11()";
    try {
        LOGD("%s", method_name);
        Size ksize((int)ksize_width, (int)ksize_height);
        ::Mat _retval_ = cv::getGaborKernel( ksize, (double)sigma, (double)theta, (double)lambd, (double)gamma, (double)psi );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_getGaborKernel_12 (JNIEnv*, jclass, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_getGaborKernel_12
  (JNIEnv* env, jclass , jdouble ksize_width, jdouble ksize_height, jdouble sigma, jdouble theta, jdouble lambd, jdouble gamma)
{
    static const char method_name[] = "imgproc::getGaborKernel_12()";
    try {
        LOGD("%s", method_name);
        Size ksize((int)ksize_width, (int)ksize_height);
        ::Mat _retval_ = cv::getGaborKernel( ksize, (double)sigma, (double)theta, (double)lambd, (double)gamma );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Mat cv::getGaussianKernel(int ksize, double sigma, int ktype = CV_64F)
//



JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_getGaussianKernel_10 (JNIEnv*, jclass, jint, jdouble, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_getGaussianKernel_10
  (JNIEnv* env, jclass , jint ksize, jdouble sigma, jint ktype)
{
    static const char method_name[] = "imgproc::getGaussianKernel_10()";
    try {
        LOGD("%s", method_name);
        ::Mat _retval_ = cv::getGaussianKernel( (int)ksize, (double)sigma, (int)ktype );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_getGaussianKernel_11 (JNIEnv*, jclass, jint, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_getGaussianKernel_11
  (JNIEnv* env, jclass , jint ksize, jdouble sigma)
{
    static const char method_name[] = "imgproc::getGaussianKernel_11()";
    try {
        LOGD("%s", method_name);
        ::Mat _retval_ = cv::getGaussianKernel( (int)ksize, (double)sigma );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Mat cv::getPerspectiveTransform(Mat src, Mat dst, int solveMethod = DECOMP_LU)
//



JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_getPerspectiveTransform_10 (JNIEnv*, jclass, jlong, jlong, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_getPerspectiveTransform_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint solveMethod)
{
    static const char method_name[] = "imgproc::getPerspectiveTransform_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        ::Mat _retval_ = cv::getPerspectiveTransform( src, dst, (int)solveMethod );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_getPerspectiveTransform_11 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_getPerspectiveTransform_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "imgproc::getPerspectiveTransform_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        ::Mat _retval_ = cv::getPerspectiveTransform( src, dst );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Mat cv::getRotationMatrix2D(Point2f center, double angle, double scale)
//



JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_getRotationMatrix2D_10 (JNIEnv*, jclass, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_getRotationMatrix2D_10
  (JNIEnv* env, jclass , jdouble center_x, jdouble center_y, jdouble angle, jdouble scale)
{
    static const char method_name[] = "imgproc::getRotationMatrix2D_10()";
    try {
        LOGD("%s", method_name);
        Point2f center((float)center_x, (float)center_y);
        ::Mat _retval_ = cv::getRotationMatrix2D( center, (double)angle, (double)scale );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Mat cv::getStructuringElement(int shape, Size ksize, Point anchor = Point(-1,-1))
//



JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_getStructuringElement_10 (JNIEnv*, jclass, jint, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_getStructuringElement_10
  (JNIEnv* env, jclass , jint shape, jdouble ksize_width, jdouble ksize_height, jdouble anchor_x, jdouble anchor_y)
{
    static const char method_name[] = "imgproc::getStructuringElement_10()";
    try {
        LOGD("%s", method_name);
        Size ksize((int)ksize_width, (int)ksize_height);
        Point anchor((int)anchor_x, (int)anchor_y);
        ::Mat _retval_ = cv::getStructuringElement( (int)shape, ksize, anchor );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_getStructuringElement_11 (JNIEnv*, jclass, jint, jdouble, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_getStructuringElement_11
  (JNIEnv* env, jclass , jint shape, jdouble ksize_width, jdouble ksize_height)
{
    static const char method_name[] = "imgproc::getStructuringElement_11()";
    try {
        LOGD("%s", method_name);
        Size ksize((int)ksize_width, (int)ksize_height);
        ::Mat _retval_ = cv::getStructuringElement( (int)shape, ksize );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Moments cv::moments(Mat array, bool binaryImage = false)
//



JNIEXPORT jdoubleArray JNICALL Java_org_opencv_imgproc_Imgproc_moments_10 (JNIEnv*, jclass, jlong, jboolean);

JNIEXPORT jdoubleArray JNICALL Java_org_opencv_imgproc_Imgproc_moments_10
  (JNIEnv* env, jclass , jlong array_nativeObj, jboolean binaryImage)
{
    static const char method_name[] = "imgproc::moments_10()";
    try {
        LOGD("%s", method_name);
        Mat& array = *((Mat*)array_nativeObj);
        Moments _retval_ = cv::moments( array, (bool)binaryImage );
        jdoubleArray _da_retval_ = env->NewDoubleArray(10);  jdouble _tmp_retval_[10] = {(jdouble)_retval_.m00, (jdouble)_retval_.m10, (jdouble)_retval_.m01, (jdouble)_retval_.m20, (jdouble)_retval_.m11, (jdouble)_retval_.m02, (jdouble)_retval_.m30, (jdouble)_retval_.m21, (jdouble)_retval_.m12, (jdouble)_retval_.m03}; env->SetDoubleArrayRegion(_da_retval_, 0, 10, _tmp_retval_);
        return _da_retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jdoubleArray JNICALL Java_org_opencv_imgproc_Imgproc_moments_11 (JNIEnv*, jclass, jlong);

JNIEXPORT jdoubleArray JNICALL Java_org_opencv_imgproc_Imgproc_moments_11
  (JNIEnv* env, jclass , jlong array_nativeObj)
{
    static const char method_name[] = "imgproc::moments_11()";
    try {
        LOGD("%s", method_name);
        Mat& array = *((Mat*)array_nativeObj);
        Moments _retval_ = cv::moments( array );
        jdoubleArray _da_retval_ = env->NewDoubleArray(10);  jdouble _tmp_retval_[10] = {(jdouble)_retval_.m00, (jdouble)_retval_.m10, (jdouble)_retval_.m01, (jdouble)_retval_.m20, (jdouble)_retval_.m11, (jdouble)_retval_.m02, (jdouble)_retval_.m30, (jdouble)_retval_.m21, (jdouble)_retval_.m12, (jdouble)_retval_.m03}; env->SetDoubleArrayRegion(_da_retval_, 0, 10, _tmp_retval_);
        return _da_retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Point2d cv::phaseCorrelate(Mat src1, Mat src2, Mat window = Mat(), double* response = 0)
//



JNIEXPORT jdoubleArray JNICALL Java_org_opencv_imgproc_Imgproc_phaseCorrelate_10 (JNIEnv*, jclass, jlong, jlong, jlong, jdoubleArray);

JNIEXPORT jdoubleArray JNICALL Java_org_opencv_imgproc_Imgproc_phaseCorrelate_10
  (JNIEnv* env, jclass , jlong src1_nativeObj, jlong src2_nativeObj, jlong window_nativeObj, jdoubleArray response_out)
{
    static const char method_name[] = "imgproc::phaseCorrelate_10()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Mat& src2 = *((Mat*)src2_nativeObj);
        Mat& window = *((Mat*)window_nativeObj);
        double response;
        Point2d _retval_ = cv::phaseCorrelate( src1, src2, window, &response );
        jdoubleArray _da_retval_ = env->NewDoubleArray(2);  jdouble _tmp_retval_[2] = {(jdouble)_retval_.x, (jdouble)_retval_.y}; env->SetDoubleArrayRegion(_da_retval_, 0, 2, _tmp_retval_);
        jdouble tmp_response[1] = {(jdouble)response}; env->SetDoubleArrayRegion(response_out, 0, 1, tmp_response);
        return _da_retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jdoubleArray JNICALL Java_org_opencv_imgproc_Imgproc_phaseCorrelate_11 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT jdoubleArray JNICALL Java_org_opencv_imgproc_Imgproc_phaseCorrelate_11
  (JNIEnv* env, jclass , jlong src1_nativeObj, jlong src2_nativeObj, jlong window_nativeObj)
{
    static const char method_name[] = "imgproc::phaseCorrelate_11()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Mat& src2 = *((Mat*)src2_nativeObj);
        Mat& window = *((Mat*)window_nativeObj);
        Point2d _retval_ = cv::phaseCorrelate( src1, src2, window );
        jdoubleArray _da_retval_ = env->NewDoubleArray(2);  jdouble _tmp_retval_[2] = {(jdouble)_retval_.x, (jdouble)_retval_.y}; env->SetDoubleArrayRegion(_da_retval_, 0, 2, _tmp_retval_);
        return _da_retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jdoubleArray JNICALL Java_org_opencv_imgproc_Imgproc_phaseCorrelate_12 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT jdoubleArray JNICALL Java_org_opencv_imgproc_Imgproc_phaseCorrelate_12
  (JNIEnv* env, jclass , jlong src1_nativeObj, jlong src2_nativeObj)
{
    static const char method_name[] = "imgproc::phaseCorrelate_12()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Mat& src2 = *((Mat*)src2_nativeObj);
        Point2d _retval_ = cv::phaseCorrelate( src1, src2 );
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
//  Ptr_CLAHE cv::createCLAHE(double clipLimit = 40.0, Size tileGridSize = Size(8, 8))
//



JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_createCLAHE_10 (JNIEnv*, jclass, jdouble, jdouble, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_createCLAHE_10
  (JNIEnv* env, jclass , jdouble clipLimit, jdouble tileGridSize_width, jdouble tileGridSize_height)
{
    static const char method_name[] = "imgproc::createCLAHE_10()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::CLAHE> Ptr_CLAHE;
        Size tileGridSize((int)tileGridSize_width, (int)tileGridSize_height);
        Ptr_CLAHE _retval_ = cv::createCLAHE( (double)clipLimit, tileGridSize );
        return (jlong)(new Ptr_CLAHE(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_createCLAHE_11 (JNIEnv*, jclass, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_createCLAHE_11
  (JNIEnv* env, jclass , jdouble clipLimit)
{
    static const char method_name[] = "imgproc::createCLAHE_11()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::CLAHE> Ptr_CLAHE;
        Ptr_CLAHE _retval_ = cv::createCLAHE( (double)clipLimit );
        return (jlong)(new Ptr_CLAHE(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_createCLAHE_12 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_createCLAHE_12
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "imgproc::createCLAHE_12()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::CLAHE> Ptr_CLAHE;
        Ptr_CLAHE _retval_ = cv::createCLAHE();
        return (jlong)(new Ptr_CLAHE(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Ptr_GeneralizedHoughBallard cv::createGeneralizedHoughBallard()
//



JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_createGeneralizedHoughBallard_10 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_createGeneralizedHoughBallard_10
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "imgproc::createGeneralizedHoughBallard_10()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::GeneralizedHoughBallard> Ptr_GeneralizedHoughBallard;
        Ptr_GeneralizedHoughBallard _retval_ = cv::createGeneralizedHoughBallard();
        return (jlong)(new Ptr_GeneralizedHoughBallard(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Ptr_GeneralizedHoughGuil cv::createGeneralizedHoughGuil()
//



JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_createGeneralizedHoughGuil_10 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_createGeneralizedHoughGuil_10
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "imgproc::createGeneralizedHoughGuil_10()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::GeneralizedHoughGuil> Ptr_GeneralizedHoughGuil;
        Ptr_GeneralizedHoughGuil _retval_ = cv::createGeneralizedHoughGuil();
        return (jlong)(new Ptr_GeneralizedHoughGuil(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Ptr_LineSegmentDetector cv::createLineSegmentDetector(int _refine = LSD_REFINE_STD, double _scale = 0.8, double _sigma_scale = 0.6, double _quant = 2.0, double _ang_th = 22.5, double _log_eps = 0, double _density_th = 0.7, int _n_bins = 1024)
//



JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_createLineSegmentDetector_10 (JNIEnv*, jclass, jint, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_createLineSegmentDetector_10
  (JNIEnv* env, jclass , jint _refine, jdouble _scale, jdouble _sigma_scale, jdouble _quant, jdouble _ang_th, jdouble _log_eps, jdouble _density_th, jint _n_bins)
{
    static const char method_name[] = "imgproc::createLineSegmentDetector_10()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::LineSegmentDetector> Ptr_LineSegmentDetector;
        Ptr_LineSegmentDetector _retval_ = cv::createLineSegmentDetector( (int)_refine, (double)_scale, (double)_sigma_scale, (double)_quant, (double)_ang_th, (double)_log_eps, (double)_density_th, (int)_n_bins );
        return (jlong)(new Ptr_LineSegmentDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_createLineSegmentDetector_11 (JNIEnv*, jclass, jint, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_createLineSegmentDetector_11
  (JNIEnv* env, jclass , jint _refine, jdouble _scale, jdouble _sigma_scale, jdouble _quant, jdouble _ang_th, jdouble _log_eps, jdouble _density_th)
{
    static const char method_name[] = "imgproc::createLineSegmentDetector_11()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::LineSegmentDetector> Ptr_LineSegmentDetector;
        Ptr_LineSegmentDetector _retval_ = cv::createLineSegmentDetector( (int)_refine, (double)_scale, (double)_sigma_scale, (double)_quant, (double)_ang_th, (double)_log_eps, (double)_density_th );
        return (jlong)(new Ptr_LineSegmentDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_createLineSegmentDetector_12 (JNIEnv*, jclass, jint, jdouble, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_createLineSegmentDetector_12
  (JNIEnv* env, jclass , jint _refine, jdouble _scale, jdouble _sigma_scale, jdouble _quant, jdouble _ang_th, jdouble _log_eps)
{
    static const char method_name[] = "imgproc::createLineSegmentDetector_12()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::LineSegmentDetector> Ptr_LineSegmentDetector;
        Ptr_LineSegmentDetector _retval_ = cv::createLineSegmentDetector( (int)_refine, (double)_scale, (double)_sigma_scale, (double)_quant, (double)_ang_th, (double)_log_eps );
        return (jlong)(new Ptr_LineSegmentDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_createLineSegmentDetector_13 (JNIEnv*, jclass, jint, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_createLineSegmentDetector_13
  (JNIEnv* env, jclass , jint _refine, jdouble _scale, jdouble _sigma_scale, jdouble _quant, jdouble _ang_th)
{
    static const char method_name[] = "imgproc::createLineSegmentDetector_13()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::LineSegmentDetector> Ptr_LineSegmentDetector;
        Ptr_LineSegmentDetector _retval_ = cv::createLineSegmentDetector( (int)_refine, (double)_scale, (double)_sigma_scale, (double)_quant, (double)_ang_th );
        return (jlong)(new Ptr_LineSegmentDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_createLineSegmentDetector_14 (JNIEnv*, jclass, jint, jdouble, jdouble, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_createLineSegmentDetector_14
  (JNIEnv* env, jclass , jint _refine, jdouble _scale, jdouble _sigma_scale, jdouble _quant)
{
    static const char method_name[] = "imgproc::createLineSegmentDetector_14()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::LineSegmentDetector> Ptr_LineSegmentDetector;
        Ptr_LineSegmentDetector _retval_ = cv::createLineSegmentDetector( (int)_refine, (double)_scale, (double)_sigma_scale, (double)_quant );
        return (jlong)(new Ptr_LineSegmentDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_createLineSegmentDetector_15 (JNIEnv*, jclass, jint, jdouble, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_createLineSegmentDetector_15
  (JNIEnv* env, jclass , jint _refine, jdouble _scale, jdouble _sigma_scale)
{
    static const char method_name[] = "imgproc::createLineSegmentDetector_15()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::LineSegmentDetector> Ptr_LineSegmentDetector;
        Ptr_LineSegmentDetector _retval_ = cv::createLineSegmentDetector( (int)_refine, (double)_scale, (double)_sigma_scale );
        return (jlong)(new Ptr_LineSegmentDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_createLineSegmentDetector_16 (JNIEnv*, jclass, jint, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_createLineSegmentDetector_16
  (JNIEnv* env, jclass , jint _refine, jdouble _scale)
{
    static const char method_name[] = "imgproc::createLineSegmentDetector_16()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::LineSegmentDetector> Ptr_LineSegmentDetector;
        Ptr_LineSegmentDetector _retval_ = cv::createLineSegmentDetector( (int)_refine, (double)_scale );
        return (jlong)(new Ptr_LineSegmentDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_createLineSegmentDetector_17 (JNIEnv*, jclass, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_createLineSegmentDetector_17
  (JNIEnv* env, jclass , jint _refine)
{
    static const char method_name[] = "imgproc::createLineSegmentDetector_17()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::LineSegmentDetector> Ptr_LineSegmentDetector;
        Ptr_LineSegmentDetector _retval_ = cv::createLineSegmentDetector( (int)_refine );
        return (jlong)(new Ptr_LineSegmentDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_createLineSegmentDetector_18 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Imgproc_createLineSegmentDetector_18
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "imgproc::createLineSegmentDetector_18()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::LineSegmentDetector> Ptr_LineSegmentDetector;
        Ptr_LineSegmentDetector _retval_ = cv::createLineSegmentDetector();
        return (jlong)(new Ptr_LineSegmentDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Rect cv::boundingRect(Mat array)
//



JNIEXPORT jdoubleArray JNICALL Java_org_opencv_imgproc_Imgproc_boundingRect_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jdoubleArray JNICALL Java_org_opencv_imgproc_Imgproc_boundingRect_10
  (JNIEnv* env, jclass , jlong array_nativeObj)
{
    static const char method_name[] = "imgproc::boundingRect_10()";
    try {
        LOGD("%s", method_name);
        Mat& array = *((Mat*)array_nativeObj);
        Rect _retval_ = cv::boundingRect( array );
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
//  RotatedRect cv::fitEllipse(vector_Point2f points)
//



JNIEXPORT jdoubleArray JNICALL Java_org_opencv_imgproc_Imgproc_fitEllipse_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jdoubleArray JNICALL Java_org_opencv_imgproc_Imgproc_fitEllipse_10
  (JNIEnv* env, jclass , jlong points_mat_nativeObj)
{
    static const char method_name[] = "imgproc::fitEllipse_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Point2f> points;
        Mat& points_mat = *((Mat*)points_mat_nativeObj);
        Mat_to_vector_Point2f( points_mat, points );
        RotatedRect _retval_ = cv::fitEllipse( points );
        jdoubleArray _da_retval_ = env->NewDoubleArray(5);  jdouble _tmp_retval_[5] = {(jdouble)_retval_.center.x, (jdouble)_retval_.center.y, (jdouble)_retval_.size.width, (jdouble)_retval_.size.height, (jdouble)_retval_.angle}; env->SetDoubleArrayRegion(_da_retval_, 0, 5, _tmp_retval_);
        return _da_retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  RotatedRect cv::fitEllipseAMS(Mat points)
//



JNIEXPORT jdoubleArray JNICALL Java_org_opencv_imgproc_Imgproc_fitEllipseAMS_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jdoubleArray JNICALL Java_org_opencv_imgproc_Imgproc_fitEllipseAMS_10
  (JNIEnv* env, jclass , jlong points_nativeObj)
{
    static const char method_name[] = "imgproc::fitEllipseAMS_10()";
    try {
        LOGD("%s", method_name);
        Mat& points = *((Mat*)points_nativeObj);
        RotatedRect _retval_ = cv::fitEllipseAMS( points );
        jdoubleArray _da_retval_ = env->NewDoubleArray(5);  jdouble _tmp_retval_[5] = {(jdouble)_retval_.center.x, (jdouble)_retval_.center.y, (jdouble)_retval_.size.width, (jdouble)_retval_.size.height, (jdouble)_retval_.angle}; env->SetDoubleArrayRegion(_da_retval_, 0, 5, _tmp_retval_);
        return _da_retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  RotatedRect cv::fitEllipseDirect(Mat points)
//



JNIEXPORT jdoubleArray JNICALL Java_org_opencv_imgproc_Imgproc_fitEllipseDirect_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jdoubleArray JNICALL Java_org_opencv_imgproc_Imgproc_fitEllipseDirect_10
  (JNIEnv* env, jclass , jlong points_nativeObj)
{
    static const char method_name[] = "imgproc::fitEllipseDirect_10()";
    try {
        LOGD("%s", method_name);
        Mat& points = *((Mat*)points_nativeObj);
        RotatedRect _retval_ = cv::fitEllipseDirect( points );
        jdoubleArray _da_retval_ = env->NewDoubleArray(5);  jdouble _tmp_retval_[5] = {(jdouble)_retval_.center.x, (jdouble)_retval_.center.y, (jdouble)_retval_.size.width, (jdouble)_retval_.size.height, (jdouble)_retval_.angle}; env->SetDoubleArrayRegion(_da_retval_, 0, 5, _tmp_retval_);
        return _da_retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  RotatedRect cv::minAreaRect(vector_Point2f points)
//



JNIEXPORT jdoubleArray JNICALL Java_org_opencv_imgproc_Imgproc_minAreaRect_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jdoubleArray JNICALL Java_org_opencv_imgproc_Imgproc_minAreaRect_10
  (JNIEnv* env, jclass , jlong points_mat_nativeObj)
{
    static const char method_name[] = "imgproc::minAreaRect_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Point2f> points;
        Mat& points_mat = *((Mat*)points_mat_nativeObj);
        Mat_to_vector_Point2f( points_mat, points );
        RotatedRect _retval_ = cv::minAreaRect( points );
        jdoubleArray _da_retval_ = env->NewDoubleArray(5);  jdouble _tmp_retval_[5] = {(jdouble)_retval_.center.x, (jdouble)_retval_.center.y, (jdouble)_retval_.size.width, (jdouble)_retval_.size.height, (jdouble)_retval_.angle}; env->SetDoubleArrayRegion(_da_retval_, 0, 5, _tmp_retval_);
        return _da_retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  bool cv::clipLine(Rect imgRect, Point& pt1, Point& pt2)
//



JNIEXPORT jboolean JNICALL Java_org_opencv_imgproc_Imgproc_clipLine_10 (JNIEnv*, jclass, jint, jint, jint, jint, jdouble, jdouble, jdoubleArray, jdouble, jdouble, jdoubleArray);

JNIEXPORT jboolean JNICALL Java_org_opencv_imgproc_Imgproc_clipLine_10
  (JNIEnv* env, jclass , jint imgRect_x, jint imgRect_y, jint imgRect_width, jint imgRect_height, jdouble pt1_x, jdouble pt1_y, jdoubleArray pt1_out, jdouble pt2_x, jdouble pt2_y, jdoubleArray pt2_out)
{
    static const char method_name[] = "imgproc::clipLine_10()";
    try {
        LOGD("%s", method_name);
        Rect imgRect(imgRect_x, imgRect_y, imgRect_width, imgRect_height);
        Point pt1((int)pt1_x, (int)pt1_y);
        Point pt2((int)pt2_x, (int)pt2_y);
        bool _retval_ = cv::clipLine( imgRect, pt1, pt2 );
        jdouble tmp_pt1[2] = {(jdouble)pt1.x, (jdouble)pt1.y}; env->SetDoubleArrayRegion(pt1_out, 0, 2, tmp_pt1);
        jdouble tmp_pt2[2] = {(jdouble)pt2.x, (jdouble)pt2.y}; env->SetDoubleArrayRegion(pt2_out, 0, 2, tmp_pt2);
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  bool cv::isContourConvex(vector_Point contour)
//



JNIEXPORT jboolean JNICALL Java_org_opencv_imgproc_Imgproc_isContourConvex_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_imgproc_Imgproc_isContourConvex_10
  (JNIEnv* env, jclass , jlong contour_mat_nativeObj)
{
    static const char method_name[] = "imgproc::isContourConvex_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Point> contour;
        Mat& contour_mat = *((Mat*)contour_mat_nativeObj);
        Mat_to_vector_Point( contour_mat, contour );
        return cv::isContourConvex( contour );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::arcLength(vector_Point2f curve, bool closed)
//



JNIEXPORT jdouble JNICALL Java_org_opencv_imgproc_Imgproc_arcLength_10 (JNIEnv*, jclass, jlong, jboolean);

JNIEXPORT jdouble JNICALL Java_org_opencv_imgproc_Imgproc_arcLength_10
  (JNIEnv* env, jclass , jlong curve_mat_nativeObj, jboolean closed)
{
    static const char method_name[] = "imgproc::arcLength_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Point2f> curve;
        Mat& curve_mat = *((Mat*)curve_mat_nativeObj);
        Mat_to_vector_Point2f( curve_mat, curve );
        return cv::arcLength( curve, (bool)closed );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::compareHist(Mat H1, Mat H2, int method)
//



JNIEXPORT jdouble JNICALL Java_org_opencv_imgproc_Imgproc_compareHist_10 (JNIEnv*, jclass, jlong, jlong, jint);

JNIEXPORT jdouble JNICALL Java_org_opencv_imgproc_Imgproc_compareHist_10
  (JNIEnv* env, jclass , jlong H1_nativeObj, jlong H2_nativeObj, jint method)
{
    static const char method_name[] = "imgproc::compareHist_10()";
    try {
        LOGD("%s", method_name);
        Mat& H1 = *((Mat*)H1_nativeObj);
        Mat& H2 = *((Mat*)H2_nativeObj);
        return cv::compareHist( H1, H2, (int)method );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::contourArea(Mat contour, bool oriented = false)
//



JNIEXPORT jdouble JNICALL Java_org_opencv_imgproc_Imgproc_contourArea_10 (JNIEnv*, jclass, jlong, jboolean);

JNIEXPORT jdouble JNICALL Java_org_opencv_imgproc_Imgproc_contourArea_10
  (JNIEnv* env, jclass , jlong contour_nativeObj, jboolean oriented)
{
    static const char method_name[] = "imgproc::contourArea_10()";
    try {
        LOGD("%s", method_name);
        Mat& contour = *((Mat*)contour_nativeObj);
        return cv::contourArea( contour, (bool)oriented );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jdouble JNICALL Java_org_opencv_imgproc_Imgproc_contourArea_11 (JNIEnv*, jclass, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_imgproc_Imgproc_contourArea_11
  (JNIEnv* env, jclass , jlong contour_nativeObj)
{
    static const char method_name[] = "imgproc::contourArea_11()";
    try {
        LOGD("%s", method_name);
        Mat& contour = *((Mat*)contour_nativeObj);
        return cv::contourArea( contour );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::getFontScaleFromHeight(int fontFace, int pixelHeight, int thickness = 1)
//



JNIEXPORT jdouble JNICALL Java_org_opencv_imgproc_Imgproc_getFontScaleFromHeight_10 (JNIEnv*, jclass, jint, jint, jint);

JNIEXPORT jdouble JNICALL Java_org_opencv_imgproc_Imgproc_getFontScaleFromHeight_10
  (JNIEnv* env, jclass , jint fontFace, jint pixelHeight, jint thickness)
{
    static const char method_name[] = "imgproc::getFontScaleFromHeight_10()";
    try {
        LOGD("%s", method_name);
        return cv::getFontScaleFromHeight( (int)fontFace, (int)pixelHeight, (int)thickness );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jdouble JNICALL Java_org_opencv_imgproc_Imgproc_getFontScaleFromHeight_11 (JNIEnv*, jclass, jint, jint);

JNIEXPORT jdouble JNICALL Java_org_opencv_imgproc_Imgproc_getFontScaleFromHeight_11
  (JNIEnv* env, jclass , jint fontFace, jint pixelHeight)
{
    static const char method_name[] = "imgproc::getFontScaleFromHeight_11()";
    try {
        LOGD("%s", method_name);
        return cv::getFontScaleFromHeight( (int)fontFace, (int)pixelHeight );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::matchShapes(Mat contour1, Mat contour2, int method, double parameter)
//



JNIEXPORT jdouble JNICALL Java_org_opencv_imgproc_Imgproc_matchShapes_10 (JNIEnv*, jclass, jlong, jlong, jint, jdouble);

JNIEXPORT jdouble JNICALL Java_org_opencv_imgproc_Imgproc_matchShapes_10
  (JNIEnv* env, jclass , jlong contour1_nativeObj, jlong contour2_nativeObj, jint method, jdouble parameter)
{
    static const char method_name[] = "imgproc::matchShapes_10()";
    try {
        LOGD("%s", method_name);
        Mat& contour1 = *((Mat*)contour1_nativeObj);
        Mat& contour2 = *((Mat*)contour2_nativeObj);
        return cv::matchShapes( contour1, contour2, (int)method, (double)parameter );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::minEnclosingTriangle(Mat points, Mat& triangle)
//



JNIEXPORT jdouble JNICALL Java_org_opencv_imgproc_Imgproc_minEnclosingTriangle_10 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_imgproc_Imgproc_minEnclosingTriangle_10
  (JNIEnv* env, jclass , jlong points_nativeObj, jlong triangle_nativeObj)
{
    static const char method_name[] = "imgproc::minEnclosingTriangle_10()";
    try {
        LOGD("%s", method_name);
        Mat& points = *((Mat*)points_nativeObj);
        Mat& triangle = *((Mat*)triangle_nativeObj);
        return cv::minEnclosingTriangle( points, triangle );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::pointPolygonTest(vector_Point2f contour, Point2f pt, bool measureDist)
//



JNIEXPORT jdouble JNICALL Java_org_opencv_imgproc_Imgproc_pointPolygonTest_10 (JNIEnv*, jclass, jlong, jdouble, jdouble, jboolean);

JNIEXPORT jdouble JNICALL Java_org_opencv_imgproc_Imgproc_pointPolygonTest_10
  (JNIEnv* env, jclass , jlong contour_mat_nativeObj, jdouble pt_x, jdouble pt_y, jboolean measureDist)
{
    static const char method_name[] = "imgproc::pointPolygonTest_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Point2f> contour;
        Mat& contour_mat = *((Mat*)contour_mat_nativeObj);
        Mat_to_vector_Point2f( contour_mat, contour );
        Point2f pt((float)pt_x, (float)pt_y);
        return cv::pointPolygonTest( contour, pt, (bool)measureDist );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::threshold(Mat src, Mat& dst, double thresh, double maxval, int type)
//



JNIEXPORT jdouble JNICALL Java_org_opencv_imgproc_Imgproc_threshold_10 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jint);

JNIEXPORT jdouble JNICALL Java_org_opencv_imgproc_Imgproc_threshold_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jdouble thresh, jdouble maxval, jint type)
{
    static const char method_name[] = "imgproc::threshold_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        return cv::threshold( src, dst, (double)thresh, (double)maxval, (int)type );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  float cv::intersectConvexConvex(Mat _p1, Mat _p2, Mat& _p12, bool handleNested = true)
//



JNIEXPORT jfloat JNICALL Java_org_opencv_imgproc_Imgproc_intersectConvexConvex_10 (JNIEnv*, jclass, jlong, jlong, jlong, jboolean);

JNIEXPORT jfloat JNICALL Java_org_opencv_imgproc_Imgproc_intersectConvexConvex_10
  (JNIEnv* env, jclass , jlong _p1_nativeObj, jlong _p2_nativeObj, jlong _p12_nativeObj, jboolean handleNested)
{
    static const char method_name[] = "imgproc::intersectConvexConvex_10()";
    try {
        LOGD("%s", method_name);
        Mat& _p1 = *((Mat*)_p1_nativeObj);
        Mat& _p2 = *((Mat*)_p2_nativeObj);
        Mat& _p12 = *((Mat*)_p12_nativeObj);
        return cv::intersectConvexConvex( _p1, _p2, _p12, (bool)handleNested );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jfloat JNICALL Java_org_opencv_imgproc_Imgproc_intersectConvexConvex_11 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_imgproc_Imgproc_intersectConvexConvex_11
  (JNIEnv* env, jclass , jlong _p1_nativeObj, jlong _p2_nativeObj, jlong _p12_nativeObj)
{
    static const char method_name[] = "imgproc::intersectConvexConvex_11()";
    try {
        LOGD("%s", method_name);
        Mat& _p1 = *((Mat*)_p1_nativeObj);
        Mat& _p2 = *((Mat*)_p2_nativeObj);
        Mat& _p12 = *((Mat*)_p12_nativeObj);
        return cv::intersectConvexConvex( _p1, _p2, _p12 );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  float cv::wrapperEMD(Mat signature1, Mat signature2, int distType, Mat cost = Mat(), Ptr_float& lowerBound = Ptr<float>(), Mat& flow = Mat())
//



JNIEXPORT jfloat JNICALL Java_org_opencv_imgproc_Imgproc_EMD_10 (JNIEnv*, jclass, jlong, jlong, jint, jlong, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_imgproc_Imgproc_EMD_10
  (JNIEnv* env, jclass , jlong signature1_nativeObj, jlong signature2_nativeObj, jint distType, jlong cost_nativeObj, jlong flow_nativeObj)
{
    static const char method_name[] = "imgproc::EMD_10()";
    try {
        LOGD("%s", method_name);
        Mat& signature1 = *((Mat*)signature1_nativeObj);
        Mat& signature2 = *((Mat*)signature2_nativeObj);
        Mat& cost = *((Mat*)cost_nativeObj);
        Mat& flow = *((Mat*)flow_nativeObj);
        return cv::wrapperEMD( signature1, signature2, (int)distType, cost, Ptr<float>(), flow );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jfloat JNICALL Java_org_opencv_imgproc_Imgproc_EMD_11 (JNIEnv*, jclass, jlong, jlong, jint, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_imgproc_Imgproc_EMD_11
  (JNIEnv* env, jclass , jlong signature1_nativeObj, jlong signature2_nativeObj, jint distType, jlong cost_nativeObj)
{
    static const char method_name[] = "imgproc::EMD_11()";
    try {
        LOGD("%s", method_name);
        Mat& signature1 = *((Mat*)signature1_nativeObj);
        Mat& signature2 = *((Mat*)signature2_nativeObj);
        Mat& cost = *((Mat*)cost_nativeObj);
        return cv::wrapperEMD( signature1, signature2, (int)distType, cost, Ptr<float>() );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jfloat JNICALL Java_org_opencv_imgproc_Imgproc_EMD_13 (JNIEnv*, jclass, jlong, jlong, jint);

JNIEXPORT jfloat JNICALL Java_org_opencv_imgproc_Imgproc_EMD_13
  (JNIEnv* env, jclass , jlong signature1_nativeObj, jlong signature2_nativeObj, jint distType)
{
    static const char method_name[] = "imgproc::EMD_13()";
    try {
        LOGD("%s", method_name);
        Mat& signature1 = *((Mat*)signature1_nativeObj);
        Mat& signature2 = *((Mat*)signature2_nativeObj);
        return cv::wrapperEMD( signature1, signature2, (int)distType );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::connectedComponents(Mat image, Mat& labels, int connectivity, int ltype, int ccltype)
//



JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Imgproc_connectedComponentsWithAlgorithm_10 (JNIEnv*, jclass, jlong, jlong, jint, jint, jint);

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Imgproc_connectedComponentsWithAlgorithm_10
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong labels_nativeObj, jint connectivity, jint ltype, jint ccltype)
{
    static const char method_name[] = "imgproc::connectedComponentsWithAlgorithm_10()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& labels = *((Mat*)labels_nativeObj);
        return cv::connectedComponents( image, labels, (int)connectivity, (int)ltype, (int)ccltype );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::connectedComponents(Mat image, Mat& labels, int connectivity = 8, int ltype = CV_32S)
//



JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Imgproc_connectedComponents_10 (JNIEnv*, jclass, jlong, jlong, jint, jint);

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Imgproc_connectedComponents_10
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong labels_nativeObj, jint connectivity, jint ltype)
{
    static const char method_name[] = "imgproc::connectedComponents_10()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& labels = *((Mat*)labels_nativeObj);
        return cv::connectedComponents( image, labels, (int)connectivity, (int)ltype );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Imgproc_connectedComponents_11 (JNIEnv*, jclass, jlong, jlong, jint);

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Imgproc_connectedComponents_11
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong labels_nativeObj, jint connectivity)
{
    static const char method_name[] = "imgproc::connectedComponents_11()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& labels = *((Mat*)labels_nativeObj);
        return cv::connectedComponents( image, labels, (int)connectivity );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Imgproc_connectedComponents_12 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Imgproc_connectedComponents_12
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong labels_nativeObj)
{
    static const char method_name[] = "imgproc::connectedComponents_12()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& labels = *((Mat*)labels_nativeObj);
        return cv::connectedComponents( image, labels );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::connectedComponentsWithStats(Mat image, Mat& labels, Mat& stats, Mat& centroids, int connectivity, int ltype, int ccltype)
//



JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Imgproc_connectedComponentsWithStatsWithAlgorithm_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jint, jint, jint);

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Imgproc_connectedComponentsWithStatsWithAlgorithm_10
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong labels_nativeObj, jlong stats_nativeObj, jlong centroids_nativeObj, jint connectivity, jint ltype, jint ccltype)
{
    static const char method_name[] = "imgproc::connectedComponentsWithStatsWithAlgorithm_10()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& labels = *((Mat*)labels_nativeObj);
        Mat& stats = *((Mat*)stats_nativeObj);
        Mat& centroids = *((Mat*)centroids_nativeObj);
        return cv::connectedComponentsWithStats( image, labels, stats, centroids, (int)connectivity, (int)ltype, (int)ccltype );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::connectedComponentsWithStats(Mat image, Mat& labels, Mat& stats, Mat& centroids, int connectivity = 8, int ltype = CV_32S)
//



JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Imgproc_connectedComponentsWithStats_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jint, jint);

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Imgproc_connectedComponentsWithStats_10
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong labels_nativeObj, jlong stats_nativeObj, jlong centroids_nativeObj, jint connectivity, jint ltype)
{
    static const char method_name[] = "imgproc::connectedComponentsWithStats_10()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& labels = *((Mat*)labels_nativeObj);
        Mat& stats = *((Mat*)stats_nativeObj);
        Mat& centroids = *((Mat*)centroids_nativeObj);
        return cv::connectedComponentsWithStats( image, labels, stats, centroids, (int)connectivity, (int)ltype );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Imgproc_connectedComponentsWithStats_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jint);

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Imgproc_connectedComponentsWithStats_11
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong labels_nativeObj, jlong stats_nativeObj, jlong centroids_nativeObj, jint connectivity)
{
    static const char method_name[] = "imgproc::connectedComponentsWithStats_11()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& labels = *((Mat*)labels_nativeObj);
        Mat& stats = *((Mat*)stats_nativeObj);
        Mat& centroids = *((Mat*)centroids_nativeObj);
        return cv::connectedComponentsWithStats( image, labels, stats, centroids, (int)connectivity );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Imgproc_connectedComponentsWithStats_12 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Imgproc_connectedComponentsWithStats_12
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong labels_nativeObj, jlong stats_nativeObj, jlong centroids_nativeObj)
{
    static const char method_name[] = "imgproc::connectedComponentsWithStats_12()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& labels = *((Mat*)labels_nativeObj);
        Mat& stats = *((Mat*)stats_nativeObj);
        Mat& centroids = *((Mat*)centroids_nativeObj);
        return cv::connectedComponentsWithStats( image, labels, stats, centroids );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::floodFill(Mat& image, Mat& mask, Point seedPoint, Scalar newVal, Rect* rect = 0, Scalar loDiff = Scalar(), Scalar upDiff = Scalar(), int flags = 4)
//



JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Imgproc_floodFill_10 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdoubleArray, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jint);

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Imgproc_floodFill_10
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong mask_nativeObj, jdouble seedPoint_x, jdouble seedPoint_y, jdouble newVal_val0, jdouble newVal_val1, jdouble newVal_val2, jdouble newVal_val3, jdoubleArray rect_out, jdouble loDiff_val0, jdouble loDiff_val1, jdouble loDiff_val2, jdouble loDiff_val3, jdouble upDiff_val0, jdouble upDiff_val1, jdouble upDiff_val2, jdouble upDiff_val3, jint flags)
{
    static const char method_name[] = "imgproc::floodFill_10()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        Point seedPoint((int)seedPoint_x, (int)seedPoint_y);
        Scalar newVal(newVal_val0, newVal_val1, newVal_val2, newVal_val3);
        Rect rect;
        Scalar loDiff(loDiff_val0, loDiff_val1, loDiff_val2, loDiff_val3);
        Scalar upDiff(upDiff_val0, upDiff_val1, upDiff_val2, upDiff_val3);
        int _retval_ = cv::floodFill( image, mask, seedPoint, newVal, &rect, loDiff, upDiff, (int)flags );
        jdouble tmp_rect[4] = {(jdouble)rect.x, (jdouble)rect.y, (jdouble)rect.width, (jdouble)rect.height}; env->SetDoubleArrayRegion(rect_out, 0, 4, tmp_rect);
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Imgproc_floodFill_11 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdoubleArray, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Imgproc_floodFill_11
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong mask_nativeObj, jdouble seedPoint_x, jdouble seedPoint_y, jdouble newVal_val0, jdouble newVal_val1, jdouble newVal_val2, jdouble newVal_val3, jdoubleArray rect_out, jdouble loDiff_val0, jdouble loDiff_val1, jdouble loDiff_val2, jdouble loDiff_val3, jdouble upDiff_val0, jdouble upDiff_val1, jdouble upDiff_val2, jdouble upDiff_val3)
{
    static const char method_name[] = "imgproc::floodFill_11()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        Point seedPoint((int)seedPoint_x, (int)seedPoint_y);
        Scalar newVal(newVal_val0, newVal_val1, newVal_val2, newVal_val3);
        Rect rect;
        Scalar loDiff(loDiff_val0, loDiff_val1, loDiff_val2, loDiff_val3);
        Scalar upDiff(upDiff_val0, upDiff_val1, upDiff_val2, upDiff_val3);
        int _retval_ = cv::floodFill( image, mask, seedPoint, newVal, &rect, loDiff, upDiff );
        jdouble tmp_rect[4] = {(jdouble)rect.x, (jdouble)rect.y, (jdouble)rect.width, (jdouble)rect.height}; env->SetDoubleArrayRegion(rect_out, 0, 4, tmp_rect);
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Imgproc_floodFill_12 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdoubleArray, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Imgproc_floodFill_12
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong mask_nativeObj, jdouble seedPoint_x, jdouble seedPoint_y, jdouble newVal_val0, jdouble newVal_val1, jdouble newVal_val2, jdouble newVal_val3, jdoubleArray rect_out, jdouble loDiff_val0, jdouble loDiff_val1, jdouble loDiff_val2, jdouble loDiff_val3)
{
    static const char method_name[] = "imgproc::floodFill_12()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        Point seedPoint((int)seedPoint_x, (int)seedPoint_y);
        Scalar newVal(newVal_val0, newVal_val1, newVal_val2, newVal_val3);
        Rect rect;
        Scalar loDiff(loDiff_val0, loDiff_val1, loDiff_val2, loDiff_val3);
        int _retval_ = cv::floodFill( image, mask, seedPoint, newVal, &rect, loDiff );
        jdouble tmp_rect[4] = {(jdouble)rect.x, (jdouble)rect.y, (jdouble)rect.width, (jdouble)rect.height}; env->SetDoubleArrayRegion(rect_out, 0, 4, tmp_rect);
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Imgproc_floodFill_13 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdoubleArray);

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Imgproc_floodFill_13
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong mask_nativeObj, jdouble seedPoint_x, jdouble seedPoint_y, jdouble newVal_val0, jdouble newVal_val1, jdouble newVal_val2, jdouble newVal_val3, jdoubleArray rect_out)
{
    static const char method_name[] = "imgproc::floodFill_13()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        Point seedPoint((int)seedPoint_x, (int)seedPoint_y);
        Scalar newVal(newVal_val0, newVal_val1, newVal_val2, newVal_val3);
        Rect rect;
        int _retval_ = cv::floodFill( image, mask, seedPoint, newVal, &rect );
        jdouble tmp_rect[4] = {(jdouble)rect.x, (jdouble)rect.y, (jdouble)rect.width, (jdouble)rect.height}; env->SetDoubleArrayRegion(rect_out, 0, 4, tmp_rect);
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Imgproc_floodFill_14 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Imgproc_floodFill_14
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong mask_nativeObj, jdouble seedPoint_x, jdouble seedPoint_y, jdouble newVal_val0, jdouble newVal_val1, jdouble newVal_val2, jdouble newVal_val3)
{
    static const char method_name[] = "imgproc::floodFill_14()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        Point seedPoint((int)seedPoint_x, (int)seedPoint_y);
        Scalar newVal(newVal_val0, newVal_val1, newVal_val2, newVal_val3);
        return cv::floodFill( image, mask, seedPoint, newVal );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::rotatedRectangleIntersection(RotatedRect rect1, RotatedRect rect2, Mat& intersectingRegion)
//



JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Imgproc_rotatedRectangleIntersection_10 (JNIEnv*, jclass, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Imgproc_rotatedRectangleIntersection_10
  (JNIEnv* env, jclass , jdouble rect1_center_x, jdouble rect1_center_y, jdouble rect1_size_width, jdouble rect1_size_height, jdouble rect1_angle, jdouble rect2_center_x, jdouble rect2_center_y, jdouble rect2_size_width, jdouble rect2_size_height, jdouble rect2_angle, jlong intersectingRegion_nativeObj)
{
    static const char method_name[] = "imgproc::rotatedRectangleIntersection_10()";
    try {
        LOGD("%s", method_name);
        RotatedRect rect1(cv::Point2f(rect1_center_x, rect1_center_y), cv::Size2f(rect1_size_width, rect1_size_height), rect1_angle);
        RotatedRect rect2(cv::Point2f(rect2_center_x, rect2_center_y), cv::Size2f(rect2_size_width, rect2_size_height), rect2_angle);
        Mat& intersectingRegion = *((Mat*)intersectingRegion_nativeObj);
        return cv::rotatedRectangleIntersection( rect1, rect2, intersectingRegion );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::Canny(Mat dx, Mat dy, Mat& edges, double threshold1, double threshold2, bool L2gradient = false)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_Canny_10 (JNIEnv*, jclass, jlong, jlong, jlong, jdouble, jdouble, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_Canny_10
  (JNIEnv* env, jclass , jlong dx_nativeObj, jlong dy_nativeObj, jlong edges_nativeObj, jdouble threshold1, jdouble threshold2, jboolean L2gradient)
{
    static const char method_name[] = "imgproc::Canny_10()";
    try {
        LOGD("%s", method_name);
        Mat& dx = *((Mat*)dx_nativeObj);
        Mat& dy = *((Mat*)dy_nativeObj);
        Mat& edges = *((Mat*)edges_nativeObj);
        cv::Canny( dx, dy, edges, (double)threshold1, (double)threshold2, (bool)L2gradient );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_Canny_11 (JNIEnv*, jclass, jlong, jlong, jlong, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_Canny_11
  (JNIEnv* env, jclass , jlong dx_nativeObj, jlong dy_nativeObj, jlong edges_nativeObj, jdouble threshold1, jdouble threshold2)
{
    static const char method_name[] = "imgproc::Canny_11()";
    try {
        LOGD("%s", method_name);
        Mat& dx = *((Mat*)dx_nativeObj);
        Mat& dy = *((Mat*)dy_nativeObj);
        Mat& edges = *((Mat*)edges_nativeObj);
        cv::Canny( dx, dy, edges, (double)threshold1, (double)threshold2 );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::Canny(Mat image, Mat& edges, double threshold1, double threshold2, int apertureSize = 3, bool L2gradient = false)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_Canny_12 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jint, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_Canny_12
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong edges_nativeObj, jdouble threshold1, jdouble threshold2, jint apertureSize, jboolean L2gradient)
{
    static const char method_name[] = "imgproc::Canny_12()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& edges = *((Mat*)edges_nativeObj);
        cv::Canny( image, edges, (double)threshold1, (double)threshold2, (int)apertureSize, (bool)L2gradient );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_Canny_13 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_Canny_13
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong edges_nativeObj, jdouble threshold1, jdouble threshold2, jint apertureSize)
{
    static const char method_name[] = "imgproc::Canny_13()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& edges = *((Mat*)edges_nativeObj);
        cv::Canny( image, edges, (double)threshold1, (double)threshold2, (int)apertureSize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_Canny_14 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_Canny_14
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong edges_nativeObj, jdouble threshold1, jdouble threshold2)
{
    static const char method_name[] = "imgproc::Canny_14()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& edges = *((Mat*)edges_nativeObj);
        cv::Canny( image, edges, (double)threshold1, (double)threshold2 );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::GaussianBlur(Mat src, Mat& dst, Size ksize, double sigmaX, double sigmaY = 0, int borderType = BORDER_DEFAULT)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_GaussianBlur_10 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jdouble, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_GaussianBlur_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jdouble ksize_width, jdouble ksize_height, jdouble sigmaX, jdouble sigmaY, jint borderType)
{
    static const char method_name[] = "imgproc::GaussianBlur_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Size ksize((int)ksize_width, (int)ksize_height);
        cv::GaussianBlur( src, dst, ksize, (double)sigmaX, (double)sigmaY, (int)borderType );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_GaussianBlur_11 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_GaussianBlur_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jdouble ksize_width, jdouble ksize_height, jdouble sigmaX, jdouble sigmaY)
{
    static const char method_name[] = "imgproc::GaussianBlur_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Size ksize((int)ksize_width, (int)ksize_height);
        cv::GaussianBlur( src, dst, ksize, (double)sigmaX, (double)sigmaY );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_GaussianBlur_12 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_GaussianBlur_12
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jdouble ksize_width, jdouble ksize_height, jdouble sigmaX)
{
    static const char method_name[] = "imgproc::GaussianBlur_12()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Size ksize((int)ksize_width, (int)ksize_height);
        cv::GaussianBlur( src, dst, ksize, (double)sigmaX );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::HoughCircles(Mat image, Mat& circles, int method, double dp, double minDist, double param1 = 100, double param2 = 100, int minRadius = 0, int maxRadius = 0)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_HoughCircles_10 (JNIEnv*, jclass, jlong, jlong, jint, jdouble, jdouble, jdouble, jdouble, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_HoughCircles_10
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong circles_nativeObj, jint method, jdouble dp, jdouble minDist, jdouble param1, jdouble param2, jint minRadius, jint maxRadius)
{
    static const char method_name[] = "imgproc::HoughCircles_10()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& circles = *((Mat*)circles_nativeObj);
        cv::HoughCircles( image, circles, (int)method, (double)dp, (double)minDist, (double)param1, (double)param2, (int)minRadius, (int)maxRadius );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_HoughCircles_11 (JNIEnv*, jclass, jlong, jlong, jint, jdouble, jdouble, jdouble, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_HoughCircles_11
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong circles_nativeObj, jint method, jdouble dp, jdouble minDist, jdouble param1, jdouble param2, jint minRadius)
{
    static const char method_name[] = "imgproc::HoughCircles_11()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& circles = *((Mat*)circles_nativeObj);
        cv::HoughCircles( image, circles, (int)method, (double)dp, (double)minDist, (double)param1, (double)param2, (int)minRadius );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_HoughCircles_12 (JNIEnv*, jclass, jlong, jlong, jint, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_HoughCircles_12
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong circles_nativeObj, jint method, jdouble dp, jdouble minDist, jdouble param1, jdouble param2)
{
    static const char method_name[] = "imgproc::HoughCircles_12()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& circles = *((Mat*)circles_nativeObj);
        cv::HoughCircles( image, circles, (int)method, (double)dp, (double)minDist, (double)param1, (double)param2 );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_HoughCircles_13 (JNIEnv*, jclass, jlong, jlong, jint, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_HoughCircles_13
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong circles_nativeObj, jint method, jdouble dp, jdouble minDist, jdouble param1)
{
    static const char method_name[] = "imgproc::HoughCircles_13()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& circles = *((Mat*)circles_nativeObj);
        cv::HoughCircles( image, circles, (int)method, (double)dp, (double)minDist, (double)param1 );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_HoughCircles_14 (JNIEnv*, jclass, jlong, jlong, jint, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_HoughCircles_14
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong circles_nativeObj, jint method, jdouble dp, jdouble minDist)
{
    static const char method_name[] = "imgproc::HoughCircles_14()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& circles = *((Mat*)circles_nativeObj);
        cv::HoughCircles( image, circles, (int)method, (double)dp, (double)minDist );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::HoughLines(Mat image, Mat& lines, double rho, double theta, int threshold, double srn = 0, double stn = 0, double min_theta = 0, double max_theta = CV_PI)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_HoughLines_10 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jint, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_HoughLines_10
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong lines_nativeObj, jdouble rho, jdouble theta, jint threshold, jdouble srn, jdouble stn, jdouble min_theta, jdouble max_theta)
{
    static const char method_name[] = "imgproc::HoughLines_10()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& lines = *((Mat*)lines_nativeObj);
        cv::HoughLines( image, lines, (double)rho, (double)theta, (int)threshold, (double)srn, (double)stn, (double)min_theta, (double)max_theta );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_HoughLines_11 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jint, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_HoughLines_11
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong lines_nativeObj, jdouble rho, jdouble theta, jint threshold, jdouble srn, jdouble stn, jdouble min_theta)
{
    static const char method_name[] = "imgproc::HoughLines_11()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& lines = *((Mat*)lines_nativeObj);
        cv::HoughLines( image, lines, (double)rho, (double)theta, (int)threshold, (double)srn, (double)stn, (double)min_theta );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_HoughLines_12 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jint, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_HoughLines_12
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong lines_nativeObj, jdouble rho, jdouble theta, jint threshold, jdouble srn, jdouble stn)
{
    static const char method_name[] = "imgproc::HoughLines_12()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& lines = *((Mat*)lines_nativeObj);
        cv::HoughLines( image, lines, (double)rho, (double)theta, (int)threshold, (double)srn, (double)stn );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_HoughLines_13 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jint, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_HoughLines_13
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong lines_nativeObj, jdouble rho, jdouble theta, jint threshold, jdouble srn)
{
    static const char method_name[] = "imgproc::HoughLines_13()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& lines = *((Mat*)lines_nativeObj);
        cv::HoughLines( image, lines, (double)rho, (double)theta, (int)threshold, (double)srn );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_HoughLines_14 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_HoughLines_14
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong lines_nativeObj, jdouble rho, jdouble theta, jint threshold)
{
    static const char method_name[] = "imgproc::HoughLines_14()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& lines = *((Mat*)lines_nativeObj);
        cv::HoughLines( image, lines, (double)rho, (double)theta, (int)threshold );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::HoughLinesP(Mat image, Mat& lines, double rho, double theta, int threshold, double minLineLength = 0, double maxLineGap = 0)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_HoughLinesP_10 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jint, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_HoughLinesP_10
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong lines_nativeObj, jdouble rho, jdouble theta, jint threshold, jdouble minLineLength, jdouble maxLineGap)
{
    static const char method_name[] = "imgproc::HoughLinesP_10()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& lines = *((Mat*)lines_nativeObj);
        cv::HoughLinesP( image, lines, (double)rho, (double)theta, (int)threshold, (double)minLineLength, (double)maxLineGap );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_HoughLinesP_11 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jint, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_HoughLinesP_11
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong lines_nativeObj, jdouble rho, jdouble theta, jint threshold, jdouble minLineLength)
{
    static const char method_name[] = "imgproc::HoughLinesP_11()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& lines = *((Mat*)lines_nativeObj);
        cv::HoughLinesP( image, lines, (double)rho, (double)theta, (int)threshold, (double)minLineLength );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_HoughLinesP_12 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_HoughLinesP_12
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong lines_nativeObj, jdouble rho, jdouble theta, jint threshold)
{
    static const char method_name[] = "imgproc::HoughLinesP_12()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& lines = *((Mat*)lines_nativeObj);
        cv::HoughLinesP( image, lines, (double)rho, (double)theta, (int)threshold );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::HoughLinesPointSet(Mat _point, Mat& _lines, int lines_max, int threshold, double min_rho, double max_rho, double rho_step, double min_theta, double max_theta, double theta_step)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_HoughLinesPointSet_10 (JNIEnv*, jclass, jlong, jlong, jint, jint, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_HoughLinesPointSet_10
  (JNIEnv* env, jclass , jlong _point_nativeObj, jlong _lines_nativeObj, jint lines_max, jint threshold, jdouble min_rho, jdouble max_rho, jdouble rho_step, jdouble min_theta, jdouble max_theta, jdouble theta_step)
{
    static const char method_name[] = "imgproc::HoughLinesPointSet_10()";
    try {
        LOGD("%s", method_name);
        Mat& _point = *((Mat*)_point_nativeObj);
        Mat& _lines = *((Mat*)_lines_nativeObj);
        cv::HoughLinesPointSet( _point, _lines, (int)lines_max, (int)threshold, (double)min_rho, (double)max_rho, (double)rho_step, (double)min_theta, (double)max_theta, (double)theta_step );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::HuMoments(Moments m, Mat& hu)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_HuMoments_10 (JNIEnv*, jclass, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_HuMoments_10
  (JNIEnv* env, jclass , jdouble m_m00, jdouble m_m10, jdouble m_m01, jdouble m_m20, jdouble m_m11, jdouble m_m02, jdouble m_m30, jdouble m_m21, jdouble m_m12, jdouble m_m03, jlong hu_nativeObj)
{
    static const char method_name[] = "imgproc::HuMoments_10()";
    try {
        LOGD("%s", method_name);
        Moments m(m_m00, m_m10, m_m01, m_m20, m_m11, m_m02, m_m30, m_m21, m_m12, m_m03);
        Mat& hu = *((Mat*)hu_nativeObj);
        cv::HuMoments( m, hu );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::Laplacian(Mat src, Mat& dst, int ddepth, int ksize = 1, double scale = 1, double delta = 0, int borderType = BORDER_DEFAULT)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_Laplacian_10 (JNIEnv*, jclass, jlong, jlong, jint, jint, jdouble, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_Laplacian_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint ddepth, jint ksize, jdouble scale, jdouble delta, jint borderType)
{
    static const char method_name[] = "imgproc::Laplacian_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::Laplacian( src, dst, (int)ddepth, (int)ksize, (double)scale, (double)delta, (int)borderType );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_Laplacian_11 (JNIEnv*, jclass, jlong, jlong, jint, jint, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_Laplacian_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint ddepth, jint ksize, jdouble scale, jdouble delta)
{
    static const char method_name[] = "imgproc::Laplacian_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::Laplacian( src, dst, (int)ddepth, (int)ksize, (double)scale, (double)delta );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_Laplacian_12 (JNIEnv*, jclass, jlong, jlong, jint, jint, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_Laplacian_12
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint ddepth, jint ksize, jdouble scale)
{
    static const char method_name[] = "imgproc::Laplacian_12()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::Laplacian( src, dst, (int)ddepth, (int)ksize, (double)scale );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_Laplacian_13 (JNIEnv*, jclass, jlong, jlong, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_Laplacian_13
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint ddepth, jint ksize)
{
    static const char method_name[] = "imgproc::Laplacian_13()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::Laplacian( src, dst, (int)ddepth, (int)ksize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_Laplacian_14 (JNIEnv*, jclass, jlong, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_Laplacian_14
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint ddepth)
{
    static const char method_name[] = "imgproc::Laplacian_14()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::Laplacian( src, dst, (int)ddepth );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::Scharr(Mat src, Mat& dst, int ddepth, int dx, int dy, double scale = 1, double delta = 0, int borderType = BORDER_DEFAULT)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_Scharr_10 (JNIEnv*, jclass, jlong, jlong, jint, jint, jint, jdouble, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_Scharr_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint ddepth, jint dx, jint dy, jdouble scale, jdouble delta, jint borderType)
{
    static const char method_name[] = "imgproc::Scharr_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::Scharr( src, dst, (int)ddepth, (int)dx, (int)dy, (double)scale, (double)delta, (int)borderType );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_Scharr_11 (JNIEnv*, jclass, jlong, jlong, jint, jint, jint, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_Scharr_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint ddepth, jint dx, jint dy, jdouble scale, jdouble delta)
{
    static const char method_name[] = "imgproc::Scharr_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::Scharr( src, dst, (int)ddepth, (int)dx, (int)dy, (double)scale, (double)delta );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_Scharr_12 (JNIEnv*, jclass, jlong, jlong, jint, jint, jint, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_Scharr_12
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint ddepth, jint dx, jint dy, jdouble scale)
{
    static const char method_name[] = "imgproc::Scharr_12()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::Scharr( src, dst, (int)ddepth, (int)dx, (int)dy, (double)scale );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_Scharr_13 (JNIEnv*, jclass, jlong, jlong, jint, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_Scharr_13
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint ddepth, jint dx, jint dy)
{
    static const char method_name[] = "imgproc::Scharr_13()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::Scharr( src, dst, (int)ddepth, (int)dx, (int)dy );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::Sobel(Mat src, Mat& dst, int ddepth, int dx, int dy, int ksize = 3, double scale = 1, double delta = 0, int borderType = BORDER_DEFAULT)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_Sobel_10 (JNIEnv*, jclass, jlong, jlong, jint, jint, jint, jint, jdouble, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_Sobel_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint ddepth, jint dx, jint dy, jint ksize, jdouble scale, jdouble delta, jint borderType)
{
    static const char method_name[] = "imgproc::Sobel_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::Sobel( src, dst, (int)ddepth, (int)dx, (int)dy, (int)ksize, (double)scale, (double)delta, (int)borderType );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_Sobel_11 (JNIEnv*, jclass, jlong, jlong, jint, jint, jint, jint, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_Sobel_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint ddepth, jint dx, jint dy, jint ksize, jdouble scale, jdouble delta)
{
    static const char method_name[] = "imgproc::Sobel_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::Sobel( src, dst, (int)ddepth, (int)dx, (int)dy, (int)ksize, (double)scale, (double)delta );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_Sobel_12 (JNIEnv*, jclass, jlong, jlong, jint, jint, jint, jint, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_Sobel_12
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint ddepth, jint dx, jint dy, jint ksize, jdouble scale)
{
    static const char method_name[] = "imgproc::Sobel_12()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::Sobel( src, dst, (int)ddepth, (int)dx, (int)dy, (int)ksize, (double)scale );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_Sobel_13 (JNIEnv*, jclass, jlong, jlong, jint, jint, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_Sobel_13
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint ddepth, jint dx, jint dy, jint ksize)
{
    static const char method_name[] = "imgproc::Sobel_13()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::Sobel( src, dst, (int)ddepth, (int)dx, (int)dy, (int)ksize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_Sobel_14 (JNIEnv*, jclass, jlong, jlong, jint, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_Sobel_14
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint ddepth, jint dx, jint dy)
{
    static const char method_name[] = "imgproc::Sobel_14()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::Sobel( src, dst, (int)ddepth, (int)dx, (int)dy );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::accumulate(Mat src, Mat& dst, Mat mask = Mat())
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_accumulate_10 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_accumulate_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jlong mask_nativeObj)
{
    static const char method_name[] = "imgproc::accumulate_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        cv::accumulate( src, dst, mask );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_accumulate_11 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_accumulate_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "imgproc::accumulate_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::accumulate( src, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::accumulateProduct(Mat src1, Mat src2, Mat& dst, Mat mask = Mat())
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_accumulateProduct_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_accumulateProduct_10
  (JNIEnv* env, jclass , jlong src1_nativeObj, jlong src2_nativeObj, jlong dst_nativeObj, jlong mask_nativeObj)
{
    static const char method_name[] = "imgproc::accumulateProduct_10()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Mat& src2 = *((Mat*)src2_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        cv::accumulateProduct( src1, src2, dst, mask );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_accumulateProduct_11 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_accumulateProduct_11
  (JNIEnv* env, jclass , jlong src1_nativeObj, jlong src2_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "imgproc::accumulateProduct_11()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Mat& src2 = *((Mat*)src2_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::accumulateProduct( src1, src2, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::accumulateSquare(Mat src, Mat& dst, Mat mask = Mat())
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_accumulateSquare_10 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_accumulateSquare_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jlong mask_nativeObj)
{
    static const char method_name[] = "imgproc::accumulateSquare_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        cv::accumulateSquare( src, dst, mask );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_accumulateSquare_11 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_accumulateSquare_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "imgproc::accumulateSquare_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::accumulateSquare( src, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::accumulateWeighted(Mat src, Mat& dst, double alpha, Mat mask = Mat())
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_accumulateWeighted_10 (JNIEnv*, jclass, jlong, jlong, jdouble, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_accumulateWeighted_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jdouble alpha, jlong mask_nativeObj)
{
    static const char method_name[] = "imgproc::accumulateWeighted_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        cv::accumulateWeighted( src, dst, (double)alpha, mask );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_accumulateWeighted_11 (JNIEnv*, jclass, jlong, jlong, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_accumulateWeighted_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jdouble alpha)
{
    static const char method_name[] = "imgproc::accumulateWeighted_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::accumulateWeighted( src, dst, (double)alpha );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::adaptiveThreshold(Mat src, Mat& dst, double maxValue, int adaptiveMethod, int thresholdType, int blockSize, double C)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_adaptiveThreshold_10 (JNIEnv*, jclass, jlong, jlong, jdouble, jint, jint, jint, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_adaptiveThreshold_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jdouble maxValue, jint adaptiveMethod, jint thresholdType, jint blockSize, jdouble C)
{
    static const char method_name[] = "imgproc::adaptiveThreshold_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::adaptiveThreshold( src, dst, (double)maxValue, (int)adaptiveMethod, (int)thresholdType, (int)blockSize, (double)C );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::applyColorMap(Mat src, Mat& dst, Mat userColor)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_applyColorMap_10 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_applyColorMap_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jlong userColor_nativeObj)
{
    static const char method_name[] = "imgproc::applyColorMap_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& userColor = *((Mat*)userColor_nativeObj);
        cv::applyColorMap( src, dst, userColor );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::applyColorMap(Mat src, Mat& dst, int colormap)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_applyColorMap_11 (JNIEnv*, jclass, jlong, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_applyColorMap_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint colormap)
{
    static const char method_name[] = "imgproc::applyColorMap_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::applyColorMap( src, dst, (int)colormap );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::approxPolyDP(vector_Point2f curve, vector_Point2f& approxCurve, double epsilon, bool closed)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_approxPolyDP_10 (JNIEnv*, jclass, jlong, jlong, jdouble, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_approxPolyDP_10
  (JNIEnv* env, jclass , jlong curve_mat_nativeObj, jlong approxCurve_mat_nativeObj, jdouble epsilon, jboolean closed)
{
    static const char method_name[] = "imgproc::approxPolyDP_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Point2f> curve;
        Mat& curve_mat = *((Mat*)curve_mat_nativeObj);
        Mat_to_vector_Point2f( curve_mat, curve );
        std::vector<Point2f> approxCurve;
        Mat& approxCurve_mat = *((Mat*)approxCurve_mat_nativeObj);
        cv::approxPolyDP( curve, approxCurve, (double)epsilon, (bool)closed );
        vector_Point2f_to_Mat( approxCurve, approxCurve_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::arrowedLine(Mat& img, Point pt1, Point pt2, Scalar color, int thickness = 1, int line_type = 8, int shift = 0, double tipLength = 0.1)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_arrowedLine_10 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jint, jint, jint, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_arrowedLine_10
  (JNIEnv* env, jclass , jlong img_nativeObj, jdouble pt1_x, jdouble pt1_y, jdouble pt2_x, jdouble pt2_y, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3, jint thickness, jint line_type, jint shift, jdouble tipLength)
{
    static const char method_name[] = "imgproc::arrowedLine_10()";
    try {
        LOGD("%s", method_name);
        Mat& img = *((Mat*)img_nativeObj);
        Point pt1((int)pt1_x, (int)pt1_y);
        Point pt2((int)pt2_x, (int)pt2_y);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::arrowedLine( img, pt1, pt2, color, (int)thickness, (int)line_type, (int)shift, (double)tipLength );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_arrowedLine_11 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jint, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_arrowedLine_11
  (JNIEnv* env, jclass , jlong img_nativeObj, jdouble pt1_x, jdouble pt1_y, jdouble pt2_x, jdouble pt2_y, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3, jint thickness, jint line_type, jint shift)
{
    static const char method_name[] = "imgproc::arrowedLine_11()";
    try {
        LOGD("%s", method_name);
        Mat& img = *((Mat*)img_nativeObj);
        Point pt1((int)pt1_x, (int)pt1_y);
        Point pt2((int)pt2_x, (int)pt2_y);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::arrowedLine( img, pt1, pt2, color, (int)thickness, (int)line_type, (int)shift );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_arrowedLine_12 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_arrowedLine_12
  (JNIEnv* env, jclass , jlong img_nativeObj, jdouble pt1_x, jdouble pt1_y, jdouble pt2_x, jdouble pt2_y, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3, jint thickness, jint line_type)
{
    static const char method_name[] = "imgproc::arrowedLine_12()";
    try {
        LOGD("%s", method_name);
        Mat& img = *((Mat*)img_nativeObj);
        Point pt1((int)pt1_x, (int)pt1_y);
        Point pt2((int)pt2_x, (int)pt2_y);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::arrowedLine( img, pt1, pt2, color, (int)thickness, (int)line_type );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_arrowedLine_13 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_arrowedLine_13
  (JNIEnv* env, jclass , jlong img_nativeObj, jdouble pt1_x, jdouble pt1_y, jdouble pt2_x, jdouble pt2_y, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3, jint thickness)
{
    static const char method_name[] = "imgproc::arrowedLine_13()";
    try {
        LOGD("%s", method_name);
        Mat& img = *((Mat*)img_nativeObj);
        Point pt1((int)pt1_x, (int)pt1_y);
        Point pt2((int)pt2_x, (int)pt2_y);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::arrowedLine( img, pt1, pt2, color, (int)thickness );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_arrowedLine_14 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_arrowedLine_14
  (JNIEnv* env, jclass , jlong img_nativeObj, jdouble pt1_x, jdouble pt1_y, jdouble pt2_x, jdouble pt2_y, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3)
{
    static const char method_name[] = "imgproc::arrowedLine_14()";
    try {
        LOGD("%s", method_name);
        Mat& img = *((Mat*)img_nativeObj);
        Point pt1((int)pt1_x, (int)pt1_y);
        Point pt2((int)pt2_x, (int)pt2_y);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::arrowedLine( img, pt1, pt2, color );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::bilateralFilter(Mat src, Mat& dst, int d, double sigmaColor, double sigmaSpace, int borderType = BORDER_DEFAULT)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_bilateralFilter_10 (JNIEnv*, jclass, jlong, jlong, jint, jdouble, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_bilateralFilter_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint d, jdouble sigmaColor, jdouble sigmaSpace, jint borderType)
{
    static const char method_name[] = "imgproc::bilateralFilter_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::bilateralFilter( src, dst, (int)d, (double)sigmaColor, (double)sigmaSpace, (int)borderType );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_bilateralFilter_11 (JNIEnv*, jclass, jlong, jlong, jint, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_bilateralFilter_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint d, jdouble sigmaColor, jdouble sigmaSpace)
{
    static const char method_name[] = "imgproc::bilateralFilter_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::bilateralFilter( src, dst, (int)d, (double)sigmaColor, (double)sigmaSpace );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::blur(Mat src, Mat& dst, Size ksize, Point anchor = Point(-1,-1), int borderType = BORDER_DEFAULT)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_blur_10 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jdouble, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_blur_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jdouble ksize_width, jdouble ksize_height, jdouble anchor_x, jdouble anchor_y, jint borderType)
{
    static const char method_name[] = "imgproc::blur_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Size ksize((int)ksize_width, (int)ksize_height);
        Point anchor((int)anchor_x, (int)anchor_y);
        cv::blur( src, dst, ksize, anchor, (int)borderType );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_blur_11 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_blur_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jdouble ksize_width, jdouble ksize_height, jdouble anchor_x, jdouble anchor_y)
{
    static const char method_name[] = "imgproc::blur_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Size ksize((int)ksize_width, (int)ksize_height);
        Point anchor((int)anchor_x, (int)anchor_y);
        cv::blur( src, dst, ksize, anchor );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_blur_12 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_blur_12
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jdouble ksize_width, jdouble ksize_height)
{
    static const char method_name[] = "imgproc::blur_12()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Size ksize((int)ksize_width, (int)ksize_height);
        cv::blur( src, dst, ksize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::boxFilter(Mat src, Mat& dst, int ddepth, Size ksize, Point anchor = Point(-1,-1), bool normalize = true, int borderType = BORDER_DEFAULT)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_boxFilter_10 (JNIEnv*, jclass, jlong, jlong, jint, jdouble, jdouble, jdouble, jdouble, jboolean, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_boxFilter_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint ddepth, jdouble ksize_width, jdouble ksize_height, jdouble anchor_x, jdouble anchor_y, jboolean normalize, jint borderType)
{
    static const char method_name[] = "imgproc::boxFilter_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Size ksize((int)ksize_width, (int)ksize_height);
        Point anchor((int)anchor_x, (int)anchor_y);
        cv::boxFilter( src, dst, (int)ddepth, ksize, anchor, (bool)normalize, (int)borderType );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_boxFilter_11 (JNIEnv*, jclass, jlong, jlong, jint, jdouble, jdouble, jdouble, jdouble, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_boxFilter_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint ddepth, jdouble ksize_width, jdouble ksize_height, jdouble anchor_x, jdouble anchor_y, jboolean normalize)
{
    static const char method_name[] = "imgproc::boxFilter_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Size ksize((int)ksize_width, (int)ksize_height);
        Point anchor((int)anchor_x, (int)anchor_y);
        cv::boxFilter( src, dst, (int)ddepth, ksize, anchor, (bool)normalize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_boxFilter_12 (JNIEnv*, jclass, jlong, jlong, jint, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_boxFilter_12
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint ddepth, jdouble ksize_width, jdouble ksize_height, jdouble anchor_x, jdouble anchor_y)
{
    static const char method_name[] = "imgproc::boxFilter_12()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Size ksize((int)ksize_width, (int)ksize_height);
        Point anchor((int)anchor_x, (int)anchor_y);
        cv::boxFilter( src, dst, (int)ddepth, ksize, anchor );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_boxFilter_13 (JNIEnv*, jclass, jlong, jlong, jint, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_boxFilter_13
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint ddepth, jdouble ksize_width, jdouble ksize_height)
{
    static const char method_name[] = "imgproc::boxFilter_13()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Size ksize((int)ksize_width, (int)ksize_height);
        cv::boxFilter( src, dst, (int)ddepth, ksize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::boxPoints(RotatedRect box, Mat& points)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_boxPoints_10 (JNIEnv*, jclass, jdouble, jdouble, jdouble, jdouble, jdouble, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_boxPoints_10
  (JNIEnv* env, jclass , jdouble box_center_x, jdouble box_center_y, jdouble box_size_width, jdouble box_size_height, jdouble box_angle, jlong points_nativeObj)
{
    static const char method_name[] = "imgproc::boxPoints_10()";
    try {
        LOGD("%s", method_name);
        RotatedRect box(cv::Point2f(box_center_x, box_center_y), cv::Size2f(box_size_width, box_size_height), box_angle);
        Mat& points = *((Mat*)points_nativeObj);
        cv::boxPoints( box, points );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::calcBackProject(vector_Mat images, vector_int channels, Mat hist, Mat& dst, vector_float ranges, double scale)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_calcBackProject_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_calcBackProject_10
  (JNIEnv* env, jclass , jlong images_mat_nativeObj, jlong channels_mat_nativeObj, jlong hist_nativeObj, jlong dst_nativeObj, jlong ranges_mat_nativeObj, jdouble scale)
{
    static const char method_name[] = "imgproc::calcBackProject_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> images;
        Mat& images_mat = *((Mat*)images_mat_nativeObj);
        Mat_to_vector_Mat( images_mat, images );
        std::vector<int> channels;
        Mat& channels_mat = *((Mat*)channels_mat_nativeObj);
        Mat_to_vector_int( channels_mat, channels );
        std::vector<float> ranges;
        Mat& ranges_mat = *((Mat*)ranges_mat_nativeObj);
        Mat_to_vector_float( ranges_mat, ranges );
        Mat& hist = *((Mat*)hist_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::calcBackProject( images, channels, hist, dst, ranges, (double)scale );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::calcHist(vector_Mat images, vector_int channels, Mat mask, Mat& hist, vector_int histSize, vector_float ranges, bool accumulate = false)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_calcHist_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_calcHist_10
  (JNIEnv* env, jclass , jlong images_mat_nativeObj, jlong channels_mat_nativeObj, jlong mask_nativeObj, jlong hist_nativeObj, jlong histSize_mat_nativeObj, jlong ranges_mat_nativeObj, jboolean accumulate)
{
    static const char method_name[] = "imgproc::calcHist_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> images;
        Mat& images_mat = *((Mat*)images_mat_nativeObj);
        Mat_to_vector_Mat( images_mat, images );
        std::vector<int> channels;
        Mat& channels_mat = *((Mat*)channels_mat_nativeObj);
        Mat_to_vector_int( channels_mat, channels );
        std::vector<int> histSize;
        Mat& histSize_mat = *((Mat*)histSize_mat_nativeObj);
        Mat_to_vector_int( histSize_mat, histSize );
        std::vector<float> ranges;
        Mat& ranges_mat = *((Mat*)ranges_mat_nativeObj);
        Mat_to_vector_float( ranges_mat, ranges );
        Mat& mask = *((Mat*)mask_nativeObj);
        Mat& hist = *((Mat*)hist_nativeObj);
        cv::calcHist( images, channels, mask, hist, histSize, ranges, (bool)accumulate );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_calcHist_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_calcHist_11
  (JNIEnv* env, jclass , jlong images_mat_nativeObj, jlong channels_mat_nativeObj, jlong mask_nativeObj, jlong hist_nativeObj, jlong histSize_mat_nativeObj, jlong ranges_mat_nativeObj)
{
    static const char method_name[] = "imgproc::calcHist_11()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> images;
        Mat& images_mat = *((Mat*)images_mat_nativeObj);
        Mat_to_vector_Mat( images_mat, images );
        std::vector<int> channels;
        Mat& channels_mat = *((Mat*)channels_mat_nativeObj);
        Mat_to_vector_int( channels_mat, channels );
        std::vector<int> histSize;
        Mat& histSize_mat = *((Mat*)histSize_mat_nativeObj);
        Mat_to_vector_int( histSize_mat, histSize );
        std::vector<float> ranges;
        Mat& ranges_mat = *((Mat*)ranges_mat_nativeObj);
        Mat_to_vector_float( ranges_mat, ranges );
        Mat& mask = *((Mat*)mask_nativeObj);
        Mat& hist = *((Mat*)hist_nativeObj);
        cv::calcHist( images, channels, mask, hist, histSize, ranges );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::circle(Mat& img, Point center, int radius, Scalar color, int thickness = 1, int lineType = LINE_8, int shift = 0)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_circle_10 (JNIEnv*, jclass, jlong, jdouble, jdouble, jint, jdouble, jdouble, jdouble, jdouble, jint, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_circle_10
  (JNIEnv* env, jclass , jlong img_nativeObj, jdouble center_x, jdouble center_y, jint radius, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3, jint thickness, jint lineType, jint shift)
{
    static const char method_name[] = "imgproc::circle_10()";
    try {
        LOGD("%s", method_name);
        Mat& img = *((Mat*)img_nativeObj);
        Point center((int)center_x, (int)center_y);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::circle( img, center, (int)radius, color, (int)thickness, (int)lineType, (int)shift );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_circle_11 (JNIEnv*, jclass, jlong, jdouble, jdouble, jint, jdouble, jdouble, jdouble, jdouble, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_circle_11
  (JNIEnv* env, jclass , jlong img_nativeObj, jdouble center_x, jdouble center_y, jint radius, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3, jint thickness, jint lineType)
{
    static const char method_name[] = "imgproc::circle_11()";
    try {
        LOGD("%s", method_name);
        Mat& img = *((Mat*)img_nativeObj);
        Point center((int)center_x, (int)center_y);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::circle( img, center, (int)radius, color, (int)thickness, (int)lineType );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_circle_12 (JNIEnv*, jclass, jlong, jdouble, jdouble, jint, jdouble, jdouble, jdouble, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_circle_12
  (JNIEnv* env, jclass , jlong img_nativeObj, jdouble center_x, jdouble center_y, jint radius, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3, jint thickness)
{
    static const char method_name[] = "imgproc::circle_12()";
    try {
        LOGD("%s", method_name);
        Mat& img = *((Mat*)img_nativeObj);
        Point center((int)center_x, (int)center_y);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::circle( img, center, (int)radius, color, (int)thickness );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_circle_13 (JNIEnv*, jclass, jlong, jdouble, jdouble, jint, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_circle_13
  (JNIEnv* env, jclass , jlong img_nativeObj, jdouble center_x, jdouble center_y, jint radius, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3)
{
    static const char method_name[] = "imgproc::circle_13()";
    try {
        LOGD("%s", method_name);
        Mat& img = *((Mat*)img_nativeObj);
        Point center((int)center_x, (int)center_y);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::circle( img, center, (int)radius, color );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::convertMaps(Mat map1, Mat map2, Mat& dstmap1, Mat& dstmap2, int dstmap1type, bool nninterpolation = false)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_convertMaps_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jint, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_convertMaps_10
  (JNIEnv* env, jclass , jlong map1_nativeObj, jlong map2_nativeObj, jlong dstmap1_nativeObj, jlong dstmap2_nativeObj, jint dstmap1type, jboolean nninterpolation)
{
    static const char method_name[] = "imgproc::convertMaps_10()";
    try {
        LOGD("%s", method_name);
        Mat& map1 = *((Mat*)map1_nativeObj);
        Mat& map2 = *((Mat*)map2_nativeObj);
        Mat& dstmap1 = *((Mat*)dstmap1_nativeObj);
        Mat& dstmap2 = *((Mat*)dstmap2_nativeObj);
        cv::convertMaps( map1, map2, dstmap1, dstmap2, (int)dstmap1type, (bool)nninterpolation );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_convertMaps_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_convertMaps_11
  (JNIEnv* env, jclass , jlong map1_nativeObj, jlong map2_nativeObj, jlong dstmap1_nativeObj, jlong dstmap2_nativeObj, jint dstmap1type)
{
    static const char method_name[] = "imgproc::convertMaps_11()";
    try {
        LOGD("%s", method_name);
        Mat& map1 = *((Mat*)map1_nativeObj);
        Mat& map2 = *((Mat*)map2_nativeObj);
        Mat& dstmap1 = *((Mat*)dstmap1_nativeObj);
        Mat& dstmap2 = *((Mat*)dstmap2_nativeObj);
        cv::convertMaps( map1, map2, dstmap1, dstmap2, (int)dstmap1type );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::convexHull(vector_Point points, vector_int& hull, bool clockwise = false,  _hidden_  returnPoints = true)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_convexHull_10 (JNIEnv*, jclass, jlong, jlong, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_convexHull_10
  (JNIEnv* env, jclass , jlong points_mat_nativeObj, jlong hull_mat_nativeObj, jboolean clockwise)
{
    static const char method_name[] = "imgproc::convexHull_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Point> points;
        Mat& points_mat = *((Mat*)points_mat_nativeObj);
        Mat_to_vector_Point( points_mat, points );
        std::vector<int> hull;
        Mat& hull_mat = *((Mat*)hull_mat_nativeObj);
        cv::convexHull( points, hull, (bool)clockwise, true );
        vector_int_to_Mat( hull, hull_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_convexHull_12 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_convexHull_12
  (JNIEnv* env, jclass , jlong points_mat_nativeObj, jlong hull_mat_nativeObj)
{
    static const char method_name[] = "imgproc::convexHull_12()";
    try {
        LOGD("%s", method_name);
        std::vector<Point> points;
        Mat& points_mat = *((Mat*)points_mat_nativeObj);
        Mat_to_vector_Point( points_mat, points );
        std::vector<int> hull;
        Mat& hull_mat = *((Mat*)hull_mat_nativeObj);
        cv::convexHull( points, hull );
        vector_int_to_Mat( hull, hull_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::convexityDefects(vector_Point contour, vector_int convexhull, vector_Vec4i& convexityDefects)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_convexityDefects_10 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_convexityDefects_10
  (JNIEnv* env, jclass , jlong contour_mat_nativeObj, jlong convexhull_mat_nativeObj, jlong convexityDefects_mat_nativeObj)
{
    static const char method_name[] = "imgproc::convexityDefects_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Point> contour;
        Mat& contour_mat = *((Mat*)contour_mat_nativeObj);
        Mat_to_vector_Point( contour_mat, contour );
        std::vector<int> convexhull;
        Mat& convexhull_mat = *((Mat*)convexhull_mat_nativeObj);
        Mat_to_vector_int( convexhull_mat, convexhull );
        std::vector<Vec4i> convexityDefects;
        Mat& convexityDefects_mat = *((Mat*)convexityDefects_mat_nativeObj);
        cv::convexityDefects( contour, convexhull, convexityDefects );
        vector_Vec4i_to_Mat( convexityDefects, convexityDefects_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::cornerEigenValsAndVecs(Mat src, Mat& dst, int blockSize, int ksize, int borderType = BORDER_DEFAULT)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_cornerEigenValsAndVecs_10 (JNIEnv*, jclass, jlong, jlong, jint, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_cornerEigenValsAndVecs_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint blockSize, jint ksize, jint borderType)
{
    static const char method_name[] = "imgproc::cornerEigenValsAndVecs_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::cornerEigenValsAndVecs( src, dst, (int)blockSize, (int)ksize, (int)borderType );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_cornerEigenValsAndVecs_11 (JNIEnv*, jclass, jlong, jlong, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_cornerEigenValsAndVecs_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint blockSize, jint ksize)
{
    static const char method_name[] = "imgproc::cornerEigenValsAndVecs_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::cornerEigenValsAndVecs( src, dst, (int)blockSize, (int)ksize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::cornerHarris(Mat src, Mat& dst, int blockSize, int ksize, double k, int borderType = BORDER_DEFAULT)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_cornerHarris_10 (JNIEnv*, jclass, jlong, jlong, jint, jint, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_cornerHarris_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint blockSize, jint ksize, jdouble k, jint borderType)
{
    static const char method_name[] = "imgproc::cornerHarris_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::cornerHarris( src, dst, (int)blockSize, (int)ksize, (double)k, (int)borderType );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_cornerHarris_11 (JNIEnv*, jclass, jlong, jlong, jint, jint, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_cornerHarris_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint blockSize, jint ksize, jdouble k)
{
    static const char method_name[] = "imgproc::cornerHarris_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::cornerHarris( src, dst, (int)blockSize, (int)ksize, (double)k );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::cornerMinEigenVal(Mat src, Mat& dst, int blockSize, int ksize = 3, int borderType = BORDER_DEFAULT)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_cornerMinEigenVal_10 (JNIEnv*, jclass, jlong, jlong, jint, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_cornerMinEigenVal_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint blockSize, jint ksize, jint borderType)
{
    static const char method_name[] = "imgproc::cornerMinEigenVal_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::cornerMinEigenVal( src, dst, (int)blockSize, (int)ksize, (int)borderType );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_cornerMinEigenVal_11 (JNIEnv*, jclass, jlong, jlong, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_cornerMinEigenVal_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint blockSize, jint ksize)
{
    static const char method_name[] = "imgproc::cornerMinEigenVal_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::cornerMinEigenVal( src, dst, (int)blockSize, (int)ksize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_cornerMinEigenVal_12 (JNIEnv*, jclass, jlong, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_cornerMinEigenVal_12
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint blockSize)
{
    static const char method_name[] = "imgproc::cornerMinEigenVal_12()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::cornerMinEigenVal( src, dst, (int)blockSize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::cornerSubPix(Mat image, Mat& corners, Size winSize, Size zeroZone, TermCriteria criteria)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_cornerSubPix_10 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jdouble, jdouble, jint, jint, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_cornerSubPix_10
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong corners_nativeObj, jdouble winSize_width, jdouble winSize_height, jdouble zeroZone_width, jdouble zeroZone_height, jint criteria_type, jint criteria_maxCount, jdouble criteria_epsilon)
{
    static const char method_name[] = "imgproc::cornerSubPix_10()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& corners = *((Mat*)corners_nativeObj);
        Size winSize((int)winSize_width, (int)winSize_height);
        Size zeroZone((int)zeroZone_width, (int)zeroZone_height);
        TermCriteria criteria(criteria_type, criteria_maxCount, criteria_epsilon);
        cv::cornerSubPix( image, corners, winSize, zeroZone, criteria );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::createHanningWindow(Mat& dst, Size winSize, int type)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_createHanningWindow_10 (JNIEnv*, jclass, jlong, jdouble, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_createHanningWindow_10
  (JNIEnv* env, jclass , jlong dst_nativeObj, jdouble winSize_width, jdouble winSize_height, jint type)
{
    static const char method_name[] = "imgproc::createHanningWindow_10()";
    try {
        LOGD("%s", method_name);
        Mat& dst = *((Mat*)dst_nativeObj);
        Size winSize((int)winSize_width, (int)winSize_height);
        cv::createHanningWindow( dst, winSize, (int)type );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::cvtColor(Mat src, Mat& dst, int code, int dstCn = 0)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_cvtColor_10 (JNIEnv*, jclass, jlong, jlong, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_cvtColor_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint code, jint dstCn)
{
    static const char method_name[] = "imgproc::cvtColor_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::cvtColor( src, dst, (int)code, (int)dstCn );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_cvtColor_11 (JNIEnv*, jclass, jlong, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_cvtColor_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint code)
{
    static const char method_name[] = "imgproc::cvtColor_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::cvtColor( src, dst, (int)code );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::cvtColorTwoPlane(Mat src1, Mat src2, Mat& dst, int code)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_cvtColorTwoPlane_10 (JNIEnv*, jclass, jlong, jlong, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_cvtColorTwoPlane_10
  (JNIEnv* env, jclass , jlong src1_nativeObj, jlong src2_nativeObj, jlong dst_nativeObj, jint code)
{
    static const char method_name[] = "imgproc::cvtColorTwoPlane_10()";
    try {
        LOGD("%s", method_name);
        Mat& src1 = *((Mat*)src1_nativeObj);
        Mat& src2 = *((Mat*)src2_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::cvtColorTwoPlane( src1, src2, dst, (int)code );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::demosaicing(Mat src, Mat& dst, int code, int dstCn = 0)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_demosaicing_10 (JNIEnv*, jclass, jlong, jlong, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_demosaicing_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint code, jint dstCn)
{
    static const char method_name[] = "imgproc::demosaicing_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::demosaicing( src, dst, (int)code, (int)dstCn );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_demosaicing_11 (JNIEnv*, jclass, jlong, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_demosaicing_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint code)
{
    static const char method_name[] = "imgproc::demosaicing_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::demosaicing( src, dst, (int)code );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::dilate(Mat src, Mat& dst, Mat kernel, Point anchor = Point(-1,-1), int iterations = 1, int borderType = BORDER_CONSTANT, Scalar borderValue = morphologyDefaultBorderValue())
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_dilate_10 (JNIEnv*, jclass, jlong, jlong, jlong, jdouble, jdouble, jint, jint, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_dilate_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jlong kernel_nativeObj, jdouble anchor_x, jdouble anchor_y, jint iterations, jint borderType, jdouble borderValue_val0, jdouble borderValue_val1, jdouble borderValue_val2, jdouble borderValue_val3)
{
    static const char method_name[] = "imgproc::dilate_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& kernel = *((Mat*)kernel_nativeObj);
        Point anchor((int)anchor_x, (int)anchor_y);
        Scalar borderValue(borderValue_val0, borderValue_val1, borderValue_val2, borderValue_val3);
        cv::dilate( src, dst, kernel, anchor, (int)iterations, (int)borderType, borderValue );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_dilate_11 (JNIEnv*, jclass, jlong, jlong, jlong, jdouble, jdouble, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_dilate_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jlong kernel_nativeObj, jdouble anchor_x, jdouble anchor_y, jint iterations, jint borderType)
{
    static const char method_name[] = "imgproc::dilate_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& kernel = *((Mat*)kernel_nativeObj);
        Point anchor((int)anchor_x, (int)anchor_y);
        cv::dilate( src, dst, kernel, anchor, (int)iterations, (int)borderType );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_dilate_12 (JNIEnv*, jclass, jlong, jlong, jlong, jdouble, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_dilate_12
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jlong kernel_nativeObj, jdouble anchor_x, jdouble anchor_y, jint iterations)
{
    static const char method_name[] = "imgproc::dilate_12()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& kernel = *((Mat*)kernel_nativeObj);
        Point anchor((int)anchor_x, (int)anchor_y);
        cv::dilate( src, dst, kernel, anchor, (int)iterations );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_dilate_13 (JNIEnv*, jclass, jlong, jlong, jlong, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_dilate_13
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jlong kernel_nativeObj, jdouble anchor_x, jdouble anchor_y)
{
    static const char method_name[] = "imgproc::dilate_13()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& kernel = *((Mat*)kernel_nativeObj);
        Point anchor((int)anchor_x, (int)anchor_y);
        cv::dilate( src, dst, kernel, anchor );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_dilate_14 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_dilate_14
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jlong kernel_nativeObj)
{
    static const char method_name[] = "imgproc::dilate_14()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& kernel = *((Mat*)kernel_nativeObj);
        cv::dilate( src, dst, kernel );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::distanceTransform(Mat src, Mat& dst, Mat& labels, int distanceType, int maskSize, int labelType = DIST_LABEL_CCOMP)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_distanceTransformWithLabels_10 (JNIEnv*, jclass, jlong, jlong, jlong, jint, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_distanceTransformWithLabels_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jlong labels_nativeObj, jint distanceType, jint maskSize, jint labelType)
{
    static const char method_name[] = "imgproc::distanceTransformWithLabels_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& labels = *((Mat*)labels_nativeObj);
        cv::distanceTransform( src, dst, labels, (int)distanceType, (int)maskSize, (int)labelType );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_distanceTransformWithLabels_11 (JNIEnv*, jclass, jlong, jlong, jlong, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_distanceTransformWithLabels_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jlong labels_nativeObj, jint distanceType, jint maskSize)
{
    static const char method_name[] = "imgproc::distanceTransformWithLabels_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& labels = *((Mat*)labels_nativeObj);
        cv::distanceTransform( src, dst, labels, (int)distanceType, (int)maskSize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::distanceTransform(Mat src, Mat& dst, int distanceType, int maskSize, int dstType = CV_32F)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_distanceTransform_10 (JNIEnv*, jclass, jlong, jlong, jint, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_distanceTransform_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint distanceType, jint maskSize, jint dstType)
{
    static const char method_name[] = "imgproc::distanceTransform_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::distanceTransform( src, dst, (int)distanceType, (int)maskSize, (int)dstType );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_distanceTransform_11 (JNIEnv*, jclass, jlong, jlong, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_distanceTransform_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint distanceType, jint maskSize)
{
    static const char method_name[] = "imgproc::distanceTransform_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::distanceTransform( src, dst, (int)distanceType, (int)maskSize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::drawContours(Mat& image, vector_vector_Point contours, int contourIdx, Scalar color, int thickness = 1, int lineType = LINE_8, Mat hierarchy = Mat(), int maxLevel = INT_MAX, Point offset = Point())
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_drawContours_10 (JNIEnv*, jclass, jlong, jlong, jint, jdouble, jdouble, jdouble, jdouble, jint, jint, jlong, jint, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_drawContours_10
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong contours_mat_nativeObj, jint contourIdx, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3, jint thickness, jint lineType, jlong hierarchy_nativeObj, jint maxLevel, jdouble offset_x, jdouble offset_y)
{
    static const char method_name[] = "imgproc::drawContours_10()";
    try {
        LOGD("%s", method_name);
        std::vector< std::vector<Point> > contours;
        Mat& contours_mat = *((Mat*)contours_mat_nativeObj);
        Mat_to_vector_vector_Point( contours_mat, contours );
        Mat& image = *((Mat*)image_nativeObj);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        Mat& hierarchy = *((Mat*)hierarchy_nativeObj);
        Point offset((int)offset_x, (int)offset_y);
        cv::drawContours( image, contours, (int)contourIdx, color, (int)thickness, (int)lineType, hierarchy, (int)maxLevel, offset );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_drawContours_11 (JNIEnv*, jclass, jlong, jlong, jint, jdouble, jdouble, jdouble, jdouble, jint, jint, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_drawContours_11
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong contours_mat_nativeObj, jint contourIdx, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3, jint thickness, jint lineType, jlong hierarchy_nativeObj, jint maxLevel)
{
    static const char method_name[] = "imgproc::drawContours_11()";
    try {
        LOGD("%s", method_name);
        std::vector< std::vector<Point> > contours;
        Mat& contours_mat = *((Mat*)contours_mat_nativeObj);
        Mat_to_vector_vector_Point( contours_mat, contours );
        Mat& image = *((Mat*)image_nativeObj);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        Mat& hierarchy = *((Mat*)hierarchy_nativeObj);
        cv::drawContours( image, contours, (int)contourIdx, color, (int)thickness, (int)lineType, hierarchy, (int)maxLevel );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_drawContours_12 (JNIEnv*, jclass, jlong, jlong, jint, jdouble, jdouble, jdouble, jdouble, jint, jint, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_drawContours_12
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong contours_mat_nativeObj, jint contourIdx, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3, jint thickness, jint lineType, jlong hierarchy_nativeObj)
{
    static const char method_name[] = "imgproc::drawContours_12()";
    try {
        LOGD("%s", method_name);
        std::vector< std::vector<Point> > contours;
        Mat& contours_mat = *((Mat*)contours_mat_nativeObj);
        Mat_to_vector_vector_Point( contours_mat, contours );
        Mat& image = *((Mat*)image_nativeObj);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        Mat& hierarchy = *((Mat*)hierarchy_nativeObj);
        cv::drawContours( image, contours, (int)contourIdx, color, (int)thickness, (int)lineType, hierarchy );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_drawContours_13 (JNIEnv*, jclass, jlong, jlong, jint, jdouble, jdouble, jdouble, jdouble, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_drawContours_13
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong contours_mat_nativeObj, jint contourIdx, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3, jint thickness, jint lineType)
{
    static const char method_name[] = "imgproc::drawContours_13()";
    try {
        LOGD("%s", method_name);
        std::vector< std::vector<Point> > contours;
        Mat& contours_mat = *((Mat*)contours_mat_nativeObj);
        Mat_to_vector_vector_Point( contours_mat, contours );
        Mat& image = *((Mat*)image_nativeObj);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::drawContours( image, contours, (int)contourIdx, color, (int)thickness, (int)lineType );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_drawContours_14 (JNIEnv*, jclass, jlong, jlong, jint, jdouble, jdouble, jdouble, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_drawContours_14
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong contours_mat_nativeObj, jint contourIdx, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3, jint thickness)
{
    static const char method_name[] = "imgproc::drawContours_14()";
    try {
        LOGD("%s", method_name);
        std::vector< std::vector<Point> > contours;
        Mat& contours_mat = *((Mat*)contours_mat_nativeObj);
        Mat_to_vector_vector_Point( contours_mat, contours );
        Mat& image = *((Mat*)image_nativeObj);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::drawContours( image, contours, (int)contourIdx, color, (int)thickness );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_drawContours_15 (JNIEnv*, jclass, jlong, jlong, jint, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_drawContours_15
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong contours_mat_nativeObj, jint contourIdx, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3)
{
    static const char method_name[] = "imgproc::drawContours_15()";
    try {
        LOGD("%s", method_name);
        std::vector< std::vector<Point> > contours;
        Mat& contours_mat = *((Mat*)contours_mat_nativeObj);
        Mat_to_vector_vector_Point( contours_mat, contours );
        Mat& image = *((Mat*)image_nativeObj);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::drawContours( image, contours, (int)contourIdx, color );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::drawMarker(Mat& img, Point position, Scalar color, int markerType = MARKER_CROSS, int markerSize = 20, int thickness = 1, int line_type = 8)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_drawMarker_10 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jint, jint, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_drawMarker_10
  (JNIEnv* env, jclass , jlong img_nativeObj, jdouble position_x, jdouble position_y, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3, jint markerType, jint markerSize, jint thickness, jint line_type)
{
    static const char method_name[] = "imgproc::drawMarker_10()";
    try {
        LOGD("%s", method_name);
        Mat& img = *((Mat*)img_nativeObj);
        Point position((int)position_x, (int)position_y);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::drawMarker( img, position, color, (int)markerType, (int)markerSize, (int)thickness, (int)line_type );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_drawMarker_11 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jint, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_drawMarker_11
  (JNIEnv* env, jclass , jlong img_nativeObj, jdouble position_x, jdouble position_y, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3, jint markerType, jint markerSize, jint thickness)
{
    static const char method_name[] = "imgproc::drawMarker_11()";
    try {
        LOGD("%s", method_name);
        Mat& img = *((Mat*)img_nativeObj);
        Point position((int)position_x, (int)position_y);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::drawMarker( img, position, color, (int)markerType, (int)markerSize, (int)thickness );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_drawMarker_12 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_drawMarker_12
  (JNIEnv* env, jclass , jlong img_nativeObj, jdouble position_x, jdouble position_y, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3, jint markerType, jint markerSize)
{
    static const char method_name[] = "imgproc::drawMarker_12()";
    try {
        LOGD("%s", method_name);
        Mat& img = *((Mat*)img_nativeObj);
        Point position((int)position_x, (int)position_y);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::drawMarker( img, position, color, (int)markerType, (int)markerSize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_drawMarker_13 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_drawMarker_13
  (JNIEnv* env, jclass , jlong img_nativeObj, jdouble position_x, jdouble position_y, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3, jint markerType)
{
    static const char method_name[] = "imgproc::drawMarker_13()";
    try {
        LOGD("%s", method_name);
        Mat& img = *((Mat*)img_nativeObj);
        Point position((int)position_x, (int)position_y);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::drawMarker( img, position, color, (int)markerType );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_drawMarker_14 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_drawMarker_14
  (JNIEnv* env, jclass , jlong img_nativeObj, jdouble position_x, jdouble position_y, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3)
{
    static const char method_name[] = "imgproc::drawMarker_14()";
    try {
        LOGD("%s", method_name);
        Mat& img = *((Mat*)img_nativeObj);
        Point position((int)position_x, (int)position_y);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::drawMarker( img, position, color );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::ellipse(Mat& img, Point center, Size axes, double angle, double startAngle, double endAngle, Scalar color, int thickness = 1, int lineType = LINE_8, int shift = 0)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_ellipse_10 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jint, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_ellipse_10
  (JNIEnv* env, jclass , jlong img_nativeObj, jdouble center_x, jdouble center_y, jdouble axes_width, jdouble axes_height, jdouble angle, jdouble startAngle, jdouble endAngle, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3, jint thickness, jint lineType, jint shift)
{
    static const char method_name[] = "imgproc::ellipse_10()";
    try {
        LOGD("%s", method_name);
        Mat& img = *((Mat*)img_nativeObj);
        Point center((int)center_x, (int)center_y);
        Size axes((int)axes_width, (int)axes_height);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::ellipse( img, center, axes, (double)angle, (double)startAngle, (double)endAngle, color, (int)thickness, (int)lineType, (int)shift );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_ellipse_11 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_ellipse_11
  (JNIEnv* env, jclass , jlong img_nativeObj, jdouble center_x, jdouble center_y, jdouble axes_width, jdouble axes_height, jdouble angle, jdouble startAngle, jdouble endAngle, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3, jint thickness, jint lineType)
{
    static const char method_name[] = "imgproc::ellipse_11()";
    try {
        LOGD("%s", method_name);
        Mat& img = *((Mat*)img_nativeObj);
        Point center((int)center_x, (int)center_y);
        Size axes((int)axes_width, (int)axes_height);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::ellipse( img, center, axes, (double)angle, (double)startAngle, (double)endAngle, color, (int)thickness, (int)lineType );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_ellipse_12 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_ellipse_12
  (JNIEnv* env, jclass , jlong img_nativeObj, jdouble center_x, jdouble center_y, jdouble axes_width, jdouble axes_height, jdouble angle, jdouble startAngle, jdouble endAngle, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3, jint thickness)
{
    static const char method_name[] = "imgproc::ellipse_12()";
    try {
        LOGD("%s", method_name);
        Mat& img = *((Mat*)img_nativeObj);
        Point center((int)center_x, (int)center_y);
        Size axes((int)axes_width, (int)axes_height);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::ellipse( img, center, axes, (double)angle, (double)startAngle, (double)endAngle, color, (int)thickness );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_ellipse_13 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_ellipse_13
  (JNIEnv* env, jclass , jlong img_nativeObj, jdouble center_x, jdouble center_y, jdouble axes_width, jdouble axes_height, jdouble angle, jdouble startAngle, jdouble endAngle, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3)
{
    static const char method_name[] = "imgproc::ellipse_13()";
    try {
        LOGD("%s", method_name);
        Mat& img = *((Mat*)img_nativeObj);
        Point center((int)center_x, (int)center_y);
        Size axes((int)axes_width, (int)axes_height);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::ellipse( img, center, axes, (double)angle, (double)startAngle, (double)endAngle, color );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::ellipse(Mat& img, RotatedRect box, Scalar color, int thickness = 1, int lineType = LINE_8)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_ellipse_14 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_ellipse_14
  (JNIEnv* env, jclass , jlong img_nativeObj, jdouble box_center_x, jdouble box_center_y, jdouble box_size_width, jdouble box_size_height, jdouble box_angle, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3, jint thickness, jint lineType)
{
    static const char method_name[] = "imgproc::ellipse_14()";
    try {
        LOGD("%s", method_name);
        Mat& img = *((Mat*)img_nativeObj);
        RotatedRect box(cv::Point2f(box_center_x, box_center_y), cv::Size2f(box_size_width, box_size_height), box_angle);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::ellipse( img, box, color, (int)thickness, (int)lineType );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_ellipse_15 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_ellipse_15
  (JNIEnv* env, jclass , jlong img_nativeObj, jdouble box_center_x, jdouble box_center_y, jdouble box_size_width, jdouble box_size_height, jdouble box_angle, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3, jint thickness)
{
    static const char method_name[] = "imgproc::ellipse_15()";
    try {
        LOGD("%s", method_name);
        Mat& img = *((Mat*)img_nativeObj);
        RotatedRect box(cv::Point2f(box_center_x, box_center_y), cv::Size2f(box_size_width, box_size_height), box_angle);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::ellipse( img, box, color, (int)thickness );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_ellipse_16 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_ellipse_16
  (JNIEnv* env, jclass , jlong img_nativeObj, jdouble box_center_x, jdouble box_center_y, jdouble box_size_width, jdouble box_size_height, jdouble box_angle, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3)
{
    static const char method_name[] = "imgproc::ellipse_16()";
    try {
        LOGD("%s", method_name);
        Mat& img = *((Mat*)img_nativeObj);
        RotatedRect box(cv::Point2f(box_center_x, box_center_y), cv::Size2f(box_size_width, box_size_height), box_angle);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::ellipse( img, box, color );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::ellipse2Poly(Point center, Size axes, int angle, int arcStart, int arcEnd, int delta, vector_Point& pts)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_ellipse2Poly_10 (JNIEnv*, jclass, jdouble, jdouble, jdouble, jdouble, jint, jint, jint, jint, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_ellipse2Poly_10
  (JNIEnv* env, jclass , jdouble center_x, jdouble center_y, jdouble axes_width, jdouble axes_height, jint angle, jint arcStart, jint arcEnd, jint delta, jlong pts_mat_nativeObj)
{
    static const char method_name[] = "imgproc::ellipse2Poly_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Point> pts;
        Mat& pts_mat = *((Mat*)pts_mat_nativeObj);
        Point center((int)center_x, (int)center_y);
        Size axes((int)axes_width, (int)axes_height);
        cv::ellipse2Poly( center, axes, (int)angle, (int)arcStart, (int)arcEnd, (int)delta, pts );
        vector_Point_to_Mat( pts, pts_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::equalizeHist(Mat src, Mat& dst)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_equalizeHist_10 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_equalizeHist_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "imgproc::equalizeHist_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::equalizeHist( src, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::erode(Mat src, Mat& dst, Mat kernel, Point anchor = Point(-1,-1), int iterations = 1, int borderType = BORDER_CONSTANT, Scalar borderValue = morphologyDefaultBorderValue())
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_erode_10 (JNIEnv*, jclass, jlong, jlong, jlong, jdouble, jdouble, jint, jint, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_erode_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jlong kernel_nativeObj, jdouble anchor_x, jdouble anchor_y, jint iterations, jint borderType, jdouble borderValue_val0, jdouble borderValue_val1, jdouble borderValue_val2, jdouble borderValue_val3)
{
    static const char method_name[] = "imgproc::erode_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& kernel = *((Mat*)kernel_nativeObj);
        Point anchor((int)anchor_x, (int)anchor_y);
        Scalar borderValue(borderValue_val0, borderValue_val1, borderValue_val2, borderValue_val3);
        cv::erode( src, dst, kernel, anchor, (int)iterations, (int)borderType, borderValue );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_erode_11 (JNIEnv*, jclass, jlong, jlong, jlong, jdouble, jdouble, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_erode_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jlong kernel_nativeObj, jdouble anchor_x, jdouble anchor_y, jint iterations, jint borderType)
{
    static const char method_name[] = "imgproc::erode_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& kernel = *((Mat*)kernel_nativeObj);
        Point anchor((int)anchor_x, (int)anchor_y);
        cv::erode( src, dst, kernel, anchor, (int)iterations, (int)borderType );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_erode_12 (JNIEnv*, jclass, jlong, jlong, jlong, jdouble, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_erode_12
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jlong kernel_nativeObj, jdouble anchor_x, jdouble anchor_y, jint iterations)
{
    static const char method_name[] = "imgproc::erode_12()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& kernel = *((Mat*)kernel_nativeObj);
        Point anchor((int)anchor_x, (int)anchor_y);
        cv::erode( src, dst, kernel, anchor, (int)iterations );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_erode_13 (JNIEnv*, jclass, jlong, jlong, jlong, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_erode_13
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jlong kernel_nativeObj, jdouble anchor_x, jdouble anchor_y)
{
    static const char method_name[] = "imgproc::erode_13()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& kernel = *((Mat*)kernel_nativeObj);
        Point anchor((int)anchor_x, (int)anchor_y);
        cv::erode( src, dst, kernel, anchor );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_erode_14 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_erode_14
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jlong kernel_nativeObj)
{
    static const char method_name[] = "imgproc::erode_14()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& kernel = *((Mat*)kernel_nativeObj);
        cv::erode( src, dst, kernel );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::fillConvexPoly(Mat& img, vector_Point points, Scalar color, int lineType = LINE_8, int shift = 0)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_fillConvexPoly_10 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jdouble, jdouble, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_fillConvexPoly_10
  (JNIEnv* env, jclass , jlong img_nativeObj, jlong points_mat_nativeObj, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3, jint lineType, jint shift)
{
    static const char method_name[] = "imgproc::fillConvexPoly_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Point> points;
        Mat& points_mat = *((Mat*)points_mat_nativeObj);
        Mat_to_vector_Point( points_mat, points );
        Mat& img = *((Mat*)img_nativeObj);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::fillConvexPoly( img, points, color, (int)lineType, (int)shift );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_fillConvexPoly_11 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jdouble, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_fillConvexPoly_11
  (JNIEnv* env, jclass , jlong img_nativeObj, jlong points_mat_nativeObj, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3, jint lineType)
{
    static const char method_name[] = "imgproc::fillConvexPoly_11()";
    try {
        LOGD("%s", method_name);
        std::vector<Point> points;
        Mat& points_mat = *((Mat*)points_mat_nativeObj);
        Mat_to_vector_Point( points_mat, points );
        Mat& img = *((Mat*)img_nativeObj);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::fillConvexPoly( img, points, color, (int)lineType );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_fillConvexPoly_12 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_fillConvexPoly_12
  (JNIEnv* env, jclass , jlong img_nativeObj, jlong points_mat_nativeObj, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3)
{
    static const char method_name[] = "imgproc::fillConvexPoly_12()";
    try {
        LOGD("%s", method_name);
        std::vector<Point> points;
        Mat& points_mat = *((Mat*)points_mat_nativeObj);
        Mat_to_vector_Point( points_mat, points );
        Mat& img = *((Mat*)img_nativeObj);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::fillConvexPoly( img, points, color );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::fillPoly(Mat& img, vector_vector_Point pts, Scalar color, int lineType = LINE_8, int shift = 0, Point offset = Point())
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_fillPoly_10 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jdouble, jdouble, jint, jint, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_fillPoly_10
  (JNIEnv* env, jclass , jlong img_nativeObj, jlong pts_mat_nativeObj, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3, jint lineType, jint shift, jdouble offset_x, jdouble offset_y)
{
    static const char method_name[] = "imgproc::fillPoly_10()";
    try {
        LOGD("%s", method_name);
        std::vector< std::vector<Point> > pts;
        Mat& pts_mat = *((Mat*)pts_mat_nativeObj);
        Mat_to_vector_vector_Point( pts_mat, pts );
        Mat& img = *((Mat*)img_nativeObj);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        Point offset((int)offset_x, (int)offset_y);
        cv::fillPoly( img, pts, color, (int)lineType, (int)shift, offset );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_fillPoly_11 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jdouble, jdouble, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_fillPoly_11
  (JNIEnv* env, jclass , jlong img_nativeObj, jlong pts_mat_nativeObj, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3, jint lineType, jint shift)
{
    static const char method_name[] = "imgproc::fillPoly_11()";
    try {
        LOGD("%s", method_name);
        std::vector< std::vector<Point> > pts;
        Mat& pts_mat = *((Mat*)pts_mat_nativeObj);
        Mat_to_vector_vector_Point( pts_mat, pts );
        Mat& img = *((Mat*)img_nativeObj);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::fillPoly( img, pts, color, (int)lineType, (int)shift );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_fillPoly_12 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jdouble, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_fillPoly_12
  (JNIEnv* env, jclass , jlong img_nativeObj, jlong pts_mat_nativeObj, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3, jint lineType)
{
    static const char method_name[] = "imgproc::fillPoly_12()";
    try {
        LOGD("%s", method_name);
        std::vector< std::vector<Point> > pts;
        Mat& pts_mat = *((Mat*)pts_mat_nativeObj);
        Mat_to_vector_vector_Point( pts_mat, pts );
        Mat& img = *((Mat*)img_nativeObj);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::fillPoly( img, pts, color, (int)lineType );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_fillPoly_13 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_fillPoly_13
  (JNIEnv* env, jclass , jlong img_nativeObj, jlong pts_mat_nativeObj, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3)
{
    static const char method_name[] = "imgproc::fillPoly_13()";
    try {
        LOGD("%s", method_name);
        std::vector< std::vector<Point> > pts;
        Mat& pts_mat = *((Mat*)pts_mat_nativeObj);
        Mat_to_vector_vector_Point( pts_mat, pts );
        Mat& img = *((Mat*)img_nativeObj);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::fillPoly( img, pts, color );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::filter2D(Mat src, Mat& dst, int ddepth, Mat kernel, Point anchor = Point(-1,-1), double delta = 0, int borderType = BORDER_DEFAULT)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_filter2D_10 (JNIEnv*, jclass, jlong, jlong, jint, jlong, jdouble, jdouble, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_filter2D_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint ddepth, jlong kernel_nativeObj, jdouble anchor_x, jdouble anchor_y, jdouble delta, jint borderType)
{
    static const char method_name[] = "imgproc::filter2D_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& kernel = *((Mat*)kernel_nativeObj);
        Point anchor((int)anchor_x, (int)anchor_y);
        cv::filter2D( src, dst, (int)ddepth, kernel, anchor, (double)delta, (int)borderType );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_filter2D_11 (JNIEnv*, jclass, jlong, jlong, jint, jlong, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_filter2D_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint ddepth, jlong kernel_nativeObj, jdouble anchor_x, jdouble anchor_y, jdouble delta)
{
    static const char method_name[] = "imgproc::filter2D_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& kernel = *((Mat*)kernel_nativeObj);
        Point anchor((int)anchor_x, (int)anchor_y);
        cv::filter2D( src, dst, (int)ddepth, kernel, anchor, (double)delta );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_filter2D_12 (JNIEnv*, jclass, jlong, jlong, jint, jlong, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_filter2D_12
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint ddepth, jlong kernel_nativeObj, jdouble anchor_x, jdouble anchor_y)
{
    static const char method_name[] = "imgproc::filter2D_12()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& kernel = *((Mat*)kernel_nativeObj);
        Point anchor((int)anchor_x, (int)anchor_y);
        cv::filter2D( src, dst, (int)ddepth, kernel, anchor );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_filter2D_13 (JNIEnv*, jclass, jlong, jlong, jint, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_filter2D_13
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint ddepth, jlong kernel_nativeObj)
{
    static const char method_name[] = "imgproc::filter2D_13()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& kernel = *((Mat*)kernel_nativeObj);
        cv::filter2D( src, dst, (int)ddepth, kernel );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::findContours(Mat image, vector_vector_Point& contours, Mat& hierarchy, int mode, int method, Point offset = Point())
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_findContours_10 (JNIEnv*, jclass, jlong, jlong, jlong, jint, jint, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_findContours_10
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong contours_mat_nativeObj, jlong hierarchy_nativeObj, jint mode, jint method, jdouble offset_x, jdouble offset_y)
{
    static const char method_name[] = "imgproc::findContours_10()";
    try {
        LOGD("%s", method_name);
        std::vector< std::vector<Point> > contours;
        Mat& contours_mat = *((Mat*)contours_mat_nativeObj);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& hierarchy = *((Mat*)hierarchy_nativeObj);
        Point offset((int)offset_x, (int)offset_y);
        cv::findContours( image, contours, hierarchy, (int)mode, (int)method, offset );
        vector_vector_Point_to_Mat( contours, contours_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_findContours_11 (JNIEnv*, jclass, jlong, jlong, jlong, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_findContours_11
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong contours_mat_nativeObj, jlong hierarchy_nativeObj, jint mode, jint method)
{
    static const char method_name[] = "imgproc::findContours_11()";
    try {
        LOGD("%s", method_name);
        std::vector< std::vector<Point> > contours;
        Mat& contours_mat = *((Mat*)contours_mat_nativeObj);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& hierarchy = *((Mat*)hierarchy_nativeObj);
        cv::findContours( image, contours, hierarchy, (int)mode, (int)method );
        vector_vector_Point_to_Mat( contours, contours_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::fitLine(Mat points, Mat& line, int distType, double param, double reps, double aeps)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_fitLine_10 (JNIEnv*, jclass, jlong, jlong, jint, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_fitLine_10
  (JNIEnv* env, jclass , jlong points_nativeObj, jlong line_nativeObj, jint distType, jdouble param, jdouble reps, jdouble aeps)
{
    static const char method_name[] = "imgproc::fitLine_10()";
    try {
        LOGD("%s", method_name);
        Mat& points = *((Mat*)points_nativeObj);
        Mat& line = *((Mat*)line_nativeObj);
        cv::fitLine( points, line, (int)distType, (double)param, (double)reps, (double)aeps );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::getDerivKernels(Mat& kx, Mat& ky, int dx, int dy, int ksize, bool normalize = false, int ktype = CV_32F)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_getDerivKernels_10 (JNIEnv*, jclass, jlong, jlong, jint, jint, jint, jboolean, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_getDerivKernels_10
  (JNIEnv* env, jclass , jlong kx_nativeObj, jlong ky_nativeObj, jint dx, jint dy, jint ksize, jboolean normalize, jint ktype)
{
    static const char method_name[] = "imgproc::getDerivKernels_10()";
    try {
        LOGD("%s", method_name);
        Mat& kx = *((Mat*)kx_nativeObj);
        Mat& ky = *((Mat*)ky_nativeObj);
        cv::getDerivKernels( kx, ky, (int)dx, (int)dy, (int)ksize, (bool)normalize, (int)ktype );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_getDerivKernels_11 (JNIEnv*, jclass, jlong, jlong, jint, jint, jint, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_getDerivKernels_11
  (JNIEnv* env, jclass , jlong kx_nativeObj, jlong ky_nativeObj, jint dx, jint dy, jint ksize, jboolean normalize)
{
    static const char method_name[] = "imgproc::getDerivKernels_11()";
    try {
        LOGD("%s", method_name);
        Mat& kx = *((Mat*)kx_nativeObj);
        Mat& ky = *((Mat*)ky_nativeObj);
        cv::getDerivKernels( kx, ky, (int)dx, (int)dy, (int)ksize, (bool)normalize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_getDerivKernels_12 (JNIEnv*, jclass, jlong, jlong, jint, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_getDerivKernels_12
  (JNIEnv* env, jclass , jlong kx_nativeObj, jlong ky_nativeObj, jint dx, jint dy, jint ksize)
{
    static const char method_name[] = "imgproc::getDerivKernels_12()";
    try {
        LOGD("%s", method_name);
        Mat& kx = *((Mat*)kx_nativeObj);
        Mat& ky = *((Mat*)ky_nativeObj);
        cv::getDerivKernels( kx, ky, (int)dx, (int)dy, (int)ksize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::getRectSubPix(Mat image, Size patchSize, Point2f center, Mat& patch, int patchType = -1)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_getRectSubPix_10 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_getRectSubPix_10
  (JNIEnv* env, jclass , jlong image_nativeObj, jdouble patchSize_width, jdouble patchSize_height, jdouble center_x, jdouble center_y, jlong patch_nativeObj, jint patchType)
{
    static const char method_name[] = "imgproc::getRectSubPix_10()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Size patchSize((int)patchSize_width, (int)patchSize_height);
        Point2f center((float)center_x, (float)center_y);
        Mat& patch = *((Mat*)patch_nativeObj);
        cv::getRectSubPix( image, patchSize, center, patch, (int)patchType );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_getRectSubPix_11 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_getRectSubPix_11
  (JNIEnv* env, jclass , jlong image_nativeObj, jdouble patchSize_width, jdouble patchSize_height, jdouble center_x, jdouble center_y, jlong patch_nativeObj)
{
    static const char method_name[] = "imgproc::getRectSubPix_11()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Size patchSize((int)patchSize_width, (int)patchSize_height);
        Point2f center((float)center_x, (float)center_y);
        Mat& patch = *((Mat*)patch_nativeObj);
        cv::getRectSubPix( image, patchSize, center, patch );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::goodFeaturesToTrack(Mat image, vector_Point& corners, int maxCorners, double qualityLevel, double minDistance, Mat mask, int blockSize, int gradientSize, bool useHarrisDetector = false, double k = 0.04)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_goodFeaturesToTrack_10 (JNIEnv*, jclass, jlong, jlong, jint, jdouble, jdouble, jlong, jint, jint, jboolean, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_goodFeaturesToTrack_10
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong corners_mat_nativeObj, jint maxCorners, jdouble qualityLevel, jdouble minDistance, jlong mask_nativeObj, jint blockSize, jint gradientSize, jboolean useHarrisDetector, jdouble k)
{
    static const char method_name[] = "imgproc::goodFeaturesToTrack_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Point> corners;
        Mat& corners_mat = *((Mat*)corners_mat_nativeObj);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        cv::goodFeaturesToTrack( image, corners, (int)maxCorners, (double)qualityLevel, (double)minDistance, mask, (int)blockSize, (int)gradientSize, (bool)useHarrisDetector, (double)k );
        vector_Point_to_Mat( corners, corners_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_goodFeaturesToTrack_11 (JNIEnv*, jclass, jlong, jlong, jint, jdouble, jdouble, jlong, jint, jint, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_goodFeaturesToTrack_11
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong corners_mat_nativeObj, jint maxCorners, jdouble qualityLevel, jdouble minDistance, jlong mask_nativeObj, jint blockSize, jint gradientSize, jboolean useHarrisDetector)
{
    static const char method_name[] = "imgproc::goodFeaturesToTrack_11()";
    try {
        LOGD("%s", method_name);
        std::vector<Point> corners;
        Mat& corners_mat = *((Mat*)corners_mat_nativeObj);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        cv::goodFeaturesToTrack( image, corners, (int)maxCorners, (double)qualityLevel, (double)minDistance, mask, (int)blockSize, (int)gradientSize, (bool)useHarrisDetector );
        vector_Point_to_Mat( corners, corners_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_goodFeaturesToTrack_12 (JNIEnv*, jclass, jlong, jlong, jint, jdouble, jdouble, jlong, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_goodFeaturesToTrack_12
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong corners_mat_nativeObj, jint maxCorners, jdouble qualityLevel, jdouble minDistance, jlong mask_nativeObj, jint blockSize, jint gradientSize)
{
    static const char method_name[] = "imgproc::goodFeaturesToTrack_12()";
    try {
        LOGD("%s", method_name);
        std::vector<Point> corners;
        Mat& corners_mat = *((Mat*)corners_mat_nativeObj);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        cv::goodFeaturesToTrack( image, corners, (int)maxCorners, (double)qualityLevel, (double)minDistance, mask, (int)blockSize, (int)gradientSize );
        vector_Point_to_Mat( corners, corners_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::goodFeaturesToTrack(Mat image, vector_Point& corners, int maxCorners, double qualityLevel, double minDistance, Mat mask = Mat(), int blockSize = 3, bool useHarrisDetector = false, double k = 0.04)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_goodFeaturesToTrack_13 (JNIEnv*, jclass, jlong, jlong, jint, jdouble, jdouble, jlong, jint, jboolean, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_goodFeaturesToTrack_13
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong corners_mat_nativeObj, jint maxCorners, jdouble qualityLevel, jdouble minDistance, jlong mask_nativeObj, jint blockSize, jboolean useHarrisDetector, jdouble k)
{
    static const char method_name[] = "imgproc::goodFeaturesToTrack_13()";
    try {
        LOGD("%s", method_name);
        std::vector<Point> corners;
        Mat& corners_mat = *((Mat*)corners_mat_nativeObj);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        cv::goodFeaturesToTrack( image, corners, (int)maxCorners, (double)qualityLevel, (double)minDistance, mask, (int)blockSize, (bool)useHarrisDetector, (double)k );
        vector_Point_to_Mat( corners, corners_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_goodFeaturesToTrack_14 (JNIEnv*, jclass, jlong, jlong, jint, jdouble, jdouble, jlong, jint, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_goodFeaturesToTrack_14
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong corners_mat_nativeObj, jint maxCorners, jdouble qualityLevel, jdouble minDistance, jlong mask_nativeObj, jint blockSize, jboolean useHarrisDetector)
{
    static const char method_name[] = "imgproc::goodFeaturesToTrack_14()";
    try {
        LOGD("%s", method_name);
        std::vector<Point> corners;
        Mat& corners_mat = *((Mat*)corners_mat_nativeObj);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        cv::goodFeaturesToTrack( image, corners, (int)maxCorners, (double)qualityLevel, (double)minDistance, mask, (int)blockSize, (bool)useHarrisDetector );
        vector_Point_to_Mat( corners, corners_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_goodFeaturesToTrack_15 (JNIEnv*, jclass, jlong, jlong, jint, jdouble, jdouble, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_goodFeaturesToTrack_15
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong corners_mat_nativeObj, jint maxCorners, jdouble qualityLevel, jdouble minDistance, jlong mask_nativeObj, jint blockSize)
{
    static const char method_name[] = "imgproc::goodFeaturesToTrack_15()";
    try {
        LOGD("%s", method_name);
        std::vector<Point> corners;
        Mat& corners_mat = *((Mat*)corners_mat_nativeObj);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        cv::goodFeaturesToTrack( image, corners, (int)maxCorners, (double)qualityLevel, (double)minDistance, mask, (int)blockSize );
        vector_Point_to_Mat( corners, corners_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_goodFeaturesToTrack_16 (JNIEnv*, jclass, jlong, jlong, jint, jdouble, jdouble, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_goodFeaturesToTrack_16
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong corners_mat_nativeObj, jint maxCorners, jdouble qualityLevel, jdouble minDistance, jlong mask_nativeObj)
{
    static const char method_name[] = "imgproc::goodFeaturesToTrack_16()";
    try {
        LOGD("%s", method_name);
        std::vector<Point> corners;
        Mat& corners_mat = *((Mat*)corners_mat_nativeObj);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        cv::goodFeaturesToTrack( image, corners, (int)maxCorners, (double)qualityLevel, (double)minDistance, mask );
        vector_Point_to_Mat( corners, corners_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_goodFeaturesToTrack_17 (JNIEnv*, jclass, jlong, jlong, jint, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_goodFeaturesToTrack_17
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong corners_mat_nativeObj, jint maxCorners, jdouble qualityLevel, jdouble minDistance)
{
    static const char method_name[] = "imgproc::goodFeaturesToTrack_17()";
    try {
        LOGD("%s", method_name);
        std::vector<Point> corners;
        Mat& corners_mat = *((Mat*)corners_mat_nativeObj);
        Mat& image = *((Mat*)image_nativeObj);
        cv::goodFeaturesToTrack( image, corners, (int)maxCorners, (double)qualityLevel, (double)minDistance );
        vector_Point_to_Mat( corners, corners_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::grabCut(Mat img, Mat& mask, Rect rect, Mat& bgdModel, Mat& fgdModel, int iterCount, int mode = GC_EVAL)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_grabCut_10 (JNIEnv*, jclass, jlong, jlong, jint, jint, jint, jint, jlong, jlong, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_grabCut_10
  (JNIEnv* env, jclass , jlong img_nativeObj, jlong mask_nativeObj, jint rect_x, jint rect_y, jint rect_width, jint rect_height, jlong bgdModel_nativeObj, jlong fgdModel_nativeObj, jint iterCount, jint mode)
{
    static const char method_name[] = "imgproc::grabCut_10()";
    try {
        LOGD("%s", method_name);
        Mat& img = *((Mat*)img_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        Rect rect(rect_x, rect_y, rect_width, rect_height);
        Mat& bgdModel = *((Mat*)bgdModel_nativeObj);
        Mat& fgdModel = *((Mat*)fgdModel_nativeObj);
        cv::grabCut( img, mask, rect, bgdModel, fgdModel, (int)iterCount, (int)mode );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_grabCut_11 (JNIEnv*, jclass, jlong, jlong, jint, jint, jint, jint, jlong, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_grabCut_11
  (JNIEnv* env, jclass , jlong img_nativeObj, jlong mask_nativeObj, jint rect_x, jint rect_y, jint rect_width, jint rect_height, jlong bgdModel_nativeObj, jlong fgdModel_nativeObj, jint iterCount)
{
    static const char method_name[] = "imgproc::grabCut_11()";
    try {
        LOGD("%s", method_name);
        Mat& img = *((Mat*)img_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        Rect rect(rect_x, rect_y, rect_width, rect_height);
        Mat& bgdModel = *((Mat*)bgdModel_nativeObj);
        Mat& fgdModel = *((Mat*)fgdModel_nativeObj);
        cv::grabCut( img, mask, rect, bgdModel, fgdModel, (int)iterCount );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::integral(Mat src, Mat& sum, Mat& sqsum, Mat& tilted, int sdepth = -1, int sqdepth = -1)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_integral3_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_integral3_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong sum_nativeObj, jlong sqsum_nativeObj, jlong tilted_nativeObj, jint sdepth, jint sqdepth)
{
    static const char method_name[] = "imgproc::integral3_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& sum = *((Mat*)sum_nativeObj);
        Mat& sqsum = *((Mat*)sqsum_nativeObj);
        Mat& tilted = *((Mat*)tilted_nativeObj);
        cv::integral( src, sum, sqsum, tilted, (int)sdepth, (int)sqdepth );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_integral3_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_integral3_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong sum_nativeObj, jlong sqsum_nativeObj, jlong tilted_nativeObj, jint sdepth)
{
    static const char method_name[] = "imgproc::integral3_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& sum = *((Mat*)sum_nativeObj);
        Mat& sqsum = *((Mat*)sqsum_nativeObj);
        Mat& tilted = *((Mat*)tilted_nativeObj);
        cv::integral( src, sum, sqsum, tilted, (int)sdepth );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_integral3_12 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_integral3_12
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong sum_nativeObj, jlong sqsum_nativeObj, jlong tilted_nativeObj)
{
    static const char method_name[] = "imgproc::integral3_12()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& sum = *((Mat*)sum_nativeObj);
        Mat& sqsum = *((Mat*)sqsum_nativeObj);
        Mat& tilted = *((Mat*)tilted_nativeObj);
        cv::integral( src, sum, sqsum, tilted );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::integral(Mat src, Mat& sum, Mat& sqsum, int sdepth = -1, int sqdepth = -1)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_integral2_10 (JNIEnv*, jclass, jlong, jlong, jlong, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_integral2_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong sum_nativeObj, jlong sqsum_nativeObj, jint sdepth, jint sqdepth)
{
    static const char method_name[] = "imgproc::integral2_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& sum = *((Mat*)sum_nativeObj);
        Mat& sqsum = *((Mat*)sqsum_nativeObj);
        cv::integral( src, sum, sqsum, (int)sdepth, (int)sqdepth );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_integral2_11 (JNIEnv*, jclass, jlong, jlong, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_integral2_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong sum_nativeObj, jlong sqsum_nativeObj, jint sdepth)
{
    static const char method_name[] = "imgproc::integral2_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& sum = *((Mat*)sum_nativeObj);
        Mat& sqsum = *((Mat*)sqsum_nativeObj);
        cv::integral( src, sum, sqsum, (int)sdepth );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_integral2_12 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_integral2_12
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong sum_nativeObj, jlong sqsum_nativeObj)
{
    static const char method_name[] = "imgproc::integral2_12()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& sum = *((Mat*)sum_nativeObj);
        Mat& sqsum = *((Mat*)sqsum_nativeObj);
        cv::integral( src, sum, sqsum );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::integral(Mat src, Mat& sum, int sdepth = -1)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_integral_10 (JNIEnv*, jclass, jlong, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_integral_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong sum_nativeObj, jint sdepth)
{
    static const char method_name[] = "imgproc::integral_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& sum = *((Mat*)sum_nativeObj);
        cv::integral( src, sum, (int)sdepth );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_integral_11 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_integral_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong sum_nativeObj)
{
    static const char method_name[] = "imgproc::integral_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& sum = *((Mat*)sum_nativeObj);
        cv::integral( src, sum );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::invertAffineTransform(Mat M, Mat& iM)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_invertAffineTransform_10 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_invertAffineTransform_10
  (JNIEnv* env, jclass , jlong M_nativeObj, jlong iM_nativeObj)
{
    static const char method_name[] = "imgproc::invertAffineTransform_10()";
    try {
        LOGD("%s", method_name);
        Mat& M = *((Mat*)M_nativeObj);
        Mat& iM = *((Mat*)iM_nativeObj);
        cv::invertAffineTransform( M, iM );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::line(Mat& img, Point pt1, Point pt2, Scalar color, int thickness = 1, int lineType = LINE_8, int shift = 0)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_line_10 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jint, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_line_10
  (JNIEnv* env, jclass , jlong img_nativeObj, jdouble pt1_x, jdouble pt1_y, jdouble pt2_x, jdouble pt2_y, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3, jint thickness, jint lineType, jint shift)
{
    static const char method_name[] = "imgproc::line_10()";
    try {
        LOGD("%s", method_name);
        Mat& img = *((Mat*)img_nativeObj);
        Point pt1((int)pt1_x, (int)pt1_y);
        Point pt2((int)pt2_x, (int)pt2_y);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::line( img, pt1, pt2, color, (int)thickness, (int)lineType, (int)shift );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_line_11 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_line_11
  (JNIEnv* env, jclass , jlong img_nativeObj, jdouble pt1_x, jdouble pt1_y, jdouble pt2_x, jdouble pt2_y, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3, jint thickness, jint lineType)
{
    static const char method_name[] = "imgproc::line_11()";
    try {
        LOGD("%s", method_name);
        Mat& img = *((Mat*)img_nativeObj);
        Point pt1((int)pt1_x, (int)pt1_y);
        Point pt2((int)pt2_x, (int)pt2_y);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::line( img, pt1, pt2, color, (int)thickness, (int)lineType );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_line_12 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_line_12
  (JNIEnv* env, jclass , jlong img_nativeObj, jdouble pt1_x, jdouble pt1_y, jdouble pt2_x, jdouble pt2_y, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3, jint thickness)
{
    static const char method_name[] = "imgproc::line_12()";
    try {
        LOGD("%s", method_name);
        Mat& img = *((Mat*)img_nativeObj);
        Point pt1((int)pt1_x, (int)pt1_y);
        Point pt2((int)pt2_x, (int)pt2_y);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::line( img, pt1, pt2, color, (int)thickness );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_line_13 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_line_13
  (JNIEnv* env, jclass , jlong img_nativeObj, jdouble pt1_x, jdouble pt1_y, jdouble pt2_x, jdouble pt2_y, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3)
{
    static const char method_name[] = "imgproc::line_13()";
    try {
        LOGD("%s", method_name);
        Mat& img = *((Mat*)img_nativeObj);
        Point pt1((int)pt1_x, (int)pt1_y);
        Point pt2((int)pt2_x, (int)pt2_y);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::line( img, pt1, pt2, color );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::linearPolar(Mat src, Mat& dst, Point2f center, double maxRadius, int flags)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_linearPolar_10 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_linearPolar_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jdouble center_x, jdouble center_y, jdouble maxRadius, jint flags)
{
    static const char method_name[] = "imgproc::linearPolar_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Point2f center((float)center_x, (float)center_y);
        cv::linearPolar( src, dst, center, (double)maxRadius, (int)flags );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::logPolar(Mat src, Mat& dst, Point2f center, double M, int flags)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_logPolar_10 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_logPolar_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jdouble center_x, jdouble center_y, jdouble M, jint flags)
{
    static const char method_name[] = "imgproc::logPolar_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Point2f center((float)center_x, (float)center_y);
        cv::logPolar( src, dst, center, (double)M, (int)flags );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::matchTemplate(Mat image, Mat templ, Mat& result, int method, Mat mask = Mat())
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_matchTemplate_10 (JNIEnv*, jclass, jlong, jlong, jlong, jint, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_matchTemplate_10
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong templ_nativeObj, jlong result_nativeObj, jint method, jlong mask_nativeObj)
{
    static const char method_name[] = "imgproc::matchTemplate_10()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& templ = *((Mat*)templ_nativeObj);
        Mat& result = *((Mat*)result_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        cv::matchTemplate( image, templ, result, (int)method, mask );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_matchTemplate_11 (JNIEnv*, jclass, jlong, jlong, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_matchTemplate_11
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong templ_nativeObj, jlong result_nativeObj, jint method)
{
    static const char method_name[] = "imgproc::matchTemplate_11()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& templ = *((Mat*)templ_nativeObj);
        Mat& result = *((Mat*)result_nativeObj);
        cv::matchTemplate( image, templ, result, (int)method );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::medianBlur(Mat src, Mat& dst, int ksize)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_medianBlur_10 (JNIEnv*, jclass, jlong, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_medianBlur_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint ksize)
{
    static const char method_name[] = "imgproc::medianBlur_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::medianBlur( src, dst, (int)ksize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::minEnclosingCircle(vector_Point2f points, Point2f& center, float& radius)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_minEnclosingCircle_10 (JNIEnv*, jclass, jlong, jdoubleArray, jdoubleArray);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_minEnclosingCircle_10
  (JNIEnv* env, jclass , jlong points_mat_nativeObj, jdoubleArray center_out, jdoubleArray radius_out)
{
    static const char method_name[] = "imgproc::minEnclosingCircle_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Point2f> points;
        Mat& points_mat = *((Mat*)points_mat_nativeObj);
        Mat_to_vector_Point2f( points_mat, points );
        Point2f center;
        float radius;
        cv::minEnclosingCircle( points, center, radius );
        jdouble tmp_center[2] = {(jdouble)center.x, (jdouble)center.y}; env->SetDoubleArrayRegion(center_out, 0, 2, tmp_center);
        jdouble tmp_radius[1] = {(jdouble)radius}; env->SetDoubleArrayRegion(radius_out, 0, 1, tmp_radius);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::morphologyEx(Mat src, Mat& dst, int op, Mat kernel, Point anchor = Point(-1,-1), int iterations = 1, int borderType = BORDER_CONSTANT, Scalar borderValue = morphologyDefaultBorderValue())
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_morphologyEx_10 (JNIEnv*, jclass, jlong, jlong, jint, jlong, jdouble, jdouble, jint, jint, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_morphologyEx_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint op, jlong kernel_nativeObj, jdouble anchor_x, jdouble anchor_y, jint iterations, jint borderType, jdouble borderValue_val0, jdouble borderValue_val1, jdouble borderValue_val2, jdouble borderValue_val3)
{
    static const char method_name[] = "imgproc::morphologyEx_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& kernel = *((Mat*)kernel_nativeObj);
        Point anchor((int)anchor_x, (int)anchor_y);
        Scalar borderValue(borderValue_val0, borderValue_val1, borderValue_val2, borderValue_val3);
        cv::morphologyEx( src, dst, (int)op, kernel, anchor, (int)iterations, (int)borderType, borderValue );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_morphologyEx_11 (JNIEnv*, jclass, jlong, jlong, jint, jlong, jdouble, jdouble, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_morphologyEx_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint op, jlong kernel_nativeObj, jdouble anchor_x, jdouble anchor_y, jint iterations, jint borderType)
{
    static const char method_name[] = "imgproc::morphologyEx_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& kernel = *((Mat*)kernel_nativeObj);
        Point anchor((int)anchor_x, (int)anchor_y);
        cv::morphologyEx( src, dst, (int)op, kernel, anchor, (int)iterations, (int)borderType );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_morphologyEx_12 (JNIEnv*, jclass, jlong, jlong, jint, jlong, jdouble, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_morphologyEx_12
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint op, jlong kernel_nativeObj, jdouble anchor_x, jdouble anchor_y, jint iterations)
{
    static const char method_name[] = "imgproc::morphologyEx_12()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& kernel = *((Mat*)kernel_nativeObj);
        Point anchor((int)anchor_x, (int)anchor_y);
        cv::morphologyEx( src, dst, (int)op, kernel, anchor, (int)iterations );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_morphologyEx_13 (JNIEnv*, jclass, jlong, jlong, jint, jlong, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_morphologyEx_13
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint op, jlong kernel_nativeObj, jdouble anchor_x, jdouble anchor_y)
{
    static const char method_name[] = "imgproc::morphologyEx_13()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& kernel = *((Mat*)kernel_nativeObj);
        Point anchor((int)anchor_x, (int)anchor_y);
        cv::morphologyEx( src, dst, (int)op, kernel, anchor );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_morphologyEx_14 (JNIEnv*, jclass, jlong, jlong, jint, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_morphologyEx_14
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint op, jlong kernel_nativeObj)
{
    static const char method_name[] = "imgproc::morphologyEx_14()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& kernel = *((Mat*)kernel_nativeObj);
        cv::morphologyEx( src, dst, (int)op, kernel );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::polylines(Mat& img, vector_vector_Point pts, bool isClosed, Scalar color, int thickness = 1, int lineType = LINE_8, int shift = 0)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_polylines_10 (JNIEnv*, jclass, jlong, jlong, jboolean, jdouble, jdouble, jdouble, jdouble, jint, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_polylines_10
  (JNIEnv* env, jclass , jlong img_nativeObj, jlong pts_mat_nativeObj, jboolean isClosed, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3, jint thickness, jint lineType, jint shift)
{
    static const char method_name[] = "imgproc::polylines_10()";
    try {
        LOGD("%s", method_name);
        std::vector< std::vector<Point> > pts;
        Mat& pts_mat = *((Mat*)pts_mat_nativeObj);
        Mat_to_vector_vector_Point( pts_mat, pts );
        Mat& img = *((Mat*)img_nativeObj);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::polylines( img, pts, (bool)isClosed, color, (int)thickness, (int)lineType, (int)shift );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_polylines_11 (JNIEnv*, jclass, jlong, jlong, jboolean, jdouble, jdouble, jdouble, jdouble, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_polylines_11
  (JNIEnv* env, jclass , jlong img_nativeObj, jlong pts_mat_nativeObj, jboolean isClosed, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3, jint thickness, jint lineType)
{
    static const char method_name[] = "imgproc::polylines_11()";
    try {
        LOGD("%s", method_name);
        std::vector< std::vector<Point> > pts;
        Mat& pts_mat = *((Mat*)pts_mat_nativeObj);
        Mat_to_vector_vector_Point( pts_mat, pts );
        Mat& img = *((Mat*)img_nativeObj);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::polylines( img, pts, (bool)isClosed, color, (int)thickness, (int)lineType );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_polylines_12 (JNIEnv*, jclass, jlong, jlong, jboolean, jdouble, jdouble, jdouble, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_polylines_12
  (JNIEnv* env, jclass , jlong img_nativeObj, jlong pts_mat_nativeObj, jboolean isClosed, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3, jint thickness)
{
    static const char method_name[] = "imgproc::polylines_12()";
    try {
        LOGD("%s", method_name);
        std::vector< std::vector<Point> > pts;
        Mat& pts_mat = *((Mat*)pts_mat_nativeObj);
        Mat_to_vector_vector_Point( pts_mat, pts );
        Mat& img = *((Mat*)img_nativeObj);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::polylines( img, pts, (bool)isClosed, color, (int)thickness );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_polylines_13 (JNIEnv*, jclass, jlong, jlong, jboolean, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_polylines_13
  (JNIEnv* env, jclass , jlong img_nativeObj, jlong pts_mat_nativeObj, jboolean isClosed, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3)
{
    static const char method_name[] = "imgproc::polylines_13()";
    try {
        LOGD("%s", method_name);
        std::vector< std::vector<Point> > pts;
        Mat& pts_mat = *((Mat*)pts_mat_nativeObj);
        Mat_to_vector_vector_Point( pts_mat, pts );
        Mat& img = *((Mat*)img_nativeObj);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::polylines( img, pts, (bool)isClosed, color );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::preCornerDetect(Mat src, Mat& dst, int ksize, int borderType = BORDER_DEFAULT)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_preCornerDetect_10 (JNIEnv*, jclass, jlong, jlong, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_preCornerDetect_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint ksize, jint borderType)
{
    static const char method_name[] = "imgproc::preCornerDetect_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::preCornerDetect( src, dst, (int)ksize, (int)borderType );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_preCornerDetect_11 (JNIEnv*, jclass, jlong, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_preCornerDetect_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint ksize)
{
    static const char method_name[] = "imgproc::preCornerDetect_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::preCornerDetect( src, dst, (int)ksize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::putText(Mat& img, String text, Point org, int fontFace, double fontScale, Scalar color, int thickness = 1, int lineType = LINE_8, bool bottomLeftOrigin = false)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_putText_10 (JNIEnv*, jclass, jlong, jstring, jdouble, jdouble, jint, jdouble, jdouble, jdouble, jdouble, jdouble, jint, jint, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_putText_10
  (JNIEnv* env, jclass , jlong img_nativeObj, jstring text, jdouble org_x, jdouble org_y, jint fontFace, jdouble fontScale, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3, jint thickness, jint lineType, jboolean bottomLeftOrigin)
{
    static const char method_name[] = "imgproc::putText_10()";
    try {
        LOGD("%s", method_name);
        Mat& img = *((Mat*)img_nativeObj);
        const char* utf_text = env->GetStringUTFChars(text, 0); String n_text( utf_text ? utf_text : "" ); env->ReleaseStringUTFChars(text, utf_text);
        Point org((int)org_x, (int)org_y);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::putText( img, n_text, org, (int)fontFace, (double)fontScale, color, (int)thickness, (int)lineType, (bool)bottomLeftOrigin );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_putText_11 (JNIEnv*, jclass, jlong, jstring, jdouble, jdouble, jint, jdouble, jdouble, jdouble, jdouble, jdouble, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_putText_11
  (JNIEnv* env, jclass , jlong img_nativeObj, jstring text, jdouble org_x, jdouble org_y, jint fontFace, jdouble fontScale, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3, jint thickness, jint lineType)
{
    static const char method_name[] = "imgproc::putText_11()";
    try {
        LOGD("%s", method_name);
        Mat& img = *((Mat*)img_nativeObj);
        const char* utf_text = env->GetStringUTFChars(text, 0); String n_text( utf_text ? utf_text : "" ); env->ReleaseStringUTFChars(text, utf_text);
        Point org((int)org_x, (int)org_y);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::putText( img, n_text, org, (int)fontFace, (double)fontScale, color, (int)thickness, (int)lineType );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_putText_12 (JNIEnv*, jclass, jlong, jstring, jdouble, jdouble, jint, jdouble, jdouble, jdouble, jdouble, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_putText_12
  (JNIEnv* env, jclass , jlong img_nativeObj, jstring text, jdouble org_x, jdouble org_y, jint fontFace, jdouble fontScale, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3, jint thickness)
{
    static const char method_name[] = "imgproc::putText_12()";
    try {
        LOGD("%s", method_name);
        Mat& img = *((Mat*)img_nativeObj);
        const char* utf_text = env->GetStringUTFChars(text, 0); String n_text( utf_text ? utf_text : "" ); env->ReleaseStringUTFChars(text, utf_text);
        Point org((int)org_x, (int)org_y);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::putText( img, n_text, org, (int)fontFace, (double)fontScale, color, (int)thickness );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_putText_13 (JNIEnv*, jclass, jlong, jstring, jdouble, jdouble, jint, jdouble, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_putText_13
  (JNIEnv* env, jclass , jlong img_nativeObj, jstring text, jdouble org_x, jdouble org_y, jint fontFace, jdouble fontScale, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3)
{
    static const char method_name[] = "imgproc::putText_13()";
    try {
        LOGD("%s", method_name);
        Mat& img = *((Mat*)img_nativeObj);
        const char* utf_text = env->GetStringUTFChars(text, 0); String n_text( utf_text ? utf_text : "" ); env->ReleaseStringUTFChars(text, utf_text);
        Point org((int)org_x, (int)org_y);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::putText( img, n_text, org, (int)fontFace, (double)fontScale, color );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::pyrDown(Mat src, Mat& dst, Size dstsize = Size(), int borderType = BORDER_DEFAULT)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_pyrDown_10 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_pyrDown_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jdouble dstsize_width, jdouble dstsize_height, jint borderType)
{
    static const char method_name[] = "imgproc::pyrDown_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Size dstsize((int)dstsize_width, (int)dstsize_height);
        cv::pyrDown( src, dst, dstsize, (int)borderType );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_pyrDown_11 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_pyrDown_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jdouble dstsize_width, jdouble dstsize_height)
{
    static const char method_name[] = "imgproc::pyrDown_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Size dstsize((int)dstsize_width, (int)dstsize_height);
        cv::pyrDown( src, dst, dstsize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_pyrDown_12 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_pyrDown_12
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "imgproc::pyrDown_12()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::pyrDown( src, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::pyrMeanShiftFiltering(Mat src, Mat& dst, double sp, double sr, int maxLevel = 1, TermCriteria termcrit = TermCriteria(TermCriteria::MAX_ITER+TermCriteria::EPS,5,1))
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_pyrMeanShiftFiltering_10 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jint, jint, jint, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_pyrMeanShiftFiltering_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jdouble sp, jdouble sr, jint maxLevel, jint termcrit_type, jint termcrit_maxCount, jdouble termcrit_epsilon)
{
    static const char method_name[] = "imgproc::pyrMeanShiftFiltering_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        TermCriteria termcrit(termcrit_type, termcrit_maxCount, termcrit_epsilon);
        cv::pyrMeanShiftFiltering( src, dst, (double)sp, (double)sr, (int)maxLevel, termcrit );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_pyrMeanShiftFiltering_11 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_pyrMeanShiftFiltering_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jdouble sp, jdouble sr, jint maxLevel)
{
    static const char method_name[] = "imgproc::pyrMeanShiftFiltering_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::pyrMeanShiftFiltering( src, dst, (double)sp, (double)sr, (int)maxLevel );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_pyrMeanShiftFiltering_12 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_pyrMeanShiftFiltering_12
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jdouble sp, jdouble sr)
{
    static const char method_name[] = "imgproc::pyrMeanShiftFiltering_12()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::pyrMeanShiftFiltering( src, dst, (double)sp, (double)sr );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::pyrUp(Mat src, Mat& dst, Size dstsize = Size(), int borderType = BORDER_DEFAULT)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_pyrUp_10 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_pyrUp_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jdouble dstsize_width, jdouble dstsize_height, jint borderType)
{
    static const char method_name[] = "imgproc::pyrUp_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Size dstsize((int)dstsize_width, (int)dstsize_height);
        cv::pyrUp( src, dst, dstsize, (int)borderType );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_pyrUp_11 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_pyrUp_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jdouble dstsize_width, jdouble dstsize_height)
{
    static const char method_name[] = "imgproc::pyrUp_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Size dstsize((int)dstsize_width, (int)dstsize_height);
        cv::pyrUp( src, dst, dstsize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_pyrUp_12 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_pyrUp_12
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "imgproc::pyrUp_12()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        cv::pyrUp( src, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::rectangle(Mat& img, Point pt1, Point pt2, Scalar color, int thickness = 1, int lineType = LINE_8, int shift = 0)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_rectangle_10 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jint, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_rectangle_10
  (JNIEnv* env, jclass , jlong img_nativeObj, jdouble pt1_x, jdouble pt1_y, jdouble pt2_x, jdouble pt2_y, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3, jint thickness, jint lineType, jint shift)
{
    static const char method_name[] = "imgproc::rectangle_10()";
    try {
        LOGD("%s", method_name);
        Mat& img = *((Mat*)img_nativeObj);
        Point pt1((int)pt1_x, (int)pt1_y);
        Point pt2((int)pt2_x, (int)pt2_y);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::rectangle( img, pt1, pt2, color, (int)thickness, (int)lineType, (int)shift );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_rectangle_11 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_rectangle_11
  (JNIEnv* env, jclass , jlong img_nativeObj, jdouble pt1_x, jdouble pt1_y, jdouble pt2_x, jdouble pt2_y, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3, jint thickness, jint lineType)
{
    static const char method_name[] = "imgproc::rectangle_11()";
    try {
        LOGD("%s", method_name);
        Mat& img = *((Mat*)img_nativeObj);
        Point pt1((int)pt1_x, (int)pt1_y);
        Point pt2((int)pt2_x, (int)pt2_y);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::rectangle( img, pt1, pt2, color, (int)thickness, (int)lineType );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_rectangle_12 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_rectangle_12
  (JNIEnv* env, jclass , jlong img_nativeObj, jdouble pt1_x, jdouble pt1_y, jdouble pt2_x, jdouble pt2_y, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3, jint thickness)
{
    static const char method_name[] = "imgproc::rectangle_12()";
    try {
        LOGD("%s", method_name);
        Mat& img = *((Mat*)img_nativeObj);
        Point pt1((int)pt1_x, (int)pt1_y);
        Point pt2((int)pt2_x, (int)pt2_y);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::rectangle( img, pt1, pt2, color, (int)thickness );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_rectangle_13 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_rectangle_13
  (JNIEnv* env, jclass , jlong img_nativeObj, jdouble pt1_x, jdouble pt1_y, jdouble pt2_x, jdouble pt2_y, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3)
{
    static const char method_name[] = "imgproc::rectangle_13()";
    try {
        LOGD("%s", method_name);
        Mat& img = *((Mat*)img_nativeObj);
        Point pt1((int)pt1_x, (int)pt1_y);
        Point pt2((int)pt2_x, (int)pt2_y);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::rectangle( img, pt1, pt2, color );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::rectangle(Mat& img, Rect rec, Scalar color, int thickness = 1, int lineType = LINE_8, int shift = 0)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_rectangle_14 (JNIEnv*, jclass, jlong, jint, jint, jint, jint, jdouble, jdouble, jdouble, jdouble, jint, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_rectangle_14
  (JNIEnv* env, jclass , jlong img_nativeObj, jint rec_x, jint rec_y, jint rec_width, jint rec_height, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3, jint thickness, jint lineType, jint shift)
{
    static const char method_name[] = "imgproc::rectangle_14()";
    try {
        LOGD("%s", method_name);
        Mat& img = *((Mat*)img_nativeObj);
        Rect rec(rec_x, rec_y, rec_width, rec_height);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::rectangle( img, rec, color, (int)thickness, (int)lineType, (int)shift );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_rectangle_15 (JNIEnv*, jclass, jlong, jint, jint, jint, jint, jdouble, jdouble, jdouble, jdouble, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_rectangle_15
  (JNIEnv* env, jclass , jlong img_nativeObj, jint rec_x, jint rec_y, jint rec_width, jint rec_height, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3, jint thickness, jint lineType)
{
    static const char method_name[] = "imgproc::rectangle_15()";
    try {
        LOGD("%s", method_name);
        Mat& img = *((Mat*)img_nativeObj);
        Rect rec(rec_x, rec_y, rec_width, rec_height);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::rectangle( img, rec, color, (int)thickness, (int)lineType );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_rectangle_16 (JNIEnv*, jclass, jlong, jint, jint, jint, jint, jdouble, jdouble, jdouble, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_rectangle_16
  (JNIEnv* env, jclass , jlong img_nativeObj, jint rec_x, jint rec_y, jint rec_width, jint rec_height, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3, jint thickness)
{
    static const char method_name[] = "imgproc::rectangle_16()";
    try {
        LOGD("%s", method_name);
        Mat& img = *((Mat*)img_nativeObj);
        Rect rec(rec_x, rec_y, rec_width, rec_height);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::rectangle( img, rec, color, (int)thickness );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_rectangle_17 (JNIEnv*, jclass, jlong, jint, jint, jint, jint, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_rectangle_17
  (JNIEnv* env, jclass , jlong img_nativeObj, jint rec_x, jint rec_y, jint rec_width, jint rec_height, jdouble color_val0, jdouble color_val1, jdouble color_val2, jdouble color_val3)
{
    static const char method_name[] = "imgproc::rectangle_17()";
    try {
        LOGD("%s", method_name);
        Mat& img = *((Mat*)img_nativeObj);
        Rect rec(rec_x, rec_y, rec_width, rec_height);
        Scalar color(color_val0, color_val1, color_val2, color_val3);
        cv::rectangle( img, rec, color );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::remap(Mat src, Mat& dst, Mat map1, Mat map2, int interpolation, int borderMode = BORDER_CONSTANT, Scalar borderValue = Scalar())
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_remap_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jint, jint, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_remap_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jlong map1_nativeObj, jlong map2_nativeObj, jint interpolation, jint borderMode, jdouble borderValue_val0, jdouble borderValue_val1, jdouble borderValue_val2, jdouble borderValue_val3)
{
    static const char method_name[] = "imgproc::remap_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& map1 = *((Mat*)map1_nativeObj);
        Mat& map2 = *((Mat*)map2_nativeObj);
        Scalar borderValue(borderValue_val0, borderValue_val1, borderValue_val2, borderValue_val3);
        cv::remap( src, dst, map1, map2, (int)interpolation, (int)borderMode, borderValue );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_remap_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_remap_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jlong map1_nativeObj, jlong map2_nativeObj, jint interpolation, jint borderMode)
{
    static const char method_name[] = "imgproc::remap_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& map1 = *((Mat*)map1_nativeObj);
        Mat& map2 = *((Mat*)map2_nativeObj);
        cv::remap( src, dst, map1, map2, (int)interpolation, (int)borderMode );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_remap_12 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_remap_12
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jlong map1_nativeObj, jlong map2_nativeObj, jint interpolation)
{
    static const char method_name[] = "imgproc::remap_12()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& map1 = *((Mat*)map1_nativeObj);
        Mat& map2 = *((Mat*)map2_nativeObj);
        cv::remap( src, dst, map1, map2, (int)interpolation );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::resize(Mat src, Mat& dst, Size dsize, double fx = 0, double fy = 0, int interpolation = INTER_LINEAR)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_resize_10 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jdouble, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_resize_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jdouble dsize_width, jdouble dsize_height, jdouble fx, jdouble fy, jint interpolation)
{
    static const char method_name[] = "imgproc::resize_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Size dsize((int)dsize_width, (int)dsize_height);
        cv::resize( src, dst, dsize, (double)fx, (double)fy, (int)interpolation );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_resize_11 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_resize_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jdouble dsize_width, jdouble dsize_height, jdouble fx, jdouble fy)
{
    static const char method_name[] = "imgproc::resize_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Size dsize((int)dsize_width, (int)dsize_height);
        cv::resize( src, dst, dsize, (double)fx, (double)fy );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_resize_12 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_resize_12
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jdouble dsize_width, jdouble dsize_height, jdouble fx)
{
    static const char method_name[] = "imgproc::resize_12()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Size dsize((int)dsize_width, (int)dsize_height);
        cv::resize( src, dst, dsize, (double)fx );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_resize_13 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_resize_13
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jdouble dsize_width, jdouble dsize_height)
{
    static const char method_name[] = "imgproc::resize_13()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Size dsize((int)dsize_width, (int)dsize_height);
        cv::resize( src, dst, dsize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::sepFilter2D(Mat src, Mat& dst, int ddepth, Mat kernelX, Mat kernelY, Point anchor = Point(-1,-1), double delta = 0, int borderType = BORDER_DEFAULT)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_sepFilter2D_10 (JNIEnv*, jclass, jlong, jlong, jint, jlong, jlong, jdouble, jdouble, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_sepFilter2D_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint ddepth, jlong kernelX_nativeObj, jlong kernelY_nativeObj, jdouble anchor_x, jdouble anchor_y, jdouble delta, jint borderType)
{
    static const char method_name[] = "imgproc::sepFilter2D_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& kernelX = *((Mat*)kernelX_nativeObj);
        Mat& kernelY = *((Mat*)kernelY_nativeObj);
        Point anchor((int)anchor_x, (int)anchor_y);
        cv::sepFilter2D( src, dst, (int)ddepth, kernelX, kernelY, anchor, (double)delta, (int)borderType );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_sepFilter2D_11 (JNIEnv*, jclass, jlong, jlong, jint, jlong, jlong, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_sepFilter2D_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint ddepth, jlong kernelX_nativeObj, jlong kernelY_nativeObj, jdouble anchor_x, jdouble anchor_y, jdouble delta)
{
    static const char method_name[] = "imgproc::sepFilter2D_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& kernelX = *((Mat*)kernelX_nativeObj);
        Mat& kernelY = *((Mat*)kernelY_nativeObj);
        Point anchor((int)anchor_x, (int)anchor_y);
        cv::sepFilter2D( src, dst, (int)ddepth, kernelX, kernelY, anchor, (double)delta );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_sepFilter2D_12 (JNIEnv*, jclass, jlong, jlong, jint, jlong, jlong, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_sepFilter2D_12
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint ddepth, jlong kernelX_nativeObj, jlong kernelY_nativeObj, jdouble anchor_x, jdouble anchor_y)
{
    static const char method_name[] = "imgproc::sepFilter2D_12()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& kernelX = *((Mat*)kernelX_nativeObj);
        Mat& kernelY = *((Mat*)kernelY_nativeObj);
        Point anchor((int)anchor_x, (int)anchor_y);
        cv::sepFilter2D( src, dst, (int)ddepth, kernelX, kernelY, anchor );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_sepFilter2D_13 (JNIEnv*, jclass, jlong, jlong, jint, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_sepFilter2D_13
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint ddepth, jlong kernelX_nativeObj, jlong kernelY_nativeObj)
{
    static const char method_name[] = "imgproc::sepFilter2D_13()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& kernelX = *((Mat*)kernelX_nativeObj);
        Mat& kernelY = *((Mat*)kernelY_nativeObj);
        cv::sepFilter2D( src, dst, (int)ddepth, kernelX, kernelY );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::spatialGradient(Mat src, Mat& dx, Mat& dy, int ksize = 3, int borderType = BORDER_DEFAULT)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_spatialGradient_10 (JNIEnv*, jclass, jlong, jlong, jlong, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_spatialGradient_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dx_nativeObj, jlong dy_nativeObj, jint ksize, jint borderType)
{
    static const char method_name[] = "imgproc::spatialGradient_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dx = *((Mat*)dx_nativeObj);
        Mat& dy = *((Mat*)dy_nativeObj);
        cv::spatialGradient( src, dx, dy, (int)ksize, (int)borderType );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_spatialGradient_11 (JNIEnv*, jclass, jlong, jlong, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_spatialGradient_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dx_nativeObj, jlong dy_nativeObj, jint ksize)
{
    static const char method_name[] = "imgproc::spatialGradient_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dx = *((Mat*)dx_nativeObj);
        Mat& dy = *((Mat*)dy_nativeObj);
        cv::spatialGradient( src, dx, dy, (int)ksize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_spatialGradient_12 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_spatialGradient_12
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dx_nativeObj, jlong dy_nativeObj)
{
    static const char method_name[] = "imgproc::spatialGradient_12()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dx = *((Mat*)dx_nativeObj);
        Mat& dy = *((Mat*)dy_nativeObj);
        cv::spatialGradient( src, dx, dy );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::sqrBoxFilter(Mat src, Mat& dst, int ddepth, Size ksize, Point anchor = Point(-1, -1), bool normalize = true, int borderType = BORDER_DEFAULT)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_sqrBoxFilter_10 (JNIEnv*, jclass, jlong, jlong, jint, jdouble, jdouble, jdouble, jdouble, jboolean, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_sqrBoxFilter_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint ddepth, jdouble ksize_width, jdouble ksize_height, jdouble anchor_x, jdouble anchor_y, jboolean normalize, jint borderType)
{
    static const char method_name[] = "imgproc::sqrBoxFilter_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Size ksize((int)ksize_width, (int)ksize_height);
        Point anchor((int)anchor_x, (int)anchor_y);
        cv::sqrBoxFilter( src, dst, (int)ddepth, ksize, anchor, (bool)normalize, (int)borderType );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_sqrBoxFilter_11 (JNIEnv*, jclass, jlong, jlong, jint, jdouble, jdouble, jdouble, jdouble, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_sqrBoxFilter_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint ddepth, jdouble ksize_width, jdouble ksize_height, jdouble anchor_x, jdouble anchor_y, jboolean normalize)
{
    static const char method_name[] = "imgproc::sqrBoxFilter_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Size ksize((int)ksize_width, (int)ksize_height);
        Point anchor((int)anchor_x, (int)anchor_y);
        cv::sqrBoxFilter( src, dst, (int)ddepth, ksize, anchor, (bool)normalize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_sqrBoxFilter_12 (JNIEnv*, jclass, jlong, jlong, jint, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_sqrBoxFilter_12
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint ddepth, jdouble ksize_width, jdouble ksize_height, jdouble anchor_x, jdouble anchor_y)
{
    static const char method_name[] = "imgproc::sqrBoxFilter_12()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Size ksize((int)ksize_width, (int)ksize_height);
        Point anchor((int)anchor_x, (int)anchor_y);
        cv::sqrBoxFilter( src, dst, (int)ddepth, ksize, anchor );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_sqrBoxFilter_13 (JNIEnv*, jclass, jlong, jlong, jint, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_sqrBoxFilter_13
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jint ddepth, jdouble ksize_width, jdouble ksize_height)
{
    static const char method_name[] = "imgproc::sqrBoxFilter_13()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Size ksize((int)ksize_width, (int)ksize_height);
        cv::sqrBoxFilter( src, dst, (int)ddepth, ksize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::warpAffine(Mat src, Mat& dst, Mat M, Size dsize, int flags = INTER_LINEAR, int borderMode = BORDER_CONSTANT, Scalar borderValue = Scalar())
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_warpAffine_10 (JNIEnv*, jclass, jlong, jlong, jlong, jdouble, jdouble, jint, jint, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_warpAffine_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jlong M_nativeObj, jdouble dsize_width, jdouble dsize_height, jint flags, jint borderMode, jdouble borderValue_val0, jdouble borderValue_val1, jdouble borderValue_val2, jdouble borderValue_val3)
{
    static const char method_name[] = "imgproc::warpAffine_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& M = *((Mat*)M_nativeObj);
        Size dsize((int)dsize_width, (int)dsize_height);
        Scalar borderValue(borderValue_val0, borderValue_val1, borderValue_val2, borderValue_val3);
        cv::warpAffine( src, dst, M, dsize, (int)flags, (int)borderMode, borderValue );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_warpAffine_11 (JNIEnv*, jclass, jlong, jlong, jlong, jdouble, jdouble, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_warpAffine_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jlong M_nativeObj, jdouble dsize_width, jdouble dsize_height, jint flags, jint borderMode)
{
    static const char method_name[] = "imgproc::warpAffine_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& M = *((Mat*)M_nativeObj);
        Size dsize((int)dsize_width, (int)dsize_height);
        cv::warpAffine( src, dst, M, dsize, (int)flags, (int)borderMode );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_warpAffine_12 (JNIEnv*, jclass, jlong, jlong, jlong, jdouble, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_warpAffine_12
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jlong M_nativeObj, jdouble dsize_width, jdouble dsize_height, jint flags)
{
    static const char method_name[] = "imgproc::warpAffine_12()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& M = *((Mat*)M_nativeObj);
        Size dsize((int)dsize_width, (int)dsize_height);
        cv::warpAffine( src, dst, M, dsize, (int)flags );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_warpAffine_13 (JNIEnv*, jclass, jlong, jlong, jlong, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_warpAffine_13
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jlong M_nativeObj, jdouble dsize_width, jdouble dsize_height)
{
    static const char method_name[] = "imgproc::warpAffine_13()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& M = *((Mat*)M_nativeObj);
        Size dsize((int)dsize_width, (int)dsize_height);
        cv::warpAffine( src, dst, M, dsize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::warpPerspective(Mat src, Mat& dst, Mat M, Size dsize, int flags = INTER_LINEAR, int borderMode = BORDER_CONSTANT, Scalar borderValue = Scalar())
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_warpPerspective_10 (JNIEnv*, jclass, jlong, jlong, jlong, jdouble, jdouble, jint, jint, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_warpPerspective_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jlong M_nativeObj, jdouble dsize_width, jdouble dsize_height, jint flags, jint borderMode, jdouble borderValue_val0, jdouble borderValue_val1, jdouble borderValue_val2, jdouble borderValue_val3)
{
    static const char method_name[] = "imgproc::warpPerspective_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& M = *((Mat*)M_nativeObj);
        Size dsize((int)dsize_width, (int)dsize_height);
        Scalar borderValue(borderValue_val0, borderValue_val1, borderValue_val2, borderValue_val3);
        cv::warpPerspective( src, dst, M, dsize, (int)flags, (int)borderMode, borderValue );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_warpPerspective_11 (JNIEnv*, jclass, jlong, jlong, jlong, jdouble, jdouble, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_warpPerspective_11
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jlong M_nativeObj, jdouble dsize_width, jdouble dsize_height, jint flags, jint borderMode)
{
    static const char method_name[] = "imgproc::warpPerspective_11()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& M = *((Mat*)M_nativeObj);
        Size dsize((int)dsize_width, (int)dsize_height);
        cv::warpPerspective( src, dst, M, dsize, (int)flags, (int)borderMode );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_warpPerspective_12 (JNIEnv*, jclass, jlong, jlong, jlong, jdouble, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_warpPerspective_12
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jlong M_nativeObj, jdouble dsize_width, jdouble dsize_height, jint flags)
{
    static const char method_name[] = "imgproc::warpPerspective_12()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& M = *((Mat*)M_nativeObj);
        Size dsize((int)dsize_width, (int)dsize_height);
        cv::warpPerspective( src, dst, M, dsize, (int)flags );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_warpPerspective_13 (JNIEnv*, jclass, jlong, jlong, jlong, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_warpPerspective_13
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jlong M_nativeObj, jdouble dsize_width, jdouble dsize_height)
{
    static const char method_name[] = "imgproc::warpPerspective_13()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Mat& M = *((Mat*)M_nativeObj);
        Size dsize((int)dsize_width, (int)dsize_height);
        cv::warpPerspective( src, dst, M, dsize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::warpPolar(Mat src, Mat& dst, Size dsize, Point2f center, double maxRadius, int flags)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_warpPolar_10 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_warpPolar_10
  (JNIEnv* env, jclass , jlong src_nativeObj, jlong dst_nativeObj, jdouble dsize_width, jdouble dsize_height, jdouble center_x, jdouble center_y, jdouble maxRadius, jint flags)
{
    static const char method_name[] = "imgproc::warpPolar_10()";
    try {
        LOGD("%s", method_name);
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        Size dsize((int)dsize_width, (int)dsize_height);
        Point2f center((float)center_x, (float)center_y);
        cv::warpPolar( src, dst, dsize, center, (double)maxRadius, (int)flags );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::watershed(Mat image, Mat& markers)
//



JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_watershed_10 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Imgproc_watershed_10
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong markers_nativeObj)
{
    static const char method_name[] = "imgproc::watershed_10()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& markers = *((Mat*)markers_nativeObj);
        cv::watershed( image, markers );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}




    // C++: Size getTextSize(const String& text, int fontFace, double fontScale, int thickness, int* baseLine);
    JNIEXPORT jdoubleArray JNICALL Java_org_opencv_imgproc_Imgproc_n_1getTextSize (JNIEnv*, jclass, jstring, jint, jdouble, jint, jintArray);


    JNIEXPORT jdoubleArray JNICALL Java_org_opencv_imgproc_Imgproc_n_1getTextSize
    (JNIEnv* env, jclass, jstring text, jint fontFace, jdouble fontScale, jint thickness, jintArray baseLine)
    {
    try {
        LOGD("Core::n_1getTextSize()");
        jdoubleArray result;
        result = env->NewDoubleArray(2);
        if (result == NULL) {
            return NULL; /* out of memory error thrown */
        }


        const char* utf_text = env->GetStringUTFChars(text, 0);
        String n_text( utf_text ? utf_text : "" );
        env->ReleaseStringUTFChars(text, utf_text);


        int _baseLine;
        int* pbaseLine = 0;


        if (baseLine != NULL)
            pbaseLine = &_baseLine;


        cv::Size rsize = cv::getTextSize(n_text, (int)fontFace, (double)fontScale, (int)thickness, pbaseLine);


        jdouble fill[2];
        fill[0]=rsize.width;
        fill[1]=rsize.height;


        env->SetDoubleArrayRegion(result, 0, 2, fill);


        if (baseLine != NULL) {
            jint jbaseLine = (jint)(*pbaseLine);
            env->SetIntArrayRegion(baseLine, 0, 1, &jbaseLine);
        }


        return result;


    } catch(const cv::Exception& e) {
        LOGD("Imgproc::n_1getTextSize() caught cv::Exception: %s", e.what());
        jclass je = env->FindClass("org/opencv/core/CvException");
        if(!je) je = env->FindClass("java/lang/Exception");
        env->ThrowNew(je, e.what());
        return NULL;
    } catch (...) {
        LOGD("Imgproc::n_1getTextSize() caught unknown exception (...)");
        jclass je = env->FindClass("java/lang/Exception");
        env->ThrowNew(je, "Unknown exception in JNI code {core::getTextSize()}");
        return NULL;
    }
    }
//
//  Size cv::CLAHE::getTilesGridSize()
//

using namespace cv;

JNIEXPORT jdoubleArray JNICALL Java_org_opencv_imgproc_CLAHE_getTilesGridSize_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jdoubleArray JNICALL Java_org_opencv_imgproc_CLAHE_getTilesGridSize_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "imgproc::getTilesGridSize_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::CLAHE>* me = (Ptr<cv::CLAHE>*) self; //TODO: check for NULL
        Size _retval_ = (*me)->getTilesGridSize();
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
//  double cv::CLAHE::getClipLimit()
//

using namespace cv;

JNIEXPORT jdouble JNICALL Java_org_opencv_imgproc_CLAHE_getClipLimit_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_imgproc_CLAHE_getClipLimit_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "imgproc::getClipLimit_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::CLAHE>* me = (Ptr<cv::CLAHE>*) self; //TODO: check for NULL
        return (*me)->getClipLimit();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::CLAHE::apply(Mat src, Mat& dst)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_imgproc_CLAHE_apply_10 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_CLAHE_apply_10
  (JNIEnv* env, jclass , jlong self, jlong src_nativeObj, jlong dst_nativeObj)
{
    static const char method_name[] = "imgproc::apply_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::CLAHE>* me = (Ptr<cv::CLAHE>*) self; //TODO: check for NULL
        Mat& src = *((Mat*)src_nativeObj);
        Mat& dst = *((Mat*)dst_nativeObj);
        (*me)->apply( src, dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::CLAHE::collectGarbage()
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_imgproc_CLAHE_collectGarbage_10 (JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_CLAHE_collectGarbage_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "imgproc::collectGarbage_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::CLAHE>* me = (Ptr<cv::CLAHE>*) self; //TODO: check for NULL
        (*me)->collectGarbage();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::CLAHE::setClipLimit(double clipLimit)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_imgproc_CLAHE_setClipLimit_10 (JNIEnv*, jclass, jlong, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_CLAHE_setClipLimit_10
  (JNIEnv* env, jclass , jlong self, jdouble clipLimit)
{
    static const char method_name[] = "imgproc::setClipLimit_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::CLAHE>* me = (Ptr<cv::CLAHE>*) self; //TODO: check for NULL
        (*me)->setClipLimit( (double)clipLimit );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::CLAHE::setTilesGridSize(Size tileGridSize)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_imgproc_CLAHE_setTilesGridSize_10 (JNIEnv*, jclass, jlong, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_CLAHE_setTilesGridSize_10
  (JNIEnv* env, jclass , jlong self, jdouble tileGridSize_width, jdouble tileGridSize_height)
{
    static const char method_name[] = "imgproc::setTilesGridSize_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::CLAHE>* me = (Ptr<cv::CLAHE>*) self; //TODO: check for NULL
        Size tileGridSize((int)tileGridSize_width, (int)tileGridSize_height);
        (*me)->setTilesGridSize( tileGridSize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void Ptr<cv::CLAHE>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_imgproc_CLAHE_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_CLAHE_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::CLAHE>*) self;
}


//
//   cv::Subdiv2D::Subdiv2D(Rect rect)
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Subdiv2D_Subdiv2D_10 (JNIEnv*, jclass, jint, jint, jint, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Subdiv2D_Subdiv2D_10
  (JNIEnv* env, jclass , jint rect_x, jint rect_y, jint rect_width, jint rect_height)
{
    static const char method_name[] = "imgproc::Subdiv2D_10()";
    try {
        LOGD("%s", method_name);
        Rect rect(rect_x, rect_y, rect_width, rect_height);
        cv::Subdiv2D* _retval_ = new cv::Subdiv2D( rect );
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//   cv::Subdiv2D::Subdiv2D()
//

using namespace cv;

JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Subdiv2D_Subdiv2D_11 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_imgproc_Subdiv2D_Subdiv2D_11
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "imgproc::Subdiv2D_11()";
    try {
        LOGD("%s", method_name);
        cv::Subdiv2D* _retval_ = new cv::Subdiv2D();
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Point2f cv::Subdiv2D::getVertex(int vertex, int* firstEdge = 0)
//

using namespace cv;

JNIEXPORT jdoubleArray JNICALL Java_org_opencv_imgproc_Subdiv2D_getVertex_10 (JNIEnv*, jclass, jlong, jint, jdoubleArray);

JNIEXPORT jdoubleArray JNICALL Java_org_opencv_imgproc_Subdiv2D_getVertex_10
  (JNIEnv* env, jclass , jlong self, jint vertex, jdoubleArray firstEdge_out)
{
    static const char method_name[] = "imgproc::getVertex_10()";
    try {
        LOGD("%s", method_name);
        cv::Subdiv2D* me = (cv::Subdiv2D*) self; //TODO: check for NULL
        int firstEdge;
        Point2f _retval_ = me->getVertex( (int)vertex, &firstEdge );
        jdoubleArray _da_retval_ = env->NewDoubleArray(2);  jdouble _tmp_retval_[2] = {(jdouble)_retval_.x, (jdouble)_retval_.y}; env->SetDoubleArrayRegion(_da_retval_, 0, 2, _tmp_retval_);
        jdouble tmp_firstEdge[1] = {(jdouble)firstEdge}; env->SetDoubleArrayRegion(firstEdge_out, 0, 1, tmp_firstEdge);
        return _da_retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jdoubleArray JNICALL Java_org_opencv_imgproc_Subdiv2D_getVertex_11 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT jdoubleArray JNICALL Java_org_opencv_imgproc_Subdiv2D_getVertex_11
  (JNIEnv* env, jclass , jlong self, jint vertex)
{
    static const char method_name[] = "imgproc::getVertex_11()";
    try {
        LOGD("%s", method_name);
        cv::Subdiv2D* me = (cv::Subdiv2D*) self; //TODO: check for NULL
        Point2f _retval_ = me->getVertex( (int)vertex );
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
//  int cv::Subdiv2D::edgeDst(int edge, Point2f* dstpt = 0)
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Subdiv2D_edgeDst_10 (JNIEnv*, jclass, jlong, jint, jdoubleArray);

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Subdiv2D_edgeDst_10
  (JNIEnv* env, jclass , jlong self, jint edge, jdoubleArray dstpt_out)
{
    static const char method_name[] = "imgproc::edgeDst_10()";
    try {
        LOGD("%s", method_name);
        cv::Subdiv2D* me = (cv::Subdiv2D*) self; //TODO: check for NULL
        Point2f dstpt;
        int _retval_ = me->edgeDst( (int)edge, &dstpt );
        jdouble tmp_dstpt[2] = {(jdouble)dstpt.x, (jdouble)dstpt.y}; env->SetDoubleArrayRegion(dstpt_out, 0, 2, tmp_dstpt);
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Subdiv2D_edgeDst_11 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Subdiv2D_edgeDst_11
  (JNIEnv* env, jclass , jlong self, jint edge)
{
    static const char method_name[] = "imgproc::edgeDst_11()";
    try {
        LOGD("%s", method_name);
        cv::Subdiv2D* me = (cv::Subdiv2D*) self; //TODO: check for NULL
        return me->edgeDst( (int)edge );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::Subdiv2D::edgeOrg(int edge, Point2f* orgpt = 0)
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Subdiv2D_edgeOrg_10 (JNIEnv*, jclass, jlong, jint, jdoubleArray);

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Subdiv2D_edgeOrg_10
  (JNIEnv* env, jclass , jlong self, jint edge, jdoubleArray orgpt_out)
{
    static const char method_name[] = "imgproc::edgeOrg_10()";
    try {
        LOGD("%s", method_name);
        cv::Subdiv2D* me = (cv::Subdiv2D*) self; //TODO: check for NULL
        Point2f orgpt;
        int _retval_ = me->edgeOrg( (int)edge, &orgpt );
        jdouble tmp_orgpt[2] = {(jdouble)orgpt.x, (jdouble)orgpt.y}; env->SetDoubleArrayRegion(orgpt_out, 0, 2, tmp_orgpt);
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Subdiv2D_edgeOrg_11 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Subdiv2D_edgeOrg_11
  (JNIEnv* env, jclass , jlong self, jint edge)
{
    static const char method_name[] = "imgproc::edgeOrg_11()";
    try {
        LOGD("%s", method_name);
        cv::Subdiv2D* me = (cv::Subdiv2D*) self; //TODO: check for NULL
        return me->edgeOrg( (int)edge );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::Subdiv2D::findNearest(Point2f pt, Point2f* nearestPt = 0)
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Subdiv2D_findNearest_10 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdoubleArray);

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Subdiv2D_findNearest_10
  (JNIEnv* env, jclass , jlong self, jdouble pt_x, jdouble pt_y, jdoubleArray nearestPt_out)
{
    static const char method_name[] = "imgproc::findNearest_10()";
    try {
        LOGD("%s", method_name);
        cv::Subdiv2D* me = (cv::Subdiv2D*) self; //TODO: check for NULL
        Point2f pt((float)pt_x, (float)pt_y);
        Point2f nearestPt;
        int _retval_ = me->findNearest( pt, &nearestPt );
        jdouble tmp_nearestPt[2] = {(jdouble)nearestPt.x, (jdouble)nearestPt.y}; env->SetDoubleArrayRegion(nearestPt_out, 0, 2, tmp_nearestPt);
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Subdiv2D_findNearest_11 (JNIEnv*, jclass, jlong, jdouble, jdouble);

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Subdiv2D_findNearest_11
  (JNIEnv* env, jclass , jlong self, jdouble pt_x, jdouble pt_y)
{
    static const char method_name[] = "imgproc::findNearest_11()";
    try {
        LOGD("%s", method_name);
        cv::Subdiv2D* me = (cv::Subdiv2D*) self; //TODO: check for NULL
        Point2f pt((float)pt_x, (float)pt_y);
        return me->findNearest( pt );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::Subdiv2D::getEdge(int edge, int nextEdgeType)
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Subdiv2D_getEdge_10 (JNIEnv*, jclass, jlong, jint, jint);

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Subdiv2D_getEdge_10
  (JNIEnv* env, jclass , jlong self, jint edge, jint nextEdgeType)
{
    static const char method_name[] = "imgproc::getEdge_10()";
    try {
        LOGD("%s", method_name);
        cv::Subdiv2D* me = (cv::Subdiv2D*) self; //TODO: check for NULL
        return me->getEdge( (int)edge, (int)nextEdgeType );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::Subdiv2D::insert(Point2f pt)
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Subdiv2D_insert_10 (JNIEnv*, jclass, jlong, jdouble, jdouble);

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Subdiv2D_insert_10
  (JNIEnv* env, jclass , jlong self, jdouble pt_x, jdouble pt_y)
{
    static const char method_name[] = "imgproc::insert_10()";
    try {
        LOGD("%s", method_name);
        cv::Subdiv2D* me = (cv::Subdiv2D*) self; //TODO: check for NULL
        Point2f pt((float)pt_x, (float)pt_y);
        return me->insert( pt );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::Subdiv2D::locate(Point2f pt, int& edge, int& vertex)
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Subdiv2D_locate_10 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdoubleArray, jdoubleArray);

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Subdiv2D_locate_10
  (JNIEnv* env, jclass , jlong self, jdouble pt_x, jdouble pt_y, jdoubleArray edge_out, jdoubleArray vertex_out)
{
    static const char method_name[] = "imgproc::locate_10()";
    try {
        LOGD("%s", method_name);
        cv::Subdiv2D* me = (cv::Subdiv2D*) self; //TODO: check for NULL
        Point2f pt((float)pt_x, (float)pt_y);
        int edge;
        int vertex;
        int _retval_ = me->locate( pt, edge, vertex );
        jdouble tmp_edge[1] = {(jdouble)edge}; env->SetDoubleArrayRegion(edge_out, 0, 1, tmp_edge);
        jdouble tmp_vertex[1] = {(jdouble)vertex}; env->SetDoubleArrayRegion(vertex_out, 0, 1, tmp_vertex);
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::Subdiv2D::nextEdge(int edge)
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Subdiv2D_nextEdge_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Subdiv2D_nextEdge_10
  (JNIEnv* env, jclass , jlong self, jint edge)
{
    static const char method_name[] = "imgproc::nextEdge_10()";
    try {
        LOGD("%s", method_name);
        cv::Subdiv2D* me = (cv::Subdiv2D*) self; //TODO: check for NULL
        return me->nextEdge( (int)edge );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::Subdiv2D::rotateEdge(int edge, int rotate)
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Subdiv2D_rotateEdge_10 (JNIEnv*, jclass, jlong, jint, jint);

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Subdiv2D_rotateEdge_10
  (JNIEnv* env, jclass , jlong self, jint edge, jint rotate)
{
    static const char method_name[] = "imgproc::rotateEdge_10()";
    try {
        LOGD("%s", method_name);
        cv::Subdiv2D* me = (cv::Subdiv2D*) self; //TODO: check for NULL
        return me->rotateEdge( (int)edge, (int)rotate );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::Subdiv2D::symEdge(int edge)
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Subdiv2D_symEdge_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_Subdiv2D_symEdge_10
  (JNIEnv* env, jclass , jlong self, jint edge)
{
    static const char method_name[] = "imgproc::symEdge_10()";
    try {
        LOGD("%s", method_name);
        cv::Subdiv2D* me = (cv::Subdiv2D*) self; //TODO: check for NULL
        return me->symEdge( (int)edge );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::Subdiv2D::getEdgeList(vector_Vec4f& edgeList)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Subdiv2D_getEdgeList_10 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Subdiv2D_getEdgeList_10
  (JNIEnv* env, jclass , jlong self, jlong edgeList_mat_nativeObj)
{
    static const char method_name[] = "imgproc::getEdgeList_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Vec4f> edgeList;
        Mat& edgeList_mat = *((Mat*)edgeList_mat_nativeObj);
        cv::Subdiv2D* me = (cv::Subdiv2D*) self; //TODO: check for NULL
        me->getEdgeList( edgeList );
        vector_Vec4f_to_Mat( edgeList, edgeList_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::Subdiv2D::getLeadingEdgeList(vector_int& leadingEdgeList)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Subdiv2D_getLeadingEdgeList_10 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Subdiv2D_getLeadingEdgeList_10
  (JNIEnv* env, jclass , jlong self, jlong leadingEdgeList_mat_nativeObj)
{
    static const char method_name[] = "imgproc::getLeadingEdgeList_10()";
    try {
        LOGD("%s", method_name);
        std::vector<int> leadingEdgeList;
        Mat& leadingEdgeList_mat = *((Mat*)leadingEdgeList_mat_nativeObj);
        cv::Subdiv2D* me = (cv::Subdiv2D*) self; //TODO: check for NULL
        me->getLeadingEdgeList( leadingEdgeList );
        vector_int_to_Mat( leadingEdgeList, leadingEdgeList_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::Subdiv2D::getTriangleList(vector_Vec6f& triangleList)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Subdiv2D_getTriangleList_10 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Subdiv2D_getTriangleList_10
  (JNIEnv* env, jclass , jlong self, jlong triangleList_mat_nativeObj)
{
    static const char method_name[] = "imgproc::getTriangleList_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Vec6f> triangleList;
        Mat& triangleList_mat = *((Mat*)triangleList_mat_nativeObj);
        cv::Subdiv2D* me = (cv::Subdiv2D*) self; //TODO: check for NULL
        me->getTriangleList( triangleList );
        vector_Vec6f_to_Mat( triangleList, triangleList_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::Subdiv2D::getVoronoiFacetList(vector_int idx, vector_vector_Point2f& facetList, vector_Point2f& facetCenters)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Subdiv2D_getVoronoiFacetList_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Subdiv2D_getVoronoiFacetList_10
  (JNIEnv* env, jclass , jlong self, jlong idx_mat_nativeObj, jlong facetList_mat_nativeObj, jlong facetCenters_mat_nativeObj)
{
    static const char method_name[] = "imgproc::getVoronoiFacetList_10()";
    try {
        LOGD("%s", method_name);
        std::vector<int> idx;
        Mat& idx_mat = *((Mat*)idx_mat_nativeObj);
        Mat_to_vector_int( idx_mat, idx );
        std::vector< std::vector<Point2f> > facetList;
        Mat& facetList_mat = *((Mat*)facetList_mat_nativeObj);
        std::vector<Point2f> facetCenters;
        Mat& facetCenters_mat = *((Mat*)facetCenters_mat_nativeObj);
        cv::Subdiv2D* me = (cv::Subdiv2D*) self; //TODO: check for NULL
        me->getVoronoiFacetList( idx, facetList, facetCenters );
        vector_vector_Point2f_to_Mat( facetList, facetList_mat );
        vector_Point2f_to_Mat( facetCenters, facetCenters_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::Subdiv2D::initDelaunay(Rect rect)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Subdiv2D_initDelaunay_10 (JNIEnv*, jclass, jlong, jint, jint, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Subdiv2D_initDelaunay_10
  (JNIEnv* env, jclass , jlong self, jint rect_x, jint rect_y, jint rect_width, jint rect_height)
{
    static const char method_name[] = "imgproc::initDelaunay_10()";
    try {
        LOGD("%s", method_name);
        cv::Subdiv2D* me = (cv::Subdiv2D*) self; //TODO: check for NULL
        Rect rect(rect_x, rect_y, rect_width, rect_height);
        me->initDelaunay( rect );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::Subdiv2D::insert(vector_Point2f ptvec)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Subdiv2D_insert_11 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Subdiv2D_insert_11
  (JNIEnv* env, jclass , jlong self, jlong ptvec_mat_nativeObj)
{
    static const char method_name[] = "imgproc::insert_11()";
    try {
        LOGD("%s", method_name);
        std::vector<Point2f> ptvec;
        Mat& ptvec_mat = *((Mat*)ptvec_mat_nativeObj);
        Mat_to_vector_Point2f( ptvec_mat, ptvec );
        cv::Subdiv2D* me = (cv::Subdiv2D*) self; //TODO: check for NULL
        me->insert( ptvec );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void cv::Subdiv2D::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_imgproc_Subdiv2D_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_Subdiv2D_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (cv::Subdiv2D*) self;
}


//
//  int cv::GeneralizedHoughBallard::getLevels()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_GeneralizedHoughBallard_getLevels_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_GeneralizedHoughBallard_getLevels_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "imgproc::getLevels_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GeneralizedHoughBallard>* me = (Ptr<cv::GeneralizedHoughBallard>*) self; //TODO: check for NULL
        return (*me)->getLevels();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::GeneralizedHoughBallard::getVotesThreshold()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_GeneralizedHoughBallard_getVotesThreshold_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_GeneralizedHoughBallard_getVotesThreshold_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "imgproc::getVotesThreshold_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GeneralizedHoughBallard>* me = (Ptr<cv::GeneralizedHoughBallard>*) self; //TODO: check for NULL
        return (*me)->getVotesThreshold();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::GeneralizedHoughBallard::setLevels(int levels)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHoughBallard_setLevels_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHoughBallard_setLevels_10
  (JNIEnv* env, jclass , jlong self, jint levels)
{
    static const char method_name[] = "imgproc::setLevels_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GeneralizedHoughBallard>* me = (Ptr<cv::GeneralizedHoughBallard>*) self; //TODO: check for NULL
        (*me)->setLevels( (int)levels );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::GeneralizedHoughBallard::setVotesThreshold(int votesThreshold)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHoughBallard_setVotesThreshold_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHoughBallard_setVotesThreshold_10
  (JNIEnv* env, jclass , jlong self, jint votesThreshold)
{
    static const char method_name[] = "imgproc::setVotesThreshold_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GeneralizedHoughBallard>* me = (Ptr<cv::GeneralizedHoughBallard>*) self; //TODO: check for NULL
        (*me)->setVotesThreshold( (int)votesThreshold );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void Ptr<cv::GeneralizedHoughBallard>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHoughBallard_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHoughBallard_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::GeneralizedHoughBallard>*) self;
}


//
//  double cv::GeneralizedHough::getDp()
//

using namespace cv;

JNIEXPORT jdouble JNICALL Java_org_opencv_imgproc_GeneralizedHough_getDp_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_imgproc_GeneralizedHough_getDp_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "imgproc::getDp_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GeneralizedHough>* me = (Ptr<cv::GeneralizedHough>*) self; //TODO: check for NULL
        return (*me)->getDp();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::GeneralizedHough::getMinDist()
//

using namespace cv;

JNIEXPORT jdouble JNICALL Java_org_opencv_imgproc_GeneralizedHough_getMinDist_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_imgproc_GeneralizedHough_getMinDist_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "imgproc::getMinDist_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GeneralizedHough>* me = (Ptr<cv::GeneralizedHough>*) self; //TODO: check for NULL
        return (*me)->getMinDist();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::GeneralizedHough::getCannyHighThresh()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_GeneralizedHough_getCannyHighThresh_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_GeneralizedHough_getCannyHighThresh_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "imgproc::getCannyHighThresh_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GeneralizedHough>* me = (Ptr<cv::GeneralizedHough>*) self; //TODO: check for NULL
        return (*me)->getCannyHighThresh();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::GeneralizedHough::getCannyLowThresh()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_GeneralizedHough_getCannyLowThresh_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_GeneralizedHough_getCannyLowThresh_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "imgproc::getCannyLowThresh_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GeneralizedHough>* me = (Ptr<cv::GeneralizedHough>*) self; //TODO: check for NULL
        return (*me)->getCannyLowThresh();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::GeneralizedHough::getMaxBufferSize()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_GeneralizedHough_getMaxBufferSize_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_GeneralizedHough_getMaxBufferSize_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "imgproc::getMaxBufferSize_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GeneralizedHough>* me = (Ptr<cv::GeneralizedHough>*) self; //TODO: check for NULL
        return (*me)->getMaxBufferSize();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::GeneralizedHough::detect(Mat edges, Mat dx, Mat dy, Mat& positions, Mat& votes = Mat())
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHough_detect_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHough_detect_10
  (JNIEnv* env, jclass , jlong self, jlong edges_nativeObj, jlong dx_nativeObj, jlong dy_nativeObj, jlong positions_nativeObj, jlong votes_nativeObj)
{
    static const char method_name[] = "imgproc::detect_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GeneralizedHough>* me = (Ptr<cv::GeneralizedHough>*) self; //TODO: check for NULL
        Mat& edges = *((Mat*)edges_nativeObj);
        Mat& dx = *((Mat*)dx_nativeObj);
        Mat& dy = *((Mat*)dy_nativeObj);
        Mat& positions = *((Mat*)positions_nativeObj);
        Mat& votes = *((Mat*)votes_nativeObj);
        (*me)->detect( edges, dx, dy, positions, votes );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHough_detect_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHough_detect_11
  (JNIEnv* env, jclass , jlong self, jlong edges_nativeObj, jlong dx_nativeObj, jlong dy_nativeObj, jlong positions_nativeObj)
{
    static const char method_name[] = "imgproc::detect_11()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GeneralizedHough>* me = (Ptr<cv::GeneralizedHough>*) self; //TODO: check for NULL
        Mat& edges = *((Mat*)edges_nativeObj);
        Mat& dx = *((Mat*)dx_nativeObj);
        Mat& dy = *((Mat*)dy_nativeObj);
        Mat& positions = *((Mat*)positions_nativeObj);
        (*me)->detect( edges, dx, dy, positions );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::GeneralizedHough::detect(Mat image, Mat& positions, Mat& votes = Mat())
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHough_detect_12 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHough_detect_12
  (JNIEnv* env, jclass , jlong self, jlong image_nativeObj, jlong positions_nativeObj, jlong votes_nativeObj)
{
    static const char method_name[] = "imgproc::detect_12()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GeneralizedHough>* me = (Ptr<cv::GeneralizedHough>*) self; //TODO: check for NULL
        Mat& image = *((Mat*)image_nativeObj);
        Mat& positions = *((Mat*)positions_nativeObj);
        Mat& votes = *((Mat*)votes_nativeObj);
        (*me)->detect( image, positions, votes );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHough_detect_13 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHough_detect_13
  (JNIEnv* env, jclass , jlong self, jlong image_nativeObj, jlong positions_nativeObj)
{
    static const char method_name[] = "imgproc::detect_13()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GeneralizedHough>* me = (Ptr<cv::GeneralizedHough>*) self; //TODO: check for NULL
        Mat& image = *((Mat*)image_nativeObj);
        Mat& positions = *((Mat*)positions_nativeObj);
        (*me)->detect( image, positions );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::GeneralizedHough::setCannyHighThresh(int cannyHighThresh)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHough_setCannyHighThresh_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHough_setCannyHighThresh_10
  (JNIEnv* env, jclass , jlong self, jint cannyHighThresh)
{
    static const char method_name[] = "imgproc::setCannyHighThresh_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GeneralizedHough>* me = (Ptr<cv::GeneralizedHough>*) self; //TODO: check for NULL
        (*me)->setCannyHighThresh( (int)cannyHighThresh );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::GeneralizedHough::setCannyLowThresh(int cannyLowThresh)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHough_setCannyLowThresh_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHough_setCannyLowThresh_10
  (JNIEnv* env, jclass , jlong self, jint cannyLowThresh)
{
    static const char method_name[] = "imgproc::setCannyLowThresh_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GeneralizedHough>* me = (Ptr<cv::GeneralizedHough>*) self; //TODO: check for NULL
        (*me)->setCannyLowThresh( (int)cannyLowThresh );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::GeneralizedHough::setDp(double dp)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHough_setDp_10 (JNIEnv*, jclass, jlong, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHough_setDp_10
  (JNIEnv* env, jclass , jlong self, jdouble dp)
{
    static const char method_name[] = "imgproc::setDp_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GeneralizedHough>* me = (Ptr<cv::GeneralizedHough>*) self; //TODO: check for NULL
        (*me)->setDp( (double)dp );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::GeneralizedHough::setMaxBufferSize(int maxBufferSize)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHough_setMaxBufferSize_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHough_setMaxBufferSize_10
  (JNIEnv* env, jclass , jlong self, jint maxBufferSize)
{
    static const char method_name[] = "imgproc::setMaxBufferSize_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GeneralizedHough>* me = (Ptr<cv::GeneralizedHough>*) self; //TODO: check for NULL
        (*me)->setMaxBufferSize( (int)maxBufferSize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::GeneralizedHough::setMinDist(double minDist)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHough_setMinDist_10 (JNIEnv*, jclass, jlong, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHough_setMinDist_10
  (JNIEnv* env, jclass , jlong self, jdouble minDist)
{
    static const char method_name[] = "imgproc::setMinDist_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GeneralizedHough>* me = (Ptr<cv::GeneralizedHough>*) self; //TODO: check for NULL
        (*me)->setMinDist( (double)minDist );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::GeneralizedHough::setTemplate(Mat edges, Mat dx, Mat dy, Point templCenter = Point(-1, -1))
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHough_setTemplate_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHough_setTemplate_10
  (JNIEnv* env, jclass , jlong self, jlong edges_nativeObj, jlong dx_nativeObj, jlong dy_nativeObj, jdouble templCenter_x, jdouble templCenter_y)
{
    static const char method_name[] = "imgproc::setTemplate_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GeneralizedHough>* me = (Ptr<cv::GeneralizedHough>*) self; //TODO: check for NULL
        Mat& edges = *((Mat*)edges_nativeObj);
        Mat& dx = *((Mat*)dx_nativeObj);
        Mat& dy = *((Mat*)dy_nativeObj);
        Point templCenter((int)templCenter_x, (int)templCenter_y);
        (*me)->setTemplate( edges, dx, dy, templCenter );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHough_setTemplate_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHough_setTemplate_11
  (JNIEnv* env, jclass , jlong self, jlong edges_nativeObj, jlong dx_nativeObj, jlong dy_nativeObj)
{
    static const char method_name[] = "imgproc::setTemplate_11()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GeneralizedHough>* me = (Ptr<cv::GeneralizedHough>*) self; //TODO: check for NULL
        Mat& edges = *((Mat*)edges_nativeObj);
        Mat& dx = *((Mat*)dx_nativeObj);
        Mat& dy = *((Mat*)dy_nativeObj);
        (*me)->setTemplate( edges, dx, dy );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::GeneralizedHough::setTemplate(Mat templ, Point templCenter = Point(-1, -1))
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHough_setTemplate_12 (JNIEnv*, jclass, jlong, jlong, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHough_setTemplate_12
  (JNIEnv* env, jclass , jlong self, jlong templ_nativeObj, jdouble templCenter_x, jdouble templCenter_y)
{
    static const char method_name[] = "imgproc::setTemplate_12()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GeneralizedHough>* me = (Ptr<cv::GeneralizedHough>*) self; //TODO: check for NULL
        Mat& templ = *((Mat*)templ_nativeObj);
        Point templCenter((int)templCenter_x, (int)templCenter_y);
        (*me)->setTemplate( templ, templCenter );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHough_setTemplate_13 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHough_setTemplate_13
  (JNIEnv* env, jclass , jlong self, jlong templ_nativeObj)
{
    static const char method_name[] = "imgproc::setTemplate_13()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GeneralizedHough>* me = (Ptr<cv::GeneralizedHough>*) self; //TODO: check for NULL
        Mat& templ = *((Mat*)templ_nativeObj);
        (*me)->setTemplate( templ );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void Ptr<cv::GeneralizedHough>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHough_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHough_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::GeneralizedHough>*) self;
}


//
//  double cv::GeneralizedHoughGuil::getAngleEpsilon()
//

using namespace cv;

JNIEXPORT jdouble JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_getAngleEpsilon_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_getAngleEpsilon_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "imgproc::getAngleEpsilon_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GeneralizedHoughGuil>* me = (Ptr<cv::GeneralizedHoughGuil>*) self; //TODO: check for NULL
        return (*me)->getAngleEpsilon();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::GeneralizedHoughGuil::getAngleStep()
//

using namespace cv;

JNIEXPORT jdouble JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_getAngleStep_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_getAngleStep_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "imgproc::getAngleStep_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GeneralizedHoughGuil>* me = (Ptr<cv::GeneralizedHoughGuil>*) self; //TODO: check for NULL
        return (*me)->getAngleStep();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::GeneralizedHoughGuil::getMaxAngle()
//

using namespace cv;

JNIEXPORT jdouble JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_getMaxAngle_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_getMaxAngle_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "imgproc::getMaxAngle_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GeneralizedHoughGuil>* me = (Ptr<cv::GeneralizedHoughGuil>*) self; //TODO: check for NULL
        return (*me)->getMaxAngle();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::GeneralizedHoughGuil::getMaxScale()
//

using namespace cv;

JNIEXPORT jdouble JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_getMaxScale_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_getMaxScale_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "imgproc::getMaxScale_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GeneralizedHoughGuil>* me = (Ptr<cv::GeneralizedHoughGuil>*) self; //TODO: check for NULL
        return (*me)->getMaxScale();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::GeneralizedHoughGuil::getMinAngle()
//

using namespace cv;

JNIEXPORT jdouble JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_getMinAngle_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_getMinAngle_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "imgproc::getMinAngle_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GeneralizedHoughGuil>* me = (Ptr<cv::GeneralizedHoughGuil>*) self; //TODO: check for NULL
        return (*me)->getMinAngle();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::GeneralizedHoughGuil::getMinScale()
//

using namespace cv;

JNIEXPORT jdouble JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_getMinScale_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_getMinScale_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "imgproc::getMinScale_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GeneralizedHoughGuil>* me = (Ptr<cv::GeneralizedHoughGuil>*) self; //TODO: check for NULL
        return (*me)->getMinScale();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::GeneralizedHoughGuil::getScaleStep()
//

using namespace cv;

JNIEXPORT jdouble JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_getScaleStep_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_getScaleStep_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "imgproc::getScaleStep_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GeneralizedHoughGuil>* me = (Ptr<cv::GeneralizedHoughGuil>*) self; //TODO: check for NULL
        return (*me)->getScaleStep();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::GeneralizedHoughGuil::getXi()
//

using namespace cv;

JNIEXPORT jdouble JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_getXi_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_getXi_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "imgproc::getXi_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GeneralizedHoughGuil>* me = (Ptr<cv::GeneralizedHoughGuil>*) self; //TODO: check for NULL
        return (*me)->getXi();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::GeneralizedHoughGuil::getAngleThresh()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_getAngleThresh_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_getAngleThresh_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "imgproc::getAngleThresh_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GeneralizedHoughGuil>* me = (Ptr<cv::GeneralizedHoughGuil>*) self; //TODO: check for NULL
        return (*me)->getAngleThresh();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::GeneralizedHoughGuil::getLevels()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_getLevels_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_getLevels_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "imgproc::getLevels_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GeneralizedHoughGuil>* me = (Ptr<cv::GeneralizedHoughGuil>*) self; //TODO: check for NULL
        return (*me)->getLevels();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::GeneralizedHoughGuil::getPosThresh()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_getPosThresh_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_getPosThresh_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "imgproc::getPosThresh_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GeneralizedHoughGuil>* me = (Ptr<cv::GeneralizedHoughGuil>*) self; //TODO: check for NULL
        return (*me)->getPosThresh();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::GeneralizedHoughGuil::getScaleThresh()
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_getScaleThresh_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_getScaleThresh_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "imgproc::getScaleThresh_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GeneralizedHoughGuil>* me = (Ptr<cv::GeneralizedHoughGuil>*) self; //TODO: check for NULL
        return (*me)->getScaleThresh();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::GeneralizedHoughGuil::setAngleEpsilon(double angleEpsilon)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_setAngleEpsilon_10 (JNIEnv*, jclass, jlong, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_setAngleEpsilon_10
  (JNIEnv* env, jclass , jlong self, jdouble angleEpsilon)
{
    static const char method_name[] = "imgproc::setAngleEpsilon_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GeneralizedHoughGuil>* me = (Ptr<cv::GeneralizedHoughGuil>*) self; //TODO: check for NULL
        (*me)->setAngleEpsilon( (double)angleEpsilon );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::GeneralizedHoughGuil::setAngleStep(double angleStep)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_setAngleStep_10 (JNIEnv*, jclass, jlong, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_setAngleStep_10
  (JNIEnv* env, jclass , jlong self, jdouble angleStep)
{
    static const char method_name[] = "imgproc::setAngleStep_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GeneralizedHoughGuil>* me = (Ptr<cv::GeneralizedHoughGuil>*) self; //TODO: check for NULL
        (*me)->setAngleStep( (double)angleStep );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::GeneralizedHoughGuil::setAngleThresh(int angleThresh)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_setAngleThresh_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_setAngleThresh_10
  (JNIEnv* env, jclass , jlong self, jint angleThresh)
{
    static const char method_name[] = "imgproc::setAngleThresh_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GeneralizedHoughGuil>* me = (Ptr<cv::GeneralizedHoughGuil>*) self; //TODO: check for NULL
        (*me)->setAngleThresh( (int)angleThresh );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::GeneralizedHoughGuil::setLevels(int levels)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_setLevels_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_setLevels_10
  (JNIEnv* env, jclass , jlong self, jint levels)
{
    static const char method_name[] = "imgproc::setLevels_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GeneralizedHoughGuil>* me = (Ptr<cv::GeneralizedHoughGuil>*) self; //TODO: check for NULL
        (*me)->setLevels( (int)levels );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::GeneralizedHoughGuil::setMaxAngle(double maxAngle)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_setMaxAngle_10 (JNIEnv*, jclass, jlong, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_setMaxAngle_10
  (JNIEnv* env, jclass , jlong self, jdouble maxAngle)
{
    static const char method_name[] = "imgproc::setMaxAngle_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GeneralizedHoughGuil>* me = (Ptr<cv::GeneralizedHoughGuil>*) self; //TODO: check for NULL
        (*me)->setMaxAngle( (double)maxAngle );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::GeneralizedHoughGuil::setMaxScale(double maxScale)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_setMaxScale_10 (JNIEnv*, jclass, jlong, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_setMaxScale_10
  (JNIEnv* env, jclass , jlong self, jdouble maxScale)
{
    static const char method_name[] = "imgproc::setMaxScale_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GeneralizedHoughGuil>* me = (Ptr<cv::GeneralizedHoughGuil>*) self; //TODO: check for NULL
        (*me)->setMaxScale( (double)maxScale );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::GeneralizedHoughGuil::setMinAngle(double minAngle)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_setMinAngle_10 (JNIEnv*, jclass, jlong, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_setMinAngle_10
  (JNIEnv* env, jclass , jlong self, jdouble minAngle)
{
    static const char method_name[] = "imgproc::setMinAngle_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GeneralizedHoughGuil>* me = (Ptr<cv::GeneralizedHoughGuil>*) self; //TODO: check for NULL
        (*me)->setMinAngle( (double)minAngle );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::GeneralizedHoughGuil::setMinScale(double minScale)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_setMinScale_10 (JNIEnv*, jclass, jlong, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_setMinScale_10
  (JNIEnv* env, jclass , jlong self, jdouble minScale)
{
    static const char method_name[] = "imgproc::setMinScale_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GeneralizedHoughGuil>* me = (Ptr<cv::GeneralizedHoughGuil>*) self; //TODO: check for NULL
        (*me)->setMinScale( (double)minScale );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::GeneralizedHoughGuil::setPosThresh(int posThresh)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_setPosThresh_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_setPosThresh_10
  (JNIEnv* env, jclass , jlong self, jint posThresh)
{
    static const char method_name[] = "imgproc::setPosThresh_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GeneralizedHoughGuil>* me = (Ptr<cv::GeneralizedHoughGuil>*) self; //TODO: check for NULL
        (*me)->setPosThresh( (int)posThresh );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::GeneralizedHoughGuil::setScaleStep(double scaleStep)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_setScaleStep_10 (JNIEnv*, jclass, jlong, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_setScaleStep_10
  (JNIEnv* env, jclass , jlong self, jdouble scaleStep)
{
    static const char method_name[] = "imgproc::setScaleStep_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GeneralizedHoughGuil>* me = (Ptr<cv::GeneralizedHoughGuil>*) self; //TODO: check for NULL
        (*me)->setScaleStep( (double)scaleStep );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::GeneralizedHoughGuil::setScaleThresh(int scaleThresh)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_setScaleThresh_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_setScaleThresh_10
  (JNIEnv* env, jclass , jlong self, jint scaleThresh)
{
    static const char method_name[] = "imgproc::setScaleThresh_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GeneralizedHoughGuil>* me = (Ptr<cv::GeneralizedHoughGuil>*) self; //TODO: check for NULL
        (*me)->setScaleThresh( (int)scaleThresh );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::GeneralizedHoughGuil::setXi(double xi)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_setXi_10 (JNIEnv*, jclass, jlong, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_setXi_10
  (JNIEnv* env, jclass , jlong self, jdouble xi)
{
    static const char method_name[] = "imgproc::setXi_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::GeneralizedHoughGuil>* me = (Ptr<cv::GeneralizedHoughGuil>*) self; //TODO: check for NULL
        (*me)->setXi( (double)xi );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void Ptr<cv::GeneralizedHoughGuil>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_GeneralizedHoughGuil_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::GeneralizedHoughGuil>*) self;
}


//
//  int cv::LineSegmentDetector::compareSegments(Size size, Mat lines1, Mat lines2, Mat& _image = Mat())
//

using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_LineSegmentDetector_compareSegments_10 (JNIEnv*, jclass, jlong, jdouble, jdouble, jlong, jlong, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_LineSegmentDetector_compareSegments_10
  (JNIEnv* env, jclass , jlong self, jdouble size_width, jdouble size_height, jlong lines1_nativeObj, jlong lines2_nativeObj, jlong _image_nativeObj)
{
    static const char method_name[] = "imgproc::compareSegments_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::LineSegmentDetector>* me = (Ptr<cv::LineSegmentDetector>*) self; //TODO: check for NULL
        Size size((int)size_width, (int)size_height);
        Mat& lines1 = *((Mat*)lines1_nativeObj);
        Mat& lines2 = *((Mat*)lines2_nativeObj);
        Mat& _image = *((Mat*)_image_nativeObj);
        return (*me)->compareSegments( size, lines1, lines2, _image );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv;

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_LineSegmentDetector_compareSegments_11 (JNIEnv*, jclass, jlong, jdouble, jdouble, jlong, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_imgproc_LineSegmentDetector_compareSegments_11
  (JNIEnv* env, jclass , jlong self, jdouble size_width, jdouble size_height, jlong lines1_nativeObj, jlong lines2_nativeObj)
{
    static const char method_name[] = "imgproc::compareSegments_11()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::LineSegmentDetector>* me = (Ptr<cv::LineSegmentDetector>*) self; //TODO: check for NULL
        Size size((int)size_width, (int)size_height);
        Mat& lines1 = *((Mat*)lines1_nativeObj);
        Mat& lines2 = *((Mat*)lines2_nativeObj);
        return (*me)->compareSegments( size, lines1, lines2 );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::LineSegmentDetector::detect(Mat _image, Mat& _lines, Mat& width = Mat(), Mat& prec = Mat(), Mat& nfa = Mat())
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_imgproc_LineSegmentDetector_detect_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_LineSegmentDetector_detect_10
  (JNIEnv* env, jclass , jlong self, jlong _image_nativeObj, jlong _lines_nativeObj, jlong width_nativeObj, jlong prec_nativeObj, jlong nfa_nativeObj)
{
    static const char method_name[] = "imgproc::detect_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::LineSegmentDetector>* me = (Ptr<cv::LineSegmentDetector>*) self; //TODO: check for NULL
        Mat& _image = *((Mat*)_image_nativeObj);
        Mat& _lines = *((Mat*)_lines_nativeObj);
        Mat& width = *((Mat*)width_nativeObj);
        Mat& prec = *((Mat*)prec_nativeObj);
        Mat& nfa = *((Mat*)nfa_nativeObj);
        (*me)->detect( _image, _lines, width, prec, nfa );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_imgproc_LineSegmentDetector_detect_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_LineSegmentDetector_detect_11
  (JNIEnv* env, jclass , jlong self, jlong _image_nativeObj, jlong _lines_nativeObj, jlong width_nativeObj, jlong prec_nativeObj)
{
    static const char method_name[] = "imgproc::detect_11()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::LineSegmentDetector>* me = (Ptr<cv::LineSegmentDetector>*) self; //TODO: check for NULL
        Mat& _image = *((Mat*)_image_nativeObj);
        Mat& _lines = *((Mat*)_lines_nativeObj);
        Mat& width = *((Mat*)width_nativeObj);
        Mat& prec = *((Mat*)prec_nativeObj);
        (*me)->detect( _image, _lines, width, prec );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_imgproc_LineSegmentDetector_detect_12 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_LineSegmentDetector_detect_12
  (JNIEnv* env, jclass , jlong self, jlong _image_nativeObj, jlong _lines_nativeObj, jlong width_nativeObj)
{
    static const char method_name[] = "imgproc::detect_12()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::LineSegmentDetector>* me = (Ptr<cv::LineSegmentDetector>*) self; //TODO: check for NULL
        Mat& _image = *((Mat*)_image_nativeObj);
        Mat& _lines = *((Mat*)_lines_nativeObj);
        Mat& width = *((Mat*)width_nativeObj);
        (*me)->detect( _image, _lines, width );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_imgproc_LineSegmentDetector_detect_13 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_LineSegmentDetector_detect_13
  (JNIEnv* env, jclass , jlong self, jlong _image_nativeObj, jlong _lines_nativeObj)
{
    static const char method_name[] = "imgproc::detect_13()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::LineSegmentDetector>* me = (Ptr<cv::LineSegmentDetector>*) self; //TODO: check for NULL
        Mat& _image = *((Mat*)_image_nativeObj);
        Mat& _lines = *((Mat*)_lines_nativeObj);
        (*me)->detect( _image, _lines );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::LineSegmentDetector::drawSegments(Mat& _image, Mat lines)
//

using namespace cv;

JNIEXPORT void JNICALL Java_org_opencv_imgproc_LineSegmentDetector_drawSegments_10 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_LineSegmentDetector_drawSegments_10
  (JNIEnv* env, jclass , jlong self, jlong _image_nativeObj, jlong lines_nativeObj)
{
    static const char method_name[] = "imgproc::drawSegments_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::LineSegmentDetector>* me = (Ptr<cv::LineSegmentDetector>*) self; //TODO: check for NULL
        Mat& _image = *((Mat*)_image_nativeObj);
        Mat& lines = *((Mat*)lines_nativeObj);
        (*me)->drawSegments( _image, lines );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void Ptr<cv::LineSegmentDetector>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_imgproc_LineSegmentDetector_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_imgproc_LineSegmentDetector_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::LineSegmentDetector>*) self;
}



} // extern "C"

#endif // HAVE_OPENCV_IMGPROC
