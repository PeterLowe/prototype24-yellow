#pragma once

#include <SFML/Graphics.hpp>
#include<iostream>
#include "Button.h"
#include "ScreenTransition.h"
#include "PlayerType.h"
#include "Controller.h"

class CharacterSelect // LIAM
{
public:

	CharacterSelect();
	void processEvents(sf::Event t_event);
	void processMouseDown(sf::Event t_event);
	void processMouseMove(sf::Event t_event);
	void processController();

	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_window);

	void setupSprite();
	void setupButton();
	void setupFontAndText();

	sf::Sprite getChar1Body();

private:

	void moveMouseHitbox();

	// Controller
	Controller controller;
	bool controllerConnected = false;
	sf::RectangleShape mouseHitbox;
	sf::Vector2f mouseHitboxPosition;
	const int MOUSE_HITBOX_SPEED = 7;

	sf::Vector2f mousePos = {};

	sf::Sprite character1Sprite;
	sf::Texture character1Texture;
	sf::Sprite character2Sprite;
	sf::Texture character2Texture;
	sf::Sprite character3sprite;
	sf::Texture character3Texture;

	sf::Texture frameTexture;
	sf::Sprite frameSprite;

	Button character1Button;
	sf::Vector2f character1Pos = { 329.0f, 405.0f };
	bool character1Colliding = false;

	Button character2Button;
	sf::Vector2f character2Pos = { 544.0f, 405.0f };
	bool character2Colliding = false;

	Button character3Button;
	sf::Vector2f character3Pos = { 758.0f, 405.0f };
	bool character3Colliding = false;

	Button character4Button;
	sf::Vector2f character4Pos = { 329, 585.0f };
	bool character4Colliding = false;

	Button character5Button;
	sf::Vector2f character5Pos = { 544.0f, 585.0f };
	bool character5Colliding = false;

	Button character6Button;
	sf::Vector2f character6Pos = { 758.0f, 585.0f };
	bool character6Colliding = false;

	int buttonHeight = 170;
	int buttonWidth = 200;

	bool character1Hover = false;

	sf::Font font;
	sf::Text characterStats;

	ScreenTransition transitionCircle;
};

