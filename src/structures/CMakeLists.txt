add_library(structures)

target_include_directories(
    structures
    PUBLIC
    include/
)

target_sources(
    structures
    PUBLIC
    binaryTree.cpp
)