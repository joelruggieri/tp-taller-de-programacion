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
	BolaBoliche();
	BolaBoliche(float x, float y, float radio);
	virtual ~BolaBoliche();
	BolaBoliche(const BolaBoliche& figura);
	float getRadio();
	void crearFisica();
	void acept(VisitorFigura*);
	float getRadio() const;
	void setRadio(float radio);
	void recibirImpacto(b2Vec2 direccion);
private:
	float radio;
};

#endif /* BOLABOLICHE_H_ */
