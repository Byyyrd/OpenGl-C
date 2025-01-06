#ifndef MODEL_LOADER_H_INCLUDED
#define MODEL_LOADER_H_INCLUDED
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <GLFW/glfw3.h>

    typedef struct Model Model;
    struct Model{
        float *vertices;
        int verticesCount;
        GLuint *indices; 
        int indicesCount;
    };
    Model loadFromFile(char *location);
#endif