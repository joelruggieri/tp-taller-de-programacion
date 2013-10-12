/*
 * CintaTransportadora.h
 *
 *  Created on: 05/10/2013
 *      Author: javier
 */

#ifndef CINTATRANSPORTADORA_H_
#define CINTATRANSPORTADORA_H_

#include "Objeto.h"
#include <vector>

class CintaTransportadora: public Objeto {
public:
	CintaTransportadora();
	CintaTransportadora(int x, int y, int longitud);
	CintaTransportadora(const CintaTransportadora& figura);
	virtual ~CintaTransportadora();
	void crearFisica(b2World * w, b2Body* ground);
	bool crearFisicaEstatica1(b2World*w, b2Body* ground);
	void crearFisicaEstaticaTemplate(b2World* m_world, b2Body* ground);
	void acept(VisitorFigura*);
	int getLongitud() const;
	void setLongitud(int longitud);
private:
	float longitud;
	std::vector<b2Body*> piezas;
	int cantPiezas;
	b2Body* ruedas[2];
	b2Body* cuerpo;
	b2Body* base;
	b2World *mundo;
};

#endif /* CINTATRANSPORTADORA_H_ */
