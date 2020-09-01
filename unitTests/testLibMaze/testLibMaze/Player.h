#pragma once
#include "SFML/Graphics.hpp"
#include "Point.h"
#include <iostream>
using namespace std;

class Player
{
public:
	Point pos; //позиция игрока в лабиринте
private:
	int **field;
	int fieldWidth;  //ширина лабиринта(матрицы), всегда нечетное 
	int fieldHeight; //высота лабиринта(матрицы), всегда нечетное
public:
	void controller(); //следит за нажатием клавишь клавиатуры (Up, Down, Right, Left) и вызывает методы по перемещению игрока
public:
	void moveLeft(); //если нажата кнопка Left, смещает игрока по матрицы в лево
	void moveRight(); //если нажата кнопка Right, смещает игрока по матрицы в право
	void moveUp();
	void moveDown();
public:
	Player(int **field, int fieldWidth, int fieldHeight, int x, int y);
	~Player();
};
