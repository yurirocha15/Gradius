/*
 * GameOver.cpp
 *
 *  Created on: 16/07/2013
 *      Author: jhonantans
 */

#include "GameOver.h"

GameOver::GameOver() : Screen("gameover_screen.png"){
	// TODO Auto-generated constructor stub
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

GameOver::~GameOver() {
	// TODO Auto-generated destructor stub
}

