/*
 * View.cpp
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#include "TrianguloView.h"
#include "../../controller/DragAndDropManager.h"

void TrianguloView::dropTemplate(DragAndDropManager* manager) {
	manager->dropNuevaFigura(this);
}

TrianguloView::TrianguloView() {

}

TrianguloView::~TrianguloView() {

}
