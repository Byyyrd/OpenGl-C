cmake_minimum_required(VERSION 3.5.0)
project(open_gl_start VERSION 0.1.0 LANGUAGES C)

cmake_policy(SET CMP0072 NEW)

find_package(OpenGL REQUIRED)
find_package(cglm REQUIRED)

add_executable(open_gl_start
    src/shader/shader.c
    src/shader/shader.h     
    src/main.c    
    src/glad.c
    src/buffer.h
    src/buffer.c
    src/model_loader.c
    src/model_loader.h
)

target_link_libraries(open_gl_start
    PRIVATE cglm
    glfw
    OpenGL::GL
)