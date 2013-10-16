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
#include <iostream>
using namespace std;
class Union: public Objeto {
public:
	Union(float x, float y);
	Union();
	virtual ~Union();
	void setFin(const b2Vec2& fin);
	void setInicio(const b2Vec2& inicio);


	float getXInicial() const;
	float getYInicial() const;
	float getXFinal() const;
	float getYFinal() const;
	void setXInicial(float);
	void setYInicial(float);
	void setXFinal(float);
	void setYFinal(float);
	void setExtremos(Figura*, Figura*);
	virtual bool isExtremoValido(Figura * f) = 0;
protected:
	void crearFisicaEstaticaTemplate(b2World* w, b2Body* ground);
	b2Vec2 inicio;
	b2Vec2 fin;
	Figura* figuraInicio;
	Figura* figuraFin;
	b2Vec2 inicioB, finB;
	float wB, hB;
	float w, h;
	virtual void setearPuntoInicial(Figura *) = 0;
	virtual void setearPuntoFinal(Figura *) = 0;
	void updateCaracteristicas();
	float calcularDistancia(b2Vec2, b2Vec2);
	void calcularCentroCuadrado();
	void calcularAnguloCuadrado();
	void calcularAnchoCuadrado();
	void updatePosicionesFiguras();
	void updateModelo();
	 void makeBackUp();
	 void restoreBackUp();
	typedef Figura super;
};

#endif /* UNION_H_ */
