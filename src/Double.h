/*
 * Double.h
 *
 *  Created on: 26/05/2013
 *      Author: yuri
 */

#ifndef DOUBLE_H_
#define DOUBLE_H_

#include "Bullet.h"

class Double: public Bullet {
public:
	Double(int x, int y, bool ally);
	Double(string path, int, int, bool);
	virtual ~Double();
};

#endif /* DOUBLE_H_ */
