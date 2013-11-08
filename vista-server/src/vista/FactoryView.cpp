/*
 * FactoryView.cpp
 *
 *  Created on: 21/09/2013
 *      Author: jonathan
 */

#include "FactoryView.h"
#include "SDL2/SDL.h"
#include <iostream>
using namespace std;

FactoryView::FactoryView() :
		View(0, 0) {
//	this->textura = textura;

}

FactoryView::~FactoryView() {
	// TODO Auto-generated destructor stub
}


void FactoryView::dibujarse(list<ViewMsj*> & lista){
//	SDL_Rect dest;
//	dest.h = this->getH();
//	dest.w = this->getW();
//	dest.x = this->getX();
//	dest.y = this->getY();
//	this->dibujarse(renderer, dest);
	cout << "Factory: ";
	cout << getXCentro() << " ";
	cout << getYCentro() << " ";
}

