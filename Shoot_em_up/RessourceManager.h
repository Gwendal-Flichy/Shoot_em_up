#pragma once
#include "IGraphics.h"
#include <SFML/Graphics.hpp>
#include <string>

class RessourceManager : public IGraphics
{
public:
	void Render();
	sf::Texture& getTexture(const std::string path);
private:
	struct TextureInfo
	{
		sf::Texture* texture;
		std::string path;
	};
	std::vector< TextureInfo> m_allTextureInfo;

};