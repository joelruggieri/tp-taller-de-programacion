/*
 * Soga.h
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#ifndef SOGA_H_
#define SOGA_H_

#include "Objeto.h"
#include <vector>

class Soga: public Objeto {
public:
	Soga(float x, float y);
	Soga(const Soga& figura);
	virtual ~Soga();
	bool crearFisicaEstatica(b2World *);
	void cargar(b2Body* origen, b2Body* destino,  b2World *m_world);
private:
	b2Body *crear(b2World *m_world, int x, int y);
	std::vector<b2Body*> tramos;
//	b2Body *origen, *destino;
};

#endif /* SOGA_H_ */
