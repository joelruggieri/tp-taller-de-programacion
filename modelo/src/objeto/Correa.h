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
	void crearFisica();
	void crearLazo(Engranaje * a, Engranaje* b, b2World* w);
	bool crearFisicaEstatica();
	void acept(VisitorFigura*);

	bool isInicioValido(Figura * f, float x, float y);
	bool isFinValido(Figura * f, float x, float y);

	void extraerPosInicial(Figura * f, float x, float y);
	void extraerPosFinal(Figura * f, float x, float y);
	void removerFisica();
protected:
	void setearPuntoInicial(Figura*f);
	void setearPuntoFinal(Figura *f);
	bool isExtremoValido(Figura * f);
//	Engranaje* engranajeA;
//	Engranaje* engranajeB;
//	Figura* figuraInicio;
//	Figura* figuraFin;

};

#endif /* CORREA_H_ */

