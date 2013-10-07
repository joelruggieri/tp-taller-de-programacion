/*
 * GloboHelio.h
 *
 *  Created on: 02/10/2013
 *      Author: ezequiel
 */

#ifndef GLOBOHELIO_H_
#define GLOBOHELIO_H_
#include "Box2D/Box2D.h"
#include "Objeto.h"

class GloboHelio : public Objeto {
public:
	GloboHelio(float x, float y, float radio) ;
	virtual ~GloboHelio();
	void crearFisica(b2World* world);
	void acept(VisitorFigura*);

private:
	float radio;
	Enganche* engancheBajo;
};

#endif /* GLOBOHELIO_H_ */
