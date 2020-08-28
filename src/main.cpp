#include <Extern/glad/glad.h>
#include <GLFW/glfw3.h>

#include "Game/Game.h"
#include "Game/ResourceManager.h"
#include "Game/Input/Input.h"
#include <iostream>

// GLFW function declerations
bool GlfwInit();
void FramebufferSizeCallback(GLFWwindow* window, int width, int height);

//Create the Game instance
Game g_Game(SCREEN_WIDTH, SCREEN_HEIGHT);

GLFWwindow* g_Window = nullptr;

int main(int argc, char *argv[])
{
    if (!GlfwInit())
    {
        return -1;
    }

    // initialize game
    Input::Init(g_Window);
    g_Game.Init();

    float deltaTime = 0.0f;
    float lastFrame = 0.0f;

    g_Game.State = GAME_MENU;//TODO: StateMachine

    while (!glfwWindowShouldClose(g_Window))
    {
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        glfwPollEvents();

        // when a user presses the escape key, close the application
        if (Input::IsKeyPressed(GLFW_KEY_ESCAPE))
        {
            glfwSetWindowShouldClose(g_Window, true);
        }

        g_Game.ProcessInput(deltaTime);

        g_Game.Update(deltaTime);

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        g_Game.Render();

        glfwSwapBuffers(g_Window);
    }

    ResourceManager::Clear();// TODO: move to destructor

    glfwTerminate();
    return 0;
}

bool GlfwInit()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    glfwWindowHint(GLFW_RESIZABLE, false);

    g_Window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_NAME.c_str(), nullptr, nullptr);
    glfwMakeContextCurrent(g_Window);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return false;
    }

    glfwSetFramebufferSizeCallback(g_Window, FramebufferSizeCallback);

    // OpenGL configuration
    // --------------------
    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    return true;
}

void FramebufferSizeCallback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}
