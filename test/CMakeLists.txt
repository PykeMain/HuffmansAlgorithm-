Include(FetchContent)


FetchContent_Declare(
  DocTest
  GIT_REPOSITORY https://github.com/onqtam/doctest
  GIT_TAG        v2.4.11
)

FetchContent_MakeAvailable(DocTest)

cmake_minimum_required(VERSION 3.13)

add_executable(algorithmsTests algorithmsTests.cpp)
add_executable(structureTests structuresTests.cpp)

target_sources(algorithmsTests PUBLIC )
target_link_libraries(
    algorithmsTests
    PUBLIC
    doctest
    algorithms
    structures
)

add_test(NAME AlgorithmsTests COMMAND algorithmsTests)

target_sources(structureTests PUBLIC )
target_link_libraries(
    structureTests
    PUBLIC
    doctest
    algorithms
    structures
)

add_test(NAME StructureTests COMMAND structureTests)