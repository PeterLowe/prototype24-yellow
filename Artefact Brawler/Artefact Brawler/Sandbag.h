#pragma once

#include <SFML/Graphics.hpp>
#include "Globals.h"
#include <iostream>

class Sandbag
{
public:
    Sandbag();
    void setup(sf::Vector2f t_pos);

    // "Get" Functions
    sf::RectangleShape getBody() { return body; }
    sf::Sprite getSprite() { return sprite; }

    void gravity();
    void checkBoundries();

    // Knockback
    void knockback(int t_angleD, float& t_power, int t_damage);
    int bounce(float t_angleD);

    // Damage
    void takeDamage(int t_damage);

    bool hitAgain = false;
    bool knockingBack = false;

    // Damage done to sandbag
    int percentage = 0;

private:

    sf::Texture sandbagTexture;
    sf::Sprite sprite;
    sf::RectangleShape body;
    float height = 100;
    float width = 50;

    sf::Vector2f position;

    // Knockback
    float deceleration = 0;
    const float POWER_GRAVITY_MULTIPLIER = 1.5f;
    const float PERCENTAGE_DIVIDER = 10.0f;

    sf::Vector2f direction;


};
