/*
 * ScrollView.cpp
 *
 *  Created on: 13/09/2013
 *      Author: jonathan
 */

#include "ScrollView.h"
ScrollView::ScrollView(FlechaScrollView* flechaArriba,
		FlechaScrollView* flechaAajo, Scroll* scroll, int sleep):View(0,0,0,0) {
	this->abajo = flechaAajo;
	this->arriba = flechaArriba;
	this->sleep = sleep;
	this->contAbajo = sleep;
	this->contArriba = sleep;
	scroll->addObserver(this);
}

ScrollView::~ScrollView() {
	delete this->abajo;
	delete this->arriba;
}

void ScrollView::dibujarse(SDL_Renderer* renderer) {
	if(this->abajo->isPresionado() && contAbajo++ == sleep){
		this->abajo->setPresionado(false);
	}
	if(this->arriba->isPresionado() && contArriba++ == sleep){
		this->arriba->setPresionado(false);
	}
	this->abajo->dibujarse(renderer);
	this->arriba->dibujarse(renderer);
}

void ScrollView::notify(Observable* obs) {
	Scroll * scroll = (Scroll *) obs;
	if(scroll->getltimoClick() > 0){
		this->contArriba = 1;
		this->arriba->setPresionado(true);
	}
	if(scroll->getltimoClick() < 0){
		this->contAbajo = 0;
		this->abajo->setPresionado(true);
	}
}
