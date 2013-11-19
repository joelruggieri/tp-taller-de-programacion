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
	bool crearFisicaEstatica();
	void crearFisica();
	void acept(VisitorFigura*);
	float getXEslabon();
	float getYEslabon();
	bool isInicioValido(Figura * f, float x, float y);
	bool isFinValido(Figura * f, float x, float y);
	void extraerPosInicial(Figura * f, float x, float y);
	void extraerPosFinal(Figura * f, float x, float y);
	void updatePosicionesFigurasSinFisica();
	void removerFisica();
	bool conEslabon();
	void calcularCentroCuadrado();
	void limpiarReferenciasB2D();

	// SOLO DESACTIVA EL JOINT UNIDO AL ENGANCHE PERO NO ELIMINA LA SOGA EN NINGUN CASO.
	void desactivarJoint(Enganche *);
	void notifyEvent(Evento_type);
	//INDICA SI EL PRIMER TRAMO ESTA ACTIVO, PUEDE NO EXISTIR EL JOINT Y ESTAR ACTIVO TBN
	bool activoPrimerTramo();
	//INDICA SI EL PRIMER TRAMO ESTA ACTIVO, PUEDE NO EXISTIR EL JOINT Y ESTAR ACTIVO TBN
	bool activoSegundoTramo();
	//Corta la soga directamente.
	void cortar(b2Body *);
	void cortar(Enganche *);
protected:
	void crearLazo(b2World*);
	void updatePosicionesFiguras();
	void setearPuntoInicial(Figura*f);
	void setearPuntoFinal(Figura *f);
	void updatePosicionesSinFisica();
private:
	//ROMPE LA SOGA Y PROPAGA EL EVENTO HACIA EL OTRO ESTREMO
	Enganche * getEngancheMasCercano(Figura* figura, float x, float y, bool desocupado);
	Enganche *origen, *destino;
	b2Body * eslabon;
	b2Vec2 posEslabon;
	b2Joint * joint2;
	bool primerTramoOn, segundoTramoOn;
	typedef Union super;
	b2Vec2 determinarPosEslabon();
};

#endif /* SOGA_H_ */
