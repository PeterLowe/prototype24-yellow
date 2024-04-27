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
	void processController();

	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_window);

	void setupFontAndText();
	void setupButtons();

private:

	void moveMouseHitbox();
	void controllerButtonCheck();

	// Controller
	Controller controller;
	bool controllerConnected = false;
	sf::RectangleShape mouseHitbox;
	sf::Vector2f mouseHitboxPosition;
	const int MOUSE_HITBOX_SPEED = 7;

	sf::Vector2f mousePos;


	// Buttons for attacks
	shopButtons sideShootLeft;
	bool sideShootLeftColliding = false;
	shopButtons sideShootRight;
	bool sideShootRightColliding = false;
	shopButtons upShoot;
	bool upShootColliding = false;
	shopButtons downShoot;
	bool downShootColliding = false;

	sf::Font font;

	// Currency
	sf::Text coinsText;

	ScreenTransition transitionCircle;
};

