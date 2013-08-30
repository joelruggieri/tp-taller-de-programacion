/*
 * EslabonCreacion.h
 *
 *  Created on: 29/08/2013
 *      Author: jonathan
 */

#ifndef ESLABONCREACION_H_
#define ESLABONCREACION_H_

#include "Dropeable.h"
#include "DropeableFactory.h"
#include "Cuerpo.h"
using namespace std;

class EslabonCreacion {
private:
	EslabonCreacion * siguiente;
	DropeableFactory * factory;
	Cuerpo cuerpo;
	int itemsDisponibles;
public:
	EslabonCreacion(DropeableFactory * factory, Cuerpo cuerpo, int maxCreacion);
	virtual ~EslabonCreacion();
	void setSiguiente(EslabonCreacion * sig);
	Dropeable * antender(float posX, float posY);
};

#endif /* ESLABONCREACION_H_ */
