#****************************************************************************
# Copyright (C) 2018 Chenrui Lei
#
# THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
# KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
# PARTICULAR PURPOSE.
#
#****************************************************************************
cmake_minimum_required(VERSION 2.8)

project(OpenCVSamples)

if (UNIX)
    set(CMAKE_CXX_STANDARD 11)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

# Basic Cpp samples
add_subdirectory(BasicCpp)

# OpenCV samples
add_subdirectory(DisplayImages)
add_subdirectory(ModifyImages)
