#pragma once

#include <SFML/Graphics.hpp>
#include<iostream>

class CharacterSelect
{
public:

	sf::Sprite character1Sprite;
	sf::Texture character1Texture;

	CharacterSelect();
	void processEvents(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_window);
	void loadCharacters();
	sf::Sprite getChar1Body();


private:

};

