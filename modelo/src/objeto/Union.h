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
	Union(float x, float y, float h);
	Union(const Union & u);
	Union();
	virtual ~Union();
	float getXInicial() const;
	float getYInicial() const;
	float getXFinal() const;
	float getYFinal() const;

	void setXInicial(float);
	void setYInicial(float);
	void setXFinal(float);
	void setYFinal(float);

	virtual bool isInicioValido(Figura * f, float x, float y) = 0;
	virtual bool isFinValido(Figura * f, float x, float y) = 0;
	void setExtremos(Figura*, Figura*);

	virtual void extraerPosInicial(Figura * f, float x, float y) = 0;
	virtual void extraerPosFinal(Figura * f, float x, float y)= 0;


	bool agregar(Mapa *);
	bool remover(Mapa *);
    void makeBackUp();
	void restoreBackUp();

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
	virtual void updatePosicionesFiguras();
	void updateModelo();
	typedef Figura super;
};

#endif /* UNION_H_ */
