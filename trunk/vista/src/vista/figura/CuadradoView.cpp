/*
 * CuadradoView.cpp
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#include "CuadradoView.h"
#include "../../controller/DropController.h"

void CuadradoView::dropTemplate(DropController* manager) {
	manager->dropNuevaFigura(this);
}

CuadradoView::CuadradoView() {

}

CuadradoView::~CuadradoView() {

}
