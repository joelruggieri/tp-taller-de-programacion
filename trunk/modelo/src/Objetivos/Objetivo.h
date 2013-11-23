/*
 * Objetivo.h
 *
 *  Created on: 21/11/2013
 *      Author: ezequiel
 */

#ifndef OBJETIVO_H_
#define OBJETIVO_H_
class Objetivo  {
public:
	Objetivo(float x, float y, int numero);
	virtual ~Objetivo();
	int getNumeroObjetivo() const;
	void setNumeroObjetivo(int numeroObjetivo);
	float getXD() const;
	void setXD(float d);
	float getYD() const;
	void setYD(float d);

protected:
	int numeroObjetivo;
	float xD,yD;
};

#endif /* OBJETIVO_H_ */
