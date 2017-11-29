#include <SFML/Graphics.hpp>
#include "ball.h"

int main()
{
	int radius = 20, windowSize = 800;
	sf::RenderWindow window(sf::VideoMode(windowSize, windowSize), "Gravity Sim");//declaring size of window, and setting the title
	Ball ball(radius);
	ball.setPos({(float) windowSize/2 - radius,(float) windowSize/2 + radius });

	//Gravity variables:
	int groundHeight = windowSize - radius * 2;
	float gravity = 0, bounce = 0;
	const float gravityStrength = 0.001;
	sf::Vector2f movement = { 0,0 };

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
		//Gravity System:
		if (ball.getY() < groundHeight) {
			movement.y += gravityStrength;
		}
		if (ball.getY() >= groundHeight) {
			bounce = -(movement.y - 0.1);
			gravity = 0;
			movement.y = bounce;
		}
		if (ball.getY() > (groundHeight)) {
			ball.setPos({(float) ball.getX(),(float) groundHeight });
		}
		window.clear();
		ball.drawTo(window);
		window.display();//open the window

		ball.move(movement);

	}

	

	return 0;
}