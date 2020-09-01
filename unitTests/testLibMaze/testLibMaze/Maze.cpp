#include "pch.h"
#include "Maze.h"


Maze::Maze(int width, int height)
{
	this->width = width;
	this->height = height;

	field = new int*[height]; //���� ���������

	for (int i = 0; i < height; i++) {
		field[i] = new int[width];
	}

	px = new int[width * height]; py = new int[width * height];

	create();
}

void Maze::create() {

	srand((unsigned)time(NULL));

	int x, y, c, a;
	bool b;

	for (int i = 0; i < height; i++) // ��������� ����
		for (int j = 0; j < width; j++)
			field[i][j] = wall;

	x = 3; y = 3; a = 0; // ����� ������ � �������
	while (a < 10000) {
		field[y][x] = blank; a++;
		while (1) { // ����������� ����, ������� ����������� ������ �������
			c = rand() % 4;
			switch (c) {
			case 0: if (y != 1)
				if (field[y - 2][x] == wall) { // �����
					field[y - 1][x] = blank;
					field[y - 2][x] = blank;
					y -= 2;
				}
			case 1: if (y != height - 2)
				if (field[y + 2][x] == wall) { // ����
					field[y + 1][x] = blank;
					field[y + 2][x] = blank;
					y += 2;
				}
			case 2: if (x != 1)
				if (field[y][x - 2] == wall) { // ������
					field[y][x - 1] = blank;
					field[y][x - 2] = blank;
					x -= 2;
				}
			case 3: if (x != width - 2)
				if (field[y][x + 2] == wall) { // �������
					field[y][x + 1] = blank;
					field[y][x + 2] = blank;
					x += 2;
				}
			}
			if (deadend(x, y))
				break;
		}

		if (deadend(x, y)) // ������� �� ������
			do {
				x = 2 * (rand() % ((width - 1) / 2)) + 1;
				y = 2 * (rand() % ((height - 1) / 2)) + 1;
			} while (field[y][x] != blank);
	}


	//unit test 1
	cout << "test 1(����� create):" << endl;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cout << field[i][j] << " ";
		}
		cout << endl;
	}

	createInOut();
	changeTrueExit();
	findExit(entrance.getX(), entrance.getY(), trueExit.getX(), trueExit.getY());
}

bool Maze::deadend(int x, int y) {
	int a = 0;

	if (x != 1) {
		if (field[y][x - 2] == blank)
			a += 1;
	}
	else a += 1;

	if (y != 1) {
		if (field[y - 2][x] == blank)
			a += 1;
	}
	else a += 1;

	if (x != width - 2) {
		if (field[y][x + 2] == blank)
			a += 1;
	}
	else a += 1;

	if (y != height - 2) {
		if (field[y + 2][x] == blank)
			a += 1;
	}
	else a += 1;

	if (a == 4)
		return 1;
	else
		return 0;
}
void Maze::createInOut() {
	//������ ����
	for (int i = ((height - 1) / 2); i < height; i++) {
		if (field[i][0] > field[i][1]) {
			entrance.setX(i);
			break;
		}
	}
	for (int i = ((height - 1) / 2); i > 0; i--) {
		if (field[i][0] > field[i][1]) {
			entrance.setY(i);
			break;
		}
	}
	if ((abs(entrance.getX() - ((height - 1) / 2))) < (abs(entrance.getY() - ((height - 1) / 2)))) {
		field[entrance.getX()][0] = -2;
		entrance.setY(entrance.getX());
		entrance.setX(0);
	}
	else {
		field[entrance.getY()][0] = -2;
		entrance.setX(entrance.getY());
		entrance.setX(0);
	}
	//������ ����� ������
	for (int i = ((height - 1) / 2); i < height; i++) {
		if (field[i][width - 1] > field[i][width - 2]) {
			exitRight.setX(i);
			break;
		}
	}
	for (int i = ((height - 1) / 2); i > 0; i--) {
		if (field[i][width - 1] > field[i][width - 2]) {
			exitRight.setY(i);
			break;
		}
	}
	if ((abs(exitRight.getX() - ((height - 1) / 2))) < (abs(exitRight.getY() - ((height - 1) / 2)))) {
		field[exitRight.getX()][width - 1] = -2;
		exitRight.setY(exitRight.getX());
		exitRight.setX(width - 1);
	}
	else {
		field[exitRight.getY()][width - 1] = -2;
		exitRight.setX(exitRight.getY());
		exitRight.setX(width - 1);
	}
	//������ ����� ������
	for (int i = ((width - 1) / 2); i < width; i++) {
		if (field[0][i] > field[1][i]) {
			exitUp.setX(i);
			break;
		}
	}
	for (int i = ((width - 1) / 2); i > 0; i--) {
		if (field[0][i] > field[1][i]) {
			exitUp.setY(i);
			break;
		}
	}
	if ((abs(exitUp.getX() - ((height - 1) / 2))) < (abs(exitUp.getY() - ((height - 1) / 2)))) {
		field[0][exitUp.getX()] = -2;
		exitUp.setY(0);
	}
	else {
		field[0][exitUp.getY()] = -2;
		exitUp.setX(exitUp.getY());
		exitUp.setY(0);
	}
	//������ ����� �����
	for (int i = ((width - 1) / 2); i < width; i++) {
		if (field[height - 1][i] > field[height - 2][i]) {
			exitDown.setX(i);
			break;
		}
	}
	for (int i = ((width - 1) / 2); i > 0; i--) {
		if (field[height - 1][i] > field[height - 2][i]) {
			exitDown.setY(i);
			break;
		}
	}
	if ((abs(exitDown.getX() - ((height - 1) / 2))) < (abs(exitDown.getY() - ((height - 1) / 2)))) {
		field[height - 1][exitDown.getX()] = -2;
		exitDown.setY(height - 1);
	}
	else {
		field[height - 1][exitDown.getY()] = -2;
		exitDown.setX(exitDown.getY());
		exitDown.setY(height - 1);
	}

	//unit test 2
	cout << "test 2(����� createInOut):" << endl;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cout << field[i][j] << " ";
		}
		cout << endl;
	}
}

