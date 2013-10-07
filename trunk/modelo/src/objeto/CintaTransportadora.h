/*
 * CintaTransportadora.h
 *
 *  Created on: 05/10/2013
 *      Author: javier
 */

#ifndef CINTATRANSPORTADORA_H_
#define CINTATRANSPORTADORA_H_

#include "Objeto.h"

#define PIEZAS 43

class CintaTransportadora: public Objeto {
public:
	CintaTransportadora();
	CintaTransportadora(int x, int y, int longitud);
	virtual ~CintaTransportadora();
	void crearFisica(b2World *);
	void acept(VisitorFigura*);
	int getLongitud() const;
	void setLongitud(int longitud);
private:
	float longitud;
	b2Body* piezas[PIEZAS];
	b2Body* ruedas[2];
	b2Body* cuerpo;
	b2Body* base;

	float alto;
	float ancho;
};

#endif /* CINTATRANSPORTADORA_H_ */
