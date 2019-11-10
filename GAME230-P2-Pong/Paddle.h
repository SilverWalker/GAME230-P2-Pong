#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Ball;

class Paddle {
public:
	sf::Vector2f position;
	float speed;
	float width;
	float height;
	sf::RectangleShape shape;
	bool aiMode;
	sf::Color color;
	sf::Color outlineColor;

	Paddle(float pX, float pY, bool aiMode, sf::Color color, sf::Color outlineColor);
	void update();
	void draw(sf::RenderWindow& window);
	void moveUp();
	void moveDown();
	void aiMove(Ball targetBall);
};