# CMake generated Testfile for 
# Source directory: /Users/virtualman/Downloads/MySource/opencv-4.3.0/modules/ml
# Build directory: /Users/virtualman/Downloads/MySource/opencv-4.3.0/release/modules/ml
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(opencv_test_ml "/Users/virtualman/Downloads/MySource/opencv-4.3.0/release/bin/opencv_test_ml" "--gtest_output=xml:opencv_test_ml.xml")
set_tests_properties(opencv_test_ml PROPERTIES  LABELS "Main;opencv_ml;Accuracy" WORKING_DIRECTORY "/Users/virtualman/Downloads/MySource/opencv-4.3.0/release/test-reports/accuracy" _BACKTRACE_TRIPLES "/Users/virtualman/Downloads/MySource/opencv-4.3.0/cmake/OpenCVUtils.cmake;1640;add_test;/Users/virtualman/Downloads/MySource/opencv-4.3.0/cmake/OpenCVModule.cmake;1309;ocv_add_test_from_target;/Users/virtualman/Downloads/MySource/opencv-4.3.0/cmake/OpenCVModule.cmake;1073;ocv_add_accuracy_tests;/Users/virtualman/Downloads/MySource/opencv-4.3.0/modules/ml/CMakeLists.txt;2;ocv_define_module;/Users/virtualman/Downloads/MySource/opencv-4.3.0/modules/ml/CMakeLists.txt;0;")
