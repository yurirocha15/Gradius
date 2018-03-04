/*
 * Message.h
 *
 *  Created on: 05/06/2013
 *      Author: yuri
 */

#ifndef MESSAGE_H_
#define MESSAGE_H_

#include <iostream>
#include "SDL/SDL_ttf.h"
using namespace std;

class Message {
private:
	SDL_Surface* text;
	int x, y, size;
	TTF_Font *font;
public:
	Message();
	virtual ~Message();
	void setText(string);
	void show(SDL_Surface*, SDL_Rect* clip = NULL);
	void show(SDL_Surface*, int, SDL_Rect* clip = NULL);
	void show(SDL_Surface*, int, int, SDL_Rect* clip = NULL);
	void setX(int);
	void setY(int);
	void setSize(int);
	SDL_Surface* getText();
};

#endif /* MESSAGE_H_ */
