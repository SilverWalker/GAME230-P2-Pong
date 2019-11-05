#include<iostream>
#include<cmath>
#include "Setting.h"
#include "Ball.h"

Ball::Ball(float pX, float pY)
{
	this->position.x = pX;
	this->position.y = pY;
	this->speed = 0.3f;
	this->angle = 60;
	this->radius = 10.0f;
}

void Ball::update()
{
	this->velocity.x = this->speed * cosf(this->angle * 3.14f / 180);
	this->velocity.y = this->speed * sinf(this->angle * 3.14f / 180);
	//std::cout << this->angle << std::endl;
	this->position.x += this->velocity.x;
	this->position.y += this->velocity.y;
	this->checkCollision();
}

void Ball::draw(sf::RenderWindow& window)
{
	shape.setRadius(this->radius);
	shape.setOrigin(this->radius, this->radius);
	shape.setPosition(this->position.x, this->position.y);
	shape.setFillColor(sf::Color::White);

	window.draw(shape);
}

void Ball::checkCollision()
{
	//screen
	if (this->position.y - this->radius<0 || this->position.y + this->radius>WINDOW_HEIGHT) {
		this->angle = -this->angle;
	}
	if (this->position.x - this->radius<0 || this->position.x + this->radius>WINDOW_WIDTH) {
		this->angle = 180-this->angle;
	}
}