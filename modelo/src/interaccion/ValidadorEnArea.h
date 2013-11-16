/*
 * ValidadorEnArea.h
 *
 *  Created on: 15/11/2013
 *      Author: jonathan
 */

#ifndef VALIDADORENAREA_H_
#define VALIDADORENAREA_H_

#include "ValidadorInteraccion.h"
#include "../figura/Figura.h"
class ValidadorEnArea: public ValidadorInteraccion {
public:
	ValidadorEnArea(Figura*f);
	virtual ~ValidadorEnArea();
	ValidadorInteraccion * clone(Figura*f);
	bool validar(Area & a, int jInteraccion);
};

#endif /* VALIDADORENAREA_H_ */
