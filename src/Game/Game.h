#pragma once

#include <vector>
#include <memory>

#include "Constants.h"

class BaseObject;

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
private:
    std::vector<std::unique_ptr<BaseObject>> m_Objects;
    
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