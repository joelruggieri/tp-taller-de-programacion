/*
 * ValidadorNoInteraccion.cpp
 *
 *  Created on: 15/11/2013
 *      Author: jonathan
 */

#include "ValidadorNoInteraccion.h"

ValidadorNoInteraccion::ValidadorNoInteraccion(Figura * f):ValidadorInteraccion(f) {
	// TODO Auto-generated constructor stub

}

ValidadorNoInteraccion::~ValidadorNoInteraccion() {
	// TODO Auto-generated destructor stub
}

bool ValidadorNoInteraccion::validar(Area & a, int jInteraccion) {
	return false;
}

ValidadorInteraccion* ValidadorNoInteraccion::clone(Figura*f) {
	return new ValidadorNoInteraccion(f);
}
