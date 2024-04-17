#pragma once

#include <SFML/Graphics.hpp>

// Including Attacks
#include "NeutralAttack.h"
#include "SideAttack.h"
#include "UpAttack.h"
#include "DownAttack.h"

enum class AttackType
{
	None,

	// Basics
	BasicNeutral,
	BasicSideLeft,
	BasicSideRight,
	BasicUp,
	BasicDown

};

// Structure that holds normal attacks
struct Attacks
{
	// Basics
	NeutralAttack basicNeutral;
	SideAttack basicSideLeft;
	SideAttack basicSideRight;
	UpAttack basicUp;
	DownAttack basicDown;

	// Next Attack Set
};

// Structure that holds special attacks
struct Specials
{
};



class AttackManager
{
public:

	static void setup();

	// Attacking
	static void neutralAttack(sf::Vector2f t_pos, Sandbag& t_sandbag, bool& t_canAttack);
	static void sideAttackLeft(sf::Vector2f t_pos, Sandbag& t_sandbag, bool& t_canAttack);
	static void sideAttackRight(sf::Vector2f t_pos, Sandbag& t_sandbag, bool& t_canAttack);
	static void upAttack(sf::Vector2f t_pos, Sandbag& t_sandbag, bool& t_canAttack);
	static void downAttack(sf::Vector2f t_pos, Sandbag& t_sandbag, bool& t_canAttack);

	// Spawning
	static void neutralSpawn(sf::Vector2f t_pos);
	static void sideSpawnLeft(sf::Vector2f t_pos);
	static void sideSpawnRight(sf::Vector2f t_pos);
	static void upSpawn(sf::Vector2f t_pos);
	static void downSpawn(sf::Vector2f t_pos);

	// Draw
	static void drawNeutral(sf::RenderWindow& t_window);
	static void drawSideLeft(sf::RenderWindow& t_window);
	static void drawSideRight(sf::RenderWindow& t_window);
	static void drawUp(sf::RenderWindow& t_window);
	static void drawDown(sf::RenderWindow& t_window);

	// Active
	static bool getNeutralActive();
	static bool getSideLeftActive();
	static bool getSideRightActive();
	static bool getUpActive();
	static bool getDownActive();

	// Damage
	static int getNeutralDamage();
	static int getSideDamageLeft();
	static int getSideDamageRight();
	static int getUpDamage();
	static int getDownDamage();

	// Power
	static float getNeutralPower();
	static float getSidePowerLeft();
	static float getSidePowerRight();
	static float getUpPower();
	static float getDownPower();

	// AngleD
	static float getNeutralAngleD();
	static float getSideAngleDLeft();
	static float getSideAngleDRight();
	static float getUpAngleD();
	static float getDownAngleD();

	// Endlag
	static int getNeutralEndlag();
	static int getSideEndlagLeft();
	static int getSideEndlagRight();
	static int getUpEndlag();
	static int getDownEndlag();

	// Has Hit
	static bool getNeutralHasHit();
	static bool getSideHasHitLeft();
	static bool getSideHasHitRight();
	static bool getUpHasHit();
	static bool getDownHasHit();


private:


};

