#ifndef B
#define B

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
private:
	sf::CircleShape ball;

};
#endif // !B
