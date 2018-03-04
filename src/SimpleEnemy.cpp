/*
 * SimpleEnemy.cpp
 *
 *  Created on: 28/05/2013
 *      Author: jhonantans
 */

#include "SimpleEnemy.h"

SimpleEnemy::SimpleEnemy(){
	xVel = 3;
	yVel = 6;
	Uint32 colorkey = SDL_MapRGB( sprite->format, 255, 255 ,255);
	SDL_SetColorKey( sprite, SDL_SRCCOLORKEY, colorkey );
}

SimpleEnemy::SimpleEnemy(int x, int y):Enemy("enemy1.png", x, y){
	xVel = 3;
	yVel = 6;
	Uint32 colorkey = SDL_MapRGB( sprite->format, 255, 255, 255);
	SDL_SetColorKey( sprite, SDL_SRCCOLORKEY, colorkey );
}

SimpleEnemy::~SimpleEnemy() {
	// TODO Auto-generated destructor stub
}

void SimpleEnemy::shoot(){

}


void SimpleEnemy::move(int screenWidth, int screenHeight){

	x -= xVel;
	y += yVel;

	if ((y < 0) || ((y + height) > (screenHeight - 60)))
	{
		y -= yVel;
		yVel = -yVel;
	}
	Box.x = x;
	Box.y = y;

}
