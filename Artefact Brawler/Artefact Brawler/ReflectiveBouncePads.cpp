#include "ReflectiveBouncePads.h"
#include "iostream"
// LIAM TREACY
ReflectiveBouncePads::ReflectiveBouncePads()
{
}

void ReflectiveBouncePads::setUpBP(sf::Vector2f t_bouncePos)
{
	BPposition = t_bouncePos;
	bouncePad.setPosition(BPposition);
	bouncePad.setFillColor(sf::Color::Red);
	bouncePad.setSize({width, height});
	bouncePad.setOrigin({ width / 2.0f, height / 2.0f });
}
