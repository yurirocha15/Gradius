/*
 * GradiusShield.cpp
 *
 *  Created on: 27/06/2013
 *      Author: yuri
 */

#include "GradiusShield.h"

GradiusShield::GradiusShield() {
	// TODO Auto-generated constructor stub
	type = ENTITY_SHIELD;
	life = 3;
	lastAnimTime = 0;
}

GradiusShield::GradiusShield(int x, int y){
	this->x = x;
	this->y = y;
	type = ENTITY_SHIELD;
	life = 3;
	setImg();
	lastAnimTime = 0;
}

GradiusShield::~GradiusShield() {
	// TODO Auto-generated destructor stub
}

void GradiusShield::move(int x, int y) {
	this->x = x;
	this->y = y;
	this->Box.x = x;
	this->Box.y = y;
}

bool GradiusShield::onAnimation(Timer globalTime) {
	if(lastAnimTime + 90 < globalTime.get_ticks()) {
		lastAnimTime = globalTime.get_ticks();
		pos++;
		if(pos == 12)
			pos = 0;
	}
	return true;
}

void GradiusShield::setImg(){
	vector<string> temp;
	temp.push_back("shield/shield1.png");
	temp.push_back("shield/shield2.png");
	temp.push_back("shield/shield3.png");
	temp.push_back("shield/shield4.png");
	temp.push_back("shield/shield5.png");
	temp.push_back("shield/shield6.png");
	temp.push_back("shield/shield7.png");
	temp.push_back("shield/shield8.png");
	temp.push_back("shield/shield9.png");
	temp.push_back("shield/shield10.png");
	temp.push_back("shield/shield11.png");
	temp.push_back("shield/shield12.png");
	temp.push_back("shield/shield13.png");

	load(temp,13);

}
