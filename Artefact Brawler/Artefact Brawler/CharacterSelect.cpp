#include "CharacterSelect.h"
#include <iostream>
//LIAM TREACY SOPHIA STANLEY IAN PEREZ BUNUEL VIT PRECHTL
CharacterSelect::CharacterSelect()
{
	// Mouse for the controller
	// Setup mouse hitbox
	mouseHitbox.setFillColor(sf::Color::Blue);
	mouseHitbox.setSize({ 20.0f, 20.0f });
	mouseHitbox.setOrigin({ 10.0f, 10.0f });

	// Setups
	setupSprite();
	setupButton();
	setupFontAndText();
}

void CharacterSelect::processEvents(sf::Event t_event)
{
	if (sf::Event::MouseButtonPressed == t_event.type)
	{
		processMouseDown(t_event);
	}

	if (sf::Event::MouseMoved == t_event.type)
	{
		processMouseMove(t_event);
	}
}

void CharacterSelect::processMouseDown(sf::Event t_event)
{
	// Deactivate controller if the mouse is pressed
	controllerConnected = false;

	if (character1Colliding)
	{
		transitionCircle.transition(character1Button.sendTo);
		
		// Set stats
		PlayerType::currentCharacter = Character::Rose;
		PlayerType::checkCharacter();

		std::cout << "Rose" << std::endl;
	}

	if (character2Colliding)
	{
		transitionCircle.transition(character2Button.sendTo);

		// Set stats
		PlayerType::currentCharacter = Character::mrBanana;
		PlayerType::checkCharacter();

		std::cout << "Mr.Banana" << std::endl;
	}

	if (character3Colliding)
	{
		transitionCircle.transition(character3Button.sendTo);

		// Set stats
		PlayerType::currentCharacter = Character::Liam1;
		PlayerType::checkCharacter();

		std::cout << "Liam1" << std::endl;
	}

	if (character4Colliding)
	{
		transitionCircle.transition(character4Button.sendTo);

		// Set stats
		PlayerType::currentCharacter = Character::Soph2;
		PlayerType::checkCharacter();

		std::cout << "Soph2" << std::endl;
	}

	if (character5Colliding)
	{
		transitionCircle.transition(character5Button.sendTo);

		// Set stats
		PlayerType::currentCharacter = Character::Vit2;
		PlayerType::checkCharacter();

		std::cout << "Vit2" << std::endl;
	}

	if (character6Colliding)
	{
		transitionCircle.transition(character6Button.sendTo);

		// Set stats
		PlayerType::currentCharacter = Character::Liam2;
		PlayerType::checkCharacter();

		std::cout << "Liam2" << std::endl;
	}
}

void CharacterSelect::processMouseMove(sf::Event t_event)
{
	mousePos.x = static_cast<float>(t_event.mouseMove.x);
	mousePos.y = static_cast<float>(t_event.mouseMove.y);
}

void CharacterSelect::processController()
{
	if (controller.currentState.A)
	{
		if (character1Colliding)
		{
			transitionCircle.transition(character1Button.sendTo);

			// Set stats
			PlayerType::currentCharacter = Character::Rose;
			PlayerType::checkCharacter();

			std::cout << "Rose" << std::endl;
		}

		if (character2Colliding)
		{
			transitionCircle.transition(character2Button.sendTo);

			// Set stats
			PlayerType::currentCharacter = Character::mrBanana;
			PlayerType::checkCharacter();

			std::cout << "Mr.Banana" << std::endl;
		}

		if (character3Colliding)
		{
			transitionCircle.transition(character3Button.sendTo);

			// Set stats
			PlayerType::currentCharacter = Character::Liam1;
			PlayerType::checkCharacter();

			std::cout << "Liam1" << std::endl;
		}

		if (character4Colliding)
		{
			transitionCircle.transition(character4Button.sendTo);

			PlayerType::checkCharacter();
		}

		if (character5Colliding)
		{
			transitionCircle.transition(character5Button.sendTo);

			PlayerType::checkCharacter();
		}

		if (character6Colliding)
		{
			transitionCircle.transition(character6Button.sendTo);

			PlayerType::checkCharacter();
		}
	}

	// Move the hitbox for the mouse using the controller
	moveMouseHitbox();
}

