#pragma once

#include <SFML/Graphics.hpp>

class CharacterSelect // LIAM
{
public:

	void processEvents(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_event);

private:

	sf::Sprite character1Sprite;
	sf::Texture character1Texture;


};