bool Maze::findExit(int ax, int ay, int bx, int by) {

	//����� ������� field
	int **fieldCopy = new int*[height]; //���� ���������

	for (int i = 0; i < height; i++) {
		fieldCopy[i] = new int[width];
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			fieldCopy[i][j] = field[i][j];
		}
	}

	int dx[4] = { 1, 0, -1, 0 }; // ��������, ��������������� ������� ������
	int dy[4] = { 0, 1, 0, -1 }; // ������, �����, ����� � ������
	int d, x, y, k;
	bool stop;

	if (fieldCopy[ay][ax] == wall || fieldCopy[by][bx] == wall) return false; // ������ (ax, ay) ��� (bx, by) - �����

	// ��������������� �����
	d = 0;
	fieldCopy[ay][ax] = 0; // ��������� ������ �������� 0
	do {
		stop = true;  // ������������, ��� ��� ��������� ������ ��� ��������
		for (y = 0; y < height; ++y)
			for (x = 0; x < width; ++x)
				if (fieldCopy[y][x] == d)  // ������ (x, y) �������� ������ d
				{
					for (k = 0; k < 4; ++k) // �������� �� ���� ������������ �������
					{
						int iy = y + dy[k], ix = x + dx[k];
						if (iy >= 0 && iy < height && ix >= 0 && ix < width &&
							fieldCopy[iy][ix] == blank)
						{
							stop = false; // ������� ������������ ������
							fieldCopy[iy][ix] = d + 1; // �������������� �����
						}
					}
				}
		d++;
	} while (!stop && fieldCopy[by][bx] == blank);

	if (fieldCopy[by][bx] == blank) return false; // ���� �� ������

	// �������������� ����
	len = fieldCopy[by][bx]; // ����� ����������� ���� �� (ax, ay) � (bx, by)
	x = bx;
	y = by;
	d = len;
	while (d > 0)
	{
		px[d] = x;
		py[d] = y; // ���������� ������ (x, y) � ����
		d--;
		for (k = 0; k < 4; ++k)
		{
			int iy = y + dy[k], ix = x + dx[k];
			if (iy >= 0 && iy < height && ix >= 0 && ix < width &&
				fieldCopy[iy][ix] == d)
			{
				x = x + dx[k];
				y = y + dy[k]; // ��������� � ������, ������� �� 1 ����� � ������
				break;
			}
		}
	}
	px[0] = ax;
	py[0] = ay;  // ������ px[0..len] � py[0..len] - ���������� ����� ����

	for (int i = 0; i < height; i++) {
		delete[] fieldCopy[i];
	}
	delete[] fieldCopy;

	return true;
}

void Maze::changeTrueExit() {
	srand((unsigned)time(NULL));
	int t = rand() % 3;

	if (t == 1) {
		trueExit.setX(exitUp.getX());
		trueExit.setY(exitUp.getY());
	}
	else if (t == 2) {
		trueExit.setX(exitRight.getX());
		trueExit.setY(exitRight.getY());
	}
	else {
		trueExit.setX(exitDown.getX());
		trueExit.setY(exitDown.getY());
	}

	//unit test 3
	cout << "test 3(����� changeTrueExit):" << endl;
	cout <<"x="<<trueExit.getX() <<", y="<< trueExit.getY()<<endl;
}

void Maze::drawTruePath() {
	for (int i = 0; i <= len; i++) {
		field[py[i]][px[i]] = 1;
	}
	//unit test 4
	cout << "test 4(����� drawTruePath):" << endl;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cout << field[i][j] << "\t";
		}
		cout << endl;
	}
}

int Maze::getHeight() {
	return height;
}

int Maze::getWidth() {
	return width;
}

Maze::~Maze()
{
	for (int i = 0; i < height; i++) {
		delete[] field[i];
	}
	delete[] field;

	delete[] px;
	delete[] py;
}