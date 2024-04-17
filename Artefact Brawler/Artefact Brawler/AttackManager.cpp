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

void AttackManager::neutralAttack()
{
	// Call the neutral attack equipped
	switch (neutral)
	{
	case AttackType::None:
		break;

	case AttackType::BasicNeutral:
		//Attacks::basicNeutral.attack();
		break;

	}
}

void AttackManager::sideAttack()
{
	// Call the side attack equipped
	switch (side)
	{
	case AttackType::None:
		break;

	case AttackType::BasicSide:
		//Attacks::basicSide.attack();
		break;
	}
}

void AttackManager::upAttack()
{
	// Call the up attack equipped
	switch (up)
	{
	case AttackType::None:
		break;

	case AttackType::BasicUp:
		//Attacks::basicUp.attack();
		break;
	}
}

void AttackManager::downAttack()
{
	// Call the down attack equipped
	switch (down)
	{
	case AttackType::None:
		break;

	case AttackType::BasicDown:
		//Attacks::basicDown.attack();
		break;
	}
}
