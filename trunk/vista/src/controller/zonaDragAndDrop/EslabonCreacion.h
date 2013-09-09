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
#include "src/figura/Cuadrado.h"
using namespace std;

class EslabonCreacion {
private:
	EslabonCreacion * siguiente;
	ViewFiguraFactory * factory;
	Dibujable * vista;
	Cuadrado * cuerpo;
	int itemsDisponibles;
public:
	EslabonCreacion(ViewFiguraFactory * factory, Cuadrado *cuerpo, int maxCreacion);
	virtual ~EslabonCreacion();
	void setSiguiente(EslabonCreacion * sig);
	FiguraView * atender(float posX, float posY);
	void dibujarse(SDL_Renderer *);
	//	void invalidar(Dropeable*);
};

#endif /* ESLABONCREACION_H_ */
