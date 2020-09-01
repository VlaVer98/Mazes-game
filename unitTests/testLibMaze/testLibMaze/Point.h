#pragma once
class Point
{
private:
	int x; //координата ’
	int y; //координата Y
public:
	void setX(int x); //установить значение координате ’
	void setY(int y); //установить значение координате ’
	int getX(); //получить значение координаты ’
	int getY(); //получить значение координаты ’
public:
	Point(int x = 0, int y = 0); //конструктор без праметров создает точку X=0, Y=0
	~Point();
};
