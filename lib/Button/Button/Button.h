#pragma once
#include <SFML/Graphics.hpp>
#include "Sound.h"
#include <iostream>

#define DllExport   __declspec( dllexport )
#define DllImport   __declspec( dllimport )

/*
* Класс реализует кнопку.
* При инициализации объекта класса, нужно в качестве первого параметра передавать изображение
* в формате .png (это изображение будет телом кнопки), вторым и третьем параметром нужно
* передавать координаты от левого верхнего угла окна, по этим координатам будет нарисована
* кнопка, последний параметр должен принимать ссылку на основной объект класса Window,
* который используется в программе, так будет возможность отрисовать кнопку прямо из функции main
* использую метод draw
*/

class DllImport Button : public Sound
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

