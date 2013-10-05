/*
 * Balancin.h
 *
 *  Created on: 05/10/2013
 *      Author: joel
 */

#ifndef BALANCIN_H_
#define BALANCIN_H_
#include "Objeto.h"
#include "../figura/Figura.h"

class Balancin: public Objeto {
private:
	float ancho;
	float alto;
public:
	Balancin();
	Balancin(const Balancin& balancin);
	Balancin(float x ,float y, float ancho, float alto );
	virtual ~Balancin();
	float getAlto() const;
	float getAncho() const;
	void setAlto(float alto);
	void setAncho(float ancho);
	void crearFisica(b2World *);
	void acept(VisitorFigura*);
};

#endif /* BALANCIN_H_ */
