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
    sf::Sprite getSprite() { return sandbagSprite; }

    void gravity();
    void checkBoundries();

private:

    sf::Texture sandbagTexture;
    sf::Sprite sandbagSprite;
    sf::RectangleShape body;
    float height = 100;
    float width = 50;

    sf::Vector2f position;

};
