/*
 * Skeleton.h
 *
 *  Created on: Aug 4, 2010
 *      Author: Teen
 */

#ifndef SKELETON_H_
#define SKELETON_H_

#include "DMASprite.h"
#include "Animation.h"
#include "ParticleGun.h"

class Skeleton: public DMASprite {
public:
	Skeleton(string, int, int);
	virtual ~Skeleton();
	virtual void update(void);
	virtual void draw(SDL_Surface *screen);
protected:
	Animation *current;
	Animation *left;
private:
	void setAnimation(Animation *newAnimation);
};

#endif /* SKELETON_H_ */
