/*
 * Game.h
 *
 *  Created on: Aug 2, 2010
 *      Author: diwant
 */

#ifndef GAME_H_
#define GAME_H_

#include "SDL/SDL.h"
#include "DMASpriteGroup.h"
#include "StatsBox.h"
#include <vector>
using namespace std;

class DMAGame {
private:
	//The frames per second
	static const int FRAMES_PER_SECOND;
	bool exit;
	vector<DMASpriteGroup*> mySpriteGroups;
	SDL_Surface *screen;
	vector<bool> pressedKeys;

	DMAGame() {
	}
	~DMAGame() {
	}
	DMAGame(const DMAGame&); // intentionally undefined
	DMAGame &operator=(const DMAGame &); // intentionally undefined

	void handleEvents(void);
	StatsBox* myStatsBox;
public:
	SDL_Rect* getRectInst(int, int, int, int);
	static DMAGame &getInstance();
	SDL_Surface* getScreen(void);
	bool init(void);
	void deinit(void);
	void setStatsBox(StatsBox* theStatsBox);
	StatsBox* getStatsBox(void);

	// The game loop
	void mainGameLoop(void);

	void quit(void);
	DMASpriteGroup* getSpriteGroup(int layer);
	vector<DMASprite*> spriteCollide(DMASprite* collideWith,
			int collideGroupIndex);
	vector<bool> getPressed(void);
};

#endif /* GAME_H_ */
