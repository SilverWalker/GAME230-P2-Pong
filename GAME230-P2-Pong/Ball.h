#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Paddle.h"

class Ball {
public:
	sf::Vector2f position;
	sf::Vector2f velocity;
	float speed;
	float angle;
	float radius;
	sf::CircleShape shape;
	std::vector<Paddle*> paddles;

	Ball(float pX, float pY, std::vector<Paddle*> paddles);
	void update();
	void draw(sf::RenderWindow& window);
	void checkCollision();
};