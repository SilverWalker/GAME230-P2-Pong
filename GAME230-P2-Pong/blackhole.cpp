#include <iostream>
#include <cmath>
#include <vector>
#include "Setting.h"
#include "Ball.h"
#include "Blackhole.h"

Blackhole::Blackhole(float pX, float pY)
{
	this->position.x = pX;
	this->position.y = pY;
	this->radius = 150.0f;
}

void Blackhole::draw(sf::RenderWindow& window)
{
	for (int i = 1; i <= 10; i++) {
		float radius = i * this->radius / 10.0f;
		this->shape.setRadius(radius);
		this->shape.setOrigin(radius, radius);
		this->shape.setPosition(this->position.x, this->position.y);
		this->shape.setFillColor(sf::Color(radius*2, radius * 2, radius * 2, 150-radius));
		window.draw(shape);
	}
}