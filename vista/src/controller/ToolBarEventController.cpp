/*
 * ToolBarEventController.cpp
 *
 *  Created on: 15/09/2013
 *      Author: ezequiel
 */

#include "ToolBarEventController.h"

ToolBarEventController::ToolBarEventController(ZonaToolBar* zona) {
	this->zona = zona;
	this->seleccionado = false;
}

ToolBarEventController::~ToolBarEventController() {
	// TODO Auto-generated destructor stub
}

bool ToolBarEventController::clickDown(int int1, int int2) {


	if (this->zona->zonaFueSeleccionada(int1, int2))
	{
	this->zona->seleccionarHerramienta(int1, int2);
	this->seleccionado = true ;
	return false;
	}
	else
		{
		this->zona->desSeleccionarHerramienta(int1,int2);
		return true ;
		}
}

bool ToolBarEventController::clickUp(int int1, int int2) {
if (this->seleccionado)
{
this->zona->desSeleccionarHerramienta(int1, int2);
this->seleccionado = false;
return false;
}
else return  true;
}

bool ToolBarEventController::rightClickDown(int int1, int int2) {
return (!this->zona->zonaFueSeleccionada(int1, int2));
}

bool ToolBarEventController::rightClickUp(int int1, int int2) {
	return (!this->zona->zonaFueSeleccionada(int1, int2));

}

bool ToolBarEventController::mouseMotion(int int1, int int2) {
	return (!this->zona->zonaFueSeleccionada(int1, int2));
}