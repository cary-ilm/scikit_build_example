# Require CMake 3.15+ (matching scikit-build-core) Use new versions of all
# policies up to CMake 3.27
cmake_minimum_required(VERSION 3.15...3.27)

set(SKBUILD_PROJECT_NAME Hello)
set(SKBUILD_PROJECT_VERSION 0.1.2)

# Scikit-build-core sets these values for you, or you can just hard-code the
# name and version.
project(
  ${SKBUILD_PROJECT_NAME}
  VERSION ${SKBUILD_PROJECT_VERSION}
  LANGUAGES CXX)

find_package(Python REQUIRED COMPONENTS Interpreter Development.Module)

python_add_library(Hello MODULE src/main.cpp WITH_SOABI)

target_compile_definitions(Hello PRIVATE VERSION_INFO=${PROJECT_VERSION})

install(TARGETS Hello DESTINATION Hello)
