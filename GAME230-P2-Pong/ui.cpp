#include <iostream>
#include <string>
#include "Setting.h"
#include "Ui.h"

Ui::Ui()
{
	this->font.loadFromFile("JustMyType-KePl.ttf");
	this->p1ScoreText.setFont(this->font);
	this->p1ScoreText.setString(std::to_string(p1Score));
	this->p1ScoreText.setCharacterSize(WINDOW_WIDTH/12);	
	this->p1ScoreText.setFillColor(sf::Color::White);
	sf::FloatRect p1Bounds = this->p1ScoreText.getLocalBounds();
	this->p1ScoreText.setPosition(sf::Vector2f(WINDOW_WIDTH * 0.4 - p1Bounds.width / 2, WINDOW_HEIGHT * 0.05));

	this->p2ScoreText.setFont(this->font);
	this->p2ScoreText.setString(std::to_string(p2Score));
	this->p2ScoreText.setCharacterSize(WINDOW_WIDTH/12);
	this->p2ScoreText.setFillColor(sf::Color::White);
	sf::FloatRect p2Bounds = this->p2ScoreText.getLocalBounds();
	this->p2ScoreText.setPosition(sf::Vector2f(WINDOW_WIDTH * 0.6 - p2Bounds.width / 2, WINDOW_HEIGHT * 0.05));
}

void Ui::update()
{
	this->p1ScoreText.setString(std::to_string(p1Score));
	this->p2ScoreText.setString(std::to_string(p2Score));
}

void Ui::draw(sf::RenderWindow& window)
{
	window.draw(this->p1ScoreText);
	window.draw(this->p2ScoreText);
}