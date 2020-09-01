#include "Background.h"

Background::Background(string path, sf::RenderWindow *window) {
	this->window = window;
	m_BackgroundTexture.loadFromFile(path);
	m_BackgroundSprite.setTexture(m_BackgroundTexture);
}

void Background::draw() {
	window->draw(m_BackgroundSprite);
}

Background::~Background()
{

}
