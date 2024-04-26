// IAN PEREZ BUNUEL // LIAM TREACY

#pragma once

#include <SFML/Graphics.hpp>
#include"Globals.h"
#include "Controller.h"
#include "ScreenTransition.h"
#include "Scenes.h"

class SplashScreen
{
public:

	SplashScreen();
	void processEvents(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_event);
	void setUpSplashScreen();

private:

	sf::Sprite m_splashScreenSprite;
	sf::Texture m_splashScreenTexture;

	ScreenTransition transitionCircle;

};

