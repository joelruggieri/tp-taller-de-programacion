/*
 * ControlRemoto.h
 *
 *  Created on: 17/11/2013
 *      Author: ezequiel
 */

#ifndef CONTROLREMOTO_H_
#define CONTROLREMOTO_H_
#include "Objeto.h"

class ControlRemoto : public Objeto {
public:
	ControlRemoto(const ControlRemoto&);
	virtual ~ControlRemoto();
	ControlRemoto();
	ControlRemoto(float x, float y, float ancho, float alto);
	void crearFisica();
	void acept(VisitorFigura* visitor);
	float getAlto() const;
	void setAlto(float alto);
	float getAncho() const;
	void setAncho(float ancho);

private:
	float ancho, alto;
	void accionar();
};

#endif /* CONTROLREMOTO_H_ */
