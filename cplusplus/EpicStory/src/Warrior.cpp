/*
 * Warrior.cpp
 *
 *  Created on: Aug 5, 2010
 *      Author: DigitalMediaAcademy
 */
#include <iostream>
using namespace std;
#include "Warrior.h"
#include "DMAGame.h"
Warrior::Warrior(string name, int x, int y) :
	DMASprite(name) {
	// Begin moving animations setup
	int width = 80;
	int height = 80;
	vector<SDL_Rect*> walkrects;
	walkrects.push_back(DMAGame::getInstance().getRectInst(0 * width, 2 * height + 1, width, height));
	walkrects.push_back(DMAGame::getInstance().getRectInst(1 * width, 2 * height + 1, width, height));
	walkrects.push_back(DMAGame::getInstance().getRectInst(2 * width, 2 * height + 1, width, height));
	vector<SDL_Rect*> jumprects;
	jumprects.push_back(DMAGame::getInstance().getRectInst(2 * width, 6 * height + 1, width, height));
	jumprects.push_back(DMAGame::getInstance().getRectInst(3 * width, 6 * height + 1, width, height));
	jumprects.push_back(DMAGame::getInstance().getRectInst(4 * width, 6 * height + 1, width, height));
	jumprects.push_back(DMAGame::getInstance().getRectInst(3 * width, 6 * height + 1, width, height));
	jumprects.push_back(DMAGame::getInstance().getRectInst(2 * width, 6 * height + 1, width, height));
	this->walk = new Animation(name + " right", walkrects, "ninjaSpriteSheet.png", 5);
	this->jump = new Animation(name + " right", jumprects, "ninjaSpriteSheet.png", 15);

	// moving animations setup complete. Begin still animations setup.

	// still animations setup complete.
	this->current = this->walk;
	this->rect = this->current->rect;
	this->current->rect.x = x;
	this->current->rect.y = y;
	this->x = x;
	this->y = y;
	this->vSpeed = 0;
	this->GRAVITY = 0.2;
	this->isJumping = false;
	this->MAX_SHOOT_TIMEOUT = 1;
	this->currentShootTimeout = 0;
	particleGun = new ParticleGun(5, "shuriken.png", 100, 20, 5, 0.6);
}

Warrior::~Warrior() {
	delete walk;
}

void Warrior::update(void) {
	if (DMAGame::getInstance().getPressed()[SDLK_z] && this->currentShootTimeout <= 0) {
		particleGun->shoot(this->current->rect.x + 32, this->current->rect.y + (this->current->rect.h) / 2, 0);
		DMAGame::getInstance().getStatsBox()->updateScore(1);
		this->currentShootTimeout = this->MAX_SHOOT_TIMEOUT;
	}
	if (DMAGame::getInstance().getPressed()[SDLK_x]) {
		DMAGame::getInstance().getStatsBox()->updateHealth(-1);
	}
	if (DMAGame::getInstance().getPressed()[SDLK_c] && !this->isJumping) {
		this->vSpeed = -10;
		this->isJumping = true;
		this->setAnimation(this->jump);
	}
	if (this->isJumping) {
		this->y += this->vSpeed;
		cout << "y is " << y << endl;
		this->vSpeed += this->GRAVITY;
		if (this->y >= 490) {
			this->y = 490;
			this->vSpeed = 0;
			this->isJumping = false;
			this->setAnimation(this->walk);
		}
	}
	this->currentShootTimeout -= 1;
	this->current->rect.x = int(this->x);
	this->current->rect.y = int(this->y);
	current->update();
	this->rect = current->rect;
}

void Warrior::draw(SDL_Surface *screen) {
	this->current->draw(screen);
}
void Warrior::setAnimation(Animation *newAnimation) {
	newAnimation->rect.x = this->current->rect.x;
	newAnimation->rect.y = this->current->rect.y;
	this->current = newAnimation;
}
