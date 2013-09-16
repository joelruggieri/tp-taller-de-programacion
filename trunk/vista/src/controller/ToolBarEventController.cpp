/*
 * ToolBarEventController.cpp
 *
 *  Created on: 15/09/2013
 *      Author: ezequiel
 */

#include "ToolBarEventController.h"

ToolBarEventController::ToolBarEventController(ZonaToolBar* zona) {
	this->zona = zona;

}

ToolBarEventController::~ToolBarEventController() {
	// TODO Auto-generated destructor stub
}

bool ToolBarEventController::clickDown(int int1, int int2) {

	//TODO SI SE HIZO CLICK  EN LA ZONA QUE RETORNE FALSE PARA QUE NO SE PROPAGUE A LAS OTRAS ZONAS.
	this->zona->seleccionarHerramienta(int1, int2);
	return true;
}

bool ToolBarEventController::clickUp(int int1, int int2) {
	this->zona->seleccionarHerramienta(int1, int2);
	return true;
}

bool ToolBarEventController::rightClickDown(int int1, int int2) {
	return true;

}

bool ToolBarEventController::rightClickUp(int int1, int int2) {
	return true;

}

bool ToolBarEventController::mouseMotion(int int1, int int2) {
	return true;
}
