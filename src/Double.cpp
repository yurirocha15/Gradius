/*
 * Double.cpp
 *
 *  Created on: 26/05/2013
 *      Author: yuri
 */

#include "Double.h"

Double::Double(int x, int y, bool ally): Bullet("tiro2.png", x, y, ally){
	xVel = 12;
	life = 2;
	sound.loadFile("bullet2.wav");
	}

Double::Double(string path, int x, int y, bool ally): Bullet(path, x, y, ally) {
	// TODO Auto-generated constructor stub
	xVel = 12;
	life = 2;
	sound.loadFile("bullet2.wav");
}

Double::~Double() {
	// TODO Auto-generated destructor stub
}
