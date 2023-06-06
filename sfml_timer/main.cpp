#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML WORKS!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	sf::Clock clock;

	while(window.isOpen())
	{
				sf::Event event;
		while(window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(shape);
		sf::Time elapsed = clock.getElapsedTime();
		std::cout << elapsed.asSeconds() << std::endl;
		

		window.display();

	}
}