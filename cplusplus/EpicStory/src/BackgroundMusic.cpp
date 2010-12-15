/*
 * BackgroundMusic.cpp
 *
 *  Created on: Aug 6, 2010
 *      Author: DigitalMediaAcademy
 */

#include "BackgroundMusic.h"

BackgroundMusic::BackgroundMusic() :
	DMASprite("Background music") {
	music = Mix_LoadMUS("newgrounds.mp3");
	Mix_PlayMusic(this->music, -1);
}

BackgroundMusic::~BackgroundMusic() {
	Mix_FreeMusic(this->music);
	this->music = NULL;
}

