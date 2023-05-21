#undef GLFW_DLL
#include <iostream>
#include <stdio.h>
#include <string>

#include <ctime>
#include <chrono>
#include <thread>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <vector>
#include <cmath>

#include "Shader.h"
#include "Window.h"
#include "Mesh.h"

using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::chrono::system_clock;

const GLint WIDTH = 800, HEIGHT = 600;
const float toRadians = 3.14159265f / 180.0f;

Window mainWindow;
std::vector<Mesh*> meshList;
std::vector<Shader> shaderList;

float triOffset = 0.0f;
float secondOffset = 0.0f;
float triIncrement = 0.07f;
float triMaxOffset = 0.7f;

bool direction = true;

int secondDirection = 0;

//Vertex Shader
static const char* vShader = "Shaders/shader.vert";

//Fragment Shader
static const char* fShader = "Shaders/shader.frag";

void CreateTriangle()
{
    //Circle
    GLfloat Circle_Vertices[] =
    {
        0.0f, 0.0f, 0.0f,     //0
        1.0f, 0.0f, 0.0f,     //1
        0.995f, 0.098f, 0.0f, //2
        0.981f, 0.195f, 0.0f, //3
        0.957f, 0.29f, 0.0f,  //4
        0.924f, 0.383f, 0.0f, //5
        0.882f, 0.471f, 0.0f, //6
        0.831f, 0.556f, 0.0f, //7
        0.773f, 0.634f, 0.0f, //8
        0.707f, 0.707f, 0.0f, //9
        0.634f, 0.773f, 0.0f, //10
        0.556f, 0.831f, 0.0f, //11
        0.471f, 0.882f, 0.0f, //12
        0.383f, 0.924f, 0.0f, //13
        0.29f, 0.957f, 0.0f,  //14
        0.195f, 0.981f, 0.0f, //15
        0.098f, 0.995f, 0.0f, //16
        0.0f, 1.0f, 0.0f      //17
    };

    unsigned int Circle_Indices[] = 
    {
        0, 1, 2,
        0, 2, 3,
        0, 3, 4,
        0, 4, 5,
        0, 5, 6,
        0, 6, 7,
        0, 7, 8,
        0, 8, 9,
        0, 9, 10,
        0, 10, 11,
        0, 11, 12,
        0, 12, 13,
        0, 13, 14,
        0, 14, 15,
        0, 15, 16,
        0, 16, 17
    };

    Mesh *Circle = new Mesh();
    Circle->CreateMesh(Circle_Vertices, Circle_Indices, 54, 54);
    meshList.push_back(Circle);

    //Recangle
    GLfloat Rec_Vertices[] =
    {
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        -1.0f, 0.0f, 0.0f,
        0.0f, -1.0f, 0.0f
    };

    unsigned int Rec_Indices[] = 
    {
        0, 1, 2,
        0, 2, 3
    };

    Mesh *Rec = new Mesh();
    Rec->CreateMesh(Rec_Vertices, Rec_Indices, 12, 6);
    meshList.push_back(Rec);

     //Beef
    GLfloat Beef_Vertices[] =
    {
        0.4f, 0.48f, 0.0f,

        0.6f, 0.315f, 0.0f,
        0.5f, 0.28f, 0.0f,
        0.457f, 0.27f, 0.0f,
        0.41f, 0.253f, 0.0f,
        0.13f, 0.307f, 0.0f,
        0.112f, 0.35f, 0.0f,
        0.081f, 0.4f, 0.0f,
        0.081f, 0.45f, 0.0f,
        0.099f, 0.5f, 0.0f,
        0.127f, 0.55f, 0.0f,
        0.148f, 0.6f, 0.0f,
        0.186f, 0.65f, 0.0f,
        0.257f, 0.7f, 0.0f,
        0.33f, 0.73f, 0.0f,
        0.4f, 0.736f, 0.0f,
        0.45f, 0.718f, 0.0f,
        0.5f, 0.688f, 0.0f,
        0.6f, 0.632f, 0.0f,
        0.65f, 0.592f, 0.0f,
        0.69f, 0.55f, 0.0f,
        0.697f, 0.5f, 0.0f,
        0.688f, 0.45f, 0.0f,
        0.673f, 0.4f, 0.0f,
    };

    unsigned int Beef_Indices[] = 
    {
        0,1,2,
        0,2,3,
        0,3,4,
        0,4,5,
        0,5,6,
        0,6,7,
        0,7,8,
        0,8,9,
        0,9,10,
        0,10,11,
        0,11,12,
        0,12,13,
        0,13,14,
        0,14,15,
        0,15,16,
        0,16,17,
        0,17,18,
        0,18,19,
        0,19,20,
        0,20,21,
        0,21,22,
        0,22,23,
        0,23,1
    };

    Mesh *Beef = new Mesh();
    Beef->CreateMesh(Beef_Vertices, Beef_Indices, 72, 69);
    meshList.push_back(Beef);

     //Beef
    GLfloat Tri_Vertices[] =
    {
        0.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        0.5f, 1.0f, 0.0f
    };

    unsigned int Tri_Indices[] = 
    {
        0, 1, 2
    };

    Mesh *Tri = new Mesh();
    Tri->CreateMesh(Tri_Vertices, Tri_Indices, 9, 3);
    meshList.push_back(Tri);

}

