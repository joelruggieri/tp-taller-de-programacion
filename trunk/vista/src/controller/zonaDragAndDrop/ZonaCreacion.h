/*
 * ZonaCreacion.h
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 */

#ifndef ZONACREACION_H_
#define ZONACREACION_H_

#include "ZonaDragAndDrop.h"
#include "EslabonCreacion.h"
#include "../viewFactory/ViewFiguraFactory.h"
#include <list>
using namespace std;

class ZonaCreacion: public Zona {
private:
	EslabonCreacion * inicioCadena;
	EslabonCreacion * ultimo;
	static const int ANCHO_VIEW_DEF = 10;
	Dibujable * fondo;
	bool agregarTemplate(FiguraView * dragueable);
	bool clickTemplate(float x, float y);
	list<Dibujable* > vistasFactories;
	void inicializar(list<ViewFiguraFactory*> *, float x, float margenSuperior);
public:
	ZonaCreacion(list<ViewFiguraFactory*> *, float x, float margenSuperior,Dibujable *);
	ZonaCreacion(list<ViewFiguraFactory*> *, float x, float margenSuperior, SDL_Texture *);
	virtual ~ZonaCreacion();
	void agregarEslabon(EslabonCreacion* eslabon);
	void dibujarse(SDL_Renderer *);
	bool removerFigura(FiguraView*);
};

#endif /* ZONACREACION_H_ */
