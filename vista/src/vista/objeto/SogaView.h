/*
 * Sogaview.h
 *
 *  Created on: Oct 5, 2013
 *      Author: matias
 */

#ifndef SOGAVIEW_H_
#define SOGAVIEW_H_

#include "UnionView.h"

class EditorUnion;
struct SDL_Texture;

class SogaView: public UnionView {
public:
	SogaView(int x, int y, int w, int h, SDL_Texture * textura, EditorUnion * editor);
	virtual ~SogaView();
	EditorNivel* getEditor();
	void dropTemplate();
	void dibujarse(SDL_Renderer * renderer, SDL_Rect & dest);
private:
	void dibujarParte(SDL_Renderer * renderer, SDL_Rect & dest, float angulo, SDL_Texture* text);
	SDL_Texture * texturaTramo;
};

#endif /* SOGAVIEW_H_ */
