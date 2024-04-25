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

	case Character::Soph2:
		maxJumps = Soph2::MAX_JUMPS;
		speed = Soph2::SPEED;
		jumpForce = Soph2::JUMP_FORCE;
		riseDuration = Soph2::RISE_DURATION;
		changeInGravity = Soph2::CHANGE_IN_GRAVITY;
		name = "Soph2";
		break;

	case Character::mrBanana:
		maxJumps = mrBanana::MAX_JUMPS;
		speed = mrBanana::SPEED;
		jumpForce = mrBanana::JUMP_FORCE;
		riseDuration = mrBanana::RISE_DURATION;
		changeInGravity = mrBanana::CHANGE_IN_GRAVITY;
		name = "Mr.Banana";
		break;

	case Character::Vit2:
		maxJumps = Vit2::MAX_JUMPS;
		speed = Vit2::SPEED;
		jumpForce = Vit2::JUMP_FORCE;
		riseDuration = Vit2::RISE_DURATION;
		changeInGravity = Vit2::CHANGE_IN_GRAVITY;
		name = "Vit2";
		break;

	case Character::Liam1:
		maxJumps = Liam1::MAX_JUMPS;
		speed = Liam1::SPEED;
		jumpForce = Liam1::JUMP_FORCE;
		riseDuration = Liam1::RISE_DURATION;
		changeInGravity = Liam1::CHANGE_IN_GRAVITY;
		name = "Liam1";
		break;

	case Character::Liam2:
		maxJumps = Liam2::MAX_JUMPS;
		speed = Liam2::SPEED;
		jumpForce = Liam2::JUMP_FORCE;
		riseDuration = Liam2::RISE_DURATION;
		changeInGravity = Liam2::CHANGE_IN_GRAVITY;
		name = "Liam2";
		break;
	}
}
