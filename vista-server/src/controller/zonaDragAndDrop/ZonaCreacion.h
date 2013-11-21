/*
 * ZonaCreacion.h
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 */

#ifndef ZONACREACION_H_
#define ZONACREACION_H_

#include "ZonaDragAndDrop.h"
#include "../viewFactory/ViewFiguraFactory.h"
#include <list>
#include <map>
#include <string>
using namespace std;

class ZonaCreacion: public Zona {
private:
	map<string, ViewFiguraFactory* > factories;
public:
	ZonaCreacion(list<ViewFiguraFactory*> &);
	virtual ~ZonaCreacion();
	void dibujarse(list<NetworkMensaje*> & lista, int desti);
	FiguraView * crearFigura(string tag, float x, float y);
};

#endif /* ZONACREACION_H_ */
