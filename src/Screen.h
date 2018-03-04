/*
 * Screen.h
 *
 *  Created on: 27/05/2013
 *      Author: jhonantans
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include "Background.h"
#include "Sprite.h"

class Screen {

public:
	Background background;
	int screenWidth, screenHeight;
	bool windowed;
	SDL_Surface* screen;

	Screen(string backgorund_path);
	void setScreenWidth(int);
	void setScreenHeight(int);
	int getScreenWidth();
	int getScreenHeight();
	void showScreen();
	void fullscreen();
	virtual ~Screen();
};

#endif /* SCREEN_H_ */
