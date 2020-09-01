#pragma once
#include "Point.h"

#define DllExport   __declspec( dllexport )
#define DllImport   __declspec( dllimport )

/*
* ����� ��������� ������ ������������ �������� ���� ���������
* ���������� ������ � ������ ������� ���������
*/

class DllExport Game
{
public:
	Point positionMaze;
private:
	int widthMaze;
	int heightMaze;
public:
	void setWidthMaze(int width);
	void setHeightMaze(int height);
	int getWidthMaze();
	int getHeightMaze();
public:
	Game();
	~Game();
};
