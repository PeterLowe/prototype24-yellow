// IAN PEREZ BUNUEL

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Globals.h"
#include "GamePlay.h"
#include "shopButtons.h"

class Shop
{
public:
	Shop();

	void processEvents(sf::Event t_event);
	void processKeys(sf::Event t_event);
	void processMouseDown(sf::Event t_event);
	void processMouseMove(sf::Event t_event);

	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_window);

	void setupFontAndText();
	void setupButtons();

private:

	sf::Vector2f mousePos;


	// Buttons for attacks
	shopButtons sideShootLeft;
	bool sideShootLeftColliding = false;

	sf::Font font;

	// Currency
	sf::Text coinsText;

	ScreenTransition transitionCircle;
};

