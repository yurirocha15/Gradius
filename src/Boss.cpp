/*
 * Boss.cpp
 *
 *  Created on: 27/05/2013
 *      Author: raphael
 */

#include "Boss.h"

Boss::Boss(){
	life = 15;
	type = ENTITY_BOSS;
	moveType = rand()%300;
	moveDirection = 1;
	yVel = 8;
	xVel = 10;
	lastFireTime = 0;
}

Boss::Boss(int x, int y): Enemy("Boss.png", x, y){
	life = 20;
	type = ENTITY_BOSS;
	moveType = rand()%300;
	moveDirection = 1;
	yVel = 8;
	xVel = 10;
	lastFireTime = 0;
}

Boss::~Boss() {
	// TODO Auto-generated destructor stub
}

void Boss::shoot(Timer globalTime, list<Entity*>* enemyList){
	if(lastFireTime + 1000 < globalTime.get_ticks()) {
		lastFireTime = globalTime.get_ticks();
		Bullet* tiro = new Double("BossShoot2.png", (this->x + 130), (this->y + 10), false);
		tiro->setXVel(12);
		enemyList->push_back(tiro);
		tiro->instanceCount();
		tiro->soundShoot();

		tiro = new Simple("BossShoot1.png", (this->x + 95), (this->y + 55), false);
		tiro->setXVel(12);
		enemyList->push_back(tiro);
		tiro->instanceCount();
		tiro->soundShoot();

		tiro = new Simple("BossShoot1.png", (this->x - 2), (this->y + 100), false);
		tiro->setXVel(12);
		enemyList->push_back(tiro);
		tiro->instanceCount();
		tiro->soundShoot();

		tiro = new Double("BossShoot2.png", (this->x + 10), (this->y + 150), false);
		tiro->setXVel(12);
		enemyList->push_back(tiro);
		tiro->instanceCount();
		tiro->soundShoot();
	}
}

void Boss::move(int screenWidth, int screenHeight){
	if(moveType == 100){
		if(moveType2(screenWidth, screenHeight)){
			moveType = rand()%300;
		}
	}
	else {
		moveType1(screenWidth, screenHeight);
			moveType = rand()%300;
	}
	cout << Box.x << " " << Box.y << endl << Box.w << " " << Box.h << endl;
	Box.x = x;
	Box.y = y;
}

void Boss::moveType1(int screenWidth, int screenHeight){
	y += yVel;
	if ((y < 40) || ((y + height) > (screenHeight - 40)))
	{
		y -= yVel;
		yVel = -yVel;
	}
}

bool Boss::moveType2(int screenWidth, int screenHeight){
	x -= xVel*moveDirection;

	if (x < 50) {
		moveDirection *= -1;
	}

	if (x > screenWidth - 290) {
		x += xVel*moveDirection;
		x -= 20;
		moveDirection *= -1;
		return true;
	}
	return false;
}

void Boss::beDamaged(int damage) {
	this->life -= damage;
	cout<<life<<endl;
}
