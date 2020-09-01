#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup") //отключаем консоль

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Engine.h"
#include "Game.h"
#include "Background.h"
#include "Button.h"
#include "Maze.h"
#include "Player.h"

int main()
{	
	Engine engine;
	Game game;
	sf::RenderWindow window(sf::VideoMode(800, 600), "Maze", sf::Style::Close);
	window.setKeyRepeatEnabled(false);

	while (engine.getState()) {
		// окно - Главное меню
		if (engine.getState() == 1) {
			Background background("images/startMenu.png", &window);
			Button buttonPlay("images/play.png", 10, 380, &window);
			Button buttonAboutProg("images/aboutProgram.png", 10, 500, &window);
			while (engine.getState() == 1)
			{
				sf::Event event;
				while (window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						engine.setState(0);
					if (buttonPlay.isActive(event)) {
						engine.setState(4);
					}
					if (buttonAboutProg.isActive(event)) {
						engine.setState(2);
					}
				}

				window.clear();
				background.draw();
				buttonPlay.draw();
				buttonAboutProg.draw();
				window.display();
			}
		}
		// окно - О программе
		else if (engine.getState() == 2) {
			Background background("images/fonAboutProgram.png", &window);
			Button buttonReference("images/reference.png", 187, 75, &window);
			Button buttonAboutDeveloper("images/aboutDeveloper.png", 173, 225, &window);
			Button buttonReturn("images/return.png", 25, 458, &window);
			while (engine.getState() == 2)
			{
				sf::Event event;
				while (window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						engine.setState(0);
					if (buttonReference.isActive(event)) {
						engine.setState(3);
					}
					if (buttonAboutDeveloper.isActive(event)) {
						engine.setState(7);
					}
					if (buttonReturn.isActive(event)) {
						engine.setState(1);
					}
				}

				window.clear();
				background.draw();
				buttonReference.draw();
				buttonAboutDeveloper.draw();
				buttonReturn.draw();
				window.display();
			}
		}
		//окно справка
		else if (engine.getState() == 3) {
			Background background("images/fonReference.png", &window);
			Button buttonReturn("images/return.png", 25, 458, &window);

			while (engine.getState() == 3)
			{
				sf::Event event;
				while (window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						engine.setState(0);
					if (buttonReturn.isActive(event)) {
						engine.setState(2);
					}
				}

				window.clear();
				background.draw();
				buttonReturn.draw();
				window.display();
			}
		}
		//окно о разработчике
		else if (engine.getState() == 7) {
			Background background("images/fonAboutDeveloper.png", &window);
			Button buttonReturn("images/return.png", 25, 458, &window);

			while (engine.getState() == 7)
			{
				sf::Event event;
				while (window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						engine.setState(0);
					if (buttonReturn.isActive(event)) {
						engine.setState(2);
					}
				}

				window.clear();
				background.draw();
				buttonReturn.draw();
				window.display();
			}
		}
		//окно - как играть
		else if (engine.getState() == 4) {
			Background background("images/fonHowToPlay.png", &window);
			Button buttonOk("images/ok.png", 597, 493, &window);
			while (engine.getState() == 4)
			{
				sf::Event event;
				while (window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						engine.setState(0);
					if (buttonOk.isActive(event)) {
						engine.setState(5);
					}
				}

				window.clear();
				background.draw();
				buttonOk.draw();
				window.display();
			}
		}
		//окно - выбрать уровень
		else if (engine.getState() == 5) {
			Background background("images/fonChooseDifficulty.png", &window);
			Button buttonSmall("images/butSmall.png", 55, 211, &window);
			Button buttonMiddle("images/butMiddle.png", 88, 349, &window);
			Button buttonBig("images/butBig.png", 139, 483, &window);
			while (engine.getState() == 5)
			{
				sf::Event event;
				while (window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						engine.setState(0);
					if (buttonSmall.isActive(event)) {
						game.setWidthMaze(15);
						game.setHeightMaze(15);
						game.positionMaze.setX(250);
						game.positionMaze.setY(130);
						engine.setState(6);
					}
					if (buttonMiddle.isActive(event)) {
						game.setWidthMaze(23);
						game.setHeightMaze(21);
						game.positionMaze.setX(170);
						game.positionMaze.setY(85);
						engine.setState(6);
					}
					if (buttonBig.isActive(event)) {
						game.setWidthMaze(33);
						game.setHeightMaze(23);
						game.positionMaze.setX(67);
						game.positionMaze.setY(67);
						engine.setState(6);
					}
				}

				window.clear();
				background.draw();
				buttonSmall.draw();
				buttonMiddle.draw();
				buttonBig.draw();
				window.display();
			}
		}
		//окно - игра
		else if (engine.getState() == 6) {
			Background background("images/background.png", &window);
			Maze maze(game.getWidthMaze(), game.getHeightMaze());
			Button buttonReturn("images/returnSmall.png", 10, 540, &window);
			Button buttonUpdate("images/update.png", 80, 540, &window);
			Button buttonPath("images/path.png", 150, 540, &window);
			Player player(maze.field, maze.getWidth(), maze.getHeight(), maze.entrance.getX(), maze.entrance.getY());

			Sound soundGuess("sounds/guessed.ogg");
			Sound soundDidNotGuess("sounds/DidNotGuess.ogg");

			//изображение кота саймона в лабиринте
			sf::Texture texture;
			texture.loadFromFile("images/saimon.png");
			sf::Sprite saimon(texture);

			//изображение которое используется в качестве стены для лабиринта
			sf::Texture texture2;
			texture2.loadFromFile("images/box.png");
			sf::Sprite wall(texture2);

			//изображение которое используется в качестве для рисования правильного пути
			sf::Texture texture3;
			texture3.loadFromFile("images/circle.png");
			sf::Sprite circle(texture3);

			//изображение - "незвестное содержимое", возле верхнего выхода
			sf::Texture textureBoxUp;
			textureBoxUp.loadFromFile("images/question.png");
			sf::Sprite spriteBoxUp(textureBoxUp);
			spriteBoxUp.setPosition(360, game.positionMaze.getY() - 60);

			//изображение - "незвестное содержимое", возле правого выхода
			sf::Texture textureBoxRight;
			textureBoxRight.loadFromFile("images/question.png");
			sf::Sprite spriteBoxRight(textureBoxRight);
			spriteBoxRight.setPosition(game.positionMaze.getX() + 20 * game.getWidthMaze(), 260);

			//изображение - "незвестное содержимое", возле нижнего выхода
			sf::Texture textureBoxDown;
			textureBoxDown.loadFromFile("images/question.png");
			sf::Sprite spriteBoxDown(textureBoxDown);
			spriteBoxDown.setPosition(360, game.positionMaze.getY()+20*game.getHeightMaze());

			while (engine.getState() == 6)
			{
				sf::Event event;
				while (window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						engine.setState(0);
					if (event.type == sf::Event::KeyPressed) {
						player.controller();
					}
					if (buttonReturn.isActive(event)) {
						engine.setState(1);
					}
					if (buttonPath.isActive(event)) {
						maze.drawTruePath();
					}
				}

				if (buttonUpdate.isActive(event)) {
					break;
				}
				//Если игрок подошел к одному из выходов
				//меняем картинку взле выхода на картинку с полной или пустой миской
				//в зависимости от того является выход верным или нет
				if (player.pos.getX() == maze.exitDown.getX() && 
					player.pos.getY() == maze.exitDown.getY()) {
					if (maze.trueExit.getX() == maze.exitDown.getX() &&
						maze.trueExit.getY() == maze.exitDown.getY()) {
						soundGuess.play();
						textureBoxDown.loadFromFile("images/fillBowl.png");
						maze.drawTruePath();
					}
					else {
						soundDidNotGuess.play();
						textureBoxDown.loadFromFile("images/emptyBowl.png");
					}
					maze.exitDown.setX(1000);
					maze.exitDown.setY(1000);
				}
				else if (player.pos.getX() == maze.exitUp.getX() &&
					player.pos.getY() == maze.exitUp.getY()) {
					if (maze.trueExit.getX() == maze.exitUp.getX() &&
						maze.trueExit.getY() == maze.exitUp.getY()) {
						soundGuess.play();
						textureBoxUp.loadFromFile("images/fillBowl.png");
						maze.drawTruePath();
					}
					else {
						soundDidNotGuess.play();
						textureBoxUp.loadFromFile("images/emptyBowl.png");
					}
					maze.exitUp.setX(0);
					maze.exitUp.setY(0);
				}
				else if (player.pos.getX() == maze.exitRight.getX() &&
					player.pos.getY() == maze.exitRight.getY()) {
					if (maze.trueExit.getX() == maze.exitRight.getX() &&
						maze.trueExit.getY() == maze.exitRight.getY()) {
						soundGuess.play();
						textureBoxRight.loadFromFile("images/fillBowl.png");
						maze.drawTruePath();
					}
					else {
						soundDidNotGuess.play();
						textureBoxRight.loadFromFile("images/emptyBowl.png");
					}
					maze.exitRight.setX(0);
					maze.exitRight.setY(0);
				}

				window.clear();
				background.draw();
				//Рисуем карту
				for (int i = 0; i < maze.getHeight(); i++)
					for (int j = 0; j < maze.getWidth(); j++)
					{
						if (maze.field[i][j] == -1) {
							wall.setPosition(j * 20 + game.positionMaze.getX(), i * 20 + game.positionMaze.getY());
							window.draw(wall);//рисуем стенку
						}
						else if (maze.field[i][j] == 1) {
							circle.setPosition(j * 20 + game.positionMaze.getX(), i * 20 + game.positionMaze.getY());
							window.draw(circle);//рисуем праильный путь
						}
						else if (maze.field[i][j] == 2) {
							saimon.setPosition(j * 20 + game.positionMaze.getX(), i * 20 + game.positionMaze.getY());
							window.draw(saimon);//рисуем саймона
						}
					}
				buttonReturn.draw();
				buttonUpdate.draw();
				buttonPath.draw();

				window.draw(spriteBoxUp);
				window.draw(spriteBoxRight);
				window.draw(spriteBoxDown);
				window.display();
			}
		}
	}
	return 0;
}
