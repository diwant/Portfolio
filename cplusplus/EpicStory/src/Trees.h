/*
 * Trees.h
 *
 *  Created on: Aug 4, 2010
 *      Author: Teen
 */

#ifndef TREES_H_
#define TREES_H_
#include "DMASprite.h"

class Trees: public DMASprite {
public:
	Trees();
	void update(void);
	void draw(SDL_Surface *screen);

};

#endif /* TREES_H_ */
