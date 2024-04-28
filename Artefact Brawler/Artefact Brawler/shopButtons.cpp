// IAN PEREZ BUNUEL

#include "shopButtons.h"

void shopButtons::draw(sf::RenderWindow& t_window)
{
	t_window.draw(body);
	t_window.draw(text);
}

void shopButtons::setup(sf::Vector2f t_pos, float t_width, float t_height, int t_price, AttackVarients t_attackType, sf::Color t_color)
{
	attackVarient = t_attackType;
	price = t_price;

	// Get the dimensions
	width = t_width;
	height = t_height;

	body.setSize({ width, height });
	body.setFillColor(t_color);

	body.setOrigin({ width / 2, height / 2 });

	position = t_pos;
	body.setPosition(position);

	// Text
	if (!font.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}

	text.setFont(font);
	text.setStyle(sf::Text::Underlined | sf::Text::Italic | sf::Text::Bold);
	text.setCharacterSize(12U);
	text.setOutlineColor(sf::Color::Black);
	text.setFillColor(sf::Color::Red);
	text.setOutlineThickness(3.0f);
	text.setPosition({ position.x - (width / 2) + 5, position.y - (height / 2) + 5 });
	text.setString("Locked");
}

bool shopButtons::checkForMouse(sf::Vector2f t_mousePos)
{
	// Check if the mouse is within the button on the x-axis
	if (t_mousePos.x >= position.x - ((width) / 2) && t_mousePos.x <= position.x + ((width) / 2))
	{
		// Check if the mouse is within the button on the y-axis
		if (t_mousePos.y <= position.y + (height / 2) && t_mousePos.y >= position.y - (height / 2))
		{
			// if colliding
			colliding = true;
			return true;
		}
	}

	// if not colliding 
	colliding = false;

	return colliding; // if not colliding
}

void shopButtons::onPress(int& t_coins, SpecialType t_attack)
{
	if (unlocked)
	{
		switch (attackVarient)
		{
		case AttackVarients::Neutral:
			AttackManager::specialNeutral = t_attack;
			break;

		case AttackVarients::SideLeft:
			std::cout << "EQUIPPED \n";
			AttackManager::specialSideLeft = t_attack;
			break;

		case AttackVarients::SideRight:
			std::cout << "EQUIPPED \n";
			AttackManager::specialSideRight = t_attack;
			break;

		case AttackVarients::Up:
			std::cout << "EQUIPPED \n";
			AttackManager::specialUp = t_attack;
			break;

		case AttackVarients::Down:
			std::cout << "EQUIPPED \n";
			AttackManager::specialDown = t_attack;
			break;
		}

		// Set color
		text.setFillColor(sf::Color::Green);
	}
	else
	{
		if (t_coins >= price)
		{
			// Pay the price
			t_coins -= price;

			// Set unlocked to true
			unlocked = true;

			text.setString("Unlocked");
			text.setFillColor({0, 255, 0, 100});

		}
		else
		{
			std::cout << "NOT ENOUGH MONEY \n";
		}
	}
}
