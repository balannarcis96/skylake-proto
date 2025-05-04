#
# SPDX-License-Identifier: MIT
# Copyright (c) 2025 Balan Narcis (balannarcis96@gmail.com)
#
cmake_minimum_required(VERSION 4.0.0)
project(libskl-proto VERSION 1.0.0)

file(GLOB_RECURSE _SKL_PROTO_SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp")

add_library(${PROJECT_NAME} STATIC ${_SKL_PROTO_SOURCE_FILES})

target_include_directories(${PROJECT_NAME}
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/source")

# Link the Skylake Core library
target_link_libraries(${PROJECT_NAME} PUBLIC libskl-core)

# Tuning
skl_add_tune_header_to_target(${PROJECT_NAME} "skl_proto" "${PRESET_NAME}" "libskl-proto")

# Code coverage
if(SKL_ENABLE_CODE_COVERAGE)
    skl_EnableCodeCoverageForTarget(${PROJECT_NAME})
endif()

if(SKL_IS_SHIPPING)
    # Enable unity build
    set_target_properties(${TARGET_NAME} PROPERTIES UNITY_BUILD ON)
    set_target_properties(${TARGET_NAME} PROPERTIES UNITY_BUILD_BATCH_SIZE 24)
endif()
