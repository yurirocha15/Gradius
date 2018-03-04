/*
 * Enemy.cpp
 *
 *  Created on: 27/05/2013
 *      Author: raphael
 */

#include "Enemy.h"

Enemy::Enemy() {
	// TODO Auto-generated constructor stub
	this->xVel = 0;
	this->yVel = 0;
	this->instancesCount();
	type = ENTITY_ENEMY;
	sound.loadFile("explosion.wav");
	setImg();
	lastAnimTime = 0;
	pos = 0;
	this->x = 0;
	this->y = 0;
	isDead = false;
}

Enemy::Enemy(string path, int x, int y):Entity(path, x, y) {
	this->xVel = 0;
	this->yVel = 0;
	this->instancesCount();
	type = ENTITY_ENEMY;
	sound.loadFile("explosion.wav");
	setImg();
	for (int i = 0; i < 10; ++i) {
		Uint32 colorkey = SDL_MapRGB( animate[i]->format, 0, 0, 0);
		SDL_SetColorKey( animate[i], SDL_SRCCOLORKEY, colorkey );
	}
	lastAnimTime = 0;
	pos = 0;
	isDead = false;
	// TODO Auto-generated constructor stub
}

void Enemy::setImg(){
	vector<string> temp;
	temp.push_back("explosao/Explosao1.png");
	temp.push_back("explosao/Explosao2.png");
	temp.push_back("explosao/Explosao3.png");
	temp.push_back("explosao/Explosao4.png");
	temp.push_back("explosao/Explosao5.png");
	temp.push_back("explosao/Explosao6.png");
	temp.push_back("explosao/Explosao7.png");
	temp.push_back("explosao/Explosao8.png");
	temp.push_back("explosao/Explosao9.png");
	temp.push_back("explosao/Explosao10.png");
	load(temp,10);
}

void Enemy::instancesCount(){
	this->instanceCount = this->instanceCount + 1;
}

bool Enemy::onAnimation(Timer globalTime){
	xVel = 0;
	yVel = 0;
	if (lastAnimTime == 0) {
		sound.playSound();
	}
	if(lastAnimTime + 50 < globalTime.get_ticks()) {
		lastAnimTime = globalTime.get_ticks();
		pos++;
		if(pos == 10)
			return true;
	}
	return false;
}

void Enemy::Save(ofstream& savefile){
	savefile << x << "\n";
	savefile << y << "\n";
	savefile << xVel << "\n";
	savefile <<  yVel << "\n";
}

void Enemy::Load(ifstream& savefile){
	savefile >> xVel ;
	savefile >>  yVel;
}

Enemy::~Enemy() {
	// TODO Auto-generated destructor stub
}

int Enemy::instanceCount = 0;
