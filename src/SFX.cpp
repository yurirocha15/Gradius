/*
 * SFX.cpp
 *
 *  Created on: 27/06/2013
 *      Author: yuri
 */

#include "SFX.h"

SFX::SFX() {
	// TODO Auto-generated constructor stub
	type = 0;
	Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
}

SFX::~SFX() {
	// TODO Auto-generated destructor stub
    Mix_CloseAudio();
}

void SFX::loadFile(string path) {

}

void SFX::playSound() {

}
