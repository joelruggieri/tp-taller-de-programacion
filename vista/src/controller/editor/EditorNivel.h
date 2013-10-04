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
	virtual void clickDown(int x, int y) = 0;
	virtual void clickUp(int x, int y) = 0;
	virtual void rightClickUp(int x, int y) = 0;
	virtual void rightClickDown(int x, int y) = 0;
	virtual bool isEnd() = 0;
	virtual void dibujarEdicion(SDL_Renderer *) = 0;
	virtual void mouseMotion(int x, int y) = 0;

};

#endif /* EDITORNIVEL_H_ */
