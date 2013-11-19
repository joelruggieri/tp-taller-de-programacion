/*
 * Aspa.h
 *
 *  Created on: 17/11/2013
 *      Author: joel
 */

#ifndef ASPA_H_
#define ASPA_H_
#include "Objeto.h"
#include "Tijera.h"


class Aspa: public 	Objeto{
private:
	float ancho, alto;
	b2RevoluteJoint * jointCuerpoTierra;
	int numeroAspa;
	Tijera* tijera;
	void crearShapes();
public:
	Aspa();
	Aspa(float,float,float,float,double,int,Tijera*);
	virtual ~Aspa();
	void crearFisica();
	void crearFisicaEstaticaTemplate(b2World * w, b2Body* ground);
	float getAlto() const;
	float getAncho() const;
	void setAlto(float alto);
	void setAncho(float ancho);
	void acept(VisitorFigura*);
	b2RevoluteJoint* getJoint();
};

#endif /* ASPA_H_ */
