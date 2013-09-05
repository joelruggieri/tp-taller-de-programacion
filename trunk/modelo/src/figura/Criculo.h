/*
 * Criculo.h
 *
 *  Created on: 04/09/2013
 *      Author: jonathan
 */

#ifndef CRICULO_H_
#define CRICULO_H_

#include "Figura.h"

class Criculo: public Figura {
public:
	Criculo();
	virtual ~Criculo();
	bool contacto(float,float);
};

#endif /* CRICULO_H_ */
