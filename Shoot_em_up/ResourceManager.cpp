#include "RessourceManager.h" 

void RessourceManager::Render()
{

}
sf::Texture& RessourceManager::getTexture(const std::string path)
{

    for (auto& texture : m_allTextureInfo)
    {
        if (texture.path == path)
            return *texture.texture;
    }


    TextureInfo Ti;
    Ti.path = path;
    Ti.texture = new sf::Texture;
    Ti.texture->loadFromFile(path);
    m_allTextureInfo.push_back(Ti);


    return *m_allTextureInfo.back().texture;
}