void CreateShaders()
{
    Shader* shader1 = new Shader();
    shader1->CreateFromFiles(vShader, fShader);
    shaderList.push_back(*shader1);
}

void Update(long elapseTime) 
{
    // s += v * dt
    if (direction)  triOffset += (triIncrement * elapseTime / 1000.0);
    else  triOffset -= (triIncrement * elapseTime / 1000.0);

    if (secondDirection == -1) 
        secondOffset -= (triIncrement * elapseTime / 1000.0);
    
    else if (secondDirection == 1) 
        secondOffset += (triIncrement * elapseTime / 1000.0);

    if (abs(triOffset) >= triMaxOffset) direction = direction;

}

void KeyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods) 
{
    if (key == GLFW_KEY_A && action == GLFW_PRESS) 
    {
        secondDirection = -1;
        //move triangle left
    }
    else if (key == GLFW_KEY_A && action == GLFW_RELEASE)
    {
        secondDirection = 0;
    }

    if (key == GLFW_KEY_D && action == GLFW_PRESS)
    {
        secondDirection = 1;
        //move triangle right
    }
    else if (key == GLFW_KEY_D && action == GLFW_RELEASE)
    {
        secondDirection = 0;
    }
}

int main()
{
    mainWindow = Window(WIDTH, HEIGHT);
    mainWindow.initialise();

    CreateTriangle();
    CreateShaders();

    GLuint uniformModel = 0, uniformProjection = 0, uniformColor = 0;
    glm::vec4 color;
    glm::mat4 projection = glm::perspective(45.0f, (GLfloat)mainWindow.getBufferWidth() / (GLfloat)mainWindow.getBufferHeight(), 0.1f, 100.0f);

    //starting animation time
    long startTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    //current animation time
    long currentTime = startTime;
    //last frame animation time
    long lastTime = currentTime;
    //elapse time
    long elapseTime;

    glfwSetKeyCallback(mainWindow.getWindow(), KeyboardHandler);

    //Loop until window closed
    while (!mainWindow.getShouldClose())
    {
        currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        elapseTime = currentTime - lastTime;

        lastTime = currentTime;

        //Get + Handle user input events
        glfwPollEvents();

        Update(elapseTime);

        //Clear window
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //draw here
        shaderList[0].UseShader();
        uniformModel = shaderList[0].GetModelLocation();
        uniformProjection = shaderList[0].GetProjectionLocation();
        uniformColor = shaderList[0].GetColorLocation();

        //Circle ---ขอบจาน ด้านบน
        glm::mat4 model (1.0f);

        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0f, -0.015f, -0.999f));
        model = glm::scale(model, glm::vec3(0.39f, 0.27f, 0.99f));
        color = glm::vec4(1, 1, 1, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //Circle --->ขอบตัดจาน ดำ
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0f, -0.015f, -0.999f));
        model = glm::scale(model, glm::vec3(0.395f, 0.275f, 0.99f));
        color = glm::vec4(0, 0, 0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //Circle --> ชามส่วนล่าง เทา
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0f, -0.041f, -0.999f));
        model = glm::scale(model, glm::vec3(0.39f, 0.275f, 0.99f));
        color = glm::vec4(228.0/255.0, 222.0/255.0, 234.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //Circle --> ชามส่วนล่าง ขาว
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0f, -0.07f, -0.999f));
        model = glm::scale(model, glm::vec3(0.38f, 0.288f, 0.99f));
        color = glm::vec4(1, 1, 1, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //Circle --> ชามส่วนล่าง ดำ
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0f, -0.063f, -0.999f));
        model = glm::scale(model, glm::vec3(0.389f, 0.299f, 0.99f));
        color = glm::vec4(0, 0, 0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //Circle 2
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0f, -0.04f, -0.99f));
        model = glm::scale(model, glm::vec3(0.35f, 0.22f, 0.97f));
        color = glm::vec4(226.0/255.0, 211.0/255.0, 182.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();


        //Rec1
        model = glm::mat4(1.0f);
        model = glm::rotate(model, -10 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        model = glm::translate(model, glm::vec3(-0.055f, 0.1f, -0.80f));
        model = glm::scale(model, glm::vec3(0.14f, 0.14f, 0.97f));
        color = glm::vec4(52.0/255.0, 63.0/255.0, 47.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[1]->RenderMesh();

        //Rec2
        model = glm::mat4(1.0f);
        model = glm::rotate(model, -10 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        model = glm::translate(model, glm::vec3(-0.19f, 0.05f, -0.80f));
        model = glm::scale(model, glm::vec3(0.14f, 0.14f, 0.97f));
        color = glm::vec4(45.0/255.0, 50.0/255.0, 43.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[1]->RenderMesh();


        // Egg1 --> ไข่ขาว
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.08f, 0.0802f, -0.7f));
        model = glm::rotate(model, 10 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        model = glm::scale(model, glm::vec3(0.071f, 0.043f, 0.97f));
        color = glm::vec4(254.0/255.0, 249.0/255.0, 219.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        // Egg1 --> ขอบไข่ขาว
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.08f, 0.0802f, -0.7f));
        model = glm::rotate(model, 10 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        model = glm::scale(model, glm::vec3(0.072f, 0.044f, 0.97f));
        color = glm::vec4(0, 0, 0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        // Egg1 --> เปลือก
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.083f, 0.0685f, -0.7f));
        model = glm::rotate(model, 10 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        model = glm::scale(model, glm::vec3(0.0712f, 0.043f, 0.97f));
        color = glm::vec4(192.0/255.0, 157.0/255.0, 101.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //Egg1 --> เปลือก ขอบดำ
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.083f, 0.0665f, -0.7f));
        model = glm::rotate(model, 10 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        model = glm::scale(model, glm::vec3(0.0713f, 0.042f, 0.97f));
        color = glm::vec4(0, 0, 0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //Egg1 ---> red egg
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0853f, 0.073f, -0.6f));
        model = glm::rotate(model, 10 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        model = glm::scale(model, glm::vec3(0.035f, 0.024f, 0.97f));
        color = glm::vec4(254.0/255.0, 164.0/255.0, 44.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //Egg1 ---> red egg ---> ตัดเส้นไข่แดง
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0853f, 0.073f, -0.6f));
        model = glm::rotate(model, 10 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        model = glm::scale(model, glm::vec3(0.036f, 0.025f, 0.97f));
        color = glm::vec4(0, 0, 0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //Egg2 ---> ไข่ขาว
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.143f, 0.0272f, -0.595f));
        model = glm::rotate(model, -20 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        model = glm::scale(model, glm::vec3(0.058f, 0.041f, 0.97f));
        color = glm::vec4(254.0/255.0, 249.0/255.0, 219.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //Egg2 ---> ตัดเส้นไข่ขาว
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.143f, 0.0272f, -0.595f));
        model = glm::rotate(model, -20 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        model = glm::scale(model, glm::vec3(0.059f, 0.042f, 0.97f));
        color = glm::vec4(0, 0, 0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //Egg2 --> เปลือก
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.142f, 0.022f, -0.595f));
        model = glm::rotate(model, -20 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        model = glm::scale(model, glm::vec3(0.061f, 0.047f, 0.97f));
        color = glm::vec4(192.0/255.0, 157.0/255.0, 101.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //Egg2 ---> เปลือกไข่ ตัดเส้น
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.142f, 0.022f, -0.595f));
        model = glm::rotate(model, -20 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        model = glm::scale(model, glm::vec3(0.062f, 0.048f, 0.97f));
        color = glm::vec4(0, 0, 0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //Egg2 ---> red egg
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.155f, 0.02f, -0.59f));
        model = glm::rotate(model, -20 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        model = glm::scale(model, glm::vec3(0.035f, 0.028f, 0.97f));
        color = glm::vec4(1, 120.0/255.0, 46.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //Egg2 ---> red egg ตัดเส้น
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.155f, 0.02f, -0.59f));
        model = glm::rotate(model, -20 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        model = glm::scale(model, glm::vec3(0.036f, 0.029f, 0.97f));
        color = glm::vec4(0, 0, 0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //Beef
        model = glm::mat4(1.0f);
        model = glm::rotate(model, -25 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        model = glm::translate(model, glm::vec3(-0.0152f, -0.115f, -0.4f));
        model = glm::scale(model, glm::vec3(0.194f, 0.194f, 0.1f));
        color = glm::vec4(185.0/255.0, 145.0/255.0, 109.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[2]->RenderMesh();

        //Beef --> ตัดเส้น
        model = glm::mat4(1.0f);
        model = glm::rotate(model, -25 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        model = glm::translate(model, glm::vec3(-0.0171f, -0.116f, -0.4f));
        model = glm::scale(model, glm::vec3(0.198f, 0.196f, 0.1f));
        color = glm::vec4(0, 0, 0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[2]->RenderMesh();

        //Beef 2
        model = glm::mat4(1.0f);
        model = glm::rotate(model, -10 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        model = glm::translate(model, glm::vec3(-0.055f, -0.144f, -0.3999f));
        model = glm::scale(model, glm::vec3(0.194f, 0.194f, 0.1f));
        color = glm::vec4(161.0/255.0, 126.0/255.0, 94.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[2]->RenderMesh();

        //Beef 2 --> ตัดเส้น
        model = glm::mat4(1.0f);
        model = glm::rotate(model, -10 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        model = glm::translate(model, glm::vec3(-0.056f, -0.146f, -0.3999f));
        model = glm::scale(model, glm::vec3(0.197f, 0.197f, 0.1f));
        color = glm::vec4(0, 0, 0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[2]->RenderMesh();

        //แสง
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(-0.093f, -0.0624f, -0.39994f));
        model = glm::rotate(model, -29 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        model = glm::scale(model, glm::vec3(0.03f, 0.01f, 0.97f));
        color = glm::vec4(1, 1, 1, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow yellow
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(-0.2f, triOffset+(-0.15f), -0.301f));
        model = glm::scale(model, glm::vec3(0.015f, 0.015f, 0.97f));
        color = glm::vec4(244.0/255.0, 216.0/255.0, 113.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow mouse
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(-0.2f, triOffset+(-0.157f), -0.3f));
        model = glm::scale(model, glm::vec3(0.004f, 0.006f, 0.97f));
        color = glm::vec4(44.0/255.0, 48.0/255.0, 58.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow eye1
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(-0.205f, triOffset+(-0.145f), -0.299f));
        model = glm::scale(model, glm::vec3(0.003f, 0.004f, 0.97f));
        color = glm::vec4(44.0/255.0, 48.0/255.0, 58.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow eye1.2
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(-0.195f, triOffset+(-0.145f), -0.299f));
        model = glm::scale(model, glm::vec3(0.003f, 0.004f, 0.97f));
        color = glm::vec4(44.0/255.0, 48.0/255.0, 58.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        
        //wow yellow 2
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(-0.15f, triOffset+(-0.17f), -0.301f));
        model = glm::scale(model, glm::vec3(0.015f, 0.015f, 0.97f));
        color = glm::vec4(244.0/255.0, 216.0/255.0, 113.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow mouse2
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(-0.15f, triOffset+(-0.177f), -0.3f));
        model = glm::scale(model, glm::vec3(0.004f, 0.006f, 0.97f));
        color = glm::vec4(44.0/255.0, 48.0/255.0, 58.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow eye2
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(-0.155f, triOffset+(-0.165f), -0.299f));
        model = glm::scale(model, glm::vec3(0.003f, 0.004f, 0.97f));
        color = glm::vec4(44.0/255.0, 48.0/255.0, 58.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow eye2.2
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(-0.145f, triOffset+(-0.165f), -0.299f));
        model = glm::scale(model, glm::vec3(0.003f, 0.004f, 0.97f));
        color = glm::vec4(44.0/255.0, 48.0/255.0, 58.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow yellow 3
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(-0.1f, triOffset+(-0.17f), -0.301f));
        model = glm::scale(model, glm::vec3(0.015f, 0.015f, 0.97f));
        color = glm::vec4(244.0/255.0, 216.0/255.0, 113.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow mouse3
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(-0.1f, triOffset+(-0.177f), -0.3f));
        model = glm::scale(model, glm::vec3(0.004f, 0.006f, 0.97f));
        color = glm::vec4(44.0/255.0, 48.0/255.0, 58.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow eye3.1
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(-0.105f, triOffset+(-0.165f), -0.299f));
        model = glm::scale(model, glm::vec3(0.003f, 0.004f, 0.97f));
        color = glm::vec4(44.0/255.0, 48.0/255.0, 58.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow eye3.2
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(-0.095f, triOffset+(-0.165f), -0.299f));
        model = glm::scale(model, glm::vec3(0.003f, 0.004f, 0.97f));
        color = glm::vec4(44.0/255.0, 48.0/255.0, 58.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow yellow 4
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(-0.03f, triOffset+(-0.17f), -0.301f));
        model = glm::scale(model, glm::vec3(0.015f, 0.015f, 0.97f));
        color = glm::vec4(244.0/255.0, 216.0/255.0, 113.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow mouse4
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(-0.03f, triOffset+(-0.177f), -0.3f));
        model = glm::scale(model, glm::vec3(0.004f, 0.006f, 0.97f));
        color = glm::vec4(44.0/255.0, 48.0/255.0, 58.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow eye4.1
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(-0.035f, triOffset+(-0.165f), -0.299f));
        model = glm::scale(model, glm::vec3(0.003f, 0.004f, 0.97f));
        color = glm::vec4(44.0/255.0, 48.0/255.0, 58.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow eye4.2
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(-0.025f, triOffset+(-0.165f), -0.299f));
        model = glm::scale(model, glm::vec3(0.003f, 0.004f, 0.97f));
        color = glm::vec4(44.0/255.0, 48.0/255.0, 58.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow yellow 5
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.01f, triOffset+(-0.21f), -0.301f));
        model = glm::scale(model, glm::vec3(0.015f, 0.015f, 0.97f));
        color = glm::vec4(244.0/255.0, 216.0/255.0, 113.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow mouse5
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.01f, triOffset+(-0.217f), -0.3f));
        model = glm::scale(model, glm::vec3(0.004f, 0.006f, 0.97f));
        color = glm::vec4(44.0/255.0, 48.0/255.0, 58.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow eye5.1
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.015f, triOffset+(-0.205f), -0.299f));
        model = glm::scale(model, glm::vec3(0.003f, 0.004f, 0.97f));
        color = glm::vec4(44.0/255.0, 48.0/255.0, 58.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow eye5.2
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.005f, triOffset+(-0.205f), -0.299f));
        model = glm::scale(model, glm::vec3(0.003f, 0.004f, 0.97f));
        color = glm::vec4(44.0/255.0, 48.0/255.0, 58.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow yellow 6
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.100f, triOffset+(-0.18f), -0.301f));
        model = glm::scale(model, glm::vec3(0.015f, 0.015f, 0.97f));
        color = glm::vec4(244.0/255.0, 216.0/255.0, 113.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow mouse6
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.100f, triOffset+(-0.187f), -0.3f));
        model = glm::scale(model, glm::vec3(0.004f, 0.006f, 0.97f));
        color = glm::vec4(44.0/255.0, 48.0/255.0, 58.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow eye6.1
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.105f, triOffset+(-0.175f), -0.299f));
        model = glm::scale(model, glm::vec3(0.003f, 0.004f, 0.97f));
        color = glm::vec4(44.0/255.0, 48.0/255.0, 58.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow eye6.2
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.095f, triOffset+(-0.175f), -0.299f));
        model = glm::scale(model, glm::vec3(0.003f, 0.004f, 0.97f));
        color = glm::vec4(44.0/255.0, 48.0/255.0, 58.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow yellow 7
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.190f, triOffset+(-0.18f), -0.301f));
        model = glm::scale(model, glm::vec3(0.015f, 0.015f, 0.97f));
        color = glm::vec4(244.0/255.0, 216.0/255.0, 113.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow mouse7
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.190f, triOffset+(-0.187f), -0.3f));
        model = glm::scale(model, glm::vec3(0.004f, 0.006f, 0.97f));
        color = glm::vec4(44.0/255.0, 48.0/255.0, 58.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow eye7.1
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.195f, triOffset+(-0.175f), -0.299f));
        model = glm::scale(model, glm::vec3(0.003f, 0.004f, 0.97f));
        color = glm::vec4(44.0/255.0, 48.0/255.0, 58.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow eye7.2
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.185f, triOffset+(-0.175f), -0.299f));
        model = glm::scale(model, glm::vec3(0.003f, 0.004f, 0.97f));
        color = glm::vec4(44.0/255.0, 48.0/255.0, 58.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow yellow 8
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.145f, triOffset+(-0.22f), -0.301f));
        model = glm::scale(model, glm::vec3(0.015f, 0.015f, 0.97f));
        color = glm::vec4(244.0/255.0, 216.0/255.0, 113.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow mouse8
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.145f, triOffset+(-0.227f), -0.3f));
        model = glm::scale(model, glm::vec3(0.004f, 0.006f, 0.97f));
        color = glm::vec4(44.0/255.0, 48.0/255.0, 58.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow eye8.1
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.150f, triOffset+(-0.215f), -0.299f));
        model = glm::scale(model, glm::vec3(0.003f, 0.004f, 0.97f));
        color = glm::vec4(44.0/255.0, 48.0/255.0, 58.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow eye8.2
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.140f, triOffset+(-0.215f), -0.299f));
        model = glm::scale(model, glm::vec3(0.003f, 0.004f, 0.97f));
        color = glm::vec4(44.0/255.0, 48.0/255.0, 58.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow yellow 9
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(-0.145f, triOffset+(-0.22f), -0.301f));
        model = glm::scale(model, glm::vec3(0.015f, 0.015f, 0.97f));
        color = glm::vec4(244.0/255.0, 216.0/255.0, 113.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow mouse9
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(-0.145f, triOffset+(-0.227f), -0.3f));
        model = glm::scale(model, glm::vec3(0.004f, 0.006f, 0.97f));
        color = glm::vec4(44.0/255.0, 48.0/255.0, 58.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow eye9.1
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(-0.150f, triOffset+(-0.215f), -0.299f));
        model = glm::scale(model, glm::vec3(0.003f, 0.004f, 0.97f));
        color = glm::vec4(44.0/255.0, 48.0/255.0, 58.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow eye9.2
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(-0.140f, triOffset+(-0.215f), -0.299f));
        model = glm::scale(model, glm::vec3(0.003f, 0.004f, 0.97f));
        color = glm::vec4(44.0/255.0, 48.0/255.0, 58.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow yellow 10
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(-0.2f, triOffset+(-0.27f), -0.301f));
        model = glm::scale(model, glm::vec3(0.015f, 0.015f, 0.97f));
        color = glm::vec4(244.0/255.0, 216.0/255.0, 113.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow mouse 10
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(-0.2f, triOffset+(-0.277f), -0.3f));
        model = glm::scale(model, glm::vec3(0.004f, 0.006f, 0.97f));
        color = glm::vec4(44.0/255.0, 48.0/255.0, 58.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow eye10.1
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(-0.205f, triOffset+(-0.265f), -0.299f));
        model = glm::scale(model, glm::vec3(0.003f, 0.004f, 0.97f));
        color = glm::vec4(44.0/255.0, 48.0/255.0, 58.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow eye10.2
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(-0.195f, triOffset+(-0.265f), -0.299f));
        model = glm::scale(model, glm::vec3(0.003f, 0.004f, 0.97f));
        color = glm::vec4(44.0/255.0, 48.0/255.0, 58.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow yellow 11
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(-0.1f, triOffset+(-0.30f), -0.301f));
        model = glm::scale(model, glm::vec3(0.015f, 0.015f, 0.97f));
        color = glm::vec4(244.0/255.0, 216.0/255.0, 113.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow mouse 11
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(-0.1f, triOffset+(-0.307f), -0.3f));
        model = glm::scale(model, glm::vec3(0.004f, 0.006f, 0.97f));
        color = glm::vec4(44.0/255.0, 48.0/255.0, 58.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow eye 11
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(-0.105f, triOffset+(-0.295f), -0.299f));
        model = glm::scale(model, glm::vec3(0.003f, 0.004f, 0.97f));
        color = glm::vec4(44.0/255.0, 48.0/255.0, 58.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow eye 11.2
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(-0.095f, triOffset+(-0.295f), -0.299f));
        model = glm::scale(model, glm::vec3(0.003f, 0.004f, 0.97f));
        color = glm::vec4(44.0/255.0, 48.0/255.0, 58.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow yellow 12
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.100f, triOffset+(-0.26f), -0.301f));
        model = glm::scale(model, glm::vec3(0.015f, 0.015f, 0.97f));
        color = glm::vec4(244.0/255.0, 216.0/255.0, 113.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow mouse 12
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.100f, triOffset+(-0.267f), -0.3f));
        model = glm::scale(model, glm::vec3(0.004f, 0.006f, 0.97f));
        color = glm::vec4(44.0/255.0, 48.0/255.0, 58.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow eye 12.1
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.105f, triOffset+(-0.255f), -0.299f));
        model = glm::scale(model, glm::vec3(0.003f, 0.004f, 0.97f));
        color = glm::vec4(44.0/255.0, 48.0/255.0, 58.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow eye 12.2
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.095f, triOffset+(-0.255f), -0.299f));
        model = glm::scale(model, glm::vec3(0.003f, 0.004f, 0.97f));
        color = glm::vec4(44.0/255.0, 48.0/255.0, 58.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow yellow 13
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.190f, triOffset+(-0.29f), -0.301f));
        model = glm::scale(model, glm::vec3(0.015f, 0.015f, 0.97f));
        color = glm::vec4(244.0/255.0, 216.0/255.0, 113.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow mouse 13
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.190f, triOffset+(-0.297f), -0.3f));
        model = glm::scale(model, glm::vec3(0.004f, 0.006f, 0.97f));
        color = glm::vec4(44.0/255.0, 48.0/255.0, 58.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow eye 13.1
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.195f, triOffset+(-0.285f), -0.299f));
        model = glm::scale(model, glm::vec3(0.003f, 0.004f, 0.97f));
        color = glm::vec4(44.0/255.0, 48.0/255.0, 58.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow eye 13.2
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.185f, triOffset+(-0.285f), -0.299f));
        model = glm::scale(model, glm::vec3(0.003f, 0.004f, 0.97f));
        color = glm::vec4(44.0/255.0, 48.0/255.0, 58.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow yellow 14
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.01f, triOffset+(-0.28f), -0.301f));
        model = glm::scale(model, glm::vec3(0.015f, 0.015f, 0.97f));
        color = glm::vec4(244.0/255.0, 216.0/255.0, 113.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow mouse 14
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.01f, triOffset+(-0.287f), -0.3f));
        model = glm::scale(model, glm::vec3(0.004f, 0.006f, 0.97f));
        color = glm::vec4(44.0/255.0, 48.0/255.0, 58.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow eye 14.1
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.015f, triOffset+(-0.275f), -0.299f));
        model = glm::scale(model, glm::vec3(0.003f, 0.004f, 0.97f));
        color = glm::vec4(44.0/255.0, 48.0/255.0, 58.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        //wow eye 14.2
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.005f, triOffset+(-0.275f), -0.299f));
        model = glm::scale(model, glm::vec3(0.003f, 0.004f, 0.97f));
        color = glm::vec4(44.0/255.0, 48.0/255.0, 58.0/255.0, 1);
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        model = glm::rotate(model, 90 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform4fv(uniformColor, 1, glm::value_ptr(color));
        meshList[0]->RenderMesh();

        glUseProgram(0);
        //end draw

        mainWindow.swapBuffers();
    }

    return 0;
}
