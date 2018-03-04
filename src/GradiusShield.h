/*
 * GradiusShield.h
 *
 *  Created on: 27/06/2013
 *      Author: yuri
 */

#ifndef GRADIUSSHIELD_H_
#define GRADIUSSHIELD_H_

#include "Entity.h"

class GradiusShield: public Entity {
private:
	int lastAnimTime;
	void setImg();
public:
	GradiusShield();
	GradiusShield(int, int);
	virtual ~GradiusShield();
	void move(int, int);
	bool onAnimation(Timer);

};

#endif /* GRADIUSSHIELD_H_ */
