/*
 * BolaBoliche.h
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#ifndef BOLABOLICHE_H_
#define BOLABOLICHE_H_
#include "Box2D/Box2D.h"
#include "Objeto.h"

class BolaBoliche: public Objeto {
public:
	BolaBoliche(float x, float y, float radio);
	virtual ~BolaBoliche();
	void crearFisica(b2World *);
private:
	float radio;
};

#endif /* BOLABOLICHE_H_ */
