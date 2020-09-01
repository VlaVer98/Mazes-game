// Maze.cpp : Определяет экспортированные функции для приложения DLL.
//

#include "stdafx.h"
#include "Maze.h"

Maze::Maze(int width, int height)
{
	this->width = width;
	this->height = height;

	field = new int*[height]; //поле лабиринта

	for (int i = 0; i < height; i++) {
		field[i] = new int[width];
	}

	px = new int[width * height]; py = new int[width * height];

	create();
}

void Maze::create() {

	srand((unsigned)time(NULL));

	int x, y, c, a;
	bool b;

	for (int i = 0; i < height; i++) // Заполняем поле
		for (int j = 0; j < width; j++)
			field[i][j] = wall;

	x = 3; y = 3; a = 0; // Точка начала и счетчик
	while (a < 10000) {
		field[y][x] = blank; a++;
		while (1) { // Бесконечный цикл, который прерывается только тупиком
			c = rand() % 4;
			switch (c) {
			case 0: if (y != 1)
				if (field[y - 2][x] == wall) { // Вверх
					field[y - 1][x] = blank;
					field[y - 2][x] = blank;
					y -= 2;
				}
			case 1: if (y != height - 2)
				if (field[y + 2][x] == wall) { // Вниз
					field[y + 1][x] = blank;
					field[y + 2][x] = blank;
					y += 2;
				}
			case 2: if (x != 1)
				if (field[y][x - 2] == wall) { // Налево
					field[y][x - 1] = blank;
					field[y][x - 2] = blank;
					x -= 2;
				}
			case 3: if (x != width - 2)
				if (field[y][x + 2] == wall) { // Направо
					field[y][x + 1] = blank;
					field[y][x + 2] = blank;
					x += 2;
				}
			}
			if (deadend(x, y))
				break;
		}

		if (deadend(x, y)) // выходим из тупика
			do {
				x = 2 * (rand() % ((width - 1) / 2)) + 1;
				y = 2 * (rand() % ((height - 1) / 2)) + 1;
			} while (field[y][x] != blank);
	}
	createInOut();
	changeTrueExit();
	findExit(entrance.getX(), entrance.getY(), trueExit.getX(), trueExit.getY());
}

bool Maze::deadend(int x, int y) {
	int a = 0;

	if (x != 1) {
		if (field[y][x - 2] == blank)
			a += 1;
	}
	else a += 1;

	if (y != 1) {
		if (field[y - 2][x] == blank)
			a += 1;
	}
	else a += 1;

	if (x != width - 2) {
		if (field[y][x + 2] == blank)
			a += 1;
	}
	else a += 1;

	if (y != height - 2) {
		if (field[y + 2][x] == blank)
			a += 1;
	}
	else a += 1;

	if (a == 4)
		return 1;
	else
		return 0;
}
void Maze::createInOut() {
	//задает вход
	for (int i = ((height - 1) / 2); i < height; i++) {
		if (field[i][0] > field[i][1]) {
			entrance.setX(i);
			break;
		}
	}
	for (int i = ((height - 1) / 2); i > 0; i--) {
		if (field[i][0] > field[i][1]) {
			entrance.setY(i);
			break;
		}
	}
	if ((abs(entrance.getX() - ((height - 1) / 2))) < (abs(entrance.getY() - ((height - 1) / 2)))) {
		field[entrance.getX()][0] = -2;
		entrance.setY(entrance.getX());
		entrance.setX(0);
	}
	else {
		field[entrance.getY()][0] = -2;
		entrance.setX(entrance.getY());
		entrance.setX(0);
	}
	//задает выход справо
	for (int i = ((height - 1) / 2); i < height; i++) {
		if (field[i][width - 1] > field[i][width - 2]) {
			exitRight.setX(i);
			break;
		}
	}
	for (int i = ((height - 1) / 2); i > 0; i--) {
		if (field[i][width - 1] > field[i][width - 2]) {
			exitRight.setY(i);
			break;
		}
	}
	if ((abs(exitRight.getX() - ((height - 1) / 2))) < (abs(exitRight.getY() - ((height - 1) / 2)))) {
		field[exitRight.getX()][width - 1] = -2;
		exitRight.setY(exitRight.getX());
		exitRight.setX(width - 1);
	}
	else {
		field[exitRight.getY()][width - 1] = -2;
		exitRight.setX(exitRight.getY());
		exitRight.setX(width - 1);
	}
	//задает выход сверху
	for (int i = ((width - 1) / 2); i < width; i++) {
		if (field[0][i] > field[1][i]) {
			exitUp.setX(i);
			break;
		}
	}
	for (int i = ((width - 1) / 2); i > 0; i--) {
		if (field[0][i] > field[1][i]) {
			exitUp.setY(i);
			break;
		}
	}
	if ((abs(exitUp.getX() - ((height - 1) / 2))) < (abs(exitUp.getY() - ((height - 1) / 2)))) {
		field[0][exitUp.getX()] = -2;
		exitUp.setY(0);
	}
	else {
		field[0][exitUp.getY()] = -2;
		exitUp.setX(exitUp.getY());
		exitUp.setY(0);
	}
	//задает выход снизу
	for (int i = ((width - 1) / 2); i < width; i++) {
		if (field[height - 1][i] > field[height - 2][i]) {
			exitDown.setX(i);
			break;
		}
	}
	for (int i = ((width - 1) / 2); i > 0; i--) {
		if (field[height - 1][i] > field[height - 2][i]) {
			exitDown.setY(i);
			break;
		}
	}
	if ((abs(exitDown.getX() - ((height - 1) / 2))) < (abs(exitDown.getY() - ((height - 1) / 2)))) {
		field[height - 1][exitDown.getX()] = -2;
		exitDown.setY(height - 1);
	}
	else {
		field[height - 1][exitDown.getY()] = -2;
		exitDown.setX(exitDown.getY());
		exitDown.setY(height - 1);
	}
}

