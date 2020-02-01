#pragma once
#include"SFML/Graphics.hpp"
#include "Player.h"
#include "BlocksField.h"
class Ball
{
public:
	Ball(Player& _Paddle);
	~Ball();
	
	float BTop();
	float BBotom();
	float BLeft();
	float BRight();

	bool CheckCollisionB(BlocksField & Block);
	bool CheckCollisionP(Player& Paddle);
	bool CheckCollisionW();

	void movement(float dT);

	void Draw(sf::RenderWindow& window);

private:
	bool _BallDelete = false;
	sf::CircleShape _Ball;
	sf::Vector2f _Velocity;
	sf::FloatRect _BallBoundBox();
	bool _shoot(Player & Paddle);
	void _setPosition(Player & Paddle);
};

