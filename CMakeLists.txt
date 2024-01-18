cmake_minimum_required (VERSION 3.8)
project(Demo)

set(CMAKE_EXPORT_COMPILE_COMMANDS True)
set(EXPORT_COMPILE_COMMANDS True)

set(TARGET_NAME Demo)

file(GLOB SOURCE_FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/demo.cpp
)

add_executable(${TARGET_NAME}
  ${SOURCE_FILES}
)