/*
 * Warrior.h
 *
 *  Created on: Aug 5, 2010
 *      Author: DigitalMediaAcademy
 */

#ifndef WARRIOR_H_
#define WARRIOR_H_

#include "DMASprite.h"
#include "Animation.h"
#include "ParticleGun.h"
class Warrior: public DMASprite {
public:
	Warrior(string, int, int);
	virtual ~Warrior();
	virtual void update(void);
	virtual void draw(SDL_Surface *screen);
protected:
	Animation *current;
	Animation *walk;
	Animation *jump;
	void setAnimation(Animation *newAnimation);
private:
	ParticleGun* particleGun;
	int currentShootTimeout;
	int MAX_SHOOT_TIMEOUT;
	bool isJumping;
	float vSpeed;
	float GRAVITY;
	float x;
	float y;
};

#endif /* WARRIOR_H_ */
