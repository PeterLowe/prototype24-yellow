
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Globals.h"

class Player
{
public:
	Player();
	void setup(sf::Vector2f t_pos);

	// "Get" Functions
	sf::RectangleShape getBody() { return body; }
	sf::Vector2f getPosition() { return position; }

	void move();
	void jump();

	void groundCheck();

	void gravity();
	void checkBoundries();

	bool jumping = false;
	bool jumpAgain = false;
	bool canJump = false;
	bool jumped = false;


private:

	sf::RectangleShape body;
	float height = 100.0f;
	float width = 50.0f;

	sf::Vector2f position;

	float speed = 5;

	// Ground checking
	sf::RectangleShape groundChecker;
	const sf::Vector2f GROUND_CHECK_DISPLACEMENT = { 0.0f, (height / 2.0f) + 0.5f };
	bool onGround = false;

	// Jump
	const int MAX_JUMPS = 2;
	int jumpAmount = 0;
	const int JUMP_FORCE = 13;
	int jumpTimer = 0;
	const float RISE_DURATION = 1;
	float deceleration = 0;

	// Fast fall
	bool fastfall = false;
	int fastfallCounter = 0;
	const int TIME_TILL_FASTFALL = 0.15f * 60; // 12 frames
	const int FASTFALL_SPEED = GRAVITY + 10;
};