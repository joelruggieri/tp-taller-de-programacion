/*
 * GeneralEventController.cpp
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#include "GeneralEventController.h"
#include "mouseEventController/MouseEventPriorComparator.h"

GeneralEventController::GeneralEventController() {
	// TODO Auto-generated constructor stub

}

GeneralEventController::~GeneralEventController() {
	list<MouseControllerPrioridades*>::iterator it;
	for (it=this->mouseControllers.begin(); it!=this->mouseControllers.end(); ++it){
		delete *it;
	}
}

void GeneralEventController::addMouseController(MouseEventController* controller,
		int prioridadClick, int prioridadMotion) {
	this->mouseControllers.push_back(new MouseControllerPrioridades(controller,prioridadClick,prioridadMotion));
}

void GeneralEventController::clickUp(float x, float y) {
	this->mouseControllers.sort(comparar_prioridadClick);
	list<MouseControllerPrioridades*>::iterator it;
	//los de mayor prioridad para el evento podrán cortar el evento a los de menor prioridad
	bool continuarEvento = true;
	for (it=this->mouseControllers.begin(); it!=this->mouseControllers.end() && continuarEvento; ++it){
		continuarEvento = (*it)->getEventController()->clickUp(x,y);
	}
}

void GeneralEventController::clickDown(float x, float y) {
	this->mouseControllers.sort(comparar_prioridadClick);
	list<MouseControllerPrioridades*>::iterator it;
	//los de mayor prioridad para el evento podrán cortar el evento a los de menor prioridad
	bool continuarEvento = true;
	for (it=this->mouseControllers.begin(); it!=this->mouseControllers.end() && continuarEvento; ++it){
		continuarEvento = (*it)->getEventController()->clickDown(x,y);
	}

}

void GeneralEventController::mouseMotion(float x, float y) {
	this->mouseControllers.sort(comparar_prioridadMotion);
	list<MouseControllerPrioridades*>::iterator it;
	//los de mayor prioridad para el evento podrán cortar el evento a los de menor prioridad
	bool continuarEvento = true;
	for (it=this->mouseControllers.begin(); it!=this->mouseControllers.end() && continuarEvento; ++it){
		continuarEvento = (*it)->getEventController()->mouseMotion(x,y);
	}

}
