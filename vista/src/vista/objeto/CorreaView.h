/*
 * CorreaView.h
 *
 *  Created on: 15/10/2013
 *      Author: joel
 */

#ifndef CORREAVIEW_H_
#define CORREAVIEW_H_

#include "ObjetoView.h"

class SimpleEditorSoga;

class CorreaView: public ObjetoView {
private:
	int xDesde;
	int yDesde;
	int xHasta;
	int yHasta;
	void dibujarse(SDL_Renderer* renderer, SDL_Rect& src, SDL_Rect& dest);
	typedef FiguraView super;
	SDL_Color color;
public:
	CorreaView(int x, int y, SDL_Texture * textura,SimpleEditorSoga * editor,Uint8 r,Uint8 g,Uint8 b);
	virtual ~CorreaView();
	EditorNivel* getEditor();
	void dropTemplate();
	void dibujarse(SDL_Renderer*);
	void update(Transformacion & tl);
	void setYDesde(int yDesde);
	void setXDesde(int xDesde);
	void setYHasta(int yHasta);
	void setXHasta(int xHasta);
};

#endif /* CORREAVIEW_H_ */
