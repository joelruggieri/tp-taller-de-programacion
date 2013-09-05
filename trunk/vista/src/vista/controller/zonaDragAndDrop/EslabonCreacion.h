/*
 * EslabonCreacion.h
 *
 *  Created on: 29/08/2013
 *      Author: jonathan
 */

#ifndef ESLABONCREACION_H_
#define ESLABONCREACION_H_

#include "../../vista/figura/FiguraView.h"
#include "../viewFactory/ViewFiguraFactory.h"
#include "src/figura/Figura.h"
using namespace std;

class EslabonCreacion {
private:
	EslabonCreacion * siguiente;
	ViewFiguraFactory * factory;
	Figura * cuerpo;
	int itemsDisponibles;
public:
	EslabonCreacion(ViewFiguraFactory * factory, Figura *cuerpo, int maxCreacion);
	virtual ~EslabonCreacion();
	void setSiguiente(EslabonCreacion * sig);
	FiguraView * antender(float posX, float posY);
//	void invalidar(Dropeable*);
};

#endif /* ESLABONCREACION_H_ */
