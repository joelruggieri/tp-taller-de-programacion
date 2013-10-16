/*
 * SogaEstaticaView.h
 *
 *  Created on: 15/10/2013
 *      Author: jonathan
 */

#ifndef SOGAESTATICAVIEW_H_
#define SOGAESTATICAVIEW_H_

#include "ObjetoView.h"
class EditorUnion;
struct SDL_Texture;
class SogaEstaticaView: public ObjetoView {
public:
	SogaEstaticaView(int x, int y, int w, int h, SDL_Texture * textura, EditorUnion * editor);
	virtual ~SogaEstaticaView();
	EditorNivel* getEditor();
	void dropTemplate();
private:
	SDL_Texture * texturaTramo;
};

#endif /* SOGAESTATICAVIEW_H_ */
