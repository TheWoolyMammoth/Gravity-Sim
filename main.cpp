#include <SFML/Graphics.hpp>
#include <vector>
#include "ball.h"
#include "floor and walls.h"

int main()
{
	int radius = 20, windowSize = 800;
	sf::RenderWindow menu(sf::VideoMode(400, 400), "Start Menu");
	
	Ball ball(radius);
	Floor floor(windowSize, radius), ceiling(windowSize, radius);
	Wall wall1(radius, windowSize), wall2(radius, windowSize);

	floor.setPos({ 0.0, (float) windowSize - radius });
	ceiling.setPos({ 0.0, 0.0 });
	wall1.setPos({ 0.0,0.0 });
	wall2.setPos({(float) windowSize - radius, 0 });

	ball.setPos({(float) windowSize + 2,(float) windowSize - radius });

	sf::RenderWindow window(sf::VideoMode(windowSize, windowSize), "Gravity Sim");//declaring size of window, and setting the title
	//Gravity variables:
	int groundHeight = windowSize - radius * 2, doesexist = 0;
	float gravity = 0, bounce = 0.05;
	const float gravityStrength = 0.0006;
	sf::Vector2f movement = { 0,.5 }, position = { 0,0 };

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
				movement.y = -.5;
				movement.x = .3;
				position = *(new sf::Vector2f(sf::Mouse::getPosition(window).x - radius, sf::Mouse::getPosition(window).y - radius));
				ball.setPos(position);
			}
		}
			//Gravity System:
			ball.collision(movement, gravityStrength, bounce, floor, ceiling, wall1, wall2);

			window.clear();
			ball.drawTo(window);
			floor.drawTo(window);
			ceiling.drawTo(window);
			wall1.drawTo(window);
			wall2.drawTo(window);
			window.display();//open the window

			ball.move(movement);

		}
	

	return 0;
}