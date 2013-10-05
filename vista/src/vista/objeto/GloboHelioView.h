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
struct SDL_Texture;

class GloboHelioView : public ObjetoView {
public:
	GloboHelioView(int x, int y, int w, int h, SDL_Texture * textura, SimpleEditorAnguloFijo * editor);
	virtual ~GloboHelioView();
	void dropTemplate();
	EditorNivel * getEditor();
};

#endif /* GLOBOHELIOVIEW_H_ */
