#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Globals.h"
#include "Scenes.h"

class ScreenTransition
{
public:
	ScreenTransition();

	sf::CircleShape getBody() { return body; }

	void transition(Scene t_goTo);
	Scene goTo = Scene::None;

	bool active = true;


private:

	bool grow = false;

	sf::CircleShape body;
	const int MAX_SIZE = SCREEN_WIDTH;
	const int MIN_SIZE = 0;
	float size = MAX_SIZE;

};

