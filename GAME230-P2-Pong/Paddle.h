#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Paddle {
public:
	sf::Vector2f position;
	float speed;
	float width;
	float height;
	sf::RectangleShape shape;

	Paddle(float pX, float pY);
	void update();
	void draw(sf::RenderWindow& window);
	void checkCollision();
	void moveUp();
	void moveDown();
};