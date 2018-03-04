/*
 * Entity.h
 *
 *  Created on: 26/05/2013
 *      Author: jhonantans
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#include"SDL/SDL.h"
#include<iostream>
#include"Timer.h"
#include"Sprite.h"
#include"Chunk.h"
#include <fstream>
#include<list>

using namespace std;

enum BulletType{
	SIMPLE_BULLET,
	DOUBLE_BULLET
};

class Entity: public Sprite{
protected:
	int xVel, yVel;
	int life;
	SDL_Rect Box;
	int type;
	Chunk sound;
	enum {
		ENTITY_GRADIUS = 0,
		ENTITY_SHIELD,
		ENTITY_BULLET,
		ENTITY_UPGRADE,
		ENTITY_ENEMY,
		ENTITY_BOSS,
	};

public:
	Entity();
	Entity(string, int, int);
	Entity(vector<string>, int, int);
	void setXVel(int);
	void setYVel(int);
	void setBox(int, int, int, int);
	void setLife(int);
	int getXVel();
	int getYVel();
	SDL_Rect getBox();
	bool checkCollision(Entity*);
	virtual bool onAnimation(Timer);
	virtual void move(int, int);
	bool endScreen(int, int);
	void beDamaged(int);
	bool isAlive();
	int EntityType();
	void virtual addUpgrade();
	virtual void Save(ofstream& savefile);
	virtual void Load(ifstream& savefile);
	virtual ~Entity();
};

#endif /* ENTITY_H_ */
