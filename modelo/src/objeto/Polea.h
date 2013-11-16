/*
 * Polea.h
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#ifndef POLEA_H_
#define POLEA_H_
#include "Box2D/Box2D.h"
#include "Objeto.h"

class Polea: public Objeto {
public:
	Polea();
	Polea(float x, float y, float radio);
	virtual ~Polea();
	Polea(const Polea& figura);
	float getRadio();
	void crearFisica();
	void acept(VisitorFigura*);
	float getRadio() const;
	void setRadio(float radio);
private:
	float radio;
};

#endif /* POLEA_H_ */