/*
 * Enemy.h
 *
 *  Created on: 27/05/2013
 *      Author: raphael
 */

#ifndef ENEMY_H_
#define ENEMY_H_

#include "Entity.h"
using namespace std;


class Enemy: public Entity {

	public:
	Enemy();
	Enemy(string,int, int);
	bool onAnimation(Timer);
	int static instanceCount;
	void Save(ofstream& savefile);
	void Load(ifstream& savefile);
	virtual ~Enemy();

private:

	bool isDead;
	int lastAnimTime;
	void setImg();
	void instancesCount();

};

#endif /* ENEMY_H_ */
