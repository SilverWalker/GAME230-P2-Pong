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

	Paddle(float pX, float pY, bool aiMode);
	void update();
	void draw(sf::RenderWindow& window);
	void moveUp();
	void moveDown();
	void aiMove(Ball targetBall);
};