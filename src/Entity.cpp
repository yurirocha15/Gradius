/*
 * Entity.cpp
 *
 *  Created on: 26/05/2013
 *      Author: jhonantans
 */

#include "Entity.h"

Entity::Entity() {
	xVel = 0;
	yVel = 0;
	x = 0;
	y = 0;
	Box.x = 0;
	Box.y = 0;
	Box.w = 0;
	Box.h = 0;
	life = 1;
	type = 0;
}

Entity::Entity(string path, int x, int y): Sprite(path,x,y) {
	xVel = 0;
	yVel = 0;
	Box.x = x - 0.1*width;
	Box.y = y - 0.1*height;
	Box.w = 0.8*width;
	Box.h = 0.8*height;
	life = 1;
	type = 0;
}

Entity::Entity(vector<string> path, int x, int y): Sprite(path,x,y) {
	xVel = 0;
	yVel = 0;
	Box.x = x - 0.1*width;
	Box.y = y - 0.1*height;
	Box.w = 0.8*width;
	Box.h = 0.8*height;
	life = 1;
	type = 0;
}

Entity::~Entity() {
	// TODO Auto-generated destructor stub
}

void Entity::setXVel(int xVel){
	this->xVel = xVel;
}

void Entity::setYVel(int yVel){
	this->yVel = yVel;
}

void Entity::setBox(int box_x, int box_y, int box_w, int box_h){
	Box.x = box_x;
	Box.y = box_y;
	Box.w = box_w;
	Box.h = box_h;
}

void Entity::setLife(int life) {
	this->life = life;
}

int Entity::getXVel(){
	return xVel;
}

int Entity::getYVel(){
	return yVel;
}

SDL_Rect Entity::getBox(){
	return Box;
}

bool Entity::onAnimation(Timer timer){
	return true;
}

void Entity::move(int screenWidth, int screenHeight){

}

bool Entity::checkCollision(Entity *other) {
	SDL_Rect Box2 = other->getBox();

	int left1, left2;
    int right1, right2;
    int top1, top2;
    int bottom1, bottom2;

    //Calculate the sides of rect 1
      left1 = this->Box.x;
      right1 = this->Box.x + this->Box.w;
      top1 = this->Box.y;
      bottom1 = this->Box.y + this->Box.h;

      //Calculate the sides of rect 2
      left2 = Box2.x;
      right2 = Box2.x + Box2.w;
      top2 = Box2.y;
      bottom2 = Box2.y + Box2.h;

      //If any of the sides from A are outside of B
      if( bottom1 <= top2 )
      {
          return false;
      }

      if( top1 >= bottom2 )
      {
          return false;
      }

      if( right1 <= left2 )
      {
          return false;
      }

      if( left1 >= right2 )
      {
          return false;
      }

      //If none of the sides from A are outside B
      return true;
}


bool Entity::endScreen(int screenWidth, int screenHeight){

	if( ( x + width < 0 ) || ( x > screenWidth) )
    {
    	return true;
    }

    if( ( y + height < 0 ) || ( y > screenHeight) )
    {
        return true;
    }

    return false;
}

void Entity::beDamaged(int damage) {
		this->life -=damage;
}

bool Entity::isAlive() {
	if (life > 0)
		return true;
	return false;
}

int Entity::EntityType() {
	return type;
}

void Entity::addUpgrade() {
	//Nothing here
}

void Entity::Save(ofstream& savefile){
		//savefile << type;
		savefile << x << "\n";
		savefile << y << "\n";
		savefile << xVel << "\n";
		savefile <<  yVel << "\n";

}

void Entity::Load(ifstream& savefile){
	savefile >> xVel ;
	savefile >>  yVel;
}
