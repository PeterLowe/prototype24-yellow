#include "CharacterSelect.h"
#include <iostream>

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
}

void CharacterSelect::setupSprite()
{
	if (!character2Texture.loadFromFile("ASSETS\\IMAGES\\Character2.png"))
	{
		std::cout << "Error loading character 2 sprite" << std::endl;
	}
	character2Sprite.setTexture(character2Texture);
	character2Sprite.setPosition(200.0f, 200.0f);
}
