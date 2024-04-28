// IAN PEREZ BUNUEL // LIAM TREACY

#include "SplashScreen.h"
#include<iostream>
#include"Game.h"


SplashScreen::SplashScreen()
{
	setUpSplashScreen();
}

void SplashScreen::processEvents(sf::Event t_event)
{
	if (sf::Event::KeyPressed == t_event.type)
	{
		transitionCircle.transition(Scene::MainMenu);
	}
}

void SplashScreen::update(sf::Time t_deltaTime)
{
	if (transitionCircle.active)
	{
		transitionCircle.transition(Scene::MainMenu);
	}
}

void SplashScreen::render(sf::RenderWindow& t_event)
{
	t_event.draw(m_splashScreenSprite);
	t_event.draw(transitionCircle.getBody());
}

void SplashScreen::setUpSplashScreen()
{
	if (!m_splashScreenTexture.loadFromFile("ASSETS\\IMAGES\\splashScreen.png"))
	{
		std::cout << "error loading the Splash Screen" << std::endl;
	}

	else
	{
		m_splashScreenSprite.setTexture(m_splashScreenTexture);
		m_splashScreenTexture.setRepeated(true);
		m_splashScreenSprite.setTextureRect(sf::IntRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
	}
}
