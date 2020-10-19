// OpenGLCourseApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdio.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

// Window dimension
const GLint WIDTH = 800, HEIGHT = 600;

int main()
{
    //Initialise GLFW
    if (!glfwInit())
    {
        printf("GLFW initialed is Failed");
        glfwTerminate();
        return 1;

    };

    //Setup GLFW window properties
    //Opengl Version
    glfwInitHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwInitHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    //Core profile = no Backwards Compatibility
    glfwInitHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //Allow forward compatibility
    glfwInitHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);


    GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Test Window", NULL, NULL);
    if (!mainWindow)
    {
        printf("GLFW window creation filed");
        glfwTerminate();
        return  1;
    }

    //get buffer size information

    int bufferWidth, bufferHeight;
    glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

    //set context for GLFW to use
    glfwMakeContextCurrent(mainWindow);

    //Allow modern extension features

    glewExperimental = GL_TRUE;

    if (!glewInit())
    {
        printf("GlEW initialised  filed");
        glfwDestroyWindow(mainWindow);
        glfwTerminate();
        return  1;


    }

    // setup ViewPort Size

    glViewport(0, 0, bufferWidth, bufferHeight);


    // Loop until window closed

    while (!glfwWindowShouldClose(mainWindow))
    {
        //Get + hundle user input events
        glfwPollEvents();


        //Clear window

        glClearColor(1.0f, 0.f, 0.f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

    }








    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
