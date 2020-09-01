#pragma once

#define DllExport   __declspec( dllexport )
#define DllImport   __declspec( dllimport )

/*
* Представляет упорядоченную пару целых чисел — координат Х и Y, определяющую точку 
* на двумерной плоскости. При создании объекта класса без параметров точка создается 
* с координатами 0,0.
*/

class DllImport Point
{
private:
	int x; //координата Х
	int y; //координата Y
public:
	void setX(int x); //установить значение координате Х
	void setY(int y); //установить значение координате Х
	int getX(); //получить значение координаты Х
	int getY(); //получить значение координаты Х
public:
	Point(int x = 0, int y = 0); //конструктор без праметров создает точку X=0, Y=0
	~Point();
};