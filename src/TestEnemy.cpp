/*
 * TestEnemy.cpp
 *
 *  Created on: 01/06/2013
 *      Author: jhonantans
 */

#include "TestEnemy.h"

TestEnemy::TestEnemy(int x, int y) : Enemy ("testEnemy.png", x, y) {
	// TODO Auto-generated constructor stub
	xVel = 0;
	yVel = 0;
}

TestEnemy::~TestEnemy() {
	// TODO Auto-generated destructor stub
}

void TestEnemy::move(int posX, int posY){

	if(x<posX)
		x += xVel;
	else
		x -= xVel;

	if(y<posY)
		y += yVel;
	else
		y -= yVel;

	Box.x = x;
	Box.y = y;
}
