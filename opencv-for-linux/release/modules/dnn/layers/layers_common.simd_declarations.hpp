#define CV_CPU_SIMD_FILENAME "/Users/virtualman/Downloads/MySource/opencv-4.3.0/modules/dnn/src/layers/layers_common.simd.hpp"
#define CV_CPU_DISPATCH_MODE AVX
#include "opencv2/core/private/cv_cpu_include_simd_declarations.hpp"

#define CV_CPU_DISPATCH_MODE AVX2
#include "opencv2/core/private/cv_cpu_include_simd_declarations.hpp"

#define CV_CPU_DISPATCH_MODE AVX512_SKX
#include "opencv2/core/private/cv_cpu_include_simd_declarations.hpp"

#define CV_CPU_DISPATCH_MODES_ALL AVX512_SKX, AVX2, AVX, BASELINE

#undef CV_CPU_SIMD_FILENAME
