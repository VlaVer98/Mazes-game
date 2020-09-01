#include "stdafx.h"
#include "Sound.h"


Sound::Sound()
{
}

Sound::Sound(std::string path)
{
	buffer.loadFromFile(path);
	sound.setBuffer(buffer);
}

void Sound::play() {
	sound.play();
}

Sound::~Sound()
{
}
