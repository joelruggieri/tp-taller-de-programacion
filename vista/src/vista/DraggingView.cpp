/*
 * DraggingView.cpp
 *
 *  Created on: 10/09/2013
 *      Author: jonathan
 */

#include "DraggingView.h"

DraggingView::DraggingView(Dragueable * dragueable) {
	this->dragueable= dragueable;
}


DraggingView::~DraggingView() {
}

void DraggingView::dibujarse(SDL_Renderer* renderer) {
	if(this->dragueable->isDragging()){
		this->dragueable->getDragueado()->dibujarse(renderer);
	}
}
