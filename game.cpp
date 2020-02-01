#include "game.h"

game::game(Player& _Paddle)
{
	player = new Player();
	blocksfield = new BlocksField();
	ball = new Ball(_Paddle);
}

void game::render(sf::RenderWindow & window)
{
	player->Draw(window);
	blocksfield->draw(window);
	ball->Draw(window);
}

void game::update(float dT,BlocksField& Block, Player& Paddle)
{
	player->Movement(dT);
	ball->CheckCollisionB(Block);
	ball->CheckCollisionP(Paddle);
	ball->CheckCollisionW();
	ball->movement(dT);
}


