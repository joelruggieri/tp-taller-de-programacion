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
#include "../../ConstantesVista.h"
namespace CLIENTE {
ZonaPlay::ZonaPlay(ViewController * vc, float x, float y,ColaEventos * cola) {
	//ENTREGA3 PONERLO DONDE CORRESPONDA.
	cuerpo = new Cuadrado(x, y, 20, 10);
	salida = cola;
	crearVista(vc);

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
}

void CLIENTE::ZonaPlay::crearVista(ViewController* vc) {
	CargadorDeTextures * texturas = CargadorDeTextures::Instance();
	SDL_Texture* canvasTexture = texturas->cargarTexture(PATH_ZONA_CREACION);
	SDL_Texture* text1 = texturas->cargarTexture(PATH_BOTON_PLAY);
	SDL_Texture* text2 = texturas->cargarTexture(PATH_BOTON_STOP);
	View *view = new BotonSwitch(110, 90, 20, 20, text1, text2);
	vc->addView(ID_BOTON_PLAY, view);
	view = new ViewConBorde(110, 90, 20, 20);
	vc->addView(ID_BOTON_PLAY_BORDE, view);
	view = new Canvas(110, 90, 20, 20, canvasTexture);
	vc->addView(ID_BOTON_PLAY_FONDO, view);
}
