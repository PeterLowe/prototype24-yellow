// IAN PEREZ BUNUEL VIT PRECHTL

#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Sandbag.h"
#include "Currency.h"
#include "Platform.h"
#include "AttackManager.h"
#include "Scenes.h"
#include "ScreenTransition.h"
#include"ReflectiveBouncePads.h"
#include <iostream>

class GamePlay
{
public:

	GamePlay();

	void processEvents(sf::Event t_event);
	void processKeys(sf::Event t_event);
	void processController();

	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_window);
	void bouncePadCheck(ReflectiveBouncePads t_bouncingPad);

private:

	void setupFontAndText();
	void setupObjects();
	void setupBackground();

	void doAttacks();
	void drawAttacks(sf::RenderWindow& t_window);
	void doSpecials();
	void drawSpecials(sf::RenderWindow& t_window);

	void Countdown();

	// Objects
	Player player;
	Sandbag sandbag;
	Platform platforms[MAX_PLATFORMS];
	ReflectiveBouncePads bouncePads[MAX_PLATFORMS];

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
	bool paused = false;

	// Background
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;

	// Countdown
	int STARTING_COUNTDOWN = 30 * 60;
	int countdown = STARTING_COUNTDOWN;
	sf::Text countdownText;
};

