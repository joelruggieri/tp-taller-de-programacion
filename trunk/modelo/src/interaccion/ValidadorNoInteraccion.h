/*
 * ValidadorNoInteraccion.h
 *
 *  Created on: 15/11/2013
 *      Author: jonathan
 */

#ifndef VALIDADORNOINTERACCION_H_
#define VALIDADORNOINTERACCION_H_

#include "ValidadorInteraccion.h"

class ValidadorNoInteraccion: public ValidadorInteraccion {
public:
	ValidadorNoInteraccion(Figura * f);
	virtual ~ValidadorNoInteraccion();
	ValidadorInteraccion * clone(Figura *);
	bool validar(Area & a, int jInteraccion);
};

#endif /* VALIDADORNOINTERACCION_H_ */
