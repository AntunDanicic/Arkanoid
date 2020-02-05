#include "Ball.h"

Ball::Ball(Player& Paddle)
{
	_Ball.setRadius(10.f);
	_Ball.setPosition(sf::Vector2f(Paddle.PPosition().x + 45.f, Paddle.PPosition().y));
	_Ball.setFillColor(sf::Color::White);
}

// Brisanje lopte ako ode dolje
Ball::~Ball()
{
	if (_BallDelete == true)
	{
		delete &_Ball;
	}
}

// Koordinate gornje strane lopte
float Ball::BTop()
{
	return _Ball.getPosition().y;
}

// Koordinate donje strane lopte
float Ball::BBotom()
{
	return _Ball.getPosition().y + _Ball.getRadius() ;
}

// Koordinate ljeve strane lopte
float Ball::BLeft()
{
	return _Ball.getPosition().x;
}

// Koordinate desne strane lopte
float Ball::BRight()
{
	return _Ball.getPosition().x +_Ball.getRadius();
}

// Checkanje collisiona izmedju lopte i blokova i setanje velocitija ovisno o bounceu 
bool Ball::CheckCollisionB(BlocksField& Block)
{
	// Gornja strana bloka
	if (BTop() <= Block.BLBottom() && BBotom() >= Block.BLTop() && _Ball.getGlobalBounds().contains.top(Block.GlobalBlockBounds().contains.height))
	{
		_Velocity.y = +_Velocity.y;
		return true;
	}
	// Donja strana bloka
	else if (BTop() >= Block.BLBottom() && BBotom() <= Block.BLTop() && _Ball.getGlobalBounds().contains.height(Block.GlobalBlockBounds().contains.top))
	{
		_Velocity.y = -_Velocity.y;
		return true;
	}
	// Desna strana bloka
	else if (BRight() >= Block.BLLeft() && BLeft() <= Block.BLRight() && _Ball.getGlobalBounds().contains.width(Block.GlobalBlockBounds().contains.left))
	{
		_Velocity.x = -_Velocity.x;
		return true;
	}
	// Ljeva strana bloka
	else if (BRight() <= Block.BLLeft() && BLeft() >= Block.BLRight() && _Ball.getGlobalBounds().contains.left(Block.GlobalBlockBounds().contains.width))
	{
		_Velocity.x = +_Velocity.x;
		return true;
	}
	 else return false;
}

// Checkanje collisiona izmedju lopte i paddlea
bool Ball::CheckCollisionP(Player& Paddle)
{
	if (BTop() >= Paddle.PBottom() && BBotom() <= Paddle.PTop() && _Ball.getGlobalBounds().contains.height(Paddle.PaddleBoundingBox().contains.top))
	{
		// Setanje velocitya.x na 0 jer je paddle stajala kad je lopta udarila
		if (_shoot(Paddle) == true && Paddle.getPVelocity() == 0.f)
		{
			_Velocity.x = 0.f;
			return true;
		}
		// Setanje velocitya.x na +50 jer je paddle isla u desno kad je lopta udarila
		if (_shoot(Paddle) == true && Paddle.getPVelocity() == 1.f)
		{
			_Velocity.x = _Velocity.x + 50.f;
			return true;
		}
		// Setanje velocitya.x na -50 jer je paddle isla u ljevo kad je lopta udarila
		if (_shoot(Paddle) == true && Paddle.getPVelocity() == -1.f)
		{
			_Velocity.x = _Velocity.x - 50.f;
			return true;
		}
		
	}

	return false;
}

// Invertanje velocitya ako lopta udara u zidi itd.
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

// Checkanje dali je lopta na sredini paddela i pucanje lopte sa misom
bool Ball::_shoot(Player & Paddle)
{
	if (_Ball.getPosition().x == Paddle.PPosition().x + 45.f && _Ball.getPosition().y == Paddle.PPosition().y 
		&& sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
			return true;
	}
	else return false;
}

// Setanje pozicije balla na sredinu paddlea
void Ball::_setPosition(Player& Paddle)
{
	while (_shoot(Paddle) == false)
	{
		_Ball.setPosition(sf::Vector2f(Paddle.PPosition().x + 45.f, Paddle.PPosition().y));
	}
}


