/*
 * SquadEnemy.cpp
 *
 *  Created on: 27/05/2013
 *      Author: raphael
 */

#include "SquadEnemy.h"

SquadEnemy::SquadEnemy(){
	cout <<"lol1";
	xVel = 10;
	yVel = 0;
	life = 2;
	//Uint32 colorkey = SDL_MapRGB( sprite->format, 255, 255, 255);
	cout << "lol1.5";
	//SDL_SetColorKey( sprite, SDL_SRCCOLORKEY, colorkey );
	cout << "lol2";
	lastFireTime = 0;
	tiro = NULL;
	sound.loadFile("GradiusExplosion.wav");

}

SquadEnemy::SquadEnemy(int x, int y):Enemy("enemy2.png", x, y){
	cout << "lol 3";
	xVel = 10;
	yVel = 0;
	life = 2;
	Uint32 colorkey = SDL_MapRGB( sprite->format, 0xFF, 0xFF, 0xFF);
	SDL_SetColorKey( sprite, SDL_SRCCOLORKEY, colorkey );
	lastFireTime = 0;
	tiro = NULL;
	sound.loadFile("GradiusExplosion.wav");

}

SquadEnemy::~SquadEnemy() {
	// TODO Auto-generated destructor stub
}

void SquadEnemy::shoot(Timer globalTime, list<Entity*>* enemyList) {
	//TODO Macros, Factory method, Generate Programming C++
	if(lastFireTime + 300 < globalTime.get_ticks()) {
		lastFireTime = globalTime.get_ticks();
		cout << "bino";
		tiro = new Simple("tiro1.png", (this->x + this->width + 2), (this->y + this->height/2), false);
		enemyList->push_back(tiro);
		tiro->instanceCount();
		tiro->soundShoot();

	}
}

void SquadEnemy::move(int a, int b){
	x -= xVel;
	Box.x = x;
	Box.y = y;
}
