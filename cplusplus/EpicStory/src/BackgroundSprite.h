/*
 * BackgroundSprite.h
 *
 *  Created on: Aug 5, 2010
 *      Author: Teen
 */

#ifndef BACKGROUNDSPRITE_H_
#define BACKGROUNDSPRITE_H_

#include "DMASprite.h"

class BackgroundSprite: public DMASprite {
public:
	BackgroundSprite(string, int, int);
	virtual void update(void);
	virtual void draw(SDL_Surface *screen);
protected:
	int speed;
};

#endif /* BACKGROUNDSPRITE_H_ */
