#include "ReflectiveBouncePads.h"
#include "iostream"

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

	ground.setPosition(BPposition + GROUND_DISPLACEMENT);
	ground.setFillColor(sf::Color::White);
	ground.setSize({ width, 10.0f });
	ground.setOrigin({ width / 2.0f, 0.5f });

}
