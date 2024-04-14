#include "Shop.h"
#include "game.h"

Shop::Shop()
{
	setupFontAndText();
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
		Game::currentMode = Scene::GamePlay;
	}
}

void Shop::update(sf::Time t_deltaTime)
{
	coinsText.setString("Coins: " + std::to_string(Currency::coins));
}

void Shop::render(sf::RenderWindow& t_window)
{
	// Coins Text
	t_window.draw(coinsText);
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
