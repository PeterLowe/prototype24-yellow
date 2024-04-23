#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Globals.h"
#include "GamePlay.h"

class Shop
{
public:
	Shop();

	void processEvents(sf::Event t_event);
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_window);

	void setupFontAndText();

private:

	sf::Font font;

	// Currency
	sf::Text coinsText;

	ScreenTransition transitionCircle;
};

