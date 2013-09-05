/*
 * Mapa.h
 *
 *  Created on: 04/09/2013
 *      Author: jonathan
 */

#ifndef MAPA_H_
#define MAPA_H_

#include "Cuadrado.h"
#include <list>
using namespace std;

class Mapa: public Cuadrado {
private:
	list<Figura*> figuras;
public:
	Mapa();
	virtual ~Mapa();
	void addFigura(Figura*);
};

#endif /* MAPA_H_ */
