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
	Figura * crearCirculo(float x,float y);
	Figura * crearRueda(float x,float y);
	Figura * crearGlobo(float x,float y);
	Figura * crearPelota(float x,float y);
	Figura * crearResorte(float x,float y);
	Figura * crearMartillo(float x,float y);
	Figura * crearBloque(float x,float y);
	Figura * crearCohete(float x,float y);
	Figura * crearCarrito(float x,float y);
	Figura * crearMotor(float x,float y);
	Figura * crearPlataforma(float x, float y);
	Figura * crearBalancin(float x, float y);
	Figura * crear(Plataforma*);
	Figura * crear(Balancin*);
	Figura * crear(Rueda*);
	Figura * crear(Circulo*);
	Figura * crear(Globo*);
	Figura * crear(Pelota*);
};

#endif /* FIGURAFACTORY_H_ */
