#pragma once
#include <iostream>
#include "Player.h"
#include "BlocksField.h"
#include "Ball.h"

class game
{
public:
	game(Player& _Paddle);

	void render(sf::RenderWindow& window);
	void update(float dT, BlocksField& Block, Player& Paddle);


private:
	Player* player;
	BlocksField* blocksfield;
	Ball* ball;
};

