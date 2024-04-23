#pragma once
#include "SFML//Graphics.hpp"

class ReflectiveBouncePads
{
public:

	ReflectiveBouncePads();
	void setUpBP(sf::Vector2f t_bouncePos);

	sf::RectangleShape getBouncePad() { return bouncePad; }

	//player Knockback Info
	float angle = 0.0f;
	float power = 0.1f;
	bool hasHit = false;

private:

	sf::RectangleShape bouncePad;
	float width = 300;
	float height = 25;
	sf::Vector2f BPposition;
};