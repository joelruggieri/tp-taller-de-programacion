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
	PelotaJuego(const PelotaJuego&);
	PelotaJuego();
	PelotaJuego(float x, float y, float radio);
	virtual ~PelotaJuego();
	void crearFisica();
	void acept(VisitorFigura* visitor);
	float getRadio() const;
	void setRadio(float radio);
    void recibirImpacto(b2Vec2 direccion);
private:
	float radio;
};

#endif /* PELOTAJUEGO_H_ */
