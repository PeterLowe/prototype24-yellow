// IAN PEREZ BUNUEL

#include "ShootSide.h"

ShootSide::ShootSide()
{
	angleD = 0;

	if (angleRight > 225 && angleRight <= 225)
	{
		angleLeft = 360 - (angleRight * 1.5f);
	}
	else
	{
		angleLeft = 360 - angleRight;
	}
}

void ShootSide::setup(bool t_left)
{
	// Check what direction the side attack is in
	leftAttack = t_left;
	// If attacking to the left...
	if (leftAttack)
	{
		direction = Direction::Left;
		angleD = angleLeft;
	}
	// If attacking to the right
	else
	{
		direction = Direction::Right;
		angleD = angleRight;
	}

	hitbox.setFillColor(sf::Color::Green);
	hitbox.setSize({ width, height });
	hitbox.setOrigin({ width / 2, height / 2 });
}

void ShootSide::spawn(sf::Vector2f t_pos)
{
	// set the position
	position = t_pos;
	hitbox.setPosition(position);

	// set it to active
	active = true;
}

void ShootSide::attack(sf::Vector2f t_pos, Sandbag& t_sandbag, bool& t_canAttack)
{
	// While attack is happening
	if (timer < ACTIVE_DURATION)
	{
		timer++;


		// Set Direction to go in
		if (direction == Direction::Right)
		{
			velocity.x = speed;
		}
		else
		{
			velocity.x = -speed;
		}

		// set the position
		position += velocity;
		hitbox.setPosition(position);


		// if the hitbox intersects sandbag
		if (hitbox.getGlobalBounds().intersects(t_sandbag.getBody().getGlobalBounds()))
		{
			hasHit = true;
		}
		else
		{
			hasHit = false;
		}
	}
	// If the attack is over
	else if (timer >= ACTIVE_DURATION)
	{
		// Once the attack is over
		timer = 0;
		active = false;

		// Can attack becomes false
		t_canAttack = false;
	}
}
