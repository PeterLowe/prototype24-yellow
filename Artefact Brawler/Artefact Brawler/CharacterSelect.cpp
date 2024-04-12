#include "CharacterSelect.h"




CharacterSelect::CharacterSelect()
{
	loadCharacters();
}

void CharacterSelect::processEvents(sf::Event t_event)
{
}

void CharacterSelect::update(sf::Time t_deltaTime)
{
}

void CharacterSelect::render(sf::RenderWindow& t_window)
{
	t_window.draw(character1Sprite);
}

void CharacterSelect::loadCharacters()
{
	if (!character1Texture.loadFromFile("ASSETS\\IMAGES\\char1.png"))
	{
		std::cout<<"error loading character 1." << std::endl;
	}
	character1Sprite.setTexture(character1Texture);
	character1Sprite.setPosition(100.0f, 100.0f);
}

sf::Sprite CharacterSelect::getChar1Body()
{
	return character1Sprite;
}
