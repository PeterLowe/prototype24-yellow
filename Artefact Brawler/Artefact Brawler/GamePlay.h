#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"

class GamePlay
{
public:

	void processEvents(sf::Event t_event);
	void processKeys(sf::Event t_event);

	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_event);

private:

	void setupObjects();

	// Objects
	Player player;
};

