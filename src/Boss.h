/*
 * Boss.h
 *
 *  Created on: 27/05/2013
 *      Author: raphael
 */

#ifndef BOSS_H_
#define BOSS_H_

#include "Enemy.h"
#include "Shoot.h"
#include "Simple.h"
#include "Double.h"

class Boss: public Enemy, public Shoot {
private:
	int lastFireTime;
	int moveType;
	int moveDirection;
	void moveType1(int, int);
	bool moveType2(int, int);
public:
	Boss();
	Boss(int, int);
	virtual ~Boss();
	void shoot(Timer, list<Entity*>*);
	void move(int, int);
	void beDamaged(int);

};

#endif /* BOSS_H_ */
