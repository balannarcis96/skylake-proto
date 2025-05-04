#
# SPDX-License-Identifier: MIT
# Copyright (c) 2025 Balan Narcis (balannarcis96@gmail.com)
#
cmake_minimum_required(VERSION 4.0.0)
project(skl-core-workbench VERSION 1.0.0)

file(GLOB_RECURSE _SKL_PROTO_WORKBENCH_SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp")

add_executable(${PROJECT_NAME} ${_SKL_PROTO_WORKBENCH_SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/source")

# Link the Skylake Proto library
target_link_libraries(${PROJECT_NAME} PRIVATE libskl-proto)

