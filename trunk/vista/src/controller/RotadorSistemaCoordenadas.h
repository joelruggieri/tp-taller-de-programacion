/*
 * RotadorSistemaCoordenadas.h
 *
 *  Created on: 19/09/2013
 *      Author: jonathan
 */

#ifndef ROTADORSISTEMACOORDENADAS_H_
#define ROTADORSISTEMACOORDENADAS_H_

#include "src/figura/Rotador.h"
#include "src/figura/Figura.h"


class RotadorSistemaCoordenadas: public Rotador {
public:
	RotadorSistemaCoordenadas();
	virtual ~RotadorSistemaCoordenadas();
	void rotar(Figura*, double & x, double & y);
};

#endif /* ROTADORSISTEMACOORDENADAS_H_ */
