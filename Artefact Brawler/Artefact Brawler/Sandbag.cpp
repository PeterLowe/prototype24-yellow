#include "Sandbag.h"

Sandbag::Sandbag() 
{
    if (!sandbagTexture.loadFromFile("ASSETS\\IMAGES\\sandbagStatic.png"))
    {
        std::cout << "problem loading sandbag texture" << std::endl;
    }
    sandbagSprite.setTexture(sandbagTexture);
    sandbagSprite.setOrigin(16, 32);
    sandbagSprite.setScale(1.5, 1.5);
}

void Sandbag::setup(sf::Vector2f t_pos)
{
    position = t_pos;
    body.setPosition(position);

    body.setFillColor(sf::Color::Red);
    body.setSize({ width, height });
    body.setOrigin({ width / 2, height / 2 });

}

void Sandbag::gravity()
{
    position.y += GRAVITY;
    body.setPosition(position);
    sandbagSprite.setPosition(position);
}

void Sandbag::checkBoundries()
{
    // x-axis checking
    if (position.x <= width / 2)
    {
        position.x = width / 2;
    }
    else if (position.x >= SCREEN_WIDTH - width / 2)
    {
        position.x = SCREEN_WIDTH - width / 2;
    }

    // y-axis checking
    if (position.y >= SCREEN_HEIGHT - (height / 2))
    {
        position.y = SCREEN_HEIGHT - (height / 2);
    }
}