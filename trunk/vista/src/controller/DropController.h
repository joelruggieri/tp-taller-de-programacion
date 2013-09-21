/*
 * DropController.h
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 *
 *      TODO ESTE TIPO DEBERÍA HACER LOS PIXELS DE LA PANTALLA NO DEBERÍAN LLEGAR A LAS ZONAS.
 */

#ifndef DropController_H_
#define DropController_H_
#include "src/figuraFactory/FiguraFactory.h"
#include "../vista/figura/FiguraView.h"
#include "zonaDragAndDrop/ZonaDragAndDrop.h"
#include "mouseEventController/MouseEventController.h"
#include "../vista/figura/FiguraView.h"
#include "../vista/figura/CuadradoView.h"
#include "../vista/figura/CirculoView.h"
#include "../vista/figura/TrianguloView.h"
#include "../vista/figura/RuedaView.h"
#include "../vista/figura/GloboView.h"
#include "../vista/figura/PelotaView.h"
#include "../vista/figura/ResorteView.h"
#include "../vista/figura/MartilloView.h"
#include "../vista/figura/BloqueView.h"
#include "../vista/figura/CoheteView.h"

#include <list>

using namespace std;

class DropController{

public:
	virtual ~DropController(){

	}
	virtual void dropNuevaFigura(RuedaView*) = 0;
	virtual void dropNuevaFigura(CuadradoView*) = 0;
	virtual void dropNuevaFigura(CirculoView*) = 0;
	virtual void dropNuevaFigura(TrianguloView*) = 0;
	virtual void dropNuevaFigura(GloboView*) = 0;
	virtual void dropNuevaFigura(PelotaView*) = 0;
	virtual void dropNuevaFigura(ResorteView*) = 0;
	virtual void dropNuevaFigura(MartilloView*) = 0;
	virtual void dropNuevaFigura(BloqueView*) = 0;
	virtual void dropNuevaFigura(CoheteView*) = 0;
	virtual void dropFigura(FiguraView*) = 0;
	virtual void drag(FiguraView *, float,float) = 0;
};

#endif /* DropController_H_ */


