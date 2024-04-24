// IAN PEREZ BUNUEL

#pragma once

# include <SFML/Graphics.hpp>
#include "Button.h"
#include "Scenes.h"
#include "ScreenTransition.h"
#include "Controller.h"

class Game;

class MainMenu
{
public:
	MainMenu();

	void processEvents(sf::Event t_event);
	void processMouseDown(sf::Event t_event);
	void processMouseMove(sf::Event t_event);
	void processController();

	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_window);

	void moveMouseHitbox();

private:

	// Controller
	Controller controller;
	bool controllerConnected = false;

	void setupButtons();

	sf::Vector2f mousePos;
	sf::RectangleShape mouseHitbox;
	sf::Vector2f mouseHitboxPosition;
	const int MOUSE_HITBOX_SPEED = 7;

	// Buttons
	Button colosseum;
	bool colosseumColliding = false;
	sf::Vector2f colosseumPos = { 500.0f, 200.0f };

	Button shop;
	bool shopColliding = false;
	sf::Vector2f shopPos = { 200.0f, 200.0f };

	Button help;
	bool helpColliding = false;
	sf::Vector2f helpPos = { 200.0f, 200.0f };

	float buttonWidth = 100.0f;
	float buttonHeight = 200.0f;

	ScreenTransition transitionCircle;

};