bool Maze::findExit(int ax, int ay, int bx, int by) {

	//копия массива field
	int **fieldCopy = new int*[height]; //поле лабиринта

	for (int i = 0; i < height; i++) {
		fieldCopy[i] = new int[width];
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			fieldCopy[i][j] = field[i][j];
		}
	}

	int dx[4] = { 1, 0, -1, 0 }; // смещения, соответствующие соседям ячейки
	int dy[4] = { 0, 1, 0, -1 }; // справа, снизу, слева и сверху
	int d, x, y, k;
	bool stop;

	if (fieldCopy[ay][ax] == wall || fieldCopy[by][bx] == wall) return false; // ячейка (ax, ay) или (bx, by) - стена

	// распространение волны
	d = 0;
	fieldCopy[ay][ax] = 0; // стартовая ячейка помечена 0
	do {
		stop = true;  // предполагаем, что все свободные клетки уже помечены
		for (y = 0; y < height; ++y)
			for (x = 0; x < width; ++x)
				if (fieldCopy[y][x] == d)  // ячейка (x, y) помечена числом d
				{
					for (k = 0; k < 4; ++k) // проходим по всем непомеченным соседям
					{
						int iy = y + dy[k], ix = x + dx[k];
						if (iy >= 0 && iy < height && ix >= 0 && ix < width &&
							fieldCopy[iy][ix] == blank)
						{
							stop = false; // найдены непомеченные клетки
							fieldCopy[iy][ix] = d + 1; // распространяем волну
						}
					}
				}
		d++;
	} while (!stop && fieldCopy[by][bx] == blank);

	if (fieldCopy[by][bx] == blank) return false; // путь не найден

	// восстановление пути
	len = fieldCopy[by][bx]; // длина кратчайшего пути из (ax, ay) в (bx, by)
	x = bx;
	y = by;
	d = len;
	while (d > 0)
	{
		px[d] = x;
		py[d] = y; // записываем ячейку (x, y) в путь
		d--;
		for (k = 0; k < 4; ++k)
		{
			int iy = y + dy[k], ix = x + dx[k];
			if (iy >= 0 && iy < height && ix >= 0 && ix < width &&
				fieldCopy[iy][ix] == d)
			{
				x = x + dx[k];
				y = y + dy[k]; // переходим в ячейку, которая на 1 ближе к старту
				break;
			}
		}
	}
	px[0] = ax;
	py[0] = ay;  // теперь px[0..len] и py[0..len] - координаты ячеек пути

	for (int i = 0; i < height; i++) {
		delete[] fieldCopy[i];
	}
	delete[] fieldCopy;

	return true;
}

void Maze::changeTrueExit() {
	srand((unsigned)time(NULL));
	int t = rand() % 3;

	if (t == 1) {
		trueExit.setX(exitUp.getX());
		trueExit.setY(exitUp.getY());
	}
	else if (t == 2) {
		trueExit.setX(exitRight.getX());
		trueExit.setY(exitRight.getY());
	}
	else {
		trueExit.setX(exitDown.getX());
		trueExit.setY(exitDown.getY());
	}
}

void Maze::drawTruePath() {
	for (int i = 0; i <= len; i++) {
		field[py[i]][px[i]] = 1;
	}
}

int Maze::getHeight() {
	return height;
}

int Maze::getWidth() {
	return width;
}

Maze::~Maze()
{
	for (int i = 0; i < height; i++) {
		delete[] field[i];
	}
	delete[] field;

	delete[] px;
	delete[] py;
}


