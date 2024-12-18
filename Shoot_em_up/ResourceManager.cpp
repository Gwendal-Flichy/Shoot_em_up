#include "ResourceManager.h"

sf::Texture& TextureCash::getTexture(const std::string path)
{

    for (auto& texture : m_allTextureInfo)
    {
        if (texture.path == path)
            return *texture.texture;
    }


    TextureInfo ti;
    ti.path = path;
    ti.texture = new sf::Texture;
    ti.texture->loadFromFile(path);
    m_allTextureInfo.push_back(ti);


    return *m_allTextureInfo.back().texture;
}