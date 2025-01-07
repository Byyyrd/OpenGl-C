#include <string.h>
#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "shader/shader.h"
#include "buffer.h"
#include "model_loader.h"
#include <cglm/cglm.h>


int startGL(Model model){
    
}

int main(int, char**){
    Model model = loadFromFile("monkey2.obj");

    float *vertices = malloc(sizeof(float) * model.verticesCount);
    int size_v = model.verticesCount;
    for(int i = 0;i < model.verticesCount; i++){
        vertices[i] = model.vertices[i];
    }
    // int size_v = model.verticesCount;
    // float vertices[size_v];
    // memcpy(vertices,model.vertices,size_v * sizeof(float));

    GLuint *indices = malloc(sizeof(GLuint) * model.indicesCount);
    int size_i = model.indicesCount;
    for(int i = 0;i < model.indicesCount; i++){
        indices[i] = model.indices[i] - 1;
    }

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
    
    glEnable(GL_DEPTH_TEST);  

    GLuint VAO;
    glGenVertexArrays(1, &VAO);  
    glBindVertexArray(VAO);
    
    Buffer VBO = newBuffer(GL_ARRAY_BUFFER,sizeof(float) * size_v,vertices,GL_STATIC_DRAW);
    bindBuffer(VBO);

    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(float)*3,(void*)0);
    glEnableVertexAttribArray(0); 

    Buffer EBO = newBuffer(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * size_i,indices,GL_STATIC_DRAW);
    bindBuffer(EBO);
    
    GLuint program = getShaderProgram();

    glUseProgram(program);
    glBindVertexArray(VAO);

    mat4 modelMat;
    glm_mat4_identity(modelMat);
    glm_rotate(modelMat, glm_rad(-55.0f), (vec3){1.0f, 0.0f, 0.0f}); 
    //glm_translate(modelMat,(vec3){0.0f, 0.0f, 10.0f}); 
    mat4 view;
    glm_mat4_identity(view);
    glm_translate(view, (vec3){0.0f, 0.0f, -5.0f}); 

    mat4 projection;
    glm_perspective(glm_rad(45.0f), 800.0f / 600.0f, 0.1f, 100.0f,projection);


    int modelLoc = glGetUniformLocation(program, "model");
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE,(const float*)modelMat);
    modelLoc = glGetUniformLocation(program, "view");
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE,(const float*)view);
    modelLoc = glGetUniformLocation(program, "projection");
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE,(const float*)projection);


    glClearColor(0,0,0,1);
    float lastFrame,currentFrame,deltaTime;
    lastFrame = glfwGetTime();
    
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glm_rotate(modelMat,deltaTime * glm_rad(50.0f), (vec3){0.5f, 1.0f, 0.0f}); 
        modelLoc = glGetUniformLocation(program, "model");
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE,(const float*)modelMat);

        glDrawElements(GL_TRIANGLES, size_i,GL_UNSIGNED_INT,0);
        glfwSwapBuffers(window);
    }
    free(vertices);
    free(indices);
    glfwTerminate();
    return 0;
    //return startGL(&model,sizeof(model)); 
}
