// Engine.cpp : Определяет экспортированные функции для приложения DLL.
//

#include "stdafx.h"
#include "Engine.h"

int Engine::getState() {
	return this->stateEngine;
}

void Engine::setState(int state) {
	this->stateEngine = state;
}

