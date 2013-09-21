/*
 * Carrito.h
 *
 *  Created on: 21/09/2013
 *      Author: joel
 */

#ifndef CARRITO_H_
#define CARRITO_H_
#include "Cuadrado.h"
#include "Rotador.h"

class Carrito: public Cuadrado {

public:
	Carrito();
	Carrito(float x, float y,Rotador* rotador, float ancho, float alto);
	virtual ~Carrito();
};

#endif /* CARRITO_H_ */
