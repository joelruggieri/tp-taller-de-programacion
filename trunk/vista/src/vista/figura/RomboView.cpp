/*
 * RomboView.cpp
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#include "RomboView.h"
#include "../../controller/DragAndDropManager.h"

RomboView::RomboView() {
	// TODO Auto-generated constructor stub

}

RomboView::~RomboView() {
	// TODO Auto-generated destructor stub
}

void RomboView::dropTemplate(DragAndDropManager* manager) {
	manager->dropNuevaFigura(this);
}
