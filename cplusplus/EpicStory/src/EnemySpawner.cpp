/*
 * EnemySpawner.cpp
 *
 *  Created on: Aug 6, 2010
 *      Author: DigitalMediaAcademy
 */

#include "EnemySpawner.h"
#include "Skeleton.h"
#include "DMAGame.h"
#include <iostream>
using namespace std;
EnemySpawner::EnemySpawner() :
	DMASprite("EnemySpawner") {
	this->timeTillSpawn = getTimeTillNextSpawn();

}
int EnemySpawner::getTimeTillNextSpawn(void) {
	return 100;
}
void EnemySpawner::update(void) {
	if (timeTillSpawn <= 0) {
		DMAGame::getInstance().getSpriteGroup(2)->addSprite(new Skeleton("Zombie", 1300, 510));
		timeTillSpawn = getTimeTillNextSpawn();

	} else {
		timeTillSpawn--;
	}
}

void EnemySpawner::draw(SDL_Surface* screen) {

}
