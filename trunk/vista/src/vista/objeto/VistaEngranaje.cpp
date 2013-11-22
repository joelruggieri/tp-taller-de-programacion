/*
 * VistaEngranaje.cpp
 *
 *  Created on: 12/10/2013
 *      Author: javier
 */

#include "VistaEngranaje.h"
#include "SDL2/SDL.h"
#include "../../ConstantesVista.h"
#include <iostream>
using namespace std;
namespace CLIENTE {
VistaEngranaje::VistaEngranaje(float x, float y, float w, float h,int numeroEvent,SDL_Texture * textura): ObjetoView(x, y, w, h,numeroEvent,textura) {
	// TODO Auto-generated constructor stub

}

VistaEngranaje::~VistaEngranaje() {
	// TODO Auto-generated destructor stub
}
void VistaEngranaje::update(ViewMsj *mje) {
	ViewObjetoConAnchoUpdateMsj* mjeCurrent = (ViewObjetoConAnchoUpdateMsj*)mje;
	this->setXl(mjeCurrent->getX());
	this->setYl(mjeCurrent->getY());
	this->setAngulo(mjeCurrent->getAngulo());
	this->setWl(mjeCurrent->getAncho());
	this->setHl(mjeCurrent->getAncho());
	this->setIdEventoSonido(mjeCurrent->getIdEvento());
}

}
