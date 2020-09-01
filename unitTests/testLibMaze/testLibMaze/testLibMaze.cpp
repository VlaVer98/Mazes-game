// testLibMaze.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <SFML/Graphics.hpp>
#include "pch.h"
#include <iostream>
#include "Maze.h"
#include "Player.h"
#include "Button.h"

int main()
{

	
	//тест класса Maze
	setlocale(LC_ALL, "rus");
	Maze maze(15, 15);
	maze.drawTruePath();

	int **field = new int*[5]; //поле лабиринта
	for (int i = 0; i < 5; i++) {
		field[i] = new int[5];
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if(i == 0 || i == 4 || j ==0|| j==4)
				field[i][j] = -1;
			else
				field[i][j] = -2;
		}
	}

	cout << "Тест 5(метод moveRight)" << endl; 
	Player right(field, 5, 5, 2, 2);
	right.moveRight();
	right.moveRight();

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (i == 0 || i == 4 || j == 0 || j == 4)
				field[i][j] = -1;
			else
				field[i][j] = -2;
		}
	}
	cout << "Тест 6(метод moveLeft)" << endl;
	Player left(field, 5, 5, 2, 2);
	left.moveLeft();
	left.moveLeft();

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (i == 0 || i == 4 || j == 0 || j == 4)
				field[i][j] = -1;
			else
				field[i][j] = -2;
		}
	}
	cout << "Тест 7(метод moveUp)" << endl;
	Player up(field, 5, 5, 2, 2);
	up.moveUp();
	up.moveUp();

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (i == 0 || i == 4 || j == 0 || j == 4)
				field[i][j] = -1;
			else
				field[i][j] = -2;
		}
	}
	cout << "Тест 8 (метод moveDown)" << endl;
	Player down(field, 5, 5, 2, 2);
	down.moveDown();
	down.moveDown();

	//тест класса player
	sf::RenderWindow window(sf::VideoMode(800, 600), "Maze", sf::Style::Close);
	window.setKeyRepeatEnabled(false);

	Button button("images/test.png", 10, 10, &window);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (button.isActive(event)) {
				cout << "Кнопка нажата" << endl;
			}
		}
		window.clear();
		button.draw();
		window.display();
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
