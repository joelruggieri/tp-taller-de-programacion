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
#include "src/figura/Cuadrado.h"
#include "../viewFactory/ViewFiguraFactory.h"
#include <list>
using namespace std;

class ZonaCreacion: public ZonaDragAndDrop {
private:
	EslabonCreacion * inicioCadena;
	EslabonCreacion * ultimo;
	bool dropTemplate(FiguraView * dragueable);
	FiguraView * dragTemplate(float x, float y);
public:
	ZonaCreacion(list<ViewFiguraFactory*> *);
	virtual ~ZonaCreacion();
	void agregarEslabon(EslabonCreacion* eslabon);
};

#endif /* ZONACREACION_H_ */
