#include <SFML/Graphics.hpp>
#include <iostream>
#include "ball.h"
using std::cin;
using std::cout;
using std::endl;

int buttonPress = 0;
int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "Gravity Sim");//declaring size of window, and setting the title

	while (window.isOpen())//while the window is open
	{
		
		//window.display();//open the window
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			
			if (event.type == sf::Event::Closed)
			{
				window.close();//closing window
			}
			if (((sf::Mouse::getPosition(window).x > 0) && (sf::Mouse::getPosition(window).x < window.getSize().x-10)) && (sf::Mouse::getPosition(window).y > 0 && sf::Mouse::getPosition(window).y < window.getSize().y-10))//if local mouse pos is in bounds of window dimensions less the radius so it doesn't go over the bounding wall
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && buttonPress == 0)//if mouse has been clicked once and the left mouse button is clicked
				{
					Ball sphere(sf::Color::White, 10, *(new sf::Vector2f(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y)));//instantiate sphere
					
					window.draw(sphere);
					window.setVerticalSyncEnabled(true);
					buttonPress++;
				}
				//else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && buttonPress == 1)
				//{
				//this is for moving the object after initial placement
				//buttonPress++;
				//}
				
			}
			//left mouse button is clicked
			//return the position of mouse, draw circle at that pos. 
				//do we want to be able to control the object initial placement? - yes
			//movement
			//vector movement of object
			
			
		}
		window.display();//open the window
	}

	

	return 0;
}