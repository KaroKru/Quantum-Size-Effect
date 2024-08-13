cmake_minimum_required(VERSION 3.10)

project(matrixGenerator)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} --coverage")
endif()

include_directories(include)

add_library(qse
    source/ReadData.cpp
    source/UnitCellInfo.cpp
    source/SampleInfo.cpp
    source/SphereCalculation.cpp
)

add_executable(run WIN32
    source/main.cpp
)

target_link_libraries(run qse)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)

include(FetchContent)
FetchContent_Declare(
    sqlite3
    GIT_REPOSITORY https://github.com/sqlite/sqlite.git
    GIT_TAG        version-3.43.1
)
FetchContent_MakeAvailable(sqlite3)

#enable_testing()

#add_executable(qseTest
#)

#target_link_libraries(qseTest gtest gmock gtest_main qse)

#add_test(NAME qseTest COMMAND qseTest --gtest_output=xml:report.xml)

