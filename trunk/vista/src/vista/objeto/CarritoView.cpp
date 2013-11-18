/*
 * CarritoView.cpp
 *
 *  Created on: 14/11/2013
 *      Author: joel
 */

#include "CarritoView.h"
#include <src/mensajes/viewMensaje/ViewCarritoMsj.h>
#include "../CargadorDeTextures.h"
CLIENTE::CarritoView::CarritoView(float x, float y, float w, float h,
		SDL_Texture* textura): ObjetoView(x, y, w, h,textura) {
	tRueda = CargadorDeTextures::Instance()->cargarTexture(PATH_VISTA_MOTOR);
}


CLIENTE::CarritoView::~CarritoView() {
	// TODO Auto-generated destructor stub
}


void CLIENTE::CarritoView::update(ViewMsj* mje) {
	ViewCarritoMsj* mjeCurrent = (ViewCarritoMsj*)mje;
	this->setXl(mjeCurrent->getX());
	this->setYl(mjeCurrent->getY());
	this->setAngulo(mjeCurrent->getRotCarrito());
	xil = mjeCurrent->getXi();
	yil = mjeCurrent->getYi();
	xdl = mjeCurrent->getXd();
	ydl = mjeCurrent->getYd();
	rotR = mjeCurrent->getRotRuedaD();
}

void CLIENTE::CarritoView::resizear() {
	super::resizear();
	float xesquina = xil - RADIO_RUEDA_CARRITO;
	float yesquina = yil + RADIO_RUEDA_CARRITO;
	tl->setVector(xesquina, yesquina);
	float xpf, ypf;
	tl->getResultadoInverso(xpf,ypf);
	xip = round(xpf);
	yip = round (ypf);
	xesquina = xdl - RADIO_RUEDA_CARRITO;
	yesquina = ydl + RADIO_RUEDA_CARRITO;
	tl->setVector(xesquina, yesquina);
	tl->getResultadoInverso(xpf,ypf);
	xdp = round(xpf);
	ydp = round (ypf);
	radioRuedaP = tl->escalarInversaEnX(RADIO_RUEDA_CARRITO);
}

void CLIENTE::CarritoView::dibujarse(SDL_Renderer* r) {
	super::dibujarse(r);
	SDL_Rect dest;
	dest.h = this->radioRuedaP *2;
	dest.w = this->radioRuedaP *2;
	dest.x = this->xip;
	dest.y = this->yip;
	SDL_RenderCopyEx(r,this->tRueda, NULL, &dest,this->rotR* 180 / 3.14,NULL,SDL_FLIP_NONE);

	dest.x = this->xdp;
	dest.y = this->ydp;
	SDL_RenderCopyEx(r,this->tRueda, NULL, &dest,this->rotR * 180 / 3.14,NULL,SDL_FLIP_NONE);

}
