cmake_minimum_required(VERSION 3.13.0)
project(HuffmansAlgorithm VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)
enable_testing()

###probably should be here the dir text mover
add_subdirectory(src)
add_subdirectory(test)

make_directory(${CMAKE_CURRENT_BINARY_DIR}/text)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/text/wibawoba.txt
    DESTINATION  ${CMAKE_CURRENT_BINARY_DIR}/text)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)