# Require CMake 3.15+ (matching scikit-build-core) Use new versions of all
# policies up to CMake 3.27
cmake_minimum_required(VERSION 3.15...3.27)

set(SKBUILD_PROJECT_NAME scikit_build_example)
set(SKBUILD_PROJECT_VERSION 0.1.2)

# Scikit-build-core sets these values for you, or you can just hard-code the
# name and version.
project(
  ${SKBUILD_PROJECT_NAME}
  VERSION ${SKBUILD_PROJECT_VERSION}
  LANGUAGES CXX)

# Find the module development requirements (requires FindPython from 3.17 or
# scikit-build-core's built-in backport)
find_package(Python REQUIRED COMPONENTS Interpreter Development.Module)

# Add a library using FindPython's tooling (pybind11 also provides a helper like
# this)
python_add_library(scikit_build_example MODULE main.cpp WITH_SOABI)

# This is passing in the version as a define just as an example
target_compile_definitions(scikit_build_example PRIVATE VERSION_INFO=${PROJECT_VERSION})

# The install directory is the output (wheel) directory
install(TARGETS scikit_build_example DESTINATION scikit_build_example)
