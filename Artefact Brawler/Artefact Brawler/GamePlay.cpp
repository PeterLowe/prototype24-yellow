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
	// Deactivate controller
	controllerConnected = false;

	// On escape swap to show scene
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		transitionCircle.transition(Scene::Shop);
	}

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
				AttackManager::upSpawn(player.getPosition());
			}
			// Down Attack
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				AttackManager::downSpawn(player.getPosition());
			}
			// Left Attack
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				AttackManager::sideSpawnLeft(player.getPosition());
			}
			// Right Attack
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				AttackManager::sideSpawnRight(player.getPosition());
			}
			else
			{
				AttackManager::neutralSpawn(player.getPosition());
			}
		}
	}
}

void GamePlay::processController()
{
	// Jumping
	if (controller.currentState.A)
	{
		if (!player.jumped)
		{
			if (player.canJump)
			{
				player.jumped = true;

				player.jumping = true;
				player.jumpAgain = true;
			}
		}
	}
	// Once let go allow another jump
	else
	{
		player.jumped = false;
	}


	// If can attack
	if (canAttack)
	{
		if (!buttonPressed)
		{
			// if X is pressed and ...
			if (controller.currentState.X)
			{
				// Up Attack
				if (controller.currentState.LeftThumbStick.y <= -50)
				{
					AttackManager::upSpawn(player.getPosition());
				}
				// Down Attack
				else if (controller.currentState.LeftThumbStick.y >= 50)
				{
					AttackManager::downSpawn(player.getPosition());
				}
				// Left Attack
				else if (controller.currentState.LeftThumbStick.x <= -50)
				{
					AttackManager::sideSpawnLeft(player.getPosition());
				}
				// Right Attack
				else if (controller.currentState.LeftThumbStick.x >= 50)
				{
					AttackManager::sideSpawnRight(player.getPosition());
				}
				else
				{
					AttackManager::neutralSpawn(player.getPosition());
				}

				// Make sure only one attack is done at a time
				buttonPressed = true;
			}
		}
	}
}


