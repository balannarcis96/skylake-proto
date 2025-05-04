#
# SPDX-License-Identifier: MIT
# Copyright (c) 2025 Balan Narcis (balannarcis96@gmail.com)
#
cmake_minimum_required(VERSION 4.0.0)
project(SkylakeProto LANGUAGES CXX VERSION 1.0.0)

# Update modules path
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules")

# Skylake Core
add_subdirectory(third_party/skylake-core)

include(SkylakeProtoOptions)

# Add presets
skl_add_presets_file("${CMAKE_CURRENT_SOURCE_DIR}/cmake/presets/dev_presets.json")
skl_add_presets_file("${CMAKE_CURRENT_SOURCE_DIR}/cmake/presets/qa_presets.json")

# Skylake Core
skl_CreateSkylakeCoreLibTarget("libskl-core" "")

# Skylake Proto
add_subdirectory(src)

# Workbench
if(PROJECT_IS_TOP_LEVEL)
    add_subdirectory(workbench)
endif()
