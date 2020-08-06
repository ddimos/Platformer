#include "Game/Game.h"
#include "Game/ResourceManager.h"
#include "Game/Input.h"

SpriteRenderer  *Renderer;

Vec2D PlayerPosition = 0.f;
float PlayerSpeed = 50.f;
Vec2D BrickPosition = 300.f;

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
    ResourceManager::LoadTexture("Data/textures/background.jpg", false, "background");
    ResourceManager::LoadTexture("Data/textures/p1_front.png", true, "player");
    ResourceManager::LoadTexture("Data/textures/brickWall.png", true, "brickWall");
}

void Game::Update(float dt)
{
    
}

void Game::ProcessInput(float dt)
{
    if (Input::IsKeyPressed('A'))
    {
        PlayerPosition.x -= PlayerSpeed * dt;
    }
    else if (Input::IsKeyPressed('D'))
    {
        PlayerPosition.x += PlayerSpeed * dt;
    }

    if (Input::IsKeyPressed('W'))
    {
        PlayerPosition.y -= PlayerSpeed * dt;
    }
    else if (Input::IsKeyPressed('S'))
    {
        PlayerPosition.y += PlayerSpeed * dt;
    }    
}

void Game::Render()
{
    Renderer->DrawSprite(ResourceManager::GetTexture("background"), 
            Vec2D(0.0f, 0.0f), Vec2D(this->Width, this->Height), 0.0f);

    Renderer->DrawSprite(ResourceManager::GetTexture("player"),
        PlayerPosition, Vec2D(100.f,50.0f), 0.0f, glm::vec3(1.0f, 1.0f, 0.0f));

    Renderer->DrawSprite(ResourceManager::GetTexture("brickWall"),
        BrickPosition, Vec2D(100.f,50.0f), 0.0f);
    
}