/*
 * Upgrade.h
 *
 *  Created on: 24/06/2013
 *      Author: yuri
 */

#ifndef UPGRADE_H_
#define UPGRADE_H_

#include "Entity.h"

class Upgrade: public Entity {
public:
	Upgrade();
	Upgrade(int, int);
	void move(int, int);
	void setXVel(int);
	void setYVel(int);
	bool isUpgrade();
	virtual ~Upgrade();
};

#endif /* UPGRADE_H_ */
