/*
 * Sogaview.cpp
 *
 *  Created on: Oct 5, 2013
 *      Author: matias
 */

#include "SogaView.h"
#include "../CargadorDeTextures.h"
namespace CLIENTE {

SogaView::SogaView(float xDesde, float yDesde, float xHasta, float yHasta, SDL_Texture * textura) :
		UnionView(xDesde, yDesde, xHasta, yHasta, RADIO_SOGA_ESTATICA, textura) {
	texturaEslabon = CargadorDeTextures::Instance()->cargarTexture(PATH_VISTA_GANCHO);
	primerTramo = true;
	segundoTramo = true;
}

SogaView::~SogaView() {
	// TODO Auto-generated destructor stub
}

//void SogaView::dibujarse(SDL_Renderer * renderer, SDL_Rect & dest){
//	void dibujarse(SDL_Renderer * renderer);
//}

void SogaView::dibujarse(SDL_Renderer* renderer) {
	//ENTREGA3 FALTA HACER SDL_RENDERCOLOR O ALGO ASI PARA CAMBIAR EL COLOR y ademas no se esta renderizando el circulo del diome.
	if (conEslabon) {
		if(primerTramo){
			SDL_RenderDrawLine(renderer, this->xp, this->yp, this->xEslabonp, this->yEslabonp);
		}
		if(segundoTramo){
			SDL_RenderDrawLine(renderer, this->xEslabonp, this->yEslabonp, this->xHastap, this->yHastap);
		}
		SDL_Rect dest;
		dest.h = this->anchoEslabonP;
		dest.w = this->anchoEslabonP;
		dest.x = this->xEslabonDibp;
		dest.y = this->yEslabonDibp;
		SDL_RenderCopy(renderer,texturaEslabon,NULL,&dest);
	} else {
		SDL_RenderDrawLine(renderer, this->xp, this->yp, this->xHastap, this->yHastap);
	}
	dibujarseCirculoEstatico(renderer);
}

void SogaView::update(ViewMsj*m) {
	super::update(m);
	ViewObjetoUnionUpdateMsj* mjeCurrent = (ViewObjetoUnionUpdateMsj*) m;
	if (conEslabon) {
		xEslabonl = mjeCurrent->getXEslb();
		yEslabonl = mjeCurrent->getYEslb();
		primerTramo = mjeCurrent->isActivoPrimerTramo();
		segundoTramo = mjeCurrent->isActivoSegundoTramo();
	}
}

void SogaView::resizear() {
	super::resizear();
	if (conEslabon) {
		float xaux, yaux;
		float corr = ANCHO_ESLABON_SOGA / 2.0;
		tl->setVector(xEslabonl, yEslabonl);
		tl->getResultadoInverso(xaux, yaux);
		xEslabonp = round(xaux);
		yEslabonp = round(yaux);
		//calculo para dibujar el eslabon.
		tl->setVector(xEslabonl - corr, yEslabonl + corr);
		tl->getResultadoInverso(xaux, yaux);
		xEslabonDibp = round(xaux);
		yEslabonDibp = round(yaux);
		anchoEslabonP = tl->escalarInversaEnX(ANCHO_ESLABON_SOGA);
	}
}

void SogaView::setPosEslabonL(float x, float y) {
	xEslabonl = x;
	yEslabonl = y;
}

}
