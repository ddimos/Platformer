#include "Game/Input.h"

bool Input::ms_Keys[1024] = {};

void Input::Init(GLFWwindow* window)
{
    glfwSetKeyCallback(window, Input::KeyCallback);
}

bool Input::IsKeyPressed(int key)
{
    if (key >= 0 && key < 1024)
    {
        return ms_Keys[key];
    }
    else
    {
        return false;   // TODO: Add a log
    }
    
}

void Input::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if (key >= 0 && key < 1024)
    {
        if (action == GLFW_PRESS)
        {
            ms_Keys[key] = true;
        }
        else if (action == GLFW_RELEASE)
        {
            ms_Keys[key] = false;
        }
    }
}