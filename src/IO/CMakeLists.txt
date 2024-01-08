add_library(IO)

target_include_directories(
    IO
    PUBLIC
    include/
)

target_sources(
    IO
    PUBLIC
    IO.cpp
)

target_link_libraries(
    IO
    PUBLIC
    fileManager
    algorithms
    structures
)