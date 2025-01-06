#include "buffer.h"


void bindBuffer(Buffer buffer){
    glBindBuffer(buffer.target,buffer.handle);
}
Buffer newBuffer(GLenum target,GLsizeiptr size,void* data,GLenum usage){
    Buffer buf;
    buf.target = target;
    glGenBuffers(1,&buf.handle);
    glBindBuffer(buf.target,buf.handle);
    glBufferData(buf.target,size,data,usage);
    return buf;
}