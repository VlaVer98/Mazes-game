#pragma once
#include <SFML/Audio.hpp>
#include <iostream>


class Sound
{
protected:
	sf::SoundBuffer buffer;
	sf::Sound sound;
public:
	Sound();
	Sound(std::string path);
	void play();
	~Sound();
};

