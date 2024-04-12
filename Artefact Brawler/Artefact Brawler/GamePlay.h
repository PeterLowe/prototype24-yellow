#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"

class GamePlay
{
public:

	GamePlay();

	void processEvents(sf::Event t_event);
	void processKeys(sf::Event t_event);

	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_window);

private:

	void setupObjects();

	sf::RenderWindow m_window; // main SFML window

	// Objects
	Player player;
};

