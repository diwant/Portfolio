/*
 * Trees.cpp
 *
 *  Created on: Aug 4, 2010
 *      Author: Teen
 */

#include "Trees.h"
#include "DMAGame.h"

Trees::Trees() :
	DMASprite("Trees") {
	this->image = this->loadImage("trees.png"); //As you should know, the .png is the image you include.
	this->rect.x = 00;
	this->rect.y = 350; //<- the position the sprite starts in

}
void Trees::update(void) {
	this->rect.x -= 2;
	if (this->rect.x <= -1280) { //<-the width of the screen where 1280 is
		rect.x = 0;
	}
}

void Trees::draw(SDL_Surface *screen) {
	SDL_Rect temp = this->rect;
	SDL_BlitSurface(this->image, NULL, screen,
			&(temp));
	temp = this->rect;
	temp.x += 1280;
	SDL_BlitSurface(this->image, NULL, screen,
			&(temp));
}

