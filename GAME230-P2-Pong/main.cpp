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
	std::vector<Paddle*> paddles;
	Paddle* paddleL = new Paddle(20.0f, float(WINDOW_HEIGHT / 2), true);
	Paddle* paddleR = new Paddle(float(WINDOW_WIDTH - 20), float(WINDOW_HEIGHT / 2), true);
	paddles.push_back(paddleL);
	paddles.push_back(paddleR);
	Ball ball(float(WINDOW_WIDTH / 2), float(WINDOW_HEIGHT / 2), paddles);
	Ui ui;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::EventType::KeyPressed) {
				//switch between player mode and AI mode
				if (event.key.code == sf::Keyboard::G) {
					std::cout << "FK" << std::endl;
					paddleL->aiMode = !paddleL->aiMode;
				}

				if (event.key.code == sf::Keyboard::H) {
					paddleR->aiMode = !paddleR->aiMode;
				}
			}
		}
		//paddle move in player mode
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !paddleL->aiMode)
		{
			paddleL->moveUp();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && !paddleL->aiMode)
		{
			paddleL->moveDown();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !paddleR->aiMode)
		{
			paddleR->moveUp();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !paddleR->aiMode)
		{
			paddleR->moveDown();
		}

		window.clear();
		ball.update();
		if (paddleL->aiMode) paddleL->aiMove(ball);
		if (paddleR->aiMode) paddleR->aiMove(ball);
		paddleL->draw(window);
		paddleR->draw(window);
		ball.draw(window);
		ui.update();
		ui.draw(window);
		window.display();
	}

	return 0;
}
