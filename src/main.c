#include <string.h>
#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "shader/shader.h"
#include "buffer.h"
#include "model_loader.h"
#include <cglm/cglm.h>


int startGL(Model model){
//     float vertices[] = {
//     -0.5f,-0.5f, 0.0f,
//      0.5f,-0.5f, 0.0f,
//      0.5f, 0.5f, 0.0f,
//     -0.5f, 0.5f, 0.0f
// };
// GLuint indices[] = {
//     0,1,2,
//     2,3,0
// };
    float vertices[model.verticesCount];
    memcpy(vertices,model.vertices,sizeof(float)*model.verticesCount);
    
    GLuint indices[model.indicesCount];
    memcpy(indices,model.indices,sizeof(GLuint)*model.indicesCount);

    GLFWwindow* window;
    if(!glfwInit()){
        return -1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);  


    window = glfwCreateWindow(500,500,"Hello",NULL,NULL);
    glfwMakeContextCurrent(window);
    
    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)){
        printf("Couldn't load OpenGl\n");
        glfwTerminate();
        return -1;
    }
    
    GLuint VAO;
    glGenVertexArrays(1, &VAO);  
    glBindVertexArray(VAO);

    Buffer VBO = newBuffer(GL_ARRAY_BUFFER,sizeof(vertices),&vertices,GL_STATIC_DRAW);
    bindBuffer(VBO);

    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(float)*3,(void*)0);
    glEnableVertexAttribArray(0); 

    Buffer EBO = newBuffer(GL_ELEMENT_ARRAY_BUFFER,sizeof(indices),&indices,GL_STATIC_DRAW);
    bindBuffer(EBO);
    
    GLuint program = getShaderProgram();

    glUseProgram(program);
    glBindVertexArray(VAO);

    glClearColor(1,0,0,1);

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT);
        glDrawElements(GL_TRIANGLES, sizeof(indices)/sizeof(GLuint),GL_UNSIGNED_INT,0);
        glfwSwapBuffers(window);
    }
    glfwTerminate();
    return 0;
}

int main(int, char**){
    Model model = loadFromFile("mokey.obj");
    return startGL(model); 
}
