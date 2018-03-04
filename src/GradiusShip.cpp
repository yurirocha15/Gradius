/*
 * GradiusShip.cpp
 *
 *  Created on: 26/05/2013
 *      Author: yuri
 */

#include "GradiusShip.h"

template <class T>
class FactoryShoot{
public:
	void gradius_shoot(list<Entity*>* gradiusList, int x, int y){
		Bullet *tiro;
		tiro = new T(x, y, true);
		gradiusList->push_back(tiro);
		tiro->instanceCount();
		tiro->soundShoot();
	}
};

GradiusShip::GradiusShip(int x, int y): Entity("gradius.png", x, y) {
	life = 3;
	powerup = 0;
	upgrade = 0;
	shieldIsOn = false;
	observerShield = false;
	speedLevel = 0;
	speed = 0;
	Uint32 colorkey = SDL_MapRGB( sprite->format, 0, 0, 0);
	SDL_SetColorKey( sprite, SDL_SRCCOLORKEY, colorkey );
	lastFireTime = 0;
	bulletType = SIMPLE_BULLET;
	type = ENTITY_GRADIUS;
	sound.loadFile("GradiusExplosion.wav");
	shield = NULL;
}

GradiusShip::~GradiusShip() {
	// TODO Auto-generated destructor stub
	sound.playSound();
}

int GradiusShip::getLife() {
	return life;
}

void GradiusShip::setUpgrade(int value) {
	upgrade = value;
}

int GradiusShip::getUpgrade() {
	return upgrade;
}

void GradiusShip::setShield(bool observerShield) {
	this->observerShield = observerShield;
}

bool GradiusShip::shieldState() {
	return observerShield;
}

Entity* GradiusShip::getShield() {
	return shield;
}

void GradiusShip::destroyShield() {
	delete(shield);
	shield = NULL;
	shieldIsOn = false;
	observerShield = false;
}

void GradiusShip::move(int velX, int velY, int screenHeight, int screenWidth) {
	xVel = velX;
	yVel = velY;

	//Move the dot left or right
	if(xVel > 0)
	{
		xVel +=speed;
	}
	else if (xVel < 0 )
	{
		xVel-=speed;
	}
	x += xVel;

    //If the dot went too far to the left or right
    if( ( x < 0 ) || ( x + width > screenWidth ) )
    {
        //move back
        x -= xVel;
    }
    Box.x = x;
    //Move the dot up or down
    if(yVel > 0)
    {
    	yVel+=speed;
    }
	else if (yVel < 0 )
	{
		yVel-=speed;
	}
    y += yVel;

    //If the dot went too far up or down
    if( ( y < 40 ) || ( y + height > screenHeight - 40 ) )
    {
        //move back
        y -= yVel;
    }
    Box.y = y;
    if (shieldIsOn) {
    	shield->move(this->x + this->width/2 - shield->getWidth()/2, this->y + this->height/2 - shield->getHeight()/2);
    }
}

void GradiusShip::addUpgrade() {
	if (powerup < 2)
	{
		powerup++;
	}
	else
	{
		powerup = 0;
		upgrade++;
	}
	if(upgrade > 3)
	{
		upgrade = 1;
	}
}

void GradiusShip::activateUpgrade() {
	switch (upgrade) {
		case POWERUP_SPEED:
		{
			if(speedLevel < 5)
			{
				upgradeSpeed();
			}
			break;
		}
		case POWERUP_BULLET:
		{
			upgradeBullet();
			break;
		}
		case POWERUP_SHIELD:
		{
			upgradeShield();
			break;
		}
	}
	upgrade = POWERUP_NONE;
}

void GradiusShip::upgradeSpeed() {
	speedLevel++;
	speed = speedLevel;
}

void GradiusShip::upgradeBullet() {
	if (bulletType != DOUBLE_BULLET)
		bulletType = DOUBLE_BULLET;
}

void GradiusShip::upgradeShield() {
	shieldIsOn = true;
	observerShield = true;
	shield = new GradiusShield(this->x, this->y);
	shield->setX(this->x + this->width/2 - shield->getWidth()/2);
	shield->setX(this->y + this->height/2 - shield->getHeight()/2);
	shield->setLife(3);
}

void GradiusShip::shoot(Timer globalTime, list<Entity*>* gradiusList) {
	//TODO Macros, Factory method, Generate Programming C++
	if(lastFireTime + 250 < globalTime.get_ticks()) {
		lastFireTime = globalTime.get_ticks();
		int x = (this->x + this->width + 2);
		int y = (this->y + this->height/2);
		switch(bulletType){
		case SIMPLE_BULLET: FactoryShoot<Simple>fire1; fire1.gradius_shoot(gradiusList, x, y); break;
		case DOUBLE_BULLET: FactoryShoot<Double>fire2; fire2.gradius_shoot(gradiusList, x, y); break;
		}
	}
}

void GradiusShip::beDamaged(int damage) {
	this->life -= damage;
}

void GradiusShip::Save(ofstream& savefile){
	savefile << x << "\n";
	savefile << y << "\n";
	savefile << powerup << "\n";
	savefile << upgrade << "\n";
	savefile << observerShield << "\n";
	savefile << shieldIsOn << "\n";
	savefile << speedLevel << "\n";
	savefile << speed << "\n";
	savefile << bulletType << "\n";
}

void GradiusShip::Load(ifstream& savefile){
	int i;
	savefile >> powerup;
	savefile >> upgrade;
	savefile >> observerShield;
	savefile >> shieldIsOn;
	savefile >> speedLevel;
	savefile >> speed;
	savefile >> i;
	if(i==DOUBLE_BULLET){
		bulletType = DOUBLE_BULLET;
	}
	else{
		bulletType = SIMPLE_BULLET;
	}
	if(shieldIsOn) upgradeShield();
}
