/*
 * Score.cpp
 *
 *  Created on: Aug 3, 2010
 *      Author: Teen
 */

#include "Score.h"

Score::Score() :
	DMASprite("Score") {
	this->image = this->loadImage("score.png");
	this->adjustRectToImage();
	this->rect.x = 134;
	this->rect.y = 21;
}

void Score::update(void) {

}
