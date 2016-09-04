cmake_minimum_required(VERSION 3.5.2)
project(tic)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/unity/unity.c
    src/unity/unity.h
    src/unity/unity_config.h
    src/unity/unity_fixture.c
    src/unity/unity_fixture.h
    src/unity/unity_fixture_internals.h
    src/unity/unity_fixture_malloc_overrides.h
    src/unity/unity_internals.h
    src/ProductionCode.c
    src/ProductionCode.h
    test/test_runners/all_tests.c
    test/test_runners/TestProductionCode_Runner.c
    test/TestProductionCode.c)

include_directories(.)
include_directories(src)
include_directories(src/unity)
include_directories(test)
include_directories(test/test_runners)

add_executable(tic ${SOURCE_FILES})
