/*
 * Event.h
 *
 *  Created on: 27/05/2013
 *      Author: yuri
 */

#ifndef EVENT_H_
#define EVENT_H_

#include "SDL/SDL.h"

class Event {
private:
	SDL_Event event;
public:
	Event();
	virtual ~Event();
	bool ThereIsEvent();
	Uint8 EventType();
	Uint8 EventButton();
	SDL_Rect MousePosition();
	SDLKey EventKey();
	Uint16 EventKeyUnicode();
};

#endif /* EVENT_H_ */
