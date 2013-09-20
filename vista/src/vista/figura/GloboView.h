/*
 * GloboView.h
 *
 *  Created on: 20/09/2013
 *      Author: joel
 */

#ifndef GLOBOVIEW_H_
#define GLOBOVIEW_H_

#include "FiguraView.h"
#include "SDL2/SDL.h"

class GloboView: public FiguraView {
private:
	void dropTemplate();
public:
	GloboView(int x, int y, int w, int h, SDL_Texture * textura,DropController * controller);
	virtual ~GloboView();
};

#endif /* GLOBOVIEW_H_ */
