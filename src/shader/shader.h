#ifndef SHADER_H_INCLUDED
#define SHADER_H_INCLUDED


#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cglm/cglm.h>
#include <stdio.h>
#include <stdlib.h>

GLuint getShaderProgram();
GLuint _private_generateShaderFromSource(char* source,GLuint shaderType);
void setUniformVec3(GLuint programId,char *name,vec3 data);
void setUniformMat4(GLuint programId,char *name,mat4 data);
void setUniformMat3(GLuint programId,char *name,mat3 data);
#endif