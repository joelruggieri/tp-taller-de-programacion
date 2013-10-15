/*
 * FiguraFactory.h
 *
 *  Created on: 04/09/2013
 *      Author: jonathan
 */

#ifndef FIGURAFACTORY_H_
#define FIGURAFACTORY_H_
#include "../figura/Figura.h"
#include "../figura/Rotador.h"
class FiguraFactory {
private:
	Rotador * rotador;
public:
	FiguraFactory(Rotador * rotador);
	virtual ~FiguraFactory();
	Figura * crearMotor(float x,float y);
	Figura * crearPlataforma(float x, float y);
	Figura*  crearGloboHelio(float x, float y);
	Figura * crearBalancin(float x, float y);
	Figura * crearCintaTransportadora(float x, float y, int longitud);
	Figura* crearBolaBoliche(float x, float y);
	Figura* crearPelotaJuego(float x, float y);
	Figura* crearEngranaje(float x, float y);
	Figura * crear(Plataforma*);
	Figura * crear(Engranaje*);
	Figura * crear(Balancin*);
	Figura * crear(CintaTransportadora* cinta);
	Figura* crear(BolaBoliche*);
	Figura* crear(PelotaJuego*);
	Figura* crear(GloboHelio*);
	Figura* crear(Motor*);
};

#endif /* FIGURAFACTORY_H_ */
