/*
 * SpriteGroup.cpp
 *
 *  Created on: Aug 2, 2010
 *      Author: diwant
 */

#include "DMASpriteGroup.h"
#include "DMASprite.h"
#include <iostream>
using namespace std;

DMASpriteGroup::DMASpriteGroup(string name) {
	this->name = name;
}
DMASpriteGroup::DMASpriteGroup(DMASpriteGroup &otherSpriteGroup) {
	cout << "[ GAME > SPRITEGROUP ] " << "Copying sprite group, " << otherSpriteGroup.name << ", which has "
			<< otherSpriteGroup.spritesInThisGroup.size() << " things" << endl;

	this->name = otherSpriteGroup.name + " (copy)";
	for (vector<DMASprite*>::iterator eachSprite = otherSpriteGroup.spritesInThisGroup.begin(); eachSprite
			!= otherSpriteGroup.spritesInThisGroup.end(); eachSprite++) {
		this->spritesInThisGroup.push_back(new DMASprite((**eachSprite)));
	}
}
DMASpriteGroup& DMASpriteGroup::operator =(DMASpriteGroup &rhs) {
	cout << "[ GAME > SPRITEGROUP ] " << "Creating from operator= new sprite group, " << rhs.name << ", which has "
			<< rhs.spritesInThisGroup.size() << " things" << endl;

	for (vector<DMASprite*>::iterator eachSprite = this->spritesInThisGroup.begin(); eachSprite
			!= this->spritesInThisGroup.end(); eachSprite++) {
		delete (*eachSprite);
	}
	this->name = rhs.name;
	for (vector<DMASprite*>::iterator eachSprite = rhs.spritesInThisGroup.begin(); eachSprite
			!= rhs.spritesInThisGroup.end(); eachSprite++) {
		this->spritesInThisGroup.push_back(new DMASprite((**eachSprite)));
	}
	return *this;
}

DMASpriteGroup::~DMASpriteGroup() {
	for (vector<DMASprite*>::iterator eachSprite = this->spritesInThisGroup.begin(); eachSprite
			!= this->spritesInThisGroup.end(); eachSprite++) {
		delete (*eachSprite);
	}
}

void DMASpriteGroup::draw(SDL_Surface *screen) {
	for (vector<DMASprite*>::iterator eachSprite = this->spritesInThisGroup.begin(); eachSprite
			!= this->spritesInThisGroup.end(); eachSprite++) {
		(*eachSprite)->draw(screen);
	}
}

void DMASpriteGroup::addSprite(DMASprite *spriteToAdd) {
	this->spritesInThisGroup.push_back(spriteToAdd);
	cout << "[ GAME > SPRITEGROUP ] " << "Added " << spriteToAdd->getName() << " to the " << this->name << " group"
			<< endl;
}

void DMASpriteGroup::removeSprite(DMASprite *spriteToRemove) {
	vector<DMASprite*>::iterator deleteThisSprite = this->spritesInThisGroup.end();
	for (vector<DMASprite*>::iterator eachSprite = this->spritesInThisGroup.begin(); eachSprite
			!= this->spritesInThisGroup.end(); eachSprite++) {
		if ((*eachSprite) == (spriteToRemove)) {
			deleteThisSprite = eachSprite;
			break;
		}
	}
	if (deleteThisSprite != this->spritesInThisGroup.end()) {
		this->spritesInThisGroup.erase(deleteThisSprite);
		cout << "[ GAME > SPRITEGROUP ] " << "Removed " << (*deleteThisSprite)->getName() << " from the " << this->name
				<< " group" << endl;
	}
}
void DMASpriteGroup::update(void) {
	vector<DMASprite*> tempSpriteList;
	for (vector<DMASprite*>::iterator eachSprite = this->spritesInThisGroup.begin(); eachSprite
			!= this->spritesInThisGroup.end(); eachSprite++) {
		tempSpriteList.push_back((*eachSprite));
	}
	for (vector<DMASprite*>::iterator eachSprite = tempSpriteList.begin(); eachSprite != tempSpriteList.end(); eachSprite++) {
		(*eachSprite)->update();
	}
}

vector<DMASprite*> DMASpriteGroup::spriteCollide(DMASprite *collideWith) {
	vector<DMASprite*> collidingSprites;
	SDL_Rect rectA = collideWith->getRect();

	int leftA = rectA.x, rightA = rectA.x + rectA.w;
	int topA = rectA.y, bottomA = rectA.y + rectA.h;
	SDL_Rect rectB;
	for (vector<DMASprite*>::iterator eachSpriteInGroup = this->spritesInThisGroup.begin(); eachSpriteInGroup
			!= this->spritesInThisGroup.end(); eachSpriteInGroup++) {
		if (collideWith == (*eachSpriteInGroup)) {
			// dont check colliding with self
			continue;
		}
		rectB = (*eachSpriteInGroup)->getRect();
		int leftB = rectB.x, rightB = rectB.x + rectB.w;
		int topB = rectB.y, bottomB = rectB.y + rectB.h;
		if (bottomA <= topB || topA >= bottomB || leftA >= rightB || rightA <= leftB) {
			// no collision
		} else {
			collidingSprites.push_back((*eachSpriteInGroup));
			cout << "Collision check with " << collideWith->getName() << " " << rectA.x << " " << rectA.y << " "
					<< rectA.w << " " << rectA.h << endl << "======================" << endl;
			cout << ">> with " << (*eachSpriteInGroup)->getName() << " " << rectB.x << " " << rectB.y << " " << rectB.w
					<< " " << rectB.h << endl;
		}
	}
	return collidingSprites;
}
