/*
 * Bomba.h
 *
 *  Created on: 17/11/2013
 *      Author: ezequiel
 */

#ifndef BOMBA_H_
#define BOMBA_H_
#include "Objeto.h"
class Bomba : public Objeto {
public:
	Bomba(const Bomba&);
	Bomba();
	Bomba(float x, float y, float radio);
	void crearFisica();
	void acept(VisitorFigura*);
	virtual ~Bomba();
	float getRadio() const;
	void setRadio(float radio);
	void accionar();
	void crearFisicaRadio(b2Vec2 centro);
	bool validarContactoBomba(b2Body * verf, b2Body * b);
	void  interactuar(Area & area, int jugador);
private:
	float radio;
	b2Body* radioAccion;
	typedef Objeto super;
};

#endif /* BOMBA_H_ */
