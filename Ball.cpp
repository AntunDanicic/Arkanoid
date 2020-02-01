#include "Ball.h"

Ball::Ball(Player& _Paddle)
{
	_Ball.setRadius(10.f);
	_Ball.setPosition(sf::Vector2f(_Paddle.PPosition().x + 45, _Paddle.PPosition().y));
	_Ball.setFillColor(sf::Color::White);
}

Ball::~Ball()
{
	if (_BallDelete == true)
	{
		delete &_Ball;
	}
}

float Ball::BTop()
{
	return _Ball.getPosition().y;
}

float Ball::BBotom()
{
	return _Ball.getPosition().y + _Ball.getRadius() ;
}

float Ball::BLeft()
{
	return _Ball.getPosition().x;
}

float Ball::BRight()
{
	return _Ball.getPosition().x +_Ball.getRadius();
}

bool Ball::CheckCollisionB(BlocksField& Block)
{
	if (BTop() <= Block.BLBottom() && BBotom() >= Block.BLTop() && _Ball.getGlobalBounds().contains.top(Block.GlobalBlockBounds().contains.height))
	{
		_Velocity.y = +_Velocity.y;
		return true;
	}
	else if (BTop() >= Block.BLBottom() && BBotom() <= Block.BLTop() && _Ball.getGlobalBounds().contains.height(Block.GlobalBlockBounds().contains.top))
	{
		_Velocity.y = -_Velocity.y;
		return true;
	}
	else if (BRight() >= Block.BLLeft() && BLeft() <= Block.BLRight() && _Ball.getGlobalBounds().contains.width(Block.GlobalBlockBounds().contains.left))
	{
		_Velocity.x = -_Velocity.x;
		return true;
	}
	else if (BRight() <= Block.BLLeft() && BLeft() >= Block.BLRight() && _Ball.getGlobalBounds().contains.left(Block.GlobalBlockBounds().contains.width))
	{
		_Velocity.x = +_Velocity.x;
		return true;
	}
	 else return false;
}

bool Ball::CheckCollisionP(Player& Paddle)
{
	if (BTop() >= Paddle.PBottom() && BBotom() <= Paddle.PTop() && _Ball.getGlobalBounds().contains.height(Paddle.PaddleBoundingBox().contains.top))
	{
		if (_shoot(Paddle) == true && Paddle.getPVelocity == 0.f)
		{
			_Velocity.x = -100.f;
			return true;
		}
		if (_shoot(Paddle) == true && Paddle.getPVelocity == 1.f)
		{
			_Velocity.x = _Velocity.x + 50.f;
			return true;
		}
		if (_shoot(Paddle) == true && Paddle.getPVelocity == -1.f)
		{
			_Velocity.x = _Velocity.x - 50.f;
			return true;
		}
		
	}

	return false;
}

bool Ball::CheckCollisionW()
{
	if (_Ball.getPosition().x >= 1014.f)
	{
		_Velocity.x = -_Velocity.x;
		return true;
	}
	if (_Ball.getPosition().x <= 0.f)
	{
		_Velocity.x = +_Velocity.x;
		return true;
	}
	if (_Ball.getPosition().y <= 0.f)
	{
		_Velocity.y = +_Velocity.y;
		return true;
	}
	if (_Ball.getPosition().y >= 758.f)
	{
		_BallDelete = true;
	}
	return false;
}

void Ball::movement(float dT)
{
	_Ball.move(_Velocity * dT);
}

void Ball::Draw(sf::RenderWindow& window)
{
	window.draw(_Ball);
}

sf::FloatRect Ball::_BallBoundBox()
{
	return _Ball.getGlobalBounds();
}

bool Ball::_shoot(Player & Paddle)
{
	if (_Ball.getPosition().x == Paddle.PPosition().x + 45.f && _Ball.getPosition().y == Paddle.PPosition().y 
		&& sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
			return true;
	}
	else return false;
}
void Ball::_setPosition(Player& Paddle)
{
	while (_shoot == false)
	{
		_Ball.setPosition(sf::Vector2f(Paddle.PPosition().x + 45.f, Paddle.PPosition().y));
	}
}


