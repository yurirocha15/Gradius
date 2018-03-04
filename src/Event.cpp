/*
 * Event.cpp
 *
 *  Created on: 27/05/2013
 *      Author: yuri
 */

#include "Event.h"

Event::Event() {
	// TODO Auto-generated constructor stub

}

Event::~Event() {
	// TODO Auto-generated destructor stub
}

bool Event::ThereIsEvent() {
	return SDL_PollEvent(&event);
}

Uint8 Event::EventType() {
	return event.type;
}

Uint8 Event::EventButton(){
	return event.button.button;
}

SDL_Rect Event::MousePosition(){
	SDL_Rect box;
	box.x = event.button.x;
	box.y = event.button.y;
	return box;
}

SDLKey Event::EventKey() {
	return event.key.keysym.sym;
}

Uint16 Event::EventKeyUnicode() {
	return event.key.keysym.unicode;
}
