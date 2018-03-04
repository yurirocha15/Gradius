/*
 * Background.cpp
 *
 *  Created on: 25/05/2013
 *      Author: jhonantans
 */

#include "Background.h"

Background::Background(string path, int xVel):Sprite(path) {
	this->xVel = xVel;
}

void Background::move(SDL_Surface* screen){
	//Scroll background
	x -= xVel;
	if( x <= -width ) {
		x = 0;
	}
	show(x,y,screen);
	show(x+width,y,screen);
}

void Background::setXVel(int xVel){
	this->xVel = xVel;
}
int Background::getXVel(){
	return xVel;
}

Background::~Background() {
	// TODO Auto-generated destructor stub
}
