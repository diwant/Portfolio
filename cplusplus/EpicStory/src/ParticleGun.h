/*
 * ParticleGun.h
 *
 *  Created on: Aug 4, 2010
 *      Author: DigitalMediaAcademy
 */

#ifndef PARTICLEGUN_H_
#define PARTICLEGUN_H_

#include "DMASprite.h"
using namespace std;
#include <vector>

class ParticleGun: public DMASprite {
public:
	ParticleGun(int numParticles,
			string pictureName,
			int framesToDeath, float spread,float speed,
			float randomness);
	void shoot(int x, int y, float angle);
	void update(void);
	void draw(SDL_Surface* screen);
private:
	int numParticles;
	int framesToDeath;
	float randomness;
	int spread;
	float speed;
};
#endif /* PARTICLEGUN_H_ */
