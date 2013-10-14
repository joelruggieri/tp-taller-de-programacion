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
#include <SDL2/SDL.h>

class CintaTransportadora: public Objeto {
public:
	CintaTransportadora();
	CintaTransportadora(float x, float y, float longitud);
	CintaTransportadora(const CintaTransportadora& figura);
	virtual ~CintaTransportadora();
	void crearFisica(b2World * w, b2Body* ground);
	void crearFisicaEstaticaTemplate(b2World* m_world, b2Body* ground);
	void acept(VisitorFigura*);
	int getLongitud() const;
	void setLongitud(float longitud);
	float *getAngulosRuedas();
	SDL_Rect* getMarcosRuedas();
	void updateModelo();
private:
	void actualizarAngulos();
	void actualizarMarcos();
	float longitud;
	std::vector<b2Body*> piezas;
	int cantPiezas;
	b2Body* ruedas[2];
	b2Body* cuerpo;
	b2Body* base;
	b2World *mundo;
	float angulosRuedas[2];
	SDL_Rect marcosRuedas[2];
};

#endif /* CINTATRANSPORTADORA_H_ */
