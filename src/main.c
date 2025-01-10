#include <string.h>
#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "shader/shader.h"
#include "buffer.h"
#include "model_loader.h"
#include <cglm/cglm.h>

bool keys[348];
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if(action == GLFW_PRESS){
        keys[key] = true;
    }else if(action == GLFW_RELEASE){
        keys[key] = false;
    }
}


int startGL(Model model){
    //Turn indexed data into one vertex Array:
    int indicesCount = model.indicesSize / sizeof(GLuint);
    //every 2nd index is one Vertex -> / 2
    int vertexCount = indicesCount/2;
    //6 Values per Vertex
    float vertices[vertexCount * 6];
    int vertexPosition = 0;
    for(int i = 0;i < model.indicesSize/sizeof(GLuint);i++){
        //3 values per index -> multiply by 3
        int index = model.indices[i] * 3;
        //Every second index is a vertex
        if(i % 2 == 0){
            vertices[vertexPosition + 0] = model.vertices[index + 0];
            vertices[vertexPosition + 1] = model.vertices[index + 1];
            vertices[vertexPosition + 2] = model.vertices[index + 2];
        }else{
            vertices[vertexPosition + 0] = model.normals[index + 0];
            vertices[vertexPosition + 1] = model.normals[index + 1];
            vertices[vertexPosition + 2] = model.normals[index + 2];
        }
        vertexPosition += 3;   
    }
    free(model.vertices);
    free(model.indices);
    free(model.normals);

    GLFWwindow* window;
    if(!glfwInit()){
        return -1;
    }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);  


    window = glfwCreateWindow(500,500,"Hello",NULL,NULL);
    glfwSetWindowPos(window,0,0);
    glfwMakeContextCurrent(window);

    glfwSetKeyCallback(window,key_callback);
    
    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)){
        printf("Couldn't load OpenGl\n");
        glfwTerminate();
        return -1;
    }
    
    glEnable(GL_DEPTH_TEST);  


    GLuint VAO;
    glGenVertexArrays(1, &VAO);  
    glBindVertexArray(VAO);
    
    

    Buffer VBO = newBuffer(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
    bindBuffer(VBO);

    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(float)*6,(void*)0);
    glEnableVertexAttribArray(0); 

    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,sizeof(float)*6,(void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1); 

    GLuint program = getShaderProgram();

    glUseProgram(program);
    glBindVertexArray(VAO);



    mat4 modelMat = GLM_MAT4_IDENTITY_INIT;
    glm_rotate(modelMat, glm_rad(-55.0f), (vec3){1.0f, 0.0f, 0.0f}); 

    mat4 view = GLM_MAT4_IDENTITY_INIT;
    glm_translate(view, (vec3){0.0f, 0.0f, -5.0f}); 

    //Init at forward direction
    vec3 direction;
    glm_vec3_copy((vec3){0.0f, 0.0f, 1.0f},direction);

    mat4 projection;
    glm_perspective(glm_rad(45.0f), 800.0f / 600.0f, 0.1f, 100.0f,projection);

    mat4 normalMat;
    glm_mat4_copy(modelMat,normalMat);
    glm_mat4_inv(modelMat,normalMat);
    glm_mat4_transpose(normalMat);

    setUniformMat4(program,"model",modelMat);
    setUniformMat4(program,"normalMat",normalMat);
    setUniformMat4(program, "view",view);
    setUniformMat4(program, "projection",projection);

    setUniformVec3(program,"lightSource",(vec3){0.0f, -5.0f, -5.0f});
    setUniformVec3(program,"lightColor",(vec3){1.0f, 1.0f, 1.0f});
    setUniformVec3(program,"objectColor",(vec3){1.0f, 1.0f, 1.0f});

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

        if(keys[GLFW_KEY_S]){
            //vec3 movement;
            //glm_vec3_scale(direction,-10*deltaTime, movement);
            //glm_translate(view,movement);
            glm_translate_z(view,-10*deltaTime);
            setUniformMat4(program,"view",view);
        }
        if(keys[GLFW_KEY_W]){
            //vec3 movement;
            // glm_vec3_scale(direction,10*deltaTime, movement);
            //glm_translate(view,movement);
            
            glm_translate_z(view,10*deltaTime);
            setUniformMat4(program,"view",view);
        }
        if(keys[GLFW_KEY_A]){
            glm_translate_x(view,10*deltaTime);
            setUniformMat4(program,"view",view);
        }
        if(keys[GLFW_KEY_D]){
            glm_translate_x(view,-10*deltaTime);
            setUniformMat4(program,"view",view);
        }
        if(keys[GLFW_KEY_RIGHT]){
            glm_rotate_y(projection,deltaTime * glm_rad(25.0f),projection);
            //glm_vec3_rotate(direction,deltaTime * -glm_rad(25.0f),(vec3){0,1,0});
            setUniformMat4(program,"projection",projection);
        }
        if(keys[GLFW_KEY_LEFT]){
            glm_rotate_y(projection,deltaTime * -glm_rad(25.0f),projection);
            //glm_vec3_rotate(direction,deltaTime * glm_rad(25.0f),(vec3){0,1,0});
            setUniformMat4(program,"projection",projection);
        }
        if(keys[GLFW_KEY_DOWN]){
            glm_rotate_x(projection,deltaTime * glm_rad(25.0f),projection);
            //glm_vec3_rotate(direction,deltaTime * -glm_rad(25.0f),(vec3){1,0,0});
            setUniformMat4(program,"projection",projection);
        }
        if(keys[GLFW_KEY_UP]){
            glm_rotate_x(projection,deltaTime * -glm_rad(25.0f),projection);
            //glm_vec3_rotate(direction,deltaTime * glm_rad(25.0f),(vec3){1,0,0});
            setUniformMat4(program,"projection",projection);
        }

        glm_rotate(modelMat,deltaTime * glm_rad(50.0f), (vec3){0.5f, 1.0f, 0.0f});
        
        glm_mat4_copy(modelMat,normalMat);
        glm_mat4_inv(modelMat,normalMat);
        glm_mat4_transpose(normalMat);

        setUniformMat4(program, "model",modelMat);
        setUniformMat4(program,"normalMat",normalMat);

        glDrawArrays(GL_TRIANGLES,0,vertexCount);

        glfwSwapBuffers(window);
    }
    glfwTerminate();
    return 0;
}

int main(int, char**){
    Model model = loadFromFile("monkey_normals.obj");
    int success = startGL(model); 
    
    return success;
}

