/*
 * Sprite.h
 *
 *  Created on: Aug 2, 2010
 *      Author: diwant
 */

#ifndef SPRITE_H_
#define SPRITE_H_
#include "SDL/SDL.h"
#include <string>
using namespace std;
class DMASprite {
public:
	DMASprite(string name);
	DMASprite(const DMASprite &otherSprite);
	DMASprite &operator=(const DMASprite &rhs);
	virtual ~DMASprite();
	virtual void update(void);
	virtual void draw(SDL_Surface *screen);
	string getName(void);
	SDL_Rect getRect(void);
protected:
	SDL_Surface *image;
	SDL_Rect rect;
	SDL_Surface* loadImage(const char * filename);
	void adjustRectToImage(void);
	string name;
};

#endif /* SPRITE_H_ */
