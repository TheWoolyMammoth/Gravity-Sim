#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "Gravity Sim");//declaring size of window, and setting the title

	while (window.isOpen())//while the window is open
	{

		window.display();//open the window

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();//closing window
			}
			//instantiate object
			//movement
			//speed of object?
		}

	}

	

	return 0;
}