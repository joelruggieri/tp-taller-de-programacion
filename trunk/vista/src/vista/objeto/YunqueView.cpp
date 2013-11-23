/*
 * YunqueView.cpp
 *
 *  Created on: 13/11/2013
 *      Author: ezequiel
 */

#include "YunqueView.h"
#include "../CargadorDeSonidos.h"
#include "src/Logger.h"
namespace CLIENTE {

YunqueView::YunqueView(float x, float y, float w, float h,int numeroEvent, SDL_Texture * textura) :ObjetoView(x, y, w, h,numeroEvent,textura)  {
	sonido = CargadorDeSonidos::Instance()->getSonido(ID_SONIDO_YUNKE);

}

YunqueView::~YunqueView() {
	// TODO Auto-generated destructor stub
}

void YunqueView::dibujarse(SDL_Renderer* renderer){
	if(this->getIdEventoSonido() == ID_SONIDO_YUNKE){
		if (sonido == NULL){
			Logger log;
			log.error("no se puede reproducir el sonido de la Yunque");
		}
		Mix_PlayChannel(-1,sonido,0);
	}
	this->idEventoSonido = 0;
	super::dibujarse(renderer);

}

void YunqueView::update(ViewMsj* mje) {
	ViewObjetoUpdateMsj* mjeCurrent = (ViewObjetoUpdateMsj*)mje;
	this->setXl(mjeCurrent->getX());
	this->setYl(mjeCurrent->getY());
	this->setAngulo(mjeCurrent->getAngulo());
	this->setIdEventoSonido(mjeCurrent->getIdEvento());

}

} /* namespace CLIENTE */
