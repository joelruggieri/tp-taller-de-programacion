/*
 * ObjetivoDesdeHasta.h
 *
 *  Created on: 23/11/2013
 *      Author: ezequiel
 */

#ifndef OBJETIVODESDEHASTA_H_
#define OBJETIVODESDEHASTA_H_
#include "Objetivo.h"
class ObjetivoDesdeHasta : public Objetivo  {
public:
	ObjetivoDesdeHasta(float xD, float yD, float xH, float yH, int numObj);
	virtual ~ObjetivoDesdeHasta();

	float getXH() const {
		return xH;
	}

	void setXH(float h) {
		xH = h;
	}

	float getYH() const {
		return yH;
	}

	void setYH(float h) {
		yH = h;
	}

private:
	float xH, yH;
};

#endif /* OBJETIVODESDEHASTA_H_ */
