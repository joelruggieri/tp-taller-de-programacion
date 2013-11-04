/*
 * Cuadrado.h
 *
 *  Created on: 04/09/2013
 *      Author: jonathan
 */

#ifndef CUADRADO_H_
#define CUADRADO_H_

class Cuadrado {
protected:
	float ancho,alto,x,y;
public:
	Cuadrado();
	Cuadrado(float, float, float, float);
	virtual ~Cuadrado();
	bool contacto(float,float);
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
