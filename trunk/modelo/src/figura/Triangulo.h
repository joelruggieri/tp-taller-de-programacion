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
private:
	float ancho,alto;
public:
	Triangulo();
	Triangulo(float, float, float, float);
	virtual ~Triangulo();
	bool contacto(float,float);
	bool contieneCentro(Posicionable* cuadrado);
	bool isAdentro1D(float pos, float posCentro, float ancho);
	void setAncho(float ancho);
	void setAlto (float alto);
	float getAncho();
	float getAlto();
	void acept(VisitorFigura*);
};

#endif /* TRIANGULO_H_ */
