#pragma once

#include <SFML/Graphics.hpp>
#include<iostream>

class CharacterSelect // LIAM
{
public:

	CharacterSelect();
	void processEvents(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_window);

	void setupSprite();

	sf::Sprite getChar1Body();

private:

	sf::Sprite character1Sprite;
	sf::Texture character1Texture;
	sf::Sprite character2Sprite;
	sf::Texture character2Texture;
	sf::Sprite character3sprite;
	sf::Texture character3Texture;
};

