/*
 * ValidadorInteraccion.h
 *
 *  Created on: 15/11/2013
 *      Author: jonathan
 */

#ifndef VALIDADORINTERACCION_H_
#define VALIDADORINTERACCION_H_
#include "../Area.h"
class Figura;
class ValidadorInteraccion {
protected:
	Figura * actuador;
public:
	ValidadorInteraccion(Figura *);
	virtual bool validar(Area & a, int jInteraccion) = 0;
	void setActuador(Figura *);
	virtual ValidadorInteraccion * clone(Figura *) = 0;
	void setJugador(int j);
	virtual ~ValidadorInteraccion();

};

#endif /* VALIDADORINTERACCION_H_ */
