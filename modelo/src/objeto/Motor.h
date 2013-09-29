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
public:
	Motor(float x, float y,Rotador * rot, float w, float h);
	virtual ~Motor();
	void crearsFisica(b2World *);
};

#endif /* MOTOR_H_ */