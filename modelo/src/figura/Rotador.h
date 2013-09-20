/*
 * Rotador.h
 *
 *  Created on: 19/09/2013
 *      Author: jonathan
 */

#ifndef ROTADOR_H_
#define ROTADOR_H_


class Figura;

class Rotador {
public:
	virtual ~Rotador(){

	};
	virtual void rotar(Figura*, double & x, double & y)=0;
};

#endif /* ROTADOR_H_ */
