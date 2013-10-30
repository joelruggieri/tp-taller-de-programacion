/*
 * Area.h
 *
 *  Created on: 04/09/2013
 *      Author: jonathan
 */

#ifndef AREA_H_
#define AREA_H_
#include "Posicionable.h"

class Area {
protected:
	float ancho,alto,x,y;
public:
	Area();
	Area(float, float, float, float);
	virtual ~Area();
	bool contacto(float,float);
	bool contieneCentro(Posicionable* posicion);
	bool isAdentro1D(float pos, float posCentro, float ancho);
	void setAncho(float ancho);
	void setAlto (float alto);
	float getAncho() const ;
	float getAlto() const;
	float getX() const;
	void setX(float x);
	float getY() const;
	void setY(float y);
};

#endif /* CUADRADO_H_ */
