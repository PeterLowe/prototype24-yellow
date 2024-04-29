// IAN PEREZ BUNUEL VIT PRECHTL

#include "Platform.h"

Platform::Platform()
{
}

void Platform::setup(sf::Vector2f t_pos, int levelRandomIndex)
{
	position = t_pos;
	body.setPosition(position);
	body.setFillColor(sf::Color::Green);
	body.setSize({ width, height });
	body.setOrigin({ width / 2.0f, height / 2.0f });

	ground.setPosition(position + GROUND_DISPLACEMENT);
	ground.setFillColor(sf::Color::White);
	ground.setSize({ width, 10.0f });
	ground.setOrigin({ width / 2.0f, 0.5f });

	// Platform - Colosseum
	if (!platformColosseumTexture.loadFromFile("ASSETS\\IMAGES\\Platform.png"))
	{
		std::cout << "problem loading Platform texture" << std::endl;

	}
	if (!platformTempleTexture.loadFromFile("ASSETS\\IMAGES\\TemplePlatform.png"))
	{
		std::cout << "problem loading Temple Platform texture" << std::endl;

	}
	platformColosseumSprite.setTexture(platformColosseumTexture);
	platformColosseumSprite.setPosition(position);
	platformColosseumSprite.setOrigin(48, 11);
	platformColosseumSprite.setScale(2, 2);

	if (levelRandomIndex == 2)
	{
		platformColosseumSprite.setTexture(platformTempleTexture);
	}
}
