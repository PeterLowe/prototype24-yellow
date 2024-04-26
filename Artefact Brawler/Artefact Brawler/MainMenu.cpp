// IAN PEREZ BUNUEL

#include "MainMenu.h"


MainMenu::MainMenu()
{
	// Setup mouse hitbox
	mouseHitbox.setFillColor(sf::Color::Blue);
	mouseHitbox.setSize({ 20.0f, 20.0f });
	mouseHitbox.setOrigin({ 10.0f, 10.0f });

	setupButtons();
}

void MainMenu::processEvents(sf::Event t_event)
{
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

void MainMenu::processMouseDown(sf::Event t_event)
{
	// Deactivate controller if the mouse is pressed
	controllerConnected = false;

	if (colosseumColliding)
	{
		transitionCircle.transition(colosseum.sendTo);
	}

	if (shopColliding)
	{
		transitionCircle.transition(shop.sendTo);
	}

	if (helpColliding)
	{
		transitionCircle.transition(help.sendTo);
	}
}

void MainMenu::processMouseMove(sf::Event t_event)
{
	mousePos.x = static_cast<float>(t_event.mouseMove.x);
	mousePos.y = static_cast<float>(t_event.mouseMove.y);
}

void MainMenu::processController()
{
	if (controller.currentState.A)
	{
		if (colosseumColliding)
		{
			transitionCircle.transition(colosseum.sendTo);
		}

		if (shopColliding)
		{
			transitionCircle.transition(shop.sendTo);
		}

		if (helpColliding)
		{
			transitionCircle.transition(help.sendTo);
		}
	}

	// Move the hitbox for the mouse using the controller
	moveMouseHitbox();
}


void MainMenu::update(sf::Time t_deltaTime)
{
	if (controllerConnected)
	{
		controller.update();
		processController();


		// Check if its over a button
		if (mouseHitbox.getGlobalBounds().intersects(colosseum.getBody().getGlobalBounds()))
		{
			colosseumColliding = true;
		}
		else
		{
			colosseumColliding = false;
		}

		if (mouseHitbox.getGlobalBounds().intersects(shop.getBody().getGlobalBounds()))
		{
			shopColliding = true;
		}
		else
		{
			shopColliding = false;
		}

		if (mouseHitbox.getGlobalBounds().intersects(help.getBody().getGlobalBounds()))
		{
			helpColliding = true;
		}
		else
		{
			helpColliding = false;
		}
	}
	else
	{
		mouseHitboxPosition = mousePos;
		// Check if the controller was connected
		controllerConnected = controller.connectCheck();

		// Check if your hovering over a button
		colosseumColliding = colosseum.checkForMouse(mousePos);
		shopColliding = shop.checkForMouse(mousePos);
		helpColliding = help.checkForMouse(mousePos);
	}

	// Screen Transition
	if (transitionCircle.active)
	{
		transitionCircle.transition(transitionCircle.goTo);
	}
}

void MainMenu::render(sf::RenderWindow& t_window)
{
	// Buttons
	t_window.draw(colosseum.getBody());
	t_window.draw(shop.getBody());
	//t_window.draw(help.getBody());


	// Mouse hitbox
	if (controllerConnected)
	{
		t_window.draw(mouseHitbox);
	}


	// Screen Transition
	if (transitionCircle.active)
	{
		t_window.draw(transitionCircle.getBody());
	}
}

void MainMenu::moveMouseHitbox()
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

void MainMenu::setupButtons()
{
	colosseum.setup(colosseumPos, buttonWidth, buttonHeight, Scene::CharacterSelect, sf::Color::Red);

	shop.setup(shopPos, buttonWidth, buttonHeight, Scene::Shop, sf::Color::Yellow);

	//help.setup(helpPos, buttonWidth, buttonHeight, Scene::Help);
}
