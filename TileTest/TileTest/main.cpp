#include "SFML/Graphics.hpp"
#include "STP/TMXLoader.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "STP Example");
	tmx::TileMap map("res/mapo.tmx");
	map.ShowObjects(); // Display all the layer objects.
	sf::View view(sf::FloatRect(200.f, 200.f, 300.f, 200.f));
	
										   // Start the game loop
	while (window.isOpen()) 
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event)) 
		{
			// Close window : exit
			if (event.type == sf::Event::Closed)
				window.close();
		}
		// Clear screen
		view.move(1.f, 1.f);
		window.clear();
		window.setView(view);
		// Draw the map
		window.draw(map);
		// Update the window
		window.display();
	}

	return EXIT_SUCCESS;
}