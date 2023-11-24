cmake_minimum_required(VERSION 3.12)

# sets project name var
set(PROJECT_NAME ConwaysLife)
project(${PROJECT_NAME})

# Target Vars
set(HEADER_FILES LifeSimulator.hpp RendererConsole.hpp Renderer.hpp Pattern.hpp PatternAcorn.hpp PatternBlinker.hpp PatternBlock.hpp PatternGlider.hpp PatternGosperGliderGun.hpp PatternPulsar.hpp)

set(SOURCE_FILES LifeSimulator.cpp RendererConsole.cpp PatternAcorn.cpp PatternBlinker.cpp PatternBlock.cpp PatternGlider.cpp PatternGosperGliderGun.cpp PatternPulsar.cpp)

set(UNIT_TEST_FILES TestGameOfLife.cpp)

# Executables
add_executable(ConwaysLife main.cpp ${HEADER_FILES} ${SOURCE_FILES})
add_executable(UnitTestRunner ${HEADER_FILES} ${SOURCE_FILES} ${UNIT_TEST_FILES})

set_property(TARGET ConwaysLife PROPERTY CXX_STANDARD 20)
set_property(TARGET UnitTestRunner PROPERTY CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Clang Format import
find_program(CLANG_FORMAT "clang-format")

# Google test import
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
    )
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googleTest)

# linked list
target_link_libraries(UnitTestRunner gtest_main)


# Clang Formating
if (CLANG_FORMAT)
    unset(SOURCE_FILES_PATHS)
    foreach(SOURCE_FILE ${HEADER_FILES} ${SOURCE_FILES} ${UNIT_TEST_FILES} main.cpp)
        get_source_file_property(WHERE ${SOURCE_FILE} LOCATION)
        set(SOURCE_FILES_PATHS ${SOURCE_FILES_PATHS} ${WHERE})
    endforeach()
    add_custom_target(
        ClangFormat
        COMMAND ${CLANG_FORMAT}
        -i
        -style=file
        ${SOURCE_FILES_PATHS})

    # Clang Dependaancy
    add_dependencies(ConwaysLife ClangFormat)
    add_dependencies(UnitTestRunner ClangFormat)
endif()



# Warnings

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /permissive-)
    target_compile_options(UnitTestRunner PRIVATE /W4 /permissive-)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(UnitTestRunner PRIVATE -Wall -Wextra -pedantic)
endif()


