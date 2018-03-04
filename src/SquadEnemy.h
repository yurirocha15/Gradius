/*
 * SquadEnemy.h
 *
 *  Created on: 27/05/2013
 *      Author: raphael
 */

#ifndef SQUADENEMY_H_
#define SQUADENEMY_H_

#include "Enemy.h"
#include "Shoot.h"
#include"Simple.h"

class SquadEnemy: public Enemy, public Shoot {
private:
	int lastFireTime;
	Simple *tiro;
public:
	SquadEnemy();
	SquadEnemy(int, int);
	virtual ~SquadEnemy();
	void shoot(Timer, list<Entity*>*);
	void move(int, int);
};

#endif /* SQUADENEMY_H_ */
