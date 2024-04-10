# CMakeList for HW2

cmake_minimum_required(VERSION 3.23)
project(AERSP_424_HW2)
set(CMAKE_CXX_STANDARD 20)

add_executable(Q1 Problem1.cpp Problem1_Classes.h Problem1_Classes.cpp)
add_executable(Q2 Problem2.cpp Problem2_Functions.h Problem2_Functions.cpp)
add_executable(Q3 Problem3.cpp Problem3_Functions.h Problem3_Functions.cpp)

# Question 4

include(CTest)
enable_testing()

# Dependencies
find_package(OpenGL REQUIRED)

include(FetchContent)

FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw
)

FetchContent_GetProperties(glfw)
if(NOT glfw_POPULATED)
    FetchContent_Populate(glfw)

    set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
    set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
    set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
    set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")

    add_subdirectory(${glfw_SOURCE_DIR} ${glfw_BINARY_DIR})
endif()

FetchContent_Declare(
        glew
        GIT_REPOSITORY https://github.com/Perlmint/glew-cmake.git
)
FetchContent_MakeAvailable(glew)
# Our Project
set(SOURCE_FILES
    Problem4.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} OpenGL::GL glfw libglew_static)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_executable(Q4 Problem4.cpp)