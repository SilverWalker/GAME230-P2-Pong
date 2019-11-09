#include "Setting.h"
#include "Paddle.h"

int WINDOW_WIDTH = 1200;
int WINDOW_HEIGHT = 800;

int p1Score = 0;
int p2Score = 0;

bool isGameOver = false;
int winReqirement = 5;

std::vector<Paddle*> paddles;

sf::Clock deltaClock;
sf::Time dt;

void checkGameOver() {
	if (p1Score >= winReqirement || p2Score >= winReqirement) {
		isGameOver = true;
	}
}

void resetGame() {
	p1Score = 0;
	p2Score = 0;
	for (int i = 0; i < paddles.size(); i++) {
		paddles.at(i)->position.y = WINDOW_HEIGHT / 2;
	}
	isGameOver = false;
}
