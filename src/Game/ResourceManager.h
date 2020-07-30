#pragma once

#include <unordered_map>
#include <string>

#include "Game/Texture.h"
#include "Game/Shader.h"

class ResourceManager
{
  public:
    static Shader& LoadShader(std::string const& vShaderFile,
                              std::string const& fShaderFile,
                              std::string const& gShaderFile, 
                              std::string const& name);

    static Texture2D& LoadTexture(std::string const& file,
                                  bool alpha,
                                  std::string const& name);

    static Shader& GetShader(std::string const& name);
    static Texture2D& GetTexture(std::string const& name);

    static void Clear();

  private:
    ResourceManager() { }
    
    static Shader LoadShaderFromFile(std::string const& vShaderFile,
                                     std::string const& fShaderFile,
                                     std::string const& gShaderFile = "");

    static Texture2D LoadTextureFromFile(std::string const& file, bool alpha);

    static std::unordered_map<std::string, Shader>    ms_Shaders;
    static std::unordered_map<std::string, Texture2D> ms_Textures;
};