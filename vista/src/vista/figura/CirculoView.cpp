/*
 * CirculoView.cpp
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#include "CirculoView.h"
#include "../../controller/DragAndDropManager.h"

void CirculoView::dropTemplate(DragAndDropManager* manager) {
	manager->dropNuevaFigura(this);
}

CirculoView::CirculoView() {

}

CirculoView::~CirculoView() {

}
