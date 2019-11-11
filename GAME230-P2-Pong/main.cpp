#include <iostream>
#include <stdlib.h> 
#include <time.h> 

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
#include "Powerup.h"
#include "Blackhole.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "PONG");
	loadAssets();
	Paddle* paddleL = new Paddle(20.0f, float(WINDOW_HEIGHT / 2), false, p1Color, p1OutlineColor);
	Paddle* paddleR = new Paddle(float(WINDOW_WIDTH - 20), float(WINDOW_HEIGHT / 2), true, p2Color, p2OutlineColor);
	paddles.push_back(paddleL);
	paddles.push_back(paddleR);
	Ball ball(float(WINDOW_WIDTH / 2), float(WINDOW_HEIGHT / 2));
	Ui ui;
	srand(time(NULL));
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
		ui.drawBg(window);
		if (!isGameOver) {
			frameCount++;
			if (frameCount % 4000 == 0) {
				int x = rand() % WINDOW_WIDTH * 0.5 + WINDOW_WIDTH * 0.25;
				int y = rand() % WINDOW_HEIGHT * 0.65 + WINDOW_HEIGHT * 0.25;
				int type = rand() % 2 + 1;
				powerups.push_back(new Powerup(float(x), float(y), type));
			}
			ball.update();
			if (paddleL->aiMode) paddleL->aiMove(ball);
			if (paddleR->aiMode) paddleR->aiMove(ball);
			paddleL->draw(window);
			paddleR->draw(window);
			blackhole->draw(window);
			ball.draw(window);
			ui.drawLine(window);
			for (int i = 0; i < powerups.size(); i++) {
				powerups.at(i)->draw(window);
			}
		}
		else {
			ui.drawGameOver(window);
		}
		ui.update();
		ui.drawScore(window);
		window.display();
	}

	return 0;
}
