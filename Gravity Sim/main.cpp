#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "Gravity Sim");
	while (window.isOpen())//while the window is open
	{
		window.display();//open the window
	}
	window.clear();//clear the window
	return 0;
}