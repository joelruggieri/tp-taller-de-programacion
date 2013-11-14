/*
 * ZonaTablero.cpp
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 */

#include "ZonaTablero.h"
#include "../Resizer.h"
#include "src/Logger.h"
#include "src/mensajes/userEvents/ClickMsj.h"
#include "src/mensajes/userEvents/MouseMotionMsj.h"
#include "../../ConstantesVista.h"
#include "../../vista/CargadorDeTextures.h"
#include "../../vista/ViewConBorde.h"
#include "src/ConstantesComunicacion.h"
//ENTREGA3 EN REALIDAD PARA NO ENVIAR BOLUDECES AL SERVER ACA HAY QUE SETEAR EL AREA DEL JUGADOR Y ESA POSICION ENTONCES SOLAMENTE SE ENVIAN LAS COSAS QUE CAEN AHI.

namespace CLIENTE {

void ZonaTablero::crearVista(ViewController* vc) {
	CargadorDeTextures * texturas = CargadorDeTextures::Instance();
	SDL_Texture* canvasTexture = texturas->cargarTexture(PATH_FONDO);
	View * view = new Canvas(50, 50, 100, 100, LAYER_CANVAS_TABLERO, canvasTexture);
	vc->addView(ID_CANVAS, view);
	view = new ViewConBorde(50, 50, 100, 100);
	vc->addView(ID_BORDE_CANVAS, view);

}

ZonaTablero::ZonaTablero(ViewController * vc, ColaEventos * cola) {
	salida = cola;
	cuerpo =new Cuadrado(50,50,100,100);
	crearVista(vc);
}

//Canvas* ZonaTablero::getCanvas(){
//	return this->canvas;
//}



ZonaTablero::~ZonaTablero() {
//	std::list<FiguraView*>::const_iterator iterator;
//	delete this->viewCanvas;
}
}

bool CLIENTE::ZonaTablero::click(float float1, float float2) {
	if (!this->cuerpo->contacto(float1, float2)) return false;
	bool ctrl;
	bool shift;
	this->setearTeclas(shift,ctrl);
	ClickMsj* b = new ClickMsj(float1, float2, true, true, shift, ctrl);
	salida->push(b);
	return true;
}

bool CLIENTE::ZonaTablero::rightClick(float float1, float float2) {
	if (!this->cuerpo->contacto(float1, float2)) return false;
	bool ctrl;
	bool shift;
	this->setearTeclas(shift,ctrl);
	ClickMsj* b = new ClickMsj(float1, float2, true, false, shift, ctrl);
	salida->push(b);
	return true;
}

bool CLIENTE::ZonaTablero::keyPressed(char key) {
	return false;
}

bool CLIENTE::ZonaTablero::keyReleased(char key) {
	return false;
		}

void CLIENTE::ZonaTablero::setearTeclas(bool& shift, bool& ctrl) {
	const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);
	shift = keyboardState[SDL_SCANCODE_LSHIFT];
	ctrl = keyboardState[SDL_SCANCODE_LCTRL];
}

bool CLIENTE::ZonaTablero::mouseMotion(float float1, float float2) {
	//POR AHORA SOLO LA ZONATABLERO REALIZA EL MOUSEMOTION
	bool ctrl = false;
	bool shift = false;
	this->setearTeclas(shift, ctrl);
	MouseMotionMsj* mje = new MouseMotionMsj(float1,float2,shift, ctrl);
	salida->push(mje);
	return true;
}

bool CLIENTE::ZonaTablero::clickUp(float float1, float float2) {
//	if (!this->cuerpo->contacto(float1, float2)) return false;
		bool ctrl;
		bool shift;
		this->setearTeclas(shift,ctrl);
		ClickMsj* b = new ClickMsj(float1, float2, false, true, shift, ctrl);
		salida->push(b);
		return true;
}

bool CLIENTE::ZonaTablero::rightClickUp(float float1, float float2) {
//	if (!this->cuerpo->contacto(float1, float2)) return false;
		ClickMsj* b = new ClickMsj(float1, float2, false, false, false, false);
		salida->push(b);
		return true;
}
