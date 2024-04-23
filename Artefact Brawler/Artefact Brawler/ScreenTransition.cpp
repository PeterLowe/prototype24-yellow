// IAN PEREZ BUNUEL

#include "ScreenTransition.h"

ScreenTransition::ScreenTransition()
{
	body.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	body.setFillColor(sf::Color::White);
	body.setRadius(size);
	body.setOrigin(size, size);
}

void ScreenTransition::transition(Scene t_goTo)
{
	active = true;
	goTo = t_goTo;

	if (grow)
	{
		if (size < MAX_SIZE)
		{
			size += 15;
			body.setRadius(size);
			body.setOrigin(size, size);
		}
		else
		{
			// Stop growing
			grow = false;

			// Swap scene
			SceneClass::currentMode = goTo;
		}
	}
	else
	{
		if (size > MIN_SIZE)
		{
			size -= 15;
			body.setRadius(size);
			body.setOrigin(size, size);
		}
		else
		{
			active = false;
			grow = true;
		}
	}
}
