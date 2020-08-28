#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1080, 720), "63010849 Worawich Tangpojthaweeporn");
	
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Magenta);
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}