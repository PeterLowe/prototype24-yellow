#include "GamePlay.h"

void GamePlay::processEvents(sf::Event t_event)
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if (sf::Event::KeyPressed == newEvent.type) //user pressed a key
		{
			processKeys(newEvent);
		}
	}
}

void GamePlay::processKeys(sf::Event t_event)
{
	// Player's Jump
	if (sf::Keyboard::Space == t_event.key.code)
	{
		if (player.canJump)
		{
			player.jumping = true;
			player.jumpAgain = true;
		}
	}
}


void GamePlay::update(sf::Time t_deltaTime)
{
}

void GamePlay::render(sf::RenderWindow& t_event)
{
}
