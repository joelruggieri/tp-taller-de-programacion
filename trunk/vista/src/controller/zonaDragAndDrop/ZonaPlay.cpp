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
#include "src/ConstantesComunicacion.h"
namespace CLIENTE {
ZonaPlay::ZonaPlay(ViewController * vc, float x, float y,ColaEventos * cola) {
	//ENTREGA3 PONERLO DONDE CORRESPONDA.
	cuerpo = new Cuadrado(x, y, 20, 20);
	salida = cola;
	controller = vc;
	crearVista(vc);
}

ZonaPlay::~ZonaPlay() {
}

bool ZonaPlay::click(float x, float y) {
	if (cuerpo->contacto(x, y)) {
		bool iniciado;
		BotonSwitch * boton = (BotonSwitch *) controller->getForUpdate(ID_BOTON_PLAY);
		iniciado = !boton->isPresionado();
		controller->endUpdate();
		JugadorListo* mje = new JugadorListo(iniciado);
		salida->push(mje);
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
	view = new Canvas(110, 90, 20, 20,-1, canvasTexture);
	vc->addView(ID_BOTON_PLAY_FONDO, view);
}

bool CLIENTE::ZonaPlay::clickUp(float x, float y){
if (!this->cuerpo->contacto(x, y)) return false;
return true;
//	bool ctrl;
//	bool shift;
//	ClickMsj* b = new ClickMsj(x, y, false, true, false, false);
//	salida->push(b);
//	return true;
//	return
	}
