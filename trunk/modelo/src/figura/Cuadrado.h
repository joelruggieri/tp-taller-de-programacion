/*
 * Cuadrado.h
 *
 *  Created on: 04/09/2013
 *      Author: jonathan
 */

#ifndef CUADRADO_H_
#define CUADRADO_H_
#include "Rotador.h"

#include "Figura.h"
class Cuadrado: public Figura {
private:
	float ancho,alto;
public:
	Cuadrado();
	Cuadrado(float, float,Rotador*, float, float);
	virtual ~Cuadrado();
	bool contacto(float,float);
	bool contieneCentro(Posicionable* posicion);
	bool isAdentro1D(float pos, float posCentro, float ancho);
	void setAncho(float ancho);
	void setAlto (float alto);
	float getAncho() const ;
	float getAlto() const;
	void acept(VisitorFigura*);
};

#endif /* CUADRADO_H_ */
