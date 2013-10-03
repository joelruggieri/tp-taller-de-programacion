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
	GloboHelio(float x, float y,Rotador * rot, float radio) ;
	virtual ~GloboHelio();
	void crearFisica(b2World* world);
private:
	float radio;
};

#endif /* GLOBOHELIO_H_ */