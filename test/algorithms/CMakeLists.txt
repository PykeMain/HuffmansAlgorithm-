add_executable(algorithmsTests)

target_sources(
    algorithmsTests
    PUBLIC
    algorithmsTests.cpp
)

target_link_libraries(
    algorithmsTests
    PUBLIC
    doctest
    algorithms
)

add_test(NAME AlgorithmsTests COMMAND algorithmsTests)