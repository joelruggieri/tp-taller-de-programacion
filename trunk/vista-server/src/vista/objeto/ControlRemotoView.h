/*
 * ControlRemotoView.h
 *
 *  Created on: 17/11/2013
 *      Author: ezequiel
 */

#ifndef CONTROLREMOTOVIEW_H_
#define CONTROLREMOTOVIEW_H_
#include "ObjetoView.h"
class SimpleEditorAnguloFijo;
class ControlRemotoView : public ObjetoView {
public:
	ControlRemotoView(float x, float y, SimpleEditorAnguloFijo* editor);
	virtual ~ControlRemotoView();
	void dropTemplate();
		EditorNivel * getEditor();
		int getLayer();
};

#endif /* CONTROLREMOTOVIEW_H_ */
