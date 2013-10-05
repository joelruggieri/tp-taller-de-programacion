/*
 * Sogaview.h
 *
 *  Created on: Oct 5, 2013
 *      Author: matias
 */

#ifndef SOGAVIEW_H_
#define SOGAVIEW_H_

#include "ObjetoView.h"

class SimpleEditorSoga;
struct SDL_Texture;

class SogaView: public ObjetoView {
public:
	SogaView(int x, int y, int w, int h, SDL_Texture * textura,SimpleEditorSoga * editor);
	virtual ~SogaView();
	EditorNivel* getEditor();
	void dropTemplate();
};

#endif /* SOGAVIEW_H_ */
