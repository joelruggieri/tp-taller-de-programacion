/*
 * ResorteView.h
 *
 *  Created on: 20/09/2013
 *      Author: joel
 */

#ifndef RESORTEVIEW_H_
#define RESORTEVIEW_H_
#include "FiguraView.h"
#include "SDL2/SDL.h"

class ResorteView: public FiguraView {
protected:
	void dropTemplate();
public:
	ResorteView(int x, int y, int w, int h, SDL_Texture * textura,DropController * controller);
	virtual ~ResorteView();
};

#endif /* RESORTEVIEW_H_ */
