# CMakeList.txt : CMake project for Lab8, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /openmp")
endif()

project ("Lab8")
# Add source to this project's executable.
add_library(MyCPPLibrary SHARED Lab8.cpp)

target_include_directories(MyCPPLibrary PRIVATE

"C:\\Program Files\\Java\\jdk-19\\include"
"C:\\Program Files\\Java\\jdk-19\\include\\win32")


