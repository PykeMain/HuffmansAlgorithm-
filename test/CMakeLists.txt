Include(FetchContent)


FetchContent_Declare(
  DocTest
  GIT_REPOSITORY https://github.com/onqtam/doctest
  GIT_TAG        v2.4.11
)

FetchContent_MakeAvailable(DocTest)

cmake_minimum_required(VERSION 3.13)

add_executable(unitTests algorithmsTests.cpp 
                         structuresTests.cpp)

target_sources(unitTests PUBLIC )
target_link_libraries(
    unitTests
    PUBLIC
    doctest
    algorithms
    structures
)

add_test(NAME UnitTests COMMAND unitTests)