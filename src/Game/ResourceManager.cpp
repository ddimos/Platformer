#include "Game/ResourceManager.h"

#include <iostream>
#include <sstream>
#include <fstream>

#include <Extern/glad/glad.h>

#define STB_IMAGE_IMPLEMENTATION
#include "Extern/stb/stb_image.h"

std::unordered_map<std::string, Texture2D>    ResourceManager::ms_Textures;
std::unordered_map<std::string, Shader>       ResourceManager::ms_Shaders;

Shader& ResourceManager::LoadShader(
    std::string const& vShaderFile,
    std::string const& fShaderFile,
    std::string const& gShaderFile, 
    std::string const& name)
{
    ms_Shaders[name] =
      LoadShaderFromFile(vShaderFile, fShaderFile, gShaderFile);
    return ms_Shaders[name];
}

Shader& ResourceManager::GetShader(std::string const& name)
{
    return ms_Shaders[name];
}

Texture2D& ResourceManager::LoadTexture(
    std::string const& file,
    bool alpha,
    std::string const& name)
{
    ms_Textures[name] = LoadTextureFromFile(file, alpha);
    return ms_Textures[name];
}

Texture2D& ResourceManager::GetTexture(std::string const& name)
{
    return ms_Textures[name];
}

void ResourceManager::Clear()
{	
    for (auto const& iter : ms_Shaders)
    {
        glDeleteProgram(iter.second.ID);
    }
    for (auto const& iter : ms_Textures)
    {
        glDeleteTextures(1, &iter.second.ID);
    }
    ms_Shaders.clear();
    ms_Textures.clear();
}

Shader ResourceManager::LoadShaderFromFile(
    std::string const& vShaderFile, 
    std::string const& fShaderFile, 
    std::string const& gShaderFile)
{
    // 1. retrieve the vertex/fragment source code from filePath
    std::string vertexCode;
    std::string fragmentCode;
    std::string geometryCode;
    try
    {
        // open files
        std::ifstream vertexShaderFile(vShaderFile);
        std::ifstream fragmentShaderFile(fShaderFile);
        std::stringstream vShaderStream, fShaderStream;
        // read file's buffer contents into streams
        vShaderStream << vertexShaderFile.rdbuf();
        fShaderStream << fragmentShaderFile.rdbuf();
        // close file handlers
        vertexShaderFile.close();
        fragmentShaderFile.close();
        // convert stream into string
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
        // if geometry shader path is present, also load a geometry shader
        if (gShaderFile != "")
        {
            std::ifstream geometryShaderFile(gShaderFile);
            std::stringstream gShaderStream;
            gShaderStream << geometryShaderFile.rdbuf();
            geometryShaderFile.close();
            geometryCode = gShaderStream.str();
        }
    }
    catch (std::exception e)
    {
        std::cout << "ERROR::SHADER: Failed to read shader files" << std::endl;
    }
    const char *vShaderCode = vertexCode.c_str();
    const char *fShaderCode = fragmentCode.c_str();
    const char *gShaderCode = geometryCode.c_str();
    // 2. now create shader object from source code
    Shader shader;
    shader.Compile(vShaderCode, fShaderCode,  gShaderFile == "" ? nullptr : gShaderCode);
    return shader;
}

Texture2D ResourceManager::LoadTextureFromFile(
    std::string const& file, bool alpha)
{
    // create texture object
    Texture2D texture;
    if (alpha)
    {
        texture.Internal_Format = GL_RGBA;
        texture.Image_Format = GL_RGBA;
    }
    // load image
    int width, height, nrChannels;
    unsigned char* data = stbi_load(file.c_str(), &width, &height, &nrChannels, 0);
    // now generate texture
    texture.Generate(width, height, data);
    // and finally free image data
    stbi_image_free(data);
    return texture;
}