/*
 * Sogaview.cpp
 *
 *  Created on: Oct 5, 2013
 *      Author: matias
 */

#include "SogaView.h"
namespace CLIENTE {

SogaView::SogaView(float x, float y, SDL_Texture * textura): UnionView(x, y, textura) {
}


SogaView::~SogaView() {
	// TODO Auto-generated destructor stub
}

void SogaView::dibujarse(SDL_Renderer * renderer, SDL_Rect & dest){
	void dibujarse(SDL_Renderer * renderer);
}

void SogaView::dibujarse(SDL_Renderer* renderer) {

	SDL_RenderDrawLine(renderer, this->xDesdeP, this->yDesdep, this->xHastap, this->yHastaP	);
}
}

void CLIENTE::SogaView::update(ViewMsj*m) {
	ViewObjetoUnionUpdateMsj* mjeCurrent = (ViewObjetoUnionUpdateMsj*)m;
	this->xDesde = mjeCurrent->getX();
	this->yDesde = mjeCurrent->getY();
	this->xHasta = mjeCurrent->getXHasta();
	this->yHasta = mjeCurrent->getYHasta();
}

void CLIENTE::SogaView::resizear() {
tl->setVector(xDesde, yDesde);
tl->getResultadoInverso((this->xDesdeP), (this->yDesdep));
tl->setVector(xHasta, yHasta);
tl->getResultadoInverso((this->xHastap), (this->yHastaP));




}
