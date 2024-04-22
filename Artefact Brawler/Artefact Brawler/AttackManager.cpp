#include "AttackManager.h"

AttackType neutral = AttackType::BasicNeutral;
AttackType sideLeft = AttackType::BasicSideLeft;
AttackType sideRight = AttackType::BasicSideRight;
AttackType up = AttackType::BasicUp;
AttackType down = AttackType::BasicDown;

static Attacks attacks;


SpecialType specialNeutral = SpecialType::ShootingNeutral;
SpecialType specialSideLeft = SpecialType::ShootingSideLeft;
SpecialType specialSideRight = SpecialType::ShootingSideRight;
SpecialType specialUp = SpecialType::ShootingUp;
SpecialType specialDown = SpecialType::ShootingDown;

static Specials specials;




// Used for attacks like side attacks with different directions
void AttackManager::setup()
{
	// Setup the basic side attacks
	attacks.basicSideLeft.setup(true);
	attacks.basicSideRight.setup(false);

	// special Side shooting
	specials.shootSideLeft.setup(true);
	specials.shootSideRight.setup(false);
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
	// Call the sideLeft spawning equipped
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
	// Call the sideRight spawning equipped
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
	// Call the up spawning equipped
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

void AttackManager::neutralSpecial(sf::Vector2f t_pos, Sandbag& t_sandbag, bool& t_canAttack)
{
	// Call the neutral attack equipped
	switch (specialNeutral)
	{
	case SpecialType::None:
		break;

	case SpecialType::ShootingNeutral:
		break;

	}
}

void AttackManager::sideSpecialLeft(sf::Vector2f t_pos, Sandbag& t_sandbag, bool& t_canAttack)
{
	// Call the sideLeft special equipped
	switch (specialSideLeft)
	{
	case SpecialType::None:
		break;

	case SpecialType::ShootingSideLeft:
		specials.shootSideLeft.attack(t_pos, t_sandbag, t_canAttack);
		break;

	}
}

void AttackManager::sideSpecialRight(sf::Vector2f t_pos, Sandbag& t_sandbag, bool& t_canAttack)
{
	// Call the sideRight special equipped
	switch (specialSideRight)
	{
	case SpecialType::None:
		break;

	case SpecialType::ShootingSideRight:
		specials.shootSideRight.attack(t_pos, t_sandbag, t_canAttack);
		break;

	}
}

void AttackManager::upSpecial(sf::Vector2f t_pos, Sandbag& t_sandbag, bool& t_canAttack)
{
	// Call the up special equipped
	switch (specialUp)
	{
	case SpecialType::None:
		break;

	case SpecialType::ShootingUp:
		break;

	}
}

void AttackManager::downSpecial(sf::Vector2f t_pos, Sandbag& t_sandbag, bool& t_canAttack)
{
	switch (specialDown)
	{
	case SpecialType::None:
		break;

	case SpecialType::ShootingDown:
		break;

	}
}

void AttackManager::neutralSpecialSpawn(sf::Vector2f t_pos)
{
	
	switch (specialNeutral)
	{
	case SpecialType::None:
		break;

	case SpecialType::ShootingNeutral:
		break;
	}
}

void AttackManager::sideSpecialSpawnLeft(sf::Vector2f t_pos)
{
	// Call the sideLeft spawning equipped
	switch (specialSideLeft)
	{
	case SpecialType::None:
		break;

	case SpecialType::ShootingSideLeft:
		specials.shootSideLeft.spawn(t_pos);
		break;
	}
}

void AttackManager::sideSpecialSpawnRight(sf::Vector2f t_pos)
{
	// Call the sideLeft spawning equipped
	switch (specialSideRight)
	{
	case SpecialType::None:
		break;

	case SpecialType::ShootingSideRight:
		specials.shootSideRight.spawn(t_pos);
		break;
	}
}

void AttackManager::upSpecialSpawn(sf::Vector2f t_pos)
{
	// Call the up spawning equipped
	switch (specialSideRight)
	{
	case SpecialType::None:
		break;

	case SpecialType::ShootingUp:
		break;
	}
}

void AttackManager::downSpecialSpawn(sf::Vector2f t_pos)
{
	// Call the down spawning equipped
	switch (specialSideRight)
	{
	case SpecialType::None:
		break;

	case SpecialType::ShootingDown:
		break;
	}
}

void AttackManager::drawNeutralSpecial(sf::RenderWindow& t_window)
{
	switch (specialNeutral)
	{
	case SpecialType::None:
		break;

	case SpecialType::ShootingNeutral:
		break;
	}
}

void AttackManager::drawSideSpecialLeft(sf::RenderWindow& t_window)
{
	switch (specialSideLeft)
	{
	case SpecialType::None:
		break;

	case SpecialType::ShootingSideLeft:
		t_window.draw(specials.shootSideLeft.getBody());
		break;
	}
}

void AttackManager::drawSideSpecialRight(sf::RenderWindow& t_window)
{
	switch (specialSideRight)
	{
	case SpecialType::None:
		break;

	case SpecialType::ShootingSideRight:
		t_window.draw(specials.shootSideRight.getBody());
		break;
	}
}

void AttackManager::drawUpSpecial(sf::RenderWindow& t_window)
{
	switch (specialUp)
	{
	case SpecialType::None:
		break;

	case SpecialType::ShootingUp:
		break;
	}
}

void AttackManager::drawDownSpecial(sf::RenderWindow& t_window)
{
	switch (specialDown)
	{
	case SpecialType::None:
		break;

	case SpecialType::ShootingDown:
		break;
	}
}

bool AttackManager::getNeutralSpecialActive()
{
	switch (specialNeutral)
	{
	case SpecialType::None:
		return false;
		break;

	case SpecialType::ShootingNeutral:

		//return specials.shootNeutral.active;
		return false;
		break;
	}
}

bool AttackManager::getSideSpecialLeftActive()
{
	switch (specialSideLeft)
	{
	case SpecialType::None:
		return false;
		break;

	case SpecialType::ShootingSideLeft:

		return specials.shootSideLeft.active;

		break;
	}
}

bool AttackManager::getSideSpecialRightActive()
{
	switch (specialSideRight)
	{
	case SpecialType::None:
		return false;
		break;

	case SpecialType::ShootingSideRight:

		return specials.shootSideRight.active;

		break;
	}
}

bool AttackManager::getUpSpecialActive()
{
	switch (specialUp)
	{
	case SpecialType::None:
		return false;
		break;

	case SpecialType::ShootingUp:

		//return specials.shootUp.active;
		return false;
		break;
	}
}

bool AttackManager::getDownSpecialActive()
{
	switch (specialDown)
	{
	case SpecialType::None:
		return false;
		break;

	case SpecialType::ShootingDown:

		//return specials.shootDown.active;
		return false;
		break;
	}
}

int AttackManager::getNeutralSpecialDamage()
{
	switch (specialNeutral)
	{
	case SpecialType::None:
		break;

	case SpecialType::ShootingNeutral:

		//return specials.shootNeutral.damage;
		return 0;
		break;
	}
}

int AttackManager::getSideSpecialDamageLeft()
{
	switch (specialSideLeft)
	{
	case SpecialType::None:
		break;

	case SpecialType::ShootingSideLeft:

		return specials.shootSideLeft.damage;

		break;
	}
}

int AttackManager::getSideSpecialDamageRight()
{
	switch (specialSideRight)
	{
	case SpecialType::None:
		break;

	case SpecialType::ShootingSideRight:

		return specials.shootSideRight.damage;

		break;
	}
}

int AttackManager::getUpSpecialDamage()
{
	switch (specialDown)
	{
	case SpecialType::None:
		break;

	case SpecialType::ShootingUp:

		//return specials.shootUp.damage;
		return 0;
		break;
	}
}

int AttackManager::getDownSpecialDamage()
{
	switch (specialDown)
	{
	case SpecialType::None:
		break;

	case SpecialType::ShootingDown:

		//return specials.shootDown.damage;
		return 0;
		break;
	}
}

float AttackManager::getNeutralSpecialPower()
{
	switch (specialNeutral)
	{
	case SpecialType::None:
		break;

	case SpecialType::ShootingNeutral:

		//return specials.shootNeutral.power;
		return 0;
		break;
	}
}

float AttackManager::getSideSpecialPowerLeft()
{
	switch (specialSideLeft)
	{
	case SpecialType::None:
		break;

	case SpecialType::ShootingSideLeft:

		return specials.shootSideLeft.power;

		break;
	}
}

float AttackManager::getSideSpecialPowerRight()
{
	switch (specialSideRight)
	{
	case SpecialType::None:
		break;

	case SpecialType::ShootingSideRight:

		return specials.shootSideRight.power;

		break;
	}
}

float AttackManager::getUpSpecialPower()
{
	switch (specialDown)
	{
	case SpecialType::None:
		break;

	case SpecialType::ShootingDown:

		//return specials.shootUp.power;
		return 0;
		break;
	}
}

float AttackManager::getDownSpecialPower()
{
	switch (specialDown)
	{
	case SpecialType::None:
		break;

	case SpecialType::ShootingDown:

		//return specials.shootDown.power;
		return 0;
		break;
	}
}

float AttackManager::getNeutralSpecialAngleD()
{
	switch (specialNeutral)
	{
	case SpecialType::None:
		break;

	case SpecialType::ShootingNeutral:

		//return specials.shootNeutral.angleD;
		return 0;
		break;
	}
}

float AttackManager::getSideSpecialAngleDLeft()
{
	switch (specialSideLeft)
	{
	case SpecialType::None:
		break;

	case SpecialType::ShootingSideLeft:

		return specials.shootSideLeft.angleD;

		break;
	}
}

float AttackManager::getSideSpecialAngleDRight()
{
	switch (specialSideRight)
	{
	case SpecialType::None:
		break;

	case SpecialType::ShootingSideRight:

		return specials.shootSideRight.angleD;

		break;
	}
}

float AttackManager::getUpSpecialAngleD()
{
	switch (specialUp)
	{
	case SpecialType::None:
		break;

	case SpecialType::ShootingUp:

		//return specials.shootUp.angleD;
		return 0;
		break;
	}
}

float AttackManager::getDownSpecialAngleD()
{
	switch (specialDown)
	{
	case SpecialType::None:
		break;

	case SpecialType::ShootingDown:

		//return specials.shootDown.angleD;
		return 0;
		break;
	}
}

int AttackManager::getNeutralSpecialEndlag()
{
	switch (specialNeutral)
	{
	case SpecialType::None:
		break;

	case SpecialType::ShootingNeutral:

		//return specials.shootNeutral.END_LAG;
		return 0;
		break;
	}
}

int AttackManager::getSideSpecialEndlagLeft()
{
	switch (specialSideLeft)
	{
	case SpecialType::None:
		break;

	case SpecialType::ShootingSideLeft:

		return specials.shootSideLeft.END_LAG;

		break;
	}
}

int AttackManager::getSideSpecialEndlagRight()
{
	switch (specialSideRight)
	{
	case SpecialType::None:
		break;

	case SpecialType::ShootingSideRight:

		return specials.shootSideRight.END_LAG;

		break;
	}
}

int AttackManager::getUpSpecialEndlag()
{
	switch (specialUp)
	{
	case SpecialType::None:
		break;

	case SpecialType::ShootingUp:

		//return specials.shootUp.END_LAG;
		return 0;
		break;
	}
}

int AttackManager::getDownSpecialEndlag()
{
	switch (specialDown)
	{
	case SpecialType::None:
		break;

	case SpecialType::ShootingDown:

		//return specials.shootDown.END_LAG;
		return 0;
		break;
	}
}

bool AttackManager::getNeutralSpecialHasHit()
{
	switch (specialNeutral)
	{
	case SpecialType::None:
		break;

	case SpecialType::ShootingNeutral:

		//return specials.shootNeutral.hasHit;
		return 0;
		break;
	}
}

bool AttackManager::getSideSpecialHasHitLeft()
{
	switch (specialSideLeft)
	{
	case SpecialType::None:
		break;

	case SpecialType::ShootingSideLeft:

		return specials.shootSideLeft.hasHit;

		break;
	}
}

bool AttackManager::getSideSpecialHasHitRight()
{
	switch (specialSideRight)
	{
	case SpecialType::None:
		break;

	case SpecialType::ShootingSideRight:

		return specials.shootSideRight.hasHit;

		break;
	}
}

bool AttackManager::getUpSpecialHasHit()
{
	switch (specialUp)
	{
	case SpecialType::None:
		break;

	case SpecialType::ShootingUp:

		//return specials.shootUp.hasHit;
		return 0;
		break;
	}
}

bool AttackManager::getDownSpecialHasHit()
{
	switch (specialDown)
	{
	case SpecialType::None:
		break;

	case SpecialType::ShootingDown:

		//return specials.shootDown.hasHit;
		return 0;
		break;
	}
}
