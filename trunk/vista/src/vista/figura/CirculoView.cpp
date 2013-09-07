/*
 * CirculoView.cpp
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#include "CirculoView.h"
#include "../../controller/DropController.h"

void CirculoView::dropTemplate(DropController* manager) {
	manager->dropNuevaFigura(this);
}

CirculoView::CirculoView() {

}

CirculoView::~CirculoView() {

}
