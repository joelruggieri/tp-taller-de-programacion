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

	void setFin(float x, float y);
	void setFiguraInicio(Figura*);
	void setFiguraFin(Figura*);

	float getXInicial();
	float getYInicial();
	float getXFinal();
	float getYFinal();
	virtual bool setearPuntoInicial(Figura *) = 0;
	virtual bool setearPuntoFinal(Figura *) = 0;

	void setExtremos(Figura*, Figura*);
	void crearFisicaEstaticaTemplate(b2World* w, b2Body* ground);
protected:
	b2Vec2 inicio;
	b2Vec2 fin;
	Figura* figuraInicio;
	Figura* figuraFin;
	float w, h;
	float calcularDistancia(b2Vec2, b2Vec2);
	void calcularCentroCuadrado();
	void calcularAnguloCuadrado();
	void calcularAnchoCuadrado();
};

#endif /* UNION_H_ */
