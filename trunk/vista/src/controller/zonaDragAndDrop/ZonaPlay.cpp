/*
 * ZonaPlay.cpp
 *
 *  Created on: 2/10/2013
 *      Author: jonathan
 */

#include "ZonaPlay.h"
#include "../UserEventCreator.h"
#include "../../vista/CargadorDeTextures.h"
#include "../../vista/ViewConBorde.h"
#include "../../vista/ViewConFondo.h"
#include "SDL2/SDL.h"
ZonaPlay::ZonaPlay(ColaEventos * cola) {
	//ENTREGA3 PONERLO DONDE CORRESPONDA.
	float x, y;
	cuerpo = new Cuadrado(x, y, 20, 10);
	salida = cola;
//	boton = new BotonSwitch(lx,ly,w,h,USREVENT_START, USREVENT_STOP,text1,text2);
}

ZonaPlay::~ZonaPlay() {
}

bool ZonaPlay::click(float x, float y) {
	if (cuerpo->contacto(x, y)) {
		this->boton->click();
		//ENTREGA3 MANDAR MENSAJE DE USER LISTO O NO LISTO.
		return true;
	}
	return false;
}
