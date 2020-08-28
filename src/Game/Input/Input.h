#pragma once
#include <GLFW/glfw3.h>

class Input
{
  public:
    static void Init(GLFWwindow* window);

    static bool IsKeyPressed(int key);

  private:
    static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
    static bool ms_Keys[1024];
};