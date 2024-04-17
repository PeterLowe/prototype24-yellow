#include "AttackManager.h"

AttackType neutral = AttackType::BasicNeutral;
AttackType side = AttackType::BasicSide;
AttackType up = AttackType::BasicUp;
AttackType down = AttackType::BasicDown;

static Attacks attacks;

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

//-------------------- Attack Drawing --------------------//
void AttackManager::drawNeutral(sf::RenderWindow& t_window)
{
	switch (neutral)
	{
	case AttackType::None:
		break;

	case AttackType::BasicNeutral:

		// Draw attack
		t_window.draw(attacks.basicNeutral.getBodyLeft());
		t_window.draw(attacks.basicNeutral.getBodyRight());

		break;
	}
}

void AttackManager::drawSide(sf::RenderWindow& t_window)
{
	switch (side)
	{
	case AttackType::None:
		break;

	case AttackType::BasicSide:

		// Draw attack
		t_window.draw(attacks.basicSide.getBody());

		break;
	}
}

void AttackManager::drawUp(sf::RenderWindow& t_window)
{
	switch (up)
	{
	case AttackType::None:
		break;

	case AttackType::BasicUp:

		// Draw attack
		t_window.draw(attacks.basicUp.getBody());

		break;
	}
}

void AttackManager::drawDown(sf::RenderWindow& t_window)
{
	switch (down)
	{
	case AttackType::None:
		break;

	case AttackType::BasicDown:

		// Draw attack
		t_window.draw(attacks.basicDown.getBody());

		break;
	}
}

//---------------- Attack Information ----------------//


/// Get Active ///
bool AttackManager::getNeutralActive()
{
	// Call the neutral spawning equipped
	switch (neutral)
	{
	case AttackType::None:
		return false;
		break;

	case AttackType::BasicNeutral:

		return attacks.basicNeutral.active;

		break;
	}
}

bool AttackManager::getSideActive()
{
	// Call the side spawning equipped
	switch (side)
	{
	case AttackType::None:
		return false;
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
		return false;
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
		return false;
		break;

	case AttackType::BasicDown:

		return attacks.basicDown.active;

		break;
	}
}


/// Get damage ///
int AttackManager::getNeutralDamage()
{
	switch (neutral)
	{
	case AttackType::None:
		return 0;
		break;

	case AttackType::BasicNeutral:

		return attacks.basicNeutral.damage;

		break;
	}
}

int AttackManager::getSideDamage()
{
	switch (side)
	{
	case AttackType::None:
		return 0;
		break;

	case AttackType::BasicSide:

		return attacks.basicSide.damage;

		break;
	}
}

int AttackManager::getUpDamage()
{
	switch (neutral)
	{
	case AttackType::None:
		return 0;
		break;

	case AttackType::BasicNeutral:

		return attacks.basicNeutral.damage;

		break;
	}
}

int AttackManager::getDownDamage()
{
	switch (down)
	{
	case AttackType::None:
		return 0;
		break;

	case AttackType::BasicDown:

		return attacks.basicDown.damage;

		break;
	}
}


/// Get Power ///
float AttackManager::getNeutralPower()
{
	switch (neutral)
	{
	case AttackType::None:
		return 0;
		break;

	case AttackType::BasicNeutral:

		return attacks.basicNeutral.power;

		break;
	}
}

float AttackManager::getSidePower()
{
	switch (side)
	{
	case AttackType::None:
		return 0;
		break;

	case AttackType::BasicSide:

		return attacks.basicSide.power;

		break;
	}
}

float AttackManager::getUpPower()
{
	switch (up)
	{
	case AttackType::None:
		return 0;
		break;

	case AttackType::BasicUp:

		return attacks.basicUp.power;

		break;
	}
}

float AttackManager::getDownPower()
{
	switch (down)
	{
	case AttackType::None:
		return 0;
		break;

	case AttackType::BasicDown:

		return attacks.basicNeutral.power;

		break;
	}
}



/// Get AngleD ///
float AttackManager::getNeutralAngleD()
{
	switch (neutral)
	{
	case AttackType::None:
		return 0;
		break;

	case AttackType::BasicNeutral:

		return attacks.basicNeutral.angleD;

		break;
	}
}

float AttackManager::getSideAngleD()
{
	switch (side)
	{
	case AttackType::None:
		return 0;
		break;

	case AttackType::BasicSide:

		return attacks.basicSide.angleD;

		break;
	}
}

float AttackManager::getUpAngleD()
{
	switch (up)
	{
	case AttackType::None:
		return 0;
		break;

	case AttackType::BasicUp:

		return attacks.basicUp.angleD;

		break;
	}
}

float AttackManager::getDownAngleD()
{
	switch (down)
	{
	case AttackType::None:
		return 0;
		break;

	case AttackType::BasicDown:

		return attacks.basicDown.angleD;

		break;
	}
}


// Get Endlag
int AttackManager::getNeutralEndlag()
{
	switch (neutral)
	{
	case AttackType::None:
		return 0;
		break;

	case AttackType::BasicNeutral:

		return attacks.basicNeutral.END_LAG;

		break;
	}
}

int AttackManager::getSideEndlag()
{
	switch (side)
	{
	case AttackType::None:
		return 0;
		break;

	case AttackType::BasicSide:

		return attacks.basicSide.END_LAG;

		break;
	}
}

int AttackManager::getUpEndlag()
{
	switch (up)
	{
	case AttackType::None:
		return 0;
		break;

	case AttackType::BasicUp:

		return attacks.basicUp.END_LAG;

		break;
	}
}

int AttackManager::getDownEndlag()
{
	switch (down)
	{
	case AttackType::None:
		return 0;
		break;

	case AttackType::BasicDown:

		return attacks.basicDown.END_LAG;

		break;
	}
}


/// Get hasHit ///
bool AttackManager::getNeutralHasHit()
{
	switch (neutral)
	{
	case AttackType::None:
		return 0;
		break;

	case AttackType::BasicNeutral:

		return attacks.basicNeutral.hasHit;

		break;
	}
}

bool AttackManager::getSideHasHit()
{
	switch (side)
	{
	case AttackType::None:
		return 0;
		break;

	case AttackType::BasicSide:

		return attacks.basicSide.hasHit;

		break;
	}
}

bool AttackManager::getUpHasHit()
{
	switch (up)
	{
	case AttackType::None:
		return 0;
		break;

	case AttackType::BasicUp:

		return attacks.basicUp.hasHit;

		break;
	}
}

bool AttackManager::getDownHasHit()
{
	switch (down)
	{
	case AttackType::None:
		return 0;
		break;

	case AttackType::BasicDown:

		return attacks.basicDown.hasHit;

		break;
	}
}
