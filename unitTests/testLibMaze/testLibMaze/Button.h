#pragma once
#include <SFML/Graphics.hpp>
#include "Sound.h"
#include <iostream>

class Button : public Sound
{
private:
	sf::Texture buttonTexture1;
	sf::Sprite buttonSprite;
	sf::Vector2i pixelPosCursor;
	sf::Color color;
	sf::RenderWindow *window;
	bool isActiveSound;
public:
	void draw();
	bool isActive(sf::Event event);
	void setSoundOnClick(std::string pathToSound);
private:
	void setColorOnClick();
	void soundPlay();
public:
	Button(std::string pathToImage, int posX, int posY, sf::RenderWindow *window);
	~Button();
};

