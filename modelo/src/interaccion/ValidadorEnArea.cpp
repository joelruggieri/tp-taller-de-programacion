/*
 * ValidadorEnArea.cpp
 *
 *  Created on: 15/11/2013
 *      Author: jonathan
 */

#include "ValidadorEnArea.h"

ValidadorEnArea::ValidadorEnArea(Figura*f):ValidadorInteraccion(f) {
	// TODO Auto-generated constructor stub

}

ValidadorEnArea::~ValidadorEnArea() {
	// TODO Auto-generated destructor stub
}

ValidadorInteraccion* ValidadorEnArea::clone(Figura*f) {
	return new ValidadorEnArea(f);
}

bool ValidadorEnArea::validar(Area & a, int jInteraccion) {
	return a.contacto(actuador->getX(),actuador->getY());
}
