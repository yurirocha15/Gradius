/*
 * Simple.cpp
 *
 *  Created on: 26/05/2013
 *      Author: yuri
 */

#include "Simple.h"

Simple::Simple(int x, int y, bool ally): Bullet("tiro1.png", x, y, ally) {
	if(ally == true)
			xVel = 12;
		else
			xVel = -10;
	Uint32 colorkey = SDL_MapRGB( sprite->format, 0, 0, 0);
	SDL_SetColorKey( sprite, SDL_SRCCOLORKEY, colorkey );
	sound.loadFile("bullet1.wav");
}

Simple::Simple(string path, int x, int y, bool ally): Bullet(path, x, y, ally) {
	// TODO Auto-generated constructor stub
	if(ally == true)
			xVel = 12;
		else
			xVel = -10;
	Uint32 colorkey = SDL_MapRGB( sprite->format, 0, 0, 0);
	SDL_SetColorKey( sprite, SDL_SRCCOLORKEY, colorkey );
	sound.loadFile("bullet1.wav");
}

Simple::~Simple() {

}
