/*
 * SimpleEnemy.h
 *
 *  Created on: 28/05/2013
 *      Author: jhonantans
 */

#ifndef SIMPLEENEMY_H_
#define SIMPLEENEMY_H_

#include "Enemy.h"

class SimpleEnemy: public Enemy {
public:
	SimpleEnemy();
	SimpleEnemy(int, int);
	virtual ~SimpleEnemy();
	void shoot();
	void move(int, int);
};

#endif /* SIMPLEENEMY_H_ */
