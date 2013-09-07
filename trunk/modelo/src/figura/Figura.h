/*
 * Figura.h
 *
 *  Created on: 04/09/2013
 *      Author: jonathan
 */

#ifndef FIGURA_H_
#define FIGURA_H_

class Figura {
protected:
	float x;
	float y;
	float rotacion;
public:
	Figura();
	virtual ~Figura();
	virtual bool contacto(float, float)= 0;
	virtual bool contieneCentro(Figura* figura) = 0;
	float getX() const;
	float getY() const;
	float getRotacion() const;
	void setX(float x);
	void setY(float y);
	void setRotacion(float rotation);
};

#endif /* FIGURA_H_ */

