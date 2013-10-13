/*
 * Engranaje.h
 *
 *  Created on: 11/10/2013
 *      Author: javier
 */

#ifndef ENGRANAJE_H_
#define ENGRANAJE_H_

#include "Objeto.h"

class Engranaje: public Objeto {
public:
	Engranaje(int x, int y, int radio);
	virtual ~Engranaje();
	void crearFisica(b2World * w, b2Body* ground);
	void acept(VisitorFigura* visitor);
	void crearFisicaEstaticaTemplate(b2World* m_world, b2Body* ground);
	void removerFisica(b2World * w);
	bool crearFisicaEstatica(b2World *w, b2Body* ground);
	b2RevoluteJoint * getJointATierra();
	b2Body * getDiscoGiro();

private:
	typedef Objeto super;
	b2Body* radioAccion;
	int radio;
	int direccion;
	b2RevoluteJoint * jointCuerpoTierra;
protected:
	void crearLazo(Engranaje*, b2World*);
};

#endif /* ENGRANAJE_H_ */
