/*
 * EnemySpawner.h
 *
 *  Created on: Aug 6, 2010
 *      Author: DigitalMediaAcademy
 */

#ifndef ENEMYSPAWNER_H_
#define ENEMYSPAWNER_H_

#include "DMASprite.h"

class EnemySpawner: public DMASprite {
public:
	EnemySpawner();
	void update(void);
	void draw(SDL_Surface* screen);
private:
	int timeTillSpawn;
	int getTimeTillNextSpawn(void);
};
#endif /* ENEMYSPAWNER_H_ */
