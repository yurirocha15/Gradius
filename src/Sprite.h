/*
 * Sprite.h
 *
 *  Created on: 26/05/2013
 *      Author: jhonantans
 */

#ifndef SPRITE_H_
#define SPRITE_H_

#include<iostream>
#include<vector>
#include"SDL/SDL.h"
using namespace std;

class Sprite {

protected:
	SDL_Surface* sprite;
	vector<SDL_Surface*> animate;
	int x, y;
	int width, height;
	int pos;

public:
	Sprite();
	Sprite(string);
	Sprite(string, int, int);
	Sprite(vector<string>, int, int);
	void show(int, int, SDL_Surface*, SDL_Rect* clip = NULL);
	void show(SDL_Surface*, SDL_Rect* clip = NULL);
	void load(string);
	void load(vector<string>, int);
	void setX(int);
	void setY(int);
	int getX();
	int getY();
	void setWidth(int);
	void setHeight(int);
	int getWidth();
	int getHeight();
	void setAnimationPos(int);
	virtual ~Sprite();
};

#endif /* SPRITE_H_ */
