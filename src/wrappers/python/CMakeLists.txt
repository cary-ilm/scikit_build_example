
find_package(Python REQUIRED COMPONENTS Interpreter Development.Module)

python_add_library(Hello MODULE main.cpp WITH_SOABI)

target_compile_definitions(Hello PRIVATE VERSION_INFO=${PROJECT_VERSION})

install(TARGETS Hello DESTINATION Hello)
