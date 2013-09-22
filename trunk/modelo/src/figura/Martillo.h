/*
 * Martillo.h
 *
 *  Created on: 20/09/2013
 *      Author: joel
 */

#ifndef MARTILLO_H_
#define MARTILLO_H_
#include "Cuadrado.h"
#include "Rotador.h"


class Martillo: public Cuadrado {
public:
	Martillo();
	Martillo(float, float,Rotador*, float, float);
	virtual ~Martillo();
	void acept(VisitorFigura *visitor);
};

#endif /* MARTILLO_H_ */
