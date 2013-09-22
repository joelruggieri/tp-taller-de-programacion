/*
 * Rueda.h
 *
 *  Created on: 20/09/2013
 *      Author: joel
 */

#ifndef RUEDA_H_
#define RUEDA_H_
#include "Figura.h"
#include "Rotador.h"
#include "Circulo.h"

class Rueda: public Circulo {
public:
	Rueda();
	virtual ~Rueda();
	Rueda(float x, float y,Rotador * rotador, float radio);
	void acept(VisitorFigura *visitor);
};

#endif /* RUEDA_H_ */
