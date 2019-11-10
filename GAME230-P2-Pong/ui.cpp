#include <iostream>
#include <string>
#include "Setting.h"
#include "Ui.h"

Ui::Ui()
{
	this->font.loadFromFile("JustMyType-KePl.ttf");
	this->bgTexture.loadFromFile("bg.png");


	this->bgShape.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
	this->bgShape.setPosition(0, 0);
	this->bgShape.setTexture(&this->bgTexture);

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

	this->lineShape.setSize(sf::Vector2f( 10, WINDOW_HEIGHT / 25 ));
	this->lineShape.setOrigin(5, WINDOW_HEIGHT / 50);
	this->lineShape.setFillColor(sf::Color::White);

	this->gameOverText.setFont(this->font);
	this->gameOverText.setString(p1Score >= p2Score ? "Player 1 Wins!" : "Player 2 Wins!");
	this->gameOverText.setCharacterSize(WINDOW_WIDTH / 12);
	this->gameOverText.setFillColor(sf::Color::White);
	sf::FloatRect gameOverBounds = this->gameOverText.getLocalBounds();
	this->gameOverText.setPosition(sf::Vector2f(WINDOW_WIDTH * 0.5 - gameOverBounds.width / 2, WINDOW_HEIGHT * 0.4));

	this->restartText.setFont(this->font);
	this->restartText.setString("Press spacebar to restart game");
	this->restartText.setCharacterSize(WINDOW_WIDTH / 24);
	this->restartText.setFillColor(sf::Color::White);
	sf::FloatRect restartBounds = this->restartText.getLocalBounds();
	this->restartText.setPosition(sf::Vector2f(WINDOW_WIDTH * 0.5 - restartBounds.width / 2, WINDOW_HEIGHT * 0.55));
}

void Ui::update()
{
	this->p1ScoreText.setString(std::to_string(p1Score));
	this->p2ScoreText.setString(std::to_string(p2Score));
}

void Ui::drawBg(sf::RenderWindow& window)
{
	window.draw(this->bgShape);
}

void Ui::drawLine(sf::RenderWindow& window)
{
	for (int i = 1; i < 25; i += 2) {
		this->lineShape.setPosition(WINDOW_WIDTH / 2, i * WINDOW_HEIGHT / 25 + WINDOW_HEIGHT / 50);
		window.draw(this->lineShape);
	}
}

void Ui::drawScore(sf::RenderWindow& window)
{
	window.draw(this->p1ScoreText);
	window.draw(this->p2ScoreText);
}

void Ui::drawGameOver(sf::RenderWindow& window)
{
	this->gameOverText.setString(p1Score >= p2Score ? "Player 1 Wins!" : "Player 2 Wins!");
	window.draw(this->gameOverText);
	window.draw(this->restartText);
}