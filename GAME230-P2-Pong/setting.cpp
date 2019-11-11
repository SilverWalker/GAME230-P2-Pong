#include "Setting.h"
#include "Paddle.h"

int WINDOW_WIDTH = 1200;
int WINDOW_HEIGHT = 800;

int p1Score = 0;
int p2Score = 0;

bool isGameOver = false;
int winReqirement = 5;

std::vector<Paddle*> paddles;
std::vector<Powerup*> powerups;
Blackhole* blackhole = new Blackhole(float(WINDOW_WIDTH / 2), float(WINDOW_HEIGHT / 2));

sf::Color p1Color(165, 105, 189, 100);
sf::Color p2Color(244, 208, 63, 100);
sf::Color p1OutlineColor(165, 105, 189, 255);
sf::Color p2OutlineColor(244, 208, 63, 255);

sf::Clock deltaClock;
sf::Time dt;
int frameCount = 0;

sf::SoundBuffer bouncePaddleBuffer;
sf::SoundBuffer bounceWallBuffer;
sf::SoundBuffer powerupBuffer;
sf::SoundBuffer failBuffer;
sf::SoundBuffer winBuffer;
sf::Sound sound;;
sf::Sound pupSound;

sf::Font font;

void checkGameOver() {
	if (p1Score >= winReqirement || p2Score >= winReqirement) {
		isGameOver = true;
		playSound(4);
	}
}

void resetGame() {
	p1Score = 0;
	p2Score = 0;
	for (int i = 0; i < paddles.size(); i++) {
		paddles.at(i)->reset();
	}
	powerups.clear();
	frameCount = 0;
	isGameOver = false;
}

void loadAssets() {
	bouncePaddleBuffer.loadFromFile("bouncePaddle.wav");
	bounceWallBuffer.loadFromFile("bounceWall.wav");
	powerupBuffer.loadFromFile("powerup.wav");
	failBuffer.loadFromFile("fail.wav");
	winBuffer.loadFromFile("win.wav");
	font.loadFromFile("JustMyType-KePl.ttf");
}

void playSound(int soundId) {
	switch (soundId) {
	case 0:
		sound.setBuffer(bouncePaddleBuffer);
		sound.play();
		break;
	case 1:
		sound.setBuffer(bounceWallBuffer);
		sound.play();
		break;
	case 2:
		pupSound.setBuffer(powerupBuffer);
		pupSound.play();
		break;
	case 3:
		sound.setBuffer(failBuffer);
		sound.play();
		break;
	case 4:
		sound.setBuffer(winBuffer);
		sound.play();
		break;
	}
}
