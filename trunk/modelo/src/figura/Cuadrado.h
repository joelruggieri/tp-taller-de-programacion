/*
 * Cuadrado.h
 *
 *  Created on: 04/09/2013
 *      Author: jonathan
 */

#ifndef CUADRADO_H_
#define CUADRADO_H_

#include "Figura.h"

class Cuadrado: public Figura {
public:
	Cuadrado();
	virtual ~Cuadrado();
	bool contacto(float,float);
	bool contieneCentro(Figura* cuadrado);
};

#endif /* CUADRADO_H_ */
