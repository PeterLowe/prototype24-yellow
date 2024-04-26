#pragma once
#include <SFML/Graphics.hpp>
#include "Sandbag.h"
class kneeSpecial
{
	public:

		kneeSpecial();

		// "get" function
		sf::RectangleShape getBody() { return hitbox; }

		void spawn(sf::Vector2f t_pos);
		void attack(sf::Vector2f t_pos, Sandbag& t_sandbag, bool& t_canAttack);
		bool active = false;

		// information of attack for sandbag
		int damage = 19; // damage done
		const int END_LAG = 30; // delay before you can attack again#
		float angleD = 270; // 0 is straight up, 45 ->, 180 down, 315 <-
		float power = 3; // how fast it's knocked back
		bool knockingBack = false;

		bool hasHit = false;

	private:
		void setup();
		// hitbox
		sf::RectangleShape hitbox;
		float width = 60.0f;
		float height = 30.0f;
		sf::Vector2f position;
		const sf::Vector2f DISPLACEMENT = { 0.0f, 50.0f };

		// information of attacks
		int timer = 0;
		const int ACTIVE_DURATION = 0.2f * 60; // seconds wanted * framerate

	
};

