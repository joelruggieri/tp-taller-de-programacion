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
	virtual ~Correa();
	void crearFisica(b2World* w, b2Body* ground);
	void crearLazo(Engranaje * a, Engranaje* b, b2World* w);
	void setFiguraInicio(Figura*);
	void setFiguraFin(Figura*);
	bool crearFisicaEstatica(b2World* w, b2Body* ground);
	void crearFisicaEstaticaTemplate(b2World* w, b2Body* ground);
private:
	Engranaje* engranajeA;
	Engranaje* engranajeB;
	Figura* figuraInicio;
	Figura* figuraFin;
	float calcularDistancia(b2Vec2, b2Vec2);
	b2Vec2 calcularCentroCuadrado();
	float calcularAnguloCuadrado();
	float calcularAnchoCuadrado();
};

#endif /* CORREA_H_ */
