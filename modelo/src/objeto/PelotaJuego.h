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
	PelotaJuego(float x, float y,Rotador * rot);;
	virtual ~PelotaJuego();
};

#endif /* PELOTAJUEGO_H_ */
