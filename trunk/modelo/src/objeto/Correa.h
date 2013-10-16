/*
 * Correa.h
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#ifndef CORREA_H_
#define CORREA_H_
#include <cmath>
#include "Objeto.h"
#include "Engranaje.h"
#include "Union.h"
#include "../figura/Figura.h"
class Correa:  public Union {
public:
	Correa(float x, float y);
	Correa(const Correa& correa);
	Correa();
	virtual ~Correa();
	void crearFisica(b2World* w, b2Body* ground);
	void crearLazo(Engranaje * a, Engranaje* b, b2World* w);
	bool crearFisicaEstatica(b2World* w, b2Body* ground);
	void acept(VisitorFigura*);
//	void crearFisicaEstaticaTemplate(b2World* w, b2Body* ground);
	bool setearPuntoInicial(Figura*f);
	bool setearPuntoFinal(Figura *f);
private:
//	Engranaje* engranajeA;
//	Engranaje* engranajeB;
//	Figura* figuraInicio;
//	Figura* figuraFin;

};

#endif /* CORREA_H_ */
