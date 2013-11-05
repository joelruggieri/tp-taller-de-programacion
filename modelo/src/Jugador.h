/*
 * Jugador.h
 *
 *  Created on: 27/10/2013
 *      Author: jonathan
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_
#include "Area.h"
#include "FactoryParam.h"
#include <list>
class Jugador {
private:
	Area * area;
	int numero;
	std::list<FactoryParam*> parametrosFactories;
public:
	Jugador();
	Jugador(const Jugador& jugador);
	virtual ~Jugador();
	Area* getArea();
	void setArea(Area* unArea);
	int getNumero() const;
	void setNumero(int numero);
	void setParametrosFactories(std::list<FactoryParam*>&);
	void agregarParametroFactory(FactoryParam*);
	std::list<FactoryParam*>& getParametrosFactories();
};

#endif /* JUGADOR_H_ */
