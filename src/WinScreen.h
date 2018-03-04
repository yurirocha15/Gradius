/*
 * WinScreen.h
 *
 *  Created on: 27/05/2013
 *      Author: jhonantans
 */

#ifndef WINSCREEN_H_
#define WINSCREEN_H_

#include "Screen.h"
#include "Event.h"

class WinScreen: public Screen {
private:
	string name_player;
public:
	WinScreen();
	string get_namePlayer();
	void set_namePlayer(string);
	void save_score(int);
	void show_scores();

	virtual ~WinScreen();
};

#endif /* WINSCREEN_H_ */
