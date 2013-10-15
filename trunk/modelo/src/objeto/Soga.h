/*
 * Soga.h
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#ifndef SOGA_H_
#define SOGA_H_

#include "Objeto.h"
#include <vector>
#include <SDL2/SDL_rect.h>

class Soga: public Objeto {
public:
	Soga(float x, float y);
	Soga(const Soga& figura);
	virtual ~Soga();
	bool crearFisicaEstatica(b2World *);
	void cargar(b2Body* origen, b2Body* destino,  b2World *m_world);
	void updateModelo();
	std::vector<float>& getAngulosTramos();
	std::vector<SDL_Rect>& getMarcosTramos();

private:
	void actualizarMarcos();
	void actualizarAngulos();
	b2Body *crear(b2World *m_world, int x, int y);
	std::vector<b2Body*> tramos;
	std::vector<SDL_Rect> marcosTramos;
	std::vector<float> angulosTramos;
	bool modificado;
//	b2Body *origen, *destino;
};

#endif /* SOGA_H_ */
