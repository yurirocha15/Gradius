/*
 * Bullet.h
 *
 *  Created on: 26/05/2013
 *      Author: yuri
 */

#ifndef BULLET_H_
#define BULLET_H_

#include "Entity.h"

class Bullet: public Entity {

protected:
	bool ally;
	static int amount;
public:
	Bullet();
	Bullet(string,int, int, bool);
	virtual ~Bullet();
	void setAlly(bool);
	bool getAlly();
	void instanceCount();
	int getAmount();
	void move(int, int);
	virtual void Save(ofstream& savefile);
	virtual void Load(ifstream& savefile);
	void soundShoot();

};

#endif /* BULLET_H_ */
