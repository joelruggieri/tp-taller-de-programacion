/*
 * Monitor.h
 *
 *  Created on: 21/11/2013
 *      Author: ezequiel
 */

#ifndef MONITOR_H_
#define MONITOR_H_
#include "Objeto.h"
class Monitor : public Objeto{
private:
	float ancho, alto;
	Figura* figuraEsperada;

public:
	Monitor(float x , float y, float w, float h);
	virtual ~Monitor();
	bool crearFisicaEstatica();
	void crearFisica();
	void acept(VisitorFigura*);
	void setFiguraEsperada(Figura*);
	void contactar(Figura*);
	float getAncho();
	float getAlto();
};

#endif /* MONITOR_H_ */
