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
	Plataforma(const Plataforma& plataforma);
	Plataforma();
	Plataforma(float x ,float y, Rotador* rotador, float ancho, float alto );
	virtual ~Plataforma();
	float getAlto() const;
	float getAncho() const;
	void setAlto(float alto);
	void setAncho(float ancho);
	void crearFisica(b2World *);
	void acept(VisitorFigura*);

};

#endif /* PLATAFORMA_H_ */