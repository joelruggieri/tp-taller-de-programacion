/*
 * Motor.h
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include "Engranaje.h"

class Motor: public Engranaje {
private:
	int direccion;
public:
	Motor(float x, float y, float radio);
	virtual ~Motor();
	Motor(const Motor& figura);
	Motor();
	void crearFisica(b2World *, b2Body*);
	void acept(VisitorFigura*);
private:
	void setRadio(float radio);

};

#endif /* MOTOR_H_ */
