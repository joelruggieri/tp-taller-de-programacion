/*
 * Seleccionable.cpp
 *
 *  Created on: 07/09/2013
 *      Author: ezequiel
 */

#include "Seleccionable.h"

namespace std {

Seleccionable::Seleccionable() {
	// TODO Auto-generated constructor stub

}

Seleccionable::~Seleccionable() {
	// TODO Auto-generated destructor stub
}

bool Seleccionable::FueSeleccionado(int x, int y)
{
	if ((x <= this->x + this->w) and ( x >= this->x ) and (y <= this->y + this->h) and ( y>= this->y))
			return true;
	else
		return false;
}

} /* namespace std */
