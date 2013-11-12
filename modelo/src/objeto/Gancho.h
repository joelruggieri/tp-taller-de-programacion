/*
 * Gancho.h
 *
 *  Created on: 12/11/2013
 *      Author: joel
 */

#ifndef GANCHO_H_
#define GANCHO_H_
#include "Objeto.h"

class Gancho: public Objeto {
private:
	float radio;
public:
	Gancho();
	Gancho(float,float,float);
	Gancho(const Gancho&);
	void crearFisica();
	void acept(VisitorFigura*);
	float getRadio() const;
	void setRadio(float radio);
	//void updateModelo();

	virtual ~Gancho();
};

#endif /* GANCHO_H_ */
