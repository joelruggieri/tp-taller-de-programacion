/*
 * CintaTransportadora.h
 *
 *  Created on: 05/10/2013
 *      Author: javier
 */

#ifndef CINTATRANSPORTADORA_H_
#define CINTATRANSPORTADORA_H_

#include "Engranaje.h"
#include <vector>
#include <SDL2/SDL.h>
class CintaTransportadora: public Engranaje {
public:
	CintaTransportadora();
	CintaTransportadora(float x, float y, float ancho, float alto);
	CintaTransportadora(const CintaTransportadora& figura);
	virtual ~CintaTransportadora();
	void crearFisica();
	void acept(VisitorFigura*);
	float getAncho() const;
	void setAncho(float ancho);
	void updateModelo();
	void removerFisica();
private:
	typedef Engranaje super;
	float alto;
	float ancho;
	float anchoBack;
	b2Body * bodyEngranaje;
};

#endif /* CINTATRANSPORTADORA_H_ */
