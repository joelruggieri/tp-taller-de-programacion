/*
 * Plataforma.h
 *
 *  Created on: 02/10/2013
 *      Author: joel
 */

#ifndef PLATAFORMA_H_
#define PLATAFORMA_H_
#include "Objeto.h"
#include "../figura/Figura.h"


class Plataforma: public Objeto {
private:
	float alto;
	float ancho;
public:
	Plataforma(float x ,float y, Rotador* rotador, float ancho, float alto );
	virtual ~Plataforma();
	float getAlto();
	float getAncho();
	void crearFisica(b2World *);
	void acept(VisitorFigura*);

};

#endif /* PLATAFORMA_H_ */
