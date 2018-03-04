/*
 * Screen.cpp
 *
 *  Created on: 27/05/2013
 *      Author: jhonantans
 */

#include "Screen.h"

Screen::Screen(string path):background(path,3){
	screen = NULL;
	screenWidth = background.getWidth();
	screenHeight = background.getHeight();
	screen = SDL_SetVideoMode( screenWidth, screenHeight, 32, SDL_SWSURFACE | SDL_RESIZABLE );
	windowed = true;
}

Screen::~Screen() {
	// TODO Auto-generated destructor stub
}

void Screen::setScreenWidth(int screen_width){
	this->screenWidth = screen_width;
	screen = SDL_SetVideoMode( screen_width, screenHeight, 32, SDL_SWSURFACE | SDL_RESIZABLE );
}

void Screen::setScreenHeight(int screen_height){
	this->screenHeight = screen_height;
	screen = SDL_SetVideoMode( screenWidth, screen_height, 32, SDL_SWSURFACE | SDL_RESIZABLE );
}

int Screen::getScreenWidth(){
	return screenWidth;
}

int Screen::getScreenHeight(){
	return screenHeight;
}

void Screen::showScreen(){
	SDL_Flip(screen);
}

void Screen::fullscreen(){
	if(windowed){
		screen = SDL_SetVideoMode( screenWidth, screenHeight, 32, SDL_SWSURFACE | SDL_RESIZABLE | SDL_FULLSCREEN);
		windowed = false;
	}
	else{
		screen = SDL_SetVideoMode( screenWidth, screenHeight, 32, SDL_SWSURFACE | SDL_RESIZABLE | SDL_FULLSCREEN);
		windowed = true;
	}
}
