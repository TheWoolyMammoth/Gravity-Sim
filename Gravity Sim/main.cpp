#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "Gravity Sim");
	while (window.isOpen())
	{
		window.display();
	}
	return 0;
}