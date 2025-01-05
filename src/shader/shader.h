#ifndef SHADER_H_INCLUDED
#define SHADER_H_INCLUDED


#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

GLuint getShaderProgram();
GLuint generateShaderFromSource(char* source,GLuint shaderType);

#endif