/*
 * BackgroundSprite.cpp
 *
 *  Created on: Aug 5, 2010
 *      Author: Teen
 */

#include "BackgroundSprite.h"
#include <string>

BackgroundSprite::BackgroundSprite(string file, int y, int speed) : DMASprite("Background") {
	this->image = this->loadImage(file.c_str());
	this->rect = this->image->clip_rect;
	this->rect.x = 0;
	this->rect.y = y;
	this->speed = speed;
}

void BackgroundSprite::update(void) {
	this->rect.x -= speed;
	if (this->rect.x < 0) {
		rect.x = rect.w;
	} else if (this->rect.x > rect.w) {
		rect.x = 0;
	}
}

void BackgroundSprite::draw(SDL_Surface *screen) {
	SDL_Rect temp = this->rect;
	SDL_BlitSurface(this->image, NULL, screen, &(temp));
	temp = this->rect;
	temp.x -= temp.w;
	SDL_BlitSurface(this->image, NULL, screen, &(temp));
}

