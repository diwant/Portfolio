/*
 * Particle.h
 *
 *  Created on: Aug 4, 2010
 *      Author: DigitalMediaAcademy
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

#include "DMASprite.h"

class Particle: public DMASprite {
public:
	Particle(SDL_Surface* particleImage, int x,
			int y, float speed, float gravity,
			float angle, int framesTillDeath);
	void update(void);
	void kill(void);
private:
	float speed;
	float gravity;
	float angle;
	float pi;
	float gravitySpeed;
	int killClock;
	bool isDead;
	int framesTillDeath;
	float x;
	float y;
};

#endif /* PARTICLE_H_ */
