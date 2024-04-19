/// <summary>
/// author Ian Perez Bunuel, Liam Treacy, Vit Pretchl, Sophia Stanley
/// you need to change the above line or lose marks
/// </summary>
#ifndef GAME_HPP
#define GAME_HPP
/// <summary>
/// include guards used so we don't process this file twice
/// same as #pragma once
/// Don't forget the endif at the bottom
/// </summary>
#include <SFML/Graphics.hpp>
// Scenes
#include "SplashScreen.h"
#include "MainMenu.h"
#include "Shop.h"
#include "CharacterSelect.h"
#include "GamePlay.h"

enum class Scene
{
	None,
	SplashScreen,
	MainMenu,
	Shop,
	CharacterSelect,
	GamePlay
};


class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

	// Screen Transition
	static Scene currentMode; // static is so that this variable can only be made once

private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();
	
	void setupFontAndText();

	bool m_exitGame; // control exiting game

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message

	// Scenes
	SplashScreen splashScreen;
	MainMenu mainMenu;
	Shop shop;
	CharacterSelect characterSelect;
	GamePlay gameplay;

};

#endif // !GAME_HPP

