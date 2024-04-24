#include "CharacterSelect.h"
#include <iostream>
//LIAM TREACY SOPHIA STANLEY
CharacterSelect::CharacterSelect()
{
	setupSprite();
	setupButton();
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

		std::cout << "Character 4" << std::endl;
	}

	if (character5Colliding)
	{
		transitionCircle.transition(character5Button.sendTo);

		PlayerType::checkCharacter();

		std::cout << "Character 5" << std::endl;
	}

	if (character6Colliding)
	{
		transitionCircle.transition(character6Button.sendTo);

		PlayerType::checkCharacter();

		std::cout << "Character 6" << std::endl;
	}
}

void CharacterSelect::processMouseMove(sf::Event t_event)
{
	mousePos.x = static_cast<float>(t_event.mouseMove.x);
	mousePos.y = static_cast<float>(t_event.mouseMove.y);
}

void CharacterSelect::update(sf::Time t_deltaTime)
{
	character1Colliding = character1Button.checkForMouse(mousePos);
	character2Colliding = character2Button.checkForMouse(mousePos);
	character3Colliding = character3Button.checkForMouse(mousePos);
	character4Colliding = character4Button.checkForMouse(mousePos);
	character5Colliding = character5Button.checkForMouse(mousePos);
	character6Colliding = character6Button.checkForMouse(mousePos);

	if (transitionCircle.active)
	{
		transitionCircle.transition(transitionCircle.goTo);
	}
}

void CharacterSelect::render(sf::RenderWindow& t_window)
{
	t_window.draw(character1Button.getBody());
	t_window.draw(character2Button.getBody());
	t_window.draw(character3Button.getBody());
	t_window.draw(character4Button.getBody());
	t_window.draw(character5Button.getBody());
	t_window.draw(character6Button.getBody());

	// character sprites
	t_window.draw(character1Sprite);
	t_window.draw(character2Sprite);
	t_window.draw(character3sprite);

	t_window.draw(frameSprite); // frame/border/background for character select screen

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

void CharacterSelect::setupSprite()
{
	if (!character2Texture.loadFromFile("ASSETS\\IMAGES\\Character2.png"))
	{
		std::cout << "Error loading character 2 sprite" << std::endl;
	}
	character2Sprite.setTexture(character2Texture);
	character2Sprite.setPosition(600.0f, 200.0f);

	if (!character1Texture.loadFromFile("ASSETS\\IMAGES\\char1.png"))
	{
		std::cout << "Error loading character 2 sprite" << std::endl;
	}
	character1Sprite.setTexture(character1Texture);
	character1Sprite.setPosition(500.0f, 200.0f);

	if (!character3Texture.loadFromFile("ASSETS\\IMAGES\\rabbit_man.png"))
	{
		std::cout << "Error loading character 2 sprite" << std::endl;
	}
	character3sprite.setTexture(character3Texture);
	character3sprite.setPosition(300.0f, 200.0f);

	if (!frameTexture.loadFromFile("ASSETS\\IMAGES\\CharacterSelectFrame.png"))
	{
		std::cout << "Error loading frame" << std::endl;
	}
	frameSprite.setTexture(frameTexture);
	frameSprite.setScale(2.0f, 2.0f);
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
