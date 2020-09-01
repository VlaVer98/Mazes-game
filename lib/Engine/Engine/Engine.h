#pragma once

#define DllExport   __declspec( dllexport )
#define DllImport   __declspec( dllimport )

/*
* Класс управляет состоянием окна, а именно с помощью изменения свойства stateEngine, 
* осуществляется переход между состояниями: главным меню, о программе, выбор уровня, игра и т.п. 
* Каждому значению свойства stateEngine должно соответствовать определенное состояние, 
* например: stateEngine = 1 - главным меню, stateEngine = 2 - о программе и т.д. 
* Значение 0 у свойства sta-teEngine означает выход.
*
* Движок игры должен в программе использовать следущий ЖЦ:
*
*	while (engine.getState()) {
*		// окно - 1
*		if (engine.getState() == 1) {
*			инициализация переменных, объектов...
			    while (engine.getState()) {
					жизненый цикл состояния окна
				}
*		}
*		// окно - 2
*		else if (engine.getState() == 2) {
*			инициализация переменных, объектов...
			    while (engine.getState()) {
					жизненый цикл состояния окна
				}
*		}
*		......
*/

class DllExport Engine {
private:
	int stateEngine = 1; //состояние окна (0 - закрыть окно)
public:
	int getState();
	void setState(int state);
};