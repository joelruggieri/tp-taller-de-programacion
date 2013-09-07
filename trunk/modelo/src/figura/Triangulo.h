/*
 * Triangulo.h
 *
 *  Created on: 06/09/2013
 *      Author: jonathan
 */

#ifndef TRIANGULO_H_
#define TRIANGULO_H_

#include "Figura.h"

class Triangulo: public Figura {
public:
	Triangulo(float,float);
	Triangulo();
	virtual ~Triangulo();
	bool contacto(float,float);
	bool contieneCentro(Figura* cuadrado);
};

#endif /* TRIANGULO_H_ */
