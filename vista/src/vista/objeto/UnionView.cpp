/*
 * UnionView.cpp
 *
 *  Created on: 16/10/2013
 *      Author: jonathan
 */

#include "UnionView.h"
#include "SDL2/SDL.h"
#include "../../ConstantesVista.h"
#include "../CargadorDeTextures.h"
namespace CLIENTE {
UnionView::UnionView(float xDesde,float yDesde,float xHasta, float yHasta,float radio, SDL_Texture * textura):ObjetoView(xDesde,yDesde,20,20,CargadorDeTextures::Instance()->cargarTexture(PATH_EDICION_UNION)) {
	xHastal = xHasta;
	yHastal = yHasta;
	radiol = radio;
	xHastap = 0;
	yHastap = 0;
	radiop = 0;
	estatica = true;
}

UnionView::~UnionView() {
//	if(getModelo() != NULL){
//		getModelo()->removeObserver(this);
//	}
}

void UnionView::dibujarseCirculoEstatico(SDL_Renderer* ren){
//	Union* u = (Union *)this->getModelo();
//
	if(this->estatica){
//		SDL_Rect dest;
//		float wi,hi;
//		float xi,yi;
//		Resizer::Instance()->adaptarDimensionLogica(u->getRadio()*2,u->getRadio()*2,wi,hi);
//		tl.setVector(u->getX(),u->getY());
//		tl.getResultadoInverso(xi,yi);
//		dest.h = hi;
//		dest.w = wi;
//		dest.x = xi - wi/2;
//		dest.y = yi - hi/2;
//		SDL_RenderCopyEx(ren,this->getTexture(), NULL, &dest,this->getModelo()->getRotacion(),NULL,SDL_FLIP_NONE);
//		SDL_RenderCopy(ren,this->getTexture(),NULL,&dest);
	}
}

void UnionView::dibujarse(SDL_Renderer* ren, Uint8 r, Uint8 g, Uint8 b) {
	SDL_SetRenderDrawColor(ren,r,g,b,0);
	SDL_RenderDrawLine(ren,this->xp,this->yp,this->xHastap,this->yHastap);
//	this->dibujarseCirculoEstatico(ren);

}

void UnionView::update(ViewMsj*m) {
	ViewObjetoUnionUpdateMsj* mjeCurrent = (ViewObjetoUnionUpdateMsj*)m;
	this->xl = mjeCurrent->getX();
	this->yl= mjeCurrent->getY();
	this->xHastal = mjeCurrent->getXHasta();
	this->yHastal = mjeCurrent->getYHasta();
	estatica = mjeCurrent->isEstatico();
}

void UnionView::resizear() {
	tl->setVector(xl,yl);
	float xaux,yaux;
	tl->getResultadoInverso(xaux,yaux);
	xp = round(xaux);
	yp = round (yaux);
	radiop = round(tl->escalarInversaEnX(radiol));
}

int UnionView::getLayer() {
	return LAYER_UNIONES;
}


}
