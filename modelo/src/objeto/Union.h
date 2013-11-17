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
#include "../observer/FiguraObserver.h"
#include "../observer/ObserverFiguraHelper.h"
class Mapa;
class Union: public Objeto, public FiguraObserver{
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

	virtual uint16 getMascaraExtremos();
	bool agregar(Mapa *);
	bool remover(Mapa *);
    void makeBackUp();
	void restoreBackUp();
	void notifyEvent(Evento_type);


	//estos son para poder indicar donde esta el cuerpo.
	bool estaEstatica();
	float getRadio();
	virtual void calcularCentroCuadrado();

protected:
	void crearFisicaEstaticaTemplate();
	b2Vec2 inicio;
	b2Vec2 fin;
	Figura* figuraInicio;
	Figura* figuraFin;
	b2Vec2 inicioB, finB;
	ObserverFiguraHelper * eventHelper;
	float wB, hB;
	float w, h;
	virtual void setearPuntoInicial(Figura *) = 0;
	virtual void setearPuntoFinal(Figura *) = 0;
	void updateCaracteristicas();
	float calcularDistancia(b2Vec2, b2Vec2);
	void calcularAnguloCuadrado();
	void calcularAnchoCuadrado();
	virtual void updatePosicionesFiguras();
	virtual void updatePosicionesFigurasSinFisica();
	void updateModelo();
	typedef Figura super;
	b2Joint * joint;
};

#endif /* UNION_H_ */
