add_library(fileManager)

target_include_directories(
    fileManager
    PUBLIC
    include/
)

target_sources(
    fileManager
    PUBLIC
    myRead.cpp
    myWrite.cpp
)