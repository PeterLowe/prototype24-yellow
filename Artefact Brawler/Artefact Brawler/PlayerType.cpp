// IAN PEREZ BUNUEL

#include "PlayerType.h"

// Definition of static variable outside the class
Character PlayerType::currentCharacter = Character::None;
int PlayerType::maxJumps = 0;
int PlayerType::speed = 0;
int PlayerType::jumpForce = 0;
int PlayerType::riseDuration = 0;
int PlayerType::changeInGravity = 0;
std::string PlayerType::name = "";

void PlayerType::checkCharacter()
{
	switch (currentCharacter)
	{
	case Character::None:
		break;

	case Character::Rose:
		maxJumps = Rose::MAX_JUMPS;
		speed = Rose::SPEED;
		jumpForce = Rose::JUMP_FORCE;
		riseDuration = Rose::RISE_DURATION;
		changeInGravity = Rose::CHANGE_IN_GRAVITY;
		name = "Rose";
		break;

	case Character::mrBanana:
		maxJumps = mrBanana::MAX_JUMPS;
		speed = mrBanana::SPEED;
		jumpForce = mrBanana::JUMP_FORCE;
		riseDuration = mrBanana::RISE_DURATION;
		changeInGravity = mrBanana::CHANGE_IN_GRAVITY;
		name = "Mr.Banana";
		break;

	case Character::Liam1:
		maxJumps = Liam1::MAX_JUMPS;
		speed = Liam1::SPEED;
		jumpForce = Liam1::JUMP_FORCE;
		riseDuration = Liam1::RISE_DURATION;
		changeInGravity = Liam1::CHANGE_IN_GRAVITY;
		name = "Liam1";
		break;
	}
}
