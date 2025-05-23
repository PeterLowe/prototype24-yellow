// IAN PEREZ BUNUEL VIT PRECHTL

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Platform
{
public:
	Platform();

	void setup(sf::Vector2f t_pos, int levelRandomIndex);
	sf::RectangleShape getBody() { return body; }
	sf::RectangleShape getGround() { return ground; }
	sf::Sprite getPlatformSprite() { return platformColosseumSprite; }

private:

	// Body
	sf::RectangleShape body;
	float width = 200;
	float height = 20;
	sf::Vector2f position;

	sf::RectangleShape ground; // { Same width, 1.0f }
	const sf::Vector2f GROUND_DISPLACEMENT = { 0.0f, -15 };

	// Platform - Colosseum
	sf::Sprite platformColosseumSprite;
	sf::Texture platformColosseumTexture;
	// Platform - Temple
	sf::Sprite platformTempleSprite;
	sf::Texture platformTempleTexture;
};

