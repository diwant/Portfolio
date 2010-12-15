/*
 * StatsBox.cpp
 *
 *  Created on: Aug 4, 2010
 *      Author: Teen
 */

#include <iostream>
#include <sstream>
using namespace std;
#include "StatsBox.h"
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"

StatsBox::StatsBox() :
	DMASprite("StatsBox") {
	this->font = TTF_OpenFont("kato.ttf", 20);
	TTF_SetFontStyle(this->font, TTF_STYLE_BOLD);
	cout << "Loaded font " << this->font << endl;
	this->healthColor.r = 0;
	this->healthColor.g = 0;
	this->healthColor.b = 255;
	this->scoreColor.r = 0;
	this->scoreColor.g = 0;
	this->scoreColor.b = 0;

	this->rect.x = 58;
	this->rect.y = 24;
	this->health = 100;
	this->score = 0;
	stringstream healthStr;
	healthStr << this->health;
	stringstream scoreStr;
	scoreStr << this->score;

	this->image = TTF_RenderText_Solid(this->font, healthStr.str().c_str(), this->healthColor);
	this->scoreImage = TTF_RenderText_Solid(this->font, scoreStr.str().c_str(), this->scoreColor);
}

StatsBox::~StatsBox() {
}

void StatsBox::draw(SDL_Surface *screen) {
	SDL_Rect temp = this->rect;
	SDL_BlitSurface(this->image, NULL, screen, &(temp));
	temp = this->rect;
	temp.x += 110;
	SDL_BlitSurface(this->scoreImage, NULL, screen, &(temp));
}

void StatsBox::updateHealth(int changeInHealth) {
	this->health += changeInHealth;
	stringstream healthStr;
	healthStr << this->health;
	this->image = TTF_RenderText_Solid(this->font, healthStr.str().c_str(), this->healthColor);
}

void StatsBox::updateScore(int changeInScore) {
	this->score += changeInScore;
	stringstream scoreStr;
	scoreStr << this->score;
	this->scoreImage = TTF_RenderText_Solid(this->font, scoreStr.str().c_str(), this->scoreColor);
}
