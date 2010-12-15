/*
 * Animation.cpp
 *
 *  Created on: Aug 3, 2010
 *      Author: Teen
 */

#include "Animation.h"
#include "SDL/SDL.h"
using namespace std;
#include <iostream>
#include <vector>

Animation::Animation(string name, vector<
		SDL_Rect*> frames, string file,
		int frameLength) :
	DMASprite(name) {
	cout << "Creating Animation\n";
	this->frames = frames;
	this->image = this->loadImage(file.c_str());
	this->adjustRectToImage();
	this->current = this->frames.begin();
	this->frameLength = frameLength;
	this->tickCount = 0;
	this->rect = **this->current;
	this->rect.x = 0;
	this->rect.y = 0;
}

Animation::Animation(Animation &otherSprite) :
	DMASprite(otherSprite.name) {
	this->name = otherSprite.name;
	for (vector<SDL_Rect*>::iterator i =
			otherSprite.frames.begin(); i
			!= otherSprite.frames.end(); i++) {
		this->frames.push_back(*i);
	}
	this->current = this->frames.begin();
	for (vector<SDL_Rect*>::iterator i2 =
			otherSprite.frames.begin(); i2
			!= otherSprite.current; i2++, this->current++)
		;
	this->image = SDL_DisplayFormatAlpha(
			otherSprite.image);
	this->frameLength = otherSprite.frameLength;
	this->tickCount = otherSprite.tickCount;
	this->rect = otherSprite.rect;
}

Animation& Animation::operator =(Animation &rhs) {
	this->name = rhs.name;
	for (vector<SDL_Rect*>::iterator i =
			rhs.frames.begin(); i
			!= rhs.frames.end(); i++) {
		this->frames.push_back(*i);
	}
	this->current = this->frames.begin();
	for (vector<SDL_Rect*>::iterator i2 =
			rhs.frames.begin(); i2 != rhs.current; i2++, this->current++)
		;
	this->image = SDL_DisplayFormat(rhs.image);
	this->frameLength = rhs.frameLength;
	this->tickCount = rhs.tickCount;
	this->rect = rhs.rect;
	return *this;
}

void Animation::draw(SDL_Surface *screen) {
	SDL_Rect tempPos = this->rect;
	SDL_Rect tempClip = **this->current;
	SDL_BlitSurface(this->image, &(tempClip),
			screen, &(tempPos));
}

void Animation::update(void) {
	this->tickCount++;
	if (this->tickCount == this->frameLength) {
		this->current++;
		this->tickCount = 0;
		if (this->current == this->frames.end()) {
			this->current = this->frames.begin();
		}
		this->rect.w = (**this->current).w;
		this->rect.h = (**this->current).h;
	}
}

Animation::~Animation() {
	for (vector<SDL_Rect*>::iterator i =
			frames.begin(); i != frames.end(); i++) {
		delete *i;
	}
}
