#ifndef BUFFER_H_INCLUDED
#define BUFFER_H_INCLUDED
    #include <glad/glad.h>
    #include <GLFW/glfw3.h>
    typedef struct Buffer Buffer;
    struct Buffer{
        GLuint handle;
        GLenum target;
    };
    void bindBuffer(Buffer buffer);
    Buffer newBuffer(GLenum target,GLsizeiptr size,void* data,GLenum usage);



#endif
