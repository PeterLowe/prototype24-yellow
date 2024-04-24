// IAN PEREZ BUNUEL

#pragma once

#include <SFML/Graphics.hpp>

#include "PlayerType.h"
#include "Globals.h"
#include "Controller.h"
#include "Platform.h"
#include "ReflectiveBouncePads.h"


#include <iostream>

class Player
{
public:
	Player();
	void setup(sf::Vector2f t_pos);

	// "Get" Functions
	sf::RectangleShape getBody() { return body; }
	sf::RectangleShape getChecker() { return groundChecker; }
	sf::Vector2f getPosition() { return position; }

	void move(Controller& t_controller, bool t_controllerConnected);
	void jump();

	void groundCheck(Platform t_platform);

	void gravity();
	void checkBoundries();

	void changeColor(bool t_canAttack);

	void setStats();

	bool jumping = false;
	bool jumpAgain = false;
	bool canJump = false;
	bool jumped = false;

	bool onGround = false;

private:

	sf::RectangleShape body;
	float height = 100;
	float width = 50;

	sf::Vector2f position;

	float speed = 5;

	// Ground checking
	sf::RectangleShape groundChecker;
	const sf::Vector2f GROUND_CHECK_DISPLACEMENT = { 0.0f, (height / 2.0f) + 0.5f };

	// Jump
	int maxJumps = 2;
	int jumpAmount = 0;
	int jumpForce = 13;
	int jumpTimer = 0;
	int riseDuration = 4;
	float deceleration = 0;
	int changeInGravity = 0;

	// Fast fall
	bool fastfall = false;
	int fastfallCounter = 0;
	const int TIME_TILL_FASTFALL = 0.15f * 60; // 12 frames
	const int FASTFALL_SPEED = GRAVITY + 10;
};

