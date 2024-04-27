#include "Partical.h"
#include <iostream>

Partical::Partical()
{
	setup();
}

void Partical::setup()
{
	// body.setFillColor(sf::Color::White);
	body.setFillColor({ 200, 200, 200, 255 });
}

void Partical::spawn(sf::Vector2f t_pos)
{
	// Set position
	position = t_pos;
	body.setPosition(position);

	// Randomize angle particals go in
	float randDirection = (rand() % 360);
	angle = randDirection + 90;

	// Randomize speed
	speed = (rand() % 5) + 1;

	// Set size and rotation
	int randAngleD = (rand() % 360) + 1;
	float randSize = (rand() % 20) + 5;

	// Body
	size = randSize;
	body.setSize({ size, size });
	body.setOrigin({ size / 2, size / 2 });
	body.setRotation(randAngleD);

	active = true;
}

void Partical::move()
{
	// 0 is Right, adding to 0 will make it go anti-clockwise
	float angleR = (angle) * 3.14f / 180;

	direction.x = (sin(angleR) * speed);
	direction.y = (cos(angleR) * speed) * -1;

	position += direction;


	// Decrease size as it moves
	if (size > MIN_SIZE)
	{
		size -= 0.2f;
		body.setSize({ size, size });
	}
	else
	{
		active = false;
	}
	// Decease Speed as it moves
	if (speed > MIN_SPEED)
	{
		speed -= 0.2f;
	}
	else
	{
		if (size > MIN_SIZE)
		{
			size -= 0.75f;
			body.setSize({ size, size });
		}
		else
		{
			active = false;
		}
	}

	body.setPosition(position);
}

void Partical::bounds()
{
	if (position.x <= -50)
	{
		active = false;
	}
	else if (position.x >= SCREEN_WIDTH + 100)
	{
		active = false;
	}

	if (position.y <= -50)
	{
		active = false;
	}
	else if (position.y >= SCREEN_HEIGHT + 100)
	{
		active = false;
	}
}
