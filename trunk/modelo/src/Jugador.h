/*
 * Jugador.h
 *
 *  Created on: 27/10/2013
 *      Author: jonathan
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_
#include "Area.h"
class Jugador {
private:
	Area * area;
	int numero;
public:
	Jugador();
	virtual ~Jugador();
	Area* getArea() ;
	int getNumero() ;
};

#endif /* JUGADOR_H_ */
