/*
 * Union.h
 *
 *  Created on: 14/10/2013
 *      Author: jonathan
 */

#ifndef UNION_H_
#define UNION_H_

#include "Objeto.h"
#include "../Constantes.h"

class Union: public Objeto {
public:
	Union(float x, float y);
	virtual ~Union();
	void setFin(const b2Vec2& fin);
	void setInicio(const b2Vec2& inicio);
	void setFiguraInicio(Figura*);
	void setFiguraFin(Figura*);
	float getXInicial();
	float getYInicial();
	float getXFinal();
	float getYFinal();
	void setCorrea(Figura*, Figura*);
	void crearFisicaEstaticaTemplate(b2World* w, b2Body* ground);
//	void crearFisicaTemplate
protected:
	b2Vec2 inicio;
	b2Vec2 fin;
	Figura* figuraInicio;
	Figura* figuraFin;
	float w,h;
	float calcularDistancia(b2Vec2, b2Vec2);
	void calcularCentroCuadrado();
	void calcularAnguloCuadrado();
	void calcularAnchoCuadrado();
};

#endif /* UNION_H_ */
