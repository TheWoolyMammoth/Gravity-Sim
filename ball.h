#ifndef B
#define B

#include <string>
#include "floorAndWalls.h"
#include <iostream>
#include <SFML\Graphics.hpp>

class Ball {
public:
	Ball(int radius) {
		ball.setRadius(radius);
		ball.setFillColor(sf::Color::Blue);
	}
	void drawTo(sf::RenderWindow &window) {
		window.draw(ball);
	}
	void move(sf::Vector2f distance) {
		ball.move(distance);
	}
	void setPos(sf::Vector2f newPos) {
		ball.setPosition(newPos);
	}
	int getY() {
		return ball.getPosition().y;
	}
	int getX() {
		return ball.getPosition().x;
	}
	sf::CircleShape getBall() {
		return  ball;
	}
	//gravity system checks for collisions with walls and floors
	void collision(sf::Vector2f &movement, float gravityStrength, float bounce, Floor &floor, Floor &ceiling, Wall &wall1, Wall &wall2) {
		if (!ball.getGlobalBounds().intersects(floor.getFloor().getGlobalBounds())) {
			movement.y += gravityStrength;
		}
		if (ball.getGlobalBounds().intersects(floor.getFloor().getGlobalBounds())) {
			if (movement.y > 0.000000001) {
				movement.y = -(movement.y - bounce);
			}
			else {
				movement.y = 0;
			}
		} if (ball.getGlobalBounds().intersects(ceiling.getFloor().getGlobalBounds())) {
			movement.y = -movement.y;
		} if (ball.getGlobalBounds().intersects(wall1.getWall().getGlobalBounds()) || ball.getGlobalBounds().intersects(wall2.getWall().getGlobalBounds())) {
			movement.x = -movement.x;
		}
		if (movement.y == 0 && movement.x > 0) {
			movement.x = movement.x - .0001;
		}
		else if (movement.y == 0 && movement.x < 0) {
			movement.x = movement.x + .0001;
		}
		/*if (this->getY() > floor.getFloor().getOrigin().y - ball.getRadius()*2) {
		ball.setPosition({ ball.getPosition().x, floor.getFloor().getOrigin().y});
		movement.y = 0;
		}*/
	}
private:
	sf::CircleShape ball;
};
#endif // !B