void CharacterSelect::update(sf::Time t_deltaTime)
{
	if (controllerConnected)
	{
		controller.update();
		processController();


		// Check if its over a button
		if (mouseHitbox.getGlobalBounds().intersects(character1Button.getBody().getGlobalBounds()))
		{
			character1Colliding = true;
		}
		else
		{
			character1Colliding = false;
		}

		if (mouseHitbox.getGlobalBounds().intersects(character2Button.getBody().getGlobalBounds()))
		{
			character2Colliding = true;
		}
		else
		{
			character2Colliding = false;
		}

		if (mouseHitbox.getGlobalBounds().intersects(character3Button.getBody().getGlobalBounds()))
		{
			character3Colliding = true;
		}
		else
		{
			character3Colliding = false;
		}

		if (mouseHitbox.getGlobalBounds().intersects(character4Button.getBody().getGlobalBounds()))
		{
			character4Colliding = true;
		}
		else
		{
			character4Colliding = false;
		}

		if (mouseHitbox.getGlobalBounds().intersects(character5Button.getBody().getGlobalBounds()))
		{
			character5Colliding = true;
		}
		else
		{
			character5Colliding = false;
		}

		if (mouseHitbox.getGlobalBounds().intersects(character6Button.getBody().getGlobalBounds()))
		{
			character6Colliding = true;
		}
		else
		{
			character6Colliding = false;
		}
	}
	else
	{
		mouseHitboxPosition = mousePos;
		// Check if the controller was connected
		controllerConnected = controller.connectCheck();

		// Mouse checking the buttons
		character1Colliding = character1Button.checkForMouse(mousePos);
		character2Colliding = character2Button.checkForMouse(mousePos);
		character3Colliding = character3Button.checkForMouse(mousePos);
		character4Colliding = character4Button.checkForMouse(mousePos);
		character5Colliding = character5Button.checkForMouse(mousePos);
		character6Colliding = character6Button.checkForMouse(mousePos);
	}

	if (character1Colliding)
	{
		characterStats.setString("Rose\n\nSpeed: " + std::to_string(Rose::SPEED) + "\nJumps: " + std::to_string(Rose::MAX_JUMPS)+ "\nJump Force: " 
		+std::to_string(Rose::JUMP_FORCE)+ "\nJump Length: " + std::to_string(Rose::RISE_DURATION) + "\nFall Speed: "
		+ std::to_string(Rose::CHANGE_IN_GRAVITY));
	}
	if (character2Colliding)
	{
		characterStats.setString("Mr. Banana\n\nSpeed: " + std::to_string(mrBanana::SPEED) + "\nJumps: " + std::to_string(mrBanana::MAX_JUMPS)
		+ "\nJump Force: " + std::to_string(mrBanana::JUMP_FORCE) + "\nJump Length: " + std::to_string(mrBanana::RISE_DURATION) + "\nFall Speed: "
		+ std::to_string(mrBanana::CHANGE_IN_GRAVITY));
	}
	if (character3Colliding)
	{
		characterStats.setString("Liam Character 1\n\nSpeed: " + std::to_string(Liam1::SPEED) + "\nJumps: " + std::to_string(Liam1::MAX_JUMPS)
		+ "\nJump Force: " + std::to_string(Liam1::JUMP_FORCE) + "\nJump Length: " + std::to_string(Liam1::RISE_DURATION) + "\nFall Speed: "
		+ std::to_string(Liam1::CHANGE_IN_GRAVITY));
	}
	if (character4Colliding)
	{
		characterStats.setString("Stargazer\n\nSpeed: " + std::to_string(Soph2::SPEED) + "\nJumps: " + std::to_string(Soph2::MAX_JUMPS)
		+ "\nJump Force: " + std::to_string(Soph2::JUMP_FORCE) + "\nJump Length: " + std::to_string(Soph2::RISE_DURATION) + "\nFall Speed: "
		+ std::to_string(Soph2::CHANGE_IN_GRAVITY));
	}
	if (character5Colliding)
	{
		characterStats.setString("Sandbag Boy\n\nSpeed: " + std::to_string(Vit2::SPEED) + "\nJumps: " + std::to_string(Vit2::MAX_JUMPS)
		+ "\nJump Force: " + std::to_string(Vit2::JUMP_FORCE) + "\nJump Length: " + std::to_string(Vit2::RISE_DURATION) + "\nFall Speed: "
		+ std::to_string(Vit2::CHANGE_IN_GRAVITY));
	}
	if (character6Colliding)
	{
		characterStats.setString("Rabbit Man\n\nSpeed: " + std::to_string(Liam2::SPEED) + "\nJumps: " + std::to_string(Liam2::MAX_JUMPS)
		+ "\nJump Force: " + std::to_string(Liam2::JUMP_FORCE) + "\nJump Length: " + std::to_string(Liam2::RISE_DURATION) + "\nFall Speed: "
		+ std::to_string(Liam2::CHANGE_IN_GRAVITY));
	}

	if (transitionCircle.active)
	{
		transitionCircle.transition(transitionCircle.goTo);
	}
}

