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

	// If can attack...
	if (canAttack)
	{
		// If J is pressed and ...
		if (sf::Keyboard::J == t_event.key.code)
		{
			// Up Attack
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				// upAttack
			}
			// Down Attack
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				// downAttack
			}
			// Left Attack
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				// sideAttackLeft
			}
			// Right Attack
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				// sideAttackRight
			}
			else
			{
				neutralAttack.spawn(player.getPosition());
			}
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

	/// Attacks ///
	// Neutral Attack
	if (neutralAttack.active) // Attack
	{
		// Do the attack and check collisions
		neutralAttack.attack(player.getPosition(), sandbag, canAttack);

		// Set the endlag
		endLagDuration = neutralAttack.END_LAG;
	}

	if (!canAttack)
	{
		// Do endlag timer
		endLag();
	}

	player.changeColor(canAttack);
}

void GamePlay::render(sf::RenderWindow& t_window)
{
	// Sandbag
	t_window.draw(sandbag.getBody());
	t_window.draw(sandbag.getSprite());

	// Player
	t_window.draw(player.getBody());

	/// Attacks ///
	if (neutralAttack.active)
	{
		t_window.draw(neutralAttack.getBodyLeft());
		t_window.draw(neutralAttack.getBodyRight());
	}
}

void GamePlay::setupObjects()
{
	// Player
	player.setup({ 300, 100 });
}

void GamePlay::endLag()
{
	if (endLagTimer < endLagDuration)
	{
		endLagTimer++;
	}
	else if (endLagTimer >= endLagDuration)
	{
		// Reset timer
		endLagTimer = 0;

		// Can attack becomes true
		canAttack = true;
	}
}