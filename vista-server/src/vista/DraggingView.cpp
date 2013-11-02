/*
 * DraggingView.cpp
 *
 *  Created on: 10/09/2013
 *      Author: jonathan
 */

#include "DraggingView.h"
#include "figura/FiguraView.h"
#include <iostream>
using namespace std;

DraggingView::DraggingView(Dragueable * dragueable) {
	this->dragueable= dragueable;
}


DraggingView::~DraggingView() {
}

void DraggingView::dibujarse(list<ViewMsj*> & lista){
	if(this->dragueable->isDragging()){
		this->dragueable->getDragueado()->dibujarse(lista);
	}
}

