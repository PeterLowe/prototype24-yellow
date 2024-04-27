#include "shopButtons.h"

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
	}
	else
	{
		if (t_coins >= price)
		{
			// Pay the price
			t_coins -= price;

			// Set unlocked to true
			unlocked = true;

			std::cout << "UNLOCKED \n";
		}
		else
		{
			std::cout << "NOT ENOUGH MONEY \n";
		}
	}
}
