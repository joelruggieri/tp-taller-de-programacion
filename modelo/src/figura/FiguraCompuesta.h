/*
 * FiguraCompuesta.h
 *
 *  Created on: 12/09/2013
 *      Author: jonathan
 */

#ifndef FIGURACOMPUESTA_H_
#define FIGURACOMPUESTA_H_
#include "Figura.h"
#include <list>


using namespace std;

class Figura;
class FiguraCompuesta: public Figura {
private:
	list<Figura*> figuras;
public:
	FiguraCompuesta(float x, float y);
	virtual ~FiguraCompuesta();
	bool contacto(float, float);
	bool contieneCentro(Posicionable* figura);
	void addFigura(Figura * figura);
	Figura * getFiguraEn(float, float);
};

#endif /* FIGURACOMPUESTA_H_ */
