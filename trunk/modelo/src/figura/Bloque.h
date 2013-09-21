/*
 * Bloque.h
 *
 *  Created on: 21/09/2013
 *      Author: joel
 */

#ifndef BLOQUE_H_
#define BLOQUE_H_
#include "Cuadrado.h"
#include "Rotador.h"

class Bloque: public Cuadrado {
public:
	Bloque();
	Bloque(float x, float y,Rotador* rotador, float ancho, float alto);
	virtual ~Bloque();
};

#endif /* BLOQUE_H_ */
