/*
 * GloboHelioView.cpp
 *
 *  Created on: 05/10/2013
 *      Author: ezequiel
 */

#include "GloboHelioView.h"
#include "../CargadorDeSonidos.h"
#include "src/Logger.h"

namespace CLIENTE {
GloboHelioView::GloboHelioView(float x, float y, float w, float h,int numeroEvent, SDL_Texture * textura): ObjetoView(x, y, w, h,numeroEvent,textura) {
	sonido = CargadorDeSonidos::Instance()->getSonido(ID_SONIDO_GLOBO);
}

GloboHelioView::~GloboHelioView() {
	// TODO Auto-generated destructor stub
}

void GloboHelioView::dibujarse(SDL_Renderer* r){
	if(this->getIdEventoSonido() == ID_SONIDO_GLOBO){
		if (sonido == NULL){
			Logger log;
			log.error("no se puede reproducir el sonido de la Globo");
		}
		Mix_PlayChannel(-1,sonido,0);
	}
	this->idEventoSonido = 0;
	super::dibujarse(r);



}
}

void CLIENTE::GloboHelioView::update(ViewMsj* mje) {
	ViewObjetoUpdateMsj* mjeCurrent = (ViewObjetoUpdateMsj*)mje;
	this->setXl(mjeCurrent->getX());
	this->setYl(mjeCurrent->getY());
	this->setAngulo(mjeCurrent->getAngulo());
	this->setIdEventoSonido(mjeCurrent->getIdEvento());
}
