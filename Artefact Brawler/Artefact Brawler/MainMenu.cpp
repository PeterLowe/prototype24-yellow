// IAN PEREZ BUNUEL

#include "MainMenu.h"


MainMenu::MainMenu()
{
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

void MainMenu::update(sf::Time t_deltaTime)
{
	// Check if your hovering over a button
	colosseumColliding = colosseum.checkForMouse(mousePos);
	shopColliding = shop.checkForMouse(mousePos);
	helpColliding = help.checkForMouse(mousePos);

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

	// Screen Transition
	if (transitionCircle.active)
	{
		t_window.draw(transitionCircle.getBody());
	}
}

void MainMenu::setupButtons()
{
	colosseum.setup(colosseumPos, buttonWidth, buttonHeight, Scene::CharacterSelect, sf::Color::Red);

	shop.setup(shopPos, buttonWidth, buttonHeight, Scene::Shop, sf::Color::Yellow);

	//help.setup(helpPos, buttonWidth, buttonHeight, Scene::Help);
}
