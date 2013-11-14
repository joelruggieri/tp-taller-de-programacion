/*
 * FiguraFactory.h
 *
 *  Created on: 04/09/2013
 *      Author: jonathan
 */

#ifndef FIGURAFACTORY_H_
#define FIGURAFACTORY_H_
#include "../figura/Figura.h"
class FiguraFactory {
public:
	FiguraFactory();
	virtual ~FiguraFactory();
	Figura * crearGancho(float x,float y,int numeroJugador);
	Figura * crearMotor(float x,float y,int numeroJugador);
	Figura * crearPlataforma(float x, float y,int numeroJugador);
	Figura*  crearGloboHelio(float x, float y, int numeroJugador);
	Figura * crearBalancin(float x, float y, int numeroJugador);
	Figura * crearCintaTransportadora(float x, float y, int numeroJugador);
	Figura* crearBolaBoliche(float x, float y, int numeroJugador);
	Figura* crearPelotaJuego(float x, float y, int numeroJugador);
	Figura* crearEngranaje(float x, float y, int numeroJugador);
	Figura* crearSoga(float x, float y, int numeroJugador);
	Figura* crearCorrea(float x, float y, int numeroJugador);
	Figura* crearYunque(float x, float y, int numeroJugador);
	Figura* crearClavo(float x, float y, int numeroJugador);
	Figura * crear(Gancho*);
	Figura * crear(Plataforma*);
	Figura * crear(Engranaje*);
	Figura * crear(Balancin*);
	Figura * crear(CintaTransportadora* cinta);
	Figura* crear(BolaBoliche*);
	Figura* crear(PelotaJuego*);
	Figura* crear(GloboHelio*);
	Figura* crear(Motor*);
	Figura* crear(Correa*);
	Figura* crear(Soga*);
	Figura* crear(Yunque*);
	Figura* crear(Clavo*);
};

#endif /* FIGURAFACTORY_H_ */
