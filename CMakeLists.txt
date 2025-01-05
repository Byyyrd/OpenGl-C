cmake_minimum_required(VERSION 3.5.0)
project(open_gl_start VERSION 0.1.0 LANGUAGES C)

cmake_policy(SET CMP0072 NEW)

find_package(OpenGL REQUIRED)

add_executable(open_gl_start
    src/shader/shader.c
    src/shader/shader.h     
    src/main.c    
    src/glad.c
    src/buffer.h
    src/buffer.c
)

target_link_libraries(open_gl_start
    glfw
    OpenGL::GL
)