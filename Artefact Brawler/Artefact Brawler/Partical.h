#pragma once

#include <SFML/Graphics.hpp>

#include "Globals.h"

class Partical
{
public:

	Partical();

	void setColor(sf::Color t_color) { body.setFillColor(t_color); }
	sf::RectangleShape getBody() { return body; }

	void spawn(sf::Vector2f t_pos);

	void move();

	void bounds();

	bool active = false;

private:

	void setup();

	sf::RectangleShape body;
	float size = 0;
	const int MIN_SIZE = 1;

	sf::Vector2f position;
	int speed = 0;
	const int MIN_SPEED = 2;

	float angle = 0.0f;
	sf::Vector2f direction;
};

