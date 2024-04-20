#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Sandbag.h"
#include "Currency.h"
#include "Platform.h"
#include "AttackManager.h"
#include "Scenes.h"
#include "ScreenTransition.h"

class GamePlay
{
public:

	GamePlay();

	void processEvents(sf::Event t_event);
	void processKeys(sf::Event t_event);
	void processController();

	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_window);

private:

	void setupFontAndText();
	void setupObjects();

	// Objects
	Player player;
	Sandbag sandbag;
	Platform platforms[3];

	// Controller
	Controller controller;
	bool controllerConnected = false;
	bool buttonPressed = false;

	// Attack info
	void endLag();
	bool canAttack = true;
	int endLagTimer = 0;
	int endLagDuration; // Set after doing an attack
	bool damageDone = false;

	// Sandbag Knockback info
	float knockbackAngle = 0.0f;
	float knockbackPower = 0.0f;
	int damageTaken = 0;

	// Sandbag Percentage
	sf::Font font;
	sf::Text sandbagPercentage;

	// Currency
	sf::Text coinsText;
	const int COINS_PER_HIT = 10;

	ScreenTransition transitionCircle;
};

