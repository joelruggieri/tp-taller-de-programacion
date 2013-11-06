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
//ENTREGA3 EN REALIDAD PARA NO ENVIAR BOLUDECES AL SERVER ACA HAY QUE SETEAR EL AREA DEL JUGADOR Y ESA POSICION ENTONCES SOLAMENTE SE ENVIAN LAS COSAS QUE CAEN AHI.

namespace CLIENTE {
ZonaTablero::ZonaTablero(ColaEventos * cola) {
	salida = cola;
	cuerpo =new Cuadrado(50,50,100,100);
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
	ClickMsj* b = new ClickMsj(float1, float2, true, true, true, true);
	salida->push(b);
	return false;
}

void CLIENTE::ZonaTablero::rightClick(float float1, float float2) {
}

void CLIENTE::ZonaTablero::keyPressed(char key) {
}

void CLIENTE::ZonaTablero::keyReleased(char key) {
}
