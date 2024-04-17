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
	void neutralAttack();
	void sideAttack();
	void upAttack();
	void downAttack();


	static AttackType neutral;
	static AttackType side;
	static AttackType up;
	static AttackType down;



private:


};

