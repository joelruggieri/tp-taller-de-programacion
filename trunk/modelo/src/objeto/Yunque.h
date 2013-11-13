/*
 * Yunque.h
 *
 *  Created on: 13/11/2013
 *      Author: ezequiel
 */

#ifndef YUNQUE_H_
#define YUNQUE_H_
#include "Objeto.h"
#include "Box2D/Box2D.h"
class Yunque : public Objeto{
public:
	Yunque();
	Yunque(float x , float y, float w, float h);
	virtual ~Yunque();
	Yunque(const Yunque& figura);
	void crearFisica();
	void acept(VisitorFigura*);
	float getAlto() const;
	void setAlto(float alto);
	float getAncho() const;
	void setAncho(float ancho);

private:
	float ancho, alto;
};

#endif /* YUNQUE_H_ */
