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
	BasicSide,
	BasicUp,
	BasicDown

};

// Structure that holds normal attacks
struct Attacks
{
	// Basics
	NeutralAttack basicNeutral;
	SideAttack basicSide;
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

	AttackManager();

	// Attacking
	static void neutralAttack(sf::Vector2f t_pos, Sandbag& t_sandbag, bool& t_canAttack);
	static void sideAttack(sf::Vector2f t_pos, Sandbag& t_sandbag, bool& t_canAttack);
	static void upAttack(sf::Vector2f t_pos, Sandbag& t_sandbag, bool& t_canAttack);
	static void downAttack(sf::Vector2f t_pos, Sandbag& t_sandbag, bool& t_canAttack);

	// Spawning
	static void neutralSpawn(sf::Vector2f t_pos);
	static void sideSpawn(sf::Vector2f t_pos);
	static void upSpawn(sf::Vector2f t_pos);
	static void downSpawn(sf::Vector2f t_pos);

	// Draw
	static void drawNeutral(sf::RenderWindow& t_window);
	static void drawSide(sf::RenderWindow& t_window);
	static void drawUp(sf::RenderWindow& t_window);
	static void drawDown(sf::RenderWindow& t_window);

	// Active
	static bool getNeutralActive();
	static bool getSideActive();
	static bool getUpActive();
	static bool getDownActive();

	// Damage
	static int getNeutralDamage();
	static int getSideDamage();
	static int getUpDamage();
	static int getDownDamage();

	// Power
	static float getNeutralPower();
	static float getSidePower();
	static float getUpPower();
	static float getDownPower();

	// AngleD
	static float getNeutralAngleD();
	static float getSideAngleD();
	static float getUpAngleD();
	static float getDownAngleD();

	// Endlag
	static int getNeutralEndlag();
	static int getSideEndlag();
	static int getUpEndlag();
	static int getDownEndlag();

	// Has Hit
	static bool getNeutralHasHit();
	static bool getSideHasHit();
	static bool getUpHasHit();
	static bool getDownHasHit();


private:


};

