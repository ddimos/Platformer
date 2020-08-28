#include "Game/Game.h"
#include "Game/ResourceManager.h"
#include "Game/Input/Input.h"
#include "Game/Render/SpriteRenderer.h"
#include "Game/Base/BaseObject.h"

SpriteRenderer  *Renderer;

PL_MATH::Vec2D PlayerPosition = 0.f;
float PlayerSpeed = 50.f;
PL_MATH::Vec2D BrickPosition = 300.f;

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

    m_Objects.push_back(std::make_unique<BaseObject>(
        PL_MATH::Vec2D{50.0f},
        PL_MATH::Vec2D{300.0f},
        PL_MATH::Vec2D{0.0f},
        0.0f,
        ResourceManager::GetTexture("brickWall")));

    m_Objects.push_back(std::make_unique<Player>(
        PL_MATH::Vec2D{50.0f},
        PL_MATH::Vec2D{0.0f},
        PL_MATH::Vec2D{20.0f},
        0.0f,
        ResourceManager::GetTexture("player")));
}

void Game::Update(float dt)
{
    for (auto& obj : m_Objects)
    {
        obj->Update(dt);
    }
    
}

void Game::ProcessInput(float dt)
{  
}

void Game::Render()
{
    Renderer->DrawSprite(ResourceManager::GetTexture("background"), 
            PL_MATH::Vec2D(0.0f, 0.0f), PL_MATH::Vec2D(this->Width, this->Height), 0.0f);

    for (auto& obj : m_Objects)
    {
        obj->Draw(*Renderer);
    }
}