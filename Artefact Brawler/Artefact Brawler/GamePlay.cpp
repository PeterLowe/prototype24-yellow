#include "GamePlay.h"

GamePlay::GamePlay()
{
	setupObjects();
	sandbag.setup(sf::Vector2f{ 100.0f,100.0f });
}

void GamePlay::processEvents(sf::Event t_event)
{
	if (sf::Event::KeyPressed == t_event.type)
	{
		processKeys(t_event);
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
	// Player
	player.move();

	// Jumping
	if (player.jumping)
	{
		player.jump();
	}

	player.groundCheck();

	player.gravity();
	player.checkBoundries();

	// Sandbag
	sandbag.gravity();
	sandbag.checkBoundries();
}

void GamePlay::render(sf::RenderWindow& t_window)
{
	// Player
	t_window.draw(player.getBody());
	t_window.draw(sandbag.getBody());
}

void GamePlay::setupObjects()
{
	// Player
	player.setup({ 300, 100 });
}
