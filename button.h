#ifndef BUTT
#define BUTT


#include <SFML/Graphics.hpp>
#include <vector>
#include "ball.h"
#include "floor and walls.h"

class Button {
public:
	Button(int length, int height) {
		button.setSize({(float) length,(float) height });
	}
	sf::RectangleShape getButton() {
		return button;
	}
	//check to see if the button is pressed
	bool isPressed(sf::RenderWindow &menu) {
		bool press = false;
		if (sf::Mouse::getPosition(menu).x > button.getPosition().x && sf::Mouse::getPosition(menu).x < button.getPosition().x + button.getSize().x && sf::Mouse::getPosition(menu).y > button.getPosition().y && sf::Mouse::getPosition(menu).y < button.getPosition().y + button.getSize().y) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				std::cout << "PRESSED" << std::endl;
				press = true;
			}
		}
		return press;
	}
	virtual void drawTo(sf::RenderWindow &window) {
		window.draw(button);
	}
	virtual void setPos(sf::Vector2f newPos) {
		button.setPosition(newPos);
	}
protected:
	sf::RectangleShape button;
};

class StartButton : public Button {
public:
	StartButton(sf::Color color, int length, int height, std::string text) : Button(length, height) {
		button.setFillColor(color);
		font.loadFromFile("Xpressive Regular.ttf");
		label.setFont(font);
		label.setString("Start");
		label.setCharacterSize(12);
		label.setColor(sf::Color::Black);
	}
	void setPos(sf::Vector2f newPos) {
		Button::setPos(newPos);
		label.setPosition(button.getPosition().x / 4, button.getPosition().y / 2 + 6);
	}
	void drawTo(sf::RenderWindow &window) {
		Button::drawTo(window);
		window.draw(label);
	}
private:
	//text to appear on the button
	sf::Text label;
	sf::Font font;
};

class Slider : public Button {
public:
	Slider(int length = 10, int height = 40) : Button(length, height) {
		button.setFillColor(sf::Color::Black);
		button.setOutlineColor(sf::Color::White);
		button.setOutlineThickness(1);
		track.setSize({ 200,2 });
		track.setFillColor(sf::Color::White);
		track.setOutlineThickness(1);
	}
	void setPos(sf::Vector2f newPos) {
		Button::setPos(newPos);
		track.setPosition({ newPos.x, newPos.y + 19 });
	}
	void drawTo(sf::RenderWindow &window) {
		window.draw(track);
		window.draw(button);
		
	}
	//slider that changes radius of ball
	void slideSize(sf::RenderWindow &window, float *parameter) {
		if (this->isPressed(window) && (button.getPosition().x - track.getPosition().x) < 199) {
			button.setPosition({ (float)sf::Mouse::getPosition(window).x, (float)button.getPosition().y });
			*parameter += ((button.getPosition().x - track.getPosition().x) / 120);
			window.clear();
		}
	}
	//slider that changes gravity strength
	void slideGravity(sf::RenderWindow &window, float *parameter) {
		if (this->isPressed(window) && (button.getPosition().x - track.getPosition().x) < 199) {
			button.setPosition({ (float)sf::Mouse::getPosition(window).x, (float)button.getPosition().y });
			*parameter += ((button.getPosition().x - track.getPosition().x) / 1000000);
			window.clear();
		}
	}
private:
	//track that the slider slides on
	sf::RectangleShape track;
};
#endif // !BUTT