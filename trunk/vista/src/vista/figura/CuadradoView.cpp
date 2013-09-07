/*
 * CuadradoView.cpp
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#include "CuadradoView.h"
#include "../../controller/DropManager.h"

void CuadradoView::dropTemplate(DropManager* manager) {
	manager->dropNuevaFigura(this);
}

CuadradoView::CuadradoView() {

}

CuadradoView::~CuadradoView() {

}
