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
UnionView::UnionView(float x,float y, SDL_Texture * textura):ObjetoView(x,y,20,20,CargadorDeTextures::Instance()->cargarTexture(PATH_EDICION_UNION)) {
	xDesde = 0;
	yDesde = 0;
	xHasta = 0;
	yHasta = 0;

}

UnionView::~UnionView() {
//	if(getModelo() != NULL){
//		getModelo()->removeObserver(this);
//	}
}

void UnionView::dibujarseEstatica(SDL_Renderer* ren){
//	Union* u = (Union *)this->getModelo();
//
//	if(u->estaEstatica()){
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
//	}
}

void UnionView::dibujarse(SDL_Renderer* ren, Uint8 r, Uint8 g, Uint8 b) {
//	SDL_SetRenderDrawColor(ren,r,g,b,0);
//	SDL_RenderDrawLine(ren,this->xDesde,this->yDesde,this->xHasta,this->yHasta);
//
//	this->dibujarseEstatica(ren);

}

void UnionView::update(ViewMsj *){
//	super::update();
//	Union* un = (Union*)this->getModelo();
//	tl.setVector(un->getXInicial(),un->getYInicial());
//	float xDesde;
//	float yDesde;
//	tl.getResultadoInverso(xDesde,yDesde);
//	this->xDesde = xDesde;
//	this->yDesde = yDesde;
//	tl.setVector(un->getXFinal(),un->getYFinal());
//	float xHasta;
//	float yHasta;
//	tl.getResultadoInverso(xHasta,yHasta);
//	this->xHasta =xHasta;
//	this->yHasta =yHasta;
//	tl.setVector(un->getX(), un->getY());
//	tl.getResultadoInverso(xHasta, yHasta);
//
//	this->setXc(xHasta);
//	this->setYc(yHasta);

}

void UnionView::resizear() {
	super::resizear();
}

int UnionView::getLayer() {
	return LAYER_UNIONES;
}
}
