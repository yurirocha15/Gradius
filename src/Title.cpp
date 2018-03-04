/*
 * Title.cpp
 *
 *  Created on: 28/05/2013
 *      Author: jhonantans
 */

#include "Title.h"

Title::Title() : Screen("title_screen.png"), NewGame(560,410,170,40), Load(550,465,175,40), Quit(600,510,90,40){
	// TODO Auto-generated constructor stub
	background.show(screen);
	SDL_WM_SetCaption( "Title!", NULL );
}

Title::~Title() {
	// TODO Auto-generated destructor stub
}

int Title::TitleLoop(){
	showScreen();
	while(true){
		if(event.ThereIsEvent()){
			if(NewGame.handle_events(event)){
				cout << "New Game!" << endl;
				return 0;
			}
			if(Load.handle_events(event)){
				cout << "Load Game!" << endl;
				return 1;
			}
			if(Quit.handle_events(event)){
				cout << "Quit Game!" << endl;
				return 2;
			}
		}
	}
	return 0;
}

void Title::HandleOptions(){

}
