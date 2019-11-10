#include <iostream>
#include <cmath>
#include <vector>
#include "Setting.h"
#include "Ball.h"
#include "Paddle.h"

Ball::Ball(float pX, float pY)
{
	this->position.x = pX;
	this->position.y = pY;
	this->speed = 300.0f;
	this->angle = 45;
	this->radius = 10.0f;
	this->color = sf::Color(255, 255, 255);
}

void Ball::update()
{
	this->velocity.x = this->speed * cosf(this->angle * 3.14f / 180);
	this->velocity.y = this->speed * sinf(this->angle * 3.14f / 180);
	//std::cout << this->angle << std::endl;
	this->position.x += this->velocity.x * dt.asSeconds();
	this->position.y += this->velocity.y * dt.asSeconds();
	this->checkCollision();
}

void Ball::draw(sf::RenderWindow& window)
{
	shape.setRadius(this->radius);
	shape.setOrigin(this->radius, this->radius);
	shape.setPosition(this->position.x, this->position.y);
	shape.setFillColor(this->color);
	shape.setOutlineColor(sf::Color::White);
	shape.setOutlineThickness(3);

	window.draw(shape);
}

void Ball::checkCollision()
{
	//screen
	if (this->position.y - this->radius<0 || this->position.y + this->radius>WINDOW_HEIGHT) {
		this->angle = -this->angle;
		this->position.y += this->position.y - this->radius < 0 ? 0.1f : -0.1f;
		playSound(1);
	}
	if (this->position.x + this->radius<0 || this->position.x - this->radius>WINDOW_WIDTH) {
		this->position.x < WINDOW_WIDTH / 2 ? p2Score++ : p1Score++;
		checkGameOver();
		this->angle = this->position.x < WINDOW_WIDTH / 2 ? 180.0f : 0.0f;
		this->position.x = float(WINDOW_WIDTH / 2);
		this->position.y = float(WINDOW_HEIGHT / 2);
		this->speed = 300.0f;
		this->color = sf::Color(255, 255, 255);
	}
	//paddle
	for (int i = 0; i < paddles.size(); i++) {
		if (this->position.x + this->radius > paddles.at(i)->position.x - paddles.at(i)->width / 2 &&
			this->position.x - this->radius < paddles.at(i)->position.x + paddles.at(i)->width / 2 &&
			this->position.y + this->radius > paddles.at(i)->position.y - paddles.at(i)->height / 2 &&
			this->position.y - this->radius < paddles.at(i)->position.y + paddles.at(i)->height / 2) {
			float collideAngle = atan2f(this->position.y - paddles.at(i)->position.y, this->position.x - paddles.at(i)->position.x) * 180 / 3.14f;
			float sideAngle = atan2f(this->radius + paddles.at(i)->height / 2, this->radius + paddles.at(i)->width / 2) * 180 / 3.14f;
			if (!(abs(collideAngle) > sideAngle && abs(collideAngle) < (180.0f - sideAngle))) {
				this->angle = abs(collideAngle) * (this->angle >= 0 ? 1 : -1);
				//if (this->speed < 2000.0f) {
					this->speed += 50.f;
					this->color = paddles.at(i)->outlineColor;
					//std::cout << this->speed << std::endl;
				//}
			}
			else {
				this->angle = -this->angle;
			}
			playSound(0);
		}
	}
}