// IAN PEREZ BUNUEL

#include "Shop.h"
#include "game.h"

Shop::Shop()
{
	// Setup mouse hitbox for controller
	mouseHitbox.setFillColor(sf::Color::Blue);
	mouseHitbox.setSize({ 20.0f, 20.0f });
	mouseHitbox.setOrigin({ 10.0f, 10.0f });

	setupFontAndText();
	setupButtons();
}

void Shop::processEvents(sf::Event t_event)
{
	if (sf::Event::KeyPressed == t_event.type)
	{
		processKeys(t_event);
	}

	// Mouse
	if (sf::Event::MouseButtonPressed == t_event.type)
	{
		processMouseDown(t_event);
	}

	if (sf::Event::MouseMoved == t_event.type)
	{
		processMouseMove(t_event);
	}
}

void Shop::processKeys(sf::Event t_event)
{
	// Deactivate controller if the keyPressed is pressed
	controllerConnected = false;

	// On escape swap to show scene
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		transitionCircle.transition(Scene::MainMenu);
	}
}

void Shop::processMouseDown(sf::Event t_event)
{
	// Deactivate controller if the mouse is pressed
	controllerConnected = false;

	// Shoot attack buttons
	if (kneeColliding)
	{
		knee.onPress(Currency::coins, SpecialType::Knee);
	}

	// Shoot attack buttons
	if (sideShootLeftColliding)
	{
		sideShootLeft.onPress(Currency::coins, SpecialType::ShootingSideLeft);
	}

	if (sideShootRightColliding)
	{
		sideShootRight.onPress(Currency::coins, SpecialType::ShootingSideRight);
	}

	if (upShootColliding)
	{
		upShoot.onPress(Currency::coins, SpecialType::ShootingUp);
	}

	if (downShootColliding)
	{
		downShoot.onPress(Currency::coins, SpecialType::ShootingDown);
	}
}

void Shop::processMouseMove(sf::Event t_event)
{
	mousePos.x = static_cast<float>(t_event.mouseMove.x);
	mousePos.y = static_cast<float>(t_event.mouseMove.y);
}

void Shop::processController()
{
	if (controller.currentState.A)
	{
		if (kneeColliding)
		{
			knee.onPress(Currency::coins, SpecialType::Knee);
		}

		if (sideShootLeftColliding)
		{
			sideShootLeft.onPress(Currency::coins, SpecialType::ShootingSideLeft);
		}

		if (sideShootRightColliding)
		{
			sideShootRight.onPress(Currency::coins, SpecialType::ShootingSideRight);
		}

		if (upShootColliding)
		{
			upShoot.onPress(Currency::coins, SpecialType::ShootingUp);
		}

		if (downShootColliding)
		{
			downShoot.onPress(Currency::coins, SpecialType::ShootingDown);
		}
	}

	// Move the hitbox for the mouse using the controller
	moveMouseHitbox();
}

void Shop::update(sf::Time t_deltaTime)
{
	if (controllerConnected)
	{
		controller.update();
		processController();

		controllerButtonCheck();
	}
	else
	{
		mouseHitboxPosition = mousePos;
		// Check if the controller was connected
		controllerConnected = controller.connectCheck();


		// Check if your hovering over a button
		kneeColliding = knee.checkForMouse(mousePos);
		sideShootLeftColliding = sideShootLeft.checkForMouse(mousePos);
		sideShootRightColliding = sideShootRight.checkForMouse(mousePos);
		upShootColliding = upShoot.checkForMouse(mousePos);
		downShootColliding = downShoot.checkForMouse(mousePos);
	}

	// Screen Transition
	if (transitionCircle.active)
	{
		transitionCircle.transition(transitionCircle.goTo);
	}

	// Coin update
	coinsText.setString("Coins: " + std::to_string(Currency::coins));
}

void Shop::render(sf::RenderWindow& t_window)
{
	// Coins Text
	t_window.draw(coinsText);


	// Mouse hitbox
	if (controllerConnected)
	{
		t_window.draw(mouseHitbox);
	}

	// Buttons
	knee.draw(t_window);
	sideShootLeft.draw(t_window);
	sideShootRight.draw(t_window);
	upShoot.draw(t_window);
	downShoot.draw(t_window);

	// Screen Transition
	if (transitionCircle.active)
	{
		t_window.draw(transitionCircle.getBody());
	}
}

