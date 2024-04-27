// IAN PEREZ BUNUEL VIT PRECHTL

#pragma once
#include <iostream>

/// Character Stats ///

struct Rose // Soph change these stats
{
	// Default values currently 
	static const int MAX_JUMPS = 2;
	static const int SPEED = 7;
	static const int JUMP_FORCE = 10; // How powerful the jump is
	static const int RISE_DURATION = 4; // How long they jump for (in frames)
	static const int CHANGE_IN_GRAVITY = 0;// How much gravity affects them. Bigger the number the faster they fall. Minus numbers the slower they fall (-9 MAX)
};

struct Soph2 // Soph change these stats
{
	// Default values currently 
	static const int MAX_JUMPS = 2;
	static const int SPEED = 5;
	static const int JUMP_FORCE = 13; // How powerful the jump is
	static const int RISE_DURATION = 1; // How long they jump for (in frames)
	static const int CHANGE_IN_GRAVITY = 0;// How much gravity affects them. Bigger the number the faster they fall. Minus numbers the slower they fall (-9 MAX)
};

struct mrBanana // Vit change these stats
{
	// Default values currently 
	static const int MAX_JUMPS = 1;
	static const int SPEED = 6;
	static const int JUMP_FORCE = 24; // How powerful the jump is
	static const int RISE_DURATION = 1; // How long they jump for (in frames)
	static const int CHANGE_IN_GRAVITY = 0;// How much gravity affects them. Bigger the number the faster they fall. Minus numbers the slower they fall (-9 MAX)
};

struct Vit2 // Vit change these stats
{
	// Default values currently 
	static const int MAX_JUMPS = 2;
	static const int SPEED = 5;
	static const int JUMP_FORCE = 13; // How powerful the jump is
	static const int RISE_DURATION = 1; // How long they jump for (in frames)
	static const int CHANGE_IN_GRAVITY = 0;// How much gravity affects them. Bigger the number the faster they fall. Minus numbers the slower they fall (-9 MAX)
};

struct Liam1 // Liam change these stats
{
	// Default values currently 
	static const int MAX_JUMPS = 2;
	static const int SPEED = 5;
	static const int JUMP_FORCE = 13; // How powerful the jump is
	static const int RISE_DURATION = 1; // How long they jump for (in frames)
	static const int CHANGE_IN_GRAVITY = 0;// How much gravity affects them. Bigger the number the faster they fall. Minus numbers the slower they fall (-9 MAX)
};

struct Liam2 // Liam change these stats
{
	// Default values currently 
	static const int MAX_JUMPS = 2;
	static const int SPEED = 5;
	static const int JUMP_FORCE = 13; // How powerful the jump is
	static const int RISE_DURATION = 1; // How long they jump for (in frames)
	static const int CHANGE_IN_GRAVITY = 0;// How much gravity affects them. Bigger the number the faster they fall. Minus numbers the slower they fall (-9 MAX)
};

// Chosen Character
enum class Character
{
	None,
	Rose,
	Soph2,
	mrBanana,
	Vit2,
	Liam1,
	Liam2
};


class PlayerType
{
public:
	PlayerType() { currentCharacter = Character::None; }

	static void checkCharacter();

	// Chosen Character
	static Character currentCharacter;

	// Character Stats. These stats change when you pick a character to the character's stats
	static int maxJumps;
	static int speed;
	static int jumpForce;
	static int riseDuration;
	static int changeInGravity;
	static std::string name;

private:

};

