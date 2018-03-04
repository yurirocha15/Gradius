/*
 * StringInput.cpp
 *
 *  Created on: 06/06/2013
 *      Author: yuri
 */

#include "StringInput.h"

StringInput::StringInput() {
	// TODO Auto-generated constructor stub
    //Initialize the string
    str = "";

    //Enable Unicode
    SDL_EnableUNICODE( SDL_ENABLE );
}

StringInput::~StringInput() {
	// TODO Auto-generated destructor stub
    //Disable Unicode
    SDL_EnableUNICODE( SDL_DISABLE );
}

void StringInput::handleInput() {
    //If a key was pressed
    if( event.EventType() == SDL_KEYDOWN )
    {
        //Keep a copy of the current version of the string
    	string temp = str;

        //If the string less than maximum size
        if( str.length() <= 3 )
        {
            //If the key is a space
            if( event.EventKeyUnicode() == (Uint16)' ' )
            {
                //Append the character
                str += (char)event.EventKeyUnicode();
            }
            //If the key is a number
            else if( ( event.EventKeyUnicode() >= (Uint16)'0' ) && ( event.EventKeyUnicode() <= (Uint16)'9' ) )
            {
                //Append the character
                str += (char)event.EventKeyUnicode();
            }
            //If the key is a uppercase letter
            else if( ( event.EventKeyUnicode() >= (Uint16)'A' ) && ( event.EventKeyUnicode() <= (Uint16)'Z' ) )
            {
                //Append the character
                str += (char)event.EventKeyUnicode();
            }
            //If the key is a lowercase letter
            else if( ( event.EventKeyUnicode() >= (Uint16)'a' ) && ( event.EventKeyUnicode() <= (Uint16)'z' ) )
            {
                //Append the character
                str += (char)event.EventKeyUnicode();
            }
        }

        //If backspace was pressed and the string isn't blank
        if( ( event.EventKey() == SDLK_BACKSPACE ) && ( str.length() != 0 ) )
        {
            //Remove a character from the end
            str.erase( str.length() - 1 );
        }

        //If the string was changed
        if( str != temp )
        {
            //Render a new text surface
            setText(str.c_str());
        }
    }
}

