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
	Globo(const Globo& figura);
	virtual ~Globo();
	Globo(float x, float y, Rotador* rotador, float radio);
	void acept(VisitorFigura *visitor);
};

#endif /* GLOBO_H_ */
