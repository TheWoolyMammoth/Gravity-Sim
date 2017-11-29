#include <SFML/Graphics.hpp>
#include "ball.h"

int main()
{
	int radius = 20, windowSize = 800;
	sf::RenderWindow window(sf::VideoMode(windowSize, windowSize), "Gravity Sim");//declaring size of window, and setting the title
	Ball ball(radius);
	ball.setPos({(float) windowSize + 2,(float) windowSize - radius });

	//Gravity variables:
	int groundHeight = windowSize - radius * 2, doesexist = 0;
	float gravity = 0, bounce = 0;
	const float gravityStrength = 0.0004;
	sf::Vector2f movement = { 0,0 }, position = { 0,0 };

	while (window.isOpen())//while the window is open
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type) {

			case sf::Event::Closed:
				window.close();
			}

			//instantiate object
			//movement
			//speed of object?
		}
		if (((sf::Mouse::getPosition(window).x > 0) && (sf::Mouse::getPosition(window).x < window.getSize().x - 10)) && (sf::Mouse::getPosition(window).y > 0 && sf::Mouse::getPosition(window).y < window.getSize().y - 10))//if local mouse pos is in bounds of window dimensions less the radius so it doesn't go over the bounding wall
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))//if mouse has been clicked once and the left mouse button is clicked
			{
				movement.y = 0;
				movement.x = 0;
				position = *(new sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y));
				ball.setPos(position);
			}
		}
			//Gravity System:
			ball.gravity(movement, gravityStrength, gravity, bounce, groundHeight);

			window.clear();
			ball.drawTo(window);
			window.display();//open the window

			ball.move(movement);

		}
	

	return 0;
}