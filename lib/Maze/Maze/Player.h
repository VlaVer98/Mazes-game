#pragma once
#include "SFML/Graphics.hpp"
#include "Point.h"

#define DllExport   __declspec( dllexport )
#define DllImport   __declspec( dllimport )

/*
* Конструктор класса принимает ссылку на матрицу лабиринта, ширину и высоту матрицы, а также координаты входа в лабиринт.
* Класс позволяет создать обьект игрок, который может перемещаться по матрице лабиринта.
* Метод controller должен должен вызываться в программе, с условием, что произашло событие - нажатие клавиши клавиатуры
*/

class DllExport Player
{
public:
	Point pos; //позиция игрока в лабиринте
private:
	int **field; 
	int fieldWidth;  //ширина лабиринта(матрицы), всегда нечетное 
	int fieldHeight; //высота лабиринта(матрицы), всегда нечетное
public:
	void controller(); //следит за нажатием клавишь клавиатуры (Up, Down, Right, Left) и вызывает методы по перемещению игрока
private:
	void moveLeft(); //если нажата кнопка Left, смещает игрока по матрицы в лево
	void moveRight(); //если нажата кнопка Right, смещает игрока по матрицы в право
	void moveUp();
	void moveDown();
public:
	Player(int **field, int fieldWidth, int fieldHeight, int x, int y);
	~Player();
};

