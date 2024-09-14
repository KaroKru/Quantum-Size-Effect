cmake_minimum_required(VERSION 3.10)

project(quantumSizeEffect)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

option(ENABLE_CLANG_TIDY "Enable clang-tidy" ON)

if (ENABLE_CLANG_TIDY)
    if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        find_program(CLANG_TIDY_EXE NAMES clang-tidy)
        if(CLANG_TIDY_EXE)
            set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE};-header-filter=${CMAKE_SOURCE_DIR}/source/.*;-extra-arg=-I${CMAKE_SOURCE_DIR}/source/include")
        endif()
    endif()
endif()

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)

if(ENABLE_CLANG_TIDY AND CLANG_TIDY_EXE)
    set_target_properties(gtest PROPERTIES CXX_CLANG_TIDY "")
    set_target_properties(gmock PROPERTIES CXX_CLANG_TIDY "")
    set_target_properties(gmock_main PROPERTIES CXX_CLANG_TIDY "")
    set_target_properties(gtest_main PROPERTIES CXX_CLANG_TIDY "")
endif()

add_subdirectory(source)
add_subdirectory(tests)

enable_testing()

file(GLOB_RECURSE ALL_SOURCE_FILES
    ${CMAKE_SOURCE_DIR}/source/src/*.cpp
    ${CMAKE_SOURCE_DIR}/source/include/*.hpp
    ${CMAKE_SOURCE_DIR}/tests/src/*.cpp
    ${CMAKE_SOURCE_DIR}/tests/include/*.hpp
)

add_custom_target(format
    COMMAND clang-format
    -i
    -style=file
    ${ALL_SOURCE_FILES}
    COMMENT "Running clang-format on source files"
)

if(ENABLE_CODE_COVERAGE)
    find_program(LCOV_EXEC lcov)
    find_program(GENHTML_EXEC genhtml)
    if(LCOV_EXEC AND GENHTML_EXEC)
        add_custom_target(coverage
            COMMAND ${LCOV_EXEC} --capture --directory . --output-file coverage.info
            COMMAND ${LCOV_EXEC} --remove coverage.info '/usr/*' '${CMAKE_BINARY_DIR}/*' --output-file coverage.info
            COMMAND ${GENHTML_EXEC} -o coverage coverage.info
            COMMENT "Generating coverage report"
            VERBATIM
        )
    else()
        message(WARNING "lcov or genhtml not found! Cannot generate coverage report.")
    endif()
endif()