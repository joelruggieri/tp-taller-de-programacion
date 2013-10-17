/*
 * Estirable.h
 *
 *  Created on: 17/10/2013
 *      Author: jonathan
 */

#ifndef ESTIRABLE_H_
#define ESTIRABLE_H_

class Estirable {
public:
	virtual ~Estirable(){

	};
	virtual void estirar (float delta) = 0;
};

#endif /* ESTIRABLE_H_ */
