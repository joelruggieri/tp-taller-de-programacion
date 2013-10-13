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
private:
	b2Body* cuerpoEje;
	b2Body* cuerpoRueda;
	int radio;
protected:
	void crearLazo(b2Body*, b2World*);
};

#endif /* ENGRANAJE_H_ */
