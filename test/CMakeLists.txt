Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0 # or a later release
)

FetchContent_MakeAvailable(Catch2)

# FetchContent_Declare(
#   DocTest
#   GIT_REPOSITORY https://github.com/catchorg/Catch2.git
#   GIT_TAG        ae7a13539fb71f270b87eb2e874fbac80bc8dda2
# )

# FetchContent_MakeAvailable(DocTest)

cmake_minimum_required(VERSION 3.13)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)

# add_subdirectory(math)
# add_subdirectory(person)