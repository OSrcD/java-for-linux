//
// This file is auto-generated. Please don't modify it!
//

#undef LOG_TAG

#include "opencv2/opencv_modules.hpp"
#ifdef HAVE_OPENCV_DNN

#include <string>

#include "opencv2/dnn.hpp"

#include "/Users/virtualman/Downloads/MySource/opencv-4.3.0/modules/dnn/misc/java/src/cpp/dnn_converters.hpp"
#include "/Users/virtualman/Downloads/MySource/opencv-4.3.0/modules/dnn/include/opencv2/dnn/dict.hpp"
#include "/Users/virtualman/Downloads/MySource/opencv-4.3.0/modules/dnn/include/opencv2/dnn/dnn.hpp"
#include "/Users/virtualman/Downloads/MySource/opencv-4.3.0/modules/dnn/include/opencv2/dnn/utils/inference_engine.hpp"

#define LOG_TAG "org.opencv.dnn"
#include "common.h"

using namespace cv;

/// throw java exception
#undef throwJavaException
#define throwJavaException throwJavaException_dnn
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
//  int cv::dnn::Layer::outputNameToIndex(String outputName)
//

using namespace cv::dnn;

JNIEXPORT jint JNICALL Java_org_opencv_dnn_Layer_outputNameToIndex_10 (JNIEnv*, jclass, jlong, jstring);

