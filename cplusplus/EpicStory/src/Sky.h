/*
 * Sky.h
 *
 *  Created on: Aug 4, 2010
 *      Author: Teen
 */

#ifndef SKY_H_
#define SKY_H_
#include "DMASprite.h"

class Sky: public DMASprite {
public:
	Sky();
	void update(void);
	void draw(SDL_Surface *screen);

};

#endif /* Sky_H_ */
