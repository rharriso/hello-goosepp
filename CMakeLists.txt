project(HelloGoose)
cmake_minimum_required(VERSION 2.8.12)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# include cpr
add_subdirectory(cpr)
include_directories(${CPR_INCLUDE_DIRS})
find_library(GOOSE goosepp)
find_library(GUMBO gumbo)

add_executable(helloGoose main.cpp)
target_link_libraries(helloGoose
  ${CONAN_LIBS}
  ${GOOSE}
  ${GUMBO}
  ${CPR_LIBRARIES})
