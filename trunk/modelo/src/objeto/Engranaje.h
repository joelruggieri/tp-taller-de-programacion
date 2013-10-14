/*
 * Engranaje.h
 *
 *  Created on: 11/10/2013
 *      Author: javier
 */

#ifndef ENGRANAJE_H_
#define ENGRANAJE_H_

#include "Objeto.h"
enum DIRECCION {HORARIO, NULO, ANTIHORARIO};
class Engranaje: public Objeto {
public:
	Engranaje();
	Engranaje(const Engranaje & engranaje);
	Engranaje(float x, float, float radio);
	virtual ~Engranaje();
	void crearFisica(b2World * w, b2Body* ground);
	void acept(VisitorFigura* visitor);
	void crearFisicaEstaticaTemplate(b2World* m_world, b2Body* ground);
	void removerFisica(b2World * w);
	bool crearFisicaEstatica(b2World *w, b2Body* ground);
	b2RevoluteJoint* & getJointATierra();
	b2Body * getDiscoGiro();
	void modificarSentido();
private:
	typedef Objeto super;
protected:
	b2RevoluteJoint * jointCuerpoTierra;
	float radio;
	b2Body* radioAccion;
	DIRECCION direccion;
	void crearLazo(Engranaje*, b2World*);
};

#endif /* ENGRANAJE_H_ */
