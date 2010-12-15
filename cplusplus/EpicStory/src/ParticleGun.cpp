/*
 * ParticleGun.cpp
 *
 *  Created on: Aug 4, 2010
 *      Author: DigitalMediaAcademy
 */

#include "ParticleGun.h"
#include "DMAGame.h"
#include "Particle.h"
#include <stdlib.h>
#include <time.h>

ParticleGun::ParticleGun(int numParticles, string pictureName, int framesToDeath, float spread, float speed,
		float randomness) :
	DMASprite("ParticleGun") {
	srand(time(NULL));
	this->image = loadImage(pictureName.c_str());
	this->rect = this->image->clip_rect;
	this->numParticles = numParticles;
	this->framesToDeath = framesToDeath;
	this->spread = int(spread);
	this->speed = speed;
	this->randomness = randomness;
}

void ParticleGun::update() {

}

void ParticleGun::shoot(int x, int y, float angle) {
	for (int i = 0; i < this->numParticles; i++) {
		float angleOfFire = angle;
		float aRandomNumber = float(rand() % this->spread);
		float speedVariation = float(rand() % 100) * this->randomness;
		speedVariation /= 99.;
		float lowestVariation = 0.8;
		speedVariation = (1 - lowestVariation) * speedVariation + lowestVariation;
		aRandomNumber = aRandomNumber - (this->spread / 2.);
		DMAGame::getInstance().getSpriteGroup(3)->addSprite(new Particle(this->image, x, y, this->speed
				* (speedVariation), 0, angleOfFire + aRandomNumber, this->framesToDeath));
	}
}

void ParticleGun::draw(SDL_Surface* screen) {
	return;
}
