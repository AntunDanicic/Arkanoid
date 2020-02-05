#include <SFML/Graphics.hpp>
#include "game.h"
#include "BlocksField.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 768), "Arkanoid");
	window.setVerticalSyncEnabled(true);
	
	BlocksField blocksfield;

	BlocksField* Block;
	Player* Paddle;

	game Game();

	

	sf::Clock clock;
	float dT;

	sf::Event sfEvent;
	while (window.isOpen())
	{
		dT = clock.restart().asSeconds();
		while (window.pollEvent(sfEvent))
		{
			if (sfEvent.type == sf::Event::EventType::Closed)
			{
				window.close();
			}
		}

		Game.update(dT,Block,Paddle);
		

		window.clear();
		blocksfield.draw(window);
		Game.render(window);
		window.display();
	}
}