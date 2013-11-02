/*
 * EditorNivel.h
 *
 *  Created on: 03/10/2013
 *      Author: jonathan
 */

#ifndef EDITORNIVEL_H_
#define EDITORNIVEL_H_
#include "SDL2/SDL.h"
#include "src/mensajes/ViewMsj.h"
#include <list>
using namespace std;
class EditorNivel {
public:
	virtual ~EditorNivel(){};
	virtual void clickDown(float x, float y) = 0;
	virtual void clickUp(float x, float y) = 0;
	virtual void rightClickUp(float x, float y) = 0;
	virtual void rightClickDown(float x, float y) = 0;
	virtual bool isEnd() = 0;
	virtual void dibujarEdicion(list<ViewMsj* > &) = 0;
	virtual void mouseMotion(float x, float y) = 0;

};

#endif /* EDITORNIVEL_H_ */
