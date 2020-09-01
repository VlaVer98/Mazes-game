#include "StartMenu.h"

void StartMenu::startLoop(Engine &engine) {
	while (engine.getState())
	{
		while (engine.window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				engine.window.close();
		}

		engine.window.clear();

		//engine.window.draw();

		engine.window.display();
	}
}