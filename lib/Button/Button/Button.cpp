// Button.cpp : Определяет экспортированные функции для приложения DLL.
//

#include "stdafx.h"
#include "Button.h"

Button::Button(std::string pathToImage, int posX, int posY, sf::RenderWindow *window)
{
	this->window = window;

	buttonTexture1.loadFromFile(pathToImage);
	buttonSprite.setTexture(buttonTexture1);
	buttonSprite.setPosition(posX, posY);

	setSoundOnClick("sounds/click.ogg");
	setColorOnClick();
}

void Button::draw() {
	window->draw(buttonSprite);
}

bool Button::isActive(sf::Event event) {
	pixelPosCursor = sf::Mouse::getPosition(*window);
	if (buttonSprite.getGlobalBounds().contains(pixelPosCursor.x, pixelPosCursor.y)) {
		buttonSprite.setColor(color);
		soundPlay();
		if ((event.type == sf::Event::MouseButtonPressed) && event.key.code == sf::Mouse::Left) {
			return true;
		}
	}
	else {
		isActiveSound = false;
		buttonSprite.setColor(sf::Color::White);
	}
	return false;
}

void Button::setColorOnClick() {
	color.r = 560; color.g = 160; color.b = 160;
}

void Button::setSoundOnClick(std::string pathToSound) {
	buffer.loadFromFile(pathToSound);
	sound.setBuffer(buffer);
}

void Button::soundPlay() {
	if (isActiveSound == false) {
		sound.play();
	}
	isActiveSound = true;
}

Button::~Button()
{
}


