cmake_minimum_required(VERSION 3.10)

project(matrixGenerator)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    find_program(CLANG_TIDY_EXE NAMES clang-tidy)
    if(CLANG_TIDY_EXE)
        set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE}")
    endif()
endif()

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} --coverage")
endif()

include_directories(include)

add_library(qse
    source/main.cpp
    source/ReadData.cpp
    source/UnitCellInfo.cpp
    source/SampleInfo.cpp
    source/ResultCalculation.cpp
    source/SphereCalculation.cpp
    source/ElectronicDensity.cpp
    source/ElectronicCalculation.cpp
)

add_executable(run 
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

enable_testing()

include_directories(tests/include)


add_executable(qseTest
    tests/src/ElectronicCalculationTest.cpp
)

target_link_libraries(qseTest gtest gmock gtest_main qse)

add_test(NAME qseTest COMMAND qseTest --gtest_output=xml:report.xml)

add_custom_target(run-clang-tidy
    COMMAND ${CMAKE_COMMAND} -E echo "Running clang-tidy"
    COMMAND ${CLANG_TIDY_EXE} --quiet -p ${CMAKE_BINARY_DIR} ${ALL_SOURCES}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

file(GLOB_RECURSE ALL_SOURCES
    "${CMAKE_SOURCE_DIR}/source/*.cpp"
    "${CMAKE_SOURCE_DIR}/include/*.h"
)

