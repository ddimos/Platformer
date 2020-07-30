#include "Game/Game.h"
#include "Game/ResourceManager.h"

SpriteRenderer  *Renderer;

Game::Game(unsigned int width, unsigned int height) 
    : State(GAME_ACTIVE), Width(width), Height(height)
{ 

}

Game::~Game()
{
    
}

void Game::Init()
{
   ResourceManager::LoadShader("Data/shaders/sprite.vs", "Data/shaders/sprite.frag", "", "sprite");
    // configure shaders
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(this->Width), 
        static_cast<float>(this->Height), 0.0f, -1.0f, 1.0f);
    ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
    ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);
    // set render-specific controls;
    Renderer = new SpriteRenderer(ResourceManager::GetShader("sprite"));
    // load textures
    ResourceManager::LoadTexture("Data/textures/p1_front.png", true, "player");
}

void Game::Update(float dt)
{
    
}

void Game::ProcessInput(float dt)
{
   
}

void Game::Render()
{
    Renderer->DrawSprite(ResourceManager::GetTexture("player"),
        glm::vec2(200.0f, 200.0f), glm::vec2(300.0f, 400.0f), 45.0f, glm::vec3(1.0f, 1.0f, 0.0f));
}