#include "Shop.h"

Shop::Shop()
{
	setupFontAndText();
}

void Shop::processEvents(sf::Event t_event)
{
}

void Shop::update(sf::Time t_deltaTime)
{
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
	//coinsText.setString("Coins: " + std::to_string(coins));
	coinsText.setStyle(sf::Text::Underlined | sf::Text::Italic | sf::Text::Bold);
	coinsText.setCharacterSize(30U);
	coinsText.setOutlineColor(sf::Color::Yellow);
	coinsText.setFillColor({ 255, 100, 0, 255 });
	coinsText.setOutlineThickness(3.0f);
	coinsText.setPosition(SCREEN_WIDTH - 250, 50);
}
