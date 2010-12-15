/*
 * Road.cpp
 *
 *  Created on: Aug 4, 2010
 *      Author: Teen
 */

#include "Road.h"
#include "DMAGame.h"


Road::Road() :
	DMASprite("Road") {
	this->image = this->loadImage("road.png"); //As you should know, the .png is the image you include.
	this->rect.x = 00;
	this->rect.y = 780;  //<- the position the sprite starts in


}

void Road::update(void) {
	this->rect.x -= 5;
	if (this->rect.x <= -1280) { //<-the width of the screen where 1280 is
			rect.x = 0;
		}
}

void Road::draw(SDL_Surface *screen) {
	SDL_Rect temp = this->rect;
	SDL_BlitSurface(this->image, NULL, screen,
			&(temp));
	temp = this->rect;
	temp.x += 1280;
	SDL_BlitSurface(this->image, NULL, screen,
			&(temp));
}
