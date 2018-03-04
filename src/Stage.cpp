/*
 * Stage.cpp
 *
 *  Created on: 27/05/2013
 *      Author: jhonantans
 */

#include "Stage.h"

Stage::Stage(): Screen("Stage1.gif") {
	SDL_WM_SetCaption( "Gradius - Stage 1", NULL );
}

Stage::~Stage() {
	// TODO
}

void Stage::options(){

}
