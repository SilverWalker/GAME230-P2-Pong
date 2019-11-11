#pragma once
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Paddle.h"
#include "Powerup.h"
#include "Blackhole.h"

extern int WINDOW_WIDTH;
extern int WINDOW_HEIGHT;

extern int p1Score;
extern int p2Score;

extern bool isGameOver;
extern int winReqirement;

extern sf::Clock deltaClock;
extern sf::Time dt;
extern int frameCount;

extern std::vector<Paddle*> paddles;
extern std::vector<Powerup*> powerups;
extern Blackhole* blackhole;

extern sf::Color p1Color;
extern sf::Color p2Color;
extern sf::Color p1OutlineColor;
extern sf::Color p2OutlineColor;

extern sf::SoundBuffer bouncePaddleBuffer;
extern sf::SoundBuffer bounceWallBuffer;
extern sf::Sound sound;

extern sf::Font font;

extern void checkGameOver();
extern void resetGame();
extern void loadAssets();
extern void playSound(int soundId);