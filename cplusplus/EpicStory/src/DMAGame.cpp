/*
 * Game.cpp
 *
 *  Created on: Aug 2, 2010
 *      Author: diwant
 */

#include "DMAGame.h"
#include "DMASpriteGroup.h"
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include <iostream>
using namespace std;

const int DMAGame::FRAMES_PER_SECOND = 60;

DMAGame& DMAGame::getInstance() {
	static DMAGame instance;
	return instance;
}

SDL_Surface* DMAGame::getScreen() {
	return this->screen;
}

bool DMAGame::init(void) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		cout << "Could not initialize SDL" << endl;
		return false;
	}
	this->screen = SDL_SetVideoMode(1024, 640, 32, SDL_DOUBLEBUF
			| SDL_HWSURFACE | SDL_FULLSCREEN);
	if (screen == NULL) {
		cout << "Could not create the window and/or grab the surface" << endl;
		return false;
	}
	SDL_WM_SetCaption("Ninja", NULL);

	if (TTF_Init() == -1) {
		cout << "Could not load the font" << endl;
		return false;
	}
	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024)) {
		cout << "Could not load the mixer" << endl;
	}
	this->mySpriteGroups.push_back(new DMASpriteGroup("background"));
	this->mySpriteGroups.push_back(new DMASpriteGroup("mainCharacters"));
	this->mySpriteGroups.push_back(new DMASpriteGroup("zombies"));
	this->mySpriteGroups.push_back(new DMASpriteGroup("particles"));
	this->mySpriteGroups.push_back(new DMASpriteGroup("scoreAndHealth"));
	this->mySpriteGroups.push_back(new DMASpriteGroup("foreground"));
	// set all key states
	for (int i = 0; i < 1000; i++) {
		this->pressedKeys.push_back(false);
	}
	cout << "Init of game was successful!" << endl;
	return true;
}

void DMAGame::deinit(void) {
	SDL_Quit();
	cout << "De-init of game was successful!" << endl;
}

void DMAGame::mainGameLoop(void) {
	this->exit = false;
	int startTime = 0, endTime = 0;
	while (!(this->exit)) {
		// Frame start time
		startTime = SDL_GetTicks();
		for (vector<DMASpriteGroup*>::iterator eachSpriteGroup =
				this->mySpriteGroups.begin(); eachSpriteGroup
				!= this->mySpriteGroups.end(); eachSpriteGroup++) {
			(*eachSpriteGroup)->update();
		}
		SDL_FillRect(this->screen, NULL, 0);
		for (vector<DMASpriteGroup*>::iterator eachSpriteGroup =
				this->mySpriteGroups.begin(); eachSpriteGroup
				!= this->mySpriteGroups.end(); eachSpriteGroup++) {
			(*eachSpriteGroup)->draw(this->screen);
		}
		this->handleEvents();
		SDL_Flip(this->screen);
		// Frame end time
		endTime = SDL_GetTicks();
		if ((endTime - startTime) < 1000 / this->FRAMES_PER_SECOND) {
			// Sleep the remaining time for this frame
			SDL_Delay(1000 / this->FRAMES_PER_SECOND - (endTime - startTime));
		}
	}
}

void DMAGame::handleEvents(void) {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			this->quit();
		}
		if (event.type == SDL_KEYDOWN) {
			this->pressedKeys[event.key.keysym.sym] = true;
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				this->quit();
			}
		}
		if (event.type == SDL_KEYUP) {
			this->pressedKeys[event.key.keysym.sym] = false;
		}
	}
}

void DMAGame::quit(void) {
	this->exit = true;
}

DMASpriteGroup* DMAGame::getSpriteGroup(int layer = 0) {
	return this->mySpriteGroups.at(layer);
}

vector<DMASprite*> DMAGame::spriteCollide(DMASprite* collideWith,
		int collideGroupIndex) {
	return this->getSpriteGroup(collideGroupIndex)->spriteCollide(collideWith);
}

vector<bool> DMAGame::getPressed() {
	return this->pressedKeys;
}

SDL_Rect* DMAGame::getRectInst(int x, int y, int w, int h) {
	SDL_Rect *ret = new SDL_Rect();
	ret->x = x;
	ret->y = y;
	ret->h = h;
	ret->w = w;
	return ret;
}

void DMAGame::setStatsBox(StatsBox *theStatsBox) {
	this->myStatsBox = theStatsBox;
	this->getSpriteGroup(4)->addSprite(this->myStatsBox);
}
StatsBox* DMAGame::getStatsBox(void) {
	return this->myStatsBox;
}
