/*
 * PelotaJuego.h
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#ifndef PELOTAJUEGO_H_
#define PELOTAJUEGO_H_

#include "Objeto.h"

class PelotaJuego: public Objeto {
public:
	PelotaJuego(float x, float y, float radio);
	virtual ~PelotaJuego();
	void crearFisica(b2World *world);
private:
	float radio;
};

#endif /* PELOTAJUEGO_H_ */
