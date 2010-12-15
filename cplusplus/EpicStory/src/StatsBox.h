/*
 * StatsBox.h
 *
 *  Created on: Aug 4, 2010
 *      Author: Teen
 */

#ifndef STATSBOX_H_
#define STATSBOX_H_

#include "DMASprite.h"
#include "SDL/SDL_ttf.h"
#include <string>
using namespace std;

class StatsBox: public DMASprite {
public:
	StatsBox();
	virtual ~StatsBox();
	void draw(SDL_Surface *screen);
	void updateHealth(int changeInHealth);
	void updateScore(int changeInScore);
private:
	SDL_Surface *background;
	TTF_Font *font;
	SDL_Surface *scoreImage;
	int health;
	int score;
	SDL_Color healthColor;
	SDL_Color scoreColor;
};

#endif /* STATSBOX_H_ */
