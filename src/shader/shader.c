#include "shader.h"


GLuint getShaderProgram(){
    
    //Vertex Shader:
    GLuint vertexShaderId = _private_generateShaderFromSource("vertex.shader",GL_VERTEX_SHADER);
    //Fragment Shader
    GLuint fragmentShaderId = _private_generateShaderFromSource("fragment.shader",GL_FRAGMENT_SHADER);

    //Shader Program
    GLuint program = glCreateProgram();
    glAttachShader(program,vertexShaderId);
    glAttachShader(program,fragmentShaderId);
    glLinkProgram(program);

    int  success;
    char infoLog[512];

    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        printf("ERROR::SHADER::PROGRAM::LINK_FAILED\n");
        printf("%s\n",infoLog); 
    }
    

    glDeleteShader(vertexShaderId);
    glDeleteShader(fragmentShaderId);
    return program;
}

char *readFile(char* source){
    FILE *fptr;
    
    char *absolutePath;
    asprintf(&absolutePath,"/home/julius/projects/c/open_gl_start/src/shader/%s",source);
    fptr = fopen(absolutePath, "r");
    

    //Start reading when file could be opened
    if(fptr != NULL) {
        //find out file lenght
        fseek(fptr, 0L, SEEK_END);
        long size = ftell(fptr);
        //create array at filesize
        char *content = malloc(size);

        //Go Back to File start
        rewind(fptr);
        // Read the content and print it
        int ch,i = 0;
        while((ch = fgetc(fptr)) != EOF){
            content[i] = ch;
            i++;
        }
        
        // Close the file
        fclose(fptr);
        return content;
    } else {
        printf("Not able to open the file.\n");
    }   
    return "";
}

GLuint _private_generateShaderFromSource(char* source,GLuint shaderType){
    char* shaderCode = readFile(source);
    GLuint shader = glCreateShader(shaderType);
    
    glShaderSource(shader,1,(const char* const*)&shaderCode,NULL);
    glCompileShader(shader);

    free(shaderCode);
    
    int  success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        printf("ERROR::SHADER::%s::COMPILATION_FAILED\n",source);
        printf("%s\n",infoLog);   
    }
    return shader;
}

void setUniformVec3(GLuint programId, char *name,vec3 data){
    int modelLoc = glGetUniformLocation(programId, name);
    glUniform3fv(modelLoc, 1,(const float*)data);
}

void setUniformMat4(GLuint programId, char *name, mat4 data)
{
    int modelLoc = glGetUniformLocation(programId, name);
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE,(const float*)data);
}
void setUniformMat3(GLuint programId, char *name, mat3 data)
{
    int modelLoc = glGetUniformLocation(programId, name);
    glUniformMatrix3fv(modelLoc, 1, GL_FALSE,(const float*)data);
}
