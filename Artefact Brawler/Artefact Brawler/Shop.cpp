// IAN PEREZ BUNUEL

#include "Shop.h"
#include "game.h"

Shop::Shop()
{
	setupFontAndText();
	setupButtons();
}

void Shop::processEvents(sf::Event t_event)
{
	if (sf::Event::KeyPressed == t_event.type)
	{
		processKeys(t_event);
	}
}

void Shop::processKeys(sf::Event t_event)
{
	// On escape swap to show scene
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		transitionCircle.transition(Scene::MainMenu);
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

void Shop::processMouseDown(sf::Event t_event)
{
	if (sideShootLeftColliding)
	{
		std::cout << "COLIDING \n";
		sideShootLeft.onPress(Currency::coins, SpecialType::ShootingSideLeft);
	}
}

void Shop::processMouseMove(sf::Event t_event)
{
	mousePos.x = static_cast<float>(t_event.mouseMove.x);
	mousePos.y = static_cast<float>(t_event.mouseMove.y);

	std::cout << mousePos.x << ", " << mousePos.y << std::endl;
}

void Shop::update(sf::Time t_deltaTime)
{

	// Screen Transition
	if (transitionCircle.active)
	{
		transitionCircle.transition(transitionCircle.goTo);
	}

	// Coin update
	coinsText.setString("Coins: " + std::to_string(Currency::coins));


	// Check if your hovering over a button
	sideShootLeftColliding = sideShootLeft.checkForMouse(mousePos);
}

void Shop::render(sf::RenderWindow& t_window)
{
	// Coins Text
	t_window.draw(coinsText);

	// Screen Transition
	if (transitionCircle.active)
	{
		t_window.draw(transitionCircle.getBody());
	}

	t_window.draw(sideShootLeft.getBody());
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
	sideShootLeft.setup({500.0f, 500.0f}, 100.0f, 100.0f, 10, AttackVarients::Side, sf::Color::Blue);
}
