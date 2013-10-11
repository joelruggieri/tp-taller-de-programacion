/*
 * Soga.h
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#ifndef SOGA_H_
#define SOGA_H_

#include "Objeto.h"

class Soga: public Objeto {
public:
	Soga(float x, float y);
	virtual ~Soga();
	bool crearFisicaEstatica(b2World *);
};

#endif /* SOGA_H_ */
