#include "CharacterSelect.h"
#include <iostream>
//LIAM TREACY SOPHIA STANLEY
CharacterSelect::CharacterSelect()
{
	setupSprite();
}

void CharacterSelect::processEvents(sf::Event t_event)
{
}

void CharacterSelect::update(sf::Time t_deltaTime)
{
}

void CharacterSelect::render(sf::RenderWindow& t_event)
{
	t_event.draw(character2Sprite);
	t_event.draw(character1Sprite);
	t_event.draw(character3sprite);
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
}
