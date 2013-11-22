/*
 * ObjetivoAccionar.h
 *
 *  Created on: 21/11/2013
 *      Author: ezequiel
 */

#ifndef OBJETIVOACCIONAR_H_
#define OBJETIVOACCIONAR_H_
#include "Objetivo.h"
class ObjetivoAccionar : public Objetivo{
public:
	ObjetivoAccionar(float x, float y, float numObj);
	virtual ~ObjetivoAccionar();
};

#endif /* OBJETIVOACCIONAR_H_ */
