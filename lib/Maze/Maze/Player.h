#pragma once
#include "SFML/Graphics.hpp"
#include "Point.h"

#define DllExport   __declspec( dllexport )
#define DllImport   __declspec( dllimport )

/*
* ����������� ������ ��������� ������ �� ������� ���������, ������ � ������ �������, � ����� ���������� ����� � ��������.
* ����� ��������� ������� ������ �����, ������� ����� ������������ �� ������� ���������.
* ����� controller ������ ������ ���������� � ���������, � ��������, ��� ��������� ������� - ������� ������� ����������
*/

class DllExport Player
{
public:
	Point pos; //������� ������ � ���������
private:
	int **field; 
	int fieldWidth;  //������ ���������(�������), ������ �������� 
	int fieldHeight; //������ ���������(�������), ������ ��������
public:
	void controller(); //������ �� �������� ������� ���������� (Up, Down, Right, Left) � �������� ������ �� ����������� ������
private:
	void moveLeft(); //���� ������ ������ Left, ������� ������ �� ������� � ����
	void moveRight(); //���� ������ ������ Right, ������� ������ �� ������� � �����
	void moveUp();
	void moveDown();
public:
	Player(int **field, int fieldWidth, int fieldHeight, int x, int y);
	~Player();
};

