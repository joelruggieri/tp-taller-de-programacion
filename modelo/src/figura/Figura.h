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

class Figura: public Posicionable {
protected:
	float x;
	float y;
	double rotacion;
public:
	Figura();
	Figura(float x, float y);
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
};

#endif /* FIGURA_H_ */

