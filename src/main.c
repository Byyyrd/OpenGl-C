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
    u_printArray(model.indices,model.indicesCount);
    float vertices[model.verticesCount];
    memcpy(vertices,model.vertices,sizeof(float)*model.verticesCount);
    
    int size = model.indicesCount;
    GLuint indices[size];
    memcpy(indices,model.indices,sizeof(indices));
    u_printArray(model.indices,model.indicesCount);
    GLuint max = 0;
    for(int i = 0; i<model.indicesCount;i++){
        if(indices[i] > max){
            max = indices[i];
        }
    }
    printf("%u\n",max);
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

    Buffer VBO = newBuffer(GL_ARRAY_BUFFER,sizeof(vertices),&vertices,GL_STATIC_DRAW);
    bindBuffer(VBO);

    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(float)*3,(void*)0);
    glEnableVertexAttribArray(0); 

    Buffer EBO = newBuffer(GL_ELEMENT_ARRAY_BUFFER,sizeof(indices),&indices,GL_STATIC_DRAW);
    bindBuffer(EBO);
    
    GLuint program = getShaderProgram();

    glUseProgram(program);
    glBindVertexArray(VAO);

    mat4 modelMat;
    glm_mat4_identity(modelMat);
    glm_rotate(modelMat, glm_rad(-55.0f), (vec3){1.0f, 0.0f, 0.0f}); 
    mat4 view;
    glm_mat4_identity(view);
    glm_translate(view, (vec3){0.0f, 0.0f, -3.0f}); 

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

        glDrawElements(GL_TRIANGLES, sizeof(indices)/sizeof(GLuint),GL_UNSIGNED_INT,0);
        glfwSwapBuffers(window);
    }
    glfwTerminate();
    return 0;
}

int main(int, char**){
    Model model = loadFromFile("mokey.obj");
    
    return startGL(model); 
    // unsigned int a1[] = {1u,2u,4u,8u};
    // unsigned int a2[4];
    // u_printArray(a1,sizeof(a1)/sizeof(unsigned int));
    // memcpy(a2,a1,sizeof(a1));
    // u_printArray(a1,sizeof(a1)/sizeof(unsigned int));
    // u_printArray(a2,sizeof(a2)/sizeof(unsigned int));

}
