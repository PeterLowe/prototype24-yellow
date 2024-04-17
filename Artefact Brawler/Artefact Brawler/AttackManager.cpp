#include "AttackManager.h"

AttackType neutral = AttackType::BasicNeutral;
AttackType sideLeft = AttackType::BasicSideLeft;
AttackType sideRight = AttackType::BasicSideRight;
AttackType up = AttackType::BasicUp;
AttackType down = AttackType::BasicDown;

static Attacks attacks;




// Used for attacks like side attacks with different directions
void AttackManager::setup()
{
	// Setup the basic side attacks
	attacks.basicSideLeft.setup(true);
	attacks.basicSideRight.setup(false);
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

void AttackManager::sideAttackLeft(sf::Vector2f t_pos, Sandbag& t_sandbag, bool& t_canAttack)
{
	// Call the sideLeft attack equipped
	switch (sideLeft)
	{
	case AttackType::None:
		break;

	case AttackType::BasicSideLeft:
		attacks.basicSideLeft.attack(t_pos, t_sandbag, t_canAttack);
		break;
	}
}

void AttackManager::sideAttackRight(sf::Vector2f t_pos, Sandbag& t_sandbag, bool& t_canAttack)
{
	// Call the sideRight attack equipped
	switch (sideRight)
	{
	case AttackType::None:
		break;

	case AttackType::BasicSideRight:
		attacks.basicSideRight.attack(t_pos, t_sandbag, t_canAttack);
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

void AttackManager::sideSpawnLeft(sf::Vector2f t_pos)
{
	// Call the down spawning equipped
	switch (sideLeft)
	{
	case AttackType::None:
		break;

	case AttackType::BasicSideLeft:
		attacks.basicSideLeft.spawn(t_pos);
		break;
	}
}

void AttackManager::sideSpawnRight(sf::Vector2f t_pos)
{
	// Call the down spawning equipped
	switch (sideRight)
	{
	case AttackType::None:
		break;

	case AttackType::BasicSideRight:
		attacks.basicSideRight.spawn(t_pos);
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

void AttackManager::drawSideLeft(sf::RenderWindow& t_window)
{
	switch (sideLeft)
	{
	case AttackType::None:
		break;

	case AttackType::BasicSideLeft:

		// Draw attack
		t_window.draw(attacks.basicSideLeft.getBody());

		break;
	}
}

void AttackManager::drawSideRight(sf::RenderWindow& t_window)
{
	switch (sideRight)
	{
	case AttackType::None:
		break;

	case AttackType::BasicSideRight:

		// Draw attack
		t_window.draw(attacks.basicSideRight.getBody());

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

bool AttackManager::getSideLeftActive()
{
	// Call the side spawning equipped
	switch (sideLeft)
	{
	case AttackType::None:
		return false;
		break;

	case AttackType::BasicSideLeft:

		return attacks.basicSideLeft.active;

		break;
	}
}

bool AttackManager::getSideRightActive()
{
	// Call the side spawning equipped
	switch (sideRight)
	{
	case AttackType::None:
		return false;
		break;

	case AttackType::BasicSideRight:

		return attacks.basicSideRight.active;

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

int AttackManager::getSideDamageLeft()
{
	switch (sideLeft)
	{
	case AttackType::None:
		return 0;
		break;

	case AttackType::BasicSideLeft:

		return attacks.basicSideLeft.damage;

		break;
	}
}

int AttackManager::getSideDamageRight()
{
	switch (sideRight)
	{
	case AttackType::None:
		return 0;
		break;

	case AttackType::BasicSideRight:

		return attacks.basicSideRight.damage;

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

float AttackManager::getSidePowerLeft()
{
	switch (sideLeft)
	{
	case AttackType::None:
		return 0;
		break;

	case AttackType::BasicSideLeft:

		return attacks.basicSideLeft.power;

		break;
	}
}

float AttackManager::getSidePowerRight()
{
	switch (sideRight)
	{
	case AttackType::None:
		return 0;
		break;

	case AttackType::BasicSideRight:

		return attacks.basicSideRight.power;

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

float AttackManager::getSideAngleDLeft()
{
	switch (sideLeft)
	{
	case AttackType::None:
		return 0;
		break;

	case AttackType::BasicSideLeft:

		return attacks.basicSideLeft.angleD;

		break;
	}
}

float AttackManager::getSideAngleDRight()
{
	switch (sideRight)
	{
	case AttackType::None:
		return 0;
		break;

	case AttackType::BasicSideRight:

		return attacks.basicSideRight.angleD;

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

int AttackManager::getSideEndlagLeft()
{
	switch (sideLeft)
	{
	case AttackType::None:
		return 0;
		break;

	case AttackType::BasicSideLeft:

		return attacks.basicSideLeft.END_LAG;

		break;
	}
}

int AttackManager::getSideEndlagRight()
{
	switch (sideRight)
	{
	case AttackType::None:
		return 0;
		break;

	case AttackType::BasicSideRight:

		return attacks.basicSideRight.END_LAG;

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

bool AttackManager::getSideHasHitLeft()
{
	switch (sideLeft)
	{
	case AttackType::None:
		return 0;
		break;

	case AttackType::BasicSideLeft:

		return attacks.basicSideLeft.hasHit;

		break;
	}
}

bool AttackManager::getSideHasHitRight()
{
	switch (sideRight)
	{
	case AttackType::None:
		return 0;
		break;

	case AttackType::BasicSideRight:

		return attacks.basicSideRight.hasHit;

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
