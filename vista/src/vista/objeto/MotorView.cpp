/*
 * MotorView.cpp
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#include "MotorView.h"
#include "../../ConstantesVista.h"
#include "../CargadorDeSonidos.h"
#include "src/Logger.h"
namespace CLIENTE {
//MotorView::MotorView(float x, float y, float w, float h, SDL_Texture * textura,SimpleEditorAnguloFijo * editor): ObjetoView(x, y, w, h,textura, editor) {
//
//}

MotorView::MotorView(float x, float y, float w, float h,int numeroEvent,SDL_Texture * textura): ObjetoView(x, y, w, h,numeroEvent,textura) {
	sonido = CargadorDeSonidos::Instance()->getSonido(ID_SONIDO_MOTOR);
	realizarSonido = false;
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
	if (mjeCurrent->getAngulo() == 0)
		realizarSonido = false;
	else
		realizarSonido = true;
}

void MotorView::dibujarse(SDL_Renderer* r){
	if(/*(this->getIdEventoSonido() == ID_SONIDO_MOTOR) || */realizarSonido){
		cout << "hola motor" << endl;
		if (sonido == NULL){
			Logger log;
			log.error("no se puede reproducir el sonido de la pelota");
		}
		Mix_VolumeChunk(sonido,1);
		Mix_PlayChannel(1,sonido,0);

		//cout<< "reprodujo" << std::endl;
		//usleep(520000);
	}
	this->idEventoSonido = 0;
	super::dibujarse(r);
}
}
