add_library(algorithms)

target_include_directories(
    algorithms
    PUBLIC
    include/
)

target_sources(
    algorithms
    PUBLIC
    letterCounter.cpp
    generateHuffmanTree.cpp
)