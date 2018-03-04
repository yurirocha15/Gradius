/*
 * Background.h
 *
 *  Created on: 25/05/2013
 *      Author: jhonantans
 */

#ifndef BACKGROUND_H_
#define BACKGROUND_H_

#include "Sprite.h"

class Background: public Sprite {
private:
	int xVel;
public:
	Background(string,int);
	void move(SDL_Surface*);
	void setXVel(int);
	int getXVel();
	virtual ~Background();
};

#endif /* BACKGROUND_H_ */
