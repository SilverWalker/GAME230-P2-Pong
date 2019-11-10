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

extern sf::Color p1Color;
extern sf::Color p2Color;
extern sf::Color p1OutlineColor;
extern sf::Color p2OutlineColor;

extern void checkGameOver();
extern void resetGame();