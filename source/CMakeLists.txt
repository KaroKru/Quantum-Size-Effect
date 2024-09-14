add_library(qse STATIC)

target_sources(qse PRIVATE
    src/ReadData.cpp
    src/UnitCellInfo.cpp
    src/SampleInfo.cpp
    src/ResultCalculation.cpp
    src/SphereCalculation.cpp
    src/ElectronicDensity.cpp
    src/ElectronicCalculation.cpp
)

target_include_directories(qse PUBLIC
    "${CMAKE_SOURCE_DIR}/source/include"
)

add_executable(run 
    src/main.cpp
)

target_link_libraries(run PRIVATE qse)

if(ENABLE_CODE_COVERAGE)
    target_compile_options(qse PRIVATE --coverage)
    target_link_libraries(qse PRIVATE --coverage)
endif()