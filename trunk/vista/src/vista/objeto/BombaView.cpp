/*
 * BombaView.cpp
 *
 *  Created on: 17/11/2013
 *      Author: ezequiel
 */

#include "BombaView.h"
#include "../CargadorDeSonidos.h"
#include "src/Logger.h"
namespace CLIENTE {

BombaView::BombaView(float x, float y, float w, float h,int numeroEvent,SDL_Texture * textura) : ObjetoView(x,y,w,h,numeroEvent,textura) {
	this->sonidoContacto = CargadorDeSonidos::Instance()->getSonido(ID_SONIDO_BOMBA_CONTACTO);
	this->sonidoExplosion = CargadorDeSonidos::Instance()->getSonido(ID_SONIDO_BOMBA_EXPLOSION);
}

BombaView::~BombaView() {
	// TODO Auto-generated destructor stub
}

void BombaView::update(ViewMsj* mje) {
	ViewObjetoUpdateMsj* mjeCurrent = (ViewObjetoUpdateMsj*)mje;
	this->setXl(mjeCurrent->getX());
	this->setYl(mjeCurrent->getY());
	this->setAngulo(mjeCurrent->getAngulo());
	this->setIdEventoSonido(mjeCurrent->getIdEvento());
}

//TODO PODRIA SER QUE LLEGUEN AMBOS EVENTOS REPRODUCIR, LA EXPLOSION Y EL CHOQUE A LA VEZ.
void BombaView::dibujarse(SDL_Renderer* renderer){
	Logger log;
	if(this->getIdEventoSonido() == ID_SONIDO_BOMBA_CONTACTO){
		if(sonidoContacto == NULL){
			log.error("no se puede reproducir el sonido de contacto de la bomba");
		}else{
			//Mix_Pause(1);
			Mix_PlayChannel(-1,sonidoContacto,0);
			cout << "reproduce" << endl;
		}
	}if(this->getIdEventoSonido() == ID_SONIDO_BOMBA_EXPLOSION){
		if(sonidoExplosion == NULL){
				log.error("no se puede reproducir el sonido de explosion de la bomba");
		}else
			Mix_PlayChannel(-1,sonidoExplosion,0);
	}

	super::dibujarse(renderer);
	this->idEventoSonido = 0;
//	Mix_Pause(-1);
}


} /* namespace CLIENTE */
