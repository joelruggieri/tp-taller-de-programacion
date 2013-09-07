/*
 * Seleccionable.h
 *
 *  Created on: 07/09/2013
 *      Author: ezequiel
 */

#ifndef SELECCIONABLE_H_
#define SELECCIONABLE_H_
#include "Posicionable.h"
namespace std {

class Seleccionable : virtual public Posicionable {
public:
	Seleccionable();
	virtual ~Seleccionable();
	bool FueSeleccionado(int x, int y);
};

} /* namespace std */
#endif /* SELECCIONABLE_H_ */
