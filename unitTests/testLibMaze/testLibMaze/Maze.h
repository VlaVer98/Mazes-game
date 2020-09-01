#pragma once
#include<cstdlib>
#include<ctime>
#include <iostream>
#include "Point.h"
using namespace std;

class Maze
{
public:
	int **field;        //���� ���������, ������������ ��������� ������ (�������)
	Point entrance;     //���� � �������
	Point exitUp;       //������ �� ��������:
	Point exitRight;
	Point exitDown;
	Point trueExit;     //���������� �����
private:
	int width;          //������ ���������(�������), ������ ��������
	int height;         //������ ���������(�������), ������ ��������
	int wall = -1;      //������������ ������
	int blank = -2;     //���������� ������
	int *px; int *py;   //���������� �����(����) � ������
	int len;            //����� ����
public:
	int getHeight();    //�������� ������ ���������
	int getWidth();     //�������� ������ ���������
	void drawTruePath();//�������� ����
private:
	void create();      //������� ��������, ���������� ���� � ������, ���������� ���� ������ �� ��������� � px, py
	void createInOut(); //������� ���� � 3 ������
	bool findExit(int ax, int ay, int bx, int by); //���� ����� �� ��������� � ���������� ��� ���� � px, py
	bool deadend(int x, int y); //���������� ����� ����, ������������ � �������� ������ findExit
	void changeTrueExit(); //��������� �������� �������� 1 ����� � ������ ��� ����������
public:
	Maze(int width, int height);
	~Maze();
};