void CharacterSelect::render(sf::RenderWindow& t_window)
{
	// Profile Buttons
	t_window.draw(character4Button.getBody());
	t_window.draw(character5Button.getBody());
	t_window.draw(character6Button.getBody());

	t_window.draw(spriteWindow);
	t_window.draw(characterBackgroundSprite);
	// Profile Sprites
	t_window.draw(monkeyProfileSprite);
	t_window.draw(sandbagBoyProfileSprite);
	t_window.draw(roseProfileSprite);
	t_window.draw(stargazerProfileSprite);
	t_window.draw(liam1ProfileSprite);
	t_window.draw(liam2ProfileSprite);

	// character sprites
	if (character1Colliding)
	{
		t_window.draw(character1Sprite);
	}
	if (character2Colliding)
	{
		t_window.draw(character2Sprite);
	}
	if (character3Colliding)
	{
		t_window.draw(character3Sprite); 
	}
	if (character4Colliding)
	{
		t_window.draw(character4Sprite);
	}
	if (character5Colliding)
	{
		t_window.draw(character5Sprite);
	}
	if (character6Colliding)
	{
		t_window.draw(character6sprite);
	}

	t_window.draw(frameSprite); // frame/border/background for character select screen
	t_window.draw(characterStats);


	// Mouse hitbox for controller
	if (controllerConnected)
	{
		t_window.draw(mouseHitbox);
	}

	// screen transition
	if (transitionCircle.active)
	{
		t_window.draw(transitionCircle.getBody());
	}

}


sf::Sprite CharacterSelect::getChar1Body()
{
	return character1Sprite;
}

void CharacterSelect::moveMouseHitbox()
{
	// Up Movement
	if (controller.currentState.LeftThumbStick.y <= -50)
	{
		mouseHitboxPosition.y += -MOUSE_HITBOX_SPEED;
	}
	// Down  Movement
	else if (controller.currentState.LeftThumbStick.y >= 50)
	{
		mouseHitboxPosition.y += MOUSE_HITBOX_SPEED;
	}
	// Left  Movement
	else if (controller.currentState.LeftThumbStick.x <= -50)
	{
		mouseHitboxPosition.x += -MOUSE_HITBOX_SPEED;
	}
	// Right Movement
	else if (controller.currentState.LeftThumbStick.x >= 50)
	{
		mouseHitboxPosition.x += MOUSE_HITBOX_SPEED;
	}

	// Border collision
	if (mouseHitboxPosition.x < 0)
	{
		mouseHitboxPosition.x = 0;
	}
	else if (mouseHitboxPosition.x > SCREEN_WIDTH)
	{
		mouseHitboxPosition.x = SCREEN_WIDTH;
	}
	if (mouseHitboxPosition.y < 0)
	{
		mouseHitboxPosition.y = 0;
	}
	else if (mouseHitboxPosition.y > SCREEN_HEIGHT)
	{
		mouseHitboxPosition.y = SCREEN_HEIGHT;
	}

	mouseHitbox.setPosition(mouseHitboxPosition);
}

