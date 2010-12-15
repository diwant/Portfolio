/*
 * Road.h
 *
 *  Created on: Aug 4, 2010
 *      Author: Teen
 */

#ifndef ROAD_H_
#define ROAD_H_
#include "DMASprite.h"

class Road: public DMASprite {
public:
	Road();
	void update(void);

	void draw(SDL_Surface *screen);

};

#endif /* ROAD_H_ */
