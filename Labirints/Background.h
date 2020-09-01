#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

/*
* Класс изменяет задний фон окна. В качестве заднего фона должно использоваться 
* изображение в формате .png. Класс инкапсулирует в себе два класса библиотеки SFML, 
* сделано это для того, чтобы еще больше абстрагироваться и сделать код в программе 
* наиболее понятным и простым.
*/

class Background {
private:
	sf::RenderWindow *window;
	sf::Sprite m_BackgroundSprite; 	// Объявляем спрайт и текстуру для фона
	sf::Texture m_BackgroundTexture;
public:
	void draw(); //рисует кнопку
public:
	Background(string path, sf::RenderWindow *window);
	~Background();
};