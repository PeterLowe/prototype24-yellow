// IAN PEREZ BUNUEL

#pragma once

#include <SFML/Graphics.hpp>

#include "Globals.h"

class Partical
{
public:

	Partical();

	void setColor(sf::Color t_color) { body.setFillColor(t_color); }
	sf::RectangleShape getBody() { return body; }
	sf::Sprite getSprite() { return sprite; }

	void spawn(sf::Vector2f t_pos);

	void move();

	void bounds();

	bool active = false;

private:

	void setup();

	sf::RectangleShape body;
	sf::Sprite sprite;
	sf::Texture texture;

	float size = 0.0f;
	const int MIN_SIZE = 1;

	float scale = 0.0f;
	const float MIN_SCALE = 0.2f;

	sf::Vector2f position;
	int speed = 0;
	const int MIN_SPEED = 2;

	float angle = 0.0f;
	sf::Vector2f direction;
};

