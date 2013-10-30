/*
 * ScrollView.cpp
 *
 *  Created on: 13/09/2013
 *      Author: jonathan
 */

#include "ScrollView.h"
ScrollView::ScrollView(Scroll* scroll, int sleep):View(0,0) {
//	this->sleep = sleep;
//	this->contAbajo = sleep;
//	this->contArriba = sleep;
	scroll->addObserver(this);
}

ScrollView::~ScrollView() {
}

void ScrollView::dibujarse(SDL_Renderer* renderer) {
//	if(this->abajo->isPresionado() && contAbajo++ == sleep){
//		this->abajo->setPresionado(false);
//	}
//	if(this->arriba->isPresionado() && contArriba++ == sleep){
//		this->arriba->setPresionado(false);
//	}
//	this->abajo->dibujarse(renderer);
//	this->arriba->dibujarse(renderer);
	cout << "Scroll: ";
	cout << getXCentro() << " ";
	cout << getYCentro() << " ";
}

void ScrollView::notify(Observable* obs, event_type T) {
	if(T == CAMBIO_VISTA){
//		Scroll * scroll = (Scroll *) obs;
//		if(scroll->getltimoClick() > 0){
//			this->contArriba = 1;
////			this->arriba->setPresionado(true);
//		}
//		if(scroll->getltimoClick() < 0){
//			this->contAbajo = 0;
//			this->abajo->setPresionado(true);
//		}
	}
}

//void ScrollView::resizear() {
////	cout << "se ha resizeado el scrool view" << endl ;
//	this->setW(Resizer::Instance()->resizearDistanciaX(this->getW()));
//	this->setH(Resizer::Instance()->resizearDistanciaX(this->getH()));
//	this->setXc(Resizer::Instance()->resizearDistanciaX(this->getXCentro()));
//	this->setYc(Resizer::Instance()->resizearPosicionY(this->getYCentro()));
//}
//
//void ScrollView::dibujarse(SDL_Renderer* renderer, SDL_Rect& dest) {
//	this->dibujarse(renderer);
//}
