/*
 * Button.h
 *
 *  Created on: 27/06/2013
 *      Author: jhonantans
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include "Event.h"
#include "Sprite.h"

class Button {
private:
	bool click;
	SDL_Rect buttonBox, mouseBox;

public:
	Sprite buttonImg;
	Button();
	Button(int, int, int, int);

	virtual ~Button();

	void setX(int);
	void setY(int);
	void setPosition(int, int);

	bool handle_events(Event);
	void setImg(string);
	bool isClicked();
	//Shows the button on the screen
	//void show();
};

#endif /* BUTTON_H_ */
