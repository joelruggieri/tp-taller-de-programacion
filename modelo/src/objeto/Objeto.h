/*
 * Objeto.h
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#ifndef OBJETO_H_
#define OBJETO_H_

#include "../figura/Figura.h"
class Objeto: public Figura {
public:
	Objeto(float x, float y,Rotador * rot);
	virtual ~Objeto();
	bool contieneCentro(Posicionable *);
	void acept(VisitorFigura*);
	//estos metodos devuelven el tamaño del cuadrado contenedor;
	float getAlto() const;
	float getAncho() const;
	bool contacto(float, float);
};

#endif /* OBJETO_H_ */
