#include "SFML/Graphics.hpp"
#include "STP/TMXLoader.hpp"
#include <iostream>
using namespace std;


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SideScroll 1.0");
	tmx::TileMap map("res/mapo.tmx");
	map.ShowObjects(); // Display all the layer objects.
	sf::View view(sf::FloatRect(0.f, 300.f, 800.f, 600.f));
	window.setView(view);
	sf::Clock clock;
	sf::Vector2f centroView;
	while (window.isOpen()) 
	{
		centroView = view.getCenter();
		sf::Time elapsed = clock.restart();
		sf::Event event;
		while (window.pollEvent(event)) 
		{
			
			if (event.type == sf::Event::Closed)
				window.close();
			
			
		}


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if (centroView.x < 1520)
			view.move((200.f)*elapsed.asSeconds(), 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			if(centroView.x > 400)
				view.move((-200.f)*elapsed.asSeconds(), 0.f);
		}

		
		// Clear screen
		window.setView(view);
		window.clear();
		// Draw the map
		window.draw(map);
		// Update the window
		window.display();
	}

	return EXIT_SUCCESS;
}