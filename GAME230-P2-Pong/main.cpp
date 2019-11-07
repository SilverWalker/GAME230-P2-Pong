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
	Paddle* paddleL = new Paddle(20.0f, float(WINDOW_HEIGHT / 2));
	Paddle* paddleR = new Paddle(float(WINDOW_WIDTH - 20), float(WINDOW_HEIGHT / 2));
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
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			paddleL->moveUp();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		{
			paddleL->moveDown();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			paddleR->moveUp();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			paddleR->moveDown();
		}

		window.clear();
		ball.update();
		paddleL->draw(window);
		paddleR->draw(window);
		ball.draw(window);
		ui.draw(window);
		window.display();
	}

	return 0;
}
