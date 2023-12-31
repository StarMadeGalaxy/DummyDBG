cmake_minimum_required(VERSION 3.15.0)
project(DummyDBG VERSION 0.1.0 LANGUAGES C CXX)

find_package(Git)
if (GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git"
              AND EXISTS "${PROJECT_SOURCE_DIR}/.gitmodules")
    execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                    RESULT_VARIABLE GIT_SUBMOD_RESULT)
    if(NOT GIT_SUBMOD_RESULT EQUAL "0")
        message(FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
    endif()
endif()

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_COMPILER clang)

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

add_custom_target(
   libelfin
   COMMAND ${CMAKE_MAKE_PROGRAM}
   WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/thirdparty/libelfin
   COMMENT "Building libelfin"
)

add_dependencies(DummyDBG libelfin)

target_link_libraries(DummyDBG
                      ${PROJECT_SOURCE_DIR}/thirdparty/libelfin/dwarf/libdwarf++.so
                      ${PROJECT_SOURCE_DIR}/thirdparty/libelfin/elf/libelf++.so)
# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
