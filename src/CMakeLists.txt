cmake_minimum_required(VERSION 3.9 FATAL_ERROR)
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_COMPILER clang-5.0)
set(CMAKE_CXX_COMPILER clang++-5.0)
set(CMAKE_CXX_STANDARD 17)

if(CMAKE_BUILD_TYPE MATCHES DEBUG)
  message("DEBUG mode")
  set(build_type_flags "-g -Og")
  set(CMAKE_CXX_CLANG_TIDY "clang-tidy-5.0")
else()
  message("RELEASE mode")
  set(build_type_flags "-O3 -Werror")
  set(CMAKE_CXX_CLANG_TIDY "clang-tidy-5.0;-warnings-as-errors=*")
endif()

set(common_flags "\
  ${build_type_flags} \
  -Wall \
  -Wextra \
  -Wpedantic")
set(CMAKE_C_FLAGS "\
  ${common_flags}")
set(CMAKE_CXX_FLAGS "\
  ${common_flags} \
  -fno-exceptions")

project(onchange)
add_subdirectory(app)
add_subdirectory(lib)

include(CTest)
enable_testing()

