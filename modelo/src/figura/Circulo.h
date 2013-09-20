/*
 * Circulo.h
 *
 *  Created on: 04/09/2013
 *      Author: jonathan
 */

#ifndef CRICULO_H_
#define CRICULO_H_

#include "Figura.h"
#include "Rotador.h"
class Circulo: public Figura {
private:
	float radio;
public:
	Circulo();
	Circulo(float, float, Rotador *, float);
	virtual ~Circulo();
	bool contacto(float,float);
	bool contieneCentro(Posicionable* cuadrado);
	float getRadio() const;
	void setRadio(float radio);
	void acept(VisitorFigura*);
	float getAlto() const ;
	float getAncho() const;

};

#endif /* CRICULO_H_ */
