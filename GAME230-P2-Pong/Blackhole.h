#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Blackhole {
public:
	sf::Vector2f position;
	float radius;
	sf::CircleShape shape;

	Blackhole(float pX, float pY);
	void draw(sf::RenderWindow& window);
};