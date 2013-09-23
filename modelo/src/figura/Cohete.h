/*
 * Cohete.h
 *
 *  Created on: 21/09/2013
 *      Author: joel
 */

#ifndef COHETE_H_
#define COHETE_H_
#include "Cuadrado.h"
#include "Rotador.h"

class Cohete: public Cuadrado {
public:
	Cohete();
	Cohete(const Cohete& figura);
	Cohete(float x, float y,Rotador* rotador, float ancho, float alto);
	virtual ~Cohete();
	void acept(VisitorFigura* visitor);
};

#endif /* COHETE_H_ */
