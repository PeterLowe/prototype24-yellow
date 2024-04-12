#include "Sandbag.h"

Sandbag::Sandbag() 
{
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