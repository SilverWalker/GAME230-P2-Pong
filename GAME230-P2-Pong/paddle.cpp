#include <iostream>
#include <cmath>
#include <vector>
#include "Setting.h"
#include "Ball.h"
#include "Paddle.h"

Paddle::Paddle(float pX, float pY, bool aiMode, sf::Color color, sf::Color outlineColor)
{
	this->position.x = pX;
	this->position.y = pY;
	this->speed = 800.0f;
	this->width = 10;
	this->height = 100;
	this->aiMode = aiMode;
	this->color = color;
	this->outlineColor = outlineColor;
}

void Paddle::update()
{
}

void Paddle::draw(sf::RenderWindow& window)
{
	shape.setSize({ this->width, this->height });
	shape.setOrigin(this->width/2, this->height/2);
	shape.setPosition(this->position.x, this->position.y);
	shape.setFillColor(this->color);
	shape.setOutlineColor(this->outlineColor);
	shape.setOutlineThickness(3);
	window.draw(shape);
}

void Paddle::moveUp()
{
	if (this->position.y - this->height / 2 > 0) {
		this->position.y -= this->speed * dt.asSeconds();
	}
}

void Paddle::moveDown()
{
	if (this->position.y + this->height / 2 < WINDOW_HEIGHT) {
		this->position.y += this->speed * dt.asSeconds();
	}
}

void Paddle::aiMove(Ball targetBall)
{
	if (abs(targetBall.position.x - this->position.x) < WINDOW_WIDTH / 1.5) {
		if (targetBall.position.y < this->position.y - this->height / 4) this->moveUp();
		if (targetBall.position.y > this->position.y + this->height / 4) this->moveDown();
	}
	else {
		this->position.y > WINDOW_HEIGHT / 2 ? this->moveUp() : this->moveDown();
	}
}