/*
 * Upgrade.cpp
 *
 *  Created on: 24/06/2013
 *      Author: yuri
 */

#include "Upgrade.h"

Upgrade::Upgrade() {
	// TODO Auto-generated constructor stub
	xVel = -2;
}

Upgrade::Upgrade(int x , int y):Entity("upgrade.png", x, y) {
	//Something here
	xVel = -4;
	type = ENTITY_UPGRADE;
}
Upgrade::~Upgrade() {
	// TODO Auto-generated destructor stub
}

void Upgrade::setXVel(int xVel) {
	this->xVel = -4;
}

void Upgrade::setYVel(int yVel) {
	this->yVel = 0;
}

void Upgrade::move(int screenWidth, int screenHeight) {
	x+=xVel;
	y+=yVel;
    //If the dot went too far to the left or right
    Box.x = x;
    //If the dot went too far up or down
    Box.y = y;
}

bool Upgrade::isUpgrade() {
	return true;
}
