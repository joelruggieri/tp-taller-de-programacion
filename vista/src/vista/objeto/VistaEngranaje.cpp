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
VistaEngranaje::VistaEngranaje(float x, float y, float w, float h, SDL_Texture * textura): ObjetoView(x, y, w, h,textura) {
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
//		super::update();
//		Engranaje* e = (Engranaje*) this->getModelo();
//		float y = 0 ;
//		tl.setVector(e->getRadio()*2,0);
//		float nuevoRadio;
//		tl.getResultadoInverso(nuevoRadio,y);
//		this->setW(nuevoRadio);
//		this->setH(nuevoRadio);

//		float a,b;
//		tl.getResultadoInverso(a,b);
//		cout << a << " " << b << endl;
//				this->setW(a);
//				this->setH(b);
}

int VistaEngranaje::getLayer() {
	return LAYER_ENGRANAJES;
}
}
