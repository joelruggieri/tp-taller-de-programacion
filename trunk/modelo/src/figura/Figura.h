/*
 * Figura.h
 *
 *  Created on: 04/09/2013
 *      Author: jonathan
 */

#ifndef FIGURA_H_
#define FIGURA_H_
#include "../Posicionable.h"
#include "VisitorFigura.h"
#include "Rotador.h"
class Figura: public Posicionable {
protected:
	float x;
	float y;
	double rotacion;
	Rotador * rotador;
public:
	Figura();
	Figura(float x, float y, Rotador * rot);
	virtual ~Figura();
	virtual bool contacto(float, float)= 0;
	virtual bool contieneCentro(Posicionable* figura) = 0;
	float getX() const;
	float getY() const;
	double getRotacion() const;
	void setX(float x);
	void setY(float y);
	void setRotacion(double rotation);
	virtual void acept(VisitorFigura*) = 0;
	//estos metodos devuelven el tamaño del cuadrado contenedor;
	virtual float getAlto() const = 0;
	virtual float getAncho() const = 0;
	void setRotador(Rotador* rotador);
};

#endif /* FIGURA_H_ */

