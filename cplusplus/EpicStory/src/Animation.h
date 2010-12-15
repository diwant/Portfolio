/*
 * Animation.h
 *
 *  Created on: Aug 3, 2010
 *      Author: Teen
 */

#ifndef ANIMATION_H_
#define ANIMATION_H_

#include "DMASprite.h"
#include "SDL/SDL.h"
#include <vector>
using namespace std;

class Animation: public DMASprite {
public:
	Animation(string, vector<SDL_Rect*> , string,
			int);
	Animation(Animation &otherSprite);
	Animation& operator=(Animation &rhs);
	virtual ~Animation();
	virtual void update(void);
	virtual void draw(SDL_Surface *screen);
	SDL_Rect rect;
protected:
	vector<SDL_Rect*> frames;
	vector<SDL_Rect*>::iterator current;
	int frameLength;
	int tickCount;
};

#endif /* ANIMATION_H_ */
