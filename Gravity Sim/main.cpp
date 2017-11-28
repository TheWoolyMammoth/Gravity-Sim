#include <SFML/Graphics.hpp>
#include <iostream>
#include "ball.h"
using std::cin;
using std::cout;
using std::endl;

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "Gravity Sim");//declaring size of window, and setting the title
	Ball sphere(sf::Color::White, 1, *(new sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2)));//instantiate sphere
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
			
			//movement
			//vector movement of object
			//if screen clicked place ball
			//window.draw(sphere);
		}
		
	}

	

	return 0;
}