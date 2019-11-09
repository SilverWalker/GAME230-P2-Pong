#pragma once
#include <SFML/System.hpp>
#include "Paddle.h"

extern int WINDOW_WIDTH;
extern int WINDOW_HEIGHT;

extern int p1Score;
extern int p2Score;

extern bool isGameOver;
extern int winReqirement;

extern sf::Clock deltaClock;
extern sf::Time dt;

extern std::vector<Paddle*> paddles;

extern void checkGameOver();
extern void resetGame();