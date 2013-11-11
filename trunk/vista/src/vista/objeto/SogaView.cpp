/*
 * Sogaview.cpp
 *
 *  Created on: Oct 5, 2013
 *      Author: matias
 */

#include "SogaView.h"
namespace CLIENTE {

SogaView::SogaView(float xDesde, float yDesde,float xHasta, float yHasta, SDL_Texture * textura): UnionView(xDesde, yDesde, xHasta, yHasta,RADIO_SOGA_ESTATICA, textura) {
}


SogaView::~SogaView() {
	// TODO Auto-generated destructor stub
}

//void SogaView::dibujarse(SDL_Renderer * renderer, SDL_Rect & dest){
//	void dibujarse(SDL_Renderer * renderer);
//}

void SogaView::dibujarse(SDL_Renderer* renderer) {
	//ENTREGA 3 FALTA HACER SDL_RENDERCOLOR O ALGO ASI PARA CAMBIAR EL COLOR
	SDL_RenderDrawLine(renderer, this->xp, this->yp, this->xHastap, this->yHastap);
}

void SogaView::resizear() {
	tl->setVector(xl,yl);
	float xaux,yaux;
	tl->getResultadoInverso(xaux,yaux);
	xp = round(xaux);
	yp = round (yaux);
	tl->setVector(xHastal,yHastal);
	tl->getResultadoInverso(xaux,yaux);
	xHastap = round(xaux);
	yHastap = round (yaux);
	radiop = round(tl->escalarInversaEnX(radiol));

}
}



