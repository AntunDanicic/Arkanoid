#include <SFML/Graphics.hpp>
#include "game.h"
#include "BlocksField.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 768), "Arkanoid");
	window.setVerticalSyncEnabled(true);

	BlocksField blocksfield;

	game game(Player & _Paddle);

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

		game.update(dT,Block,Paddle);

		window.clear();
		blocksfield.draw(window);
		game.render(window);
		window.display();
	}
}