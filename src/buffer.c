#include "buffer.h"


void bindBuffer(BUFFER buffer){
    glBindBuffer(buffer.target,buffer.handle);
}
BUFFER newBuffer(GLenum target,GLsizeiptr size,void* data,GLenum usage){
    BUFFER buf;
    buf.target = target;
    glGenBuffers(1,&buf.handle);
    glBindBuffer(buf.target,buf.handle);
    glBufferData(buf.target,size,data,usage);
    return buf;
}