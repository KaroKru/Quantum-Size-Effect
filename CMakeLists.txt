cmake_minimum_required(VERSION 3.10)

project(quantumSizeEffect)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Sprawdzenie, czy clang-tidy jest dostępny
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    find_program(CLANG_TIDY_EXE NAMES clang-tidy)
    if(CLANG_TIDY_EXE)
        set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE};-extra-arg=-I${CMAKE_SOURCE_DIR}/include")
    endif()
endif()

# Dodanie ścieżki do katalogu include
include_directories("${CMAKE_SOURCE_DIR}/include")

# Definicja biblioteki
add_library(qse
    source/ReadData.cpp
    source/UnitCellInfo.cpp
    source/SampleInfo.cpp
    source/ResultCalculation.cpp
    source/SphereCalculation.cpp
    source/ElectronicDensity.cpp
    source/ElectronicCalculation.cpp
)

# Definicja pliku wykonywalnego
add_executable(run 
    source/main.cpp
)

target_link_libraries(run qse)
