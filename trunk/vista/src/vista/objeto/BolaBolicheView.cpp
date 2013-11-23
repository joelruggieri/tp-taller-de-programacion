/*
 * BolaBolicheView.cpp
 *
 *  Created on: 06/10/2013
 *      Author: ezequiel
 */

#include "BolaBolicheView.h"
#include "../CargadorDeSonidos.h"
#include "src/Logger.h"
namespace CLIENTE {
BolaBolicheView::BolaBolicheView(float x, float y, float w, float h,int numeroEvent,SDL_Texture * textura): ObjetoView(x, y, w, h,numeroEvent,textura) {
	this->sonido = CargadorDeSonidos::Instance()->getSonido(ID_SONIDO_BOLA);

}

BolaBolicheView::~BolaBolicheView() {
	// TODO Auto-generated destructor stub
}

void BolaBolicheView::update(ViewMsj* mje) {
	ViewObjetoUpdateMsj* mjeCurrent = (ViewObjetoUpdateMsj*) mje ;
	this->setXl(mjeCurrent->getX());
	this->setYl(mjeCurrent->getY());
	this->setAngulo(mjeCurrent->getAngulo());
	this->setIdEventoSonido(mjeCurrent->getIdEvento());
}

void BolaBolicheView::dibujarse(SDL_Renderer* renderer){
	if(this->getIdEventoSonido() == ID_SONIDO_BOLA){
		if (sonido == NULL){
			Logger log;
			log.error("no se puede reproducir el sonido de la bola");
		}
		Mix_PlayChannel(-1,sonido,0);
		//cout<< "reprodujo" << std::endl;
		//usleep(520000);
	}
	this->idEventoSonido = 0;
	super::dibujarse(renderer);
//	Mix_Pause(-1);
}
}
