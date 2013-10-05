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
#include "../vista/figura/CirculoView.h"
#include "../vista/figura/RuedaView.h"
#include "../vista/figura/PelotaView.h"
#include "../vista/objeto/PlataformaView.h"
#include "../vista/objeto/BalancinView.h"
#include "../vista/figura/RuedaView.h"
#include <list>

using namespace std;
class MotorView;
class GloboHelioView;
class PlataformaView;
class BalancinView;
class DropController{

public:
	virtual ~DropController(){

	}
	virtual void dropNuevaFigura(RuedaView*) = 0;
	virtual void dropNuevaFigura(CirculoView*) = 0;
	virtual void dropNuevaFigura(PelotaView*) = 0;
	virtual void dropNuevaFigura(MotorView*) = 0;
	virtual void dropNuevaFigura(PlataformaView*) = 0;
	virtual void dropNuevaFigura(GloboHelioView*) = 0;
	virtual void dropNuevaFigura(BalancinView*) = 0;
	virtual void dropFigura(FiguraView*) = 0;
	virtual void drag(FiguraView *, float,float) = 0;
};

#endif /* DropController_H_ */


