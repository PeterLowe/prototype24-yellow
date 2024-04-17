#include "AttackManager.h"

AttackType neutral = AttackType::BasicNeutral;
AttackType side = AttackType::BasicNeutral;
AttackType up = AttackType::BasicNeutral;
AttackType down = AttackType::BasicNeutral;

AttackManager::AttackManager()
{
	// Go through and find the attack you have equipped for neutral
	switch (neutral)
	{

	}

	// Go through and find the attack you have equipped for side
	switch (side)
	{

	}

	// Go through and find the attack you have equipped for up
	switch (up)
	{

	}

	// Go through and find the attack you have equipped for down
	switch (down)
	{

	}
}


/// Attacking ///
void AttackManager::neutralAttack(sf::Vector2f t_pos, Sandbag& t_sandbag, bool& t_canAttack)
{
	// Call the neutral attack equipped
	switch (neutral)
	{
	case AttackType::None:
		break;

	case AttackType::BasicNeutral:
		attacks.basicNeutral.attack(t_pos, t_sandbag, t_canAttack);
		break;

	}
}

void AttackManager::sideAttack(sf::Vector2f t_pos, Sandbag& t_sandbag, bool& t_canAttack)
{
	// Call the side attack equipped
	switch (side)
	{
	case AttackType::None:
		break;

	case AttackType::BasicSide:
		attacks.basicSide.attack(t_pos, t_sandbag, t_canAttack);
		break;
	}
}

void AttackManager::upAttack(sf::Vector2f t_pos, Sandbag& t_sandbag, bool& t_canAttack)
{
	// Call the up attack equipped
	switch (up)
	{  
	case AttackType::None:
		break;

	case AttackType::BasicUp:
		attacks.basicUp.attack(t_pos, t_sandbag, t_canAttack);
		break;
	}
}

void AttackManager::downAttack(sf::Vector2f t_pos, Sandbag& t_sandbag, bool& t_canAttack)
{
	// Call the down attack equipped
	switch (down)
	{
	case AttackType::None:
		break;

	case AttackType::BasicDown:

		// Info
		damage = attacks.basicDown.damage;
		power = attacks.basicDown.power;
		angleD = attacks.basicDown.angleD;
		endLag = attacks.basicDown.END_LAG;
		active = attacks.basicDown.active;
		hasHit = attacks.basicDown.hasHit;

		// Call attack
		attacks.basicDown.attack(t_pos, t_sandbag, t_canAttack);

		break;
	}
}


/// Spawning ///
void AttackManager::neutralSpawn(sf::Vector2f t_pos)
{
	// Call the down spawning equipped
	switch (neutral)
	{
	case AttackType::None:
		break;

	case AttackType::BasicNeutral:
		attacks.basicNeutral.spawn(t_pos);
		break;
	}
}

void AttackManager::sideSpawn(sf::Vector2f t_pos)
{
	// Call the down spawning equipped
	switch (side)
	{
	case AttackType::None:
		break;

	case AttackType::BasicSide:
		attacks.basicSide.spawn(t_pos);
		break;
	}
}

void AttackManager::upSpawn(sf::Vector2f t_pos)
{
	// Call the down spawning equipped
	switch (up)
	{
	case AttackType::None:
		break;

	case AttackType::BasicUp:
		attacks.basicUp.spawn(t_pos);
		break;
	}
}

void AttackManager::downSpawn(sf::Vector2f t_pos)
{
	// Call the down spawning equipped
	switch (down)
	{
	case AttackType::None:
		break;

	case AttackType::BasicDown:

		// Spawn attack
		attacks.basicDown.spawn(t_pos);

		break;
	}
}

bool AttackManager::getNeutralActive()
{
	// Call the neutral spawning equipped
	switch (down)
	{
	case AttackType::None:
		break;

	case AttackType::BasicDown:

		return attacks.basicDown.active;

		break;
	}
}

bool AttackManager::getSideActive()
{
	// Call the side spawning equipped
	switch (side)
	{
	case AttackType::None:
		break;

	case AttackType::BasicSide:

		return attacks.basicSide.active;

		break;
	}
}

bool AttackManager::getUpActive()
{
	// Call the up spawning equipped
	switch (up)
	{
	case AttackType::None:
		break;

	case AttackType::BasicUp:

		return attacks.basicUp.active;

		break;
	}
}

bool AttackManager::getDownActive()
{
	// Call the down spawning equipped
	switch (down)
	{
	case AttackType::None:
		break;

	case AttackType::BasicDown:

		return attacks.basicDown.active;

		break;
	}
}

