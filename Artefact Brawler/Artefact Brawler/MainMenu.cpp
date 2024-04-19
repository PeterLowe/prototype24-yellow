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
		SceneClass::currentMode = colosseum.sendTo;
	}

	if (shopColliding)
	{
		SceneClass::currentMode = shop.sendTo;
	}

	if (helpColliding)
	{
		SceneClass::currentMode = help.sendTo;
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
}

void MainMenu::render(sf::RenderWindow& t_window)
{
	t_window.draw(colosseum.getBody());
	t_window.draw(shop.getBody());
	//t_window.draw(help.getBody());
}

void MainMenu::setupButtons()
{
	colosseum.setup(colosseumPos, buttonWidth, buttonHeight, Scene::GamePlay, sf::Color::Red); // CHANGE SCENE TO CHARACTER SELECT ONCE DONE

	shop.setup(shopPos, buttonWidth, buttonHeight, Scene::Shop, sf::Color::Yellow);

	//help.setup(helpPos, buttonWidth, buttonHeight, Scene::Help);
}
