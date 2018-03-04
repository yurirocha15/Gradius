/*
 * GradiusShip.h
 *
 *  Created on: 26/05/2013
 *      Author: yuri
 */

#ifndef GRADIUSSHIP_H_
#define GRADIUSSHIP_H_

#include"SDL/SDL.h"
#include<iostream>
#include"GradiusShield.h"
#include"Entity.h"
#include"Simple.h"
#include"Bullet.h"
#include"Double.h"
#include"Timer.h"
#include<list>

using namespace std;

class GradiusShip: public Entity {

private:
	int powerup;
	int upgrade;
	bool observerShield;
	bool shieldIsOn;
	int speedLevel;
	int speed;
	int lastFireTime;
	Entity* shield;
	BulletType bulletType;
	enum {
		POWERUP_NONE = 0,
		POWERUP_SPEED,
		POWERUP_SHIELD,
		POWERUP_BULLET,
	};


public:
	GradiusShip(int, int);
	virtual ~GradiusShip();
	int getLife();
	void setUpgrade(int);
	int getUpgrade();
	void setShield(bool);
	bool shieldState();
	Entity* getShield();
	void move(int, int, int, int);
	void addUpgrade();
	void activateUpgrade();
	void upgradeSpeed();
	void upgradeBullet();
	void upgradeShield();
	void destroyShield();
	void shoot(Timer, list<Entity*>*);
	void beDamaged(int);
	void Save(ofstream& savefile);
	void Load(ifstream& savefile);
};

#endif /* GRADIUSSHIP_H_ */
