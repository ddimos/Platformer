#pragma once

//#include <Extern/glad/glad.h>
//#include <GLFW/glfw3.h>

#include "Game/Constants.h"
#include "Game/SpriteRenderer.h"

// Represents the current state of the game
enum GameState {
    GAME_ACTIVE,
    GAME_MENU,
    GAME_WIN
};

// Game holds all game-related state and functionality.
// Combines all game-related data into a single class for
// easy access to each of the components and manageability.
class Game
{
public:
    //static Game * g_Game;
    
    Game(unsigned int width, unsigned int height);
    ~Game();
    
    // game state
    GameState               State;	
    
    unsigned int            Width, Height;
    // constructor/destructor
    // initialize game state (load all shaders/textures/levels)
    void Init();
    // game loop
    void ProcessInput(float dt);
    void Update(float dt);
    void Render();
};