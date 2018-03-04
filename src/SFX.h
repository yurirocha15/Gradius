/*
 * SFX.h
 *
 *  Created on: 27/06/2013
 *      Author: yuri
 */

#ifndef SFX_H_
#define SFX_H_
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include <iostream>

using namespace std;

class SFX {
private:
	int type;
public:
	SFX();
	virtual ~SFX();
	virtual void loadFile(string);
	virtual void playSound();
};

#endif /* SFX_H_ */
