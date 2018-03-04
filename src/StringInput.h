/*
 * StringInput.h
 *
 *  Created on: 06/06/2013
 *      Author: yuri
 */

#ifndef STRINGINPUT_H_
#define STRINGINPUT_H_

#include "Message.h"
#include "Event.h"

class StringInput: public Message {
private:
	Event event;
	string str;
public:
	StringInput();
	virtual ~StringInput();
	void handleInput();
};

#endif /* STRINGINPUT_H_ */
