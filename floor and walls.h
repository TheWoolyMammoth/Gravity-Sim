#ifndef F
#define F

#include <iostream>
#include <SFML\Graphics.hpp>

class Floor {
public:
	Floor(int length, int width) {
		floor.setFillColor(sf::Color::Magenta);
		floor.setSize({ (float) length, (float) width });
	}
	void drawTo(sf::RenderWindow &window) {
		window.draw(floor);
	}
	void setPos(sf::Vector2f newPos) {
		floor.setPosition(newPos);
	}
	sf::RectangleShape getFloor() {
		return floor;
	}
private:
	sf::RectangleShape floor;
};

class Wall {
public:
	Wall(int length, int width) {
		wall.setFillColor(sf::Color::Magenta);
		wall.setSize({(float) length, (float) width });
	}
	void drawTo(sf::RenderWindow &window) {
		window.draw(wall);
	}
	void setPos(sf::Vector2f newPos) {
		wall.setPosition(newPos);
	}
	sf::RectangleShape getWall() {
		return wall;
	}
private:
	sf::RectangleShape wall;
};
#endif // !1