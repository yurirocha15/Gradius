/*
 * WinScreen.cpp
 *
 *  Created on: 27/05/2013
 *      Author: jhonantans
 */

#include "WinScreen.h"

WinScreen::WinScreen():Screen("end_screen.png") {
	Event event;
	bool quit = false;
	// TODO
	background.show(screen);
	showScreen();
	while(!quit){
		if(event.ThereIsEvent()){
			if(event.EventType() == SDL_QUIT){
				quit = true;
			}
		}
	}

}

WinScreen::~WinScreen() {
	// TODO
}

void WinScreen::set_namePlayer(string name){
	name_player = name;
}

void WinScreen::save_score(int score){
	//TODO Function to save the best scores in a database.
}

void WinScreen::show_scores(){
	//TODO Show the best scores until now.
}
