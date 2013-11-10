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
CorreaView::CorreaView(float xDesde, float yDesde,float xHasta, float yHasta, SDL_Texture * textura): UnionView(xDesde, yDesde, xHasta, yHasta,RADIO_CORREA_ESTATICA, textura) {


	//todo inicializar todo en cero.
	//v1xp, v1yp,v2xp,v2yp;
	calcularVectoresLogicos();
}

CorreaView::~CorreaView() {
	// TODO Auto-generated destructor stub
}


void CorreaView::dibujarse(SDL_Renderer* renderer){
	dibujarseCirculoEstatico(renderer);

//	SDL_SetRenderDrawColor(renderer,10,10,10,0);
//	SDL_RenderDrawLine(renderer,this->xp + v1iX,this->yp + v1iY,this->xHastap + v1fX,this->yHastap + v1fY);
//	SDL_RenderDrawLine(renderer,this->xp + v2iX,this->yp + v2iY,this->xHastap + v2fX,this->yHastap + v2fY);
//	float longitud = 0.9;
//	for (int i = 0; i < 9; ++i) {
//		longitud += 0.01;
//		SDL_RenderDrawLine(renderer,this->xDesde + v1iX *longitud,this->yDesde + v1iY*longitud,this->xHasta + v1fX*longitud,this->yHasta + v1fY*longitud);
//		SDL_RenderDrawLine(renderer,this->xDesde + v2iX*longitud,this->yDesde + v2iY*longitud,this->xHasta + v2fX*longitud,this->yHasta + v2fY*longitud);
//
//	}
//
//	this->dibujarseCirculoEstatico(renderer, estatica);

}

void CorreaView::calcularVectoresLogicos() {

}

void CorreaView::update(ViewMsj *m){
	super::update(m);

	//	super::update(m);
////	super::update();
//	ViewObjetoUnionUpdateMsj* mje = (ViewObjetoUnionUpdateMsj*) m ;
//	this->estatica = mje->isEstatico();
//	this->x = mje->getX();
//	this->y = mje->getY();
//	this->radio = mje->getRadio();
//	this->angulo = mje->getAngulo();
//	double xHastaRespectoXDesde = (float)this->xHasta - (float)this->xDesde;
//	double yHastaRespectoYDesde = (float)this->yHasta - (float)this->yDesde;
//	double norma = sqrt((xHastaRespectoXDesde*xHastaRespectoXDesde) + (yHastaRespectoYDesde*yHastaRespectoYDesde));
//	xHastaRespectoXDesde = xHastaRespectoXDesde / norma;
//	yHastaRespectoYDesde = yHastaRespectoYDesde / norma;
//	//V1o
//	float v1oX = (-yHastaRespectoYDesde);
//	float v1oY = xHastaRespectoXDesde;
////
////	if(this->getModelo() == NULL){
////		 v1iX = v1oX *((float)this->getW()/2);
////		 v1iY = v1oY * ((float)this->getW()/2);
////		 v1fX = v1oX * ((float)this->getW()/2);
////		 v1fY = v1oY * ((float)this->getW()/2);
////	} else {
////		Correa* c = (Correa*)this->getModelo();
//		float radio,foo;
//		tl->setVector(mje->getRadioInicial() * 0.8,0.0f);
//		tl->getResultadoInverso(radio,foo);
//		v1iX = v1oX * radio;
//		v1iY = v1oY * radio;
//		tl->setVector(mje->getRadioFinal() * 0.8,0.0f);
//		tl->getResultadoInverso(radio,foo);
//		v1fX = v1oX * radio;
//		v1fY = v1oY * radio;
////	}
////	//V2o
//	v2iX = -v1iX;
//	v2iY = -v1iY;
//	v2fX = -v1fX;
//	v2fY = -v1fY;

}
}

//void CLIENTE::CorreaView::dibujarseCirculoEstatico(SDL_Renderer* ren, bool estatica) {
//	SDL_Rect dest;
//	if (estatica){
//			float wi,hi;
//			float xi,yi;
//			tl->setVector(this->radio*2,this->radio*2);
//			tl->getResultadoInverso(wi,hi);
//			tl->setVector(this->x,this->y);
//			tl->getResultadoInverso(xi,yi);
////			dest.h = hi;
////			dest.w = wi;
//			dest.h = hi;
//			dest.w = wi;
//			dest.x = xi - wi/2;
//			dest.y = yi - hi/2;
//			SDL_RenderCopyEx(ren,this->getTexture(), NULL, &dest,this->angulo,NULL,SDL_FLIP_NONE);
////			SDL_RenderCopy(ren,this->getTexture(),NULL,&dest);
//	}
//}
