cmake_minimum_required(VERSION 3.15.0)
project(DummyDBG VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_C_COMPILER clang)
# add_compile_options(-std=c++17)

# include(CTest)
# enable_testing()

add_executable(DummyDBG 
    thirdparty/linenoise/linenoise.c
    code/dummy_main.cpp 
)

target_include_directories(DummyDBG 
    PRIVATE thirdparty/libelfin 
    PRIVATE thirdparty/linenoise 
    PRIVATE include
)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
