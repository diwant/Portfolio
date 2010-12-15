/*
 * Sky.cpp
 *
 *  Created on: Aug 4, 2010
 *      Author: Teen
 */

#include "Sky.h"
#include "DMAGame.h"

Sky::Sky() :
	DMASprite("Sky") {
	this->image = this->loadImage("Sky.png"); //As you should know, the .png is the image you include.
	this->rect.x = 0;
	this->rect.y = 0; //<- the position the sprite starts in

}
void Sky::update(void) {
	this->rect.x += 1;
	if (this->rect.x >= 1280) { //<-the width of the screen where 1280 is
		rect.x = 0;
	}
}

void Sky::draw(SDL_Surface *screen) {
	SDL_Rect temp = this->rect;
	SDL_BlitSurface(this->image, NULL, screen,
			&(temp));
	temp = this->rect;
	temp.x -= 1280;
	SDL_BlitSurface(this->image, NULL, screen,
			&(temp));
}

