#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <map>
#include <SFML/Graphics.hpp>

class AssetManager
{
public:
    AssetManager();

    static sf::Texture& GetTexture(std::string const& fileName);
    static sf::Font& GetFont(std::string const& fileName);

private:
    std::map< std::string, sf::Texture > texMap;
    std::map< std::string, sf::Font > fontMap;
    static AssetManager* sInstance;

};

#endif // ASSETMANAGER_H
