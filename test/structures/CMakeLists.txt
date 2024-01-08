add_executable(structuresTests)

target_sources(
    structuresTests
    PUBLIC
    structuresTests.cpp
)

target_link_libraries(
    structuresTests
    PUBLIC
    doctest
    structures
)

add_test(NAME StructuresTests COMMAND structuresTests)