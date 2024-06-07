cmake_minimum_required (VERSION 3.8)
project(Demo)

set(CMAKE_EXPORT_COMPILE_COMMANDS True)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_BUILD_TYPE Debug)

set(TARGET_NAME demo)

file(GLOB SOURCE_FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/demo.cpp
)

add_executable(${TARGET_NAME}
  ${SOURCE_FILES}
)