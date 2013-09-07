/*
 * CirculoView.cpp
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#include "CirculoView.h"
#include "../../controller/DropManager.h"

void CirculoView::dropTemplate(DropManager* manager) {
	manager->dropNuevaFigura(this);
}

CirculoView::CirculoView() {

}

CirculoView::~CirculoView() {

}
