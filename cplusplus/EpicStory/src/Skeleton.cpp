/*
 * Skeleton.cpp
 *
 *  Created on: Aug 4, 2010
 *      Author: Teen
 */

#include "Skeleton.h"
#include <vector>
#include "SDL/SDL.h"
#include "DMAGame.h"
using namespace std;

Skeleton::Skeleton(string name, int x, int y) :
	DMASprite(name) {
	int width = 64;
	int height = 64;
	// Begin moving animations setup
	vector<SDL_Rect*> leftrects;
	leftrects.push_back(DMAGame::getInstance().getRectInst(0 * width, 2 * height, width, height));
	leftrects.push_back(DMAGame::getInstance().getRectInst(1 * width, 2 * height, width, height));
	leftrects.push_back(DMAGame::getInstance().getRectInst(2 * width, 2 * height, width, height));
	leftrects.push_back(DMAGame::getInstance().getRectInst(3 * width, 2 * height, width, height));
	leftrects.push_back(DMAGame::getInstance().getRectInst(4 * width, 2 * height, width, height));
	leftrects.push_back(DMAGame::getInstance().getRectInst(5 * width, 2 * height, width, height));
	leftrects.push_back(DMAGame::getInstance().getRectInst(6 * width, 2 * height, width, height));
	this->left = new Animation(name + " left", leftrects, "zombie.png", 10);

	// moving animations setup complete. Begin still animations setup.
	this->current = this->left;
	this->current->rect.x = x;
	this->current->rect.y = y;
	this->setAnimation(this->left);
	this->rect = this->current->rect;
}

void Skeleton::update(void) {
	this->current->rect.x -=4;
	this->current->update();
	this->rect = current->rect;
	vector<DMASprite*> collisions = DMAGame::getInstance().spriteCollide(this, 3);
	for (vector<DMASprite*>::iterator eachCollision = collisions.begin(); eachCollision != collisions.end(); eachCollision++) {
		DMAGame::getInstance().getSpriteGroup(3)->removeSprite((*eachCollision));
		DMAGame::getInstance().getSpriteGroup(2)->removeSprite(this);
	}
}

void Skeleton::draw(SDL_Surface *screen) {
	this->current->draw(screen);
}

Skeleton::~Skeleton() {
	delete left;
	DMAGame::getInstance().getStatsBox()->updateScore(1);
}
void Skeleton::setAnimation(Animation *newAnimation) {
	newAnimation->rect.x = this->current->rect.x;
	newAnimation->rect.y = this->current->rect.y;
	this->current = newAnimation;
}
