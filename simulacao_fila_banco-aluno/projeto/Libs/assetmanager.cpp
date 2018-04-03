#include "assetmanager.h"

#include <cassert>

AssetManager* AssetManager::sInstance = nullptr;

AssetManager::AssetManager()
{
    assert(sInstance == nullptr);
    this->sInstance = this;
}

sf::Texture &AssetManager::GetTexture(const std::string &fileName)
{
    try
    {
        return sInstance->texMap.at(fileName);
    }
    catch (...)
    {
        sf::Texture& texture = sInstance->texMap[fileName];
        if (texture.loadFromFile(fileName))
            return texture;
        else
            throw;
    }
}

sf::Font &AssetManager::GetFont(const std::string &fileName)
{
    try
    {
        return sInstance->fontMap.at(fileName);
    }
    catch (...)
    {
        sf::Font& font = sInstance->fontMap[fileName];
        if (font.loadFromFile(fileName))
            return font;
        else
            throw;
    }
}

