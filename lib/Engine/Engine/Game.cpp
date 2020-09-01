#include "stdafx.h"
#include "Game.h"

Game::Game()
{
}

void Game::setWidthMaze(int width) {
	widthMaze = width;
}

void Game::setHeightMaze(int height) {
	heightMaze = height;
}

int Game::getWidthMaze() {
	return widthMaze;
}

int Game::getHeightMaze() {
	return heightMaze;
}

Game::~Game()
{
}
