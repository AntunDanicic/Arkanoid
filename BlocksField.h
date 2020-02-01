#pragma once
#include"SFML/Graphics.hpp"
#include "Ball.h"
#include <iostream>
#include <list>
class BlocksField
{
public:
	BlocksField();

	sf::FloatRect GlobalBlockBounds();

	std::list <sf::RectangleShape> blocks;
	void update(Ball& ball, BlocksField& Block);
	void draw(sf::RenderWindow & window);

	float BLTop();
	float BLBottom();
	float BLLeft();
	float BLRight();

	sf::FloatRect BlockBoundBox();


private:
	sf::RectangleShape _Block;

};

