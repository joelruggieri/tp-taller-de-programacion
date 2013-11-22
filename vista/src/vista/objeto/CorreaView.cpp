/*
 * CorreaView.cpp
 *
 *  Created on: 15/10/2013
 *      Author: joel
 */

#include "CorreaView.h"
#include <cmath>
#define PI 3.14159265
namespace CLIENTE {
CorreaView::CorreaView(float xDesde, float yDesde, float xHasta, float yHasta, float radioi, float radiof,int numeroEvent,SDL_Texture * textura) :
		UnionView(xDesde, yDesde, xHasta, yHasta, RADIO_CORREA_ESTATICA,numeroEvent,textura) {

	//todo inicializar todo en cero.
	//v1xp, v1yp,v2xp,v2yp;
	radioil = radioi;
	radiofl = radiof;
}

CorreaView::~CorreaView() {
	// TODO Auto-generated destructor stub
}

void CorreaView::dibujarse(SDL_Renderer* renderer) {
//	dibujarseCirculoEstatico(renderer);
	int v1xi = v1xip * radioil;
	int v1yi = v1yip * radioil;

	int v1xf = v1xip * radiofl;
	int v1yf = v1yip * radiofl;
	SDL_SetRenderDrawColor(renderer,10,10,10,0);
//	SDL_RenderDrawLine(renderer,xp + v1xi, yp - v1yi, xHastap + v1xf, yHastap - v1yf);
//	SDL_RenderDrawLine(renderer,xp - v1xi, yp + v1yi, xHastap - v1xf, yHastap + v1yf);
	float longitud = 0.9;
	for (int i = 0; i < 9; ++i) {
		longitud += 0.01;
		SDL_RenderDrawLine(renderer,xp + v1xi*longitud, yp - v1yi*longitud, xHastap + v1xf*longitud, yHastap - v1yf*longitud);
		SDL_RenderDrawLine(renderer,xp - v1xi*longitud, yp + v1yi*longitud, xHastap - v1xf*longitud, yHastap + v1yf*longitud);

	}

	this->dibujarseCirculoEstatico(renderer);

}

void CorreaView::update(ViewMsj *m) {
	super::update(m);
	ViewObjetoUnionUpdateMsj* mjeCurrent = (ViewObjetoUnionUpdateMsj*) m;
	this->radioil = mjeCurrent->getRadioInicial();
	this->radiofl = mjeCurrent->getRadioFinal();

	double xHastaRespectoXDesde = (float) this->xHastal - (float) this->xl;	//director
	double yHastaRespectoYDesde = (float) this->yHastal - (float) this->yl;	//director
	double norma = sqrt((xHastaRespectoXDesde * xHastaRespectoXDesde) + (yHastaRespectoYDesde * yHastaRespectoYDesde));
	xHastaRespectoXDesde = xHastaRespectoXDesde / norma;
	yHastaRespectoYDesde = yHastaRespectoYDesde / norma;

	v1xil = (-yHastaRespectoYDesde);	//ya ahi esta v1 en el origen
	v1yil = xHastaRespectoXDesde;
	this->setIdEventoSonido(mjeCurrent->getIdEvento());
}

void CLIENTE::CorreaView::resizear() {
	super::resizear();
	v1xip = tl->escalarInversaEnX(v1xil);
	v1yip = tl->escalarInversaEnX(v1yil);
}
}

