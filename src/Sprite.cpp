/*
 * Sprite.cpp
 *
 *  Created on: 26/05/2013
 *      Author: jhonantans
 */

#include "SDL/SDL_image.h"
#include "Sprite.h"

Sprite::Sprite() {
	x = 0;
	y = 0;
	sprite = NULL;
	width = 0;
	height = 0;
	pos = 0;
}

Sprite::Sprite(string path) {
	sprite = IMG_Load(path.c_str());
	animate.push_back(sprite);
	this->x = 0;
	this->y = 0;
	width = sprite->w;
	height = sprite->h;
	pos = 0;
}

Sprite::Sprite(string path, int x, int y) {
	sprite = IMG_Load(path.c_str());
	animate.push_back(sprite);
	this->x = x;
	this->y = y;
	width = sprite->w;
	height = sprite->h;
	pos = 0;
}

Sprite::Sprite(vector<string> paths, int x, int y){
	vector<string>::iterator it;
	for (it = paths.begin(); it != paths.end(); ++it) {
		sprite = IMG_Load((*it).c_str());
		animate.push_back(sprite);
	}
	this->x = x;
	this->y = y;
	width = sprite->w;
	height = sprite->h;
	pos = 0;
}

void Sprite::show(int posX, int posY, SDL_Surface* screen, SDL_Rect* clip){
	SDL_Rect offset;
	offset.x = posX;
	offset.y = posY;
	SDL_BlitSurface(animate[pos], clip, screen, &offset);
}

void Sprite::show(SDL_Surface* screen, SDL_Rect* clip){
	SDL_Rect offset;
	offset.x = this->x;
	offset.y = this->y;
	SDL_BlitSurface(animate[pos], clip, screen, &offset);
}

void Sprite::load(string path){
//	SDL_Surface* temp;
//	temp = IMG_Load(path.c_str());
	sprite = IMG_Load(path.c_str()); // SDL_DisplayFormat(temp);
	animate.push_back(sprite);
//	SDL_FreeSurface(temp);
	width = sprite->w;
	height = sprite->h;
}

void Sprite::load(vector<string> paths, int n) {
	for (int i = 0; i < n-1; ++i) {
		sprite = IMG_Load(paths[i].c_str());
		animate.push_back(sprite);
	}
	width = animate[0]->w;
	height = animate[0]->h;
}
void Sprite::setX(int x){
	this->x = x;
}

void Sprite::setY(int y){
	this->y = y;
}

int Sprite::getX(){
	return x;
}

int Sprite::getY() {
	return y;
}

void Sprite::setWidth(int width){
	this->width = width;
}

void Sprite::setHeight(int height){
	this->height = height;
}

int Sprite::getWidth(){
	return width;
}

int Sprite::getHeight(){
	return height;
}

void Sprite::setAnimationPos(int pos){
	this->pos = pos;
}

Sprite::~Sprite() {
	SDL_FreeSurface(sprite);
}
