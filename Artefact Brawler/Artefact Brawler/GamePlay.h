#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Sandbag.h"
// Attacks
#include "NeutralAttack.h"

class GamePlay
{
public:

	GamePlay();

	void processEvents(sf::Event t_event);
	void processKeys(sf::Event t_event);

	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_window);

private:

	void setupObjects();

	// Objects
	Player player;
	Sandbag sandbag;
	// Attacks (Objects)
	NeutralAttack neutralAttack;

	// Attack info
	void endLag();
	bool canAttack = true;
	int endLagTimer = 0;
	int endLagDuration; // Set after doing an attack

	// Sandbag Knockback info
	float knockbackAngle = 0.0f;
	float knockbackPower = 0.0f;
	int damageTaken = 0;
};

