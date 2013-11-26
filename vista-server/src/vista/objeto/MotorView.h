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
class SimpleEditorOrientacionCambiable;

class MotorView: public ObjetoView {
private:
	typedef ObjetoView super;
public:
//	MotorView(int x, int y, int w, int h, SDL_Texture * textura, SimpleEditorAnguloFijo * editor);
	MotorView(float x, float y,SimpleEditorOrientacionCambiable * editor);

	virtual ~MotorView();
	void dropTemplate();
	EditorNivel * getEditor();
	int getLayer();
};

#endif /* MOTORVIEW_H_ */
