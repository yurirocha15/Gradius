/*
 * Gradius.cpp
 *
 *  Created on: 27/05/2013
 *      Author: jhonantans
 */

#include "Controler.h"

bool init()
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }

    return true;
}

int main(){
	//TODO Main
	Controler GameControl;

//	bool quit = false;

	if(!init()){
		cout << "Unknown Problem!" << endl;
	}

	GameControl.GameLoop();
//	quit = GameControl.GameQuit();

	SDL_Quit();

	return 0;
}
