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

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "PONG");
	Ball ball(float(WINDOW_WIDTH / 2), float(WINDOW_HEIGHT / 2));
	Paddle paddleL(20.0f, float(WINDOW_HEIGHT / 2));
	Paddle paddleR(float(WINDOW_WIDTH - 20), float(WINDOW_HEIGHT / 2));

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
			paddleL.moveUp();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		{
			paddleL.moveDown();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			paddleR.moveUp();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			paddleR.moveDown();
		}

		window.clear();
		ball.update();
		ball.draw(window);
		paddleL.draw(window);
		paddleR.draw(window);
		window.display();
	}

	return 0;
}
