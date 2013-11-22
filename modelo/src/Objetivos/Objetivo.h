/*
 * Objetivo.h
 *
 *  Created on: 21/11/2013
 *      Author: ezequiel
 */

#ifndef OBJETIVO_H_
#define OBJETIVO_H_
#include "../observer/ObserverModelo.h"
class Objetivo : public ObserverModelo {
public:
	Objetivo(float x, float y, int numero);
	virtual ~Objetivo();
protected:
	int numeroObjetivo;
	float xD,yD;
};

#endif /* OBJETIVO_H_ */
