/*
 * Soga.h
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#ifndef SOGA_H_
#define SOGA_H_

#include "Union.h"
#include <vector>
#include <SDL2/SDL_rect.h>

class Soga: public Union {
public:
	Soga(float x, float y);
	Soga(const Soga& figura);
	Soga();
	virtual ~Soga();
	bool crearFisicaEstatica(b2World *);
	void crearFisica(b2World * w, b2Body* g);
	void acept(VisitorFigura*);

	bool isInicioValido(Figura * f, float x, float y);
	bool isFinValido(Figura * f, float x, float y);
	void extraerPosInicial(Figura * f, float x, float y);
	void extraerPosFinal(Figura * f, float x, float y);

	bool crearFisicaEstatica(b2World*, b2Body* ground);
	void removerFisica(b2World * w);
protected:
	void crearLazo(b2World*);
	void updatePosicionesFiguras();
	void setearPuntoInicial(Figura*f);
	void setearPuntoFinal(Figura *f);
private:
	Enganche * getEngancheMasCercano(Figura* figura, float x, float y, bool desocupado);
	Enganche *origen, *destino;
};

#endif /* SOGA_H_ */
