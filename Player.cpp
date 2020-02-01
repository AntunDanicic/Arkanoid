#include "Player.h"

Player::Player()
{
	_Paddle.setFillColor(sf::Color::Green);
	_Paddle.setPosition(sf::Vector2f(512, 730));
	_Paddle.setSize(sf::Vector2f(100, 15));
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(_Paddle);
}

void Player::Movement(float dT)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && _Paddle.getPosition().x > 0)
	{
		_Paddle.move(-speed * dT, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && _Paddle.getPosition().x + 100 < 1024)
	{
		_Paddle.move(speed * dT, 0.f);
	}
}

void Player::MovementCheck()
{
	while (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		PVelocity = PVelocity - 1.f;
		if (PVelocity > -1.f)
		{
			PVelocity = -1.f;
		}
	}
	while (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		PVelocity = PVelocity + 1.f;
		if (PVelocity > 1.f)
		{
			PVelocity = 1.f;
		}
	}
	if (sf::Keyboard::isKeyPressed == false)
	{
		PVelocity = 0.f;
	}
}

sf::Vector2f Player::PPosition()
{
	return _Paddle.getPosition();
}

float Player::PTop()
{
	return _Paddle.getPosition().y;
}

float Player::PBottom()
{
	return _Paddle.getPosition().y + 15.f;
}

float Player::PLeft()
{
	return _Paddle.getPosition().x;
}

float Player::PRight()
{
	return _Paddle.getPosition().x + 100.f;
}

float Player::PRightMiddle()
{
	return _Paddle.getPosition().x + 66.f;
}

float Player::PLeftMiddle()
{
	return _Paddle.getPosition().x + 33.f;
}

float Player::getPVelocity()
{
	return PVelocity;
}

sf::FloatRect Player::PaddleBoundingBox()
{
	return _Paddle.getGlobalBounds();
}



