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
#include "Estirable.h"
class CintaTransportadora: public Engranaje, public Estirable {
public:
	CintaTransportadora();
	CintaTransportadora(const CintaTransportadora& figura);
	CintaTransportadora(float x, float y, float ancho, float alto);
	virtual ~CintaTransportadora();
	void crearFisica();
	void acept(VisitorFigura*);
	float getAncho() const;
	void setAncho(float ancho);
	void updateModelo();
	void removerFisica();
	float getAlto() const;
	double getRotacionEje() const;
	void estirar(float delta);
private:
	typedef Engranaje super;
	float alto;
	float ancho;
	float anchoBack;
	float rotacionEje;
	b2Body * bodyEngranaje;
};

#endif /* CINTATRANSPORTADORA_H_ */
