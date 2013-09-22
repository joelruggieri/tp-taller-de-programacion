/*
 * RotationView.h
 *
 *  Created on: 11/09/2013
 *      Author: jonathan
 */

#ifndef ROTATIONVIEW_H_
#define ROTATIONVIEW_H_
#include "Rotable.h"
#include "Dibujable.h"
#include "SDL2/SDL.h"
class RotationView : public Dibujable{
	Rotable * rotado;
	SDL_Texture * textura;
public:

	RotationView(Rotable *, SDL_Texture * textura);
	virtual ~RotationView();
	void dibujarse(SDL_Renderer *);
	void dibujarse(SDL_Renderer*, SDL_Rect &);
};

#endif /* ROTATIONVIEW_H_ */
