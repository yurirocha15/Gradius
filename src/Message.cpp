/*
 * Message.cpp
 *
 *  Created on: 05/06/2013
 *      Author: yuri
 */

#include "Message.h"

Message::Message() {
	// TODO Auto-generated constructor stub
	text = NULL;
	x = 0;
	y = 0;
	size = 20;
	TTF_Init();
	font = TTF_OpenFont("g7gradius1_1byte.TTF", size);
}

Message::~Message() {
	// TODO Auto-generated destructor stub
	TTF_CloseFont(font);
	TTF_Quit();
}

void Message::setText(string text) {
	SDL_Color textColor = {255,255,255};
	this->text = TTF_RenderText_Solid( font, text.c_str(), textColor );
	if(this->text == NULL)
	{
		cout << "ERROR RENDER" << endl;
	}
}

void Message::show(SDL_Surface* screen, SDL_Rect* clip) {
	SDL_Rect offset;
	offset.x = this->x;
	offset.y = this->y;
	SDL_BlitSurface(text, clip, screen, &offset);
}

void Message::show(SDL_Surface* screen, int screenWidth, SDL_Rect* clip)
{
    //If the surface isn't blank
    if( text != NULL )
    {
        //Show the name]
    	SDL_Rect offset;
    	offset.x = (screenWidth - text->w )/2;
    	offset.y = this->y;
    	SDL_BlitSurface(text, clip, screen, &offset);
    }
}

void Message::show(SDL_Surface* screen, int screenWidth, int screenHeight, SDL_Rect* clip)
{
    //If the surface isn't blank
    if( text != NULL )
    {
        //Show the name]
    	SDL_Rect offset;
    	offset.x = (screenWidth - text->w )/2;
    	offset.y = ( screenHeight - text->h )/2;
    	SDL_BlitSurface(text, clip, screen, &offset);
    }
}

void Message::setX(int x){
	this->x = x;
}

void Message::setY(int y){
	this->y = y;
}

void Message::setSize(int size) {
	TTF_CloseFont(font);
	this->size = size;
	font = TTF_OpenFont("g7gradius1_1byte.TTF", this->size);
}

SDL_Surface* Message::getText() {
	return this->text;
}
