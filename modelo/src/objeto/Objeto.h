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
	Objeto();
	Objeto(float x, float y);
	Objeto(float x, float y, ValidadorInteraccion * v);
	Objeto(const Objeto & obj);

	virtual ~Objeto();
	bool contieneCentro(Posicionable *);
	//estos metodos devuelven el tamaño del cuadrado contenedor;
	bool contacto(float, float);
};

#endif /* OBJETO_H_ */
