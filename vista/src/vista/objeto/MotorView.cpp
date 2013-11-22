/*
 * MotorView.cpp
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#include "MotorView.h"
#include "../../ConstantesVista.h"

namespace CLIENTE {
//MotorView::MotorView(float x, float y, float w, float h, SDL_Texture * textura,SimpleEditorAnguloFijo * editor): ObjetoView(x, y, w, h,textura, editor) {
//
//}

MotorView::MotorView(float x, float y, float w, float h,int numeroEvent,SDL_Texture * textura): ObjetoView(x, y, w, h,numeroEvent,textura) {

}

MotorView::~MotorView() {
	// TODO Auto-generated destructor stub
}


void MotorView::update(ViewMsj* mje) {
	ViewObjetoUpdateMsj* mjeCurrent = (ViewObjetoUpdateMsj*)mje;
	this->setXl(mjeCurrent->getX());
	this->setYl(mjeCurrent->getY());
	this->setAngulo(mjeCurrent->getAngulo());
	this->setIdEventoSonido(mjeCurrent->getIdEvento());
}
}
