cmake_minimum_required(VERSION 3.8)
project(mmn_11_graphics)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

add_executable(mmn_11_graphics ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})