#include "MouseControllerPrioridades.h"

bool comparar_prioridadClick(MouseControllerPrioridades * first,
		MouseControllerPrioridades * second) {
	return first->getPrioridadClickUpDown() > second->getPrioridadClickUpDown();
}
bool comparar_prioridadMotion(MouseControllerPrioridades * first,
		MouseControllerPrioridades * second) {
	return first->getPrioridadMotion() > second->getPrioridadMotion();
}
