/*
 * Circulo.h
 *
 *  Created on: 04/09/2013
 *      Author: jonathan
 */

#ifndef CRICULO_H_
#define CRICULO_H_

#include "Figura.h"

class Circulo: public Figura {
private:
	float x,y,radio;
public:
	Circulo(float, float, float);
	virtual ~Circulo();
	bool contacto(float,float);
	bool contieneCentro(Figura* cuadrado);
};

#endif /* CRICULO_H_ */
