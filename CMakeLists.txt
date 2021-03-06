CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(ds-lib CXX)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
else()
    CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
    if(COMPILER_SUPPORTS_CXX0X)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
    else()
        message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
    endif()
endif()
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -g")

SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
FILE(MAKE_DIRECTORY ${LIBRARY_OUTPUT_PATH})

SET(INCLUDE include/)
SET(EXTERNAL_INCLUDE external/cst_v_1_1/ external/divsufsortxx)
FILE(GLOB_RECURSE SOURCE_FILES src/*.cc)
INCLUDE_DIRECTORIES(${INCLUDE} ${EXTERNAL_INCLUDE})
ADD_LIBRARY(ds STATIC ${SOURCE_FILES})
SET_TARGET_PROPERTIES(ds PROPERTIES LINKER_LANGUAGE CXX)
TARGET_LINK_LIBRARIES(ds cst)

ADD_SUBDIRECTORY(external/cst_v_1_1)
ADD_SUBDIRECTORY(bench)
ADD_SUBDIRECTORY(construct)
