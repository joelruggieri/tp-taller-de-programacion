/*
 * ObjetoCualquiera.h
 *
 *  Created on: 01/10/2013
 *      Author: jonathan
 */

#ifndef OBJETOCUALQUIERA_H_
#define OBJETOCUALQUIERA_H_

#include "src/objeto/Objeto.h"

#include "Box2D/Box2D.h"
class ObjetoCualquiera: public Objeto {
public:
	ObjetoCualquiera(float x, float y);
	virtual ~ObjetoCualquiera();
	void crearFisica(b2World *);
	void acept(VisitorFigura*);
};

#endif /* OBJETOCUALQUIERA_H_ */
