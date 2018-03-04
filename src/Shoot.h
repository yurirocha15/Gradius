/*
 * Shoot.h
 *
 *  Created on: 27/05/2013
 *      Author: raphael
 */

#ifndef SHOOT_H_
#define SHOOT_H_

#include "Timer.h"
#include "Entity.h"
#include <list>

class Shoot {
public:
	Shoot();
	virtual ~Shoot();
	virtual void shoot(Timer, list<Entity*>*) = 0;
};

#endif /* SHOOT_H_ */
