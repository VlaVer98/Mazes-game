#pragma once
#include<cstdlib>
#include<ctime>
#include "Point.h"

#define DllExport   __declspec( dllexport )
#define DllImport   __declspec( dllimport )

/*
* Создает лабиринт при инициализации объекта.
* Лабиринт генерируется без петель или замкнутых цепей и без недостижимых областей.
* Лабиринт будет иметь один вход и 3 выхода, только один выход сгенерируется верным.
* В лабиринте можно найти верный выход с помощью метода drawTruePath 
*/

class DllImport Maze
{
public:
	int **field;        //поле лабиринта, представляет двумерный массив (матрица)
	Point entrance;     //вход в лабринт
	Point exitUp;       //выходы из лабринта:
	Point exitRight;
	Point exitDown;
	Point trueExit;     //правильный выход
private:
	int width;          //ширина лабиринта(матрицы), всегда нечетное
	int height;         //высота лабиринта(матрицы), всегда нечетное
	int wall = -1;      //непроходимая ячейка
	int blank = -2;     //проходимая ячейка
	int *px; int *py;   //координаты ячеек(путь) к выходу
	int len;            //длина пути
public:
	int getHeight();    //получить высоту лабиринта
	int getWidth();     //получить ширину лабиринта
	void drawTruePath();//показать путь
private:
	void create();      //создает лабиринт, генерирует вход и выходы, записывать путь выхода из лабиринта в px, py
	void createInOut(); //создает вход и 3 выхода
	bool findExit(int ax, int ay, int bx, int by); //ищет выход из лабиринта и записывает его путь в px, py
	bool deadend(int x, int y); //определяет конец пути, используется в алгоитме метода findExit
	void changeTrueExit(); //рандомным образова выбирает 1 выход и делает его правильным
public:
	Maze(int width, int height);
	~Maze();
};

