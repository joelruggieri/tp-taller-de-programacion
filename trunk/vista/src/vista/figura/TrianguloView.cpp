/*
 * View.cpp
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#include "TrianguloView.h"
#include "../../controller/DropManager.h"

void TrianguloView::dropTemplate(DropManager* manager) {
	manager->dropNuevaFigura(this);
}

TrianguloView::TrianguloView() {

}

TrianguloView::~TrianguloView() {

}
