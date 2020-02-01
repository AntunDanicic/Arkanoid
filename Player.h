#pragma once
#include "SFML/Graphics.hpp"

class Player
{
public:
	Player();

	void Draw(sf::RenderWindow& window);
	void Movement(float dT);
	void MovementCheck();

	sf::Vector2f PPosition();

	float PTop();
	float PBottom();
	float PLeft();
	float PRight();
	float PLeftMiddle();
	float PRightMiddle();

	float PVelocity = 0.f;
	float getPVelocity();

	sf::FloatRect PaddleBoundingBox();

private:

	sf::RectangleShape _Paddle;
	float speed = 350.f;

};

