#include "kneeSpecial.h"
//LIAM TREACY
kneeSpecial::kneeSpecial()
{
	setup();
}

void kneeSpecial::spawn(sf::Vector2f t_pos)
{
	// set position
	position = t_pos;
	hitbox.setPosition(position);

	active = true; // set it to active
}

void kneeSpecial::attack(sf::Vector2f t_pos, Sandbag& t_sandbag, bool& t_canAttack)
{
	// while attack is happening
	if (timer < ACTIVE_DURATION)
	{
		timer++;

		// set position
		position = t_pos;
		hitbox.setPosition(position + DISPLACEMENT);

		// if hitbox intersects sandbag
		if (hitbox.getGlobalBounds().intersects(t_sandbag.getBody().getGlobalBounds()))
		{
			hasHit = true;
		}
		else
		{
			hasHit = false;
		}
	}
	// if attack is over
	else if (timer >= ACTIVE_DURATION)
	{
		// when attack is over
		timer = 0;
		active = false;

		// can attack becomes false
		t_canAttack = false;
	}
}

void kneeSpecial::setup()
{
	hitbox.setFillColor(sf::Color::Green);
	hitbox.setSize({ width, height });
	hitbox.setOrigin({ width / 2, height / 2 });
}
