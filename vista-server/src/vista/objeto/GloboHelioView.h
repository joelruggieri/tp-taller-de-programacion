/*
 * GloboHelioView.h
 *
 *  Created on: 05/10/2013
 *      Author: ezequiel
 */

#ifndef GLOBOHELIOVIEW_H_
#define GLOBOHELIOVIEW_H_
#include "ObjetoView.h"

class SimpleEditorAnguloFijo;

class GloboHelioView : public ObjetoView {
public:
	GloboHelioView(float x, float y,SimpleEditorAnguloFijo * editor);
	virtual ~GloboHelioView();
	void dropTemplate();
	EditorNivel * getEditor();
};

#endif /* GLOBOHELIOVIEW_H_ */
