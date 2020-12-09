cmake_minimum_required(VERSION 3.2)

project(AlgorithmLibrary)

set(ProjectDir ${CMAKE_CURRENT_SOURCE_DIR})

set(LIBRARY_OUTPUT_PATH ${ProjectDir}/lib)

set(DynamicRegisterDir ${CMAKE_CURRENT_SOURCE_DIR}/DynamicRegister/)

include_directories(

    ./include /opt/jdk1.8.0_201/include/ 

    ${DynamicRegisterDir}

    TimeComplexity/

    Test/

)

add_library(
    
    AlgorithmLibrary SHARED 

    ${DynamicRegisterDir}/DynamicRegisterMethod.cpp

    TimeComplexity/InstrucNumTime.cpp

    Test/Test.cpp

)

