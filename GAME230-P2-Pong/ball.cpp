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
	for (int i = 0; i < 10; i++) {
		this->trails.push_back(sf::Vector2f(this->position.x, this->position.y));
	}

	this->shape.setRadius(this->radius);
	this->shape.setOrigin(this->radius, this->radius);
	this->shape.setOutlineThickness(3);

	//this->trailShape.setOutlineThickness(3);
	//this->trailShape.setOutlineColor(sf::Color(255, 255, 255, 100));
}

void Ball::update()
{
	this->velocity.x = this->speed * cosf(this->angle * 3.14f / 180);
	this->velocity.y = this->speed * sinf(this->angle * 3.14f / 180);
	//std::cout << this->angle << std::endl;
	this->position.x += this->velocity.x * dt.asSeconds();
	this->position.y += this->velocity.y * dt.asSeconds();
	this->checkCollision();

	if (frameCount % 10 == 0) {
		this->trails.erase(this->trails.begin());
		this->trails.push_back(sf::Vector2f(this->position.x, this->position.y));
	}
}

void Ball::draw(sf::RenderWindow& window)
{
	this->shape.setPosition(this->position.x, this->position.y);
	this->shape.setFillColor(this->color);
	this->shape.setOutlineColor(sf::Color::White);
	
	for (int i = 0; i < this->trails.size(); i++) {
		this->trailShape.setRadius(this->radius * i / this->trails.size());
		this->trailShape.setOrigin(this->radius *i / this->trails.size(), this->radius * i / this->trails.size());
		this->trailShape.setPosition(this->trails.at(i));
		this->trailShape.setFillColor(this->color);
		window.draw(this->trailShape);
	}
	window.draw(this->shape);
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
		playSound(3);
		checkGameOver();
		this->angle = this->position.x < WINDOW_WIDTH / 2 ? 180.0f : 0.0f;
		this->position.x = float(WINDOW_WIDTH / 2);
		this->position.y = float(WINDOW_HEIGHT / 2);
		this->speed = 300.0f;
		this->color = sf::Color(255, 255, 255);
		powerups.clear();
		for (int i = 0; i < paddles.size(); i++) {
			paddles.at(i)->reset();
		}
		frameCount = 0;
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
	//powerup
	for (int i = 0; i < powerups.size(); i++) {
		if (this->position.x + this->radius > powerups.at(i)->position.x - powerups.at(i)->width / 2 &&
			this->position.x - this->radius < powerups.at(i)->position.x + powerups.at(i)->width / 2 &&
			this->position.y + this->radius > powerups.at(i)->position.y - powerups.at(i)->height / 2 &&
			this->position.y - this->radius < powerups.at(i)->position.y + powerups.at(i)->height / 2) {
			if (this->color.r == p1OutlineColor.r) {
				paddles.at(0)->upgrade(powerups.at(i)->upType);
			}
			else {
				paddles.at(1)->upgrade(powerups.at(i)->upType);
			}
			playSound(2);
			powerups.erase(powerups.begin()+i);
		}
	}
	//blackhole
	if (this->position.x + this->radius > blackhole->position.x - blackhole->radius / 2 &&
		this->position.x - this->radius < blackhole->position.x + blackhole->radius / 2 &&
		this->position.y + this->radius > blackhole->position.y - blackhole->radius / 2 &&
		this->position.y - this->radius < blackhole->position.y + blackhole->radius / 2) {
		float collideAngle = atan2f(this->position.y - blackhole->position.y, this->position.x - blackhole->position.x) * 180 / 3.14f;
		this->angle += collideAngle * 0.01;
	}
}