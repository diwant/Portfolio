/*
 * Scoreboard.cpp
 *
 *  Created on: Aug 3, 2010
 *      Author: Teen
 */

#include "Scoreboard.h"

Scoreboard::Scoreboard() :
	DMASprite("Scoreboard") {
	this->image = this->loadImage(
			"scoreboard.png");
	this->adjustRectToImage();
	this->rect.x = 13;
	this->rect.y = 13;
}

void Scoreboard::update(void) {

}
