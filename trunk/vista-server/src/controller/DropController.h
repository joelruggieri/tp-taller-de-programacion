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
#include "../vista/figura/FiguraView.h"
#include "../vista/objeto/PlataformaView.h"
#include "../vista/objeto/BalancinView.h"
#include "../vista/objeto/BolaBolicheView.h"
#include "../vista/objeto/CorreaView.h"
#include "../vista/objeto/GloboHelioView.h"
#include "../vista/objeto/MotorView.h"
#include "../vista/objeto/PelotaJuegoView.h"
#include "../vista/objeto/SogaEstaticaView.h"
#include "../vista/objeto/CorreaEstaticaView.h"
#include "../vista/objeto/CintaTransportadoraView.h"
#include "../vista/objeto/VistaEngranaje.h"


#include <list>

using namespace std;
class MotorView;
class GloboHelioView;
class PlataformaView;
class BalancinView;
class CintaTransportadoraView;
class BolaBolicheView;
class PelotaJuegoView;
class VistaEngranaje;
class CorreaEstaticaView;
class SogaEstaticaView;
class DropController {

public:
	virtual ~DropController(){

	}
	virtual void dropFigura(FiguraView*) = 0;
	virtual void drag(FiguraView *, float,float) = 0;
};

#endif /* DropController_H_ */

