/*
 * Sprite.cpp
 *
 *  Created on: Aug 2, 2010
 *      Author: diwant
 */

#include "DMASprite.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <iostream>
using namespace std;

DMASprite::DMASprite(string name) {
	this->name = name;

}
DMASprite::DMASprite(const DMASprite &otherSprite) {
	cout << "[ GAME > SPRITEGROUP > SPRITE ] " << "Creating from copy constructor new sprite, " << otherSprite.name
			<< endl;
	this->name = otherSprite.name;
	this->image = SDL_DisplayFormatAlpha(otherSprite.image);
	this->rect = this->image->clip_rect;
}
DMASprite& DMASprite::operator =(const DMASprite &rhs) {
	cout << "[ GAME > SPRITEGROUP > SPRITE ] " << "Creating from operator= new sprite, " << rhs.name << endl;
	SDL_FreeSurface(this->image);
	this->name = rhs.name;
	this->image = SDL_DisplayFormat(rhs.image);
	this->rect = this->image->clip_rect;
	return *this;
}
DMASprite::~DMASprite() {
	SDL_FreeSurface(this->image);
}

void DMASprite::draw(SDL_Surface *screen) {
	SDL_Rect temp = this->rect;
	SDL_BlitSurface(this->image, NULL, screen, &(temp));
}

SDL_Surface* DMASprite::loadImage(const char *filename) {
	SDL_Surface * loadedImage = IMG_Load(filename), *optimizedImage;
	if (loadedImage != NULL) {
		optimizedImage = SDL_DisplayFormatAlpha(loadedImage);
		SDL_FreeSurface(loadedImage);
		return optimizedImage;
	} else {
		cout << "[ GAME > SPRITEGROUP > SPRITE ] " << "Error loading the image for the sprite " << this->name << ": "
				<< IMG_GetError() << endl;
		this->image = NULL;
	}
	return NULL;
}

string DMASprite::getName(void) {
	return this->name;
}
void DMASprite::update(void) {
}
SDL_Rect DMASprite::getRect() {
	return this->rect;
}
void DMASprite::adjustRectToImage() {
	this->rect.h = this->image->clip_rect.h;
	this->rect.w = this->image->clip_rect.w;
}

