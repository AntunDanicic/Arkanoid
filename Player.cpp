#include "Player.h"

Player::Player(sf::RenderWindow& window)
{
	_Paddle.setFillColor(sf::Color::Green);
	_Paddle.setPosition(sf::Vector2f(window.getSize().x / 2.f, 730));
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
	while  (IsBothKeyPressed() == true || IsKeyPressed() == false)
	{
		PVelocity = 0.f;
	}
	while (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		PVelocity = -1.f;
	}
	while (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		PVelocity = 1.f;
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

float Player::getPVelocity()
{
	return PVelocity;
}

bool Player::IsKeyPressed()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Player::IsBothKeyPressed()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		return true;
	}
	else return false;
}

sf::FloatRect Player::PaddleBoundingBox()
{
	return _Paddle.getGlobalBounds();
}



