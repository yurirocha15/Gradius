/*
 * Bullet.cpp
 *
 *  Created on: 26/05/2013
 *      Author: yuri
 */

#include "Bullet.h"

Bullet::Bullet() {
	xVel = 8;
	yVel = 0;
	this->ally = true;
	type = ENTITY_BULLET;
}

Bullet::Bullet(string path, int x, int y, bool ally): Entity(path, x, y) {
	// TODO Auto-generated constructor stub
	xVel = 8;
	yVel = 0;
	this->ally = ally;
	type = ENTITY_BULLET;
}

Bullet::~Bullet() {
	// TODO Auto-generated destructor stub
	amount -= 1;
}

void Bullet::setAlly(bool ally) {
	this->ally = ally;
}

bool Bullet::getAlly() {
	return ally;
}

void Bullet::instanceCount() {
	amount += 1;
}

int Bullet::getAmount() {
	return amount;
}


void Bullet::move (int screenHeight, int screenWidth) {

	//Move the dot left or right
	if (ally)
	{
		x += xVel;
	}

	else
	{
		x -= xVel;
	}

    //If the dot went too far to the left or right
    Box.x = x;

    //Move the dot up or down
    y += yVel;

    //If the dot went too far up or down
    Box.y = y;

}

void Bullet::Save(ofstream& savefile){
	savefile << x << "\n";
	savefile << y << "\n";
	savefile << xVel << "\n";
	savefile <<  yVel << "\n";
	savefile << life << "\n";
	savefile << ally << "\n";
}

void Bullet::Load(ifstream& savefile){
	savefile >> xVel;
	savefile >>  yVel;
	savefile >> life;
	savefile >> ally;
}

void Bullet::soundShoot() {
	sound.playSound();
}

int Bullet::amount = 0;
