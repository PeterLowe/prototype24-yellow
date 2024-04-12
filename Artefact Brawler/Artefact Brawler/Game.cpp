/// <summary>
/// @author Peter Lowe
/// @date May 2019
///
/// you need to change the above lines or lose marks
/// </summary>

#include "Game.h"
#include <iostream>


Scene Game::currentMode = Scene::GamePlay;
/// <summary>
/// default constructor
/// setup the window properties
/// load and setup the text 
/// load and setup thne image
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ SCREEN_WIDTH, SCREEN_HEIGHT, 32U }, "SFML Game" },
	m_exitGame{false} //when true game will exit
{
	setupFontAndText(); // load font 
}

/// <summary>
/// default destructor we didn't dynamically allocate anything
/// so we don't need to free it, but mthod needs to be here
/// </summary>
Game::~Game()
{
}


/// <summary>
/// main game loop
/// update 60 times per second,
/// process update as often as possible and at least 60 times per second
/// draw as often as possible but only updates are on time
/// if updates run slow then don't render frames
/// </summary>
void Game::run()
{	
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if ( sf::Event::Closed == newEvent.type) // window message
		{
			m_exitGame = true;
		}
		
		// Check which scene you are in and do the processEvents() of that scene
		switch (currentMode)
		{
		case Scene::None:
			break;

		case Scene::SplashScreen:
			splashScreen.processEvents(newEvent);
			break;

		case Scene::MainMenu:
			mainMenu.processEvents(newEvent);
			break;

		case Scene::Shop:
			shop.processEvents(newEvent);
			break;

		case Scene::CharacterSelect:
			characterSelect.processEvents(newEvent);
			break;

		case Scene::GamePlay:
			gameplay.processEvents(newEvent);
			break;
		}
	}
}


/// <summary>
/// deal with key presses from the user
/// </summary>
/// <param name="t_event">key press event</param>
void Game::processKeys(sf::Event t_event)
{
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		m_exitGame = true;
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}

	// Check which scene you are in and do the update() of that scene
	switch (currentMode)
	{
	case Scene::None:
		break;

	case Scene::SplashScreen:
		splashScreen.update(t_deltaTime);
		break;

	case Scene::MainMenu:
		mainMenu.update(t_deltaTime);
		break;

	case Scene::Shop:
		shop.update(t_deltaTime);
		break;

	case Scene::CharacterSelect:
		characterSelect.update(t_deltaTime);
		break;

	case Scene::GamePlay:
		gameplay.update(t_deltaTime);
		break;
	}
}

/// <summary>
/// draw the frame and then switch buffers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::Black);
	
	// Check which scene you are in and do the render() of that scene
	switch (currentMode)
	{
	case Scene::None:
		break;

	case Scene::SplashScreen:
		splashScreen.render(m_window);
		break;

	case Scene::MainMenu:
		mainMenu.render(m_window);
		break;

	case Scene::Shop:
		shop.render(m_window);
		break;

	case Scene::CharacterSelect:
		characterSelect.render(m_window);
		break;

	case Scene::GamePlay:
		gameplay.render(m_window);
		break;
	}

	m_window.display();
}

/// <summary>
/// load the font and setup the text message for screen
/// </summary>
void Game::setupFontAndText()
{
	if (!m_ArialBlackfont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}
}
