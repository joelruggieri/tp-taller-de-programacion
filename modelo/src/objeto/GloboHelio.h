/*
 * GloboHelio.h
 *
 *  Created on: 02/10/2013
 *      Author: ezequiel
 */

#ifndef GLOBOHELIO_H_
#define GLOBOHELIO_H_
#include "Box2D/Box2D.h"
#include "Objeto.h"

class GloboHelio : public Objeto {
public:
	typedef Objeto super;
	GloboHelio(const GloboHelio&);
	GloboHelio();
	GloboHelio(float x, float y, float radio) ;
	virtual ~GloboHelio();
	void crearFisica(b2World * w, b2Body* ground);
	void acept(VisitorFigura*);
	float getRadio() const;
	void setRadio(float radio);
	void updateModelo();
private:
	float radio;
};

#endif /* GLOBOHELIO_H_ */