JNIEXPORT jint JNICALL Java_org_opencv_dnn_Layer_outputNameToIndex_10
  (JNIEnv* env, jclass , jlong self, jstring outputName)
{
    static const char method_name[] = "dnn::outputNameToIndex_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::dnn::Layer>* me = (Ptr<cv::dnn::Layer>*) self; //TODO: check for NULL
        const char* utf_outputName = env->GetStringUTFChars(outputName, 0); String n_outputName( utf_outputName ? utf_outputName : "" ); env->ReleaseStringUTFChars(outputName, utf_outputName);
        return (*me)->outputNameToIndex( n_outputName );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::dnn::Layer::finalize(vector_Mat inputs, vector_Mat& outputs)
//

using namespace cv::dnn;

JNIEXPORT void JNICALL Java_org_opencv_dnn_Layer_finalize_10 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_dnn_Layer_finalize_10
  (JNIEnv* env, jclass , jlong self, jlong inputs_mat_nativeObj, jlong outputs_mat_nativeObj)
{
    static const char method_name[] = "dnn::finalize_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> inputs;
        Mat& inputs_mat = *((Mat*)inputs_mat_nativeObj);
        Mat_to_vector_Mat( inputs_mat, inputs );
        std::vector<Mat> outputs;
        Mat& outputs_mat = *((Mat*)outputs_mat_nativeObj);
        Ptr<cv::dnn::Layer>* me = (Ptr<cv::dnn::Layer>*) self; //TODO: check for NULL
        (*me)->finalize( inputs, outputs );
        vector_Mat_to_Mat( outputs, outputs_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::dnn::Layer::run(vector_Mat inputs, vector_Mat& outputs, vector_Mat& internals)
//

using namespace cv::dnn;

JNIEXPORT void JNICALL Java_org_opencv_dnn_Layer_run_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_dnn_Layer_run_10
  (JNIEnv* env, jclass , jlong self, jlong inputs_mat_nativeObj, jlong outputs_mat_nativeObj, jlong internals_mat_nativeObj)
{
    static const char method_name[] = "dnn::run_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> inputs;
        Mat& inputs_mat = *((Mat*)inputs_mat_nativeObj);
        Mat_to_vector_Mat( inputs_mat, inputs );
        std::vector<Mat> outputs;
        Mat& outputs_mat = *((Mat*)outputs_mat_nativeObj);
        std::vector<Mat> internals;
        Mat& internals_mat = *((Mat*)internals_mat_nativeObj);
        Mat_to_vector_Mat( internals_mat, internals );
        Ptr<cv::dnn::Layer>* me = (Ptr<cv::dnn::Layer>*) self; //TODO: check for NULL
        (*me)->run( inputs, outputs, internals );
        vector_Mat_to_Mat( outputs, outputs_mat );
        vector_Mat_to_Mat( internals, internals_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
// vector_Mat Layer::blobs
//

using namespace cv::dnn;

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Layer_get_1blobs_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Layer_get_1blobs_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "dnn::get_1blobs_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::dnn::Layer>* me = (Ptr<cv::dnn::Layer>*) self; //TODO: check for NULL
        std::vector<Mat> _ret_val_vector_ = (*me)->blobs;//();
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
// void Layer::blobs
//

using namespace cv::dnn;

JNIEXPORT void JNICALL Java_org_opencv_dnn_Layer_set_1blobs_10 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_dnn_Layer_set_1blobs_10
  (JNIEnv* env, jclass , jlong self, jlong blobs_mat_nativeObj)
{
    static const char method_name[] = "dnn::set_1blobs_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> blobs;
        Mat& blobs_mat = *((Mat*)blobs_mat_nativeObj);
        Mat_to_vector_Mat( blobs_mat, blobs );
        Ptr<cv::dnn::Layer>* me = (Ptr<cv::dnn::Layer>*) self; //TODO: check for NULL
        (*me)->blobs = ( blobs );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
// String Layer::name
//

using namespace cv::dnn;

JNIEXPORT jstring JNICALL Java_org_opencv_dnn_Layer_get_1name_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jstring JNICALL Java_org_opencv_dnn_Layer_get_1name_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "dnn::get_1name_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::dnn::Layer>* me = (Ptr<cv::dnn::Layer>*) self; //TODO: check for NULL
        cv::String _retval_ = (*me)->name;//();
        return env->NewStringUTF(_retval_.c_str());
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return env->NewStringUTF("");
}



//
// String Layer::type
//

using namespace cv::dnn;

JNIEXPORT jstring JNICALL Java_org_opencv_dnn_Layer_get_1type_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jstring JNICALL Java_org_opencv_dnn_Layer_get_1type_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "dnn::get_1type_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::dnn::Layer>* me = (Ptr<cv::dnn::Layer>*) self; //TODO: check for NULL
        cv::String _retval_ = (*me)->type;//();
        return env->NewStringUTF(_retval_.c_str());
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return env->NewStringUTF("");
}



//
// int Layer::preferableTarget
//

using namespace cv::dnn;

JNIEXPORT jint JNICALL Java_org_opencv_dnn_Layer_get_1preferableTarget_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_dnn_Layer_get_1preferableTarget_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "dnn::get_1preferableTarget_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::dnn::Layer>* me = (Ptr<cv::dnn::Layer>*) self; //TODO: check for NULL
        return (*me)->preferableTarget;//();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  native support for java finalize()
//  static void Ptr<cv::dnn::Layer>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_dnn_Layer_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_dnn_Layer_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::dnn::Layer>*) self;
}


//
//  Mat cv::dnn::blobFromImage(Mat image, double scalefactor = 1.0, Size size = Size(), Scalar mean = Scalar(), bool swapRB = false, bool crop = false, int ddepth = CV_32F)
//



JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_blobFromImage_10 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jboolean, jboolean, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_blobFromImage_10
  (JNIEnv* env, jclass , jlong image_nativeObj, jdouble scalefactor, jdouble size_width, jdouble size_height, jdouble mean_val0, jdouble mean_val1, jdouble mean_val2, jdouble mean_val3, jboolean swapRB, jboolean crop, jint ddepth)
{
    static const char method_name[] = "dnn::blobFromImage_10()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Size size((int)size_width, (int)size_height);
        Scalar mean(mean_val0, mean_val1, mean_val2, mean_val3);
        ::Mat _retval_ = cv::dnn::blobFromImage( image, (double)scalefactor, size, mean, (bool)swapRB, (bool)crop, (int)ddepth );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_blobFromImage_11 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jboolean, jboolean);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_blobFromImage_11
  (JNIEnv* env, jclass , jlong image_nativeObj, jdouble scalefactor, jdouble size_width, jdouble size_height, jdouble mean_val0, jdouble mean_val1, jdouble mean_val2, jdouble mean_val3, jboolean swapRB, jboolean crop)
{
    static const char method_name[] = "dnn::blobFromImage_11()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Size size((int)size_width, (int)size_height);
        Scalar mean(mean_val0, mean_val1, mean_val2, mean_val3);
        ::Mat _retval_ = cv::dnn::blobFromImage( image, (double)scalefactor, size, mean, (bool)swapRB, (bool)crop );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_blobFromImage_12 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jboolean);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_blobFromImage_12
  (JNIEnv* env, jclass , jlong image_nativeObj, jdouble scalefactor, jdouble size_width, jdouble size_height, jdouble mean_val0, jdouble mean_val1, jdouble mean_val2, jdouble mean_val3, jboolean swapRB)
{
    static const char method_name[] = "dnn::blobFromImage_12()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Size size((int)size_width, (int)size_height);
        Scalar mean(mean_val0, mean_val1, mean_val2, mean_val3);
        ::Mat _retval_ = cv::dnn::blobFromImage( image, (double)scalefactor, size, mean, (bool)swapRB );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_blobFromImage_13 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_blobFromImage_13
  (JNIEnv* env, jclass , jlong image_nativeObj, jdouble scalefactor, jdouble size_width, jdouble size_height, jdouble mean_val0, jdouble mean_val1, jdouble mean_val2, jdouble mean_val3)
{
    static const char method_name[] = "dnn::blobFromImage_13()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Size size((int)size_width, (int)size_height);
        Scalar mean(mean_val0, mean_val1, mean_val2, mean_val3);
        ::Mat _retval_ = cv::dnn::blobFromImage( image, (double)scalefactor, size, mean );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_blobFromImage_14 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_blobFromImage_14
  (JNIEnv* env, jclass , jlong image_nativeObj, jdouble scalefactor, jdouble size_width, jdouble size_height)
{
    static const char method_name[] = "dnn::blobFromImage_14()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        Size size((int)size_width, (int)size_height);
        ::Mat _retval_ = cv::dnn::blobFromImage( image, (double)scalefactor, size );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_blobFromImage_15 (JNIEnv*, jclass, jlong, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_blobFromImage_15
  (JNIEnv* env, jclass , jlong image_nativeObj, jdouble scalefactor)
{
    static const char method_name[] = "dnn::blobFromImage_15()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        ::Mat _retval_ = cv::dnn::blobFromImage( image, (double)scalefactor );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_blobFromImage_16 (JNIEnv*, jclass, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_blobFromImage_16
  (JNIEnv* env, jclass , jlong image_nativeObj)
{
    static const char method_name[] = "dnn::blobFromImage_16()";
    try {
        LOGD("%s", method_name);
        Mat& image = *((Mat*)image_nativeObj);
        ::Mat _retval_ = cv::dnn::blobFromImage( image );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Mat cv::dnn::blobFromImages(vector_Mat images, double scalefactor = 1.0, Size size = Size(), Scalar mean = Scalar(), bool swapRB = false, bool crop = false, int ddepth = CV_32F)
//



JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_blobFromImages_10 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jboolean, jboolean, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_blobFromImages_10
  (JNIEnv* env, jclass , jlong images_mat_nativeObj, jdouble scalefactor, jdouble size_width, jdouble size_height, jdouble mean_val0, jdouble mean_val1, jdouble mean_val2, jdouble mean_val3, jboolean swapRB, jboolean crop, jint ddepth)
{
    static const char method_name[] = "dnn::blobFromImages_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> images;
        Mat& images_mat = *((Mat*)images_mat_nativeObj);
        Mat_to_vector_Mat( images_mat, images );
        Size size((int)size_width, (int)size_height);
        Scalar mean(mean_val0, mean_val1, mean_val2, mean_val3);
        ::Mat _retval_ = cv::dnn::blobFromImages( images, (double)scalefactor, size, mean, (bool)swapRB, (bool)crop, (int)ddepth );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_blobFromImages_11 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jboolean, jboolean);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_blobFromImages_11
  (JNIEnv* env, jclass , jlong images_mat_nativeObj, jdouble scalefactor, jdouble size_width, jdouble size_height, jdouble mean_val0, jdouble mean_val1, jdouble mean_val2, jdouble mean_val3, jboolean swapRB, jboolean crop)
{
    static const char method_name[] = "dnn::blobFromImages_11()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> images;
        Mat& images_mat = *((Mat*)images_mat_nativeObj);
        Mat_to_vector_Mat( images_mat, images );
        Size size((int)size_width, (int)size_height);
        Scalar mean(mean_val0, mean_val1, mean_val2, mean_val3);
        ::Mat _retval_ = cv::dnn::blobFromImages( images, (double)scalefactor, size, mean, (bool)swapRB, (bool)crop );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_blobFromImages_12 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jboolean);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_blobFromImages_12
  (JNIEnv* env, jclass , jlong images_mat_nativeObj, jdouble scalefactor, jdouble size_width, jdouble size_height, jdouble mean_val0, jdouble mean_val1, jdouble mean_val2, jdouble mean_val3, jboolean swapRB)
{
    static const char method_name[] = "dnn::blobFromImages_12()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> images;
        Mat& images_mat = *((Mat*)images_mat_nativeObj);
        Mat_to_vector_Mat( images_mat, images );
        Size size((int)size_width, (int)size_height);
        Scalar mean(mean_val0, mean_val1, mean_val2, mean_val3);
        ::Mat _retval_ = cv::dnn::blobFromImages( images, (double)scalefactor, size, mean, (bool)swapRB );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_blobFromImages_13 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_blobFromImages_13
  (JNIEnv* env, jclass , jlong images_mat_nativeObj, jdouble scalefactor, jdouble size_width, jdouble size_height, jdouble mean_val0, jdouble mean_val1, jdouble mean_val2, jdouble mean_val3)
{
    static const char method_name[] = "dnn::blobFromImages_13()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> images;
        Mat& images_mat = *((Mat*)images_mat_nativeObj);
        Mat_to_vector_Mat( images_mat, images );
        Size size((int)size_width, (int)size_height);
        Scalar mean(mean_val0, mean_val1, mean_val2, mean_val3);
        ::Mat _retval_ = cv::dnn::blobFromImages( images, (double)scalefactor, size, mean );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_blobFromImages_14 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_blobFromImages_14
  (JNIEnv* env, jclass , jlong images_mat_nativeObj, jdouble scalefactor, jdouble size_width, jdouble size_height)
{
    static const char method_name[] = "dnn::blobFromImages_14()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> images;
        Mat& images_mat = *((Mat*)images_mat_nativeObj);
        Mat_to_vector_Mat( images_mat, images );
        Size size((int)size_width, (int)size_height);
        ::Mat _retval_ = cv::dnn::blobFromImages( images, (double)scalefactor, size );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_blobFromImages_15 (JNIEnv*, jclass, jlong, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_blobFromImages_15
  (JNIEnv* env, jclass , jlong images_mat_nativeObj, jdouble scalefactor)
{
    static const char method_name[] = "dnn::blobFromImages_15()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> images;
        Mat& images_mat = *((Mat*)images_mat_nativeObj);
        Mat_to_vector_Mat( images_mat, images );
        ::Mat _retval_ = cv::dnn::blobFromImages( images, (double)scalefactor );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_blobFromImages_16 (JNIEnv*, jclass, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_blobFromImages_16
  (JNIEnv* env, jclass , jlong images_mat_nativeObj)
{
    static const char method_name[] = "dnn::blobFromImages_16()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> images;
        Mat& images_mat = *((Mat*)images_mat_nativeObj);
        Mat_to_vector_Mat( images_mat, images );
        ::Mat _retval_ = cv::dnn::blobFromImages( images );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Mat cv::dnn::readTensorFromONNX(String path)
//



JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readTensorFromONNX_10 (JNIEnv*, jclass, jstring);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readTensorFromONNX_10
  (JNIEnv* env, jclass , jstring path)
{
    static const char method_name[] = "dnn::readTensorFromONNX_10()";
    try {
        LOGD("%s", method_name);
        const char* utf_path = env->GetStringUTFChars(path, 0); String n_path( utf_path ? utf_path : "" ); env->ReleaseStringUTFChars(path, utf_path);
        ::Mat _retval_ = cv::dnn::readTensorFromONNX( n_path );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Mat cv::dnn::readTorchBlob(String filename, bool isBinary = true)
//



JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readTorchBlob_10 (JNIEnv*, jclass, jstring, jboolean);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readTorchBlob_10
  (JNIEnv* env, jclass , jstring filename, jboolean isBinary)
{
    static const char method_name[] = "dnn::readTorchBlob_10()";
    try {
        LOGD("%s", method_name);
        const char* utf_filename = env->GetStringUTFChars(filename, 0); String n_filename( utf_filename ? utf_filename : "" ); env->ReleaseStringUTFChars(filename, utf_filename);
        ::Mat _retval_ = cv::dnn::readTorchBlob( n_filename, (bool)isBinary );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readTorchBlob_11 (JNIEnv*, jclass, jstring);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readTorchBlob_11
  (JNIEnv* env, jclass , jstring filename)
{
    static const char method_name[] = "dnn::readTorchBlob_11()";
    try {
        LOGD("%s", method_name);
        const char* utf_filename = env->GetStringUTFChars(filename, 0); String n_filename( utf_filename ? utf_filename : "" ); env->ReleaseStringUTFChars(filename, utf_filename);
        ::Mat _retval_ = cv::dnn::readTorchBlob( n_filename );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Net cv::dnn::readNet(String framework, vector_uchar bufferModel, vector_uchar bufferConfig = std::vector<uchar>())
//



JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readNet_10 (JNIEnv*, jclass, jstring, jlong, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readNet_10
  (JNIEnv* env, jclass , jstring framework, jlong bufferModel_mat_nativeObj, jlong bufferConfig_mat_nativeObj)
{
    static const char method_name[] = "dnn::readNet_10()";
    try {
        LOGD("%s", method_name);
        std::vector<uchar> bufferModel;
        Mat& bufferModel_mat = *((Mat*)bufferModel_mat_nativeObj);
        Mat_to_vector_uchar( bufferModel_mat, bufferModel );
        std::vector<uchar> bufferConfig;
        Mat& bufferConfig_mat = *((Mat*)bufferConfig_mat_nativeObj);
        Mat_to_vector_uchar( bufferConfig_mat, bufferConfig );
        const char* utf_framework = env->GetStringUTFChars(framework, 0); String n_framework( utf_framework ? utf_framework : "" ); env->ReleaseStringUTFChars(framework, utf_framework);
        cv::dnn::Net _retval_ = cv::dnn::readNet( n_framework, bufferModel, bufferConfig );
        return (jlong) new cv::dnn::Net(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readNet_11 (JNIEnv*, jclass, jstring, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readNet_11
  (JNIEnv* env, jclass , jstring framework, jlong bufferModel_mat_nativeObj)
{
    static const char method_name[] = "dnn::readNet_11()";
    try {
        LOGD("%s", method_name);
        std::vector<uchar> bufferModel;
        Mat& bufferModel_mat = *((Mat*)bufferModel_mat_nativeObj);
        Mat_to_vector_uchar( bufferModel_mat, bufferModel );
        const char* utf_framework = env->GetStringUTFChars(framework, 0); String n_framework( utf_framework ? utf_framework : "" ); env->ReleaseStringUTFChars(framework, utf_framework);
        cv::dnn::Net _retval_ = cv::dnn::readNet( n_framework, bufferModel );
        return (jlong) new cv::dnn::Net(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Net cv::dnn::readNet(String model, String config = "", String framework = "")
//



JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readNet_12 (JNIEnv*, jclass, jstring, jstring, jstring);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readNet_12
  (JNIEnv* env, jclass , jstring model, jstring config, jstring framework)
{
    static const char method_name[] = "dnn::readNet_12()";
    try {
        LOGD("%s", method_name);
        const char* utf_model = env->GetStringUTFChars(model, 0); String n_model( utf_model ? utf_model : "" ); env->ReleaseStringUTFChars(model, utf_model);
        const char* utf_config = env->GetStringUTFChars(config, 0); String n_config( utf_config ? utf_config : "" ); env->ReleaseStringUTFChars(config, utf_config);
        const char* utf_framework = env->GetStringUTFChars(framework, 0); String n_framework( utf_framework ? utf_framework : "" ); env->ReleaseStringUTFChars(framework, utf_framework);
        cv::dnn::Net _retval_ = cv::dnn::readNet( n_model, n_config, n_framework );
        return (jlong) new cv::dnn::Net(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readNet_13 (JNIEnv*, jclass, jstring, jstring);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readNet_13
  (JNIEnv* env, jclass , jstring model, jstring config)
{
    static const char method_name[] = "dnn::readNet_13()";
    try {
        LOGD("%s", method_name);
        const char* utf_model = env->GetStringUTFChars(model, 0); String n_model( utf_model ? utf_model : "" ); env->ReleaseStringUTFChars(model, utf_model);
        const char* utf_config = env->GetStringUTFChars(config, 0); String n_config( utf_config ? utf_config : "" ); env->ReleaseStringUTFChars(config, utf_config);
        cv::dnn::Net _retval_ = cv::dnn::readNet( n_model, n_config );
        return (jlong) new cv::dnn::Net(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readNet_14 (JNIEnv*, jclass, jstring);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readNet_14
  (JNIEnv* env, jclass , jstring model)
{
    static const char method_name[] = "dnn::readNet_14()";
    try {
        LOGD("%s", method_name);
        const char* utf_model = env->GetStringUTFChars(model, 0); String n_model( utf_model ? utf_model : "" ); env->ReleaseStringUTFChars(model, utf_model);
        cv::dnn::Net _retval_ = cv::dnn::readNet( n_model );
        return (jlong) new cv::dnn::Net(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Net cv::dnn::readNetFromCaffe(String prototxt, String caffeModel = String())
//



JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readNetFromCaffe_10 (JNIEnv*, jclass, jstring, jstring);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readNetFromCaffe_10
  (JNIEnv* env, jclass , jstring prototxt, jstring caffeModel)
{
    static const char method_name[] = "dnn::readNetFromCaffe_10()";
    try {
        LOGD("%s", method_name);
        const char* utf_prototxt = env->GetStringUTFChars(prototxt, 0); String n_prototxt( utf_prototxt ? utf_prototxt : "" ); env->ReleaseStringUTFChars(prototxt, utf_prototxt);
        const char* utf_caffeModel = env->GetStringUTFChars(caffeModel, 0); String n_caffeModel( utf_caffeModel ? utf_caffeModel : "" ); env->ReleaseStringUTFChars(caffeModel, utf_caffeModel);
        cv::dnn::Net _retval_ = cv::dnn::readNetFromCaffe( n_prototxt, n_caffeModel );
        return (jlong) new cv::dnn::Net(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readNetFromCaffe_11 (JNIEnv*, jclass, jstring);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readNetFromCaffe_11
  (JNIEnv* env, jclass , jstring prototxt)
{
    static const char method_name[] = "dnn::readNetFromCaffe_11()";
    try {
        LOGD("%s", method_name);
        const char* utf_prototxt = env->GetStringUTFChars(prototxt, 0); String n_prototxt( utf_prototxt ? utf_prototxt : "" ); env->ReleaseStringUTFChars(prototxt, utf_prototxt);
        cv::dnn::Net _retval_ = cv::dnn::readNetFromCaffe( n_prototxt );
        return (jlong) new cv::dnn::Net(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Net cv::dnn::readNetFromCaffe(vector_uchar bufferProto, vector_uchar bufferModel = std::vector<uchar>())
//



JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readNetFromCaffe_12 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readNetFromCaffe_12
  (JNIEnv* env, jclass , jlong bufferProto_mat_nativeObj, jlong bufferModel_mat_nativeObj)
{
    static const char method_name[] = "dnn::readNetFromCaffe_12()";
    try {
        LOGD("%s", method_name);
        std::vector<uchar> bufferProto;
        Mat& bufferProto_mat = *((Mat*)bufferProto_mat_nativeObj);
        Mat_to_vector_uchar( bufferProto_mat, bufferProto );
        std::vector<uchar> bufferModel;
        Mat& bufferModel_mat = *((Mat*)bufferModel_mat_nativeObj);
        Mat_to_vector_uchar( bufferModel_mat, bufferModel );
        cv::dnn::Net _retval_ = cv::dnn::readNetFromCaffe( bufferProto, bufferModel );
        return (jlong) new cv::dnn::Net(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readNetFromCaffe_13 (JNIEnv*, jclass, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readNetFromCaffe_13
  (JNIEnv* env, jclass , jlong bufferProto_mat_nativeObj)
{
    static const char method_name[] = "dnn::readNetFromCaffe_13()";
    try {
        LOGD("%s", method_name);
        std::vector<uchar> bufferProto;
        Mat& bufferProto_mat = *((Mat*)bufferProto_mat_nativeObj);
        Mat_to_vector_uchar( bufferProto_mat, bufferProto );
        cv::dnn::Net _retval_ = cv::dnn::readNetFromCaffe( bufferProto );
        return (jlong) new cv::dnn::Net(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Net cv::dnn::readNetFromDarknet(String cfgFile, String darknetModel = String())
//



JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readNetFromDarknet_10 (JNIEnv*, jclass, jstring, jstring);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readNetFromDarknet_10
  (JNIEnv* env, jclass , jstring cfgFile, jstring darknetModel)
{
    static const char method_name[] = "dnn::readNetFromDarknet_10()";
    try {
        LOGD("%s", method_name);
        const char* utf_cfgFile = env->GetStringUTFChars(cfgFile, 0); String n_cfgFile( utf_cfgFile ? utf_cfgFile : "" ); env->ReleaseStringUTFChars(cfgFile, utf_cfgFile);
        const char* utf_darknetModel = env->GetStringUTFChars(darknetModel, 0); String n_darknetModel( utf_darknetModel ? utf_darknetModel : "" ); env->ReleaseStringUTFChars(darknetModel, utf_darknetModel);
        cv::dnn::Net _retval_ = cv::dnn::readNetFromDarknet( n_cfgFile, n_darknetModel );
        return (jlong) new cv::dnn::Net(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readNetFromDarknet_11 (JNIEnv*, jclass, jstring);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readNetFromDarknet_11
  (JNIEnv* env, jclass , jstring cfgFile)
{
    static const char method_name[] = "dnn::readNetFromDarknet_11()";
    try {
        LOGD("%s", method_name);
        const char* utf_cfgFile = env->GetStringUTFChars(cfgFile, 0); String n_cfgFile( utf_cfgFile ? utf_cfgFile : "" ); env->ReleaseStringUTFChars(cfgFile, utf_cfgFile);
        cv::dnn::Net _retval_ = cv::dnn::readNetFromDarknet( n_cfgFile );
        return (jlong) new cv::dnn::Net(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Net cv::dnn::readNetFromDarknet(vector_uchar bufferCfg, vector_uchar bufferModel = std::vector<uchar>())
//



JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readNetFromDarknet_12 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readNetFromDarknet_12
  (JNIEnv* env, jclass , jlong bufferCfg_mat_nativeObj, jlong bufferModel_mat_nativeObj)
{
    static const char method_name[] = "dnn::readNetFromDarknet_12()";
    try {
        LOGD("%s", method_name);
        std::vector<uchar> bufferCfg;
        Mat& bufferCfg_mat = *((Mat*)bufferCfg_mat_nativeObj);
        Mat_to_vector_uchar( bufferCfg_mat, bufferCfg );
        std::vector<uchar> bufferModel;
        Mat& bufferModel_mat = *((Mat*)bufferModel_mat_nativeObj);
        Mat_to_vector_uchar( bufferModel_mat, bufferModel );
        cv::dnn::Net _retval_ = cv::dnn::readNetFromDarknet( bufferCfg, bufferModel );
        return (jlong) new cv::dnn::Net(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readNetFromDarknet_13 (JNIEnv*, jclass, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readNetFromDarknet_13
  (JNIEnv* env, jclass , jlong bufferCfg_mat_nativeObj)
{
    static const char method_name[] = "dnn::readNetFromDarknet_13()";
    try {
        LOGD("%s", method_name);
        std::vector<uchar> bufferCfg;
        Mat& bufferCfg_mat = *((Mat*)bufferCfg_mat_nativeObj);
        Mat_to_vector_uchar( bufferCfg_mat, bufferCfg );
        cv::dnn::Net _retval_ = cv::dnn::readNetFromDarknet( bufferCfg );
        return (jlong) new cv::dnn::Net(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Net cv::dnn::readNetFromModelOptimizer(String xml, String bin)
//



JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readNetFromModelOptimizer_10 (JNIEnv*, jclass, jstring, jstring);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readNetFromModelOptimizer_10
  (JNIEnv* env, jclass , jstring xml, jstring bin)
{
    static const char method_name[] = "dnn::readNetFromModelOptimizer_10()";
    try {
        LOGD("%s", method_name);
        const char* utf_xml = env->GetStringUTFChars(xml, 0); String n_xml( utf_xml ? utf_xml : "" ); env->ReleaseStringUTFChars(xml, utf_xml);
        const char* utf_bin = env->GetStringUTFChars(bin, 0); String n_bin( utf_bin ? utf_bin : "" ); env->ReleaseStringUTFChars(bin, utf_bin);
        cv::dnn::Net _retval_ = cv::dnn::readNetFromModelOptimizer( n_xml, n_bin );
        return (jlong) new cv::dnn::Net(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Net cv::dnn::readNetFromModelOptimizer(vector_uchar bufferModelConfig, vector_uchar bufferWeights)
//



JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readNetFromModelOptimizer_11 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readNetFromModelOptimizer_11
  (JNIEnv* env, jclass , jlong bufferModelConfig_mat_nativeObj, jlong bufferWeights_mat_nativeObj)
{
    static const char method_name[] = "dnn::readNetFromModelOptimizer_11()";
    try {
        LOGD("%s", method_name);
        std::vector<uchar> bufferModelConfig;
        Mat& bufferModelConfig_mat = *((Mat*)bufferModelConfig_mat_nativeObj);
        Mat_to_vector_uchar( bufferModelConfig_mat, bufferModelConfig );
        std::vector<uchar> bufferWeights;
        Mat& bufferWeights_mat = *((Mat*)bufferWeights_mat_nativeObj);
        Mat_to_vector_uchar( bufferWeights_mat, bufferWeights );
        cv::dnn::Net _retval_ = cv::dnn::readNetFromModelOptimizer( bufferModelConfig, bufferWeights );
        return (jlong) new cv::dnn::Net(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Net cv::dnn::readNetFromONNX(String onnxFile)
//



JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readNetFromONNX_10 (JNIEnv*, jclass, jstring);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readNetFromONNX_10
  (JNIEnv* env, jclass , jstring onnxFile)
{
    static const char method_name[] = "dnn::readNetFromONNX_10()";
    try {
        LOGD("%s", method_name);
        const char* utf_onnxFile = env->GetStringUTFChars(onnxFile, 0); String n_onnxFile( utf_onnxFile ? utf_onnxFile : "" ); env->ReleaseStringUTFChars(onnxFile, utf_onnxFile);
        cv::dnn::Net _retval_ = cv::dnn::readNetFromONNX( n_onnxFile );
        return (jlong) new cv::dnn::Net(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Net cv::dnn::readNetFromONNX(vector_uchar buffer)
//



JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readNetFromONNX_11 (JNIEnv*, jclass, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readNetFromONNX_11
  (JNIEnv* env, jclass , jlong buffer_mat_nativeObj)
{
    static const char method_name[] = "dnn::readNetFromONNX_11()";
    try {
        LOGD("%s", method_name);
        std::vector<uchar> buffer;
        Mat& buffer_mat = *((Mat*)buffer_mat_nativeObj);
        Mat_to_vector_uchar( buffer_mat, buffer );
        cv::dnn::Net _retval_ = cv::dnn::readNetFromONNX( buffer );
        return (jlong) new cv::dnn::Net(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Net cv::dnn::readNetFromTensorflow(String model, String config = String())
//



JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readNetFromTensorflow_10 (JNIEnv*, jclass, jstring, jstring);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readNetFromTensorflow_10
  (JNIEnv* env, jclass , jstring model, jstring config)
{
    static const char method_name[] = "dnn::readNetFromTensorflow_10()";
    try {
        LOGD("%s", method_name);
        const char* utf_model = env->GetStringUTFChars(model, 0); String n_model( utf_model ? utf_model : "" ); env->ReleaseStringUTFChars(model, utf_model);
        const char* utf_config = env->GetStringUTFChars(config, 0); String n_config( utf_config ? utf_config : "" ); env->ReleaseStringUTFChars(config, utf_config);
        cv::dnn::Net _retval_ = cv::dnn::readNetFromTensorflow( n_model, n_config );
        return (jlong) new cv::dnn::Net(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readNetFromTensorflow_11 (JNIEnv*, jclass, jstring);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readNetFromTensorflow_11
  (JNIEnv* env, jclass , jstring model)
{
    static const char method_name[] = "dnn::readNetFromTensorflow_11()";
    try {
        LOGD("%s", method_name);
        const char* utf_model = env->GetStringUTFChars(model, 0); String n_model( utf_model ? utf_model : "" ); env->ReleaseStringUTFChars(model, utf_model);
        cv::dnn::Net _retval_ = cv::dnn::readNetFromTensorflow( n_model );
        return (jlong) new cv::dnn::Net(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Net cv::dnn::readNetFromTensorflow(vector_uchar bufferModel, vector_uchar bufferConfig = std::vector<uchar>())
//



JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readNetFromTensorflow_12 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readNetFromTensorflow_12
  (JNIEnv* env, jclass , jlong bufferModel_mat_nativeObj, jlong bufferConfig_mat_nativeObj)
{
    static const char method_name[] = "dnn::readNetFromTensorflow_12()";
    try {
        LOGD("%s", method_name);
        std::vector<uchar> bufferModel;
        Mat& bufferModel_mat = *((Mat*)bufferModel_mat_nativeObj);
        Mat_to_vector_uchar( bufferModel_mat, bufferModel );
        std::vector<uchar> bufferConfig;
        Mat& bufferConfig_mat = *((Mat*)bufferConfig_mat_nativeObj);
        Mat_to_vector_uchar( bufferConfig_mat, bufferConfig );
        cv::dnn::Net _retval_ = cv::dnn::readNetFromTensorflow( bufferModel, bufferConfig );
        return (jlong) new cv::dnn::Net(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readNetFromTensorflow_13 (JNIEnv*, jclass, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readNetFromTensorflow_13
  (JNIEnv* env, jclass , jlong bufferModel_mat_nativeObj)
{
    static const char method_name[] = "dnn::readNetFromTensorflow_13()";
    try {
        LOGD("%s", method_name);
        std::vector<uchar> bufferModel;
        Mat& bufferModel_mat = *((Mat*)bufferModel_mat_nativeObj);
        Mat_to_vector_uchar( bufferModel_mat, bufferModel );
        cv::dnn::Net _retval_ = cv::dnn::readNetFromTensorflow( bufferModel );
        return (jlong) new cv::dnn::Net(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Net cv::dnn::readNetFromTorch(String model, bool isBinary = true, bool evaluate = true)
//



JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readNetFromTorch_10 (JNIEnv*, jclass, jstring, jboolean, jboolean);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readNetFromTorch_10
  (JNIEnv* env, jclass , jstring model, jboolean isBinary, jboolean evaluate)
{
    static const char method_name[] = "dnn::readNetFromTorch_10()";
    try {
        LOGD("%s", method_name);
        const char* utf_model = env->GetStringUTFChars(model, 0); String n_model( utf_model ? utf_model : "" ); env->ReleaseStringUTFChars(model, utf_model);
        cv::dnn::Net _retval_ = cv::dnn::readNetFromTorch( n_model, (bool)isBinary, (bool)evaluate );
        return (jlong) new cv::dnn::Net(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readNetFromTorch_11 (JNIEnv*, jclass, jstring, jboolean);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readNetFromTorch_11
  (JNIEnv* env, jclass , jstring model, jboolean isBinary)
{
    static const char method_name[] = "dnn::readNetFromTorch_11()";
    try {
        LOGD("%s", method_name);
        const char* utf_model = env->GetStringUTFChars(model, 0); String n_model( utf_model ? utf_model : "" ); env->ReleaseStringUTFChars(model, utf_model);
        cv::dnn::Net _retval_ = cv::dnn::readNetFromTorch( n_model, (bool)isBinary );
        return (jlong) new cv::dnn::Net(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}





JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readNetFromTorch_12 (JNIEnv*, jclass, jstring);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Dnn_readNetFromTorch_12
  (JNIEnv* env, jclass , jstring model)
{
    static const char method_name[] = "dnn::readNetFromTorch_12()";
    try {
        LOGD("%s", method_name);
        const char* utf_model = env->GetStringUTFChars(model, 0); String n_model( utf_model ? utf_model : "" ); env->ReleaseStringUTFChars(model, utf_model);
        cv::dnn::Net _retval_ = cv::dnn::readNetFromTorch( n_model );
        return (jlong) new cv::dnn::Net(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  String cv::dnn::getInferenceEngineBackendType()
//



JNIEXPORT jstring JNICALL Java_org_opencv_dnn_Dnn_getInferenceEngineBackendType_10 (JNIEnv*, jclass);

JNIEXPORT jstring JNICALL Java_org_opencv_dnn_Dnn_getInferenceEngineBackendType_10
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "dnn::getInferenceEngineBackendType_10()";
    try {
        LOGD("%s", method_name);
        cv::String _retval_ = cv::dnn::getInferenceEngineBackendType();
        return env->NewStringUTF(_retval_.c_str());
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return env->NewStringUTF("");
}



//
//  String cv::dnn::getInferenceEngineVPUType()
//



JNIEXPORT jstring JNICALL Java_org_opencv_dnn_Dnn_getInferenceEngineVPUType_10 (JNIEnv*, jclass);

JNIEXPORT jstring JNICALL Java_org_opencv_dnn_Dnn_getInferenceEngineVPUType_10
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "dnn::getInferenceEngineVPUType_10()";
    try {
        LOGD("%s", method_name);
        cv::String _retval_ = cv::dnn::getInferenceEngineVPUType();
        return env->NewStringUTF(_retval_.c_str());
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return env->NewStringUTF("");
}



//
//  String cv::dnn::setInferenceEngineBackendType(String newBackendType)
//



JNIEXPORT jstring JNICALL Java_org_opencv_dnn_Dnn_setInferenceEngineBackendType_10 (JNIEnv*, jclass, jstring);

JNIEXPORT jstring JNICALL Java_org_opencv_dnn_Dnn_setInferenceEngineBackendType_10
  (JNIEnv* env, jclass , jstring newBackendType)
{
    static const char method_name[] = "dnn::setInferenceEngineBackendType_10()";
    try {
        LOGD("%s", method_name);
        const char* utf_newBackendType = env->GetStringUTFChars(newBackendType, 0); String n_newBackendType( utf_newBackendType ? utf_newBackendType : "" ); env->ReleaseStringUTFChars(newBackendType, utf_newBackendType);
        cv::String _retval_ = cv::dnn::setInferenceEngineBackendType( n_newBackendType );
        return env->NewStringUTF(_retval_.c_str());
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return env->NewStringUTF("");
}



//
//  vector_Target cv::dnn::getAvailableTargets(dnn_Backend be)
//



JNIEXPORT jobject JNICALL Java_org_opencv_dnn_Dnn_getAvailableTargets_10 (JNIEnv*, jclass, jint);

JNIEXPORT jobject JNICALL Java_org_opencv_dnn_Dnn_getAvailableTargets_10
  (JNIEnv* env, jclass , jint be)
{
    static const char method_name[] = "dnn::getAvailableTargets_10()";
    try {
        LOGD("%s", method_name);
        std::vector< cv::dnn::Target > _ret_val_vector_ = cv::dnn::getAvailableTargets( (cv::dnn::Backend)be );
        return vector_Target_to_List(env, _ret_val_vector_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::dnn::NMSBoxes(vector_Rect2d bboxes, vector_float scores, float score_threshold, float nms_threshold, vector_int& indices, float eta = 1.f, int top_k = 0)
//



JNIEXPORT void JNICALL Java_org_opencv_dnn_Dnn_NMSBoxes_10 (JNIEnv*, jclass, jlong, jlong, jfloat, jfloat, jlong, jfloat, jint);

JNIEXPORT void JNICALL Java_org_opencv_dnn_Dnn_NMSBoxes_10
  (JNIEnv* env, jclass , jlong bboxes_mat_nativeObj, jlong scores_mat_nativeObj, jfloat score_threshold, jfloat nms_threshold, jlong indices_mat_nativeObj, jfloat eta, jint top_k)
{
    static const char method_name[] = "dnn::NMSBoxes_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Rect2d> bboxes;
        Mat& bboxes_mat = *((Mat*)bboxes_mat_nativeObj);
        Mat_to_vector_Rect2d( bboxes_mat, bboxes );
        std::vector<float> scores;
        Mat& scores_mat = *((Mat*)scores_mat_nativeObj);
        Mat_to_vector_float( scores_mat, scores );
        std::vector<int> indices;
        Mat& indices_mat = *((Mat*)indices_mat_nativeObj);
        cv::dnn::NMSBoxes( bboxes, scores, (float)score_threshold, (float)nms_threshold, indices, (float)eta, (int)top_k );
        vector_int_to_Mat( indices, indices_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_dnn_Dnn_NMSBoxes_11 (JNIEnv*, jclass, jlong, jlong, jfloat, jfloat, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_dnn_Dnn_NMSBoxes_11
  (JNIEnv* env, jclass , jlong bboxes_mat_nativeObj, jlong scores_mat_nativeObj, jfloat score_threshold, jfloat nms_threshold, jlong indices_mat_nativeObj, jfloat eta)
{
    static const char method_name[] = "dnn::NMSBoxes_11()";
    try {
        LOGD("%s", method_name);
        std::vector<Rect2d> bboxes;
        Mat& bboxes_mat = *((Mat*)bboxes_mat_nativeObj);
        Mat_to_vector_Rect2d( bboxes_mat, bboxes );
        std::vector<float> scores;
        Mat& scores_mat = *((Mat*)scores_mat_nativeObj);
        Mat_to_vector_float( scores_mat, scores );
        std::vector<int> indices;
        Mat& indices_mat = *((Mat*)indices_mat_nativeObj);
        cv::dnn::NMSBoxes( bboxes, scores, (float)score_threshold, (float)nms_threshold, indices, (float)eta );
        vector_int_to_Mat( indices, indices_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_dnn_Dnn_NMSBoxes_12 (JNIEnv*, jclass, jlong, jlong, jfloat, jfloat, jlong);

JNIEXPORT void JNICALL Java_org_opencv_dnn_Dnn_NMSBoxes_12
  (JNIEnv* env, jclass , jlong bboxes_mat_nativeObj, jlong scores_mat_nativeObj, jfloat score_threshold, jfloat nms_threshold, jlong indices_mat_nativeObj)
{
    static const char method_name[] = "dnn::NMSBoxes_12()";
    try {
        LOGD("%s", method_name);
        std::vector<Rect2d> bboxes;
        Mat& bboxes_mat = *((Mat*)bboxes_mat_nativeObj);
        Mat_to_vector_Rect2d( bboxes_mat, bboxes );
        std::vector<float> scores;
        Mat& scores_mat = *((Mat*)scores_mat_nativeObj);
        Mat_to_vector_float( scores_mat, scores );
        std::vector<int> indices;
        Mat& indices_mat = *((Mat*)indices_mat_nativeObj);
        cv::dnn::NMSBoxes( bboxes, scores, (float)score_threshold, (float)nms_threshold, indices );
        vector_int_to_Mat( indices, indices_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::dnn::NMSBoxes(vector_RotatedRect bboxes, vector_float scores, float score_threshold, float nms_threshold, vector_int& indices, float eta = 1.f, int top_k = 0)
//



JNIEXPORT void JNICALL Java_org_opencv_dnn_Dnn_NMSBoxesRotated_10 (JNIEnv*, jclass, jlong, jlong, jfloat, jfloat, jlong, jfloat, jint);

JNIEXPORT void JNICALL Java_org_opencv_dnn_Dnn_NMSBoxesRotated_10
  (JNIEnv* env, jclass , jlong bboxes_mat_nativeObj, jlong scores_mat_nativeObj, jfloat score_threshold, jfloat nms_threshold, jlong indices_mat_nativeObj, jfloat eta, jint top_k)
{
    static const char method_name[] = "dnn::NMSBoxesRotated_10()";
    try {
        LOGD("%s", method_name);
        std::vector< RotatedRect > bboxes;
        Mat& bboxes_mat = *((Mat*)bboxes_mat_nativeObj);
        Mat_to_vector_RotatedRect( bboxes_mat, bboxes );
        std::vector<float> scores;
        Mat& scores_mat = *((Mat*)scores_mat_nativeObj);
        Mat_to_vector_float( scores_mat, scores );
        std::vector<int> indices;
        Mat& indices_mat = *((Mat*)indices_mat_nativeObj);
        cv::dnn::NMSBoxes( bboxes, scores, (float)score_threshold, (float)nms_threshold, indices, (float)eta, (int)top_k );
        vector_int_to_Mat( indices, indices_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_dnn_Dnn_NMSBoxesRotated_11 (JNIEnv*, jclass, jlong, jlong, jfloat, jfloat, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_dnn_Dnn_NMSBoxesRotated_11
  (JNIEnv* env, jclass , jlong bboxes_mat_nativeObj, jlong scores_mat_nativeObj, jfloat score_threshold, jfloat nms_threshold, jlong indices_mat_nativeObj, jfloat eta)
{
    static const char method_name[] = "dnn::NMSBoxesRotated_11()";
    try {
        LOGD("%s", method_name);
        std::vector< RotatedRect > bboxes;
        Mat& bboxes_mat = *((Mat*)bboxes_mat_nativeObj);
        Mat_to_vector_RotatedRect( bboxes_mat, bboxes );
        std::vector<float> scores;
        Mat& scores_mat = *((Mat*)scores_mat_nativeObj);
        Mat_to_vector_float( scores_mat, scores );
        std::vector<int> indices;
        Mat& indices_mat = *((Mat*)indices_mat_nativeObj);
        cv::dnn::NMSBoxes( bboxes, scores, (float)score_threshold, (float)nms_threshold, indices, (float)eta );
        vector_int_to_Mat( indices, indices_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_dnn_Dnn_NMSBoxesRotated_12 (JNIEnv*, jclass, jlong, jlong, jfloat, jfloat, jlong);

JNIEXPORT void JNICALL Java_org_opencv_dnn_Dnn_NMSBoxesRotated_12
  (JNIEnv* env, jclass , jlong bboxes_mat_nativeObj, jlong scores_mat_nativeObj, jfloat score_threshold, jfloat nms_threshold, jlong indices_mat_nativeObj)
{
    static const char method_name[] = "dnn::NMSBoxesRotated_12()";
    try {
        LOGD("%s", method_name);
        std::vector< RotatedRect > bboxes;
        Mat& bboxes_mat = *((Mat*)bboxes_mat_nativeObj);
        Mat_to_vector_RotatedRect( bboxes_mat, bboxes );
        std::vector<float> scores;
        Mat& scores_mat = *((Mat*)scores_mat_nativeObj);
        Mat_to_vector_float( scores_mat, scores );
        std::vector<int> indices;
        Mat& indices_mat = *((Mat*)indices_mat_nativeObj);
        cv::dnn::NMSBoxes( bboxes, scores, (float)score_threshold, (float)nms_threshold, indices );
        vector_int_to_Mat( indices, indices_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::dnn::imagesFromBlob(Mat blob_, vector_Mat& images_)
//



JNIEXPORT void JNICALL Java_org_opencv_dnn_Dnn_imagesFromBlob_10 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_dnn_Dnn_imagesFromBlob_10
  (JNIEnv* env, jclass , jlong blob__nativeObj, jlong images__mat_nativeObj)
{
    static const char method_name[] = "dnn::imagesFromBlob_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> images_;
        Mat& images__mat = *((Mat*)images__mat_nativeObj);
        Mat& blob_ = *((Mat*)blob__nativeObj);
        cv::dnn::imagesFromBlob( blob_, images_ );
        vector_Mat_to_Mat( images_, images__mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::dnn::resetMyriadDevice()
//



JNIEXPORT void JNICALL Java_org_opencv_dnn_Dnn_resetMyriadDevice_10 (JNIEnv*, jclass);

JNIEXPORT void JNICALL Java_org_opencv_dnn_Dnn_resetMyriadDevice_10
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "dnn::resetMyriadDevice_10()";
    try {
        LOGD("%s", method_name);
        cv::dnn::resetMyriadDevice();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::dnn::shrinkCaffeModel(String src, String dst, vector_String layersTypes = std::vector<String>())
//



JNIEXPORT void JNICALL Java_org_opencv_dnn_Dnn_shrinkCaffeModel_10 (JNIEnv*, jclass, jstring, jstring, jobject);

JNIEXPORT void JNICALL Java_org_opencv_dnn_Dnn_shrinkCaffeModel_10
  (JNIEnv* env, jclass , jstring src, jstring dst, jobject layersTypes_list)
{
    static const char method_name[] = "dnn::shrinkCaffeModel_10()";
    try {
        LOGD("%s", method_name);
        std::vector< String > layersTypes;
        layersTypes = List_to_vector_String(env, layersTypes_list);
        const char* utf_src = env->GetStringUTFChars(src, 0); String n_src( utf_src ? utf_src : "" ); env->ReleaseStringUTFChars(src, utf_src);
        const char* utf_dst = env->GetStringUTFChars(dst, 0); String n_dst( utf_dst ? utf_dst : "" ); env->ReleaseStringUTFChars(dst, utf_dst);
        cv::dnn::shrinkCaffeModel( n_src, n_dst, layersTypes );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}





JNIEXPORT void JNICALL Java_org_opencv_dnn_Dnn_shrinkCaffeModel_11 (JNIEnv*, jclass, jstring, jstring);

JNIEXPORT void JNICALL Java_org_opencv_dnn_Dnn_shrinkCaffeModel_11
  (JNIEnv* env, jclass , jstring src, jstring dst)
{
    static const char method_name[] = "dnn::shrinkCaffeModel_11()";
    try {
        LOGD("%s", method_name);
        const char* utf_src = env->GetStringUTFChars(src, 0); String n_src( utf_src ? utf_src : "" ); env->ReleaseStringUTFChars(src, utf_src);
        const char* utf_dst = env->GetStringUTFChars(dst, 0); String n_dst( utf_dst ? utf_dst : "" ); env->ReleaseStringUTFChars(dst, utf_dst);
        cv::dnn::shrinkCaffeModel( n_src, n_dst );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::dnn::writeTextGraph(String model, String output)
//



JNIEXPORT void JNICALL Java_org_opencv_dnn_Dnn_writeTextGraph_10 (JNIEnv*, jclass, jstring, jstring);

JNIEXPORT void JNICALL Java_org_opencv_dnn_Dnn_writeTextGraph_10
  (JNIEnv* env, jclass , jstring model, jstring output)
{
    static const char method_name[] = "dnn::writeTextGraph_10()";
    try {
        LOGD("%s", method_name);
        const char* utf_model = env->GetStringUTFChars(model, 0); String n_model( utf_model ? utf_model : "" ); env->ReleaseStringUTFChars(model, utf_model);
        const char* utf_output = env->GetStringUTFChars(output, 0); String n_output( utf_output ? utf_output : "" ); env->ReleaseStringUTFChars(output, utf_output);
        cv::dnn::writeTextGraph( n_model, n_output );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//   cv::dnn::SegmentationModel::SegmentationModel(Net network)
//

using namespace cv::dnn;

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_SegmentationModel_SegmentationModel_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_SegmentationModel_SegmentationModel_10
  (JNIEnv* env, jclass , jlong network_nativeObj)
{
    static const char method_name[] = "dnn::SegmentationModel_10()";
    try {
        LOGD("%s", method_name);
        cv::dnn::SegmentationModel* _retval_ = new cv::dnn::SegmentationModel( (*(cv::dnn::Net*)network_nativeObj) );
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//   cv::dnn::SegmentationModel::SegmentationModel(String model, String config = "")
//

using namespace cv::dnn;

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_SegmentationModel_SegmentationModel_11 (JNIEnv*, jclass, jstring, jstring);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_SegmentationModel_SegmentationModel_11
  (JNIEnv* env, jclass , jstring model, jstring config)
{
    static const char method_name[] = "dnn::SegmentationModel_11()";
    try {
        LOGD("%s", method_name);
        const char* utf_model = env->GetStringUTFChars(model, 0); String n_model( utf_model ? utf_model : "" ); env->ReleaseStringUTFChars(model, utf_model);
        const char* utf_config = env->GetStringUTFChars(config, 0); String n_config( utf_config ? utf_config : "" ); env->ReleaseStringUTFChars(config, utf_config);
        cv::dnn::SegmentationModel* _retval_ = new cv::dnn::SegmentationModel( n_model, n_config );
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv::dnn;

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_SegmentationModel_SegmentationModel_12 (JNIEnv*, jclass, jstring);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_SegmentationModel_SegmentationModel_12
  (JNIEnv* env, jclass , jstring model)
{
    static const char method_name[] = "dnn::SegmentationModel_12()";
    try {
        LOGD("%s", method_name);
        const char* utf_model = env->GetStringUTFChars(model, 0); String n_model( utf_model ? utf_model : "" ); env->ReleaseStringUTFChars(model, utf_model);
        cv::dnn::SegmentationModel* _retval_ = new cv::dnn::SegmentationModel( n_model );
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::dnn::SegmentationModel::segment(Mat frame, Mat& mask)
//

using namespace cv::dnn;

JNIEXPORT void JNICALL Java_org_opencv_dnn_SegmentationModel_segment_10 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_dnn_SegmentationModel_segment_10
  (JNIEnv* env, jclass , jlong self, jlong frame_nativeObj, jlong mask_nativeObj)
{
    static const char method_name[] = "dnn::segment_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::dnn::SegmentationModel>* me = (Ptr<cv::dnn::SegmentationModel>*) self; //TODO: check for NULL
        Mat& frame = *((Mat*)frame_nativeObj);
        Mat& mask = *((Mat*)mask_nativeObj);
        (*me)->segment( frame, mask );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void Ptr<cv::dnn::SegmentationModel>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_dnn_SegmentationModel_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_dnn_SegmentationModel_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::dnn::SegmentationModel>*) self;
}


//
//   cv::dnn::KeypointsModel::KeypointsModel(Net network)
//

using namespace cv::dnn;

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_KeypointsModel_KeypointsModel_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_KeypointsModel_KeypointsModel_10
  (JNIEnv* env, jclass , jlong network_nativeObj)
{
    static const char method_name[] = "dnn::KeypointsModel_10()";
    try {
        LOGD("%s", method_name);
        cv::dnn::KeypointsModel* _retval_ = new cv::dnn::KeypointsModel( (*(cv::dnn::Net*)network_nativeObj) );
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//   cv::dnn::KeypointsModel::KeypointsModel(String model, String config = "")
//

using namespace cv::dnn;

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_KeypointsModel_KeypointsModel_11 (JNIEnv*, jclass, jstring, jstring);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_KeypointsModel_KeypointsModel_11
  (JNIEnv* env, jclass , jstring model, jstring config)
{
    static const char method_name[] = "dnn::KeypointsModel_11()";
    try {
        LOGD("%s", method_name);
        const char* utf_model = env->GetStringUTFChars(model, 0); String n_model( utf_model ? utf_model : "" ); env->ReleaseStringUTFChars(model, utf_model);
        const char* utf_config = env->GetStringUTFChars(config, 0); String n_config( utf_config ? utf_config : "" ); env->ReleaseStringUTFChars(config, utf_config);
        cv::dnn::KeypointsModel* _retval_ = new cv::dnn::KeypointsModel( n_model, n_config );
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv::dnn;

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_KeypointsModel_KeypointsModel_12 (JNIEnv*, jclass, jstring);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_KeypointsModel_KeypointsModel_12
  (JNIEnv* env, jclass , jstring model)
{
    static const char method_name[] = "dnn::KeypointsModel_12()";
    try {
        LOGD("%s", method_name);
        const char* utf_model = env->GetStringUTFChars(model, 0); String n_model( utf_model ? utf_model : "" ); env->ReleaseStringUTFChars(model, utf_model);
        cv::dnn::KeypointsModel* _retval_ = new cv::dnn::KeypointsModel( n_model );
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  vector_Point2f cv::dnn::KeypointsModel::estimate(Mat frame, float thresh = 0.5)
//

using namespace cv::dnn;

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_KeypointsModel_estimate_10 (JNIEnv*, jclass, jlong, jlong, jfloat);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_KeypointsModel_estimate_10
  (JNIEnv* env, jclass , jlong self, jlong frame_nativeObj, jfloat thresh)
{
    static const char method_name[] = "dnn::estimate_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::dnn::KeypointsModel>* me = (Ptr<cv::dnn::KeypointsModel>*) self; //TODO: check for NULL
        Mat& frame = *((Mat*)frame_nativeObj);
        std::vector<Point2f> _ret_val_vector_ = (*me)->estimate( frame, (float)thresh );
        Mat* _retval_ = new Mat();
        vector_Point2f_to_Mat(_ret_val_vector_, *_retval_);
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv::dnn;

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_KeypointsModel_estimate_11 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_KeypointsModel_estimate_11
  (JNIEnv* env, jclass , jlong self, jlong frame_nativeObj)
{
    static const char method_name[] = "dnn::estimate_11()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::dnn::KeypointsModel>* me = (Ptr<cv::dnn::KeypointsModel>*) self; //TODO: check for NULL
        Mat& frame = *((Mat*)frame_nativeObj);
        std::vector<Point2f> _ret_val_vector_ = (*me)->estimate( frame );
        Mat* _retval_ = new Mat();
        vector_Point2f_to_Mat(_ret_val_vector_, *_retval_);
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  native support for java finalize()
//  static void Ptr<cv::dnn::KeypointsModel>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_dnn_KeypointsModel_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_dnn_KeypointsModel_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::dnn::KeypointsModel>*) self;
}


//
//   cv::dnn::DictValue::DictValue(String s)
//

using namespace cv::dnn;

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_DictValue_DictValue_10 (JNIEnv*, jclass, jstring);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_DictValue_DictValue_10
  (JNIEnv* env, jclass , jstring s)
{
    static const char method_name[] = "dnn::DictValue_10()";
    try {
        LOGD("%s", method_name);
        const char* utf_s = env->GetStringUTFChars(s, 0); String n_s( utf_s ? utf_s : "" ); env->ReleaseStringUTFChars(s, utf_s);
        cv::dnn::DictValue* _retval_ = new cv::dnn::DictValue( n_s );
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//   cv::dnn::DictValue::DictValue(double p)
//

using namespace cv::dnn;

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_DictValue_DictValue_11 (JNIEnv*, jclass, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_DictValue_DictValue_11
  (JNIEnv* env, jclass , jdouble p)
{
    static const char method_name[] = "dnn::DictValue_11()";
    try {
        LOGD("%s", method_name);
        cv::dnn::DictValue* _retval_ = new cv::dnn::DictValue( (double)p );
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//   cv::dnn::DictValue::DictValue(int i)
//

using namespace cv::dnn;

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_DictValue_DictValue_12 (JNIEnv*, jclass, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_DictValue_DictValue_12
  (JNIEnv* env, jclass , jint i)
{
    static const char method_name[] = "dnn::DictValue_12()";
    try {
        LOGD("%s", method_name);
        cv::dnn::DictValue* _retval_ = new cv::dnn::DictValue( (int)i );
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  String cv::dnn::DictValue::getStringValue(int idx = -1)
//

using namespace cv::dnn;

JNIEXPORT jstring JNICALL Java_org_opencv_dnn_DictValue_getStringValue_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT jstring JNICALL Java_org_opencv_dnn_DictValue_getStringValue_10
  (JNIEnv* env, jclass , jlong self, jint idx)
{
    static const char method_name[] = "dnn::getStringValue_10()";
    try {
        LOGD("%s", method_name);
        cv::dnn::DictValue* me = (cv::dnn::DictValue*) self; //TODO: check for NULL
        cv::String _retval_ = me->getStringValue( (int)idx );
        return env->NewStringUTF(_retval_.c_str());
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return env->NewStringUTF("");
}



using namespace cv::dnn;

JNIEXPORT jstring JNICALL Java_org_opencv_dnn_DictValue_getStringValue_11 (JNIEnv*, jclass, jlong);

JNIEXPORT jstring JNICALL Java_org_opencv_dnn_DictValue_getStringValue_11
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "dnn::getStringValue_11()";
    try {
        LOGD("%s", method_name);
        cv::dnn::DictValue* me = (cv::dnn::DictValue*) self; //TODO: check for NULL
        cv::String _retval_ = me->getStringValue();
        return env->NewStringUTF(_retval_.c_str());
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return env->NewStringUTF("");
}



//
//  bool cv::dnn::DictValue::isInt()
//

using namespace cv::dnn;

JNIEXPORT jboolean JNICALL Java_org_opencv_dnn_DictValue_isInt_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_dnn_DictValue_isInt_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "dnn::isInt_10()";
    try {
        LOGD("%s", method_name);
        cv::dnn::DictValue* me = (cv::dnn::DictValue*) self; //TODO: check for NULL
        return me->isInt();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  bool cv::dnn::DictValue::isReal()
//

using namespace cv::dnn;

JNIEXPORT jboolean JNICALL Java_org_opencv_dnn_DictValue_isReal_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_dnn_DictValue_isReal_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "dnn::isReal_10()";
    try {
        LOGD("%s", method_name);
        cv::dnn::DictValue* me = (cv::dnn::DictValue*) self; //TODO: check for NULL
        return me->isReal();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  bool cv::dnn::DictValue::isString()
//

using namespace cv::dnn;

JNIEXPORT jboolean JNICALL Java_org_opencv_dnn_DictValue_isString_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_dnn_DictValue_isString_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "dnn::isString_10()";
    try {
        LOGD("%s", method_name);
        cv::dnn::DictValue* me = (cv::dnn::DictValue*) self; //TODO: check for NULL
        return me->isString();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::dnn::DictValue::getRealValue(int idx = -1)
//

using namespace cv::dnn;

JNIEXPORT jdouble JNICALL Java_org_opencv_dnn_DictValue_getRealValue_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT jdouble JNICALL Java_org_opencv_dnn_DictValue_getRealValue_10
  (JNIEnv* env, jclass , jlong self, jint idx)
{
    static const char method_name[] = "dnn::getRealValue_10()";
    try {
        LOGD("%s", method_name);
        cv::dnn::DictValue* me = (cv::dnn::DictValue*) self; //TODO: check for NULL
        return me->getRealValue( (int)idx );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv::dnn;

JNIEXPORT jdouble JNICALL Java_org_opencv_dnn_DictValue_getRealValue_11 (JNIEnv*, jclass, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_dnn_DictValue_getRealValue_11
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "dnn::getRealValue_11()";
    try {
        LOGD("%s", method_name);
        cv::dnn::DictValue* me = (cv::dnn::DictValue*) self; //TODO: check for NULL
        return me->getRealValue();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::dnn::DictValue::getIntValue(int idx = -1)
//

using namespace cv::dnn;

JNIEXPORT jint JNICALL Java_org_opencv_dnn_DictValue_getIntValue_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT jint JNICALL Java_org_opencv_dnn_DictValue_getIntValue_10
  (JNIEnv* env, jclass , jlong self, jint idx)
{
    static const char method_name[] = "dnn::getIntValue_10()";
    try {
        LOGD("%s", method_name);
        cv::dnn::DictValue* me = (cv::dnn::DictValue*) self; //TODO: check for NULL
        return me->getIntValue( (int)idx );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv::dnn;

JNIEXPORT jint JNICALL Java_org_opencv_dnn_DictValue_getIntValue_11 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_dnn_DictValue_getIntValue_11
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "dnn::getIntValue_11()";
    try {
        LOGD("%s", method_name);
        cv::dnn::DictValue* me = (cv::dnn::DictValue*) self; //TODO: check for NULL
        return me->getIntValue();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  native support for java finalize()
//  static void cv::dnn::DictValue::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_dnn_DictValue_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_dnn_DictValue_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (cv::dnn::DictValue*) self;
}


//
//   cv::dnn::ClassificationModel::ClassificationModel(Net network)
//

using namespace cv::dnn;

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_ClassificationModel_ClassificationModel_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_ClassificationModel_ClassificationModel_10
  (JNIEnv* env, jclass , jlong network_nativeObj)
{
    static const char method_name[] = "dnn::ClassificationModel_10()";
    try {
        LOGD("%s", method_name);
        cv::dnn::ClassificationModel* _retval_ = new cv::dnn::ClassificationModel( (*(cv::dnn::Net*)network_nativeObj) );
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//   cv::dnn::ClassificationModel::ClassificationModel(String model, String config = "")
//

using namespace cv::dnn;

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_ClassificationModel_ClassificationModel_11 (JNIEnv*, jclass, jstring, jstring);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_ClassificationModel_ClassificationModel_11
  (JNIEnv* env, jclass , jstring model, jstring config)
{
    static const char method_name[] = "dnn::ClassificationModel_11()";
    try {
        LOGD("%s", method_name);
        const char* utf_model = env->GetStringUTFChars(model, 0); String n_model( utf_model ? utf_model : "" ); env->ReleaseStringUTFChars(model, utf_model);
        const char* utf_config = env->GetStringUTFChars(config, 0); String n_config( utf_config ? utf_config : "" ); env->ReleaseStringUTFChars(config, utf_config);
        cv::dnn::ClassificationModel* _retval_ = new cv::dnn::ClassificationModel( n_model, n_config );
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv::dnn;

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_ClassificationModel_ClassificationModel_12 (JNIEnv*, jclass, jstring);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_ClassificationModel_ClassificationModel_12
  (JNIEnv* env, jclass , jstring model)
{
    static const char method_name[] = "dnn::ClassificationModel_12()";
    try {
        LOGD("%s", method_name);
        const char* utf_model = env->GetStringUTFChars(model, 0); String n_model( utf_model ? utf_model : "" ); env->ReleaseStringUTFChars(model, utf_model);
        cv::dnn::ClassificationModel* _retval_ = new cv::dnn::ClassificationModel( n_model );
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::dnn::ClassificationModel::classify(Mat frame, int& classId, float& conf)
//

using namespace cv::dnn;

JNIEXPORT void JNICALL Java_org_opencv_dnn_ClassificationModel_classify_10 (JNIEnv*, jclass, jlong, jlong, jdoubleArray, jdoubleArray);

JNIEXPORT void JNICALL Java_org_opencv_dnn_ClassificationModel_classify_10
  (JNIEnv* env, jclass , jlong self, jlong frame_nativeObj, jdoubleArray classId_out, jdoubleArray conf_out)
{
    static const char method_name[] = "dnn::classify_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::dnn::ClassificationModel>* me = (Ptr<cv::dnn::ClassificationModel>*) self; //TODO: check for NULL
        Mat& frame = *((Mat*)frame_nativeObj);
        int classId;
        float conf;
        (*me)->classify( frame, classId, conf );
        jdouble tmp_classId[1] = {(jdouble)classId}; env->SetDoubleArrayRegion(classId_out, 0, 1, tmp_classId);
        jdouble tmp_conf[1] = {(jdouble)conf}; env->SetDoubleArrayRegion(conf_out, 0, 1, tmp_conf);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void Ptr<cv::dnn::ClassificationModel>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_dnn_ClassificationModel_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_dnn_ClassificationModel_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::dnn::ClassificationModel>*) self;
}


//
//   cv::dnn::DetectionModel::DetectionModel(Net network)
//

using namespace cv::dnn;

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_DetectionModel_DetectionModel_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_DetectionModel_DetectionModel_10
  (JNIEnv* env, jclass , jlong network_nativeObj)
{
    static const char method_name[] = "dnn::DetectionModel_10()";
    try {
        LOGD("%s", method_name);
        cv::dnn::DetectionModel* _retval_ = new cv::dnn::DetectionModel( (*(cv::dnn::Net*)network_nativeObj) );
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//   cv::dnn::DetectionModel::DetectionModel(String model, String config = "")
//

using namespace cv::dnn;

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_DetectionModel_DetectionModel_11 (JNIEnv*, jclass, jstring, jstring);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_DetectionModel_DetectionModel_11
  (JNIEnv* env, jclass , jstring model, jstring config)
{
    static const char method_name[] = "dnn::DetectionModel_11()";
    try {
        LOGD("%s", method_name);
        const char* utf_model = env->GetStringUTFChars(model, 0); String n_model( utf_model ? utf_model : "" ); env->ReleaseStringUTFChars(model, utf_model);
        const char* utf_config = env->GetStringUTFChars(config, 0); String n_config( utf_config ? utf_config : "" ); env->ReleaseStringUTFChars(config, utf_config);
        cv::dnn::DetectionModel* _retval_ = new cv::dnn::DetectionModel( n_model, n_config );
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv::dnn;

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_DetectionModel_DetectionModel_12 (JNIEnv*, jclass, jstring);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_DetectionModel_DetectionModel_12
  (JNIEnv* env, jclass , jstring model)
{
    static const char method_name[] = "dnn::DetectionModel_12()";
    try {
        LOGD("%s", method_name);
        const char* utf_model = env->GetStringUTFChars(model, 0); String n_model( utf_model ? utf_model : "" ); env->ReleaseStringUTFChars(model, utf_model);
        cv::dnn::DetectionModel* _retval_ = new cv::dnn::DetectionModel( n_model );
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::dnn::DetectionModel::detect(Mat frame, vector_int& classIds, vector_float& confidences, vector_Rect& boxes, float confThreshold = 0.5f, float nmsThreshold = 0.0f)
//

using namespace cv::dnn;

JNIEXPORT void JNICALL Java_org_opencv_dnn_DetectionModel_detect_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jfloat, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_dnn_DetectionModel_detect_10
  (JNIEnv* env, jclass , jlong self, jlong frame_nativeObj, jlong classIds_mat_nativeObj, jlong confidences_mat_nativeObj, jlong boxes_mat_nativeObj, jfloat confThreshold, jfloat nmsThreshold)
{
    static const char method_name[] = "dnn::detect_10()";
    try {
        LOGD("%s", method_name);
        std::vector<int> classIds;
        Mat& classIds_mat = *((Mat*)classIds_mat_nativeObj);
        std::vector<float> confidences;
        Mat& confidences_mat = *((Mat*)confidences_mat_nativeObj);
        std::vector<Rect> boxes;
        Mat& boxes_mat = *((Mat*)boxes_mat_nativeObj);
        Ptr<cv::dnn::DetectionModel>* me = (Ptr<cv::dnn::DetectionModel>*) self; //TODO: check for NULL
        Mat& frame = *((Mat*)frame_nativeObj);
        (*me)->detect( frame, classIds, confidences, boxes, (float)confThreshold, (float)nmsThreshold );
        vector_int_to_Mat( classIds, classIds_mat );
        vector_float_to_Mat( confidences, confidences_mat );
        vector_Rect_to_Mat( boxes, boxes_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv::dnn;

JNIEXPORT void JNICALL Java_org_opencv_dnn_DetectionModel_detect_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_dnn_DetectionModel_detect_11
  (JNIEnv* env, jclass , jlong self, jlong frame_nativeObj, jlong classIds_mat_nativeObj, jlong confidences_mat_nativeObj, jlong boxes_mat_nativeObj, jfloat confThreshold)
{
    static const char method_name[] = "dnn::detect_11()";
    try {
        LOGD("%s", method_name);
        std::vector<int> classIds;
        Mat& classIds_mat = *((Mat*)classIds_mat_nativeObj);
        std::vector<float> confidences;
        Mat& confidences_mat = *((Mat*)confidences_mat_nativeObj);
        std::vector<Rect> boxes;
        Mat& boxes_mat = *((Mat*)boxes_mat_nativeObj);
        Ptr<cv::dnn::DetectionModel>* me = (Ptr<cv::dnn::DetectionModel>*) self; //TODO: check for NULL
        Mat& frame = *((Mat*)frame_nativeObj);
        (*me)->detect( frame, classIds, confidences, boxes, (float)confThreshold );
        vector_int_to_Mat( classIds, classIds_mat );
        vector_float_to_Mat( confidences, confidences_mat );
        vector_Rect_to_Mat( boxes, boxes_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv::dnn;

JNIEXPORT void JNICALL Java_org_opencv_dnn_DetectionModel_detect_12 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_dnn_DetectionModel_detect_12
  (JNIEnv* env, jclass , jlong self, jlong frame_nativeObj, jlong classIds_mat_nativeObj, jlong confidences_mat_nativeObj, jlong boxes_mat_nativeObj)
{
    static const char method_name[] = "dnn::detect_12()";
    try {
        LOGD("%s", method_name);
        std::vector<int> classIds;
        Mat& classIds_mat = *((Mat*)classIds_mat_nativeObj);
        std::vector<float> confidences;
        Mat& confidences_mat = *((Mat*)confidences_mat_nativeObj);
        std::vector<Rect> boxes;
        Mat& boxes_mat = *((Mat*)boxes_mat_nativeObj);
        Ptr<cv::dnn::DetectionModel>* me = (Ptr<cv::dnn::DetectionModel>*) self; //TODO: check for NULL
        Mat& frame = *((Mat*)frame_nativeObj);
        (*me)->detect( frame, classIds, confidences, boxes );
        vector_int_to_Mat( classIds, classIds_mat );
        vector_float_to_Mat( confidences, confidences_mat );
        vector_Rect_to_Mat( boxes, boxes_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void Ptr<cv::dnn::DetectionModel>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_dnn_DetectionModel_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_dnn_DetectionModel_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::dnn::DetectionModel>*) self;
}


//
//   cv::dnn::Model::Model(Net network)
//

using namespace cv::dnn;

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Model_Model_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Model_Model_10
  (JNIEnv* env, jclass , jlong network_nativeObj)
{
    static const char method_name[] = "dnn::Model_10()";
    try {
        LOGD("%s", method_name);
        cv::dnn::Model* _retval_ = new cv::dnn::Model( (*(cv::dnn::Net*)network_nativeObj) );
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//   cv::dnn::Model::Model(String model, String config = "")
//

using namespace cv::dnn;

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Model_Model_11 (JNIEnv*, jclass, jstring, jstring);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Model_Model_11
  (JNIEnv* env, jclass , jstring model, jstring config)
{
    static const char method_name[] = "dnn::Model_11()";
    try {
        LOGD("%s", method_name);
        const char* utf_model = env->GetStringUTFChars(model, 0); String n_model( utf_model ? utf_model : "" ); env->ReleaseStringUTFChars(model, utf_model);
        const char* utf_config = env->GetStringUTFChars(config, 0); String n_config( utf_config ? utf_config : "" ); env->ReleaseStringUTFChars(config, utf_config);
        cv::dnn::Model* _retval_ = new cv::dnn::Model( n_model, n_config );
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv::dnn;

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Model_Model_12 (JNIEnv*, jclass, jstring);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Model_Model_12
  (JNIEnv* env, jclass , jstring model)
{
    static const char method_name[] = "dnn::Model_12()";
    try {
        LOGD("%s", method_name);
        const char* utf_model = env->GetStringUTFChars(model, 0); String n_model( utf_model ? utf_model : "" ); env->ReleaseStringUTFChars(model, utf_model);
        cv::dnn::Model* _retval_ = new cv::dnn::Model( n_model );
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Model cv::dnn::Model::setInputCrop(bool crop)
//

using namespace cv::dnn;

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Model_setInputCrop_10 (JNIEnv*, jclass, jlong, jboolean);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Model_setInputCrop_10
  (JNIEnv* env, jclass , jlong self, jboolean crop)
{
    static const char method_name[] = "dnn::setInputCrop_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::dnn::Model>* me = (Ptr<cv::dnn::Model>*) self; //TODO: check for NULL
        cv::dnn::Model _retval_ = (*me)->setInputCrop( (bool)crop );
        return (jlong) new cv::dnn::Model(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Model cv::dnn::Model::setInputMean(Scalar mean)
//

using namespace cv::dnn;

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Model_setInputMean_10 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Model_setInputMean_10
  (JNIEnv* env, jclass , jlong self, jdouble mean_val0, jdouble mean_val1, jdouble mean_val2, jdouble mean_val3)
{
    static const char method_name[] = "dnn::setInputMean_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::dnn::Model>* me = (Ptr<cv::dnn::Model>*) self; //TODO: check for NULL
        Scalar mean(mean_val0, mean_val1, mean_val2, mean_val3);
        cv::dnn::Model _retval_ = (*me)->setInputMean( mean );
        return (jlong) new cv::dnn::Model(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Model cv::dnn::Model::setInputScale(double scale)
//

using namespace cv::dnn;

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Model_setInputScale_10 (JNIEnv*, jclass, jlong, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Model_setInputScale_10
  (JNIEnv* env, jclass , jlong self, jdouble scale)
{
    static const char method_name[] = "dnn::setInputScale_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::dnn::Model>* me = (Ptr<cv::dnn::Model>*) self; //TODO: check for NULL
        cv::dnn::Model _retval_ = (*me)->setInputScale( (double)scale );
        return (jlong) new cv::dnn::Model(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Model cv::dnn::Model::setInputSize(Size size)
//

using namespace cv::dnn;

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Model_setInputSize_10 (JNIEnv*, jclass, jlong, jdouble, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Model_setInputSize_10
  (JNIEnv* env, jclass , jlong self, jdouble size_width, jdouble size_height)
{
    static const char method_name[] = "dnn::setInputSize_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::dnn::Model>* me = (Ptr<cv::dnn::Model>*) self; //TODO: check for NULL
        Size size((int)size_width, (int)size_height);
        cv::dnn::Model _retval_ = (*me)->setInputSize( size );
        return (jlong) new cv::dnn::Model(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Model cv::dnn::Model::setInputSize(int width, int height)
//

using namespace cv::dnn;

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Model_setInputSize_11 (JNIEnv*, jclass, jlong, jint, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Model_setInputSize_11
  (JNIEnv* env, jclass , jlong self, jint width, jint height)
{
    static const char method_name[] = "dnn::setInputSize_11()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::dnn::Model>* me = (Ptr<cv::dnn::Model>*) self; //TODO: check for NULL
        cv::dnn::Model _retval_ = (*me)->setInputSize( (int)width, (int)height );
        return (jlong) new cv::dnn::Model(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Model cv::dnn::Model::setInputSwapRB(bool swapRB)
//

using namespace cv::dnn;

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Model_setInputSwapRB_10 (JNIEnv*, jclass, jlong, jboolean);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Model_setInputSwapRB_10
  (JNIEnv* env, jclass , jlong self, jboolean swapRB)
{
    static const char method_name[] = "dnn::setInputSwapRB_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::dnn::Model>* me = (Ptr<cv::dnn::Model>*) self; //TODO: check for NULL
        cv::dnn::Model _retval_ = (*me)->setInputSwapRB( (bool)swapRB );
        return (jlong) new cv::dnn::Model(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::dnn::Model::predict(Mat frame, vector_Mat& outs)
//

using namespace cv::dnn;

JNIEXPORT void JNICALL Java_org_opencv_dnn_Model_predict_10 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_dnn_Model_predict_10
  (JNIEnv* env, jclass , jlong self, jlong frame_nativeObj, jlong outs_mat_nativeObj)
{
    static const char method_name[] = "dnn::predict_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> outs;
        Mat& outs_mat = *((Mat*)outs_mat_nativeObj);
        Ptr<cv::dnn::Model>* me = (Ptr<cv::dnn::Model>*) self; //TODO: check for NULL
        Mat& frame = *((Mat*)frame_nativeObj);
        (*me)->predict( frame, outs );
        vector_Mat_to_Mat( outs, outs_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::dnn::Model::setInputParams(double scale = 1.0, Size size = Size(), Scalar mean = Scalar(), bool swapRB = false, bool crop = false)
//

using namespace cv::dnn;

JNIEXPORT void JNICALL Java_org_opencv_dnn_Model_setInputParams_10 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jboolean, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_dnn_Model_setInputParams_10
  (JNIEnv* env, jclass , jlong self, jdouble scale, jdouble size_width, jdouble size_height, jdouble mean_val0, jdouble mean_val1, jdouble mean_val2, jdouble mean_val3, jboolean swapRB, jboolean crop)
{
    static const char method_name[] = "dnn::setInputParams_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::dnn::Model>* me = (Ptr<cv::dnn::Model>*) self; //TODO: check for NULL
        Size size((int)size_width, (int)size_height);
        Scalar mean(mean_val0, mean_val1, mean_val2, mean_val3);
        (*me)->setInputParams( (double)scale, size, mean, (bool)swapRB, (bool)crop );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv::dnn;

JNIEXPORT void JNICALL Java_org_opencv_dnn_Model_setInputParams_11 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_dnn_Model_setInputParams_11
  (JNIEnv* env, jclass , jlong self, jdouble scale, jdouble size_width, jdouble size_height, jdouble mean_val0, jdouble mean_val1, jdouble mean_val2, jdouble mean_val3, jboolean swapRB)
{
    static const char method_name[] = "dnn::setInputParams_11()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::dnn::Model>* me = (Ptr<cv::dnn::Model>*) self; //TODO: check for NULL
        Size size((int)size_width, (int)size_height);
        Scalar mean(mean_val0, mean_val1, mean_val2, mean_val3);
        (*me)->setInputParams( (double)scale, size, mean, (bool)swapRB );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv::dnn;

JNIEXPORT void JNICALL Java_org_opencv_dnn_Model_setInputParams_12 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_dnn_Model_setInputParams_12
  (JNIEnv* env, jclass , jlong self, jdouble scale, jdouble size_width, jdouble size_height, jdouble mean_val0, jdouble mean_val1, jdouble mean_val2, jdouble mean_val3)
{
    static const char method_name[] = "dnn::setInputParams_12()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::dnn::Model>* me = (Ptr<cv::dnn::Model>*) self; //TODO: check for NULL
        Size size((int)size_width, (int)size_height);
        Scalar mean(mean_val0, mean_val1, mean_val2, mean_val3);
        (*me)->setInputParams( (double)scale, size, mean );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv::dnn;

JNIEXPORT void JNICALL Java_org_opencv_dnn_Model_setInputParams_13 (JNIEnv*, jclass, jlong, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_dnn_Model_setInputParams_13
  (JNIEnv* env, jclass , jlong self, jdouble scale, jdouble size_width, jdouble size_height)
{
    static const char method_name[] = "dnn::setInputParams_13()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::dnn::Model>* me = (Ptr<cv::dnn::Model>*) self; //TODO: check for NULL
        Size size((int)size_width, (int)size_height);
        (*me)->setInputParams( (double)scale, size );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv::dnn;

JNIEXPORT void JNICALL Java_org_opencv_dnn_Model_setInputParams_14 (JNIEnv*, jclass, jlong, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_dnn_Model_setInputParams_14
  (JNIEnv* env, jclass , jlong self, jdouble scale)
{
    static const char method_name[] = "dnn::setInputParams_14()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::dnn::Model>* me = (Ptr<cv::dnn::Model>*) self; //TODO: check for NULL
        (*me)->setInputParams( (double)scale );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv::dnn;

JNIEXPORT void JNICALL Java_org_opencv_dnn_Model_setInputParams_15 (JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_dnn_Model_setInputParams_15
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "dnn::setInputParams_15()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::dnn::Model>* me = (Ptr<cv::dnn::Model>*) self; //TODO: check for NULL
        (*me)->setInputParams();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void Ptr<cv::dnn::Model>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_dnn_Model_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_dnn_Model_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::dnn::Model>*) self;
}


//
//   cv::dnn::Net::Net()
//

using namespace cv::dnn;

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Net_Net_10 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Net_Net_10
  (JNIEnv* env, jclass )
{
    static const char method_name[] = "dnn::Net_10()";
    try {
        LOGD("%s", method_name);
        cv::dnn::Net* _retval_ = new cv::dnn::Net();
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Mat cv::dnn::Net::forward(String outputName = String())
//

using namespace cv::dnn;

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Net_forward_10 (JNIEnv*, jclass, jlong, jstring);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Net_forward_10
  (JNIEnv* env, jclass , jlong self, jstring outputName)
{
    static const char method_name[] = "dnn::forward_10()";
    try {
        LOGD("%s", method_name);
        cv::dnn::Net* me = (cv::dnn::Net*) self; //TODO: check for NULL
        const char* utf_outputName = env->GetStringUTFChars(outputName, 0); String n_outputName( utf_outputName ? utf_outputName : "" ); env->ReleaseStringUTFChars(outputName, utf_outputName);
        ::Mat _retval_ = me->forward( n_outputName );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv::dnn;

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Net_forward_11 (JNIEnv*, jclass, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Net_forward_11
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "dnn::forward_11()";
    try {
        LOGD("%s", method_name);
        cv::dnn::Net* me = (cv::dnn::Net*) self; //TODO: check for NULL
        ::Mat _retval_ = me->forward();
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Mat cv::dnn::Net::getParam(LayerId layer, int numParam = 0)
//

using namespace cv::dnn;

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Net_getParam_10 (JNIEnv*, jclass, jlong, jlong, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Net_getParam_10
  (JNIEnv* env, jclass , jlong self, jlong layer_nativeObj, jint numParam)
{
    static const char method_name[] = "dnn::getParam_10()";
    try {
        LOGD("%s", method_name);
        cv::dnn::Net* me = (cv::dnn::Net*) self; //TODO: check for NULL
        ::Mat _retval_ = me->getParam( (*(cv::dnn::DictValue*)layer_nativeObj), (int)numParam );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



using namespace cv::dnn;

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Net_getParam_11 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Net_getParam_11
  (JNIEnv* env, jclass , jlong self, jlong layer_nativeObj)
{
    static const char method_name[] = "dnn::getParam_11()";
    try {
        LOGD("%s", method_name);
        cv::dnn::Net* me = (cv::dnn::Net*) self; //TODO: check for NULL
        ::Mat _retval_ = me->getParam( (*(cv::dnn::DictValue*)layer_nativeObj) );
        return (jlong) new ::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// static Net cv::dnn::Net::readFromModelOptimizer(String xml, String bin)
//

using namespace cv::dnn;

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Net_readFromModelOptimizer_10 (JNIEnv*, jclass, jstring, jstring);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Net_readFromModelOptimizer_10
  (JNIEnv* env, jclass , jstring xml, jstring bin)
{
    static const char method_name[] = "dnn::readFromModelOptimizer_10()";
    try {
        LOGD("%s", method_name);
        const char* utf_xml = env->GetStringUTFChars(xml, 0); String n_xml( utf_xml ? utf_xml : "" ); env->ReleaseStringUTFChars(xml, utf_xml);
        const char* utf_bin = env->GetStringUTFChars(bin, 0); String n_bin( utf_bin ? utf_bin : "" ); env->ReleaseStringUTFChars(bin, utf_bin);
        cv::dnn::Net _retval_ = cv::dnn::Net::readFromModelOptimizer( n_xml, n_bin );
        return (jlong) new cv::dnn::Net(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// static Net cv::dnn::Net::readFromModelOptimizer(vector_uchar bufferModelConfig, vector_uchar bufferWeights)
//

using namespace cv::dnn;

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Net_readFromModelOptimizer_11 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Net_readFromModelOptimizer_11
  (JNIEnv* env, jclass , jlong bufferModelConfig_mat_nativeObj, jlong bufferWeights_mat_nativeObj)
{
    static const char method_name[] = "dnn::readFromModelOptimizer_11()";
    try {
        LOGD("%s", method_name);
        std::vector<uchar> bufferModelConfig;
        Mat& bufferModelConfig_mat = *((Mat*)bufferModelConfig_mat_nativeObj);
        Mat_to_vector_uchar( bufferModelConfig_mat, bufferModelConfig );
        std::vector<uchar> bufferWeights;
        Mat& bufferWeights_mat = *((Mat*)bufferWeights_mat_nativeObj);
        Mat_to_vector_uchar( bufferWeights_mat, bufferWeights );
        cv::dnn::Net _retval_ = cv::dnn::Net::readFromModelOptimizer( bufferModelConfig, bufferWeights );
        return (jlong) new cv::dnn::Net(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  Ptr_Layer cv::dnn::Net::getLayer(LayerId layerId)
//

using namespace cv::dnn;

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Net_getLayer_10 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Net_getLayer_10
  (JNIEnv* env, jclass , jlong self, jlong layerId_nativeObj)
{
    static const char method_name[] = "dnn::getLayer_10()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::dnn::Layer> Ptr_Layer;
        cv::dnn::Net* me = (cv::dnn::Net*) self; //TODO: check for NULL
        Ptr_Layer _retval_ = me->getLayer( (*(cv::dnn::DictValue*)layerId_nativeObj) );
        return (jlong)(new Ptr_Layer(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  String cv::dnn::Net::dump()
//

using namespace cv::dnn;

JNIEXPORT jstring JNICALL Java_org_opencv_dnn_Net_dump_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jstring JNICALL Java_org_opencv_dnn_Net_dump_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "dnn::dump_10()";
    try {
        LOGD("%s", method_name);
        cv::dnn::Net* me = (cv::dnn::Net*) self; //TODO: check for NULL
        cv::String _retval_ = me->dump();
        return env->NewStringUTF(_retval_.c_str());
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return env->NewStringUTF("");
}



//
//  bool cv::dnn::Net::empty()
//

using namespace cv::dnn;

JNIEXPORT jboolean JNICALL Java_org_opencv_dnn_Net_empty_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_dnn_Net_empty_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "dnn::empty_10()";
    try {
        LOGD("%s", method_name);
        cv::dnn::Net* me = (cv::dnn::Net*) self; //TODO: check for NULL
        return me->empty();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::dnn::Net::getLayerId(String layer)
//

using namespace cv::dnn;

JNIEXPORT jint JNICALL Java_org_opencv_dnn_Net_getLayerId_10 (JNIEnv*, jclass, jlong, jstring);

JNIEXPORT jint JNICALL Java_org_opencv_dnn_Net_getLayerId_10
  (JNIEnv* env, jclass , jlong self, jstring layer)
{
    static const char method_name[] = "dnn::getLayerId_10()";
    try {
        LOGD("%s", method_name);
        cv::dnn::Net* me = (cv::dnn::Net*) self; //TODO: check for NULL
        const char* utf_layer = env->GetStringUTFChars(layer, 0); String n_layer( utf_layer ? utf_layer : "" ); env->ReleaseStringUTFChars(layer, utf_layer);
        return me->getLayerId( n_layer );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::dnn::Net::getLayersCount(String layerType)
//

using namespace cv::dnn;

JNIEXPORT jint JNICALL Java_org_opencv_dnn_Net_getLayersCount_10 (JNIEnv*, jclass, jlong, jstring);

JNIEXPORT jint JNICALL Java_org_opencv_dnn_Net_getLayersCount_10
  (JNIEnv* env, jclass , jlong self, jstring layerType)
{
    static const char method_name[] = "dnn::getLayersCount_10()";
    try {
        LOGD("%s", method_name);
        cv::dnn::Net* me = (cv::dnn::Net*) self; //TODO: check for NULL
        const char* utf_layerType = env->GetStringUTFChars(layerType, 0); String n_layerType( utf_layerType ? utf_layerType : "" ); env->ReleaseStringUTFChars(layerType, utf_layerType);
        return me->getLayersCount( n_layerType );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int64 cv::dnn::Net::getFLOPS(MatShape netInputShape)
//

using namespace cv::dnn;

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Net_getFLOPS_10 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Net_getFLOPS_10
  (JNIEnv* env, jclass , jlong self, jlong netInputShape_mat_nativeObj)
{
    static const char method_name[] = "dnn::getFLOPS_10()";
    try {
        LOGD("%s", method_name);
        MatShape netInputShape;
        Mat& netInputShape_mat = *((Mat*)netInputShape_mat_nativeObj);
        Mat_to_MatShape( netInputShape_mat, netInputShape );
        cv::dnn::Net* me = (cv::dnn::Net*) self; //TODO: check for NULL
        return me->getFLOPS( netInputShape );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int64 cv::dnn::Net::getFLOPS(int layerId, MatShape netInputShape)
//

using namespace cv::dnn;

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Net_getFLOPS_11 (JNIEnv*, jclass, jlong, jint, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Net_getFLOPS_11
  (JNIEnv* env, jclass , jlong self, jint layerId, jlong netInputShape_mat_nativeObj)
{
    static const char method_name[] = "dnn::getFLOPS_11()";
    try {
        LOGD("%s", method_name);
        MatShape netInputShape;
        Mat& netInputShape_mat = *((Mat*)netInputShape_mat_nativeObj);
        Mat_to_MatShape( netInputShape_mat, netInputShape );
        cv::dnn::Net* me = (cv::dnn::Net*) self; //TODO: check for NULL
        return me->getFLOPS( (int)layerId, netInputShape );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int64 cv::dnn::Net::getFLOPS(int layerId, vector_MatShape netInputShapes)
//

using namespace cv::dnn;

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Net_getFLOPS_12 (JNIEnv*, jclass, jlong, jint, jobject);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Net_getFLOPS_12
  (JNIEnv* env, jclass , jlong self, jint layerId, jobject netInputShapes_list)
{
    static const char method_name[] = "dnn::getFLOPS_12()";
    try {
        LOGD("%s", method_name);
        std::vector< MatShape > netInputShapes;
        netInputShapes = List_to_vector_MatShape(env, netInputShapes_list);
        cv::dnn::Net* me = (cv::dnn::Net*) self; //TODO: check for NULL
        return me->getFLOPS( (int)layerId, netInputShapes );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int64 cv::dnn::Net::getFLOPS(vector_MatShape netInputShapes)
//

using namespace cv::dnn;

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Net_getFLOPS_13 (JNIEnv*, jclass, jlong, jobject);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Net_getFLOPS_13
  (JNIEnv* env, jclass , jlong self, jobject netInputShapes_list)
{
    static const char method_name[] = "dnn::getFLOPS_13()";
    try {
        LOGD("%s", method_name);
        std::vector< MatShape > netInputShapes;
        netInputShapes = List_to_vector_MatShape(env, netInputShapes_list);
        cv::dnn::Net* me = (cv::dnn::Net*) self; //TODO: check for NULL
        return me->getFLOPS( netInputShapes );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int64 cv::dnn::Net::getPerfProfile(vector_double& timings)
//

using namespace cv::dnn;

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Net_getPerfProfile_10 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Net_getPerfProfile_10
  (JNIEnv* env, jclass , jlong self, jlong timings_mat_nativeObj)
{
    static const char method_name[] = "dnn::getPerfProfile_10()";
    try {
        LOGD("%s", method_name);
        std::vector<double> timings;
        Mat& timings_mat = *((Mat*)timings_mat_nativeObj);
        cv::dnn::Net* me = (cv::dnn::Net*) self; //TODO: check for NULL
        int64 _retval_ = me->getPerfProfile( timings );
        vector_double_to_Mat( timings, timings_mat );
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  vector_String cv::dnn::Net::getLayerNames()
//

using namespace cv::dnn;

JNIEXPORT jobject JNICALL Java_org_opencv_dnn_Net_getLayerNames_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jobject JNICALL Java_org_opencv_dnn_Net_getLayerNames_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "dnn::getLayerNames_10()";
    try {
        LOGD("%s", method_name);
        cv::dnn::Net* me = (cv::dnn::Net*) self; //TODO: check for NULL
        std::vector< String > _ret_val_vector_ = me->getLayerNames();
        return vector_String_to_List(env, _ret_val_vector_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  vector_String cv::dnn::Net::getUnconnectedOutLayersNames()
//

using namespace cv::dnn;

JNIEXPORT jobject JNICALL Java_org_opencv_dnn_Net_getUnconnectedOutLayersNames_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jobject JNICALL Java_org_opencv_dnn_Net_getUnconnectedOutLayersNames_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "dnn::getUnconnectedOutLayersNames_10()";
    try {
        LOGD("%s", method_name);
        cv::dnn::Net* me = (cv::dnn::Net*) self; //TODO: check for NULL
        std::vector< String > _ret_val_vector_ = me->getUnconnectedOutLayersNames();
        return vector_String_to_List(env, _ret_val_vector_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  vector_int cv::dnn::Net::getUnconnectedOutLayers()
//

using namespace cv::dnn;

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Net_getUnconnectedOutLayers_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_Net_getUnconnectedOutLayers_10
  (JNIEnv* env, jclass , jlong self)
{
    static const char method_name[] = "dnn::getUnconnectedOutLayers_10()";
    try {
        LOGD("%s", method_name);
        cv::dnn::Net* me = (cv::dnn::Net*) self; //TODO: check for NULL
        std::vector<int> _ret_val_vector_ = me->getUnconnectedOutLayers();
        Mat* _retval_ = new Mat();
        vector_int_to_Mat(_ret_val_vector_, *_retval_);
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::dnn::Net::connect(String outPin, String inpPin)
//

using namespace cv::dnn;

JNIEXPORT void JNICALL Java_org_opencv_dnn_Net_connect_10 (JNIEnv*, jclass, jlong, jstring, jstring);

JNIEXPORT void JNICALL Java_org_opencv_dnn_Net_connect_10
  (JNIEnv* env, jclass , jlong self, jstring outPin, jstring inpPin)
{
    static const char method_name[] = "dnn::connect_10()";
    try {
        LOGD("%s", method_name);
        cv::dnn::Net* me = (cv::dnn::Net*) self; //TODO: check for NULL
        const char* utf_outPin = env->GetStringUTFChars(outPin, 0); String n_outPin( utf_outPin ? utf_outPin : "" ); env->ReleaseStringUTFChars(outPin, utf_outPin);
        const char* utf_inpPin = env->GetStringUTFChars(inpPin, 0); String n_inpPin( utf_inpPin ? utf_inpPin : "" ); env->ReleaseStringUTFChars(inpPin, utf_inpPin);
        me->connect( n_outPin, n_inpPin );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::dnn::Net::dumpToFile(String path)
//

using namespace cv::dnn;

JNIEXPORT void JNICALL Java_org_opencv_dnn_Net_dumpToFile_10 (JNIEnv*, jclass, jlong, jstring);

JNIEXPORT void JNICALL Java_org_opencv_dnn_Net_dumpToFile_10
  (JNIEnv* env, jclass , jlong self, jstring path)
{
    static const char method_name[] = "dnn::dumpToFile_10()";
    try {
        LOGD("%s", method_name);
        cv::dnn::Net* me = (cv::dnn::Net*) self; //TODO: check for NULL
        const char* utf_path = env->GetStringUTFChars(path, 0); String n_path( utf_path ? utf_path : "" ); env->ReleaseStringUTFChars(path, utf_path);
        me->dumpToFile( n_path );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::dnn::Net::enableFusion(bool fusion)
//

using namespace cv::dnn;

JNIEXPORT void JNICALL Java_org_opencv_dnn_Net_enableFusion_10 (JNIEnv*, jclass, jlong, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_dnn_Net_enableFusion_10
  (JNIEnv* env, jclass , jlong self, jboolean fusion)
{
    static const char method_name[] = "dnn::enableFusion_10()";
    try {
        LOGD("%s", method_name);
        cv::dnn::Net* me = (cv::dnn::Net*) self; //TODO: check for NULL
        me->enableFusion( (bool)fusion );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::dnn::Net::forward(vector_Mat& outputBlobs, String outputName = String())
//

using namespace cv::dnn;

JNIEXPORT void JNICALL Java_org_opencv_dnn_Net_forward_12 (JNIEnv*, jclass, jlong, jlong, jstring);

JNIEXPORT void JNICALL Java_org_opencv_dnn_Net_forward_12
  (JNIEnv* env, jclass , jlong self, jlong outputBlobs_mat_nativeObj, jstring outputName)
{
    static const char method_name[] = "dnn::forward_12()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> outputBlobs;
        Mat& outputBlobs_mat = *((Mat*)outputBlobs_mat_nativeObj);
        cv::dnn::Net* me = (cv::dnn::Net*) self; //TODO: check for NULL
        const char* utf_outputName = env->GetStringUTFChars(outputName, 0); String n_outputName( utf_outputName ? utf_outputName : "" ); env->ReleaseStringUTFChars(outputName, utf_outputName);
        me->forward( outputBlobs, n_outputName );
        vector_Mat_to_Mat( outputBlobs, outputBlobs_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv::dnn;

JNIEXPORT void JNICALL Java_org_opencv_dnn_Net_forward_13 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_dnn_Net_forward_13
  (JNIEnv* env, jclass , jlong self, jlong outputBlobs_mat_nativeObj)
{
    static const char method_name[] = "dnn::forward_13()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> outputBlobs;
        Mat& outputBlobs_mat = *((Mat*)outputBlobs_mat_nativeObj);
        cv::dnn::Net* me = (cv::dnn::Net*) self; //TODO: check for NULL
        me->forward( outputBlobs );
        vector_Mat_to_Mat( outputBlobs, outputBlobs_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::dnn::Net::forward(vector_Mat& outputBlobs, vector_String outBlobNames)
//

using namespace cv::dnn;

JNIEXPORT void JNICALL Java_org_opencv_dnn_Net_forward_14 (JNIEnv*, jclass, jlong, jlong, jobject);

JNIEXPORT void JNICALL Java_org_opencv_dnn_Net_forward_14
  (JNIEnv* env, jclass , jlong self, jlong outputBlobs_mat_nativeObj, jobject outBlobNames_list)
{
    static const char method_name[] = "dnn::forward_14()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> outputBlobs;
        Mat& outputBlobs_mat = *((Mat*)outputBlobs_mat_nativeObj);
        std::vector< String > outBlobNames;
        outBlobNames = List_to_vector_String(env, outBlobNames_list);
        cv::dnn::Net* me = (cv::dnn::Net*) self; //TODO: check for NULL
        me->forward( outputBlobs, outBlobNames );
        vector_Mat_to_Mat( outputBlobs, outputBlobs_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::dnn::Net::getLayerTypes(vector_String& layersTypes)
//

using namespace cv::dnn;

JNIEXPORT void JNICALL Java_org_opencv_dnn_Net_getLayerTypes_10 (JNIEnv*, jclass, jlong, jobject);

JNIEXPORT void JNICALL Java_org_opencv_dnn_Net_getLayerTypes_10
  (JNIEnv* env, jclass , jlong self, jobject layersTypes_list)
{
    static const char method_name[] = "dnn::getLayerTypes_10()";
    try {
        LOGD("%s", method_name);
        std::vector< String > layersTypes;
        cv::dnn::Net* me = (cv::dnn::Net*) self; //TODO: check for NULL
        me->getLayerTypes( layersTypes );
        Copy_vector_String_to_List(env,layersTypes,layersTypes_list);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::dnn::Net::getMemoryConsumption(MatShape netInputShape, size_t& weights, size_t& blobs)
//

using namespace cv::dnn;

JNIEXPORT void JNICALL Java_org_opencv_dnn_Net_getMemoryConsumption_10 (JNIEnv*, jclass, jlong, jlong, jdoubleArray, jdoubleArray);

JNIEXPORT void JNICALL Java_org_opencv_dnn_Net_getMemoryConsumption_10
  (JNIEnv* env, jclass , jlong self, jlong netInputShape_mat_nativeObj, jdoubleArray weights_out, jdoubleArray blobs_out)
{
    static const char method_name[] = "dnn::getMemoryConsumption_10()";
    try {
        LOGD("%s", method_name);
        MatShape netInputShape;
        Mat& netInputShape_mat = *((Mat*)netInputShape_mat_nativeObj);
        Mat_to_MatShape( netInputShape_mat, netInputShape );
        cv::dnn::Net* me = (cv::dnn::Net*) self; //TODO: check for NULL
        size_t weights;
        size_t blobs;
        me->getMemoryConsumption( netInputShape, weights, blobs );
        jdouble tmp_weights[1] = {(jdouble)weights}; env->SetDoubleArrayRegion(weights_out, 0, 1, tmp_weights);
        jdouble tmp_blobs[1] = {(jdouble)blobs}; env->SetDoubleArrayRegion(blobs_out, 0, 1, tmp_blobs);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::dnn::Net::getMemoryConsumption(int layerId, MatShape netInputShape, size_t& weights, size_t& blobs)
//

using namespace cv::dnn;

JNIEXPORT void JNICALL Java_org_opencv_dnn_Net_getMemoryConsumption_11 (JNIEnv*, jclass, jlong, jint, jlong, jdoubleArray, jdoubleArray);

JNIEXPORT void JNICALL Java_org_opencv_dnn_Net_getMemoryConsumption_11
  (JNIEnv* env, jclass , jlong self, jint layerId, jlong netInputShape_mat_nativeObj, jdoubleArray weights_out, jdoubleArray blobs_out)
{
    static const char method_name[] = "dnn::getMemoryConsumption_11()";
    try {
        LOGD("%s", method_name);
        MatShape netInputShape;
        Mat& netInputShape_mat = *((Mat*)netInputShape_mat_nativeObj);
        Mat_to_MatShape( netInputShape_mat, netInputShape );
        cv::dnn::Net* me = (cv::dnn::Net*) self; //TODO: check for NULL
        size_t weights;
        size_t blobs;
        me->getMemoryConsumption( (int)layerId, netInputShape, weights, blobs );
        jdouble tmp_weights[1] = {(jdouble)weights}; env->SetDoubleArrayRegion(weights_out, 0, 1, tmp_weights);
        jdouble tmp_blobs[1] = {(jdouble)blobs}; env->SetDoubleArrayRegion(blobs_out, 0, 1, tmp_blobs);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::dnn::Net::getMemoryConsumption(int layerId, vector_MatShape netInputShapes, size_t& weights, size_t& blobs)
//

using namespace cv::dnn;

JNIEXPORT void JNICALL Java_org_opencv_dnn_Net_getMemoryConsumption_12 (JNIEnv*, jclass, jlong, jint, jobject, jdoubleArray, jdoubleArray);

JNIEXPORT void JNICALL Java_org_opencv_dnn_Net_getMemoryConsumption_12
  (JNIEnv* env, jclass , jlong self, jint layerId, jobject netInputShapes_list, jdoubleArray weights_out, jdoubleArray blobs_out)
{
    static const char method_name[] = "dnn::getMemoryConsumption_12()";
    try {
        LOGD("%s", method_name);
        std::vector< MatShape > netInputShapes;
        netInputShapes = List_to_vector_MatShape(env, netInputShapes_list);
        cv::dnn::Net* me = (cv::dnn::Net*) self; //TODO: check for NULL
        size_t weights;
        size_t blobs;
        me->getMemoryConsumption( (int)layerId, netInputShapes, weights, blobs );
        jdouble tmp_weights[1] = {(jdouble)weights}; env->SetDoubleArrayRegion(weights_out, 0, 1, tmp_weights);
        jdouble tmp_blobs[1] = {(jdouble)blobs}; env->SetDoubleArrayRegion(blobs_out, 0, 1, tmp_blobs);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::dnn::Net::setHalideScheduler(String scheduler)
//

using namespace cv::dnn;

JNIEXPORT void JNICALL Java_org_opencv_dnn_Net_setHalideScheduler_10 (JNIEnv*, jclass, jlong, jstring);

JNIEXPORT void JNICALL Java_org_opencv_dnn_Net_setHalideScheduler_10
  (JNIEnv* env, jclass , jlong self, jstring scheduler)
{
    static const char method_name[] = "dnn::setHalideScheduler_10()";
    try {
        LOGD("%s", method_name);
        cv::dnn::Net* me = (cv::dnn::Net*) self; //TODO: check for NULL
        const char* utf_scheduler = env->GetStringUTFChars(scheduler, 0); String n_scheduler( utf_scheduler ? utf_scheduler : "" ); env->ReleaseStringUTFChars(scheduler, utf_scheduler);
        me->setHalideScheduler( n_scheduler );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::dnn::Net::setInput(Mat blob, String name = "", double scalefactor = 1.0, Scalar mean = Scalar())
//

using namespace cv::dnn;

JNIEXPORT void JNICALL Java_org_opencv_dnn_Net_setInput_10 (JNIEnv*, jclass, jlong, jlong, jstring, jdouble, jdouble, jdouble, jdouble, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_dnn_Net_setInput_10
  (JNIEnv* env, jclass , jlong self, jlong blob_nativeObj, jstring name, jdouble scalefactor, jdouble mean_val0, jdouble mean_val1, jdouble mean_val2, jdouble mean_val3)
{
    static const char method_name[] = "dnn::setInput_10()";
    try {
        LOGD("%s", method_name);
        cv::dnn::Net* me = (cv::dnn::Net*) self; //TODO: check for NULL
        Mat& blob = *((Mat*)blob_nativeObj);
        const char* utf_name = env->GetStringUTFChars(name, 0); String n_name( utf_name ? utf_name : "" ); env->ReleaseStringUTFChars(name, utf_name);
        Scalar mean(mean_val0, mean_val1, mean_val2, mean_val3);
        me->setInput( blob, n_name, (double)scalefactor, mean );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv::dnn;

JNIEXPORT void JNICALL Java_org_opencv_dnn_Net_setInput_11 (JNIEnv*, jclass, jlong, jlong, jstring, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_dnn_Net_setInput_11
  (JNIEnv* env, jclass , jlong self, jlong blob_nativeObj, jstring name, jdouble scalefactor)
{
    static const char method_name[] = "dnn::setInput_11()";
    try {
        LOGD("%s", method_name);
        cv::dnn::Net* me = (cv::dnn::Net*) self; //TODO: check for NULL
        Mat& blob = *((Mat*)blob_nativeObj);
        const char* utf_name = env->GetStringUTFChars(name, 0); String n_name( utf_name ? utf_name : "" ); env->ReleaseStringUTFChars(name, utf_name);
        me->setInput( blob, n_name, (double)scalefactor );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv::dnn;

JNIEXPORT void JNICALL Java_org_opencv_dnn_Net_setInput_12 (JNIEnv*, jclass, jlong, jlong, jstring);

JNIEXPORT void JNICALL Java_org_opencv_dnn_Net_setInput_12
  (JNIEnv* env, jclass , jlong self, jlong blob_nativeObj, jstring name)
{
    static const char method_name[] = "dnn::setInput_12()";
    try {
        LOGD("%s", method_name);
        cv::dnn::Net* me = (cv::dnn::Net*) self; //TODO: check for NULL
        Mat& blob = *((Mat*)blob_nativeObj);
        const char* utf_name = env->GetStringUTFChars(name, 0); String n_name( utf_name ? utf_name : "" ); env->ReleaseStringUTFChars(name, utf_name);
        me->setInput( blob, n_name );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



using namespace cv::dnn;

JNIEXPORT void JNICALL Java_org_opencv_dnn_Net_setInput_13 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_dnn_Net_setInput_13
  (JNIEnv* env, jclass , jlong self, jlong blob_nativeObj)
{
    static const char method_name[] = "dnn::setInput_13()";
    try {
        LOGD("%s", method_name);
        cv::dnn::Net* me = (cv::dnn::Net*) self; //TODO: check for NULL
        Mat& blob = *((Mat*)blob_nativeObj);
        me->setInput( blob );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::dnn::Net::setInputShape(String inputName, MatShape shape)
//

using namespace cv::dnn;

JNIEXPORT void JNICALL Java_org_opencv_dnn_Net_setInputShape_10 (JNIEnv*, jclass, jlong, jstring, jlong);

JNIEXPORT void JNICALL Java_org_opencv_dnn_Net_setInputShape_10
  (JNIEnv* env, jclass , jlong self, jstring inputName, jlong shape_mat_nativeObj)
{
    static const char method_name[] = "dnn::setInputShape_10()";
    try {
        LOGD("%s", method_name);
        MatShape shape;
        Mat& shape_mat = *((Mat*)shape_mat_nativeObj);
        Mat_to_MatShape( shape_mat, shape );
        cv::dnn::Net* me = (cv::dnn::Net*) self; //TODO: check for NULL
        const char* utf_inputName = env->GetStringUTFChars(inputName, 0); String n_inputName( utf_inputName ? utf_inputName : "" ); env->ReleaseStringUTFChars(inputName, utf_inputName);
        me->setInputShape( n_inputName, shape );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::dnn::Net::setInputsNames(vector_String inputBlobNames)
//

using namespace cv::dnn;

JNIEXPORT void JNICALL Java_org_opencv_dnn_Net_setInputsNames_10 (JNIEnv*, jclass, jlong, jobject);

JNIEXPORT void JNICALL Java_org_opencv_dnn_Net_setInputsNames_10
  (JNIEnv* env, jclass , jlong self, jobject inputBlobNames_list)
{
    static const char method_name[] = "dnn::setInputsNames_10()";
    try {
        LOGD("%s", method_name);
        std::vector< String > inputBlobNames;
        inputBlobNames = List_to_vector_String(env, inputBlobNames_list);
        cv::dnn::Net* me = (cv::dnn::Net*) self; //TODO: check for NULL
        me->setInputsNames( inputBlobNames );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::dnn::Net::setParam(LayerId layer, int numParam, Mat blob)
//

using namespace cv::dnn;

JNIEXPORT void JNICALL Java_org_opencv_dnn_Net_setParam_10 (JNIEnv*, jclass, jlong, jlong, jint, jlong);

JNIEXPORT void JNICALL Java_org_opencv_dnn_Net_setParam_10
  (JNIEnv* env, jclass , jlong self, jlong layer_nativeObj, jint numParam, jlong blob_nativeObj)
{
    static const char method_name[] = "dnn::setParam_10()";
    try {
        LOGD("%s", method_name);
        cv::dnn::Net* me = (cv::dnn::Net*) self; //TODO: check for NULL
        Mat& blob = *((Mat*)blob_nativeObj);
        me->setParam( (*(cv::dnn::DictValue*)layer_nativeObj), (int)numParam, blob );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::dnn::Net::setPreferableBackend(int backendId)
//

using namespace cv::dnn;

JNIEXPORT void JNICALL Java_org_opencv_dnn_Net_setPreferableBackend_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_dnn_Net_setPreferableBackend_10
  (JNIEnv* env, jclass , jlong self, jint backendId)
{
    static const char method_name[] = "dnn::setPreferableBackend_10()";
    try {
        LOGD("%s", method_name);
        cv::dnn::Net* me = (cv::dnn::Net*) self; //TODO: check for NULL
        me->setPreferableBackend( (int)backendId );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::dnn::Net::setPreferableTarget(int targetId)
//

using namespace cv::dnn;

JNIEXPORT void JNICALL Java_org_opencv_dnn_Net_setPreferableTarget_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_dnn_Net_setPreferableTarget_10
  (JNIEnv* env, jclass , jlong self, jint targetId)
{
    static const char method_name[] = "dnn::setPreferableTarget_10()";
    try {
        LOGD("%s", method_name);
        cv::dnn::Net* me = (cv::dnn::Net*) self; //TODO: check for NULL
        me->setPreferableTarget( (int)targetId );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void cv::dnn::Net::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_dnn_Net_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_dnn_Net_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (cv::dnn::Net*) self;
}



} // extern "C"

#endif // HAVE_OPENCV_DNN
