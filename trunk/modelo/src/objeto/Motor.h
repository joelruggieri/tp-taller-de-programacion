/*
 * Motor.h
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include "Objeto.h"

class Motor: public Objeto {
private:
	float32 w,h;
	int direccion;
public:
	Motor(float x, float y, float w, float h);
	virtual ~Motor();
	void crearFisica(b2World * w, b2Body* ground);
	void acept(VisitorFigura*);
	void modificarSentido();

};

#endif /* MOTOR_H_ */
