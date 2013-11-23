/*
 * PelotaJuegoView.cpp
 *
 *  Created on: 06/10/2013
 *      Author: ezequiel
 */

#include "PelotaJuegoView.h"
#include <SDL2/SDL_mixer.h>
#include "../CargadorDeSonidos.h"
#include "src/Logger.h"
namespace CLIENTE {
PelotaJuegoView::PelotaJuegoView(float x, float y, float w, float h,int numeroEvent,SDL_Texture * textura): ObjetoView(x, y, w, h,numeroEvent,textura) {
	sonido =  CargadorDeSonidos::Instance()->getSonido(ID_SONIDO_PELOTA);
}

PelotaJuegoView::~PelotaJuegoView() {
	// TODO Auto-generated destructor stub
}

void PelotaJuegoView::dibujarse(SDL_Renderer* renderer){
//	CargadorDeSonidos* cargador = CargadorDeSonidos::Instance();
	if(this->getIdEventoSonido() == ID_SONIDO_PELOTA){
		std::cout<< "hola pelota" << endl;
		//Mix_Chunk* sonido = cargador->getSonido(ID_SONIDO_PELOTA);
		//if(!sonido)	sonido = Mix_LoadWAV(PATH_SONIDO_PELOTA);
		if (sonido == NULL){
			Logger log;
			log.error("no se puede reproducir el sonido de la pelota");
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

void CLIENTE::PelotaJuegoView::update(ViewMsj* mje) {
ViewObjetoUpdateMsj* mjeCurrent = (ViewObjetoUpdateMsj*)mje;
this->setXl(mjeCurrent->getX());
this->setYl(mjeCurrent->getY());
this->setAngulo(mjeCurrent->getAngulo());
this->setIdEventoSonido(mjeCurrent->getIdEvento());

}
