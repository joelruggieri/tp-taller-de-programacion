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
#include "../../modelo/Scroll.h"
#include "../../vista/ScrollView.h"
using namespace std;

class ZonaCreacion: public Zona {
private:
	EslabonCreacion * inicioCadena;
	EslabonCreacion * ultimo;
	static const int ANCHO_VIEW_DEF = 10;
	static const int ALTO_PANEL = 90;
	static const int DISTANCIA_ENTRE_ELEMENTOS = 15;
	static const int SLEEP_BOTONES_SCROLL = 10;

	bool agregarTemplate(FiguraView * dragueable);
	FiguraView * getFiguraTemplate(float x, float y);
	void inicializar(list<ViewFiguraFactory*> *, float x, float margenSuperior);
	list<View*> canvas;
	Scroll * scroll;
	ScrollView * crearScrollView(Cuadrado* c1, Cuadrado* c2,Scroll* scroll);
	float margenSuperior;
	void agregarEslabon(EslabonCreacion* eslabon);

public:
	ZonaCreacion(list<ViewFiguraFactory*> *, float x, float margenSuperior);
	virtual ~ZonaCreacion();
	void dibujarse(list<ViewMsj*> & lista);
	bool click(float x, float y);
	bool mouseScroll(float x, float y, int amountScrolled);
	bool enContacto(float posX, float posY);
};

#endif /* ZONACREACION_H_ */
