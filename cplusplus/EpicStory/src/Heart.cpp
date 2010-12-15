/*
 * Heart.cpp
 *
 *  Created on: Aug 3, 2010
 *      Author: Teen
 */

#include "Heart.h"

Heart::Heart() :
	DMASprite("Heart") {
	this->image = this->loadImage("heart.png");
	this->adjustRectToImage();
	this->rect.x = 24;
	this->rect.y = 22;
}

void Heart::update(void) {

}
