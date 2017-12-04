#ifndef B
#define B

#include "floor and walls.h"
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
	void gravity(sf::Vector2f &movement, float gravityStrength, float gravity, float bounce, int groundHeight) {
		if (this->getY() < groundHeight) {
			movement.y += gravityStrength;
		}
		if (this->getY() >= groundHeight) {
			bounce = -(movement.y - 0.05);
			gravity = 0;
			movement.y = bounce;
		}
		if (this->getY() > (groundHeight)) {
			this->setPos({ (float)this->getX(),(float)groundHeight });
		}
	}
	void collision(sf::Vector2f &movement, float gravityStrength, float bounce, Floor floor, Floor ceiling, Wall wall1, Wall wall2) {
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
			movement.x = movement.x - .00001;
		}
		else if (movement.y == 0 && movement.x < 0) {
			movement.x = movement.x + .00001;
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
