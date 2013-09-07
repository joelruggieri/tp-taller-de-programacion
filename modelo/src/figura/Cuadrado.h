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
private:
	float ancho,alto;
public:
	Cuadrado(float, float, float, float);
	virtual ~Cuadrado();
	bool contacto(float,float);
	bool contieneCentro(Figura* cuadrado);
	bool isAdentro1D(float pos, float posCentro, float ancho);
};

#endif /* CUADRADO_H_ */
