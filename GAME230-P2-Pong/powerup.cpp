#include <iostream>
#include <cmath>
#include <vector>
#include "Setting.h"
#include "Ball.h"
#include "Powerup.h"

Powerup::Powerup(float pX, float pY, int upType)
{
	this->position.x = pX;
	this->position.y = pY;
	this->width = 30;
	this->height = 30;
	this->upType = upType;
	this->color = (this->upType == 1) ? sf::Color(0, 0, 255, 100) : sf::Color(255, 0, 0, 100);
	this->outlineColor = (this->upType == 1) ? sf::Color(0, 0, 255, 255) : sf::Color(255, 0, 0, 255);
}

void Powerup::draw(sf::RenderWindow& window)
{
	shape.setSize({ this->width, this->height });
	shape.setOrigin(this->width / 2, this->height / 2);
	shape.setPosition(this->position.x, this->position.y);
	shape.setFillColor(this->color);
	shape.setOutlineColor(this->outlineColor);
	shape.setOutlineThickness(3);
	window.draw(shape);

	sf::Text pupText;
	pupText.setFont(font);
	pupText.setString((this->upType == 1) ? 'L' : 'S');
	pupText.setCharacterSize(30);
	pupText.setFillColor(this->outlineColor);
	sf::FloatRect pupBounds = pupText.getLocalBounds();
	pupText.setPosition(sf::Vector2f(this->position.x, this->position.y));
	pupText.setOrigin(sf::Vector2f(5, this->height/2 + 3));
	window.draw(pupText);
}