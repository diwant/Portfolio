/*
 * SpriteGroup.h
 *
 *  Created on: Aug 2, 2010
 *      Author: diwant
 */

#ifndef SPRITEGROUP_H_
#define SPRITEGROUP_H_
#include "SDL/SDL.h"
#include "DMASprite.h"
#include <string>
#include <vector>
using namespace std;

class DMASpriteGroup {
public:
	string name;
	DMASpriteGroup(string name);
	DMASpriteGroup(DMASpriteGroup &otherSpriteGroup);
	DMASpriteGroup &operator=(DMASpriteGroup &rhs);
	virtual ~DMASpriteGroup();
	void update();
	void draw(SDL_Surface *screen);
	void addSprite(DMASprite *spriteToAdd);
	void removeSprite(DMASprite *spriteToRemove);
	vector<DMASprite*> spriteCollide(DMASprite* collideWith);
private:
	vector<DMASprite*> spritesInThisGroup;
};

#endif /* SPRITEGROUP_H_ */
