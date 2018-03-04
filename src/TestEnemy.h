/*
 * TestEnemy.h
 *
 *  Created on: 01/06/2013
 *      Author: jhonantans
 */

#ifndef TESTENEMY_H_
#define TESTENEMY_H_

#include "Enemy.h"

class TestEnemy: public Enemy {
public:
	TestEnemy(int, int);
	void move(int, int);
	virtual ~TestEnemy();
};

#endif /* TESTENEMY_H_ */
