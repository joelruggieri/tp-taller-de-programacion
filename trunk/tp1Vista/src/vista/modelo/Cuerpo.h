/*
 * Cuerpo.h
 *
 *  Created on: 29/08/2013
 *      Author: jonathan
 */

#ifndef CUERPO_H_
#define CUERPO_H_

class Cuerpo {
private:
	float posX, posY, alto, ancho;
	bool isAdentro1D(float pos, float posCentro, float ancho);
public:
	bool isAdentro(float posX,float posY );
	Cuerpo(float posX,float posY,float alto,float ancho);
	Cuerpo(Cuerpo& other);
	Cuerpo();
	virtual ~Cuerpo();
};

#endif /* CUERPO_H_ */
