include(GoogleTest)
include(CTest)

add_executable(qseTest
    src/main.cpp
    src/CellInfoTest.cpp
    src/ElectronicCalcTest.cpp
    src/DensityTest.cpp
    src/ResultTest.cpp
    src/SampleTest.cpp
    src/SphereCalcTest.cpp
)

target_include_directories(qseTest PUBLIC
    "${gtest_SOURCE_DIR}/include"
    "${gmock_SOURCE_DIR}/include"
    "${CMAKE_SOURCE_DIR}/tests/include"
    "${CMAKE_SOURCE_DIR}/source/include"
)

target_link_libraries(qseTest PRIVATE
    qse
    gtest_main
    gmock_main
)

if(ENABLE_CLANG_TIDY AND CLANG_TIDY_EXE)
    set_target_properties(qseTest PROPERTIES CXX_CLANG_TIDY "")
endif()

gtest_discover_tests(qseTest XML_OUTPUT_DIR ${CMAKE_BINARY_DIR}/tests/qseTest)

if(ENABLE_CODE_COVERAGE)
    target_compile_options(qseTest PRIVATE --coverage)
    target_link_libraries(qseTest PRIVATE --coverage)
endif()
