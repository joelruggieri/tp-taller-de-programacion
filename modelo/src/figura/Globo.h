/*
 * Globo.h
 *
 *  Created on: 20/09/2013
 *      Author: joel
 */

#ifndef GLOBO_H_
#define GLOBO_H_
#include "Circulo.h"
#include "Rotador.h"
class Globo: public Circulo {
public:
	Globo();
	virtual ~Globo();
	Globo(float x, float y, Rotador* rotador, float radio);
};

#endif /* GLOBO_H_ */