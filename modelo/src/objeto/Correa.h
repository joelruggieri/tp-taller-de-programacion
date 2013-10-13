/*
 * Correa.h
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#ifndef CORREA_H_
#define CORREA_H_

#include "Objeto.h"
#include "Engranaje.h"
class Correa: public Objeto {
public:
	Correa(float x, float y);
	virtual ~Correa();
	void crearFisica(b2World* w, b2Body* ground);
	void crearLazo(Engranaje * a, Engranaje* b, b2World* w);
	b2RevoluteJoint* getJointATierra();
	void setInicio(b2Vec2);
	void setFin(b2Vec2);
private:
	Engranaje* engranajeA;
	Engranaje* engranajeB;
	b2Vec2 inicio;
	b2Vec2 fin;

};

#endif /* CORREA_H_ */
