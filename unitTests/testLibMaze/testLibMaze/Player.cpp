#include "pch.h"
#include "Player.h" 

Player::Player(int **field, int fieldWidth, int fieldHeight, int x, int y)
{
	this->field = field;
	this->fieldWidth = fieldWidth;
	this->fieldHeight = fieldHeight;
	pos.setX(x);
	pos.setY(y);
	field[y][x] = 2;
}

void Player::controller() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		moveLeft();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		moveRight();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		moveUp();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		moveDown();
	}
}

void Player::moveLeft() {
	if (pos.getX() > 0) {
		if (field[pos.getY()][pos.getX() - 1] == -2) {
			field[pos.getY()][pos.getX()] = -2;
			field[pos.getY()][pos.getX() - 1] = 2;
			pos.setX(pos.getX() - 1);
			cout << "true" << endl;
		}
		else {
			cout << "false" << endl;
		}
	}
}

void Player::moveRight() {
	if (pos.getX() < fieldWidth - 1) {
		if (field[pos.getY()][pos.getX() + 1] == -2) {
			field[pos.getY()][pos.getX()] = -2;
			field[pos.getY()][pos.getX() + 1] = 2;
			pos.setX(pos.getX() + 1);
			cout << "true"<<endl;

		}
		else {
			cout << "false"<<endl;
		}
	}
}

void Player::moveUp() {
	if (pos.getY() > 0) {
		if (field[pos.getY() - 1][pos.getX()] == -2) {
			field[pos.getY()][pos.getX()] = -2;
			field[pos.getY() - 1][pos.getX()] = 2;
			pos.setY(pos.getY() - 1);
			cout << "true" << endl;
		}
		else {
			cout << "false" << endl;
		}
	}
}

void Player::moveDown() {
	if (pos.getY() < fieldHeight - 1) {
		if (field[pos.getY() + 1][pos.getX()] == -2) {
			field[pos.getY()][pos.getX()] = -2;
			field[pos.getY() + 1][pos.getX()] = 2;
			pos.setY(pos.getY() + 1);
			cout << "true" << endl;
		}
		else {
			cout << "false" << endl;
		}
	}
}

Player::~Player()
{
}
