/*
 * MotorView.h
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#ifndef MOTORVIEW_H_
#define MOTORVIEW_H_

#include "ObjetoView.h"

class SimpleEditorAnguloFijo;
struct SDL_Texture;

class MotorView: public ObjetoView {
public:
	MotorView(int x, int y, int w, int h, SDL_Texture * textura, SimpleEditorAnguloFijo * editor);
	virtual ~MotorView();
	void dropTemplate();
	EditorNivel * getEditor();

};

#endif /* MOTORVIEW_H_ */
