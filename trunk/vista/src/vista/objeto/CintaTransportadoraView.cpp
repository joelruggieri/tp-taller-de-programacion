/*
 * CintaTransportadoraView.cpp
 *
 *  Created on: 05/10/2013
 *      Author: javier
 */

#include "CintaTransportadoraView.h"

#include "../figura/FiguraView.h"
#include "ObjetoView.h"
#include "../CargadorDeTextures.h"
#include "../../ConstantesVista.h"
#include "../CargadorDeSonidos.h"
#include "src/Logger.h"
namespace CLIENTE {
#define RADTODEG 57.295779513082320876f

CintaTransportadoraView::CintaTransportadoraView(float x, float y, float w,
		float h,int numeroEvent,SDL_Texture* textura) :
		ObjetoView(x, y, w, h, LAYER_CINTA,numeroEvent,textura) {
	rueda = CargadorDeTextures::Instance()->cargarTexture(PATH_VISTA_ENGRANAJE);
	altocintal = 1;
}

CintaTransportadoraView::~CintaTransportadoraView() {
	// TODO Auto-generated destructor stub
}

void CintaTransportadoraView::dibujarse(SDL_Renderer*r) {
	SDL_Rect dest;
//	calculo el alto donde va a estar la plataforma
	dest.x = xp + radiop;
	dest.y = yp;
	dest.w = wp - 2 * radiop;
	dest.h = altocintap;
	SDL_RenderCopy(r, this->getTexture(), NULL, &dest);
	dest.y = yp + hp - altocintap;
	SDL_RenderCopy(r, this->getTexture(), NULL, &dest);
	dest.x = xmedp;
	dest.w = radiop * 2;
	dest.h = radiop * 2;
	dest.y = yp;

	if (angulo) {
		SDL_RenderCopyEx(r, rueda, NULL, &dest, angulo, NULL, SDL_FLIP_NONE);
		dest.x = xizqp;
		SDL_RenderCopyEx(r, rueda, NULL, &dest, angulo, NULL, SDL_FLIP_NONE);
		dest.x = xderp;
		SDL_RenderCopyEx(r, rueda, NULL, &dest, angulo, NULL, SDL_FLIP_NONE);
	} else {
		SDL_RenderCopy(r, rueda, NULL, &dest);
		dest.x = xizqp;
		SDL_RenderCopy(r, rueda, NULL, &dest);
		dest.x = xderp;
		SDL_RenderCopy(r, rueda, NULL, &dest);
	}
}

void CintaTransportadoraView::resizear() {
	super::resizear();
	radiop = tl->escalarInversaEnX(RADIO_EJE_CINTA_LOG);
	xizqp = tl->escalarInversaEnX(xizql);
	xderp = tl->escalarInversaEnX(xderl);
	xmedp = tl->escalarInversaEnX(xmedl);
	altocintap = tl->escalarInversaEnX(altocintal);
}

void CintaTransportadoraView::recalcular() {
	xizql = xl - wl / 2.0;
	xderl = xl + wl / 2.0 - 2 * RADIO_EJE_CINTA_LOG;
	xmedl = xl - RADIO_EJE_CINTA_LOG;
}

void CintaTransportadoraView::update(ViewMsj* mje) {
	ViewObjetoConAnchoUpdateMsj* mjeCurrent = (ViewObjetoConAnchoUpdateMsj*) mje;
	this->setXl(mjeCurrent->getX());
	this->setYl(mjeCurrent->getY());
	this->setAngulo(mjeCurrent->getAngulo());
	this->setWl(mjeCurrent->getAncho());
	this->setIdEventoSonido(mjeCurrent->getIdEvento());
	recalcular();
}

}