void Shop::setupFontAndText()
{
	if (!font.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}

	coinsText.setFont(font);
	coinsText.setStyle(sf::Text::Underlined | sf::Text::Italic | sf::Text::Bold);
	coinsText.setCharacterSize(30U);
	coinsText.setOutlineColor(sf::Color::Yellow);
	coinsText.setFillColor({ 255, 100, 0, 255 });
	coinsText.setOutlineThickness(3.0f);
	coinsText.setPosition(SCREEN_WIDTH - 250, 50);
}

void Shop::setupButtons()
{
	knee.setup({250, 500.0f}, 100.0f, 100.0f, 75, AttackVarients::SideLeft, sf::Color::Cyan);
	sideShootLeft.setup({400.0f, 500.0f}, 100.0f, 100.0f, 75, AttackVarients::SideLeft, sf::Color::Blue);
	sideShootRight.setup({ 550.0f, 500.0f }, 100.0f, 100.0f, 75, AttackVarients::SideRight, sf::Color::Red);
	upShoot.setup({ 700.0f, 500.0f }, 100.0f, 100.0f, 150, AttackVarients::Up, sf::Color::Green);
	downShoot.setup({ 850.0f, 500.0f }, 100.0f, 100.0f, 150, AttackVarients::Up, sf::Color::Magenta);
}

void Shop::moveMouseHitbox()
{
	// Up Movement
	if (controller.currentState.LeftThumbStick.y <= -50)
	{
		mouseHitboxPosition.y += -MOUSE_HITBOX_SPEED;
	}
	// Down  Movement
	else if (controller.currentState.LeftThumbStick.y >= 50)
	{
		mouseHitboxPosition.y += MOUSE_HITBOX_SPEED;
	}
	// Left  Movement
	else if (controller.currentState.LeftThumbStick.x <= -50)
	{
		mouseHitboxPosition.x += -MOUSE_HITBOX_SPEED;
	}
	// Right Movement
	else if (controller.currentState.LeftThumbStick.x >= 50)
	{
		mouseHitboxPosition.x += MOUSE_HITBOX_SPEED;
	}

	// Border collision
	if (mouseHitboxPosition.x < 0)
	{
		mouseHitboxPosition.x = 0;
	}
	else if (mouseHitboxPosition.x > SCREEN_WIDTH)
	{
		mouseHitboxPosition.x = SCREEN_WIDTH;
	}
	if (mouseHitboxPosition.y < 0)
	{
		mouseHitboxPosition.y = 0;
	}
	else if (mouseHitboxPosition.y > SCREEN_HEIGHT)
	{
		mouseHitboxPosition.y = SCREEN_HEIGHT;
	}

	mouseHitbox.setPosition(mouseHitboxPosition);
}

void Shop::controllerButtonCheck()
{
	// Check if its over a button
	if (mouseHitbox.getGlobalBounds().intersects(knee.getBody().getGlobalBounds()))
	{
		kneeColliding = true;
	}
	else
	{
		kneeColliding = false;
	}

	if (mouseHitbox.getGlobalBounds().intersects(sideShootLeft.getBody().getGlobalBounds()))
	{
		sideShootLeftColliding = true;
	}
	else
	{
		sideShootLeftColliding = false;
	}

	if (mouseHitbox.getGlobalBounds().intersects(sideShootRight.getBody().getGlobalBounds()))
	{
		sideShootRightColliding = true;
	}
	else
	{
		sideShootRightColliding = false;
	}

	if (mouseHitbox.getGlobalBounds().intersects(upShoot.getBody().getGlobalBounds()))
	{
		upShootColliding = true;
	}
	else
	{
		upShootColliding = false;
	}

	if (mouseHitbox.getGlobalBounds().intersects(downShoot.getBody().getGlobalBounds()))
	{
		downShootColliding = true;
	}
	else
	{
		downShootColliding = false;
	}
}
