#pragma once
#include "SFML/Graphics.hpp"
#include "Point.h"
#include <iostream>
using namespace std;

class Player
{
public:
	Point pos; //������� ������ � ���������
private:
	int **field;
	int fieldWidth;  //������ ���������(�������), ������ �������� 
	int fieldHeight; //������ ���������(�������), ������ ��������
public:
	void controller(); //������ �� �������� ������� ���������� (Up, Down, Right, Left) � �������� ������ �� ����������� ������
public:
	void moveLeft(); //���� ������ ������ Left, ������� ������ �� ������� � ����
	void moveRight(); //���� ������ ������ Right, ������� ������ �� ������� � �����
	void moveUp();
	void moveDown();
public:
	Player(int **field, int fieldWidth, int fieldHeight, int x, int y);
	~Player();
};
