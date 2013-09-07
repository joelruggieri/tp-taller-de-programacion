/*
 * CuadradoView.cpp
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#include "CuadradoView.h"
#include "../../controller/DragAndDropManager.h"

void CuadradoView::dropTemplate(DragAndDropManager* manager) {
	manager->dropNuevaFigura(this);
}

CuadradoView::CuadradoView() {

}

CuadradoView::~CuadradoView() {

}
