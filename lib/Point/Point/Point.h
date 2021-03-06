#pragma once

#define DllExport   __declspec( dllexport )
#define DllImport   __declspec( dllimport )

/*
* ������������ ������������� ���� ����� ����� � ��������� � � Y, ������������ ����� 
* �� ��������� ���������. ��� �������� ������� ������ ��� ���������� ����� ��������� 
* � ������������ 0,0.
*/

class DllImport Point
{
private:
	int x; //���������� �
	int y; //���������� Y
public:
	void setX(int x); //���������� �������� ���������� �
	void setY(int y); //���������� �������� ���������� �
	int getX(); //�������� �������� ���������� �
	int getY(); //�������� �������� ���������� �
public:
	Point(int x = 0, int y = 0); //����������� ��� ��������� ������� ����� X=0, Y=0
	~Point();
};