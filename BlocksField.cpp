#include "BlocksField.h"

BlocksField::BlocksField()
{
	sf::Vector2f size(100.f, 30.f);
	float position = 0.f;
	float space = 103.f;
	for (int i = 0; i < 10; i++)
	{
			_Block.setFillColor(sf::Color::Red);
			_Block.setPosition(sf::Vector2f(position +(space * i), 3.f));
			_Block.setSize(size);
			blocks.push_back(_Block);
	}
	for (int i = 0; i < 10; i++)
	{
		_Block.setFillColor(sf::Color::Red);
		_Block.setPosition(sf::Vector2f(position + (space * i), 36.f));
		_Block.setSize(size);
		blocks.push_back(_Block);
	}
	for (int i = 0; i < 10; i++)
	{
		_Block.setFillColor(sf::Color::Red);
		_Block.setPosition(sf::Vector2f(position + (space * i), 69.f));
		_Block.setSize(size);
		blocks.push_back(_Block);
	}
	for (int i = 0; i < 10; i++)
	{
		_Block.setFillColor(sf::Color::Red);
		_Block.setPosition(sf::Vector2f(position + (space * i), 102.f));
		_Block.setSize(size);
		blocks.push_back(_Block);
	}
	for (int i = 0; i < 10; i++)
	{
		_Block.setFillColor(sf::Color::Red);
		_Block.setPosition(sf::Vector2f(position + (space * i), 135.f));
		_Block.setSize(size);
		blocks.push_back(_Block);
	}
}

sf::FloatRect BlocksField::GlobalBlockBounds()
{
	return _Block.getGlobalBounds();
}

void BlocksField::update(Ball & ball, BlocksField& Block)
{
	/*for (auto& IBlock : blocks)
	{
		blocks.remove_if([&ball, this] {return ball.CheckCollisionB(Block)};);
	}
	*/
}

void BlocksField::draw(sf::RenderWindow& window)
{
	for (auto& Block : blocks)
	{
		window.draw(Block);
	}
}

float BlocksField::BLTop()
{
	return _Block.getPosition().y;
}

float BlocksField::BLBottom()
{
	return _Block.getPosition().y + 30.f;
}

float BlocksField::BLLeft()
{
	return _Block.getPosition().x;
}

float BlocksField::BLRight()
{
	return _Block.getPosition().x + 100.f;
}

sf::FloatRect BlocksField::BlockBoundBox()
{
	return _Block.getGlobalBounds();
}


