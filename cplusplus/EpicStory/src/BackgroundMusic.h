/*
 * BackgroundMusic.h
 *
 *  Created on: Aug 6, 2010
 *      Author: DigitalMediaAcademy
 */

#ifndef BACKGROUNDMUSIC_H_
#define BACKGROUNDMUSIC_H_

#include "DMASprite.h"
#include "SDL/SDL_mixer.h"
class BackgroundMusic: public DMASprite {
public:
	BackgroundMusic();
	virtual ~BackgroundMusic();
private:
	Mix_Music *music;
};

#endif /* BACKGROUNDMUSIC_H_ */
