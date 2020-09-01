#pragma once
#include <SFML/Audio.hpp>
#include <iostream>

#define DllExport   __declspec( dllexport )
#define DllImport   __declspec( dllimport )

/*
* Класс идеально подходит для воспроизведения коротких звуков,
* которые могут уместиться в памяти и не требовать задержек.
*/ 

class DllExport Sound
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

