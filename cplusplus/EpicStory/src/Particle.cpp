/*
 * Particle.cpp
 *
 *  Created on: Aug 4, 2010
 *      Author: DigitalMediaAcademy
 */

#include "Particle.h"
#include <cmath>
#include "DMAGame.h"

Particle::Particle(SDL_Surface *particleImage, int x, int y, float speed, float gravity, float angle,
		int framesTillDeath) :
	DMASprite("particle") {
	this->rect.x = x;
	this->rect.y = y;
	this->speed = speed;
	this->gravity = gravity;
	this->angle = angle;
	this->pi = 3.14159;
	this->gravitySpeed = 0;
	this->killClock = 0;
	this->image = particleImage;
	this->framesTillDeath = framesTillDeath;
	this->x = x;
	this->y = y;
	adjustRectToImage();
}

void Particle::update() {
	this->killClock += 1;
	this->x += this->speed * cos((this->angle * this->pi) / 180);
	this->gravitySpeed += this->gravity;
	this->y -= this->speed * sin((this->angle * this->pi) / 180) - this->gravitySpeed;
	this->rect.x = int(this->x);
	this->rect.y = int(this->y);
	this->kill();
}

void Particle::kill() {
	if (this->killClock >= this->framesTillDeath) {
		DMAGame::getInstance().getSpriteGroup(3)->removeSprite(this);
	}
}
