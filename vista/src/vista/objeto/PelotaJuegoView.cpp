/*
 * PelotaJuegoView.cpp
 *
 *  Created on: 06/10/2013
 *      Author: ezequiel
 */

#include "PelotaJuegoView.h"
#include <SDL2/SDL_mixer.h>
#include "../CargadorDeSonidos.h"
namespace CLIENTE {
PelotaJuegoView::PelotaJuegoView(float x, float y, float w, float h,int numeroEvent,SDL_Texture * textura): ObjetoView(x, y, w, h,numeroEvent,textura) {

}

PelotaJuegoView::~PelotaJuegoView() {
	// TODO Auto-generated destructor stub
}

void PelotaJuegoView::dibujarse(SDL_Renderer* renderer){
	CargadorDeSonidos* cargador = CargadorDeSonidos::Instance();
	if(this->getIdEventoSonido() == ID_SONIDO_PELOTA){
		if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ){
				printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
		}
		//Mix_Chunk* sonido = cargador->getSonido(ID_SONIDO_PELOTA);
		Mix_Chunk* sonido = Mix_LoadWAV(PATH_SONIDO_PELOTA);
		if (sonido == NULL){
			std::cout << "conchudo" << endl;
		}
		Mix_PlayChannelTimed(-1,sonido,1,520);
		cout<< "entro aca" << std::endl;
		//usleep(520000);
	}
	this->idEventoSonido = 0;
	super::dibujarse(renderer);
	Mix_Pause(-1);


}

}

void CLIENTE::PelotaJuegoView::update(ViewMsj* mje) {
ViewObjetoUpdateMsj* mjeCurrent = (ViewObjetoUpdateMsj*)mje;
this->setXl(mjeCurrent->getX());
this->setYl(mjeCurrent->getY());
this->setAngulo(mjeCurrent->getAngulo());
this->setIdEventoSonido(mjeCurrent->getIdEvento());

}
