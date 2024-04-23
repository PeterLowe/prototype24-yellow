// IAN PEREZ BUNUEL

#pragma once

# include <SFML/Graphics.hpp>
#include "Button.h"
#include "Scenes.h"
#include "ScreenTransition.h"

class Game;

class MainMenu
{
public:
	MainMenu();

	void processEvents(sf::Event t_event);
	void processMouseDown(sf::Event t_event);
	void processMouseMove(sf::Event t_event);

	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_window);

private:

	void setupButtons();

	sf::Vector2f mousePos;

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

