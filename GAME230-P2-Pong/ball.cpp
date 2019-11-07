#include <iostream>
#include <cmath>
#include <vector>
#include "Setting.h"
#include "Ball.h"
#include "Paddle.h"

Ball::Ball(float pX, float pY, std::vector<Paddle*> paddles)
{
	this->position.x = pX;
	this->position.y = pY;
	this->speed = 0.3f;
	this->angle = 0;
	this->radius = 10.0f;
	this->paddles = paddles;
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
	if (this->position.x + this->radius<0 || this->position.x - this->radius>WINDOW_WIDTH) {
		//this->angle = 180 - this->angle;
		this->position.x < WINDOW_WIDTH / 2 ? p2Score++ : p1Score++;
		this->angle = this->position.x < WINDOW_WIDTH / 2 ? 180 : 0;
		this->position.x = float(WINDOW_WIDTH / 2);
		this->position.y = float(WINDOW_HEIGHT / 2);
		this->speed = 0.3f;
	}
	//paddle
	for (int i = 0; i < this->paddles.size(); i++) {
		if (this->position.x + this->radius > this->paddles.at(i)->position.x - this->paddles.at(i)->width / 2 &&
			this->position.x - this->radius < this->paddles.at(i)->position.x + this->paddles.at(i)->width / 2 &&
			this->position.y + this->radius > this->paddles.at(i)->position.y - this->paddles.at(i)->height / 2 &&
			this->position.y - this->radius < this->paddles.at(i)->position.y + this->paddles.at(i)->height / 2) {
			float collideAngle = atan2f(this->position.y - this->paddles.at(i)->position.y, this->position.x - this->paddles.at(i)->position.x) * 180 / 3.14f;
			float sideAngle = atan2f(this->radius + this->paddles.at(i)->height / 2, this->radius + this->paddles.at(i)->width / 2) * 180 / 3.14f;
			if (!(abs(collideAngle) > sideAngle && abs(collideAngle) < (180.0f - sideAngle))) {
				this->angle = abs(collideAngle) * (this->angle >= 0 ? 1 : -1);
				if (this->speed < 1.0f) {
					this->speed += 0.02f;
				}
			}
			else {
				this->angle = -this->angle;
			}
		}
	}
}