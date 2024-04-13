#include "GamePlay.h"

GamePlay::GamePlay()
{
	setupFontAndText();
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
				upAttack.spawn(player.getPosition());
			}
			// Down Attack
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				downAttack.spawn(player.getPosition());
			}
			// Left Attack
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				sideAttackLeft.spawn(player.getPosition());
			}
			// Right Attack
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				sideAttackRight.spawn(player.getPosition());
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
	// Off screen indicator
	sandbag.offScreenIndicator();

	/// Attacks ///
	// Neutral Attack
	if (neutralAttack.active) // Attack
	{
		// Do the attack and check collisions
		neutralAttack.attack(player.getPosition(), sandbag, canAttack);

		// Set the endlag
		endLagDuration = neutralAttack.END_LAG;

		// If hit...
		if (neutralAttack.hasHit)
		{
			knockbackAngle = neutralAttack.angleD; // Set angle
			knockbackPower = neutralAttack.power; // Set power
			damageTaken = neutralAttack.damage; // Set the damage to add to sandbag's percentage


			sandbag.hitAgain = true;
			sandbag.knockingBack = true;

			// Do damage if damage has not been done
			if (!damageDone)
			{
				// Add to the sandbag's percentage
				sandbag.takeDamage(neutralAttack.damage);


				damageDone = true;
			}
		}
	}

	// Right Attack
	if (sideAttackRight.active) // Attack
	{
		sideAttackRight.attack(player.getPosition(), sandbag, canAttack);

		// Set the endlag
		endLagDuration = sideAttackRight.END_LAG;

		// If hit...
		if (sideAttackRight.hasHit)
		{
			knockbackAngle = sideAttackRight.angleD; // Set angle
			knockbackPower = sideAttackRight.power; // Set power
			damageTaken = sideAttackRight.damage; // Set the damage to add to sandbag's percentage


			sandbag.hitAgain = true;
			sandbag.knockingBack = true;

			// Do damage if damage has not been done
			if (!damageDone)
			{
				// Add to the sandbag's percentage
				sandbag.takeDamage(sideAttackRight.damage);


				damageDone = true;
			}
		}
	}

	// Left Attack
	if (sideAttackLeft.active) // Attack
	{
		sideAttackLeft.attack(player.getPosition(), sandbag, canAttack);

		// Set the endlag
		endLagDuration = sideAttackLeft.END_LAG;

		// If hit...
		if (sideAttackLeft.hasHit)
		{
			knockbackAngle = sideAttackLeft.angleD; // Set angle
			knockbackPower = sideAttackLeft.power; // Set power
			damageTaken = sideAttackLeft.damage; // Set the damage to add to sandbag's percentage


			sandbag.hitAgain = true;
			sandbag.knockingBack = true;

			// Do damage if damage has not been done
			if (!damageDone)
			{
				// Add to the sandbag's percentage
				sandbag.takeDamage(sideAttackLeft.damage);


				damageDone = true;
			}
		}
	}

	if (upAttack.active) // Attack
	{
		// Do the attack and check collisions
		upAttack.attack(player.getPosition(), sandbag, canAttack);

		// Set the endlag
		endLagDuration = upAttack.END_LAG;

		// If hit...
		if (upAttack.hasHit)
		{
			knockbackAngle = upAttack.angleD; // Set angle
			knockbackPower = upAttack.power; // Set power
			damageTaken = upAttack.damage; // Set the damage to add to sandbag's percentage


			sandbag.hitAgain = true;
			sandbag.knockingBack = true;

			// Do damage if damage has not been done
			if (!damageDone)
			{
				// Add to the sandbag's percentage
				sandbag.takeDamage(upAttack.damage);


				damageDone = true;
			}
		}
	}

	// down attack
	if (downAttack.active) // attack
	{
		downAttack.attack(player.getPosition(), sandbag, canAttack);

		// set endlag
		endLagDuration = downAttack.END_LAG;

		// If hit...
		if (downAttack.hasHit)
		{
			knockbackAngle = downAttack.angleD; // set angle
			knockbackPower = downAttack.power; // set power
			damageTaken = downAttack.damage;  // set damage to add to sandbag's percentage

			sandbag.hitAgain = true;
			sandbag.knockingBack = true;

			// Do damage if damage has not been done
			if (!damageDone)
			{
				// Add to the sandbag's percentage
				sandbag.takeDamage(downAttack.damage);


				damageDone = true;
			}
		}
	}

	// Sandbags knockback
	if (sandbag.knockingBack)
	{
		// Change the percentage string
		sandbagPercentage.setString("Sandbag: " + std::to_string(sandbag.percentage) + "%");

		// Bouncing
		knockbackAngle = sandbag.bounce(knockbackAngle);
		sandbag.knockback(knockbackAngle, knockbackPower, damageTaken); // Knockback
	}

	if (!canAttack)
	{
		// Do endlag timer
		endLag();

		// Allow damage again
		damageDone = false;
	}

	player.changeColor(canAttack);
}

void GamePlay::render(sf::RenderWindow& t_window)
{
	// Sandbag
	t_window.draw(sandbag.getSprite());

	// Off screen indicator
	if (sandbag.indicatorActive)
	{
		t_window.draw(sandbag.getIndicatorBody());
	}

	// Player
	t_window.draw(player.getBody());

	/// Attacks ///
	if (neutralAttack.active)
	{
		t_window.draw(neutralAttack.getBodyLeft());
		t_window.draw(neutralAttack.getBodyRight());
	}
	else if (sideAttackLeft.active)
	{
		t_window.draw(sideAttackLeft.getBody());
	}
	else if (sideAttackRight.active)
	{
		t_window.draw(sideAttackRight.getBody());
	}
	else if (upAttack.active)
	{
		t_window.draw(upAttack.getBody());
	}
	else if (downAttack.active)
	{
		t_window.draw(downAttack.getBody());
	}

	// Sandbag's percentage
	t_window.draw(sandbagPercentage);
}

void GamePlay::setupFontAndText()
{
	if (!font.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}
	sandbagPercentage.setFont(font);
	sandbagPercentage.setString("Sandbag: " + std::to_string(sandbag.percentage) + "%");
	sandbagPercentage.setStyle(sf::Text::Underlined | sf::Text::Italic | sf::Text::Bold);
	sandbagPercentage.setCharacterSize(30U);
	sandbagPercentage.setOutlineColor(sf::Color::Red);
	sandbagPercentage.setFillColor(sf::Color::White);
	sandbagPercentage.setOutlineThickness(3.0f);

	sandbagPercentage.setPosition(SCREEN_WIDTH - 250, SCREEN_HEIGHT - 50);
}

void GamePlay::setupObjects()
{
	// Player
	player.setup({ 300, 100 });

	// Setup side attacks
	sideAttackLeft.setup(true);
	sideAttackRight.setup(false);
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