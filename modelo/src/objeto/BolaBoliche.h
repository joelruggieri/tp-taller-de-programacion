/*
 * BolaBoliche.h
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#ifndef BOLABOLICHE_H_
#define BOLABOLICHE_H_

#include "Objeto.h"

class BolaBoliche: public Objeto {
public:
	BolaBoliche(float x, float y,Rotador * rot);
	virtual ~BolaBoliche();
};

#endif /* BOLABOLICHE_H_ */