void CharacterSelect::setupSprite()
{
	if (!character1Texture.loadFromFile("ASSETS\\IMAGES\\Character2.png"))
	{
		std::cout << "Error loading character 1 sprite" << std::endl;
	}
	character1Sprite.setTexture(character1Texture);
	character1Sprite.setScale(3.0f, 3.0f);
	character1Sprite.setPosition(200.0f, 100.0f);

	if (!character2Texture.loadFromFile("ASSETS\\IMAGES\\MonkeyCharacter.png"))
	{
		std::cout << "Error loading character 2 monkey sprite" << std::endl;
	}
	character2Sprite.setTexture(character2Texture);
	character2Sprite.setScale(3.0f, 3.0f);
	character2Sprite.setPosition(200.0f, 100.0f);

	if (!character3Texture.loadFromFile("ASSETS\\IMAGES\\char1.png"))
	{
		std::cout << "Error loading character 3 sprite" << std::endl;
	}
	character3Sprite.setTexture(character3Texture);
	character3Sprite.setScale(3.0f, 3.0f);
	character3Sprite.setPosition(200.0f, 100.0f);

	if (!character4Texture.loadFromFile("ASSETS\\IMAGES\\Stargazer.png"))
	{
		std::cout << "Error loading character 4 Stargazer sprite" << std::endl;
	}
	character4Sprite.setTexture(character4Texture);
	character4Sprite.setScale(3.0f, 3.0f);
	character4Sprite.setPosition(200.0f, 100.0f);

	if (!character5Texture.loadFromFile("ASSETS\\IMAGES\\Sandbag_Boy.png"))
	{
		std::cout << "Error loading character 5 sandbag boy sprite" << std::endl;
	}
	character5Sprite.setTexture(character5Texture);
	character5Sprite.setScale(3.0f, 3.0f);
	character5Sprite.setPosition(200.0f, 100.0f);

	if (!character6Texture.loadFromFile("ASSETS\\IMAGES\\rabbit_man.png"))
	{
		std::cout << "Error loading character 6 sprite" << std::endl;
	}
	character6sprite.setTexture(character6Texture);
	character6sprite.setScale(3.0f, 3.0f);
	character6sprite.setPosition(200.0f, 100.0f);

	if (!frameTexture.loadFromFile("ASSETS\\IMAGES\\CharacterSelectFrame.png"))
	{
		std::cout << "Error loading frame" << std::endl;
	}
	frameSprite.setTexture(frameTexture);
	frameSprite.setScale(2.0f, 2.0f);

	// Monkey Character Profile
	if (!monkeyProfileTexture.loadFromFile("ASSETS\\IMAGES\\MonkeyCharacterProfile.png"))
	{
		std::cout << "Error loading MonkeyCharacterProfile" << std::endl;
	}
	monkeyProfileSprite.setTexture(monkeyProfileTexture);
	monkeyProfileSprite.setScale(2.6f, 2.2f);
	monkeyProfileSprite.setOrigin(42, 60);
	monkeyProfileSprite.setPosition(character2Pos);

	//Sandbag Boy Profile
	if (!sandbagBoyProfileTexture.loadFromFile("ASSETS\\IMAGES\\SandBagBoyProfile.png"))
	{
		std::cout << "Error loading SandbagBoyProfile" << std::endl;
	}
	sandbagBoyProfileSprite.setTexture(sandbagBoyProfileTexture);
	sandbagBoyProfileSprite.setScale(2.6f, 2.0f);
	sandbagBoyProfileSprite.setOrigin(42, 60);
	sandbagBoyProfileSprite.setPosition(character5Pos);

	// Rose Profile
	if (!stargazerProfileTexture.loadFromFile("ASSETS\\IMAGES\\Stargazer_Portrait.png"))
	{
		std::cout << "Error loading Rose portrait" << std::endl;
	}
	stargazerProfileSprite.setTexture(stargazerProfileTexture);
	stargazerProfileSprite.setScale(2.0f, 2.0f);
	stargazerProfileSprite.setOrigin(50, 42);
	stargazerProfileSprite.setPosition(character4Pos);

	// Stargazer Profile
	if (!roseProfileTexture.loadFromFile("ASSETS\\IMAGES\\RosePortrait.png"))
	{
		std::cout << "Error loading Rose portrait" << std::endl;
	}
	roseProfileSprite.setTexture(roseProfileTexture);
	roseProfileSprite.setScale(2.0f, 2.0f);
	roseProfileSprite.setOrigin(50, 42);
	roseProfileSprite.setPosition(character1Pos);

	// Liam 1 Profile
	if (!liam1ProfileTexture.loadFromFile("ASSETS\\IMAGES\\liamCharSelectIcon.png"))
	{
		std::cout << "Error loading Liam 1 portrait" << std::endl;
	}
	liam1ProfileSprite.setTexture(liam1ProfileTexture);
	liam1ProfileSprite.setScale(2.6f, 1.9f);
	liam1ProfileSprite.setOrigin(42, 50);
	liam1ProfileSprite.setPosition(character3Pos);

	// Rabbit Man Profile
	if (!liam2ProfileTexture.loadFromFile("ASSETS\\IMAGES\\rabbitMan.png"))
	{
		std::cout << "Error loading Liam 2 portrait" << std::endl;
	}
	liam2ProfileSprite.setTexture(liam2ProfileTexture);
	liam2ProfileSprite.setScale(2.6f, 1.9f);
	liam2ProfileSprite.setOrigin(42, 50);
	liam2ProfileSprite.setPosition(character6Pos);

	spriteWindow.setSize({ 360.0f, 306.0f });
	spriteWindow.setFillColor(sf::Color::Red);
	//spriteWindow.setOrigin(180.0f, 153.0f);
	spriteWindow.setPosition(55.0f, 2.0f);

	//Character preview background
	if (!characterBackgroundTexture.loadFromFile("ASSETS\\IMAGES\\MenuBackground.png"))
	{
		std::cout << "Error loading MenuBackground file" << std::endl;
	}
	characterBackgroundSprite.setTexture(characterBackgroundTexture);
}

