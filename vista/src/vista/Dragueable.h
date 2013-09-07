/*
 * Dragueable.h
 *
 *  Created on: 06/09/2013
 *      Author: ezequiel
 */

#ifndef DRAGUEABLE_H_
#define DRAGUEABLE_H_
#include "Dibujable.h"
#include "Resizeable.h"
#include "Seleccionable.h"
namespace std {

class Dragueable : public Dibujable, public Seleccionable {
public:
	Dragueable(int x, int y, int h, int w, SDL_Texture* textura, SDL_Renderer* render) : Dibujable(x,y,h,w,textura,render)
	{

	}
	virtual ~Dragueable();
	bool Draguear(int nuevoX, int nuevoY);
//	bool FueSeleccionado(int x, int y);
};

} /* namespace std */
#endif /* DRAGUEABLE_H_ */
