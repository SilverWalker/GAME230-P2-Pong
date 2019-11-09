#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Ui {
public:
	sf::Font font;
	sf::Text p1ScoreText;
	sf::Text p2ScoreText;
	sf::RectangleShape lineShape;
	sf::Text gameOverText;
	sf::Text restartText;

	Ui();
	void update();
	void draw(sf::RenderWindow& window);
};