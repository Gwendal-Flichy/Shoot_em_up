#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "vector"


class TextureCash
{
public:
	sf::Texture& getTexture(const std::string path);
private:
	struct TextureInfo
	{
		sf::Texture* texture;
		std::string path;
	};
	std::vector<TextureInfo> m_allTextureInfo;
};
