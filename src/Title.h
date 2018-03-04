/*
 * Title.h
 *
 *  Created on: 28/05/2013
 *      Author: jhonantans
 */

#ifndef TITLE_H_
#define TITLE_H_

#include "Screen.h"
#include "Button.h"

class Title: public Screen {
public:
	Event event;
	Button NewGame, Load, Quit;
	Title();
	int TitleLoop();
	void HandleOptions();
	virtual ~Title();
};

#endif /* TITLE_H_ */
