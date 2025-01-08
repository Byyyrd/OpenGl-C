#ifndef MODEL_LOADER_H_INCLUDED
#define MODEL_LOADER_H_INCLUDED
    #include <stdio.h>
    #include <stdlib.h>
    #include <GLFW/glfw3.h>
    #include <string.h>
    #include <cglm/cglm.h>
    #include "utils.h"

    typedef struct Model Model;
    struct Model{
        float *vertices;
        size_t verticesSize;
        GLuint *indices; 
        size_t indicesSize;
        float *normals; 
        size_t normalsSize;
    };
    Model loadFromFile(char *location);
#endif