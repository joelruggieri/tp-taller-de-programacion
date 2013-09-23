/*
 * Resorte.h
 *
 *  Created on: 20/09/2013
 *      Author: joel
 */

#ifndef RESORTE_H_
#define RESORTE_H_
#include "Cuadrado.h"
#include "Rotador.h"

class Resorte: public Cuadrado {
public:
	Resorte();
	Resorte(const Resorte& figura);
	Resorte(float, float,Rotador*, float, float);
	virtual ~Resorte();
	void acept(VisitorFigura *visitor);
};

#endif /* RESORTE_H_ */