void CharacterSelect::setupButton()
{
	character1Button.setup(character1Pos, buttonWidth, buttonHeight, Scene::GamePlay, sf::Color::Red);

	character2Button.setup(character2Pos, buttonWidth, buttonHeight, Scene::GamePlay, sf::Color::Blue);

	character3Button.setup(character3Pos, buttonWidth, buttonHeight, Scene::GamePlay, sf::Color::Green);

	character4Button.setup(character4Pos, buttonWidth, buttonHeight, Scene::GamePlay, sf::Color::Yellow);

	character5Button.setup(character5Pos, buttonWidth, buttonHeight, Scene::GamePlay, sf::Color::Magenta);

	character6Button.setup(character6Pos, buttonWidth, buttonHeight, Scene::GamePlay, sf::Color::Cyan);
}

void CharacterSelect::setupFontAndText()
{
	if (!font.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "Error loading font" << std::endl;
	}

	characterStats.setFont(font);
	characterStats.setStyle(sf::Text::Underlined | sf::Text::Italic | sf::Text::Bold);
	characterStats.setCharacterSize(30U);
	characterStats.setOutlineColor(sf::Color::Red);
	characterStats.setFillColor(sf::Color::White);
	characterStats.setOutlineThickness(3.0f);
	characterStats.setPosition(SCREEN_WIDTH / 2.5f, 10);
}
