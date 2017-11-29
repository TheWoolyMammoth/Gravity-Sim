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
private:
	sf::CircleShape ball;

};
#endif // !B
