/*
 * Triangulo.h
 *
 *  Created on: 06/09/2013
 *      Author: jonathan
 */

#ifndef TRIANGULO_H_
#define TRIANGULO_H_

#include "Figura.h"
#include "Rotador.h"
#include "Box2D/Box2D.h"
class Triangulo: public Figura {
private:
	float ancho,alto;
public:
	Triangulo();
	Triangulo(float, float, Rotador * rotador, float, float);
	virtual ~Triangulo();
	bool contacto(float,float);
	bool contieneCentro(Posicionable* cuadrado);
	bool isAdentro1D(float pos, float posCentro, float ancho);
	void setAncho(float ancho);
	void setAlto (float alto);
	float getAncho() const;
	float getAlto() const;
	void acept(VisitorFigura*);
	void crearsFisica(b2World *);
};

#endif /* TRIANGULO_H_ */
