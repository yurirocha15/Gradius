/*
 * Button.cpp
 *
 *  Created on: 27/06/2013
 *      Author: jhonantans
 */

#include "Button.h"

Button::Button() {
		// TODO Auto-generated constructor stub
	buttonBox.x = 0;
	buttonBox.y = 0;
	buttonBox.w = 0;
	buttonBox.h = 0;
	click = false;
}

Button::Button( int x, int y, int w, int h )
{
    //Set the button's attributes
    buttonBox.x = x;
    buttonBox.y = y;
    buttonBox.w = w;
    buttonBox.h = h;
    click = false;
}

Button::~Button() {
	// TODO Auto-generated destructor stub
}

void Button::setX(int x){
	buttonBox.x = x;
	buttonImg.setX(x);
}

void Button::setY(int y){
	buttonBox.y = y;
	buttonImg.setY(y);
}

void Button::setPosition(int x, int y){
	buttonBox.x = x;
	buttonBox.y = y;
	buttonImg.setX(x);
	buttonImg.setY(y);
}

bool Button::handle_events(Event event)
{
    //If a mouse button was pressed
    if( event.EventType() == SDL_MOUSEBUTTONDOWN ){

        //If the left mouse button was pressed
        if( event.EventButton() == SDL_BUTTON_LEFT ){
        	cout << "Event Type = SDL_MouseButtonDown!" << endl;
        	mouseBox = event.MousePosition();
            //If the mouse is over the button
            if( ( mouseBox.x > buttonBox.x ) && ( mouseBox.x < buttonBox.x + buttonBox.w )){
            	if(( mouseBox.y > buttonBox.y ) && ( mouseBox.y < buttonBox.y + buttonBox.h ) ){
                //Set the button sprite
            		click = true;
            		 return true;
            	}
            }
        }
    }

    //If a mouse button was released
    if( event.EventButton() == SDL_MOUSEBUTTONUP ){
    	click = false;
    }
    return false;
}

void Button::setImg(string path){
	buttonImg.load(path);
	buttonImg.setX(buttonBox.x);
	buttonImg.setY(buttonBox.y);
	buttonBox.w = buttonImg.getWidth();
	buttonBox.h = buttonImg.getHeight();
}

bool Button::isClicked(){
	return click;
}
