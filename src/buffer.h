#ifndef BUFFER_H_INCLUDED
#define BUFFER_H_INCLUDED
    #include <glad/glad.h>
    #include <GLFW/glfw3.h>
    typedef struct Buffer
    {
        GLuint handle;
        GLenum target;
    }BUFFER;
    void bindBuffer(BUFFER buffer);
    BUFFER newBuffer(GLenum target,GLsizeiptr size,void* data,GLenum usage);



#endif
