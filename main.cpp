
///////////////////////////////////////////////////////////////////////////////////////
// Programmers: Luke Brossman														 //
//				Joey Warner															 //
//				Derek Montgomery													 //
// Class: Cpts 122																	 //
// Description: This application is used to simuluate gravity. It allows the user to //
// spawn a ball onto the screen, and choose the radius, and gravity that will affect //
// the ball. They can click and drag on the screen to create a motion vector for each//
// ball that is spawned to the screen and launch the ball so that it bounces around. //


#include <SFML/Graphics.hpp>
#include <vector>
#include "button.h"
#include "ball.h"
#include "floorAndWalls.h"

int main()
{

	int radius = 10, windowSize = 800;
	float gravityStrength = 0.000004, radius1 = 5.0; // setting the base gravity acted on by the ball, and the base radius for the ball

	bool MousePressed = false; 
	sf::VertexArray line(sf::LinesStrip, 2); // Declare the line that will be displayed when mouse is clicked

	Ball * testBall = new Ball(radius1); // Test ball to be displayed in the menu
	Floor floor(windowSize, 20), ceiling(windowSize, 20); // setting the size of the floor and ceiling and declaring them
	Wall wall1(20, windowSize), wall2(20, windowSize);// setting the size of walls, and declaring them

	StartButton start(sf::Color::Cyan, 100, 60, "Start"); // Construct the start button
	Slider *ballSize, *gravity; 
	ballSize = new Slider("Radius"); // construct the radius slider
	gravity = new Slider("Gravity"); // construct the gravity slider

	start.setPos({ 50, 400 }); // sets position of start button
	ballSize->setPos({ 50, 150 });// sets the positiion of the radius slider
	gravity->setPos({ 50, 250 }); //set the position of the gravity slider
	floor.setPos({ 0.0, (float)windowSize - 20 }); //set the position for the floor
	ceiling.setPos({ 0.0, 0.0 });
	wall1.setPos({ 0.0,0.0 });
	wall2.setPos({ (float)windowSize - 20, 0 });
	sf::Event event; // Declare an event to keep track of


	sf::RenderWindow menu(sf::VideoMode(600, 600), "Start Menu"); //Render the start menu to the screen
	while (menu.isOpen()) {
		while (menu.pollEvent(event))
		{
			switch (event.type) {

			case sf::Event::Closed:
				menu.close();
			}

			//instantiate object
			//movement
			//speed of object?
		}

		if (start.isPressed(menu)) { //start button launches another window in which the sim takes place
			sf::RenderWindow window(sf::VideoMode(windowSize, windowSize), "Gravity Sim");//declaring size of window, and setting the title
																						  //Gravity variables:
			float gravity = 0, bounce = 0.05;
			sf::Vector2f movement = { 0,.5 }, position = { 0,0 };
			Ball ball(radius1);
			ball.setPos({ (float)windowSize + 2,(float)windowSize - radius1 });
			sf::Event event;


			while (window.isOpen())//while the window is open
			{

				while (window.pollEvent(event))
				{
					switch (event.type) {

					case sf::Event::Closed:
						window.close();
					}
					//left clicking the mouse spawns the ball 
					if (((sf::Mouse::getPosition(window).x > 0) && (sf::Mouse::getPosition(window).x < window.getSize().x - 10)) && (sf::Mouse::getPosition(window).y > 0 && sf::Mouse::getPosition(window).y < window.getSize().y - 10))//if local mouse pos is in bounds of window dimensions less the radius so it doesn't go over the bounding wall
					{
						if (event.type == sf::Event::MouseButtonPressed)
						{
							//if mouse is pressed set movement of ball to 0 and position of the ball to mouse position
							if (!MousePressed && event.MouseLeft) {
								movement.y = 0;
								movement.x = 0;
								position = *(new sf::Vector2f(sf::Mouse::getPosition(window).x - radius1, sf::Mouse::getPosition(window).y - radius1));
								ball.setPos(position);
								MousePressed = true;
								position.x = sf::Mouse::getPosition(window).x;
								position.y = sf::Mouse::getPosition(window).y;
								line[0].position = sf::Vector2f(position);
							}
						}
						if (event.type == sf::Event::MouseButtonReleased)
						{
							//if mouse is released use the x and y magnitude to launch the ball
							if (MousePressed && event.MouseLeft) {
								movement.x = (position.x - (sf::Mouse::getPosition(window).x))*0.005;
								movement.y = (position.y - (sf::Mouse::getPosition(window).y))*0.005;
								MousePressed = false;
							}
						}
					}

				}

				//Gravity System:
				ball.collision(movement, gravityStrength, bounce, floor, ceiling, wall1, wall2);
				line[1].position = sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);

				window.clear();
				ball.drawTo(window);
				floor.drawTo(window);
				ceiling.drawTo(window);
				wall1.drawTo(window);
				wall2.drawTo(window);
				//draws the launch line to visual trajectory and speed
				if (MousePressed) {
					window.draw(line);
				}
				//moves the ball once the mouse is released
				window.display();//open the window
				if (!MousePressed) {
					ball.move(movement);
				}

			}
		}

		/*
		All of the function calls to draw the different objects to the screen, and display what is happening
		*/
		gravity->slideGravity(menu, &gravityStrength);
		ballSize->slideSize(menu, (float*)&radius1);
		testBall = new Ball(radius1);
		testBall->setPos({ (float)450 - radius1, (float)150 - radius1 });
		testBall->drawTo(menu);
		start.drawTo(menu);
		gravity->drawTo(menu);
		ballSize->drawTo(menu);
		menu.display();
		delete testBall;
	}




	return 0;
}