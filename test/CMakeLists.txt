Include(FetchContent)


FetchContent_Declare(
  DocTest
  GIT_REPOSITORY https://github.com/onqtam/doctest
  GIT_TAG        2.3.1
)

FetchContent_MakeAvailable(DocTest)

cmake_minimum_required(VERSION 3.13)

# add_subdirectory(algorithms)
# add_subdirectory(structures)