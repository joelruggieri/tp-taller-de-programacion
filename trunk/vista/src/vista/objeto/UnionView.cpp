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
UnionView::UnionView(float xDesde,float yDesde,float xHasta, float yHasta,float radio, SDL_Texture * textura):ObjetoView(xDesde,yDesde,20,20,LAYER_UNIONES,CargadorDeTextures::Instance()->cargarTexture(PATH_EDICION_UNION)) {
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
		SDL_Rect dest;
		dest.h = radiop*2;
		dest.w = radiop*2;
		dest.x = xcp - radiop;
		dest.y = ycp - radiop;
		SDL_RenderCopy(ren,this->getTexture(),NULL,&dest);
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
	xcl = (xl + xHastal) / 2.0;
	ycl = (yl + yHastal) / 2.0;
	estatica = mjeCurrent->isEstatico();
	conEslabon = mjeCurrent->isConEslabon();
	this->setIdEventoSonido(mjeCurrent->getIdEvento());
}

void UnionView::resizear() {
	float xaux,yaux;
	tl->setVector(xl,yl);
	tl->getResultadoInverso(xaux,yaux);
	xp = round(xaux);
	yp = round (yaux);
	tl->setVector(xHastal,yHastal);
	tl->getResultadoInverso(xaux,yaux);
	xHastap = round(xaux);
	yHastap = round (yaux);
	radiop = round(tl->escalarInversaEnX(radiol));
	tl->setVector(xcl,ycl);
	tl->getResultadoInverso(xaux,yaux);
	xcp = round(xaux);
	ycp = round (yaux);


}


}
