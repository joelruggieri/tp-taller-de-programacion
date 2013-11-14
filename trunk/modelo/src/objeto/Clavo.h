/*
 * Clavo.h
 *
 *  Created on: 13/11/2013
 *      Author: ezequiel
 */

#ifndef CLAVO_H_
#define CLAVO_H_
#include "Objeto.h"
class Clavo : public Objeto {
public:
	Clavo();
	Clavo(const Clavo&);
	virtual ~Clavo();
	Clavo(float x, float y, float w,float h);
	void acept(VisitorFigura* visitor);
	void crearFisica();

	float getAncho() const {
		return ancho;
	}

	void setAncho(float ancho) {
		this->ancho = ancho;
	}

private:
	float ancho, alto;
};

#endif /* CLAVO_H_ */
