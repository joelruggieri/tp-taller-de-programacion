/*
 * EditorNivel.h
 *
 *  Created on: 03/10/2013
 *      Author: jonathan
 */

#ifndef EDITORNIVEL_H_
#define EDITORNIVEL_H_
#include "SDL2/SDL.h"
class EditorNivel {
public:
	virtual ~EditorNivel(){};
	virtual void clickDown(float x, float y) = 0;
	virtual void clickUp(float x, float y) = 0;
	virtual void rightClickUp(float x, float y) = 0;
	virtual void rightClickDown(float x, float y) = 0;
	virtual bool isEnd() = 0;
	virtual void dibujarEdicion(SDL_Renderer *) = 0;
	virtual void mouseMotion(float x, float y) = 0;

};

#endif /* EDITORNIVEL_H_ */
