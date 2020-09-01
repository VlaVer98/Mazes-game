#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

/*
* ����� �������� ������ ��� ����. � �������� ������� ���� ������ �������������� 
* ����������� � ������� .png. ����� ������������� � ���� ��� ������ ���������� SFML, 
* ������� ��� ��� ����, ����� ��� ������ ���������������� � ������� ��� � ��������� 
* �������� �������� � �������.
*/

class Background {
private:
	sf::RenderWindow *window;
	sf::Sprite m_BackgroundSprite; 	// ��������� ������ � �������� ��� ����
	sf::Texture m_BackgroundTexture;
public:
	void draw(); //������ ������
public:
	Background(string path, sf::RenderWindow *window);
	~Background();
};