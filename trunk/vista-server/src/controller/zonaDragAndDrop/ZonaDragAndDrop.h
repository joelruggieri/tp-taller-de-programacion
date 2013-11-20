/*
 * Zona.h
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 */

#ifndef ZONADRAGANDDROP_H_
#define ZONADRAGANDDROP_H_

#include "../../modelo/Cuadrado.h"
#include "../../vista/figura/FiguraView.h"
#include "../../vista/Dibujable.h"
#include <list>
using namespace std;

class Zona {
protected:
	Cuadrado *cuerpo;
	void setCuerpo(Cuadrado * cuerpo);
public:
	Zona(Cuadrado* cuadrado);
	virtual ~Zona();
	Cuadrado*& getCuerpo();
};

#endif /* ZONADRAGANDDROP_H_ */

