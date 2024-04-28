// IAN PEREZ BUNUEL

#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "AttackManager.h"

enum class AttackVarients
{
	Neutral,
	SideLeft,
	SideRight,
	Up,
	Down
};


class shopButtons
{
public:
	sf::RectangleShape getBody() { return body; }

	void setup(sf::Vector2f t_pos, float t_width, float t_height, int t_price, AttackVarients t_attackType, sf::Color t_color);
	void draw(sf::RenderWindow& t_window);

	bool checkForMouse(sf::Vector2f t_mousePos);

	void onPress(int& t_coins, SpecialType t_attack);


	bool unlocked = false;

private:

	sf::RectangleShape body;
	float width;
	float height;

	sf::Vector2f position;

	bool colliding = false;

	int price = 0;

	AttackVarients attackVarient;

	sf::Font font;
	sf::Text text;
};

