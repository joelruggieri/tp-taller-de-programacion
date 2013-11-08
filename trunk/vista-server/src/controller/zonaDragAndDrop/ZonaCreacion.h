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
#include "../../modelo/Scroll.h"
#include "../../vista/ScrollView.h"
using namespace std;

class ZonaCreacion: public Zona {
private:
	void inicializar(list<ViewFiguraFactory*> *);
public:
	ZonaCreacion(list<ViewFiguraFactory*> *);
	virtual ~ZonaCreacion();
	void dibujarse(list<ViewMsj*> & lista);

	//ENTREGA3 esto es para poder crear los elementos
	FiguraView * crearFigura(string tag, float x, float y);
};

#endif /* ZONACREACION_H_ */
