#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

#include "Setting.h"
#include "Ball.h"
#include "Paddle.h"
#include "Ui.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "PONG");
	Paddle* paddleL = new Paddle(20.0f, float(WINDOW_HEIGHT / 2), false);
	Paddle* paddleR = new Paddle(float(WINDOW_WIDTH - 20), float(WINDOW_HEIGHT / 2), true);
	paddles.push_back(paddleL);
	paddles.push_back(paddleR);
	Ball ball(float(WINDOW_WIDTH / 2), float(WINDOW_HEIGHT / 2));
	Ui ui;

	while (window.isOpen())
	{
		dt = deltaClock.restart();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::EventType::KeyPressed) {
				//switch between player mode and AI mode
				if (event.key.code == sf::Keyboard::G && !isGameOver) {
					paddleL->aiMode = !paddleL->aiMode;
				}

				if (event.key.code == sf::Keyboard::H && !isGameOver) {
					paddleR->aiMode = !paddleR->aiMode;
				}
				//restart game
				if (event.key.code == sf::Keyboard::Space && isGameOver) {
					resetGame();
				}
			}
		}
		//paddle move in player mode
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !paddleL->aiMode && !isGameOver)
		{
			paddleL->moveUp();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && !paddleL->aiMode && !isGameOver)
		{
			paddleL->moveDown();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !paddleR->aiMode && !isGameOver)
		{
			paddleR->moveUp();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !paddleR->aiMode && !isGameOver)
		{
			paddleR->moveDown();
		}
		window.clear();
		if (!isGameOver) {
			ball.update();
			if (paddleL->aiMode) paddleL->aiMove(ball);
			if (paddleR->aiMode) paddleR->aiMove(ball);
			paddleL->draw(window);
			paddleR->draw(window);
			ball.draw(window);
		}
		ui.update();
		ui.draw(window);
		window.display();
	}

	return 0;
}
