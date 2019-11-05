#include<iostream>
#include<cmath>
#include "Setting.h"
#include "Paddle.h"

Paddle::Paddle(float pX, float pY)
{
	this->position.x = pX;
	this->position.y = pY;
	this->speed = 0.3f;
	this->width = 10;
	this->height = 100;
}

void Paddle::update()
{
	this->checkCollision();
}

void Paddle::draw(sf::RenderWindow& window)
{
	shape.setSize({ this->width, this->height });
	shape.setOrigin(this->width/2, this->height/2);
	shape.setPosition(this->position.x, this->position.y);
	shape.setFillColor(sf::Color::White);

	window.draw(shape);
}

void Paddle::checkCollision()
{
}

void Paddle::moveUp()
{
	if (this->position.y - this->height / 2 > 0) {
		this->position.y -= this->speed;
	}
}

void Paddle::moveDown()
{
	if (this->position.y + this->height / 2 < WINDOW_HEIGHT) {
		this->position.y += this->speed;
	}
}