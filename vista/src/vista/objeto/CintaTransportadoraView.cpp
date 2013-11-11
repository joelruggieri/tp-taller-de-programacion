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
namespace CLIENTE {
#define RADTODEG 57.295779513082320876f

CintaTransportadoraView::CintaTransportadoraView(float x, float y, float w,
		float h, SDL_Texture* textura) :
		ObjetoView(x, y, w, h, textura) {
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

//	FiguraView::dibujarse(renderer, dest);
//
//	CintaTransportadora *cinta = (CintaTransportadora*) getModelo();
//	if (!getModelo()) {
//		SDL_RenderCopy(renderer,getTexture(),NULL,&dest);
//	} else {
////		std::vector<SDL_Rect> &marcosPiezas = cinta->getMarcosPiezas();
////		std::vector<float> &angulosPiezas = cinta->getAngulosPiezas();
//
////		SDL_Rect* marcosRuedas = cinta->getMarcosRuedas();
//		float* angulosRuedas = cinta->getAngulosRuedas();
//
////		Resizer * r = Resizer::Instance();
////		r->adaptarDimensionLogica(marcosRuedas[0].x, marcosRuedas[0].y, marcosRuedas[0].x, marcosRuedas[0].y);
////		r->adaptarDimensionLogica(marcosRuedas[0].w, marcosRuedas[0].h, marcosRuedas[0].w, marcosRuedas[0].h);
////		r->adaptarDimensionLogica(marcosRuedas[1].x, marcosRuedas[1].y, marcosRuedas[1].x, marcosRuedas[1].y);
////		r->adaptarDimensionLogica(marcosRuedas[1].w, marcosRuedas[1].h, marcosRuedas[1].w, marcosRuedas[1].h);
//
//		// Ruedas
//		SDL_Rect aux1, aux2, auxRueda1, auxRueda2;
//		aux1 = aux2 = dest;
//		aux1.w = aux2.w = aux1.h = aux2.h = dest.h * 0.20;
//		aux2.x = dest.x + dest.w * 0.75;
//		aux1.y = aux2.y = dest.y + dest.h *0.38;
//		auxRueda1 = aux1;
//		auxRueda2 = aux2;
//		SDL_Rect aux3 = aux1;
//		aux3.x += aux1.w/2;
//		aux3.y += 3;
//		aux3.w = 10;
//		aux3.h = 3;
//		for (; aux3.x < (aux2.x+aux2.w/3); aux3.x += 13){
//			SDL_RenderCopy(renderer,pieza,NULL,&aux3);
//		}
//		aux3.x = aux1.x;
//		aux3.x += aux1.w/2;
//		aux3.y += (aux1.h - aux1.h*0.18);
//		for (; aux3.x < (aux2.x+aux2.w/3); aux3.x += 13){
//			SDL_RenderCopy(renderer,pieza,NULL,&aux3);
//		}
//		dibujarParte(renderer, auxRueda1, -angulosRuedas[0] * RADTODEG, rueda);
//		dibujarParte(renderer, auxRueda2, -angulosRuedas[1] * RADTODEG, rueda);
////		dibujarParte(renderer, marcosRuedas[0], angulosRuedas[0], rueda);
////		dibujarParte(renderer, marcosRuedas[1], angulosRuedas[1], rueda);
//	}

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
	recalcular();
	resizear();
}

int CintaTransportadoraView::getLayer() {
	return LAYER_CINTA;
}
}