void GamePlay::update(sf::Time t_deltaTime)
{
	if (controllerConnected)
	{
		controller.update();
		processController();
	}
	// Check if the controller should be connected
	else
	{
		controllerConnected = controller.connectCheck();
	}

	// Screen Transition
	if (transitionCircle.active)
	{
		transitionCircle.transition(transitionCircle.goTo);
	}

	// Player
	player.move(controller, controllerConnected);
	// Jumping
	if (player.jumping)
	{
		player.jump();
	}
	for (int i = 0; i < 3; i++) // Used to check each platform
	{
		player.groundCheck(platforms[i]);

		if (player.onGround)
		{
			break;
		}
	}

	player.gravity();
	player.checkBoundries();

	// Sandbag
	for (int i = 0; i < 3; i++)
	{
		sandbag.groundCheck(platforms[i]);

		if (sandbag.onGround)
		{
			break;
		}
	}
	sandbag.gravity();
	sandbag.checkBoundries();
	// Off screen indicator
	sandbag.offScreenIndicator();

	/// Attacks ///
	// Neutral Attack
	if (AttackManager::getNeutralActive()) // Attack
	{
		// Do the attack and check collisions
		AttackManager::neutralAttack(player.getPosition(), sandbag, canAttack);

		// Set the endlag
		endLagDuration = AttackManager::getNeutralEndlag();

		// If hit...
		if (AttackManager::getNeutralHasHit())
		{
			knockbackAngle = AttackManager::getNeutralAngleD(); // Set angle
			knockbackPower = AttackManager::getNeutralPower(); // Set power
			damageTaken = AttackManager::getNeutralDamage(); // Set the damage to add to sandbag's percentage


			sandbag.hitAgain = true;
			sandbag.knockingBack = true;

			// Do damage if damage has not been done
			if (!damageDone)
			{
				// Add to the sandbag's percentage
				sandbag.takeDamage(AttackManager::getNeutralDamage());

				// Add to the currency
				Currency::coins += COINS_PER_HIT; // * comboMultiplier
				coinsText.setString("Coins: " + std::to_string(Currency::coins));

				damageDone = true;
			}
		}
	}

	// Right Attack
	if (AttackManager::getSideRightActive()) // Attack
	{
		AttackManager::sideAttackRight(player.getPosition(), sandbag, canAttack);

		// Set the endlag
		endLagDuration = AttackManager::getSideEndlagRight();

		// If hit...
		if (AttackManager::getSideHasHitRight())
		{
			knockbackAngle = AttackManager::getSideAngleDRight(); // Set angle
			knockbackPower = AttackManager::getSidePowerRight(); // Set power
			damageTaken = AttackManager::getSideDamageRight(); // Set the damage to add to sandbag's percentage


			sandbag.hitAgain = true;
			sandbag.knockingBack = true;

			// Do damage if damage has not been done
			if (!damageDone)
			{
				// Add to the sandbag's percentage
				sandbag.takeDamage(AttackManager::getSideDamageRight());

				// Add to the currency
				Currency::coins += COINS_PER_HIT; // * comboMultiplier
				coinsText.setString("Coins: " + std::to_string(Currency::coins));


				damageDone = true;
			}
		}
	}

	// Left Attack
	if (AttackManager::getSideLeftActive()) // Attack
	{
		AttackManager::sideAttackLeft(player.getPosition(), sandbag, canAttack);

		// Set the endlag
		endLagDuration = AttackManager::getSideEndlagLeft();

		// If hit...
		if (AttackManager::getSideHasHitLeft())
		{
			knockbackAngle = AttackManager::getSideAngleDLeft(); // Set angle
			knockbackPower = AttackManager::getSidePowerLeft(); // Set power
			damageTaken = AttackManager::getSideDamageLeft(); // Set the damage to add to sandbag's percentage


			sandbag.hitAgain = true;
			sandbag.knockingBack = true;

			// Do damage if damage has not been done
			if (!damageDone)
			{
				// Add to the sandbag's percentage
				sandbag.takeDamage(AttackManager::getSideDamageLeft());

				// Add to the currency
				Currency::coins += COINS_PER_HIT; // * comboMultiplier
				coinsText.setString("Coins: " + std::to_string(Currency::coins));


				damageDone = true;
			}
		}
	}

	if (AttackManager::getUpActive()) // Attack
	{
		// Do the attack and check collisions
		AttackManager::upAttack(player.getPosition(), sandbag, canAttack);

		// Set the endlag
		endLagDuration = AttackManager::getUpEndlag();

		// If hit...
		if (AttackManager::getUpHasHit())
		{
			knockbackAngle = AttackManager::getUpAngleD(); // Set angle
			knockbackPower = AttackManager::getUpPower(); // Set power
			damageTaken = AttackManager::getUpDamage();


			sandbag.hitAgain = true;
			sandbag.knockingBack = true;

			// Do damage if damage has not been done
			if (!damageDone)
			{
				// Add to the sandbag's percentage
				sandbag.takeDamage(AttackManager::getUpDamage());

				// Add to the currency
				Currency::coins += COINS_PER_HIT; // * comboMultiplier
				coinsText.setString("Coins: " + std::to_string(Currency::coins));


				damageDone = true;
			}
		}
	}

	// down attack
	if (AttackManager::getDownActive()) // attack
	{
		AttackManager::downAttack(player.getPosition(), sandbag, canAttack);

		// set endlag
		endLagDuration = AttackManager::getDownEndlag();

		// If hit...
		if (AttackManager::getDownHasHit())
		{
			knockbackAngle = AttackManager::getDownAngleD(); // set angle
			knockbackPower = AttackManager::getDownPower(); // set power
			damageTaken = AttackManager::getDownDamage();

			sandbag.hitAgain = true;
			sandbag.knockingBack = true;

			// Do damage if damage has not been done
			if (!damageDone)
			{
				// Add to the sandbag's percentage
				sandbag.takeDamage(AttackManager::getDownDamage());

				// Add to the currency
				Currency::coins += COINS_PER_HIT; // * comboMultiplier
				coinsText.setString("Coins: " + std::to_string(Currency::coins));


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

		// Allow for another attack input from controller
		buttonPressed = false;

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
	if (AttackManager::getNeutralActive())
	{
		AttackManager::drawNeutral(t_window);
	}

	else if (AttackManager::getSideLeftActive())
	{
		AttackManager::drawSideLeft(t_window);
	}

	else if (AttackManager::getSideRightActive())
	{
		AttackManager::drawSideRight(t_window);
	}

	else if (AttackManager::getUpActive())
	{
		AttackManager::drawUp(t_window);
	}

	else if (AttackManager::getDownActive())
	{
		AttackManager::drawDown(t_window);
	}

	// Platforms
	for (int i = 0; i < 3; i++)
	{
		t_window.draw(platforms[i].getBody());
	}

	// Sandbag's percentage
	t_window.draw(sandbagPercentage);

	// Coins Text
	t_window.draw(coinsText);

	// Screen Transition
	if (transitionCircle.active)
	{
		t_window.draw(transitionCircle.getBody());
	}
}

void GamePlay::setupFontAndText()
{
	if (!font.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}

	// Percentage
	sandbagPercentage.setFont(font);
	sandbagPercentage.setString("Sandbag: " + std::to_string(sandbag.percentage) + "%");
	sandbagPercentage.setStyle(sf::Text::Underlined | sf::Text::Italic | sf::Text::Bold);
	sandbagPercentage.setCharacterSize(30U);
	sandbagPercentage.setOutlineColor(sf::Color::Red);
	sandbagPercentage.setFillColor(sf::Color::White);
	sandbagPercentage.setOutlineThickness(3.0f);
	sandbagPercentage.setPosition(SCREEN_WIDTH - 250, SCREEN_HEIGHT - 50);

	coinsText.setFont(font);
	coinsText.setString("Coins: " + std::to_string(Currency::coins));
	coinsText.setStyle(sf::Text::Underlined | sf::Text::Italic | sf::Text::Bold);
	coinsText.setCharacterSize(30U);
	coinsText.setOutlineColor(sf::Color::Yellow);
	coinsText.setFillColor({ 255, 100, 0, 255});
	coinsText.setOutlineThickness(3.0f);
	coinsText.setPosition(SCREEN_WIDTH - 250, 50);
}

void GamePlay::setupObjects()
{
	// Player
	player.setup({ 300, 100 });


	// Platforms
	platforms[0].setup({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 3 }); // Top
	platforms[1].setup({ SCREEN_WIDTH / 3 - 50, (SCREEN_HEIGHT / 3) * 2 }); // Left
	platforms[2].setup({ (SCREEN_WIDTH / 3 + 50) * 2, (SCREEN_HEIGHT / 3) * 2 }); // Right

	// Attack setups
	AttackManager::setup();
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