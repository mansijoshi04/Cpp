# CMakeList.txt : CMake project for FinalProject, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("FinalProject")

# Add source to this project's executable.
add_executable (FinalProject "FinalProject.cpp" "FinalProject.h" "NormalTest.h" "Test.h" "UniformTest.h")
target_include_directories(FinalProject PUBLIC "C:\\Users\\mansi\\Visual Studio\\FinalProject\\nana\\include")
add_definitions(-D_SILENCE_EXPERIMENTIAL_FILESYSTEM_DEPRECATION_WARNING)
target_link_libraries(FinalProject "nana_v143_Debug_x64" )
target_link_directories(FinalProject PUBLIC "C:\\Users\\mansi\\Visual Studio\\FinalProject\\nana\\build\\bin")
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET FinalProject PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
