//============================================================================
// Name        : EpicStory.cpp
// Author      : Diwant Vaidya
// Version     :
// Copyright   : 2010 Diwant Vaidya
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "DMAGame.h"
#include "DMASprite.h"
#include "DMASpriteGroup.h"
// For the parallax background
#include "Road.h"
#include "Trees.h"
#include "Sky.h"
#include "BackgroundSprite.h"
// For animation
#include "Warrior.h"
#include "EnemySpawner.h"
// For the stats box/scoreboard
#include "Scoreboard.h"
#include "Heart.h"
#include "Score.h"
#include "StatsBox.h"
// My background music
#include "BackgroundMusic.h"

int main(int argc, char **argv) {
	if (DMAGame::getInstance().init()) {
		// Backgrounds
		DMAGame::getInstance().getSpriteGroup(0)->addSprite(new BackgroundSprite("snow.png", 0, 1));
		DMAGame::getInstance().getSpriteGroup(0)->addSprite(new BackgroundSprite("ledge.png", 450, 4));
		// Character
		DMAGame::getInstance().getSpriteGroup(1)->addSprite(new Warrior("Kenji", 200, 490));
		// Zombies
		DMAGame::getInstance().getSpriteGroup(2)->addSprite(new EnemySpawner());
		// Scoring stuff
		DMAGame::getInstance().getSpriteGroup(4)->addSprite(new Scoreboard());
		DMAGame::getInstance().getSpriteGroup(4)->addSprite(new Heart());
		DMAGame::getInstance().getSpriteGroup(4)->addSprite(new Score());
		DMAGame::getInstance().setStatsBox(new StatsBox());
		// music
		DMAGame::getInstance().getSpriteGroup(0)->addSprite(new BackgroundMusic());
		// done adding stuff
		DMAGame::getInstance().mainGameLoop();
		DMAGame::getInstance().deinit();

	}
	cout << "Game Over." << endl;
	return 0;
}
