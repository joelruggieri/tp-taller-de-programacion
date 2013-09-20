/*
 * Pelota.h
 *
 *  Created on: 20/09/2013
 *      Author: joel
 */

#ifndef PELOTA_H_
#define PELOTA_H_
#include "Circulo.h"
#include "Figura.h"
#include "Rotador.h"

class Pelota: public Circulo{
public:
	Pelota();
	Pelota(float x, float y, Rotador* rotador,float radio);
	virtual ~Pelota();
};

#endif /* PELOTA_H_ */
